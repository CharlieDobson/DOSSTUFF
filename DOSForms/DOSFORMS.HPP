// DOSForms base class definition

#ifndef DOSFORMS_HPP
#define DOSFORMS_HPP

#include "structs.hpp"

class DOSForms
{
public:
    DOSForms( void );
    DOSForms( const foreground_color_t foreground, const background_color_t background );
    virtual ~DOSForms( void );

    foreground_color_t fg_color;
    background_color_t bg_color;
    boolean IsMouseEnabled;

    // methods
    virtual int ColorsToInt( void );
    virtual void Draw( void );
};

#endif