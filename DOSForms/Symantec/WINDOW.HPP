// Window.hpp : class definition file

#ifndef WINDOW_HPP
#define WINDOW_HPP 1

#include <stdlib.h>     // toupper
#include <ctype.h>      // toupper
#include <string.h>     // strlen
#if _DEBUG
#include <stdio.h>		// puts
#endif
#if defined( _MSC_VER ) || defined( __WATCOMC__ )
#include <graph.h>
#elif __SC__
#include <disp.h>
#endif
#include "structs.hpp"

class Window
{
    window_coordinates_t m_coordinates;
    forms_colors_t m_color;
    window_border_style_t m_border_style;
    short m_cols_max;
    short m_rows_max;
    boolean m_drop_shadow;
    char *m_title;
    char m_title_justify;

public:
    Window( void );
    Window( const foreground_colors_t Foreground, const background_colors_t Background );
    Window( const short Row, const short Column, const short EndRow, const short EndColumn );
    Window( const short Row, const short Column, const short EndRow, const short EndColumn, const foreground_colors_t Foreground, const background_colors_t Background, const window_border_style_t Style );
    Window( const short Row, const short Column, const short EndRow, const short EndColumn, const foreground_colors_t Foreground, const background_colors_t Background, const window_border_style_t Style, const char* TitleText );
    ~Window( void );

    // accessors
    const window_coordinates_t Coordinates( void ) const;
    const forms_colors_t Color( void ) const;
    const window_border_style_t BorderStyle( void ) const;
    boolean DropShadow( void ) const;
    const char* Title( void ) const;
    const char TitleJustify( void ) const;

    // mutators
    void Coordinates( const window_coordinates_t Coordinates );
    void Coordinates( const short Row, const short Column, const short EndRow, const short EndColumn );
    void Color( const forms_colors_t Color );
    void Color( const foreground_colors_t Foreground, const background_colors_t Background );
    void BorderStyle( const window_border_style_t Style );
    void DropShadow( const boolean DropShadow );
    void Title( const char* Text );
    void TitleJustify( const char Justify );
};

#endif // WINDOW_H
