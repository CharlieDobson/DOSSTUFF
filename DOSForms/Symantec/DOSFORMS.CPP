// dosforms.cpp : class implementation file

#include "dosforms.hpp"

const unsigned short max_dosforms_title = 35;
const unsigned short max_dosforms_statusbar = 78;

static short dosforms_inited = 0;

DOSForms::DOSForms( void )
{
    if ( dosforms_inited ) {
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
    screen_buffer = new unsigned short[text_columns * text_rows];
    title_text = new char[max_dosforms_title + 1];
    status_bar_text = new char[max_dosforms_statusbar + 1];
    is_screen_buffer_used = 0;
    dosforms_inited = 1;

    title_text[0] = NULL;
    status_bar_text[0] = NULL;
    memset( screen_buffer, '\0', text_columns * text_rows );
}

DOSForms::DOSForms( const unsigned int FormColor )
{
    if ( dosforms_inited ) {
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
    screen_buffer = new unsigned short[text_columns * text_rows];
    title_text = new char[max_dosforms_title + 1];
    status_bar_text = new char[max_dosforms_statusbar + 1];
    is_screen_buffer_used = 0;
    dosforms_inited = 1;

    title_text[0] = NULL;
    status_bar_text[0] = NULL;
    memset( screen_buffer, '\0', text_columns * text_rows );
}

DOSForms::DOSForms( const unsigned int FormColor, const unsigned int TitleColor, const char* szTitleText )
{
    if ( dosforms_inited ) {
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
    screen_buffer = new unsigned short[text_columns * text_rows];
    title_text = new char[max_dosforms_title + 1];
    status_bar_text = new char[max_dosforms_statusbar + 1];
    is_screen_buffer_used = 0;
    memset( screen_buffer, '\0', text_columns * text_rows );

    title_text[0] = NULL;
    status_bar_text[0] = NULL;
    TitleText( szTitleText );
    dosforms_inited = 1;
}

DOSForms::DOSForms( const unsigned int FormColor, const unsigned int TitleColor, const char* szTitleText, const unsigned int StatusBarColor, const char* szStatusBarText )
{
    if ( dosforms_inited ) {
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
    screen_buffer = new unsigned short[text_columns * text_rows];
    title_text = new char[max_dosforms_title + 1];
    status_bar_text = new char[max_dosforms_statusbar + 1];
    is_screen_buffer_used = 0;
    memset( screen_buffer, '\0', text_columns * text_rows );

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
        disp_showcursor();
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
    if ( Text == NULL || strlen( Text ) > max_dosforms_title ) {
        return;
    }

    strncpy( title_text, Text, max_dosforms_title );

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
        disp_puts( "[]" ); // ALT+0196
        disp_setattr( form_color );

        msm_showcursor();
    }

    return disp_inited;
}

void DOSForms::StatusBarText( const char* Text )
{
    if ( Text == NULL || strlen( Text ) > max_dosforms_statusbar ) {
        return;
    }

    strncpy( status_bar_text, Text, max_dosforms_statusbar );

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

    disp_hidecursor();

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
        disp_puts( "[]" ); // ALT+0196
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
        disp_fillbox( __BLACK * 256 + ' ', window.Top() + 1, window.Left() + 1, window.Bottom() + 1, window.Right() + 1 );
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
