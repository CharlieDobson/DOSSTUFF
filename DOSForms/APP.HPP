// class definition for Application

#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include "dosforms.hpp"
#include "structs.hpp"

class Application : public DOSForms
{
public:
    Application( void );
    Application( const foreground_color_t foreground, const background_color_t background );
    ~Application( void );

    int ColorsToInt( void );
    void Draw( void );
};

#endif
