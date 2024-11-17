// Window.hpp : class definition file

#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <stdlib.h> // toupper()
#include <ctype.h> // toupper()
#include <string.h> // strlen()

class Window
{
    unsigned short top;
    unsigned short left;
    unsigned short bottom;
    unsigned short right;
    #ifdef __SC__
    unsigned short color;
    unsigned short borderstyle;
    #elif ( _MSC_VER || __WATCOMC__ )
    short text_color;
    long background_color;
    #endif
    short drop_shadow;
    char title[21];
    char title_justify;
    char label[41];

  public:
    Window( void );
    Window( const unsigned short Top, const unsigned short Left, const unsigned short Bottom, const unsigned short Right );
	#ifdef __SC__
    Window( const unsigned short Top, const unsigned short Left, const unsigned short Bottom, const unsigned short Right, const unsigned short uColor, const unsigned short Style );
	#elif ( _MSC_VER || __WATCOMC__ )
    Window( const unsigned short Top, const unsigned short Left, const unsigned short Bottom, const unsigned short Right, const short TColor, const short BColor );
	#endif
    ~Window( void );

    void Top( const unsigned short point );
    unsigned short Top( void ) const;
    void Left( const unsigned short point );
    unsigned short Left( void ) const;
    void Bottom( const unsigned short point );
    unsigned short Bottom( void ) const;
    void Right( const unsigned short point );
    unsigned short Right( void ) const;
    #ifdef __SC__
    void Color( const unsigned short uColor );
    unsigned short Color( void ) const;
    void BorderStyle( const unsigned short Style );
    unsigned short BorderStyle( void ) const;
    #elif ( _MSC_VER || __WATCOMC__ )
    void TextColor( const short Color );
    short TextColor( void ) const;
    void BackgroundColor( const long Color );
    long BackgroundColor( void ) const;
    #endif
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