// dosforms.cpp : class implementation file

#include "dosforms.hpp"

const unsigned short _MAX_DOSFORMS_TITLE = 35;
const unsigned short _MAX_DOSFORMS_STATUSBAR = 78;

#ifdef __SC__
static short dosforms_inited = 0;

DOSForms::DOSForms( void )
{
    if ( dosforms_inited != 0 ) {
        return;
    }

    old_display_mode = disp_getmode();

    if ( old_display_mode != 3 || old_display_mode != 7 ) {
        disp_setmode( 3 );
    }

    if ( disp_inited == 0 ) {
        disp_open();
    }

    text_columns = (short)disp_numcols;
    text_rows = (short)disp_numrows;
    old_display_attributes = disp_getattr();
    is_mouse_enabled = msm_init();
    form_color = __GRAY;
    title_color = 0;
    status_bar_color = 0;
    screen_buffer = new unsigned short[80 * 25];
    title_text = new char[_MAX_DOSFORMS_TITLE + 1];
    status_bar_text = new char[_MAX_DOSFORMS_STATUSBAR + 1];
    is_screen_buffer_used = 0;
    dosforms_inited = 1;

    title_text[0] = NULL;
    status_bar_text[0] = NULL;
    memset( screen_buffer, '\0', 80 * 25 );
}

DOSForms::DOSForms( const unsigned int FormColor = __GRAY )
{
    if ( dosforms_inited != 0 ) {
        return;
    }

    old_display_mode = disp_getmode();

    if ( old_display_mode != 3 || old_display_mode != 7 ) {
        disp_setmode( 3 );
    }

    if ( disp_inited == 0 ) {
        disp_open();
    }

    text_columns = (short)disp_numcols;
    text_rows = (short)disp_numrows;
    old_display_attributes = disp_getattr();
    is_mouse_enabled = msm_init();
    form_color = FormColor;
    title_color = 0;
    status_bar_color = 0;
    screen_buffer = new unsigned short[80 * 25];
    title_text = new char[_MAX_DOSFORMS_TITLE + 1];
    status_bar_text = new char[_MAX_DOSFORMS_STATUSBAR + 1];
    is_screen_buffer_used = 0;
    dosforms_inited = 1;

    title_text[0] = NULL;
    status_bar_text[0] = NULL;
    memset( screen_buffer, '\0', 80 * 25 );
}

DOSForms::DOSForms( const unsigned int FormColor, const unsigned int TitleColor, const char* szTitleText )
{
    if ( dosforms_inited != 0 ) {
        return;
    }

    old_display_mode = disp_getmode();

    if ( old_display_mode != 3 || old_display_mode != 7 ) {
        disp_setmode( 3 );
    }

    if ( disp_inited == 0 ) {
        disp_open();
    }

    text_columns = (short)disp_numcols;
    text_rows = (short)disp_numrows;
    old_display_attributes = disp_getattr();
    is_mouse_enabled = msm_init();
    form_color = FormColor;
    title_color = TitleColor;
    status_bar_color = 0;
    screen_buffer = new unsigned short[80 * 25];
    title_text = new char[_MAX_DOSFORMS_TITLE + 1];
    status_bar_text = new char[_MAX_DOSFORMS_STATUSBAR + 1];
    is_screen_buffer_used = 0;
    memset( screen_buffer, '\0', 80 * 25 );

    title_text[0] = NULL;
    status_bar_text[0] = NULL;
    TitleText( szTitleText );
    dosforms_inited = 1;
}

DOSForms::DOSForms( const unsigned int FormColor, const unsigned int TitleColor, const char* szTitleText, const unsigned int StatusBarColor, const char* szStatusBarText )
{
    if ( dosforms_inited != 0 ) {
        return;
    }

    old_display_mode = disp_getmode();

    if ( old_display_mode != 3 || old_display_mode != 7 ) {
        disp_setmode( 3 );
    }

    if ( disp_inited == 0 ) {
        disp_open();
    }

    text_columns = (short)disp_numcols;
    text_rows = (short)disp_numrows;
    old_display_attributes = disp_getattr();
    is_mouse_enabled = msm_init();
    form_color = FormColor;
    title_color = TitleColor;
    status_bar_color = StatusBarColor;
    screen_buffer = new unsigned short[80 * 25];
    title_text = new char[_MAX_DOSFORMS_TITLE + 1];
    status_bar_text = new char[_MAX_DOSFORMS_STATUSBAR + 1];
    is_screen_buffer_used = 0;
    memset( screen_buffer, '\0', 80 * 25 );

    title_text[0] = NULL;
    status_bar_text[0] = NULL;
    TitleText( szTitleText );
    StatusBarText( szStatusBarText );
    dosforms_inited = 1;
}

DOSForms::~DOSForms( void )
{
    if ( is_mouse_enabled ) {
        msm_term();
    }

    if ( disp_inited != 0 ) {
        disp_setattr( old_display_attributes );
        disp_move( 0, 0 );
        disp_eeop();
        disp_close();
        disp_setmode( old_display_mode );
    }

    delete[] title_text;
    delete[] status_bar_text;
    delete[] screen_buffer;

    dosforms_inited = 0;
}

unsigned int DOSForms::FormColor( void ) const
{
    return form_color;
}

unsigned int DOSForms::TitleColor( void ) const
{
    return title_color;
}

unsigned int DOSForms::StatusBarColor( void ) const
{
    return status_bar_color;
}

void DOSForms::TitleColor( const unsigned int Color )
{
    if ( Color == NULL ) {
        return;
    }

    title_color = Color;

    if ( disp_inited == 0 || dosforms_inited == 0 ) {
        return;
    }

    if ( is_mouse_enabled != 0 ) {
        msm_hidecursor();
    }

    disp_move( 0, 0 );
    disp_setattr( title_color );
    disp_eeol();
    disp_setattr( form_color );

    if ( is_mouse_enabled != 0 ) {
        msm_showcursor();
    }
}

void DOSForms::TitleText( const char* Text )
{
    if ( Text == NULL || strlen( Text ) > _MAX_DOSFORMS_TITLE ) {
        return;
    }

    strncpy( title_text, Text, _MAX_DOSFORMS_TITLE );

    if ( disp_inited == 0 || dosforms_inited == 0 ) {
        return;
    }

    if ( is_mouse_enabled != 0 ) {
        msm_hidecursor();
    }

    disp_move( 0, CenterScreen( title_text ) );
    disp_setattr( title_color );
    disp_puts( title_text );
    disp_setattr( form_color );

    if ( is_mouse_enabled != 0 ) {
        msm_showcursor();
    }
}

int DOSForms::RemoveTitleBar( void )
{
    if ( disp_inited == 0 || dosforms_inited == 0 ) {
        return 0;
    }

    if ( is_mouse_enabled != 0 ) {
        msm_hidecursor();
    }

    disp_setattr( form_color );
    disp_move( 0, 0 );
    disp_eeol();

    if ( is_mouse_enabled != 0 ) {
        disp_setattr( title_color );
        disp_move( 0, 0 );
        disp_puts( "[Ä]" ); // ALT+0196
        disp_setattr( form_color );

        msm_showcursor();
    }

    return disp_inited;
}

void DOSForms::StatusBarText( const char* Text )
{
    if ( Text == NULL || strlen( Text ) > _MAX_DOSFORMS_STATUSBAR ) {
        return;
    }

    strncpy( status_bar_text, Text, _MAX_DOSFORMS_STATUSBAR );

    if ( disp_inited == 0 || dosforms_inited == 0 ) {
        return;
    }

    if ( is_mouse_enabled != 0 ) {
        msm_hidecursor();
    }

    disp_move( text_rows - 1, 0 );
    disp_flush();
    disp_setattr( status_bar_color );
    disp_eeol();
    disp_move( text_rows - 1, 1 );
    disp_puts( status_bar_text );
    disp_setattr( form_color );

    if ( is_mouse_enabled != 0 ) {
        msm_showcursor();
    }
}

void DOSForms::StatusBarColor( const unsigned int Color )
{
    if ( Color == NULL ) {
        return;
    }

    status_bar_color = Color;

    if ( disp_inited == 0 || dosforms_inited == 0 ) {
        return;
    }

    if ( is_mouse_enabled != 0 ) {
        msm_hidecursor();
    }

    disp_move( text_rows - 1, 0 );
    disp_flush();
    disp_setattr( status_bar_color );
    disp_eeol();
    disp_setattr( form_color );

    if ( is_mouse_enabled != 0 ) {
        msm_showcursor();
    }
}

int DOSForms::RemoveStatusBar( void )
{
    if ( disp_inited == 0 || dosforms_inited == 0 ) {
        return 0;
    }

    if ( is_mouse_enabled != 0 ) {
        msm_hidecursor();
    }

    disp_setattr( form_color );
    disp_move( text_rows - 1, 0 );
    disp_eeol();

    if ( is_mouse_enabled != 0 ) {
        msm_showcursor();
    }

    return disp_inited;
}

int DOSForms::OpenForm( void )
{
    if ( disp_inited == 0 || dosforms_inited == 0 ) {
        return 0;
    }

    // check for B&W (mono) display and set colors
    /*
    if ( disp_getmode() != 3 ) {
        if ( form_color != WHITE_ON_BLACK ) {
            form_color = WHITE_ON_BLACK;
        }
        if ( title_color != BLACK_ON_WHITE ) {
            title_color = BLACK_ON_WHITE;
        }
        if ( status_bar_color != BLACK_ON_WHITE ) {
            status_bar_color = BLACK_ON_WHITE;
        }
    }
    */

    if ( is_mouse_enabled != 0 ) {
        msm_hidecursor();
    }

    disp_flush();
    disp_move( 0, 0 );
    disp_setattr( form_color );
    disp_eeop();

    if ( is_mouse_enabled != 0 ) {
        msm_showcursor();
    }

    if ( title_color != 0 || title_color != NULL ) {
        TitleColor( title_color );
    }

    if ( title_text != NULL ) {
        TitleText( title_text );
    }

    if ( is_mouse_enabled != 0 ) {
        msm_hidecursor();
        disp_setattr( title_color );
        disp_move( 0, 0 );
        disp_puts( "[Ä]" ); // ALT+0196
        msm_showcursor();
    }

    disp_setattr( form_color );

    if ( status_bar_color != 0 || status_bar_color != NULL ) {
        StatusBarText( status_bar_text );
    }

    return disp_inited;
}

int DOSForms::DrawButton( const Window window )
{
    if ( disp_inited == 0 || dosforms_inited == 0 ) {
        return 0;
    }

    if ( window.Top() != window.Bottom() ) {
        disp_fillbox( __BLACK * 256 + ' ', window.Top() + 1, window.Left() + 2, window.Bottom() + 1, window.Right() + 2 );
    }
    disp_fillbox( window.Color() * 256 + ' ', window.Top(), window.Left(), window.Bottom(), window.Right() );

    if ( window.Label() != NULL ) {
        if ( window.Top() != window.Bottom() ) {
            // center formula: ( strlen( Text ) + text_columns ) / 2 - strlen( Text )
            unsigned int row = ( window.Top() + window.Bottom() ) / 2;
            unsigned int col = ( strlen( window.Label() ) + window.Left() + window.Right() ) / 2 - strlen( window.Label() ) + 1;
            disp_move( row, col );
            disp_setattr( window.Color() );
            disp_puts( window.Label() );
        }
        else {
            unsigned int col = ( strlen( window.Label() ) + window.Left() + window.Right() ) / 2 - strlen( window.Label() ) + 1;
            disp_move( window.Top(), col );
            disp_setattr( window.Color() );
            disp_puts( window.Label() );
        }

        disp_setattr( form_color );
    }

    return disp_inited;
}

// popup window
int DOSForms::OpenPopupWindow( const Window window )
{
    if ( disp_inited == 0 || dosforms_inited == 0 ) {
        return 0;
    }

    if ( is_screen_buffer_used != 0 ) {
        return 0;
    }

    if ( is_mouse_enabled != 0 ) {
        msm_hidecursor();
    }

    disp_peekbox( screen_buffer, 3, 5, 22, 75 ); // save current contents to buffer
    disp_fillbox( __BLACK * 256 + ' ', 4, 6, 22, 75 ); // draw drop shadow
    disp_box( 1, window.Color(), 3, 5, 21, 74 ); //draw popup
    disp_fillbox( window.Color() * 256 + ' ', 4, 6, 20, 73 ); // fill popup box

    // set title if specified
    if ( window.Title() != NULL ) {
        disp_setattr( window.Color() );

        if ( window.TitleJustify() == 'R' ) {
            disp_move( 3, 74 - strlen( window.Title() ) - 3 );
        }
        else if ( window.TitleJustify() == 'C' ) {
            disp_move( 3, ( strlen( window.Title() ) + 74 ) / 2 - strlen( window.Title() ) );
        }
        else {
            disp_move( 3, 7 );
        }

        disp_printf( " %s ", window.Title() );

        if ( form_color != NULL ) {
            disp_setattr( form_color );
        }
    }

    if ( is_mouse_enabled != 0 ) {
        msm_showcursor();
    }

    is_screen_buffer_used = 1;
    return disp_inited;
}

int DOSForms::ClosePopupWindow( void )
{
    if ( disp_inited == 0 || dosforms_inited == 0 ) {
        return 0;
    }

    if ( is_screen_buffer_used == 0 ) {
        return 0;
    }

    if ( is_mouse_enabled != 0 ) {
        msm_hidecursor();
    }

    disp_pokebox( screen_buffer, 3, 5, 22, 75 );
    memset( screen_buffer, '\0', sizeof( screen_buffer ) );

    if ( is_mouse_enabled != 0 ) {
        msm_showcursor();
    }

    is_screen_buffer_used = 0;

    return disp_inited;
}

// message box
// Window window provides color, coordinates, and Label provides dialog text
// return 0 on error, or number of button pressed
short DOSForms::MessageBox( const Window window, const DIALOG_BUTTONS Buttons, unsigned int ButtonColor ) const
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

// clear screen
int DOSForms::ClearScreen( void )
{
    if ( disp_inited == 0 ) {
        return 0;
    }

    if ( is_mouse_enabled != 0 ) {
        msm_hidecursor();
    }

    disp_move( 0, 0 );
    disp_eeop();
    disp_setattr( form_color );

    if ( is_mouse_enabled != 0 ) {
        msm_showcursor();
    }

    return disp_inited;
}

// clear text from line
int DOSForms::ClearRow( const unsigned int row )
{
    if ( disp_inited == 0 ) {
        return 0;
    }

    if ( is_mouse_enabled != 0 ) {
        msm_hidecursor();
    }

    for ( unsigned int i = 0; i < text_columns; ++i ) {
        disp_move( row, i );
        disp_putc( ' ' );
    }

    if ( is_mouse_enabled != 0 ) {
        msm_showcursor();
    }

    return disp_inited;
}

unsigned int DOSForms::CenterScreen( const char* Text ) const
{
    return ( strlen( Text ) + text_columns ) / 2 - strlen( Text );
}

int DOSForms::IsMouseEnabled( void ) const
{
    return is_mouse_enabled;
}

char* DOSForms::TitleText( void ) const
{
    return title_text;
}

char* DOSForms::StatusBarText( void ) const
{
    return status_bar_text;
}

#elif ( _MSC_VER || __WATCOMC__ )
///
/// ***********************************
/// Microsoft / Open WatCom compatible
/// ***********************************
///

DOSForms::DOSForms( void )
{
    struct videoconfig vc;
    _getvideoconfig( &vc );

    text_columns = vc.numtextcols;
    text_rows = vc.numtextrows;
    old_display_mode = vc.mode;
    old_text_display = _gettextcolor();
    old_background_display = _getbkcolor();
    old_text_cursor = _settextcursor( 0x2000 );

    if ( old_display_mode != _TEXTBW80 || old_display_mode != _TEXTC80 ) {
        _setvideomode( _TEXTC80 ) == 0 ? _setvideomode( _TEXTBW80 ) == 0 ? is_display_inited = 0 : is_display_inited = 1 : is_display_inited = 1;
    }
    else {
        is_display_inited = 1;
    }

    title_text = new char[_MAX_DOSFORMS_TITLE + 1];
    status_bar_text = new char[_MAX_DOSFORMS_STATUSBAR + 1];
    form_text_color = 1;
    form_background_color = 7;
    title_text_color = 0;
    title_background_color = 0L;
    status_bar_text_color = 0;
    status_bar_background_color = 0L;

    mouse_inited = 0;
    mouse_visible = 0;
    mouse_position_x = 0;
    mouse_position_y = 0;

    *title_text = NULL;
    *status_bar_text = NULL;

    union REGS regs;
    struct SREGS sregs;
    // Check to see if the mouse driver is safe to call
    // Get interrupt vector
    regs.h.ah = 0x35;
    regs.h.al = 33;
    int86x( 0x21, &regs, &regs, &sregs );
    if ( ( sregs.es | regs.x.bx ) == 0 ) {
        return;
    }

    regs.x.ax = 0x0000; // reset mouse driver
    int86( 0x33, &regs, &regs );
    if ( regs.x.ax == 0 ) {
        return;
    }

    // despite documentation saying success should be 0x0020,
    // testing has shown successful result is 0xffff
    regs.x.ax = 0x0020;     // enable mouse driver
    int86( 0x33, &regs, &regs );
    if ( regs.x.ax != 0xffff ) {
        return;
    }

    mouse_inited = 1;
}

DOSForms::DOSForms( const short FormTextColor, const long FormBackgroundColor )
{
    struct videoconfig vc;
    _getvideoconfig( &vc );

    text_columns = vc.numtextcols;
    text_rows = vc.numtextrows;
    old_display_mode = vc.mode;
    old_text_display = _gettextcolor();
    old_background_display = _getbkcolor();
    old_text_cursor = _settextcursor( 0x2000 );

    if ( old_display_mode != _TEXTBW80 || old_display_mode != _TEXTC80 ) {
        _setvideomode( _TEXTC80 ) == 0 ? _setvideomode( _TEXTBW80 ) == 0 ? is_display_inited = 0 : is_display_inited = 1 : is_display_inited = 1;
    }
    else {
        is_display_inited = 1;
    }

    title_text = new char[_MAX_DOSFORMS_TITLE + 1];
    status_bar_text = new char[_MAX_DOSFORMS_STATUSBAR + 1];
    form_text_color = FormTextColor;
    form_background_color = FormBackgroundColor;
    title_text_color = 0;
    title_background_color = 0L;
    status_bar_text_color = 0;
    status_bar_background_color = 0L;

    mouse_inited = 0;
    mouse_visible = 0;
    mouse_position_x = 0;
    mouse_position_y = 0;

    *title_text = NULL;
    *status_bar_text = NULL;

    union REGS regs;
    struct SREGS sregs;
    // Check to see if the mouse driver is safe to call
    // Get interrupt vector
    regs.h.ah = 0x35;
    regs.h.al = 33;
    int86x( 0x21, &regs, &regs, &sregs );
    if ( ( sregs.es | regs.x.bx ) == 0 ) {
        return;
    }

    regs.x.ax = 0x0000; // reset mouse driver
    int86( 0x33, &regs, &regs );
    if ( regs.x.ax == 0 ) {
        return;
    }

    // despite documentation saying success should be 0x0020,
    // testing has shown successful result is 0xffff
    regs.x.ax = 0x0020;     // enable mouse driver
    int86( 0x33, &regs, &regs );
    if ( regs.x.ax != 0xffff ) {
        return;
    }

    mouse_inited = 1;
}

DOSForms::DOSForms( const short FormTextColor, const long FormBackgroundColor, const short TitleTextColor, const long TitleBackgroundColor, const char* TitleText )
{
    struct videoconfig vc;
    _getvideoconfig( &vc );

    text_columns = vc.numtextcols;
    text_rows = vc.numtextrows;
    old_display_mode = vc.mode;
    old_text_display = _gettextcolor();
    old_background_display = _getbkcolor();
    old_text_cursor = _settextcursor( 0x2000 );

    if ( old_display_mode != _TEXTBW80 || old_display_mode != _TEXTC80 ) {
        _setvideomode( _TEXTC80 ) == 0 ? _setvideomode( _TEXTBW80 ) == 0 ? is_display_inited = 0 : is_display_inited = 1 : is_display_inited = 1;
    }
    else {
        is_display_inited = 1;
    }

    title_text = new char[_MAX_DOSFORMS_TITLE + 1];
    status_bar_text = new char[_MAX_DOSFORMS_STATUSBAR + 1];
    form_text_color = FormTextColor;
    form_background_color = FormBackgroundColor;
    title_text_color = TitleTextColor;
    title_background_color = TitleBackgroundColor;
    status_bar_text_color = 0;
    status_bar_background_color = 0L;

    mouse_inited = 0;
    mouse_visible = 0;
    mouse_position_x = 0;
    mouse_position_y = 0;

    *title_text = NULL;
    *status_bar_text = NULL;
    strncpy( title_text, TitleText, _MAX_DOSFORMS_TITLE );

    union REGS regs;
    struct SREGS sregs;
    // Check to see if the mouse driver is safe to call
    // Get interrupt vector
    regs.h.ah = 0x35;
    regs.h.al = 33;
    int86x( 0x21, &regs, &regs, &sregs );
    if ( ( sregs.es | regs.x.bx ) == 0 ) {
        return;
    }

    regs.x.ax = 0x0000; // reset mouse driver
    int86( 0x33, &regs, &regs );
    if ( regs.x.ax == 0 ) {
        return;
    }

    // despite documentation saying success should be 0x0020,
    // testing has shown successful result is 0xffff
    regs.x.ax = 0x0020;     // enable mouse driver
    int86( 0x33, &regs, &regs );
    if ( regs.x.ax != 0xffff ) {
        return;
    }

    mouse_inited = 1;
}

DOSForms::~DOSForms( void )
{
    delete[] status_bar_text;
    delete[] title_text;
    _setvideomode( old_display_mode );
    _settextcolor( old_text_display );
    _setbkcolor( old_background_display );
    _settextcursor( old_text_cursor );
}

char* DOSForms::TitleText( void ) const
{
    return title_text;
}

char* DOSForms::StatusBarText( void ) const
{
    return status_bar_text;
}

short DOSForms::FormTextColor( void ) const
{
    return form_text_color;
}

long DOSForms::FormBackgroundColor( void ) const
{
    return form_background_color;
}

short DOSForms::TitleTextColor( void ) const
{
    return title_text_color;
}

long DOSForms::TitleBackgroundColor( void ) const
{
    return title_background_color;
}

short DOSForms::StatusBarTextColor( void ) const
{
    return status_bar_text_color;
}

long DOSForms::StatusBarBackgroundColor( void ) const
{
    return status_bar_background_color;
}

void DOSForms::TitleTextColor( const short Color )
{
    if ( Color == NULL ) {
        return;
    }

    title_text_color = Color;

    if ( is_display_inited != 0 ) {
        if ( mouse_inited != 0 ) {
            HideMouse();
        }

        _settextcolor( title_text_color );
        _setbkcolor( title_background_color );
        _settextwindow( 1, 1, 1, text_columns );

        if ( title_text != NULL ) {
            TitleText( title_text );
        }

        _settextcolor( form_text_color );
        _setbkcolor( form_background_color );
        _settextwindow( 1, 1, text_rows, text_columns );

        if ( mouse_inited != 0 ) {
            ShowMouse();
        }
    }
}

void DOSForms::TitleBackgroundColor( const long Color )
{
    if ( Color == NULL ) {
        return;
    }

    title_background_color = Color;

    if ( is_display_inited != 0 ) {
        if ( mouse_inited != 0 ) {
            HideMouse();
        }

        _settextcolor( title_text_color );
        _setbkcolor( title_background_color );
        _settextwindow( 1, 1, 1, text_columns );

        if ( title_text != NULL ) {
            TitleText( title_text );
        }

        _settextcolor( form_text_color );
        _setbkcolor( form_background_color );
        _settextwindow( 1, 1, text_rows, text_columns );

        if ( mouse_inited != 0 ) {
            ShowMouse();
        }
    }
}

void DOSForms::TitleText( const char* Text )
{
    if ( Text == NULL ) {
        return;
    }

    strncpy( title_text, Text, _MAX_DOSFORMS_TITLE );

    if ( is_display_inited != 0 ) {
        if ( mouse_inited != 0 ) {
            HideMouse();
        }

        _settextcolor( title_text_color );
        _setbkcolor( title_background_color );
        _settextwindow( 1, 1, 1, text_columns );
        _clearscreen( _GWINDOW );
        _settextposition( 1, CenterScreen( title_text ) );
        _outtext( title_text );

        _settextcolor( form_text_color );
        _setbkcolor( form_background_color );
        _settextwindow( 1, 1, text_rows, text_columns );

        if ( mouse_inited != 0 ) {
            ShowMouse();
        }
    }
}

void DOSForms::StatusBarTextColor( const short Color )
{
    if ( Color == NULL ) {
        return;
    }

    status_bar_text_color = Color;

    if ( is_display_inited != 0 ) {
        if ( mouse_inited != 0 ) {
            HideMouse();
        }

        _settextcolor( status_bar_text_color );
        _setbkcolor( status_bar_background_color );
        _settextwindow( text_rows, 1, text_rows, text_columns );
        _clearscreen( _GWINDOW );

        if ( status_bar_text != NULL ) {
            StatusBarText( status_bar_text );
        }

        _settextcolor( form_text_color );
        _setbkcolor( form_background_color );
        _settextwindow( 1, 1, text_rows, text_columns );

        if ( mouse_inited != 0 ) {
            ShowMouse();
        }
    }
}

void DOSForms::StatusBarBackgroundColor( const long Color )
{
    if ( Color == NULL ) {
        return;
    }

    status_bar_background_color = Color;

    if ( is_display_inited != 0 ) {
        if ( mouse_inited != 0 ) {
            HideMouse();
        }

        _settextcolor( status_bar_text_color );
        _setbkcolor( status_bar_background_color );
        _settextwindow( text_rows, 1, text_rows, text_columns );
        _clearscreen( _GWINDOW );

        if ( status_bar_text != NULL ) {
            StatusBarText( status_bar_text );
        }

        _settextcolor( form_text_color );
        _setbkcolor( form_background_color );
        _settextwindow( 1, 1, text_rows, text_columns );

        if ( mouse_inited != 0 ) {
            ShowMouse();
        }
    }
}


void DOSForms::StatusBarText( const char* Text )
{
    if ( Text == NULL ) {
        return;
    }

    strncpy( status_bar_text, Text, _MAX_DOSFORMS_STATUSBAR );

    if ( is_display_inited != 0 ) {
        if ( mouse_inited != 0 ) {
            HideMouse();
        }

        _settextcolor( status_bar_text_color );
        _setbkcolor( status_bar_background_color );
        _settextwindow( text_rows, 1, text_rows, text_columns );
        _clearscreen( _GWINDOW );
        _settextposition( text_rows, CenterScreen( status_bar_text ) );
        _outtext( status_bar_text );

        _settextcolor( form_text_color );
        _setbkcolor( form_background_color );
        _settextwindow( 1, 1, text_rows, text_columns );

        if ( mouse_inited != 0 ) {
            ShowMouse();
        }
    }
}

void DOSForms::ClearScreen( void )
{
    OpenForm();
}

void DOSForms::ClearRow( unsigned int row )
{
    if ( is_display_inited == 0 ) {
        return;
    }

    if ( row > (unsigned int)text_rows ) {
        return;
    }

    if ( mouse_inited != 0 ) {
        HideMouse();
    }

    _settextcolor( form_text_color );
    _setbkcolor( form_background_color );
    _settextwindow( row, 1, row, text_columns );
    _clearscreen( _GWINDOW );

    _settextwindow( 1, 1, text_rows, text_columns );

    if ( mouse_inited != 0 ) {
        ShowMouse();
    }
}

unsigned int DOSForms::CenterScreen( char* Text ) const
{
    return ( strlen( Text ) + text_columns ) / 2 - strlen( Text );
}

int DOSForms::OpenForm( void )
{
    if ( is_display_inited == 0 ) {
        fputs( "Failed to initialize display!\n", stderr );
        return is_display_inited;
    }

    if ( mouse_inited != 0 ) {
        HideMouse();
    }

    _settextcolor( form_text_color );
    _setbkcolor( form_background_color );
    _clearscreen( _GCLEARSCREEN );

    if ( mouse_inited != 0 ) {
        ShowMouse();
    }

    if ( title_text_color != 0 || title_background_color != 0 ) {
        TitleTextColor( title_text_color );
        TitleBackgroundColor( title_background_color );
    }

    if ( title_text != NULL ) {
        TitleText( title_text );
    }

    if ( mouse_inited != 0 ) {
        if ( title_text_color != 0 && title_background_color != 0 ) {
            _settextcolor( title_text_color );
            _setbkcolor( title_background_color );
        }
        else {
            _settextcolor( form_text_color );
            _setbkcolor( form_background_color );
        }

        _settextposition( 1, 1 );
        _outtext( "[Ä]" ); // ALT+0196
    }

    if ( status_bar_text != NULL ) {
        StatusBarText( status_bar_text );
    }

    _settextcolor( form_text_color );
    _setbkcolor( form_background_color );

    return is_display_inited;
}

void DOSForms::WriteLine( const short Row, const short Column, const char* Text )
{
    if ( Text == NULL ) {
        return;
    }

    if ( is_display_inited != 0 ) {
        if ( mouse_inited != 0 ) {
            HideMouse();
        }

        if ( title_text_color == 0 && title_background_color == 0 && status_bar_text_color == 0 && status_bar_background_color == 0 ) {
            _settextwindow( 1, 1, text_rows, text_columns );
        }
        else if ( title_text_color != 0 && title_background_color != 0 && status_bar_text_color == 0 && status_bar_background_color == 0 ) {
            _settextwindow( 2, 1, text_rows, text_columns );
        }
        else if ( title_text_color == 0 && title_background_color == 0 && status_bar_text_color != 0 && status_bar_background_color != 0 ) {
            _settextwindow( 1, 1, text_rows - 1, text_columns );
        }
        else {
            _settextwindow( 2, 1, text_rows - 1, text_columns );
        }

        char *buffer = new char[text_columns + 1];
        strncpy( buffer, Text, text_columns - Column - 1 );

        _settextcolor( form_text_color );
        _setbkcolor( form_background_color );
        _settextposition( Row, Column );
        _outtext( buffer );
        delete[] buffer;
        _settextwindow( 1, 1, text_rows, text_columns );

        if ( mouse_inited != 0 ) {
            ShowMouse();
        }
    }
}

void DOSForms::RemoveTitleBar( void )
{
    if ( is_display_inited != 0 ) {
        if ( mouse_inited != 0 ) {
            HideMouse();
        }

        _settextwindow( 1, 1, 1, text_columns );
        _settextcolor( form_text_color );
        _setbkcolor( form_background_color );
        _clearscreen( _GWINDOW );

        title_text_color = 0;
        title_background_color = 0L;
        title_text = NULL;
        _settextwindow( 1, 1, text_rows, text_columns );

        if ( mouse_inited != 0 ) {
            ShowMouse();
        }
    }
}

void DOSForms::RemoveStatusBar( void )
{
    if ( is_display_inited != 0 ) {
        if ( mouse_inited != 0 ) {
            HideMouse();
        }

        _settextwindow( text_rows, 1, text_rows, text_columns );
        _settextcolor( form_text_color );
        _setbkcolor( form_background_color );
        _clearscreen( _GWINDOW );

        status_bar_text_color = 0;
        status_bar_background_color = 0L;
        status_bar_text = NULL;
        _settextwindow( 1, 1, text_rows, text_columns );

        if ( mouse_inited != 0 ) {
            ShowMouse();
        }
    }
}

int DOSForms::DrawButton( const Window window )
{
    if ( is_display_inited == 0 ) {
        return -1;
    }

    if ( mouse_inited != 0 ) {
        HideMouse();
    }

    if ( window.DropShadow() != 0 ) {
        _settextcolor( 0 );
        _setbkcolor( 0 );
        _settextwindow( window.Top() + 1, window.Left() + 2, window.Bottom() + 1, window.Right() + 2 );
        _clearscreen( _GWINDOW );
    }

    _settextcolor( window.TextColor() );
    _setbkcolor( window.BackgroundColor() );
    _settextwindow( window.Top(), window.Left(), window.Bottom(), window.Right() );
    _clearscreen( _GWINDOW );

    _settextwindow( 1, 1, text_rows, text_columns );
    short button_row = (short)( window.Top() + window.Bottom() ) / 2;
    short button_column = (short)( window.Left() + window.Right() + strlen( window.Label() ) ) / 2 - strlen( window.Label() ) + 1;
    _settextposition( button_row, button_column );
    _outtext( window.Label() );

    _settextcolor( form_text_color );
    _setbkcolor( form_background_color );

    if ( mouse_inited != 0 ) {
        ShowMouse();
    }

    return 1;
}

int DOSForms::OpenPopupWindow( const Window window )
{
    if ( is_display_inited == 0 ) {
        return -1;
    }

    if ( mouse_inited != 0 ) {
        HideMouse();
    }

    // add code here

    if ( mouse_inited != 0 ) {
        ShowMouse();
    }

    return 1;
}

int DOSForms::ClosePopupWindow( void )
{
    if ( is_display_inited == 0 ) {
        return -1;
    }

    if ( mouse_inited != 0 ) {
        HideMouse();
    }

    // add code here

    if ( mouse_inited != 0 ) {
        ShowMouse();
    }

    return 1;
}

DIALOG_BUTTON DOSForms::MessageBox( const Window& window, const DIALOG_BUTTON Buttons, unsigned int ButtonColor )
{
    if ( mouse_inited != 0 ) {
        HideMouse();
    }

    // add code here

    if ( mouse_inited != 0 ) {
        ShowMouse();
    }

    return BTN_OK;
}

//
// Mouse methods
//
int DOSForms::IsMouseEnabled( void ) const
{
    return mouse_inited;
}

void DOSForms::ShowMouse( void )
{
    if ( mouse_visible != 0 || mouse_inited == 0 ) {
        return;
    }

    union REGS regs;
    regs.x.ax = 0x0001;
    int86( 0x33, &regs, &regs );
    mouse_visible = 1;
}

void DOSForms::HideMouse( void )
{
    if ( mouse_visible == 0 || mouse_inited == 0 ) {
        return;
    }

    union REGS regs;
    regs.x.ax = 0x0002;
    int86( 0x33, &regs, &regs );
    mouse_visible = 0;
}

// Function: MouseStatus()
// return value is state of buttons as bit pattern
// bit 0: left button ( 1 == down, 0 == up )
// bit 1: right button ( 1 == down, 0 == up )
// bit 2: center button ( 1 == down, 0 == up )
// e.g.: 0000000000000011 = mouse left and right pressed down
// e.g.: 0000000000000010 = right button pressed down
// other bits should be ignored
int DOSForms::MouseStatus( void )
{
    if ( mouse_inited == 0 ) {
        return -1;
    }

    union REGS regs;
    regs.x.ax = 0x0003;
    int86( 0x33, &regs, &regs );
    mouse_position_x = regs.x.cx;
    mouse_position_y = regs.x.dx;
    return regs.x.bx;
}

void DOSForms::MousePosition( const unsigned x, const unsigned y )
{
    if ( mouse_inited == 0 ) {
        return;
    }

    unsigned char mouseX;
    unsigned char mouseY;
    sprintf( (char*)&mouseX, "%x", x ); // converts X to hex value?
    sprintf( (char*)&mouseY, "%x", y ); // converts Y to hex value?

    union REGS regs;
    regs.x.ax = 0x0004;
    regs.x.cx = mouseX;
    regs.x.dx = mouseY;
    int86( 0x33, &regs, &regs );
}

// Function: MousePress()
// return value is state of buttons as bit pattern
// bit 0: left button ( 1 == down, 0 == up )
// bit 1: right button ( 1 == down, 0 == up )
// bit 2: center button ( 1 == down, 0 == up )
// other bits should be ignored
// button = button to query since last call to MousePress()
// x = column position of last press
// y = row position of last press
int DOSForms::MousePress( unsigned button, unsigned x, unsigned y ) const
{
    if ( mouse_inited == 0 ) {
        return -1;
    }

    if ( button > 2 ) {
        return -2;
    }

    union REGS regs;
    regs.x.ax = 0x0005;
    regs.x.bx = button;
    int86( 0x33, &regs, &regs );
    button = regs.x.bx;
    x = regs.x.cx;
    y = regs.x.dx;
    return regs.x.ax;
}

// Function: MouseRelease()
// return value is state of buttons as bit pattern
// bit 0: left button ( 1 == down, 0 == up )
// bit 1: right button ( 1 == down, 0 == up )
// bit 2: center button ( 1 == down, 0 == up )
// other bits should be ignored
// button = button to query since last call to MouseRelease()
// x = column position of last release
// y = row position of last release
int DOSForms::MouseRelease( unsigned button, unsigned x, unsigned y ) const
{
    if ( mouse_inited == 0 ) {
        return -1;
    }

    if ( button > 2 ) {
        return -2;
    }

    union REGS regs;
    regs.x.ax = 0x0006;
    regs.x.bx = button;
    int86( 0x33, &regs, &regs );
    button = regs.x.bx;
    x = regs.x.cx;
    y = regs.x.dx;
    return regs.x.ax;
}

// Function: MouseAreaX
// defines min and max mouse position on the X axis
void DOSForms::MouseAreaX( const unsigned min, const unsigned max )
{
    if ( mouse_inited == 0 ) {
        return;
    }

    unsigned char minimum;
    unsigned char maximum;
    sprintf( (char*)&minimum, "%x", min ); // converts min to hex?
    sprintf( (char*)&maximum, "%x", max ); // converts max to hex?

    union REGS regs;
    regs.x.ax = 0x0007;
    regs.x.cx = minimum;
    regs.x.dx = maximum;
    int86( 0x33, &regs, &regs );
}

// Function: MouseAreaY
// defines min and max mouse position on the Y axis
void DOSForms::MouseAreaY( const unsigned min, const unsigned max )
{
    if ( mouse_inited == 0 ) {
        return;
    }

    unsigned char minimum;
    unsigned char maximum;
    sprintf( (char*)&minimum, "%x", min ); // converts min to hex?
    sprintf( (char*)&maximum, "%x", max ); // converts max to hex?

    union REGS regs;
    regs.x.ax = 0x0008;
    regs.x.cx = minimum;
    regs.x.dx = maximum;
    int86( 0x33, &regs, &regs );
}

// Function: ReadMouseCounters
// returns x and y of mouse motion in mickeys
void DOSForms::ReadMouseCounters( int x, int y )
{
    if ( mouse_inited == 0 ) {
        return;
    }

    union REGS regs;
    regs.x.ax = 0x000b;
    int86( 0x33, &regs, &regs );
    x = regs.x.cx;
    y = regs.x.dx;
}

#endif // __SC__
