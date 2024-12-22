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
    FormButton( void );
    FormButton( const forms_colors_t color, const window_coordinates_t coordinates, char* label );
    FormButton( const foreground_colors_t foreground, const background_colors_t background, const short row, const short column, const short height, const short width, char* label );
    FormButton( const FormButton& button );
    ~FormButton( void );

    // operators
    FormButton& operator=( const FormButton& button );
    boolean operator==( const FormButton& button );

    // accessors
    forms_colors_t Color( void ) const;
    window_coordinates_t Coordinates( void ) const;
    char* Label( void ) const;

    // mutators
    void Color( const forms_colors_t color );
    void Color( const foreground_colors_t foreground, const background_colors_t background );
    void Coordinates( const short x, const short y, const short end_x, const short end_y );
    void Coordinates( const window_coordinates_t coordinates );
    void Label( const char* label );
};


#endif