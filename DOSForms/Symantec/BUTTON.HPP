// Button.hpp : DOSForms button definition file

#ifndef BUTTON_HPP
#define BUTTON_HPP 1

#include "structs.hpp"
#include <string.h>
#include <string.h>     // strlen
#if _DEBUG
#include <stdio.h>		// puts
#endif

class FormButton
{
    forms_colors_t m_color;
    window_coordinates_t m_coordinates;
    char* m_label;
    boolean m_drop_shadow;

public:
    FormButton( void );
    FormButton( const foreground_colors_t Foreground, const background_colors_t Background );
    FormButton( const forms_colors_t Color, const window_coordinates_t Coordinates, char* Label );
    FormButton( const foreground_colors_t Foreground, const background_colors_t Background, const short Row, const short Column, const short EndRow, const short EndColumn, char* Label );
    FormButton( const short Row, const short Column, const short EndRow, const short EndColumn, char* Label );
    FormButton( const FormButton& Button );
    ~FormButton( void );

    // operators
    const FormButton& operator=( const FormButton& Button );
    boolean operator==( const FormButton& Button );

    // accessors
    const forms_colors_t Color( void ) const;
    const window_coordinates_t Coordinates( void ) const;
    const char* Label( void ) const;
    boolean DropShadow( void ) const;

    // mutators
    void Color( const forms_colors_t Color );
    void Color( const foreground_colors_t Foreground, const background_colors_t Background );
    void Coordinates( const short Row, const short Column, const short EndRow, const short EndColumn );
    void Coordinates( const window_coordinates_t Coordinates );
    void Label( const char* Label );
    void DropShadow( const boolean DropShadow );
};


#endif // BUTTON_HPP