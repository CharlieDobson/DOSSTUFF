// Message.hpp : DOSForms message window definition file

#ifndef FORMMESSAGE_HPP
#define FORMMESSAGE_HPP 1

#include "structs.hpp"
#include <string.h>


class FormMessageWindow
{
    forms_colors_t m_color;
    window_coordinates_t m_coordinates;
    char* m_title;
    char* m_message;
    dialog_buttons_t m_buttons;

public:
    FormMessageWindow( const forms_colors_t color, const window_coordinates_t coordinates, const char* title, const char* message, const dialog_buttons_t buttons );
    FormMessageWindow( const foreground_colors_t foreground, const background_colors_t background, const short row, const short column, const short height, const short width, const char* title, const char* message, const dialog_buttons_t buttons );
    FormMessageWindow( const FormMessageWindow& messageWindow );
    ~FormMessageWindow( void );

    // operators
    FormMessageWindow& operator=( const FormMessageWindow& messageWindow );
    boolean operator==( const FormMessageWindow& messageWindow );
    
    // accessors
    forms_colors_t color( void ) const;
    window_coordinates_t coordinates( void ) const;
    char* title( void ) const;
    char* message( void ) const;
    dialog_buttons_t buttons( void ) const;

    // mutators
    void color( const forms_colors_t color );
    void coordinates( const window_coordinates_t coordinates );
    void title( const char* title );
    void message( const char* message );
    void buttons( const dialog_buttons_t buttons );
};


#endif