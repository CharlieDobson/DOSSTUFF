// dosforms.cpp : class implementation file

#include "dosforms.hpp"

const unsigned int hide_keyboard_cursor = 0x2000;
const unsigned int show_keyboard_cursor = 0x0707;
const unsigned short max_dosforms_title = 35;
static boolean dosforms_inited = FALSE;

DOSForms::DOSForms( void )
{
    if ( dosforms_inited ) {
        return;
    }

    videoconfig vc;
    _getvideoconfig( &vc );

    isFormOpen = FALSE;
    m_form_color.foreground = FG_BLUE;
    m_form_color.background = BG_WHITE;
    m_title_color.foreground = FG_NO_COLOR;
    m_title_color.background = BG_NO_COLOR;
    m_status_bar_color.foreground = FG_NO_COLOR;
    m_status_bar_color.background = BG_NO_COLOR;
    m_old_display_mode = vc.mode;
    m_text_columns = vc.numtextcols;
    m_text_rows = vc.numtextrows;
    m_title_text = new char[max_dosforms_title + 1];
    m_status_bar_text = new char[m_text_columns - 1];
    m_screen_buffer = new char[m_text_columns * m_text_rows];
    m_mouse_control = new char[4];

    m_title_text[0] = '\0';
    m_status_bar_text[0] = '\0';
    m_screen_buffer[0] = '\0';
    memset( &m_save_window, 0, sizeof( window_coordinates_t ) );
    sprintf( m_mouse_control, "[%c]", 196 ); // 196 = ASCII "em dash" ─
    dosforms_inited = TRUE;
}

DOSForms::DOSForms( const forms_colors_t FormColor )
{
    if ( dosforms_inited ) {
        return;
    }

    videoconfig vc;
    _getvideoconfig( &vc );

    isFormOpen = FALSE;
    m_form_color = FormColor;
    m_title_color.foreground = FG_NO_COLOR;
    m_title_color.background = BG_NO_COLOR;
    m_status_bar_color.foreground = FG_NO_COLOR;
    m_status_bar_color.background = BG_NO_COLOR;
    m_old_display_mode = vc.mode;
    m_text_columns = vc.numtextcols;
    m_text_rows = vc.numtextrows;
    m_title_text = new char[max_dosforms_title + 1];
    m_status_bar_text = new char[m_text_columns - 1];
    m_screen_buffer = new char[m_text_columns * m_text_rows];
    m_mouse_control = new char[4];

    m_title_text[0] = '\0';
    m_status_bar_text[0] = '\0';
    m_screen_buffer[0] = '\0';
    memset( &m_save_window, 0, sizeof( window_coordinates_t ) );
    sprintf( m_mouse_control, "[%c]", 196 ); // 196 = ASCII "em dash" ─
    dosforms_inited = TRUE;
}

DOSForms::DOSForms( const forms_colors_t FormColor, const forms_colors_t TitleColor, const char* TitleText )
{
    if ( dosforms_inited ) {
        return;
    }

    videoconfig vc;
    _getvideoconfig( &vc );

    isFormOpen = FALSE;
    m_form_color = FormColor;
    m_title_color = TitleColor;
    m_status_bar_color.foreground = FG_NO_COLOR;
    m_status_bar_color.background = BG_NO_COLOR;
    m_old_display_mode = vc.mode;
    m_text_columns = vc.numtextcols;
    m_text_rows = vc.numtextrows;
    m_title_text = new char[max_dosforms_title + 1];
    m_status_bar_text = new char[m_text_columns - 1];
    m_screen_buffer = new char[m_text_columns * m_text_rows];
    m_mouse_control = new char[4];

    strncpy( m_title_text, TitleText, max_dosforms_title );
    m_status_bar_text[0] = '\0';
    m_screen_buffer[0] = '\0';
    memset( &m_save_window, 0, sizeof( window_coordinates_t ) );
    sprintf( m_mouse_control, "[%c]", 196 ); // 196 = ASCII "em dash" ─
    dosforms_inited = TRUE;
}

DOSForms::DOSForms( const forms_colors_t FormColor, const forms_colors_t TitleColor, const char* TitleText, const forms_colors_t StatusBarColor, const char* StatusBarText )
{
    if ( dosforms_inited ) {
        return;
    }

    videoconfig vc;
    _getvideoconfig( &vc );

    isFormOpen = FALSE;
    m_form_color = FormColor;
    m_title_color = TitleColor;
    m_status_bar_color = StatusBarColor;
    m_old_display_mode = vc.mode;
    m_text_columns = vc.numtextcols;
    m_text_rows = vc.numtextrows;
    m_title_text = new char[max_dosforms_title + 1];
    m_status_bar_text = new char[m_text_columns - 1];
    m_screen_buffer = new char[m_text_columns * m_text_rows];
    m_mouse_control = new char[4];

    strncpy( m_title_text, TitleText, max_dosforms_title );
    strncpy( m_status_bar_text, StatusBarText, m_text_columns - 2 );
    m_screen_buffer[0] = '\0';
    memset( &m_save_window, 0, sizeof( window_coordinates_t ) );
    sprintf( m_mouse_control, "[%c]", 196 ); // 196 = ASCII "em dash" ─
    dosforms_inited = TRUE;
}

DOSForms::~DOSForms( void )
{
    delete[] m_mouse_control;
    delete[] m_screen_buffer;
    delete[] m_status_bar_text;
    delete[] m_title_text;

    _setvideomode( m_old_display_mode );
    _settextcursor( 0x0707 );
    _clearscreen( _GCLEARSCREEN );

    dosforms_inited = FALSE;
}

/**************************************************
* Private methods
**************************************************/
unsigned short DOSForms::CenterScreen( const char* Text ) const
{
    return ( strlen( Text ) + m_text_columns ) / 2 - strlen( Text );
}

// clear text from line
void DOSForms::ClearRow( const unsigned short row )
{
    if ( row < 1 || row > m_text_rows ) {
        return;
    }

    if ( mouse.isInited() && !mouse.isCursorHidden() ) {
        mouse.hideCursor();
    }

    _settextposition( row, 1 );
    _settextcolor( _gettextcolor() );
    _setbkcolor( _getbkcolor() );
    _settextwindow( row, 1, row, m_text_columns );
    _clearscreen( _GWINDOW );
    _settextwindow( 1, 1, m_text_rows, m_text_columns );

    if ( mouse.isInited() && mouse.isCursorHidden() ) {
        mouse.showCursor();
    }
}

void DOSForms::SaveWindow( const short x, const short y, const short width, const short height )
{
    window_coordinates_t temp;
    temp.column = x;
    temp.row = y;
    temp.width = width;
    temp.height = height;

    SaveWindow( temp );
}

void DOSForms::SaveWindow( const window_coordinates_t coordinates )
{
    if ( m_screen_buffer[0] != '\0' ) {
        return;
    }

    REGS regs;
    m_save_window = coordinates;

    for ( short i = 0; i < m_save_window.height; ++i ) {
        regs.h.ah = 0x08; // BIOS function to read character and attribute
        regs.h.bh = 0; // page number

        for ( short j = 0; j < m_save_window.width; ++j ) {
            regs.h.dh = m_save_window.row + i; // row
            regs.h.dl = m_save_window.column + j; // column
            int86( 0x10, &regs, &regs );
            m_screen_buffer[( i * m_save_window.width + j ) * 2] = regs.h.al; // character
            m_screen_buffer[( i * m_save_window.width + j ) * 2 + 1] = regs.h.ah; // attribute
        }
    }
}

void DOSForms::RestoreWindow( void )
{
    if ( m_screen_buffer[0] == '\0' ) {
        return;
    }

    REGS regs;

    for ( short i = 0; i < m_save_window.height; ++i ) {
        regs.h.ah = 0x09; // BIOS function to write character and atribute
        regs.h.bh = 0; // page number

        for ( short j = 0; j < m_save_window.width; ++j ) {
            regs.h.dh = m_save_window.row + i; // row
            regs.h.dl = m_save_window.column + j; // column
            regs.h.al = m_screen_buffer[( i * m_save_window.width + j ) * 2]; // character
            regs.h.bl = m_screen_buffer[( i * m_save_window.width + j ) * 2 + 1]; // attribute
            regs.x.cx = 1; // repeat count
            int86( 0x10, &regs, &regs );
        }
    }

    m_screen_buffer[0] = '\0';
    memset( &m_save_window, 0, sizeof( window_coordinates_t ) );
}

/**************************************************
* Accessors
**************************************************/
forms_colors_t DOSForms::FormColor( void ) const
{
    return m_form_color;
}

forms_colors_t DOSForms::TitleColor( void ) const
{
    return m_title_color;
}

forms_colors_t DOSForms::StatusBarColor( void ) const
{
    return m_status_bar_color;
}

char* DOSForms::TitleText( void ) const
{
    return m_title_text;
}

char* DOSForms::StatusBarText( void ) const
{
    return m_status_bar_text;
}

/**************************************************
*  Mutators
**************************************************/
void DOSForms::TitleColor( const forms_colors_t Color )
{
    if ( Color.foreground == FG_NO_COLOR || Color.background == BG_NO_COLOR ) {
        return;
    }

    m_title_color = Color;

    if ( !isFormOpen ) {
        return;
    }

    if ( mouse.isInited() && !mouse.isCursorHidden() ) {
        mouse.hideCursor();
    }

    _settextcolor( m_title_color.foreground );
    _setbkcolor( m_title_color.background );
    _settextwindow( 1, 1, 1, m_text_columns );
    _clearscreen( _GWINDOW );
    _settextwindow( 1, 1, m_text_rows, m_text_columns );

    if ( mouse.isInited() && mouse.isCursorHidden() ) {
        mouse.showCursor();
    }

    if ( m_title_text[0] != '\0' ) {
        TitleText( m_title_text );
    }
}

void DOSForms::TitleColor( const foreground_colors_t foreground, const background_colors_t background )
{
    if ( foreground == FG_NO_COLOR || background == BG_NO_COLOR ) {
        return;
    }

    m_title_color.foreground = foreground;
    m_title_color.background = background;

    if ( !isFormOpen ) {
        return;
    }

    if ( mouse.isInited() && !mouse.isCursorHidden() ) {
        mouse.hideCursor();
    }

    _settextcolor( m_title_color.foreground );
    _setbkcolor( m_title_color.background );
    _settextwindow( 1, 1, 1, m_text_columns );
    _clearscreen( _GWINDOW );
    _settextwindow( 1, 1, m_text_rows, m_text_columns );

    if ( mouse.isInited() && mouse.isCursorHidden() ) {
        mouse.showCursor();
    }

    if ( m_title_text[0] != '\0' ) {
        TitleText( m_title_text );
    }
}

void DOSForms::TitleText( const char* Text )
{
    if ( Text[0] == '\0' || strlen( Text ) > max_dosforms_title ) {
        return;
    }

    strcpy( m_title_text, Text );

    if ( !isFormOpen ) {
        return;
    }

    if ( mouse.isInited() && !mouse.isCursorHidden() ) {
        mouse.hideCursor();
    }

    short center = ( strlen( m_title_text ) + m_text_columns ) / 2 - strlen( m_title_text );
    _settextposition( 1, center );
    _settextcolor( _gettextcolor() );
    _setbkcolor( _getbkcolor() );
    _outtext( m_title_text );

    if ( mouse.isInited() && mouse.isCursorHidden() ) {
        mouse.showCursor();
    }
}

void DOSForms::StatusBarColor( const forms_colors_t Color )
{
    if ( Color.foreground == FG_NO_COLOR || Color.background == BG_NO_COLOR ) {
        return;
    }
    
    m_status_bar_color = Color;

    if ( !isFormOpen ) {
        return;
    }

    if ( mouse.isInited() && !mouse.isCursorHidden() ) {
        mouse.hideCursor();
    }

    _settextcolor( m_status_bar_color.foreground );
    _setbkcolor( m_status_bar_color.background );
    _settextwindow( m_text_rows, 1, m_text_rows, m_text_columns );
    _clearscreen( _GWINDOW );
    _settextwindow( 1, 1, m_text_rows, m_text_columns );

    if ( mouse.isInited() && mouse.isCursorHidden() ) {
        mouse.showCursor();
    }

    if ( m_status_bar_text[0] != '\0' ) {
        StatusBarText( m_status_bar_text );
    }
}

void DOSForms::StatusBarColor( const foreground_colors_t foreground, const background_colors_t background )
{
    if ( foreground == FG_NO_COLOR || background == BG_NO_COLOR ) {
        return;
    }

    m_status_bar_color.foreground = foreground;
    m_status_bar_color.background = background;

    if ( !isFormOpen ) {
        return;
    }

    if ( mouse.isInited() && !mouse.isCursorHidden() ) {
        mouse.hideCursor();
    }

    _settextcolor( m_status_bar_color.foreground );
    _setbkcolor( m_status_bar_color.background );
    _settextwindow( m_text_rows, 1, m_text_rows, m_text_columns );
    _clearscreen( _GWINDOW );
    _settextwindow( 1, 1, m_text_rows, m_text_columns );

    if ( mouse.isInited() && mouse.isCursorHidden() ) {
        mouse.showCursor();
    }

    if ( m_status_bar_text[0] != '\0' ) {
        StatusBarText( m_status_bar_text );
    }
}

void DOSForms::StatusBarText( const char* Text )
{
    if ( Text[0] == '\0' || strlen( Text ) > m_text_columns - 1 ) {
        return;
    }

    strcpy( m_status_bar_text, Text );

    if ( !isFormOpen ) {
        return;
    }

    if ( mouse.isInited() && !mouse.isCursorHidden() ) {
        mouse.hideCursor();
    }

    _settextposition( m_text_rows, 1 );
    _settextcolor( _gettextcolor() );
    _setbkcolor( _getbkcolor() );
    _outtext( m_status_bar_text );

    if ( mouse.isInited() && mouse.isCursorHidden() ) {
        mouse.showCursor();
    }
}

/**************************************************
*  Methods
**************************************************/
void DOSForms::OpenForm( void )
{
    if ( mouse.isInited() && !mouse.isCursorHidden() ) {
        mouse.hideCursor();
    }

    isFormOpen = TRUE;
    _setvideomode( _TEXTC80 );
    _settextcolor( m_form_color.foreground );
    _setbkcolor( m_form_color.background );
    _clearscreen( _GCLEARSCREEN );
    _settextcursor( 0x2000 );

    if ( mouse.isInited() && mouse.isCursorHidden() ) {
        mouse.showCursor();
    }

    TitleColor( m_title_color ); // this will call TitleText() as well
    StatusBarColor( m_status_bar_color ); // this will call StatusBarText() as well

    if ( mouse.isInited() && !mouse.isCursorHidden() ) {
        mouse.hideCursor();

        if ( m_title_color.foreground != FG_NO_COLOR ) {
            _settextcolor( m_title_color.foreground );
            _setbkcolor( m_title_color.background );
        }
        else {
            _settextcolor( m_form_color.foreground );
            _setbkcolor( m_form_color.background );
        }

        _settextposition( 1, 1 );
        _outtext( m_mouse_control );

        if ( mouse.isCursorHidden() ) {
            mouse.showCursor();
        }
    }
}

void DOSForms::RemoveTitleBar( void )
{
    if ( m_title_text[0] == '\0' || ( m_title_color.foreground == FG_NO_COLOR && m_title_color.background == BG_NO_COLOR ) ) {
        return;
    }

    m_title_color.foreground = FG_NO_COLOR;
    m_title_color.background = BG_NO_COLOR;
    m_title_text[0] = '\0';

    if ( !isFormOpen ) {
        return;
    }

    if ( mouse.isInited() && !mouse.isCursorHidden() ) {
        mouse.hideCursor();
    }

    _settextcolor( m_form_color.foreground );
    _setbkcolor( m_form_color.background );
    _settextwindow( 1, 1, 1, m_text_columns );
    _clearscreen( _GWINDOW );
    _settextwindow( 1, 1, m_text_rows, m_text_columns );
    
    if ( mouse.isInited() ) {
        _settextposition( 1, 1 );
        _settextcolor( _gettextcolor() );
        _setbkcolor( _getbkcolor() );
        _outtext( m_mouse_control );
    }

    if ( mouse.isInited() && mouse.isCursorHidden() ) {
        mouse.showCursor();
    }
}

void DOSForms::RemoveStatusBar( void )
{
    if ( m_status_bar_text[0] == '\0' || ( m_status_bar_color.foreground == FG_NO_COLOR && m_status_bar_color.background == BG_NO_COLOR ) ) {
        return;
    }

    m_status_bar_color.foreground = FG_NO_COLOR;
    m_status_bar_color.background = BG_NO_COLOR;
    m_status_bar_text[0] = '\0';

    if ( !isFormOpen ) {
        return;
    }

    if ( mouse.isInited() && !mouse.isCursorHidden() ) {
        mouse.hideCursor();
    }

    _settextcolor( m_form_color.foreground );
    _setbkcolor( m_form_color.background );
    _settextwindow( m_text_rows, 1, m_text_rows, m_text_columns );
    _clearscreen( _GWINDOW );
    _settextwindow( 1, 1, m_text_rows, m_text_columns );

    if ( mouse.isInited() && mouse.isCursorHidden() ) {
        mouse.showCursor();
    }
}

void DOSForms::DrawButton( const FormButton button )
{
    if ( button.color().foreground == FG_NO_COLOR || button.coordinates().column < 1 || button.coordinates().row < 1 ) {
        return;
    }

    if ( !isFormOpen ) {
        return;
    }

    if ( mouse.isInited() && !mouse.isCursorHidden() ) {
        mouse.hideCursor();
    }

    // draw drop shadow first
    _settextcolor( button.color().foreground );
    if ( button.color().background != BG_BLACK && m_form_color.background != BG_BLACK ) {
        _setbkcolor( BG_BLACK );
    }
    else if ( button.color().background != BG_DARK_GRAY && m_form_color.background != BG_DARK_GRAY ) {
        _setbkcolor( BG_DARK_GRAY );
    }
    _settextwindow( button.coordinates().row + 1, button.coordinates().column + 1, button.coordinates().end_row + 1, button.coordinates().end_column + 1 );
    _clearscreen( _GWINDOW );

    // draw button
    _setbkcolor( button.color().background );
    _settextwindow( button.coordinates().row, button.coordinates().column, button.coordinates().end_row, button.coordinates().end_column );
    _clearscreen( _GWINDOW );

    _settextwindow( 1, 1, m_text_columns, m_text_rows );

    // center text on button
    // center column formula:   starting column number + ( button width - length of text ) / 2
    // center row formula:      button row number + button height / 2
    short text_x = button.coordinates().column + ( button.coordinates().width - strlen( button.label() ) ) / 2;
    short text_y = button.coordinates().row + button.coordinates().height / 2;
    _settextposition( text_y, text_x );
    _outtext( button.label() );

    if ( mouse.isInited() && mouse.isCursorHidden() ) {
        mouse.showCursor();
    }
}

/*
button_t DOSForms::MessageBox( const FormMessage message )
{
    if ( mouse.isInited() && !mouse.isCursorHidden() ) {
        mouse.hideCursor();
    }

    button_t button_id;

    SaveWindow( message.coordinates() );

    _settextcolor( message.color().foreground );
    _setbkcolor( message.color().background );
    _settextwindow( message.coordinates().row, message.coordinates().column, message.coordinates().end_row, message.coordinates().end_column );
    _clearscreen( _GWINDOW );

    // code here

    RestoreWindow();

    if ( mouse.isInited() && mouse.isCursorHidden() ) {
        mouse.showCursor();
    }

    return button_id;
}
*/

/*
// message box
// Window window provides color, coordinates, and Label provides dialog text
// return 0 on error, or number of button pressed
short DOSForms::MessageBox( const Window window, const dialog_buttons_t Buttons, unsigned int ButtonColor ) const
{
    unsigned char choice = 0;
    char buttons[2][9] = { NULL, NULL };

    switch( Buttons ) {
        case BTN_YESNO:
            strcpy( buttons[0], "Yes" );
            strcpy( buttons[1], "No" );
            break;
        case BTN_NEXTBACK:
            strcpy( buttons[0], "Next" );
            strcpy( buttons[1], "Back" );
            break;
        case BTN_INSTALLCANCEL:
            strcpy( buttons[0], "Install" );
            strcpy( buttons[1], "Cancel" );
            break;
        case BTN_OKCANCEL:
            strcpy( buttons[0], "OK" );
            strcpy( buttons[1], "Cancel" );
            break;
        default:
            strcpy( buttons[0], "OK" );
    }

    if ( disp_inited == 0 ) {
        return 0;
    }

    if ( is_mouse_enabled != 0 ) {
        msm_hidecursor();
    }

    unsigned short *scrnBuffer = new unsigned short[50*10];

    disp_peekbox( scrnBuffer, window.Top(), window.Left(), window.Top() + 7 + 1, window.Left() + 44 + 1 ); // save current contents to buffer
    disp_fillbox( __BLACK * 256 + ' ', window.Top() + 1, window.Left() + 1, window.Top() + 7, window.Left() + 44 + 1 ); // draw drop shadow
    disp_box( window.BorderStyle(), window.Color(), window.Top(), window.Left(), window.Top() + 6, window.Left() + 44 ); //draw popup
    disp_fillbox( window.Color() * 256 + ' ', window.Top() + 1, window.Left() + 1, window.Top() + 5, window.Left() + 43 ); // fill popup box

    if ( window.Label() != NULL ) {
        disp_setattr( window.Color() );
        int centerColumn = ( strlen( window.Label() ) + 44 ) / 2 - strlen( window.Label() );
        disp_move( window.Top() + 2, window.Left() + centerColumn );
        disp_printf( "%s", window.Label() );
    }

    if ( ButtonColor == NULL ) {
        ButtonColor = __YELLOW_ON_GREEN;
    }

    if ( Buttons == BTN_OK ) {
        //int center = ( ( 8 + 44 ) / 2 - 8 ) + 1;
        disp_box( 5, ButtonColor, window.Top() + 4, window.Left() + 17, window.Top() + 4, window.Left() + 25 );
    }
    else {
        disp_box( 5, ButtonColor, window.Top() + 4, window.Left() + 7, window.Top() + 4, window.Left() + 15 );
        disp_box( 5, ButtonColor, window.Top() + 4, window.Left() + 27, window.Top() + 4, window.Left() + 35 );
    }

    disp_setattr( ButtonColor );

    if ( Buttons == BTN_OKCANCEL ) {
        disp_move( window.Top() + 4, window.Left() + 10 );
        disp_puts( buttons[0] );
        disp_move( window.Top() + 4, window.Left() + 28 );
        disp_puts( buttons[1] );
    }
    else if ( Buttons == BTN_YESNO ) {
        disp_move( window.Top() + 4, window.Left() + 10 );
        disp_puts( buttons[0] );
        disp_move( window.Top() + 4, window.Left() + 30 );
        disp_puts( buttons[1] );
    }
    else if ( Buttons == BTN_NEXTBACK ) {
        disp_move( window.Top() + 4, window.Left() + 9 );
        disp_puts( buttons[0] );
        disp_move( window.Top() + 4, window.Left() + 29 );
        disp_puts( buttons[1] );
    }
    else if ( Buttons == BTN_INSTALLCANCEL ) {
        disp_move( window.Top() + 4, window.Left() + 8 );
        disp_puts( buttons[0] );
        disp_move( window.Top() + 4, window.Left() + 28 );
        disp_puts( buttons[1] );
    }
    else {
        disp_move( window.Top() + 4, window.Left() + 20 );
        disp_puts( buttons[0] );
    }

    disp_setattr( window.Color() );

    if ( is_mouse_enabled != 0 ) {
        msm_showcursor();
    }

    do {
        if ( is_mouse_enabled != 0 ) {
            static int mouse_status = -1;
            static int old_mouse_status = -1;

            mouse_status = msm_getstatus( &mouse_x, &mouse_y );

            if ( (mouse_status & LEFT_BUTTON) && (mouse_status != old_mouse_status) ) {
                // multiply button positions by 8 to get mouse location
                if ( mouse_y == ( ( window.Top() + 4 ) * 8 ) ) {
                    if ( Buttons == BTN_OK ) {
                        if ( mouse_x >= ( ( window.Left() + 17 ) * 8 ) && mouse_x <= ( ( window.Left() + 25 ) * 8 ) ) {
                            break;
                        }
                    }
                    else {
                        if ( mouse_x >= ( ( window.Left() + 7 ) * 8 ) && mouse_x <= ( ( window.Left() + 15 ) * 8 ) ) {
                            choice = 1;
                            break;
                        }
                        if ( mouse_x >= ( ( window.Left() + 27 ) * 8 ) && mouse_x <= ( ( window.Left() + 35 ) * 8 ) ) {
                            choice = 2;
                            break;
                        }
                    }
                }
            }

            old_mouse_status = mouse_status;
        }
        if ( _kbhit() ) {
            static int kb_input = -1;
            kb_input = _getch();

            if ( kb_input == 27 ) {
                choice = 0;
                break;
            }
            if ( Buttons == BTN_OK ) {
                if ( kb_input == 'O' || kb_input == 'o' || kb_input == 13 ) {
                    break;
                }
            }
            if ( Buttons == BTN_OKCANCEL ) {
                if ( kb_input == 'O' || kb_input == 'o' ) {
                    choice = 1;
                    break;
                }
                else if ( kb_input == 'C' || kb_input == 'c' ) {
                    choice = 2;
                    break;
                }
            }
            if ( Buttons == BTN_YESNO ) {
                if ( kb_input == 'Y' || kb_input == 'y' ) {
                    choice = 1;
                    break;
                }
                else if ( kb_input == 'N' || kb_input == 'n' ) {
                    choice = 2;
                    break;
                }
            }
            if ( Buttons == BTN_NEXTBACK ) {
                if ( kb_input == 'N' || kb_input == 'n' ) {
                    choice = 1;
                    break;
                }
                else if ( kb_input == 'B' || kb_input == 'b' ) {
                    choice = 2;
                    break;
                }
            }
            if ( Buttons == BTN_INSTALLCANCEL ) {
                if ( kb_input == 'I' || kb_input == 'i' ) {
                    choice = 1;
                    break;
                }
                else if ( kb_input == 'C' || kb_input == 'c' ) {
                    choice = 2;
                    break;
                }
            }
        }
    } while ( 1 );

    if ( is_mouse_enabled != 0 ) {
        msm_hidecursor();
    }

    disp_pokebox( scrnBuffer, window.Top(), window.Left(), window.Top() + 7 + 1, window.Left() + 44 + 1 );
    delete[] scrnBuffer;

    if ( is_mouse_enabled != 0 ) {
        msm_showcursor();
    }

    return choice;
}
*/