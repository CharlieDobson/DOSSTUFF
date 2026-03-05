// Titlebar class implementation file

#include "titlebar.hpp"
#include <disp.h>               // Symantec display functions
#include <msmouse.h>            // Symantec mouse functions
#include <stdio.h>              // _snprintf
#include <string.h>             // strncpy

TitleBar::TitleBar( void ) : DOSForms( FG_WHITE, BG_BLUE )
{
    Text[0] = '\0';
}

TitleBar::TitleBar( const foreground_color_t foreground, const background_color_t background )
    : DOSForms( foreground, background )
{
    Text[0] = '\0';
}

TitleBar::TitleBar( const foreground_color_t foreground, const background_color_t background, const char* title )
    : DOSForms( foreground, background )
{
    Text[0] = '\0';
    if ( title && title[0] != '\0' ) {
        strncpy( Text, title, sizeof( Text ) - 1 );
        Text[sizeof( Text ) - 1] = '\0';
    }
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