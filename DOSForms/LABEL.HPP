// class definition file for Label

#ifndef LABEL_HPP
#define LABEL_HPP

#include "dosforms.hpp"
#include "structs.hpp"
#include <stdarg.h>

class Label : public DOSForms
{
public:
    Label( void );
    Label( const char* text );
    Label( const unsigned short row, const unsigned short column, const char* text );
    Label( const foreground_color_t foreground, const background_color_t background );
    Label( const foreground_color_t foreground, const background_color_t background, const char* text );
    Label( const foreground_color_t foreground, const background_color_t background, const unsigned short row, const unsigned short column, const char* text );

    unsigned short row;
    unsigned short column;
    char text[80];

    // methods
    void Draw( void );
    void SetPosition( const unsigned short row, const unsigned short column );
    void SetText( const char* format, ... );
};

#endif
