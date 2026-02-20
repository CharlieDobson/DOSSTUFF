// class definition file for Buttons

#ifndef BUTTON_HPP
#define BUTTON_HPP

#include "dosforms.hpp"
#include "structs.hpp"

class Button : public DOSForms
{
public:
    Button( void );
    Button( const foreground_color_t foreground, const background_color_t background );
    Button( const foreground_color_t foreground, const background_color_t background, const coordinates_t* coordinates );
    Button( const foreground_color_t foreground, const background_color_t background, const coordinates_t* coordinates, const char* label );
    ~Button( void );

    coordinates_t coordinates;
    char label[16];
    boolean drop_shadow;

    // methods
    int ColorsToInt( void );
    void Draw( void );
};

#endif
