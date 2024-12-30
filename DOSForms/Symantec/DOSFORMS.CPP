// dosforms.cpp : class implementation file

#include "dosforms.hpp"

static short dosforms_inited = 0;

DOSForms::DOSForms( void )
{
    if ( dosforms_inited ) {
        return;
    }

    m_old_display_mode = disp_getmode();

    if ( m_old_display_mode != 3 || m_old_display_mode != 7 ) {
        disp_setmode( 3 );
    }

    if ( disp_inited == 0 ) {
        disp_open();
    }

    m_mouse_inited = msm_init();

    m_text_columns = disp_numcols;
    m_text_rows = disp_numrows;
    m_old_display_attributes = disp_getattr();
    m_forms_colors.foreground = FG_BLUE;
    m_forms_colors.background = BG_WHITE;
    m_title_colors.foreground = FG_WHITE;
    m_title_colors.background = BG_BLUE;
    m_status_bar_colors.foreground = FG_YELLOW;
    m_status_bar_colors.background = BG_BLUE;
    m_screen_buffer = new unsigned short[m_text_columns * m_text_rows];
    m_title_text = new char[m_text_columns / 2];
    m_status_bar_text = new char[m_text_columns - 2];
    m_mouse_control = new char[4];
    is_screen_buffer_used = 0;
    has_title_bar = FALSE;
    has_status_bar = FALSE;
    dosforms_inited = 1;

    m_title_text[0] = '\0';
    m_status_bar_text[0] = '\0';
    memset( m_screen_buffer, '\0', m_text_columns * m_text_rows );
    sprintf( m_mouse_control, "[%c]", 196 ); // 196 - ASCII "em dash"
}

DOSForms::DOSForms( const foreground_colors_t FormForeground, const background_colors_t FormBackground )
{
    if ( dosforms_inited ) {
        return;
    }

    m_old_display_mode = disp_getmode();

    if ( m_old_display_mode != 3 || m_old_display_mode != 7 ) {
        disp_setmode( 3 );
    }

    if ( disp_inited == 0 ) {
        disp_open();
    }

    m_mouse_inited = msm_init();

    m_text_columns = disp_numcols;
    m_text_rows = disp_numrows;
    m_old_display_attributes = disp_getattr();
    m_forms_colors.foreground = FormForeground;
    m_forms_colors.background = FormBackground;
    m_title_colors.foreground = FG_WHITE;
    m_title_colors.background = BG_BLUE;
    m_status_bar_colors.foreground = FG_YELLOW;
    m_status_bar_colors.background = BG_BLUE;
    m_screen_buffer = new unsigned short[m_text_columns * m_text_rows];
    m_title_text = new char[m_text_columns / 2];
    m_status_bar_text = new char[m_text_columns - 2];
    m_mouse_control = new char[4];
    is_screen_buffer_used = 0;
    has_title_bar = FALSE;
    has_status_bar = FALSE;
    dosforms_inited = 1;

    m_title_text[0] = '\0';
    m_status_bar_text[0] = '\0';
    memset( m_screen_buffer, '\0', m_text_columns * m_text_rows );
    sprintf( m_mouse_control, "[%c]", 196 ); // 196 - ASCII "em dash"
}

DOSForms::DOSForms( const foreground_colors_t FormForeground, const background_colors_t FormBackground, const foreground_colors_t TitleForeground, const background_colors_t TitleBackground, const char* TitleText )
{
    if ( dosforms_inited ) {
        return;
    }

    m_old_display_mode = disp_getmode();

    if ( m_old_display_mode != 3 || m_old_display_mode != 7 ) {
        disp_setmode( 3 );
    }

    if ( disp_inited == 0 ) {
        disp_open();
    }

    m_mouse_inited = msm_init();

    m_text_columns = disp_numcols;
    m_text_rows = disp_numrows;
    m_old_display_attributes = disp_getattr();
    m_forms_colors.foreground = FormForeground;
    m_forms_colors.background = FormBackground;
    m_title_colors.foreground = TitleForeground;
    m_title_colors.background = TitleBackground;
    m_status_bar_colors.foreground = FG_YELLOW;
    m_status_bar_colors.background = BG_BLUE;
    m_screen_buffer = new unsigned short[m_text_columns * m_text_rows];
    m_title_text = new char[m_text_columns / 2];
    m_status_bar_text = new char[m_text_columns - 2];
    m_mouse_control = new char[4];
    is_screen_buffer_used = 0;
    has_title_bar = TRUE;
    has_status_bar = FALSE;
    dosforms_inited = 1;

    strncpy( m_title_text, TitleText, m_text_columns / 2 );
    m_status_bar_text[0] = '\0';
    memset( m_screen_buffer, '\0', m_text_columns * m_text_rows );
    sprintf( m_mouse_control, "[%c]", 196 ); // 196 - ASCII "em dash"
}

DOSForms::DOSForms( const foreground_colors_t FormForeground, const background_colors_t FormBackground, const foreground_colors_t TitleForeground, const background_colors_t TitleBackground, const char* TitleText, const foreground_colors_t StatusBarForeground, const background_colors_t StatusBarBackground )
{
    if ( dosforms_inited ) {
        return;
    }

    m_old_display_mode = disp_getmode();

    if ( m_old_display_mode != 3 || m_old_display_mode != 7 ) {
        disp_setmode( 3 );
    }

    if ( disp_inited == 0 ) {
        disp_open();
    }

    m_mouse_inited = msm_init();

    m_text_columns = disp_numcols;
    m_text_rows = disp_numrows;
    m_old_display_attributes = disp_getattr();
    m_forms_colors.foreground = FormForeground;
    m_forms_colors.background = FormBackground;
    m_title_colors.foreground = TitleForeground;
    m_title_colors.background = TitleBackground;
    m_status_bar_colors.foreground = StatusBarForeground;
    m_status_bar_colors.background = StatusBarBackground;
    m_screen_buffer = new unsigned short[m_text_columns * m_text_rows];
    m_title_text = new char[m_text_columns / 2];
    m_status_bar_text = new char[m_text_columns - 2];
    m_mouse_control = new char[4];
    is_screen_buffer_used = 0;
    has_title_bar = TRUE;
    has_status_bar = TRUE;
    dosforms_inited = 1;

    strncpy( m_title_text, TitleText, m_text_columns / 2 );
    m_status_bar_text[0] = '\0';
    memset( m_screen_buffer, '\0', m_text_columns * m_text_rows );
    sprintf( m_mouse_control, "[%c]", 196 ); // 196 - ASCII "em dash"
}

DOSForms::~DOSForms( void )
{
    if ( disp_inited != 0 ) {
        disp_setattr( m_old_display_attributes );
        disp_move( 0, 0 );
        disp_eeop();
        disp_showcursor();
        disp_close();
        disp_setmode( m_old_display_mode );
    }

    if ( m_mouse_inited ) {
        msm_term();
    }

    delete[] m_mouse_control;
    delete[] m_title_text;
    delete[] m_status_bar_text;
    delete[] m_screen_buffer;

    dosforms_inited = 0;
}

/************************
*  Private methods
************************/
// clear screen
void DOSForms::ClearScreen( void )
{
    if ( disp_inited == 0 ) {
        return;
    }

    if ( m_mouse_inited ) {
        msm_hidecursor();
    }

    disp_move( 0, 0 );
    disp_eeop();
    disp_setattr( m_forms_colors.ToInt() );

    if ( m_mouse_inited ) {
        msm_showcursor();
    }
}

// clear text from line
void DOSForms::ClearRow( const unsigned int row )
{
    if ( disp_inited == 0 ) {
        return;
    }

    if ( m_mouse_inited ) {
        msm_hidecursor();
    }

    for ( unsigned int i = 0; i < m_text_columns; ++i ) {
        disp_move( row, i );
        disp_putc( ' ' );
    }

    if ( m_mouse_inited ) {
        msm_showcursor();
    }
}

unsigned int DOSForms::CenterScreen( const char* Text ) const
{
    return ( strlen( Text ) + m_text_columns ) / 2 - strlen( Text );
}


/************************
* Accessors
************************/
int DOSForms::IsMouseEnabled( void )
{
    return m_mouse_inited;
}

const forms_colors_t DOSForms::FormColor( void ) const
{
    return m_forms_colors;
}

const forms_colors_t DOSForms::TitleColor( void ) const
{
    return m_title_colors;
}

const char* DOSForms::TitleText( void ) const
{
    return m_title_text;
}

const forms_colors_t DOSForms::StatusBarColor( void ) const
{
    return m_status_bar_colors;
}

const char* DOSForms::StatusBarText( void ) const
{
    return m_status_bar_text;
}


/************************
* Mutators
************************/
void DOSForms::TitleColor( const foreground_colors_t Foreground, const background_colors_t Background )
{
    m_title_colors.foreground = Foreground;
    m_title_colors.background = Background;
    has_title_bar = TRUE;

    if ( disp_inited == 0 || dosforms_inited == 0 ) {
        return;
    }

    if ( m_mouse_inited ) {
        msm_hidecursor();
    }

    disp_move( 0, 0 );
    disp_setattr( m_title_colors.ToInt() );
    disp_eeol();
    disp_setattr( m_forms_colors.ToInt() );

    if ( m_mouse_inited ) {
        msm_showcursor();
    }
}

void DOSForms::TitleText( const char* Text )
{
    if ( Text == NULL || strlen( Text ) > m_text_columns / 2 ) {
        return;
    }

    strncpy( m_title_text, Text, m_text_columns / 2 );

    if ( disp_inited == 0 || dosforms_inited == 0 ) {
        return;
    }

    if ( m_mouse_inited ) {
        msm_hidecursor();
    }

    disp_move( 0, CenterScreen( m_title_text ) );
    disp_setattr( m_title_colors.ToInt() );
    disp_puts( m_title_text );
    disp_setattr( m_forms_colors.ToInt() );

    if ( m_mouse_inited ) {
        msm_showcursor();
    }
}

void DOSForms::StatusBarColor( const foreground_colors_t Foreground, const background_colors_t Background )
{
    m_status_bar_colors.foreground = Foreground;
    m_status_bar_colors.background = Background;
    has_status_bar = TRUE;

    if ( disp_inited == 0 || dosforms_inited == 0 ) {
        return;
    }

    if ( m_mouse_inited ) {
        msm_hidecursor();
    }

    disp_move( m_text_rows - 1, 0 );
    disp_flush();
    disp_setattr( m_status_bar_colors.ToInt() );
    disp_eeol();
    disp_setattr( m_forms_colors.ToInt() );

    if ( m_mouse_inited ) {
        msm_showcursor();
    }
}

void DOSForms::StatusBarText( const char* Text )
{
    if ( Text == NULL || strlen( Text ) > m_text_columns - 2 ) {
        return;
    }

    strncpy( m_status_bar_text, Text, m_text_columns - 2 );

    if ( disp_inited == 0 || dosforms_inited == 0 ) {
        return;
    }

    if ( m_mouse_inited ) {
        msm_hidecursor();
    }

    disp_move( m_text_rows - 1, 0 );
    disp_flush();
    disp_setattr( m_status_bar_colors.ToInt() );
    disp_eeol();
    disp_move( m_text_rows - 1, 1 );
    disp_puts( m_status_bar_text );
    disp_setattr( m_forms_colors.ToInt() );

    if ( m_mouse_inited ) {
        msm_showcursor();
    }
}


/************************
* Methods
************************/
void DOSForms::RemoveTitleBar( void )
{
    if ( disp_inited == 0 || dosforms_inited == 0 ) {
        return;
    }

    if ( m_mouse_inited ) {
        msm_hidecursor();
    }

    disp_setattr( m_forms_colors.ToInt() );
    disp_move( 0, 0 );
    disp_eeol();

    if ( m_mouse_inited ) {
        disp_setattr( m_title_colors.ToInt() );
        disp_move( 0, 0 );
        disp_puts( "[-]" ); // ALT+196
        disp_setattr( m_forms_colors.ToInt() );

        msm_showcursor();
    }

    has_title_bar = FALSE;
}

void DOSForms::RemoveStatusBar( void )
{
    if ( disp_inited == 0 || dosforms_inited == 0 ) {
        return;
    }

    if ( m_mouse_inited ) {
        msm_hidecursor();
    }

    disp_setattr( m_forms_colors.ToInt() );
    disp_move( m_text_rows - 1, 0 );
    disp_eeol();

    if ( m_mouse_inited ) {
        msm_showcursor();
    }

    has_status_bar = FALSE;
}

void DOSForms::OpenForm( void )
{
    if ( disp_inited == 0 || dosforms_inited == 0 ) {
        return;
    }

    // check for B&W (mono) display and set colors
    /*
    if ( disp_getmode() != 3 ) {
        if ( m_form_color != WHITE_ON_BLACK ) {
            m_form_color = WHITE_ON_BLACK;
        }
        if ( m_title_color != BLACK_ON_WHITE ) {
            m_title_color = BLACK_ON_WHITE;
        }
        if ( m_status_bar_color != BLACK_ON_WHITE ) {
            m_status_bar_color = BLACK_ON_WHITE;
        }
    }
    */

    disp_hidecursor();

    if ( m_mouse_inited ) {
        msm_hidecursor();
    }

    disp_flush();
    disp_move( 0, 0 );
    disp_setattr( m_forms_colors.ToInt() );
    disp_eeop();

    if ( m_mouse_inited ) {
        msm_showcursor();
    }

    if ( has_title_bar ) {
        TitleColor( m_title_colors.foreground, m_title_colors.background );
    }

    if ( *m_title_text != NULL ) {
        TitleText( m_title_text );
    }

    if ( m_mouse_inited ) {
        msm_hidecursor();
        disp_setattr( m_title_colors.ToInt() );
        disp_move( 0, 0 );
        disp_puts( m_mouse_control ); // ALT+196
        msm_showcursor();
    }

    disp_setattr( m_forms_colors.ToInt() );

    if ( has_status_bar ) {
        StatusBarText( m_status_bar_text );
    }
}

void DOSForms::DrawButton( const FormButton* Button )
{
    if ( disp_inited == 0 || dosforms_inited == 0 ) {
        return;
    }

    // draw dropshadow
    if ( Button->DropShadow() ) {
        disp_fillbox( BG_BLACK * 256 + ' ', Button->Coordinates().row + 1, Button->Coordinates().column + 1, Button->Coordinates().end_row + 1, Button->Coordinates().end_column + 1 );
    }
    // draw button
    disp_fillbox( Button->Color().ToInt() * 256 + ' ', Button->Coordinates().row, Button->Coordinates().column, Button->Coordinates().end_row, Button->Coordinates().end_column );

    if ( Button->Label() == NULL ) {
        return;
    }

    // center formula: StartColumn + ( ButtonHeight / 2 ) - ( TextHeight / 2 )
    // center formula: StartRow + ( ButtonWidth / 2 ) - ( TextWidth / 2 )
    unsigned int row = Button->Coordinates().row + ( Button->Coordinates().height / 2 ) - ( 1 / 2 );
    unsigned int col = Button->Coordinates().column + ( Button->Coordinates().width / 2 ) - ( strlen( Button->Label() ) / 2 );
    disp_move( row, col );
    disp_setattr( Button->Color().ToInt() );
    disp_puts( Button->Label() );

    disp_setattr( m_forms_colors.ToInt() );
}

// general window
boolean DOSForms::OpenWindow( const Window* Window )
{
    if ( disp_inited == 0 || dosforms_inited == 0 ) {
        return FALSE;
    }

    if ( is_screen_buffer_used != 0 ) {
        return FALSE;
    }

    if ( m_mouse_inited ) {
        msm_hidecursor();
    }

    disp_peekbox( m_screen_buffer, 3, 5, 22, 75 ); // save current contents to buffer
    disp_fillbox( 0 * 256 + ' ', 4, 6, 22, 75 ); // draw drop shadow
    disp_box( 1, Window->Color().ToInt(), 3, 5, 21, 74 ); //draw popup
    disp_fillbox( Window->Color().ToInt() * 256 + ' ', 4, 6, 20, 73 ); // fill popup box

    // set title if specified
    if ( Window->Title() != NULL ) {
        disp_setattr( Window->Color().ToInt() );

        if ( Window->TitleJustify() == 'R' ) {
            disp_move( 3, 74 - strlen( Window->Title() ) - 3 );
        }
        else if ( Window->TitleJustify() == 'C' ) {
            disp_move( 3, ( strlen( Window->Title() ) + 74 ) / 2 - strlen( Window->Title() ) );
        }
        else {
            disp_move( 3, 7 );
        }

        disp_printf( " %s ", Window->Title() );

        disp_setattr( m_forms_colors.ToInt() );
    }

    if ( m_mouse_inited ) {
        msm_showcursor();
    }

    is_screen_buffer_used = 1;

    return TRUE;
}

void DOSForms::CloseWindow( void )
{
    if ( disp_inited == 0 || dosforms_inited == 0 ) {
        return;
    }

    if ( is_screen_buffer_used == 0 ) {
        return;
    }

    if ( m_mouse_inited ) {
        msm_hidecursor();
    }

    disp_pokebox( m_screen_buffer, 3, 5, 22, 75 );
    memset( m_screen_buffer, '\0', sizeof( m_screen_buffer ) );

    if ( m_mouse_inited ) {
        msm_showcursor();
    }

    is_screen_buffer_used = 0;
}

// message box
// Window window provides color, coordinates, and Label provides dialog text
// return 0 on error, or number of button pressed
const button_t DOSForms::MessageBox( const Window* Window, const FormButton* Button, const dialog_buttons_t Choices ) const
{
    button_t selected_choice = BUTTON_CANCEL;
    button_t choice1, choice2;
    char button_text[2][9] = { NULL, NULL };

    switch( Choices ) {
        case DB_YESNO:
            strcpy( button_text[0], "Yes" );
            choice1 = BUTTON_YES;
            strcpy( button_text[1], "No" );
            choice2 = BUTTON_NO;
            break;
        case DB_NEXTBACK:
            strcpy( button_text[0], "Next" );
            choice1 = BUTTON_NEXT;
            strcpy( button_text[1], "Back" );
            choice2 = BUTTON_BACK;
            break;
        case DB_INSTALLCANCEL:
            strcpy( button_text[0], "Install" );
            choice1 = BUTTON_INSTALL;
            strcpy( button_text[1], "Cancel" );
            choice2 = BUTTON_CANCEL;
            break;
        case DB_OKCANCEL:
            strcpy( button_text[0], "OK" );
            choice1 = BUTTON_OK;
            strcpy( button_text[1], "Cancel" );
            choice2 = BUTTON_CANCEL;
            break;
        default:
            strcpy( button_text[0], "OK" );
            choice1 = BUTTON_OK;
    }

    if ( disp_inited == 0 ) {
        return BUTTON_CANCEL;
    }

    if ( m_mouse_inited ) {
        msm_hidecursor();
    }

    unsigned short *scrnBuffer = new unsigned short[50*10];

    disp_peekbox( scrnBuffer, Window->Coordinates().row, Window->Coordinates().column, Window->Coordinates().row + 7 + 1, Window->Coordinates().column + 44 + 1 ); // save current contents to buffer
    disp_fillbox( 0 * 256 + ' ', Window->Coordinates().row + 1, Window->Coordinates().column + 1, Window->Coordinates().row + 7, Window->Coordinates().column + 44 + 1 ); // draw drop shadow
    disp_box( Window->BorderStyle(), Window->Color().ToInt(), Window->Coordinates().row, Window->Coordinates().column, Window->Coordinates().row + 6, Window->Coordinates().column + 44 ); //draw popup
    disp_fillbox( Window->Color().ToInt() * 256 + ' ', Window->Coordinates().row + 1, Window->Coordinates().column + 1, Window->Coordinates().row + 5, Window->Coordinates().column + 43 ); // fill popup box

    if ( Button->Label() != NULL ) {
        disp_setattr( Button->Color().ToInt() );
        int centerColumn = ( strlen( Button->Label() ) + 44 ) / 2 - strlen( Button->Label() );
        disp_move( Window->Coordinates().row + 2, Window->Coordinates().column + centerColumn );
        disp_printf( "%s", Button->Label() );
    }

    if ( Choices == DB_OK ) {
        //int center = ( ( 8 + 44 ) / 2 - 8 ) + 1;
        disp_box( 5, Button->Color().ToInt(), Window->Coordinates().row + 4, Window->Coordinates().column + 17, Window->Coordinates().row + 4, Window->Coordinates().column + 25 );
    }
    else {
        disp_box( 5, Button->Color().ToInt(), Window->Coordinates().row + 4, Window->Coordinates().column + 7, Window->Coordinates().row + 4, Window->Coordinates().column + 15 );
        disp_box( 5, Button->Color().ToInt(), Window->Coordinates().row + 4, Window->Coordinates().column + 27, Window->Coordinates().row + 4, Window->Coordinates().column + 35 );
    }

    disp_setattr( Button->Color().ToInt() );

    if ( Choices == DB_OKCANCEL ) {
        disp_move( Window->Coordinates().row + 4, Window->Coordinates().column + 10 );
        disp_puts( button_text[0] );
        disp_move( Window->Coordinates().row + 4, Window->Coordinates().column + 28 );
        disp_puts( button_text[1] );
    }
    else if ( Choices == DB_YESNO ) {
        disp_move( Window->Coordinates().row + 4, Window->Coordinates().column + 10 );
        disp_puts( button_text[0] );
        disp_move( Window->Coordinates().row + 4, Window->Coordinates().column + 30 );
        disp_puts( button_text[1] );
    }
    else if ( Choices == DB_NEXTBACK ) {
        disp_move( Window->Coordinates().row + 4, Window->Coordinates().column + 9 );
        disp_puts( button_text[0] );
        disp_move( Window->Coordinates().row + 4, Window->Coordinates().column + 29 );
        disp_puts( button_text[1] );
    }
    else if ( Choices == DB_INSTALLCANCEL ) {
        disp_move( Window->Coordinates().row + 4, Window->Coordinates().column + 8 );
        disp_puts( button_text[0] );
        disp_move( Window->Coordinates().row + 4, Window->Coordinates().column + 28 );
        disp_puts( button_text[1] );
    }
    else {
        disp_move( Window->Coordinates().row + 4, Window->Coordinates().column + 20 );
        disp_puts( button_text[0] );
    }

    disp_setattr( Window->Color().ToInt() );

    if ( m_mouse_inited ) {
        msm_showcursor();
    }

    do {
        if ( m_mouse_inited ) {
            static int mouse_status = -1;
            static int old_mouse_status = -1;

            mouse_status = msm_getstatus( &mouse_x, &mouse_y );

            if ( (mouse_status & LEFT_BUTTON) && (mouse_status != old_mouse_status) ) {
                // multiply button positions by 8 to get mouse location
                if ( mouse_y == ( ( Window->Coordinates().row + 4 ) * 8 ) ) {
                    if ( Choices == DB_OK ) {
                        if ( mouse_x >= ( ( Window->Coordinates().column + 17 ) * 8 ) && mouse_x <= ( ( Window->Coordinates().column + 25 ) * 8 ) ) {
                            selected_choice = choice1;
                            break;
                        }
                    }
                    else {
                        if ( mouse_x >= ( ( Window->Coordinates().column + 7 ) * 8 ) && mouse_x <= ( ( Window->Coordinates().column + 15 ) * 8 ) ) {
                            selected_choice = choice1;
                            break;
                        }
                        if ( mouse_x >= ( ( Window->Coordinates().column + 27 ) * 8 ) && mouse_x <= ( ( Window->Coordinates().column + 35 ) * 8 ) ) {
                            selected_choice = choice2;
                            break;
                        }
                    }
                }
            }

            old_mouse_status = mouse_status;
        }
        if ( kbhit() ) {
            static int kb_input = -1;
            kb_input = getch();

            if ( kb_input == 27 ) {
                selected_choice = BUTTON_CANCEL;
                break;
            }
            if ( Choices == DB_OK ) {
                if ( kb_input == 'O' || kb_input == 'o' || kb_input == 13 ) {
                    selected_choice = BUTTON_OK;
                    break;
                }
            }
            if ( Choices == DB_OKCANCEL ) {
                if ( kb_input == 'O' || kb_input == 'o' ) {
                    selected_choice = BUTTON_OK;
                    break;
                }
                else if ( kb_input == 'C' || kb_input == 'c' ) {
                    selected_choice = BUTTON_CANCEL;
                    break;
                }
            }
            if ( Choices == DB_YESNO ) {
                if ( kb_input == 'Y' || kb_input == 'y' ) {
                    selected_choice = BUTTON_YES;
                    break;
                }
                else if ( kb_input == 'N' || kb_input == 'n' ) {
                    selected_choice = BUTTON_NO;
                    break;
                }
            }
            if ( Choices == DB_NEXTBACK ) {
                if ( kb_input == 'N' || kb_input == 'n' ) {
                    selected_choice = BUTTON_NEXT;
                    break;
                }
                else if ( kb_input == 'B' || kb_input == 'b' ) {
                    selected_choice = BUTTON_BACK;
                    break;
                }
            }
            if ( Choices == DB_INSTALLCANCEL ) {
                if ( kb_input == 'I' || kb_input == 'i' ) {
                    selected_choice = BUTTON_INSTALL;
                    break;
                }
                else if ( kb_input == 'C' || kb_input == 'c' ) {
                    selected_choice = BUTTON_CANCEL;
                    break;
                }
            }
        }
    } while ( 1 );

    if ( m_mouse_inited ) {
        msm_hidecursor();
    }

    disp_pokebox( scrnBuffer, Window->Coordinates().row, Window->Coordinates().column, Window->Coordinates().row + 7 + 1, Window->Coordinates().column + 44 + 1 );
    delete[] scrnBuffer;

    if ( m_mouse_inited ) {
        msm_showcursor();
    }

    return selected_choice;
}
