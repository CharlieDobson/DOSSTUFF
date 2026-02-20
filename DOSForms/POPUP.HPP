// class definition file for Popup

#ifndef POPUP_HPP
#define POPUP_HPP

#include "dosforms.hpp"
#include "structs.hpp"

class Popup : public DOSForms
{
public:
    Popup( void );
    Popup( const foreground_color_t foreground, const background_color_t background );
    Popup( const foreground_color_t foreground, const background_color_t background, const coordinates_t* coordinates );
    Popup( const foreground_color_t foreground, const background_color_t background, const coordinates_t* coordinates, const char* title );
    ~Popup( void );

    coordinates_t coordinates;
    border_style_t border_style;
    char title[35];
    text_justify_t text_justification;
    boolean drop_shadow;

    // methods
    int ColorsToInt( void );
    void Draw( void );
    boolean RestoreWindow( void );

protected:
    unsigned short* screen_buffer;
    boolean SaveWindow( void );
};

#endif