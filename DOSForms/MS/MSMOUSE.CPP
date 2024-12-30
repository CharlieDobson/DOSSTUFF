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

    REGS regs;
    
    regs.x.ax = 0;
    int86( mouseint, &regs, &regs );
    if ( regs.x.ax == 0xffff ) {
        m_inited = 1;

        #if defined( _MSC_VER ) || defined( __WATCOMC__ )
        videoconfig vc;
        _getvideoconfig( &vc );
        m_cols_max = vc.numtextcols;
        #elif __SC__
        if ( disp_inited ) {
            m_cols_max = disp_numcols;
        }
        else {
            disp_open();
            m_cols_max = disp_numcols;
            disp_close();
        }
        #endif
        
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
}

const int msmouse::IsInited( void ) const
{
	return m_inited;
}

const int msmouse::IsCursorHidden( void ) const
{
	return m_cursor_hidden;
}

const unsigned int msmouse::xPosition( void ) const
{
    if ( !m_inited ) {
        return UINT_MAX;
    }

    return m_cols_max == 40 ? m_x_position / 16 : m_x_position / 8;
}

const unsigned int msmouse::yPosition( void ) const
{
    if ( !m_inited ) {
        return UINT_MAX;
    }

    return m_y_position / 8;
}

void msmouse::CursorPosition( const unsigned int x, const unsigned int y )
{
    if ( !m_inited ) {
        return;
    }

    REGS regs;

    regs.x.ax = 0x0004;
    regs.x.cx = ( m_cols_max == 40 ) ? x * 16 : x * 8;
    regs.x.dx = y * 8;
    int86( mouseint, &regs, &regs );
    m_x_position = x;
    m_y_position = y;
}

void msmouse::ShowCursor( void )
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

void msmouse::HideCursor( void )
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
const int msmouse::Status( void ) const
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
const int msmouse::Status( unsigned int *x, unsigned int *y ) const
{
    if ( !m_inited ) {
        return INT_MAX;
    }

    REGS regs;

    regs.x.ax = 0x0003;
    int86( mouseint, &regs, &regs );
    m_x_position = regs.x.cx;
    m_y_position = regs.x.dx;
    x = ( m_cols_max == 40 ) ? (unsigned int*)( m_x_position / 16 ) : (unsigned int*)( m_x_position / 8 );
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
const int msmouse::GetButtonPress( int *button, unsigned int *x_position, unsigned int *y_position ) const
{
    if ( !m_inited ) {
        return INT_MAX;
    }
    
    REGS regs;

    regs.x.ax = 0x0005;
    regs.x.bx = (unsigned int)button;
    int86( mouseint, &regs, &regs );
    button = (int*)regs.x.bx;
    x_position = ( m_cols_max == 40 ) ? (unsigned int*)( regs.x.cx / 16 ) : (unsigned int*)( regs.x.cx / 8 );
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
const int msmouse::GetButtonRelease( int *button, unsigned int *x_position, unsigned int *y_position ) const
{
    if ( !m_inited ) {
        return INT_MAX;
    }
    
    REGS regs;

    regs.x.ax = 0x0006;
    regs.x.bx = (unsigned int)button;
    int86( mouseint, &regs, &regs );
    button = (int*)regs.x.bx;
    x_position = ( m_cols_max == 40 ) ? (unsigned int*)( regs.x.cx / 16 ) : (unsigned int*)( regs.x.cx / 8 );
    y_position = (unsigned int*)( regs.x.dx / 8 );
    return (int)regs.x.ax;
}

/*********************************************************************
    SetArea*()
    defines the coordinates the mouse is allowed to move in
*********************************************************************/
void msmouse::SetAreax( const unsigned int min, const unsigned int max )
{
    if ( !m_inited ) {
        return;
    }

    if ( max < min ) {
        return;
    }

    REGS regs;
    
    regs.x.ax = 0x0007;
    regs.x.cx = ( m_cols_max == 40 ) ? min * 16 : min * 8;
    regs.x.dx = ( m_cols_max == 40 ) ? max * 16 : max * 8;
    int86( mouseint, &regs, &regs );
}

void msmouse::SetAreay( const unsigned int min, const unsigned int max )
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

void msmouse::SetArea( const unsigned int x_min, const unsigned int y_min, const unsigned int x_max, const unsigned int y_max )
{
    if ( !m_inited ) {
        return;
    }

    if ( x_max < x_min || y_max < y_min ) {
        return;
    }

    REGS regs;

    regs.x.ax = 0x0007;
    regs.x.cx = ( m_cols_max == 40 ) ? x_min * 16 : x_min * 8;
    regs.x.dx = ( m_cols_max == 40 ) ? x_max * 16 : x_max * 8;
    int86( mouseint, &regs, &regs );
    regs.x.ax = 0x0008;
    regs.x.cx = y_min * 8;
    regs.x.dx = y_max * 8;
    int86( mouseint, &regs, &regs );
}

// Read motion counters in mickeys (1/200 inch)
void msmouse::ReadCounters( int *x, int *y )
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
void msmouse::MovementSpeed( const unsigned int x, const unsigned int y )
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

void msmouse::HidePointerInRegion( const unsigned int x_min, const unsigned int y_min, const unsigned int x_max, const unsigned int y_max )
{
    if ( !m_inited ) {
        return;
    }

    REGS regs;
    
    regs.x.ax = 0x0010;
    regs.x.cx = ( m_cols_max == 40 ) ? x_min * 16 : x_min * 8;
    regs.x.si = ( m_cols_max == 40 ) ? x_max * 16 : x_max * 8;
    regs.x.dx = y_min * 8;
    regs.x.di = y_max * 8;
    int86( mouseint, &regs, &regs );
    m_cursor_hidden = 1;
}
