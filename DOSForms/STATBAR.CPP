// Statusbar class implementation file

#include "statbar.hpp"
#include <disp.h>               // Symantec display functions
#include <msmouse.h>            // Symantec mouse functions
#include <stdlib.h>             // required for NULL
#include <stdio.h>              // _vsnprintf, _snprintf
#include <string.h>             // strncpy

StatusBar::StatusBar( void ) : DOSForms()
{
    fg_color = FG_LIGHT_CYAN;
    bg_color = BG_CYAN;
    IsMouseEnabled = FALSE;
}

StatusBar::StatusBar( const foreground_color_t foreground, const background_color_t background )
{
    fg_color = foreground;
    bg_color = background;
}

StatusBar::~StatusBar( void )
{
    // destructor code here
}

int StatusBar::ColorsToInt( void )
{
    return (int)( ( bg_color << 4 ) | fg_color );
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

    if ( NULL == message ) return;

    // create buffer to hold status message
    // and ensure it doesn't exceed screen width
    char* buffer = (char*)calloc( disp_numcols - 2, sizeof( char ) );

    if ( NULL == buffer ) return;

    strncpy( buffer, message, disp_numcols - 2 );
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

    if ( NULL == format ) return;

    // create buffer to hold formatted status message
    char* buffer = (char*)calloc( disp_numcols - 2, sizeof( char ) );

    if ( NULL == buffer ) return;

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
