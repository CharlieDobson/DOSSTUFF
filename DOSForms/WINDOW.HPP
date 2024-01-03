// Window.hpp : class definition file

#ifndef WINDOW_H
#define WINDOW_H

#include <stdlib.h>         // toupper()
#include <ctype.h>          // toupper()
#include <string.h>         // strlen()

class Window
{
    unsigned short top;
    unsigned short left;
    unsigned short bottom;
    unsigned short right;
    #ifdef __SC__
    unsigned short color;
    #else
    short textColor;
    long backgroundColor;
    #endif
    unsigned short borderstyle;
    char title[21];
    char titlejustify;
    char label[41];

  public:
    Window( void );
    Window( const unsigned short Top, const unsigned short Left, const unsigned short Bottom, const unsigned short Right );
    ~Window( void );

    void Top( const unsigned short uTop );
    unsigned short Top( void ) const;
    void Left( const unsigned short uLeft );
    unsigned short Left( void ) const;
    void Bottom( const unsigned short uBottom );
    unsigned short Bottom( void ) const;
    void Right( const unsigned short uRight );
    unsigned short Right( void ) const;
    #ifdef __SC__
    void Color( const unsigned short uColor );
    unsigned short Color( void ) const;
    #else
    void TextColor( const short iTextColor );
    short TextColor( void ) const;
    void BackgroundColor( const long iBackgroundColor );
    long BackgroundColor( void ) const;
    #endif
    void BorderStyle( const unsigned short uBorderStyle );
    unsigned short BorderStyle( void ) const;
    void Title( const char *szTitle );
    char* Title( void ) const;
    void TitleJustify( const char chTitleJustify );
    char TitleJustify( void ) const;
    void Label( const char *szLabel );
    char* Label( void ) const;

    void Coords( const unsigned short uTop, const unsigned short uLeft, const unsigned short uBottom, const unsigned short uRight );
};

#endif // WINDOW_H