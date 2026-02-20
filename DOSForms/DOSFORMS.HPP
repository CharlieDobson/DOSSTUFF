// DOSForms base class definition

#ifndef DOSFORMS_HPP
#define DOSFORMS_HPP

#include "structs.hpp"

class DOSForms
{
public:
    DOSForms( void );
    virtual ~DOSForms( void );

    foreground_color_t fg_color;
    background_color_t bg_color;
    boolean IsMouseEnabled;

    // methods
    virtual int ColorsToInt( void ) = 0;
    virtual void Draw( void ) = 0;

protected:

};

#endif
