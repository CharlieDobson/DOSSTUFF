// Popup class implementation file

#include "popup.hpp"
#include <disp.h>               // Symantec display functions
#include <msmouse.h>            // Symantec mouse functions
#include <stdlib.h>             // required for NULL
#include <stdio.h>              // _snprintf
#include <string.h>             // strncpy

Popup::Popup( void ) : DOSForms()
{
    screen_buffer = (unsigned short*)calloc( disp_numrows * disp_numcols + 1, sizeof( unsigned short ) );

    fg_color = FG_BLACK;
    bg_color = BG_WHITE;
    IsMouseEnabled = FALSE;

    coordinates.row = 0;
    coordinates.column = 0;
    coordinates.end_row = 0;
    coordinates.end_column = 0;
    border_style = BORDER_NONE;
    title[0] = '\0';
    text_justification = LEFT;
    drop_shadow = TRUE;
}

Popup::Popup( const foreground_color_t foreground, const background_color_t background )
{
    screen_buffer = (unsigned short*)calloc( disp_numrows * disp_numcols + 1, sizeof( unsigned short ) );

    fg_color = foreground;
    bg_color = background;
    IsMouseEnabled = FALSE;

    coordinates.row = 0;
    coordinates.column = 0;
    coordinates.end_row = 0;
    coordinates.end_column = 0;
    border_style = BORDER_NONE;
    title[0] = '\0';
    text_justification = LEFT;
    drop_shadow = TRUE;
}

Popup::Popup( const foreground_color_t foreground, const background_color_t background, const coordinates_t* coordinates )
{
    screen_buffer = (unsigned short*)calloc( disp_numrows * disp_numcols + 1, sizeof( unsigned short ) );

    fg_color = foreground;
    bg_color = background;
    IsMouseEnabled = FALSE;

    if ( NULL != coordinates ) {
        this->coordinates = *coordinates;
    } else {
        this->coordinates.row = 0;
        this->coordinates.column = 0;
        this->coordinates.end_row = 0;
        this->coordinates.end_column = 0;
    }
    border_style = BORDER_NONE;
    title[0] = '\0';
    text_justification = LEFT;
    drop_shadow = TRUE;
}

Popup::Popup( const foreground_color_t foreground, const background_color_t background, const coordinates_t* coordinates, const char* title )
{
    screen_buffer = (unsigned short*)calloc( disp_numrows * disp_numcols + 1, sizeof( unsigned short ) );

    fg_color = foreground;
    bg_color = background;
    IsMouseEnabled = FALSE;

    if ( NULL != coordinates ) {
        this->coordinates = *coordinates;
    } else {
        this->coordinates.row = 0;
        this->coordinates.column = 0;
        this->coordinates.end_row = 0;
        this->coordinates.end_column = 0;
    }
    border_style = BORDER_NONE;
    if ( NULL != title ) {
        strncpy( this->title, title, sizeof( this->title ) - 1 );
        this->title[ sizeof( this->title ) - 1 ] = '\0';
    } else {
        this->title[0] = '\0';
    }
    text_justification = LEFT;
    drop_shadow = TRUE;
}

Popup::~Popup( void )
{
    free( screen_buffer );
}

int Popup::ColorsToInt( void )
{
    return (int)( ( bg_color << 4 ) | fg_color );
}

boolean Popup::SaveWindow( void )
{
    if ( disp_inited == 0 ) return FALSE;

    if ( coordinates.row == 0 && coordinates.column == 0
         && coordinates.end_row == 0 && coordinates.end_column == 0 ) return FALSE;

    // define save area
    unsigned short start_row = coordinates.row;
    unsigned short start_column = coordinates.column;
    unsigned short end_row = coordinates.end_row;
    unsigned short end_column = coordinates.end_column;

    // account for dropshadow
    if ( drop_shadow ) {
        ++end_row;
        end_column += 2;
    }

    if ( IsMouseEnabled ) msm_hidecursor();

    // save screen contents to buffer
    disp_peekbox( screen_buffer, start_row, start_column, end_row, end_column );

    if ( IsMouseEnabled ) msm_showcursor();

    return TRUE;
}

boolean Popup::RestoreWindow( void )
{
    if ( disp_inited == 0 ) return FALSE;

    if ( coordinates.row == 0 && coordinates.column == 0
         && coordinates.end_row == 0 && coordinates.end_column == 0 ) return FALSE;

    // define restore area
    unsigned short start_row = coordinates.row;
    unsigned short start_column = coordinates.column;
    unsigned short end_row = coordinates.end_row;
    unsigned short end_column = coordinates.end_column;

    // account for dropshadow
    if ( drop_shadow ) {
        ++end_row;
        end_column += 2;
    }

    if ( IsMouseEnabled ) msm_hidecursor();

    // restore screen contents from buffer
    disp_pokebox( screen_buffer, start_row, start_column, end_row, end_column );

    if ( IsMouseEnabled ) msm_showcursor();

    return TRUE;
}

void Popup::Draw( void )
{
    if ( disp_inited == 0 ) return;

    if ( coordinates.row == 0 && coordinates.column == 0
         && coordinates.end_row == 0 && coordinates.end_column == 0 ) return;

    // save screen area
    if ( !SaveWindow() ) return;

    if ( IsMouseEnabled ) msm_hidecursor();

    if ( drop_shadow ) {
        // draw drop shadow
        disp_fillbox( BG_BLACK * 256 + ' ',
                      coordinates.row + 1,
                      coordinates.column + 2,
                      coordinates.end_row + 1,
                      coordinates.end_column + 2 );
    }

    // draw window box
    disp_setattr( ColorsToInt() );
    disp_box( border_style, ColorsToInt(),
              coordinates.row, coordinates.column,
              coordinates.end_row, coordinates.end_column );
    // fill window area
    disp_fillbox( ColorsToInt() * 256 + ' ',
                  coordinates.row + 1,
                  coordinates.column + 1,
                  coordinates.end_row - 1,
                  coordinates.end_column - 1 );

    // draw title if specified
    if ( title[0] != '\0' ) {
        char temp[38] = { '\0' };
        short title_length = (short)strlen( title );
        short title_column = coordinates.column + 3;

        switch ( text_justification ) {
            case LEFT: {
                title_column = coordinates.column + 3;
                break;
            }
            case CENTER: {
                title_column = coordinates.column +
                               ( ( coordinates.end_column - coordinates.column ) / 2 ) -
                               ( title_length / 2 );
                break;
            }
            case RIGHT: {
                title_column = coordinates.end_column - title_length - 3;
                break;
            }
            default: {
                break;
            }
        }

        _snprintf( temp, sizeof( temp ), " %s ", title ); // ensure spaces surround title
        disp_setattr( ColorsToInt() );
        disp_move( coordinates.row, title_column );
        disp_puts( temp );
    }

    if ( IsMouseEnabled ) msm_showcursor();
}
