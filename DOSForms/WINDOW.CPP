// Window.cpp : class implementation file

#include "window.hpp"

#ifdef __SC__
const int _MAX_WINDOW_ROWS = 24;
const int _MAX_WINDOW_COLS = 79;
#else
const int _MAX_WINDOW_ROWS = 25;
const int _MAX_WINDOW_COLS = 80;
#endif

const int _MAX_WINDOW_TITLE = 20;
const int _MAX_WINDOW_LABEL = 40;

Window::Window( void )
{
    top = 0;
    left = 0;
    bottom = 0;
    right = 0;
    #ifdef __SC__
    color = 0x81; // BLUE_ON_GRAY
    #else
    textColor = 1; // BLUE
    backgroundColor = 0x151515L; // GRAY
    #endif
    borderstyle = 5; // no border
    title[0] = NULL;
    titlejustify = 'L';
    label[0] = NULL;
}

Window::Window( const unsigned short Top, const unsigned short Left, const unsigned short Bottom, const unsigned short Right )
{
    top = Top;
    left = Left;
    bottom = Bottom;
    right = Right;
    #ifdef __SC__
    color = 0x81; // BLUE_ON_GRAY
    #else
    textColor = 1; // BLUE
    backgroundColor = 0x151515L; // GRAY
    #endif
    borderstyle = 5; // no border
    title[0] = NULL;
    titlejustify = 'L';
    label[0] = NULL;
}

Window::~Window( void )
{

}

void Window::Top( const unsigned short uTop )
{
    if ( uTop < _MAX_WINDOW_ROWS ) {
        top = uTop;
    }
}

unsigned short Window::Top( void ) const
{
    return top;
}

void Window::Left( const unsigned short uLeft )
{
    if ( uLeft < _MAX_WINDOW_COLS ) {
        left = uLeft;
    }
}

unsigned short Window::Left( void ) const
{
    return left;
}

void Window::Bottom( const unsigned short uBottom )
{
    if ( uBottom < _MAX_WINDOW_ROWS ) {
        bottom = uBottom;
    }
}

unsigned short Window::Bottom( void ) const
{
    return bottom;
}

void Window::Right( const unsigned short uRight )
{
    if ( uRight < _MAX_WINDOW_COLS ) {
        right = uRight;
    }
}

unsigned short Window::Right( void ) const
{
    return right;
}

#ifdef __SC__
void Window::Color( const unsigned short uColor )
{
    color = uColor;
}

unsigned short Window::Color( void ) const
{
    return color;
}

#else
void Window::TextColor( const short iTextColor )
{
    textColor = iTextColor;
}

short Window::TextColor( void ) const
{
    return textColor;
}

void Window::BackgroundColor( const long iBackgroundColor )
{
    backgroundColor = iBackgroundColor;
}

long Window::BackgroundColor( void ) const
{
    return backgroundColor;
}
#endif

void Window::BorderStyle( const unsigned short uBorderStyle )
{
    if ( uBorderStyle > 0 && uBorderStyle < 6 ) {
        borderstyle = uBorderStyle;
    }
}

unsigned short Window::BorderStyle( void ) const
{
    return borderstyle;
}

void Window::Title( const char *szTitle )
{
    if ( strlen( szTitle ) < _MAX_WINDOW_TITLE ) {
        strcpy( title, szTitle );
    }
}

char* Window::Title( void ) const
{
    return title;
}

void Window::TitleJustify( const char chTitleJustify )
{
    if ( toupper( chTitleJustify ) == 'L' ) {
        titlejustify = 'L';
    }
    else if ( toupper( chTitleJustify ) == 'C' ) {
        titlejustify = 'C';
    }
    else if ( toupper( chTitleJustify ) == 'R' ) {
        titlejustify = 'R';
    }
}

char Window::TitleJustify( void ) const
{
    return titlejustify;
}

void Window::Label( const char *szLabel )
{
    if ( strlen( szLabel ) < _MAX_WINDOW_LABEL ) {
        strcpy( label, szLabel );
    }
}

char* Window::Label( void ) const
{
    return label;
}

void Window::Coords( const unsigned short uTop, const unsigned short uLeft, const unsigned short uBottom, const unsigned short uRight )
{
    if ( uTop < _MAX_WINDOW_ROWS ) {
        top = uTop;
    }
    if ( uLeft < _MAX_WINDOW_COLS ) {
        left = uLeft;
    }
    if ( uBottom < _MAX_WINDOW_ROWS ) {
        bottom = uBottom;
    }
    if ( uRight < _MAX_WINDOW_COLS ) {
        right = uRight;
    }
}
