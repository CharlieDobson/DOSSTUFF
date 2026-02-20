// class definition file for DlgBox class

#ifndef DLGBOX_HPP
#define DLGBOX_HPP

#include "memmod.hpp"
#include "structs.hpp"
#include "popup.hpp"

class DlgBox : public Popup
{
public:
    DlgBox( void );
    DlgBox( const foreground_color_t foreground, const background_color_t background );
    DlgBox( const foreground_color_t foreground, const background_color_t background, const char PTYPE* message );
    DlgBox( const foreground_color_t foreground, const background_color_t background, const dialog_buttons_t* buttons );
    DlgBox( const foreground_color_t foreground, const background_color_t background, const dialog_buttons_t* buttons, const char PTYPE* message );
    ~DlgBox( void );

    char message[256];
    dialog_buttons_t buttons;

    // methods
    int ColorsToInt( void );
    void Draw( void );
    button_return_value_t Open( void );

private:
    boolean RestoreWindow( void );
    boolean SaveWindow( void );

};

#endif