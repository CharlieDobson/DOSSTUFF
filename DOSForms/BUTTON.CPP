// Button class implementation

#ifndef __SC__
#error This file should only be compiled by Symantec C++ compiler
#endif
#include "button.hpp"
#include <stdlib.h>             // calloc, free
#include <disp.h>               // Symantec display functions
#include <msmouse.h>            // Symantec mouse functions
#include <string.h>             // strlen

Button::Button( void ) : DOSForms( FG_YELLOW, BG_GREEN )
{
    coordinates.row = 0;
    coordinates.column = 0;
    coordinates.end_row = 0;
    coordinates.end_column = 0;
    this->label[0] = '\0';
    drop_shadow = TRUE;
}

Button::Button( const char* label ) : DOSForms( FG_YELLOW, BG_GREEN )
{
    coordinates.row = 0;
    coordinates.column = 0;
    coordinates.end_row = 0;
    coordinates.end_column = 0;
    this->label[0] = '\0';

    if ( label && label[0] != '\0' ) {
        strncpy( this->label, label, sizeof( this->label ) - 1 );
        this->label[ sizeof( this->label ) - 1 ] = '\0';
    }
    drop_shadow = TRUE;
}

Button::Button( const coordinates_t* coordinates, const char* label ) : DOSForms( FG_YELLOW, BG_GREEN )
{
    this->coordinates.row = 0;
    this->coordinates.column = 0;
    this->coordinates.end_row = 0;
    this->coordinates.end_column = 0;
    this->label[0] = '\0';

    if ( coordinates ) {
        this->coordinates = *coordinates;
    }
    if ( label && label[0] != '\0' ) {
        strncpy( this->label, label, sizeof( this->label ) - 1 );
        this->label[ sizeof( this->label ) - 1 ] = '\0';
    }
    drop_shadow = TRUE;
}

Button::Button( const foreground_color_t foreground, const background_color_t background )
    : DOSForms( foreground, background )
{
    coordinates.row = 0;
    coordinates.column = 0;
    coordinates.end_row = 0;
    coordinates.end_column = 0;
    label[0] = '\0';
    drop_shadow = TRUE;
}

Button::Button( const foreground_color_t foreground, const background_color_t background, const coordinates_t* coordinates )
    : DOSForms( foreground, background )
{
    this->coordinates.row = 0;
    this->coordinates.column = 0;
    this->coordinates.end_row = 0;
    this->coordinates.end_column = 0;
    label[0] = '\0';

    if ( coordinates ) {
        this->coordinates = *coordinates;
    }
    drop_shadow = TRUE;
}

Button::Button( const foreground_color_t foreground, const background_color_t background, const coordinates_t* coordinates, const char* label )
    : DOSForms( foreground, background )
{
    this->coordinates.row = 0;
    this->coordinates.column = 0;
    this->coordinates.end_row = 0;
    this->coordinates.end_column = 0;
    this->label[0] = '\0';

    if ( coordinates ) {
        this->coordinates = *coordinates;
    }
    if ( label && label[0] != '\0' ) {
        strncpy( this->label, label, sizeof( this->label ) - 1 );
        this->label[ sizeof( this->label ) - 1 ] = '\0';
    }
    drop_shadow = TRUE;
}

Button::Button( const Button& other ) : DOSForms( other.fg_color, other.bg_color )
{
    coordinates = other.coordinates;
    strncpy( label, other.label, sizeof( label ) - 1 );
    label[ sizeof( label ) - 1 ] = '\0';
    drop_shadow = other.drop_shadow;
}

Button& Button::operator=( const Button& other )
{
    if ( this != &other ) {
        fg_color = other.fg_color;
        bg_color = other.bg_color;
        coordinates = other.coordinates;
        strncpy( label, other.label, sizeof( label ) - 1 );
        label[ sizeof( label ) - 1 ] = '\0';
        drop_shadow = other.drop_shadow;
    }
    return *this;
}

void Button::SetCoordinates( const unsigned short row, const unsigned short column, const unsigned short end_row, const unsigned short end_column )
{
    // ensure valid coordinates
    if ( end_row < row || end_column < column ) return;

    coordinates.row = row;
    coordinates.column = column;
    coordinates.end_row = end_row;
    coordinates.end_column = end_column;
}

void Button::SetCoordinates( const unsigned short row, const unsigned short column )
{
    // default button size to 3 rows and size of label + 2 columns, or 10 columns if no label
    label[0] == '\0' ? SetCoordinates( row, column, row + 2, column + 10 ) :
                      SetCoordinates( row, column, row + 2, column + (unsigned short)strlen( label ) + 2 );
}

void Button::Draw( void )
{
    if ( disp_inited == 0 ) return;

    // don't draw button if coordinates are not set
    if ( coordinates.row == 0 && coordinates.column == 0
         && coordinates.end_row == 0 && coordinates.end_column == 0 ) return;

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