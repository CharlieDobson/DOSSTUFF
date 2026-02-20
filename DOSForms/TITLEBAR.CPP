// Titlebar class implementation file

#include "titlebar.hpp"
#include <disp.h>               // Symantec display functions
#include <msmouse.h>            // Symantec mouse functions
#include <stdlib.h>             // required for NULL
#include <stdio.h>              // _snprintf
#include <string.h>             // strncpy

TitleBar::TitleBar( void ) : DOSForms()
{
    fg_color = FG_WHITE;
    bg_color = BG_BLUE;
    Text[0] = '\0';
}

TitleBar::TitleBar( const foreground_color_t foreground, const background_color_t background )
{
    fg_color = foreground;
    bg_color = background;
    IsMouseEnabled = FALSE;
    Text[0] = '\0';
}

TitleBar::TitleBar( const foreground_color_t foreground, const background_color_t background, const char* title )
{
    fg_color = foreground;
    bg_color = background;
    IsMouseEnabled = FALSE;
    if( NULL != title ) {
        strncpy( Text, title, sizeof( Text ) - 1 );
        Text[sizeof( Text ) - 1] = '\0';
    } else {
        Text[0] = '\0';
    }
}

TitleBar::~TitleBar( void )
{
    // destructor code here
}

int TitleBar::ColorsToInt( void )
{
    return (int)( ( bg_color << 4 ) | fg_color );
}

void TitleBar::Draw( void )
{
    if ( disp_inited == 0 ) return;

    if ( IsMouseEnabled ) msm_hidecursor();

    disp_move( 0, 0 );
    disp_setattr( ColorsToInt() );
    disp_eeol();

    if ( Text[0] != '\0' ) {
        disp_move( 0, ( disp_numcols - ( strlen( Text ) ) ) / 2 );
        disp_puts( Text );
    }

    if ( IsMouseEnabled ) {
        char mouse_control[4];
        _snprintf( mouse_control, sizeof( mouse_control ), "[%c]", 196 );
        disp_move( 0, 0 );
        disp_puts( mouse_control );
    }

    if ( IsMouseEnabled ) msm_showcursor();
}
