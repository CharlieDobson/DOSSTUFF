// Message.hpp : DOSForms message window definition file

#ifndef FORMMESSAGE_HPP
#define FORMMESSAGE_HPP 1

#include "structs.hpp"
#include <string.h>


class FormMessage
{
    forms_colors_t m_color;
    window_coordinates_t m_coordinates;
    char* m_title;
    char* m_message;
    dialog_buttons_t m_buttons;

public:
    FormMessage( const forms_colors_t color, const window_coordinates_t coordinates, const char* title, const char* message, const dialog_buttons_t buttons );
    FormMessage( const foreground_colors_t foreground, const background_colors_t background, const short row, const short column, const short height, const short width, const char* title, const char* message, const dialog_buttons_t buttons );
    FormMessage( const FormMessage& formMessage );
    ~FormMessage( void );

    // operators
    FormMessage& operator=( const FormMessage& formMessage );
    boolean operator==( const FormMessage& formMessage );
    
    // accessors
    forms_colors_t color( void ) const;
    window_coordinates_t coordinates( void ) const;
    char* title( void ) const;
    char* message( void ) const;
    dialog_buttons_t buttons( void ) const;

    // mutators
    void color( const forms_colors_t color );
    void color( const foreground_colors_t foreground, const background_colors_t background );
    void coordinates( const window_coordinates_t coordinates );
    void coordinates( const short row, const short column, const short height, const short width );
    void title( const char* title );
    void message( const char* message );
    void buttons( const dialog_buttons_t buttons );
};


#endif