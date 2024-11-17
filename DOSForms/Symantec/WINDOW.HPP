// Window.hpp : class definition file

#ifndef WINDOW_HPP
#define WINDOW_HPP 1

#include <stdlib.h> // toupper()
#include <ctype.h> // toupper()
#include <string.h> // strlen()

class Window
{
    unsigned short m_top;
    unsigned short m_left;
    unsigned short m_bottom;
    unsigned short m_right;
    unsigned short m_color;
    unsigned short m_borderstyle;
    short m_drop_shadow;
    char m_title[21];
    char m_title_justify;
    char m_label[41];

public:
    Window( void );
    Window( const unsigned short Top, const unsigned short Left, const unsigned short Bottom, const unsigned short Right );
    Window( const unsigned short Top, const unsigned short Left, const unsigned short Bottom, const unsigned short Right, const unsigned short color, const unsigned short Style );
    ~Window( void );

    void Top( const unsigned short point );
    unsigned short Top( void ) const;
    void Left( const unsigned short point );
    unsigned short Left( void ) const;
    void Bottom( const unsigned short point );
    unsigned short Bottom( void ) const;
    void Right( const unsigned short point );
    unsigned short Right( void ) const;
    void Color( const unsigned short color );
    unsigned short Color( void ) const;
    void BorderStyle( const unsigned short Style );
    unsigned short BorderStyle( void ) const;
    void DropShadow( const short dropshadow );
    short DropShadow( void ) const;
    void Title( const char* Text );
    char* Title( void ) const;
    void TitleJustify( const char Justify );
    char TitleJustify( void ) const;
    void Label( const char* Text );
    char* Label( void ) const;

    void Coords( const unsigned short Top, const unsigned short Left, const unsigned short Bottom, const unsigned short Right );
};

#endif // WINDOW_H