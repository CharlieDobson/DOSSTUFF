// Statusbar class implementation file

#include "statbar.hpp"
#include <stdlib.h>             // calloc, free
#include <disp.h>               // Symantec display functions
#include <msmouse.h>            // Symantec mouse functions
#include <stdio.h>              // _vsnprintf, _snprintf
#include <string.h>             // strncpy

StatusBar::StatusBar( void ) : DOSForms( FG_LIGHT_CYAN, BG_CYAN )
{

}

StatusBar::StatusBar( const foreground_color_t foreground, const background_color_t background )
    : DOSForms( foreground, background )
{

}

void StatusBar::Draw( void )
{
    if ( disp_inited == 0 ) return;

    if ( IsMouseEnabled ) msm_hidecursor();

    disp_move( disp_numrows - 1, 0 );
    disp_setattr( ColorsToInt() );
    disp_eeol();

    if ( IsMouseEnabled ) msm_showcursor();
}

void StatusBar::Print( const char* message )
{
    if ( disp_inited == 0 ) return;

    if ( !message || message[0] == '\0' ) return;

    // create buffer to hold status message
    // and ensure it doesn't exceed screen width
    char* buffer = (char*)calloc( disp_numcols - 2, sizeof( char ) );

    if ( !buffer ) return;

    strncpy( buffer, message, disp_numcols - 3 );
    buffer[disp_numcols - 3] = '\0';

    if ( IsMouseEnabled ) msm_hidecursor();

    disp_move( disp_numrows - 1, 0 );
    disp_setattr( ColorsToInt() );
    disp_puts( buffer );
    disp_eeol();
    free( buffer );

    if ( IsMouseEnabled ) msm_showcursor();
}

void StatusBar::Printf( const char* format, ... )
{
    if ( disp_inited == 0 ) return;

    if ( !format || format[0] == '\0' ) return;

    // create buffer to hold formatted status message
    char* buffer = (char*)calloc( disp_numcols - 2, sizeof( char ) );

    if ( !buffer ) return;

    va_list args;
    va_start( args, format );
    _vsnprintf( buffer, disp_numcols - 2, format, args );
    buffer[disp_numcols - 3] = '\0';
    va_end( args );

    if ( IsMouseEnabled ) msm_hidecursor();

    disp_move( disp_numrows - 1, 0 );
    disp_setattr( ColorsToInt() );
    disp_puts( buffer );
    disp_eeol();
    free( buffer );

    if ( IsMouseEnabled ) msm_showcursor();
}