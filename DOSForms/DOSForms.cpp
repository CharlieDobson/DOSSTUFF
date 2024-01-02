// dosforms.cpp : class implementation file

#include "dosforms.hpp"

#ifdef __SC__
DOSForms::DOSForms( void )
{
	if ( dosforms_inited ) {
		return;
	}

	oldDisplayMode = disp_getmode();

    if ( oldDisplayMode != 3 || oldDisplayMode != 7 ) {
        disp_setmode( 3 );
    }

	if ( disp_inited == 0 ) {
		disp_open();
	}

    numTextCols = (short)disp_numcols;
    numTextRows = (short)disp_numrows;
	oldDisplayAttributes = disp_getattr();
	isMouseEnabled = msm_init();
    formColor = __DARKGRAY;
    titleColor = 0;
    statusBarColor = 0;
    screenBuffer = new unsigned short[80 * 25];
    titleText = new char[_MAX_DOSFORMS_TITLE + 1];
    statusBarText = new char[_MAX_DOSFORMS_STATUSBAR + 1];
    titleText[0] = NULL;
    statusBarText[0] = NULL;
    screenBufferUsed = FALSE;
    dosforms_inited = TRUE;

    memset( screenBuffer, '\0', 80 * 25 );
}

DOSForms::DOSForms( const unsigned int FormColor )
{
	if ( dosforms_inited ) {
		return;
	}

	oldDisplayMode = disp_getmode();

    if ( oldDisplayMode != 3 || oldDisplayMode != 7 ) {
        disp_setmode( 3 );
    }

	if ( disp_inited == 0 ) {
		disp_open();
	}

    numTextCols = (short)disp_numcols;
    numTextRows = (short)disp_numrows;
	oldDisplayAttributes = disp_getattr();
	isMouseEnabled = msm_init();
    formColor = FormColor;
    titleColor = 0;
    statusBarColor = 0;
    screenBuffer = new unsigned short[80 * 25];
    titleText = new char[_MAX_DOSFORMS_TITLE + 1];
    statusBarText = new char[_MAX_DOSFORMS_STATUSBAR + 1];
    titleText[0] = NULL;
    statusBarText[0] = NULL;
    screenBufferUsed = FALSE;
    dosforms_inited = TRUE;

    memset( screenBuffer, '\0', 80 * 25 );
}

DOSForms::DOSForms( const unsigned int FormColor, const unsigned int TitleColor, const char *szTitleText )
{
	if ( dosforms_inited ) {
		return;
	}

	oldDisplayMode = disp_getmode();

    if ( oldDisplayMode != 3 || oldDisplayMode != 7 ) {
        disp_setmode( 3 );
    }

	if ( disp_inited == 0 ) {
		disp_open();
	}

    numTextCols = (short)disp_numcols;
    numTextRows = (short)disp_numrows;
	oldDisplayAttributes = disp_getattr();
	isMouseEnabled = msm_init();
    formColor = FormColor;
    titleColor = TitleColor;
    statusBarColor = 0;
    screenBuffer = new unsigned short[80 * 25];
    titleText = new char[_MAX_DOSFORMS_TITLE + 1];
    statusBarText = new char[_MAX_DOSFORMS_STATUSBAR + 1];
    titleText[0] = NULL;
    statusBarText[0] = NULL;
    screenBufferUsed = FALSE;
    TitleText( szTitleText );
    memset( screenBuffer, '\0', 80 * 25 );

    dosforms_inited = TRUE;
}

DOSForms::DOSForms( const unsigned int FormColor, const unsigned int TitleColor, const char *szTitleText, const unsigned int StatusBarColor, const char *szStatusBarText )
{
	if ( dosforms_inited ) {
		return;
	}

	oldDisplayMode = disp_getmode();

    if ( oldDisplayMode != 3 || oldDisplayMode != 7 ) {
        disp_setmode( 3 );
    }

	if ( disp_inited == 0 ) {
		disp_open();
	}

    numTextCols = (short)disp_numcols;
    numTextRows = (short)disp_numrows;
	oldDisplayAttributes = disp_getattr();
	isMouseEnabled = msm_init();
    formColor = FormColor;
    titleColor = TitleColor;
    statusBarColor = StatusBarColor;
    screenBuffer = new unsigned short[80 * 25];
    titleText = new char[_MAX_DOSFORMS_TITLE + 1];
    statusBarText = new char[_MAX_DOSFORMS_STATUSBAR + 1];
    titleText[0] = NULL;
    statusBarText[0] = NULL;
    screenBufferUsed = FALSE;
    TitleText( szTitleText );
    StatusBarText( szStatusBarText );
    memset( screenBuffer, '\0', 80 * 25 );

    dosforms_inited = TRUE;
}

DOSForms::~DOSForms( void )
{
	if ( isMouseEnabled ) {
		msm_term();
	}

    if ( disp_inited != 0 ) {
        disp_setattr( oldDisplayAttributes );
        disp_move( 0, 0 );
        disp_eeop();
        disp_close();
        disp_setmode( oldDisplayMode );
    }

    delete[] titleText;
    delete[] statusBarText;
    delete[] screenBuffer;

    dosforms_inited = FALSE;
}

BOOL DOSForms::TitleColor( const unsigned int Color )
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

BOOL DOSForms::TitleText( const char *Text )
{
    if ( Text != NULL && strlen( Text ) < _MAX_DOSFORMS_TITLE ) {
        strncpy( titleText, Text, _MAX_DOSFORMS_TITLE );

        if ( (BOOL)disp_inited && dosforms_inited ) {
            if ( isMouseEnabled ) {
                msm_hidecursor();
            }

            disp_move( 0, CenterScreen( titleText ) );
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
            disp_puts( "[Ä]" ); // ALT+0196
            disp_setattr( formColor );

            msm_showcursor();
        }
    }

    return (BOOL)disp_inited;
}

BOOL DOSForms::StatusBarText( const char* Text )
{
    if ( Text != NULL && strlen( Text ) < _MAX_DOSFORMS_STATUSBAR ) {
        strncpy( statusBarText, Text, _MAX_DOSFORMS_STATUSBAR );

        if ( (BOOL)disp_inited && dosforms_inited ) {
            if ( isMouseEnabled ) {
                msm_hidecursor();
            }

            disp_move( numTextRows - 1, 0 );
            disp_flush();
            disp_setattr( statusBarColor );
            disp_eeol();
            disp_move( numTextRows - 1, 1 );
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

BOOL DOSForms::StatusBarColor( const unsigned int Color )
{
    if ( Color != NULL ) {
        statusBarColor = Color;

        if ( (BOOL)disp_inited && dosforms_inited ) {
            if ( isMouseEnabled ) {
                msm_hidecursor();
            }

            disp_move( numTextRows - 1, 0 );
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
        disp_move( numTextRows - 1, 0 );
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
        TitleColor( titleColor );
    }

    if ( titleText != NULL ) {
        TitleText( titleText );
    }

    if ( isMouseEnabled ) {
        msm_hidecursor();
        disp_setattr( titleColor );
        disp_move( 0, 0 );
        //disp_puts( "[]" );
        disp_puts( "[Ä]" ); // ALT+0196
        msm_showcursor();
    }

    disp_setattr( formColor );

    if ( statusBarColor != 0 || statusBarColor != NULL ) {
        StatusBarText( statusBarText );
    }

    return (BOOL)disp_inited;
}

BOOL DOSForms::DrawButton( const Window window )
{
    if ( (BOOL)!disp_inited || !dosforms_inited ) {
        return FALSE;
    }

    if ( window.Top() != window.Bottom() ) {
        disp_fillbox( __BLACK * 256 + ' ', window.Top() + 1, window.Left() + 1, window.Bottom() + 1, window.Right() + 1 );
    }
    disp_fillbox( window.Color() * 256 + ' ', window.Top(), window.Left(), window.Bottom(), window.Right() );

    if ( window.Label() != NULL ) {
        if ( window.Top() != window.Bottom() ) {
            // center formula: ( strlen( Text ) + numTextCols ) / 2 - strlen( Text )
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

    disp_peekbox( screenBuffer, 3, 5, 22, 75 ); // save current contents to buffer
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

    disp_pokebox( screenBuffer, 3, 5, 22, 75 );
    memset( screenBuffer, '\0', sizeof( screenBuffer ) );

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

        if ( Buttons == BTN_OK || Buttons == NULL ) {
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
           	        if ( mouse_y == ( ( window.Top() + 4 ) * 8 ) ) {
           	            if ( Buttons == BTN_OK || Buttons == NULL ) {
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

        disp_pokebox( scrnBuffer, window.Top(), window.Left(), window.Top() + 7 + 1, window.Left() + 44 + 1 );
        delete[] scrnBuffer;

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

        for ( unsigned int i = 0; i < numTextCols; ++i ) {
            disp_move( row, i );
            disp_putc( ' ' );
        }

        if ( isMouseEnabled ) {
            msm_showcursor();
        }
    }

    return (BOOL)disp_inited;
}

#else // __SC__

///
/// ***********************************
/// Microsoft / OpenWatCom compatible
/// ***********************************
///

DOSForms::DOSForms( void )
{
	struct _videoconfig videoconfig;
	_getvideoconfig( &videoconfig );
	numTextCols = videoconfig.numtextcols;
	numTextRows = videoconfig.numtextrows;
	oldDisplayMode = videoconfig.mode;
	oldTextDisplay = _gettextcolor();
	oldBackgroundDisplay = _getbkcolor();

	if ( oldDisplayMode != _TEXTBW80 || oldDisplayMode != _TEXTC80 ) {
		if ( _setvideomode( _TEXTC80 ) != 0 ) {
			dispInited = TRUE;
		}
		else {
			dispInited = FALSE;
		}
	}
	else {
		dispInited = TRUE;
	}

	formTextColor = __BLUE;
	formBackgroundColor = __GRAY;
	titleTextColor = 0;
	titleBackgroundColor = 0L;
	statusBarTextColor = 0;
	statusBarBackgroundColor = 0L;
	screenBuffer = new unsigned short[80 * 25];
	memset( &screenBuffer, '\0', 80 * 25 );
	titleText = new char[_MAX_DOSFORMS_TITLE + 1];
	statusBarText = new char[_MAX_DOSFORMS_STATUSBAR + 1];
    titleText[0] = NULL;
    statusBarText[0] = NULL;

    screenBufferUsed = FALSE;

    isMouseEnabled = mouse.IsMouseEnabled();
}

DOSForms::DOSForms( const unsigned int FormTextColor, const unsigned int FormBackgroundColor )
{
	struct _videoconfig videoconfig;
	_getvideoconfig( &videoconfig );
	numTextCols = videoconfig.numtextcols;
	numTextRows = videoconfig.numtextrows;
	oldDisplayMode = videoconfig.mode;
	oldTextDisplay = _gettextcolor();
	oldBackgroundDisplay = _getbkcolor();

	if ( oldDisplayMode != _TEXTBW80 || oldDisplayMode != _TEXTC80 ) {
		if ( _setvideomode( _TEXTC80 ) != 0 ) {
			dispInited = TRUE;
		}
		else {
			dispInited = FALSE;
		}
	}
	else {
		dispInited = TRUE;
	}

	formTextColor = FormTextColor;
	formBackgroundColor = FormBackgroundColor;
	titleTextColor = 0;
	titleBackgroundColor = 0L;
	statusBarTextColor = 0;
	statusBarBackgroundColor = 0L;
	screenBuffer = new unsigned short[80 * 25];
	memset( &screenBuffer, '\0', 80 * 25 );
	titleText = new char[_MAX_DOSFORMS_TITLE + 1];
	statusBarText = new char[_MAX_DOSFORMS_STATUSBAR + 1];
    titleText[0] = NULL;
    statusBarText[0] = NULL;
    screenBufferUsed = FALSE;

    isMouseEnabled = mouse.IsMouseEnabled();
}

DOSForms::DOSForms( const unsigned int FormTextColor, const unsigned int FormBackgroundColor, const unsigned int TitleTextColor, const unsigned int TitleBackgroundColor, const char *TitleText )
{
	struct _videoconfig videoconfig;
	_getvideoconfig( &videoconfig );
	numTextCols = videoconfig.numtextcols;
	numTextRows = videoconfig.numtextrows;
	oldDisplayMode = videoconfig.mode;
	oldTextDisplay = _gettextcolor();
	oldBackgroundDisplay = _getbkcolor();

	if ( oldDisplayMode != _TEXTBW80 || oldDisplayMode != _TEXTC80 ) {
		if ( _setvideomode( _TEXTC80 ) != 0 ) {
			dispInited = TRUE;
		}
		else {
			dispInited = FALSE;
		}
	}
	else {
		dispInited = TRUE;
	}

	formTextColor = FormTextColor;
	formBackgroundColor = FormBackgroundColor;
	titleTextColor = TitleTextColor;
	titleBackgroundColor = TitleBackgroundColor;
	statusBarTextColor = 0;
	statusBarBackgroundColor = 0L;
	screenBuffer = new unsigned short[80 * 25];
	memset( &screenBuffer, '\0', 80 * 25 );
	titleText = new char[_MAX_DOSFORMS_TITLE + 1];
	statusBarText = new char[_MAX_DOSFORMS_STATUSBAR + 1];
	strncpy( titleText, TitleText, _MAX_DOSFORMS_TITLE );
    statusBarText[0] = NULL;
    screenBufferUsed = FALSE;

    isMouseEnabled = mouse.IsMouseEnabled();
}

DOSForms::~DOSForms( void )
{
	delete[] screenBuffer;
	delete[] titleText;
	delete[] statusBarText;
	_setvideomode( oldDisplayMode );
	_settextcolor( oldTextDisplay );
	_setbkcolor( oldBackgroundDisplay );
}

BOOL DOSForms::TitleTextColor( const unsigned int Color )
{
	if ( Color == NULL ) {
		return FALSE;
	}

    titleTextColor = Color;

	if ( dispInited ) {
    	if ( isMouseEnabled ) {
        	mouse.HideMouse();
    	}

		_settextcolor( titleTextColor );
		_setbkcolor( titleBackgroundColor );
		_settextposition( 1, 1 );
		_outmem( " ", numTextCols );

		if ( titleText[0] != NULL ) {
			TitleText( titleText );
		}

	    _settextcolor( formTextColor );
    	_setbkcolor( formBackgroundColor );

    	if ( isMouseEnabled ) {
    		mouse.ShowMouse();
    	}
    }

    return TRUE;
}

BOOL DOSForms::TitleBackgroundColor( const unsigned long Color )
{
	if ( Color == NULL ) {
		return FALSE;
	}

    titleBackgroundColor = Color;

	if ( dispInited ) {
    	if ( isMouseEnabled ) {
        	mouse.HideMouse();
    	}

		_settextcolor( titleTextColor );
		_setbkcolor( titleBackgroundColor );
		_settextposition( 1, 1 );
		_outmem( " ", numTextCols );

		if ( titleText[0] != NULL ) {
			TitleText( titleText );
		}

	    _settextcolor( formTextColor );
    	_setbkcolor( formBackgroundColor );

    	if ( isMouseEnabled ) {
    		mouse.ShowMouse();
    	}
    }

    return TRUE;
}

BOOL DOSForms::StatusBarTextColor( const unsigned int Color )
{
	if ( Color == NULL ) {
		return FALSE;
	}

    statusBarTextColor = Color;

	if ( dispInited ) {
    	if ( isMouseEnabled ) {
        	mouse.HideMouse();
    	}

		_settextcolor( statusBarTextColor );
		_setbkcolor( statusBarBackgroundColor );
		_settextposition( numTextRows, 1 );
		_outmem( " ", numTextCols );

		if ( statusBarText[0] != NULL ) {
			StatusBarText( statusBarText );
		}

	    _settextcolor( formTextColor );
    	_setbkcolor( formBackgroundColor );

    	if ( isMouseEnabled ) {
    		mouse.ShowMouse();
    	}
    }

    return TRUE;
}

BOOL DOSForms::StatusBarBackgroundColor( const unsigned long Color )
{
	if ( Color == NULL ) {
		return FALSE;
	}

    statusBarBackgroundColor = Color;

	if ( dispInited ) {
    	if ( isMouseEnabled ) {
        	mouse.HideMouse();
    	}

		_settextcolor( statusBarTextColor );
		_setbkcolor( statusBarBackgroundColor );
		_settextposition( numTextRows, 1 );
		_outmem( " ", numTextCols );

		if ( statusBarText[0] != NULL ) {
			StatusBarText( statusBarText );
		}

	    _settextcolor( formTextColor );
    	_setbkcolor( formBackgroundColor );

    	if ( isMouseEnabled ) {
    		mouse.ShowMouse();
    	}
    }

    return TRUE;
}

BOOL DOSForms::TitleText( const char *Text )
{
	if ( Text[0] == NULL ) {
		return FALSE;
	}

    strncpy( titleText, Text, _MAX_DOSFORMS_TITLE );

    if ( dispInited ) {
        if ( isMouseEnabled ) {
            mouse.HideMouse();
        }

		_settextposition( 1, CenterScreen( titleText ) );
		_settextcolor( titleTextColor );
		_setbkcolor( titleBackgroundColor );
		_outmem( titleText, strlen( titleText ) );
		_settextcolor( formTextColor );
		_setbkcolor( formBackgroundColor );

        if ( isMouseEnabled ) {
            mouse.ShowMouse();
        }
    }

    return TRUE;
}

BOOL DOSForms::StatusBarText( const char *Text )
{
	if ( Text[0] == NULL ) {
		return FALSE;
	}

    strncpy( statusBarText, Text, _MAX_DOSFORMS_STATUSBAR );

    if ( dispInited ) {
        if ( isMouseEnabled ) {
            mouse.HideMouse();
        }

		_settextposition( numTextRows, CenterScreen( statusBarText ) );
		_settextcolor( statusBarTextColor );
		_setbkcolor( statusBarBackgroundColor );
		_outmem( statusBarText, strlen( statusBarText ) );
		_settextcolor( formTextColor );
		_setbkcolor( formBackgroundColor );

        if ( isMouseEnabled ) {
            mouse.ShowMouse();
        }
    }

    return TRUE;
}

BOOL DOSForms::OpenForm( void )
{
    if ( !dispInited ) {
        return FALSE;
    }

    // TODO: check for B&W (mono) display and set colors

    if ( isMouseEnabled ) {
        mouse.HideMouse();
    }

	_settextcolor( formTextColor );
	_setbkcolor( formBackgroundColor );
	_clearscreen( _GCLEARSCREEN );

    if ( isMouseEnabled ) {
        mouse.ShowMouse();
    }

    if ( titleTextColor != 0 || titleBackgroundColor != 0 ) {
        TitleTextColor( titleTextColor );
        TitleBackgroundColor( titleBackgroundColor );
    }

    if ( titleText[0] != NULL ) {
        TitleText( titleText );
    }

    if ( isMouseEnabled ) {
        mouse.HideMouse();
        _settextcolor( titleTextColor );
        _setbkcolor( titleBackgroundColor );
        _settextposition( 1, 1 );
        _outmem( "[]", 3 );
        mouse.ShowMouse();
    }

    if ( statusBarText[0] != NULL ) {
        StatusBarText( statusBarText );
    }

	_settextcolor( formTextColor );
	_setbkcolor( formBackgroundColor );

    return dispInited;
}

#endif // __SC__

unsigned int DOSForms::CenterScreen( const char *Text ) const
{
	return ( strlen( Text ) + numTextCols ) / 2 - strlen( Text );
}
