// dosforms.cpp : class implementation file

#include "dosforms.hpp"
#pragma warning( disable: 4018 ) // don't show warning about mismatched data types

DOSForms::DOSForms( void )
{
	if ( dosforms_inited ) {
		return;
	}

	OldDisplayMode = disp_getmode();
	OldDisplayAttributes = disp_getattr();

    if ( OldDisplayMode != 3 || OldDisplayMode != 7 ) {
        disp_setmode( 3 );
    }

	if ( disp_inited == 0 ) {
		disp_open();
	}

	isMouseEnabled = msm_init();
    formColor = __DARKGRAY;
    titleColor = 0;
    statusBarColor = 0;
    ScreenBuffer = new unsigned short[80 * 25];
    titleText = new char[TITLE_MAX];
    statusBarText = new char[STATUSBAR_MAX];
    screenBufferUsed = FALSE;
    dosforms_inited = TRUE;

    titleText[0] = NULL;
    statusBarText[0] = NULL;
    memset( ScreenBuffer, '\0', sizeof( ScreenBuffer ) );
}

DOSForms::DOSForms( const unsigned int FormColor )
{
	if ( dosforms_inited ) {
		return;
	}

	OldDisplayMode = disp_getmode();
	OldDisplayAttributes = disp_getattr();

    if ( OldDisplayMode != 3 || OldDisplayMode != 7 ) {
        disp_setmode( 3 );
    }

	if ( disp_inited == 0 ) {
		disp_open();
	}

	isMouseEnabled = msm_init();
    formColor = FormColor;
    titleColor = 0;
    statusBarColor = 0;
    ScreenBuffer = new unsigned short[80 * 25];
    titleText = new char[TITLE_MAX];
    statusBarText = new char[STATUSBAR_MAX];
    screenBufferUsed = FALSE;
    dosforms_inited = TRUE;

    titleText[0] = NULL;
    statusBarText[0] = NULL;
    memset( ScreenBuffer, '\0', sizeof( ScreenBuffer ) );
}

DOSForms::DOSForms( const unsigned int FormColor, const unsigned int TitleColor, const char *TitleText )
{
	if ( dosforms_inited ) {
		return;
	}

	OldDisplayMode = disp_getmode();
	OldDisplayAttributes = disp_getattr();

    if ( OldDisplayMode != 3 || OldDisplayMode != 7 ) {
        disp_setmode( 3 );
    }

	if ( disp_inited == 0 ) {
		disp_open();
	}

	isMouseEnabled = msm_init();
    formColor = FormColor;
    titleColor = TitleColor;
    statusBarColor = 0;
    ScreenBuffer = new unsigned short[80 * 25];
    titleText = new char[TITLE_MAX];
    statusBarText = new char[STATUSBAR_MAX];
    screenBufferUsed = FALSE;

    SetTitleText( TitleText );
    statusBarText[0] = NULL;
    memset( ScreenBuffer, '\0', sizeof( ScreenBuffer ) );

    dosforms_inited = TRUE;
}

DOSForms::DOSForms( const unsigned int FormColor, const unsigned int TitleColor, const char *TitleText, const unsigned int StatusBarColor, const char *StatusBarText )
{
	if ( dosforms_inited ) {
		return;
	}

	OldDisplayMode = disp_getmode();
	OldDisplayAttributes = disp_getattr();

    if ( OldDisplayMode != 3 || OldDisplayMode != 7 ) {
        disp_setmode( 3 );
    }

	if ( disp_inited == 0 ) {
		disp_open();
	}

	isMouseEnabled = msm_init();
    formColor = FormColor;
    titleColor = TitleColor;
    statusBarColor = StatusBarColor;
    ScreenBuffer = new unsigned short[80 * 25];
    titleText = new char[TITLE_MAX];
    titleText[0] = NULL;
    statusBarText = new char[STATUSBAR_MAX];
    statusBarText[0] = NULL;
    screenBufferUsed = FALSE;

    SetTitleText( TitleText );
    SetStatusBarText( StatusBarText );
    memset( ScreenBuffer, '\0', sizeof( ScreenBuffer ) );

    dosforms_inited = TRUE;
}

DOSForms::~DOSForms( void )
{
	if ( isMouseEnabled ) {
		msm_term();
	}

    if ( disp_inited != 0 ) {
        disp_setattr( OldDisplayAttributes );
        disp_move( 0, 0 );
        disp_eeop();
        disp_close();
        disp_setmode( OldDisplayMode );
    }

    dosforms_inited = FALSE;

    delete[] ScreenBuffer;
    delete[] titleText;
    delete[] statusBarText;
}

BOOL DOSForms::SetTitleColor( const unsigned int Color )
{
    if ( Color != NULL ) {
        titleColor = Color;

        if ( (BOOL)disp_inited && dosforms_inited ) {
            if ( isMouseEnabled ) {
                msm_hidecursor();
            }

            disp_move( 0, 0 );
            disp_setattr( titleColor );
            disp_eeol();
            disp_setattr( formColor );

            if ( isMouseEnabled ) {
                msm_showcursor();
            }
        }

        return TRUE;
    }

    return FALSE;
}

BOOL DOSForms::SetTitleText( const char *Text )
{
    if ( Text != NULL && strlen( Text ) < TITLE_MAX ) {
        strncpy( titleText, Text, TITLE_MAX );

        if ( (BOOL)disp_inited && dosforms_inited ) {
            if ( isMouseEnabled ) {
                msm_hidecursor();
            }

            disp_move( 0, GetCenterScreen( titleText ) );
            disp_setattr( titleColor );
            disp_puts( titleText );
            disp_setattr( formColor );

            if ( isMouseEnabled ) {
                msm_showcursor();
            }
        }

        return TRUE;
    }

    return FALSE;
}

BOOL DOSForms::RemoveTitleBar( void )
{
    if ( (BOOL)disp_inited && dosforms_inited ) {
        if ( isMouseEnabled ) {
            msm_hidecursor();
        }

        disp_setattr( formColor );
        disp_move( 0, 0 );
        disp_eeol();

        if ( isMouseEnabled ) {
            disp_setattr( titleColor );
            disp_move( 0, 0 );
            disp_puts( "[]" );
            disp_setattr( formColor );

            msm_showcursor();
        }
    }

    return (BOOL)disp_inited;
}

BOOL DOSForms::SetStatusBarText( const char* Text )
{
    if ( Text != NULL && strlen( Text ) < STATUSBAR_MAX ) {
        strncpy( statusBarText, Text, STATUSBAR_MAX );

        if ( (BOOL)disp_inited && dosforms_inited ) {
            if ( isMouseEnabled ) {
                msm_hidecursor();
            }

            disp_move( disp_numrows - 1, 0 );
            disp_flush();
            disp_setattr( statusBarColor );
            disp_eeol();
            disp_move( disp_numrows - 1, 1 );
            disp_puts( statusBarText );
            disp_setattr( formColor );

            if ( isMouseEnabled ) {
                msm_showcursor();
            }
        }

        return TRUE;
    }

    return FALSE;
}

BOOL DOSForms::SetStatusBarColor( const unsigned int Color )
{
    if ( Color != NULL ) {
        statusBarColor = Color;

        if ( (BOOL)disp_inited && dosforms_inited ) {
            if ( isMouseEnabled ) {
                msm_hidecursor();
            }

            disp_move( disp_numrows - 1, 0 );
            disp_flush();
            disp_setattr( statusBarColor );
            disp_eeol();
            disp_setattr( formColor );

            if ( isMouseEnabled ) {
                msm_showcursor();
            }
        }

        return TRUE;
    }

    return FALSE;
}

BOOL DOSForms::RemoveStatusBar( void )
{
    if ( (BOOL)disp_inited && dosforms_inited ) {
        if ( isMouseEnabled ) {
            msm_hidecursor();
        }

        disp_setattr( formColor );
        disp_move( disp_numrows - 1, 0 );
        disp_eeol();

        if ( isMouseEnabled ) {
            msm_showcursor();
        }
    }

    return (BOOL)disp_inited;
}

BOOL DOSForms::OpenForm( void )
{
    if ( (BOOL)!disp_inited || !dosforms_inited ) {
        return FALSE;
    }

    // check for B&W (mono) display and set colors
    /*
    if ( disp_getmode() != 3 ) {
        if ( formColor != WHITE_ON_BLACK ) {
            formColor = WHITE_ON_BLACK;
        }
        if ( titleColor != BLACK_ON_WHITE ) {
            titleColor = BLACK_ON_WHITE;
        }
        if ( statusBarColor != BLACK_ON_WHITE ) {
            statusBarColor = BLACK_ON_WHITE;
        }
    }
    */

    if ( isMouseEnabled ) {
        msm_hidecursor();
    }

    disp_flush();
    disp_move( 0, 0 );
    disp_setattr( formColor );
    disp_eeop();

    if ( isMouseEnabled ) {
        msm_showcursor();
    }

    if ( titleColor != 0 || titleColor != NULL ) {
        SetTitleColor( titleColor );
    }

    if ( titleText != NULL ) {
        SetTitleText( titleText );
    }

    if ( isMouseEnabled ) {
        msm_hidecursor();
        disp_setattr( titleColor );
        disp_move( 0, 0 );
        //disp_puts( "[]" );
        disp_puts( "[]" );
        msm_showcursor();
    }

    disp_setattr( formColor );

    if ( statusBarColor != 0 || statusBarColor != NULL ) {
        SetStatusBarText( statusBarText );
    }

    return (BOOL)disp_inited;
}

BOOL DOSForms::DrawButton( const Window window )
{
    if ( (BOOL)!disp_inited || !dosforms_inited ) {
        return FALSE;
    }

    if ( window.GetTop() != window.GetBottom() ) {
        disp_fillbox( __BLACK * 256 + ' ', window.GetTop() + 1, window.GetLeft() + 1, window.GetBottom() + 1, window.GetRight() + 1 );
    }
    disp_fillbox( window.GetColor() * 256 + ' ', window.GetTop(), window.GetLeft(), window.GetBottom(), window.GetRight() );

    if ( window.GetLabel() != NULL ) {
        if ( window.GetTop() != window.GetBottom() ) {
            // center formula: ( strlen( Text ) + disp_numcols ) / 2 - strlen( Text )
            unsigned int row = ( window.GetTop() + window.GetBottom() ) / 2;
            unsigned int col = ( strlen( window.GetLabel() ) + window.GetLeft() + window.GetRight() ) / 2 - strlen( window.GetLabel() ) + 1;
            disp_move( row, col );
            disp_setattr( window.GetColor() );
            disp_puts( window.GetLabel() );
        }
        else {
            unsigned int col = ( strlen( window.GetLabel() ) + window.GetLeft() + window.GetRight() ) / 2 - strlen( window.GetLabel() ) + 1;
            disp_move( window.GetTop(), col );
            disp_setattr( window.GetColor() );
            disp_puts( window.GetLabel() );
        }

        disp_setattr( formColor );
    }

    return (BOOL)disp_inited;
}

// popup window
BOOL DOSForms::OpenPopupWindow( const Window window )
{
    if ( (BOOL)!disp_inited || !dosforms_inited ) {
        return FALSE;
    }

    if ( screenBufferUsed ) {
        return FALSE;
    }

    if ( isMouseEnabled ) {
        msm_hidecursor();
    }

    disp_peekbox( ScreenBuffer, 3, 5, 22, 75 ); // save current contents to buffer
    disp_fillbox( __BLACK * 256 + ' ', 4, 6, 22, 75 ); // draw drop shadow
    disp_box( 1, window.GetColor(), 3, 5, 21, 74 ); //draw popup
    disp_fillbox( window.GetColor() * 256 + ' ', 4, 6, 20, 73 ); // fill popup box

    // set title if specified
    if ( window.GetTitle() != NULL ) {
        disp_setattr( window.GetColor() );

        if ( window.GetTitleJustify() == 'R' ) {
            disp_move( 3, 74 - strlen( window.GetTitle() ) - 3 );
        }
        else if ( window.GetTitleJustify() == 'C' ) {
            disp_move( 3, ( strlen( window.GetTitle() ) + 74 ) / 2 - strlen( window.GetTitle() ) );
        }
        else {
            disp_move( 3, 7 );
        }

        disp_printf( " %s ", window.GetTitle() );

        if ( formColor != NULL ) {
            disp_setattr( formColor );
        }
    }

    if ( isMouseEnabled ) {
        msm_showcursor();
    }

    screenBufferUsed = TRUE;
    return (BOOL)disp_inited;
}

BOOL DOSForms::ClosePopupWindow( void )
{
    if ( (BOOL)!disp_inited || !dosforms_inited ) {
        return FALSE;
    }

    if ( !screenBufferUsed ) {
        return FALSE;
    }

    if ( isMouseEnabled ) {
        msm_hidecursor();
    }

    disp_pokebox( ScreenBuffer, 3, 5, 22, 75 );
    memset( ScreenBuffer, '\0', sizeof( ScreenBuffer ) );

    if ( isMouseEnabled ) {
        msm_showcursor();
    }

    screenBufferUsed = FALSE;

    return (BOOL)disp_inited;
}

// message box with default values
BYTE DOSForms::MessageBox( const Window window )
{
    return MessageBox( window, NULL, NULL );
}

// message box
// Window window provides color, coordinates, and Label provides dialog text
// return 0 on error, or number of button pressed
BYTE DOSForms::MessageBox( const Window window, const BYTE Buttons, unsigned int ButtonColor ) const
{
    BYTE choice = 0;
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

    if ( (BOOL)disp_inited ) {
        if ( isMouseEnabled ) {
            msm_hidecursor();
        }

        unsigned short *scrnBuffer = new unsigned short[50*10];

        disp_peekbox( scrnBuffer, window.GetTop(), window.GetLeft(), window.GetTop() + 7 + 1, window.GetLeft() + 44 + 1 ); // save current contents to buffer
        disp_fillbox( __BLACK * 256 + ' ', window.GetTop() + 1, window.GetLeft() + 1, window.GetTop() + 7, window.GetLeft() + 44 + 1 ); // draw drop shadow
        disp_box( window.GetBorderStyle(), window.GetColor(), window.GetTop(), window.GetLeft(), window.GetTop() + 6, window.GetLeft() + 44 ); //draw popup
        disp_fillbox( window.GetColor() * 256 + ' ', window.GetTop() + 1, window.GetLeft() + 1, window.GetTop() + 5, window.GetLeft() + 43 ); // fill popup box

        if ( window.GetLabel() != NULL ) {
            disp_setattr( window.GetColor() );
            int centerColumn = ( strlen( window.GetLabel() ) + 44 ) / 2 - strlen( window.GetLabel() );
            disp_move( window.GetTop() + 2, window.GetLeft() + centerColumn );
            disp_printf( "%s", window.GetLabel() );
        }

        if ( ButtonColor == NULL ) {
            ButtonColor = YELLOW_ON_GREEN;
        }

        if ( Buttons == BTN_OK || Buttons == NULL ) {
            //int center = ( ( 8 + 44 ) / 2 - 8 ) + 1;
            disp_box( 5, ButtonColor, window.GetTop() + 4, window.GetLeft() + 17, window.GetTop() + 4, window.GetLeft() + 25 );
        }
        else {
            disp_box( 5, ButtonColor, window.GetTop() + 4, window.GetLeft() + 7, window.GetTop() + 4, window.GetLeft() + 15 );
            disp_box( 5, ButtonColor, window.GetTop() + 4, window.GetLeft() + 27, window.GetTop() + 4, window.GetLeft() + 35 );
        }

        disp_setattr( ButtonColor );

        if ( Buttons == BTN_OKCANCEL ) {
            disp_move( window.GetTop() + 4, window.GetLeft() + 10 );
            disp_puts( buttons[0] );
            disp_move( window.GetTop() + 4, window.GetLeft() + 28 );
            disp_puts( buttons[1] );
        }
        else if ( Buttons == BTN_YESNO ) {
            disp_move( window.GetTop() + 4, window.GetLeft() + 10 );
            disp_puts( buttons[0] );
            disp_move( window.GetTop() + 4, window.GetLeft() + 30 );
            disp_puts( buttons[1] );
        }
        else if ( Buttons == BTN_NEXTBACK ) {
            disp_move( window.GetTop() + 4, window.GetLeft() + 9 );
            disp_puts( buttons[0] );
            disp_move( window.GetTop() + 4, window.GetLeft() + 29 );
            disp_puts( buttons[1] );
        }
        else if ( Buttons == BTN_INSTALLCANCEL ) {
            disp_move( window.GetTop() + 4, window.GetLeft() + 8 );
            disp_puts( buttons[0] );
            disp_move( window.GetTop() + 4, window.GetLeft() + 28 );
            disp_puts( buttons[1] );
        }
        else {
            disp_move( window.GetTop() + 4, window.GetLeft() + 20 );
            disp_puts( buttons[0] );
        }

        disp_setattr( window.GetColor() );

        if ( isMouseEnabled ) {
            msm_showcursor();
        }

        do {
            if ( isMouseEnabled ) {
    	        static int mouse_status = -1;
    	        static int old_mouse_status = -1;

	            mouse_status = msm_getstatus( &mouse_x, &mouse_y );

        	    if ( (mouse_status & LEFT_BUTTON) && (mouse_status != old_mouse_status) ) {
        	        // multiply button positions by 8 to get mouse location
           	        if ( mouse_y == ( ( window.GetTop() + 4 ) * 8 ) ) {
           	            if ( Buttons == BTN_OK || Buttons == NULL ) {
           	                if ( mouse_x >= ( ( window.GetLeft() + 17 ) * 8 ) && mouse_x <= ( ( window.GetLeft() + 25 ) * 8 ) ) {
           	                    break;
           	                }
           	            }
           	            else {
           	                if ( mouse_x >= ( ( window.GetLeft() + 7 ) * 8 ) && mouse_x <= ( ( window.GetLeft() + 15 ) * 8 ) ) {
           	                    choice = 1;
           	                    break;
           	                }
       	                    if ( mouse_x >= ( ( window.GetLeft() + 27 ) * 8 ) && mouse_x <= ( ( window.GetLeft() + 35 ) * 8 ) ) {
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
    	        if ( Buttons == BTN_OK || Buttons == NULL ) {
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
        } while ( TRUE );

        if ( isMouseEnabled ) {
            msm_hidecursor();
        }

        disp_pokebox( scrnBuffer, window.GetTop(), window.GetLeft(), window.GetTop() + 7 + 1, window.GetLeft() + 44 + 1 );
        delete scrnBuffer;

        if ( isMouseEnabled ) {
            msm_showcursor();
        }
    }

    return choice;
}

// clear screen
BOOL DOSForms::ClearScreen( void )
{
    if ( (BOOL)disp_inited ) {
        if ( isMouseEnabled ) {
            msm_hidecursor();
        }

        disp_move( 0, 0 );
        disp_eeop();
        disp_setattr( formColor );

        if ( isMouseEnabled ) {
            msm_showcursor();
        }
    }

    return (BOOL)disp_inited;
}

// clear text from line
BOOL DOSForms::ClearRow( const unsigned int row )
{
    if ( (BOOL)disp_inited ) {
        if ( isMouseEnabled ) {
            msm_hidecursor();
        }

        for ( unsigned int i = 0; i < disp_numcols; ++i ) {
            disp_move( row, i );
            disp_putc( ' ' );
        }

        if ( isMouseEnabled ) {
            msm_showcursor();
        }
    }

    return (BOOL)disp_inited;
}

// centers text
unsigned int DOSForms::GetCenterScreen( const char *Text ) const
{
    return ( strlen( Text ) + disp_numcols ) / 2 - strlen( Text );
}


#pragma warning( default: 4018 )
