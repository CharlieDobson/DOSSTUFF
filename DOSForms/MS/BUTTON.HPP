// Button.hpp : DOSForms button definition file

#ifndef BUTTON_HPP
#define BUTTON_HPP 1

#include "structs.hpp"
#include <string.h>


class FormButton
{
    forms_colors_t m_color;
    window_coordinates_t m_coordinates;
    char* m_label;

public:
    FormButton( const forms_colors_t color, const window_coordinates_t coordinates, char* label );
    FormButton( const foreground_colors_t foreground, const background_colors_t background, const short column, const short row, const short width, const short height, char* label );
    FormButton( const FormButton& button );
    ~FormButton( void );

    // operators
    FormButton& operator=( const FormButton& button );
    int operator==( const FormButton& button );
    
    // accessors
    forms_colors_t color( void ) const;
    window_coordinates_t coordinates( void ) const;
    char* label( void ) const;

    // mutators
    void color( const forms_colors_t color );
    void coordinates( const window_coordinates_t coordinates );
    void label( const char* label );
};


#endif