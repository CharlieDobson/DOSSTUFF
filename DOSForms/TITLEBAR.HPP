// class definition file for TitleBar

#ifndef TITLEBAR_HPP
#define TITLEBAR_HPP

#include "dosforms.hpp"
#include "structs.hpp"

class TitleBar : public DOSForms
{
public:
    TitleBar( void );
    TitleBar( const foreground_color_t foreground, const background_color_t background );
    TitleBar( const foreground_color_t foreground, const background_color_t background, const char* title );
    ~TitleBar( void );

    char Text[35];

    // methods
    int ColorsToInt( void );
    void Draw( void );
};

#endif
