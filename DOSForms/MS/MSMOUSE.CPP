// MSMOUSE.CPP : Microsoft Mouse implementation file

#include "msmouse.hpp"

/*
const int signal_move = 1;
const int signal_button_down_left = 2;
const int signal_button_up_left = 4;
const int signal_button_down_right = 8;
const int signal_button_up_right = 16;
const int signal_button_down_middle = 32;
const int signal_button_up_middle = 64;
const int button_left = 1;
const int button_right = 2;
const int button_middle = 4;
*/

const int mouseint = 0x33;

msmouse::msmouse( void )
{
    m_inited = 0;
    m_cursor_hidden = -2;
    m_y_position = UINT_MAX;
    m_x_position = UINT_MAX;
    m_cols_max = UINT_MAX;
    m_rows_max = UINT_MAX;

    REGS regs;
    
    regs.x.ax = 0;
    int86( mouseint, &regs, &regs );
    if ( regs.x.ax == 0xffff ) {
        m_inited = 1;

        videoconfig vc;
        _getvideoconfig( &vc );
        m_cols_max = vc.numtextcols;
        m_rows_max = vc.numtextrows;
        
	    regs.x.ax = 0x0001;
    	int86( mouseint, &regs, &regs );
    	m_cursor_hidden = 0;
    }
}

msmouse::~msmouse( void )
{
    if ( !m_inited ) {
        return;
    }

    REGS regs;

    regs.x.ax = 0;
    int86( mouseint, &regs, &regs );
    #ifdef _DEBUG
    puts( "Mouse destructor called" );
    #endif
}

int msmouse::isInited( void ) const
{
	return m_inited;
}

int msmouse::isCursorHidden( void ) const
{
	return m_cursor_hidden;
}

unsigned int msmouse::xPosition( void ) const
{
    if ( !m_inited ) {
        return UINT_MAX;
    }

    return m_x_position;
}

unsigned int msmouse::yPosition( void ) const
{
    if ( !m_inited ) {
        return UINT_MAX;
    }

    return m_y_position;
}

void msmouse::cursorPosition( const unsigned int x, const unsigned int y )
{
    if ( !m_inited ) {
        return;
    }

    REGS regs;

    regs.x.ax = 0x0004;
    regs.x.cx = x;
    regs.x.dx = y;
    int86( mouseint, &regs, &regs );
    m_x_position = x;
    m_y_position = y;
}

void msmouse::showCursor( void )
{
    if ( !m_inited ) {
        return;
    }

    if ( m_cursor_hidden ) {
        return;
    }

    REGS regs;

    regs.x.ax = 0x0001;
    int86( mouseint, &regs, &regs );
    m_cursor_hidden = 0;
}

void msmouse::hideCursor( void )
{
    if ( !m_inited ) {
        return;
    }

    if ( !m_cursor_hidden ) {
        return;
    }

    REGS regs;

    regs.x.ax = 0x0002;
    int86( mouseint, &regs, &regs );
    m_cursor_hidden = 1;
}


/*********************************************************************
    Status()
    return state of all buttons as a bit pattern
    Bit Button
    0   left button ( 1 == down, 0 == up )
    1   right button
    2   middle button
    Ignore all other bits
*********************************************************************/
int msmouse::status( void )
{
    if ( !m_inited ) {
        return INT_MAX;
    }

    REGS regs;

    regs.x.ax = 0x0003;
    int86( mouseint, &regs, &regs );
    m_x_position = regs.x.cx;
    m_y_position = regs.x.dx;
    return (int)regs.x.bx;
}

/*********************************************************************
    Status( unsigned *, unsigned *)
    same as above but returns mouse position in x and y
*********************************************************************/
int msmouse::status( unsigned int *x, unsigned int *y )
{
    if ( !m_inited ) {
        return INT_MAX;
    }

    REGS regs;

    regs.x.ax = 0x0003;
    int86( mouseint, &regs, &regs );
    m_x_position = regs.x.cx;
    m_y_position = regs.x.dx;
    x = (unsigned int*)m_x_position;
    y = (unsigned int*)m_y_position;
    return (int)regs.x.bx;
}

/*********************************************************************
    GetButtonPress()
    return button press information since last call to GetButtonPress()
    input button:
    -1 = wheel (if supported by driver)
    0 = left
    1 = right
    2 = middle
    return value will be bit pattern as follows:
    bit Button
    0   left button ( 1 == down, 0 == up )
    1   right button
    2   middle button
    Ignore all other bits
*********************************************************************/
int msmouse::getButtonPress( int *button, unsigned int *x_position, unsigned int *y_position )
{
    if ( !m_inited ) {
        return INT_MAX;
    }
    
    REGS regs;

    regs.x.ax = 0x0005;
    regs.x.bx = (unsigned int)button;
    int86( mouseint, &regs, &regs );
    button = (int*)regs.x.bx;
    x_position = (unsigned int*)regs.x.cx;
    y_position = (unsigned int*)regs.x.dx;
    return (int)regs.x.ax;
}

/*********************************************************************
    GetButtonRelease()
    return button release information since last call to GetButtonRelease()
    input button:
    -1 = wheel (if supported by driver)
    0 = left
    1 = right
    2 = middle
    return value will be bit pattern as follows:
    bit Button
    0   left button ( 1 == down, 0 == up )
    1   right button
    2   middle button
    Ignore all other bits
*********************************************************************/
int msmouse::getButtonRelease( int *button, unsigned int *x_position, unsigned int *y_position )
{
    if ( !m_inited ) {
        return INT_MAX;
    }
    
    REGS regs;

    regs.x.ax = 0x0006;
    regs.x.bx = (unsigned int)button;
    int86( mouseint, &regs, &regs );
    button = (int*)regs.x.bx;
    x_position = (unsigned int*)regs.x.cx;
    y_position = (unsigned int*)regs.x.dx;
    return (int)regs.x.ax;
}

/*********************************************************************
    SetArea*()
    defines the coordinates the mouse is allowed to move in
*********************************************************************/
void msmouse::setAreax( const unsigned int min, const unsigned int max )
{
    if ( !m_inited ) {
        return;
    }

    if ( max < min ) {
        return;
    }

    REGS regs;
    
    regs.x.ax = 0x0007;
    regs.x.cx = min;
    regs.x.dx = max;
    int86( mouseint, &regs, &regs );
}

void msmouse::setAreay( const unsigned int min, const unsigned int max )
{
    if ( !m_inited ) {
        return;
    }

    if ( max < min ) {
        return;
    }

    REGS regs;
    
    regs.x.ax = 0x0008;
    regs.x.cx = min;
    regs.x.dx = max;
    int86( mouseint, &regs, &regs );
}

void msmouse::setArea( const unsigned int x_min, const unsigned int x_max, const unsigned int y_min, const unsigned int y_max )
{
    if ( !m_inited ) {
        return;
    }

    if ( x_max < x_min || y_max < y_min ) {
        return;
    }

    REGS regs;

    regs.x.ax = 0x0007;
    regs.x.cx = x_min;
    regs.x.dx = x_max;
    int86( mouseint, &regs, &regs );
    regs.x.ax = 0x0008;
    regs.x.cx = y_min;
    regs.x.dx = y_max;
    int86( mouseint, &regs, &regs );
}

// Read motion counters in mickeys (1/200 inch)
void msmouse::readCounters( int *x, int *y )
{
    if ( !m_inited ) {
        return;
    }

    REGS regs;
    
    regs.x.ax = 0x000B;
    int86( mouseint, &regs, &regs );
    x = (int*)regs.x.cx;
    y = (int*)regs.x.dx;
}

// Set mouse movement speed.  Higher values = slower, lower values = faster
void msmouse::movementSpeed( const unsigned int x, const unsigned int y )
{
    if ( !m_inited ) {
        return;
    }

    REGS regs;
    
    regs.x.ax = 0x001A;
    regs.x.bx = x;
    regs.x.cx = y;
    int86( mouseint, &regs, &regs );
}

void msmouse::hidePointerInRegion( const unsigned int left, const unsigned int top, const unsigned int right, const unsigned int bottom )
{
    if ( !m_inited ) {
        return;
    }

    REGS regs;
    
    regs.x.ax = 0x0010;
    regs.x.cx = left;
    regs.x.dx = top;
    regs.x.si = right;
    regs.x.di = bottom;
    int86( mouseint, &regs, &regs );
    m_cursor_hidden = 1;
}
