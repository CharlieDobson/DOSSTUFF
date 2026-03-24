// class definition file for DlgBox class

#ifndef DLGBOX_HPP
#define DLGBOX_HPP

#include "memmod.hpp"
#include "structs.hpp"
#include "popup.hpp"
#include "button.hpp"

class DlgBox : public Popup
{
private:
    DlgBox( const DlgBox & );
    DlgBox &operator=( const DlgBox & );

public:
    DlgBox( const foreground_color_t foreground, const background_color_t background );
    DlgBox( const foreground_color_t foreground, const background_color_t background, const char* message );
    DlgBox( const foreground_color_t foreground, const background_color_t background, const dialog_buttons_t* buttons );
    DlgBox( const foreground_color_t foreground, const background_color_t background, const dialog_buttons_t* buttons, const char* message );

    char message[256];
    dialog_buttons_t buttons;

    // methods
    void Draw( void );
    button_return_value_t Show( void );
};

#endif