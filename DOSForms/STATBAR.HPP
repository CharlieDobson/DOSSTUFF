// class definition file for StatusBar

#ifndef STATUSBAR_HPP
#define STATUSBAR_HPP

#include "dosforms.hpp"
#include "structs.hpp"
#include <stdarg.h>

class StatusBar : public DOSForms
{
public:
    StatusBar( void );
    StatusBar( const foreground_color_t foreground, const background_color_t background );
    ~StatusBar( void );

    // methods
    int ColorsToInt( void );
    void Draw( void );
    void Print( const char* message );
    void Printf( const char* format, ... );
};

#endif

