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

    if ( m_cols_max == 40 ) {
        return m_x_position / 16;
    }
    else {
        return m_x_position / 8;
    }
}

unsigned int msmouse::yPosition( void ) const
{
    if ( !m_inited ) {
        return UINT_MAX;
    }

    return m_y_position / 8;
}

void msmouse::cursorPosition( const unsigned int x, const unsigned int y )
{
    if ( !m_inited ) {
        return;
    }

    REGS regs;

    regs.x.ax = 0x0004;
    if ( m_cols_max == 40 ) {
        regs.x.cx = x * 16;
    }
    else {
        regs.x.cx = x * 8;
    }
    regs.x.dx = y * 8;
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
    if ( m_cols_max == 40 ) {
        x = (unsigned int*)( m_x_position / 16 );
    }
    else {
        x = (unsigned int*)( m_x_position / 8 );
    }
    y = (unsigned int*)( m_y_position / 8 );
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
    if ( m_cols_max == 40 ) {
        x_position = (unsigned int*)( regs.x.cx / 16 );
    }
    else {
        x_position = (unsigned int*)( regs.x.cx / 8 );
    }
    y_position = (unsigned int*)( regs.x.dx / 8 );
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
    if ( m_cols_max == 40 ) {
        x_position = (unsigned int*)( regs.x.cx / 16 );
    }
    else {
        x_position = (unsigned int*)( regs.x.cx / 8 );
    }
    y_position = (unsigned int*)( regs.x.dx / 8 );
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
    if ( m_cols_max == 40 ) {
        regs.x.cx = min * 16;
        regs.x.dx = max * 16;
    }
    else {
        regs.x.cx = min * 8;
        regs.x.dx = max * 8;
    }
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
    regs.x.cx = min * 8;
    regs.x.dx = max * 8;
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
    if ( m_cols_max == 40 ) {
        regs.x.cx = x_min * 16;
        regs.x.dx = x_max * 16;
    }
    else {
        regs.x.cx = x_min * 8;
        regs.x.dx = x_max * 8;
    }
    int86( mouseint, &regs, &regs );
    regs.x.ax = 0x0008;
    regs.x.cx = y_min * 8;
    regs.x.dx = y_max * 8;
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

void msmouse::hidePointerInRegion( const unsigned int min_x, const unsigned int min_y, const unsigned int max_x, const unsigned int max_y )
{
    if ( !m_inited ) {
        return;
    }

    REGS regs;
    
    regs.x.ax = 0x0010;
    if ( m_cols_max == 40 ) {
        regs.x.cx = min_x * 16;
        regs.x.si = max_x * 16;
    }
    else {
        regs.x.cx = min_x * 8;
        regs.x.si = max_x * 8;
    }
    regs.x.dx = min_y * 8;
    regs.x.di = max_y * 8;
    int86( mouseint, &regs, &regs );
    m_cursor_hidden = 1;
}
