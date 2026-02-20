// Button class implementation

#ifndef __SC__
#error This file should only be compiled by Symantec C++ compiler
#endif
#include "button.hpp"
#include <disp.h>               // Symantec display functions
#include <msmouse.h>            // Symantec mouse functions
#include <stdlib.h>             // required for NULL
#include <string.h>             // strlen

Button::Button( void ) : DOSForms()
{
    fg_color = FG_BLACK;
    bg_color = BG_WHITE;
    IsMouseEnabled = FALSE;

    coordinates.row = 0;
    coordinates.column = 0;
    coordinates.end_row = 0;
    coordinates.end_column = 0;
    label[0] = '\0';
    drop_shadow = TRUE;
}

Button::Button( const foreground_color_t foreground, const background_color_t background )
{
    fg_color = foreground;
    bg_color = background;
    IsMouseEnabled = FALSE;

    coordinates.row = 0;
    coordinates.column = 0;
    coordinates.end_row = 0;
    coordinates.end_column = 0;
    label[0] = '\0';
    drop_shadow = TRUE;
}

Button::Button( const foreground_color_t foreground, const background_color_t background, const coordinates_t* coordinates )
{
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
    label[0] = '\0';
    drop_shadow = TRUE;
}

Button::Button( const foreground_color_t foreground, const background_color_t background, const coordinates_t* coordinates, const char* label )
{
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
    if ( NULL != label ) {
        strncpy( this->label, label, sizeof( this->label ) - 1 );
        this->label[ sizeof( this->label ) - 1 ] = '\0';
    } else {
        this->label[0] = '\0';
    }
    drop_shadow = TRUE;
}

Button::~Button( void )
{
    // destructor code here
}

int Button::ColorsToInt( void )
{
    return (int)( ( bg_color << 4 ) | fg_color );
}

void Button::Draw( void )
{
    if ( disp_inited == 0 ) return;

    if ( IsMouseEnabled ) msm_hidecursor();

    // draw drop shadow if specified
    if ( drop_shadow ) {
        disp_fillbox( BG_BLACK * 256 + ' ',
                      coordinates.row + 1,
                      coordinates.column + 2,
                      coordinates.end_row + 1,
                      coordinates.end_column + 2 );
    }

    // draw button box
    disp_box( 1, ColorsToInt(),
              coordinates.row, coordinates.column,
              coordinates.end_row, coordinates.end_column );
    disp_fillbox( ColorsToInt() * 256 + ' ',
                  coordinates.row,
                  coordinates.column,
                  coordinates.end_row,
                  coordinates.end_column );

    // draw button label if specified
    if ( label[0] != '\0' ) {
        short button_width = coordinates.end_column - coordinates.column;
        char* temp = (char*)calloc( button_width - 2, sizeof( char ) );

        if ( NULL == temp ) return;

        strncpy( temp, label, button_width - 2 );
        temp[button_width - 3] = '\0';

        short label_length = (short)strlen( temp );
        short label_row = coordinates.row +
                          ( ( coordinates.end_row - coordinates.row ) / 2 );
        short label_column = coordinates.column +
                             ( ( coordinates.end_column - coordinates.column ) / 2 ) -
                             ( label_length / 2 );

        disp_setattr( ColorsToInt() );
        disp_move( label_row, label_column );
        disp_puts( temp );
        free( temp );
    }
}
