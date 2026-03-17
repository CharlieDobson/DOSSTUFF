// class definition file for Buttons

#ifndef BUTTON_HPP
#define BUTTON_HPP

#include "dosforms.hpp"
#include "structs.hpp"

class Button : public DOSForms
{
public:
    Button( void );
    Button( const char* label );
    Button( const coordinates_t* coordinates, const char* label );
    Button( const foreground_color_t foreground, const background_color_t background );
    Button( const foreground_color_t foreground, const background_color_t background, const coordinates_t* coordinates );
    Button( const foreground_color_t foreground, const background_color_t background, const coordinates_t* coordinates, const char* label );
    Button( const Button& other );

    coordinates_t coordinates;
    char label[16];
    boolean drop_shadow;
    foreground_color_t hotkey_color;
    char hotkey;

    // methods
    void Draw( void );
    void SetCoordinates( const unsigned short row, const unsigned short column, const unsigned short end_row, const unsigned short end_column );
    void SetCoordinates( const unsigned short row, const unsigned short column );
    Button& operator=( const Button& other );
};

#endif