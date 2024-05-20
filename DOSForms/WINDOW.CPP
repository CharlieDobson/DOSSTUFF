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
    borderstyle = 5; // no border
    #elif ( _MSC_VER || __WATCOMC__ )
    text_color = 1; // BLUE
    background_color = 7; // WHITE
    #endif
    drop_shadow = 1; // drop shadow on
    title[0] = NULL;
    title_justify = 'L';
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
    borderstyle = 5; // no border
    #elif ( _MSC_VER || __WATCOMC__ )
    text_color = 1; // BLUE
    background_color = 7; // WHITE
    #endif
    drop_shadow = 1; // drop shadow on
    title[0] = NULL;
    title_justify = 'L';
    label[0] = NULL;
}

#ifdef __SC__
Window::Window( const unsigned short Top, const unsigned short Left, const unsigned short Bottom, const unsigned short Right, const unsigned short uColor, const unsigned short Style )
{
    top = Top;
    left = Left;
    bottom = Bottom;
    right = Right;
    color = uColor;
    borderstyle = Style;
    drop_shadow = 1; // drop shadow on
    title[0] = NULL;
    title_justify = 'L';
    label[0] = NULL;
}
#elif ( _MSC_VER || __WATCOMC__ )
Window::Window( const unsigned short Top, const unsigned short Left, const unsigned short Bottom, const unsigned short Right, const short TColor, const short BColor )
{
    top = Top;
    left = Left;
    bottom = Bottom;
    right = Right;
    text_color = TColor;
    background_color = BColor;
    drop_shadow = 1; // drop shadow on
    title[0] = NULL;
    title_justify = 'L';
    label[0] = NULL;
}
#endif

Window::~Window( void )
{

}

void Window::Top( const unsigned short point )
{
    if ( point < _MAX_WINDOW_ROWS ) {
        top = point;
    }
}

unsigned short Window::Top( void ) const
{
    return top;
}

void Window::Left( const unsigned short point )
{
    if ( point < _MAX_WINDOW_COLS ) {
        left = point;
    }
}

unsigned short Window::Left( void ) const
{
    return left;
}

void Window::Bottom( const unsigned short point )
{
    if ( point < _MAX_WINDOW_ROWS ) {
        bottom = point;
    }
}

unsigned short Window::Bottom( void ) const
{
    return bottom;
}

void Window::Right( const unsigned short point )
{
    if ( point < _MAX_WINDOW_COLS ) {
        right = point;
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

void Window::BorderStyle( const unsigned short Style )
{
    if ( Style > 0 && Style < 6 ) {
        borderstyle = Style;
    }
}

unsigned short Window::BorderStyle( void ) const
{
    return borderstyle;
}

#elif ( _MSC_VER || __WATCOMC__ )
void Window::TextColor( const short Color )
{
    text_color = Color;
}

short Window::TextColor( void ) const
{
    return text_color;
}

void Window::BackgroundColor( const long Color )
{
    background_color = Color;
}

long Window::BackgroundColor( void ) const
{
    return background_color;
}
#endif

void Window::DropShadow( const short dropshadow )
{
    if ( dropshadow == 0 ) {
        drop_shadow = 0;
    }
    else {
        drop_shadow = 1;
    }
    //dropshadow == 0 ? drop_shadow = 0 : drop_shadow = 1;
}

short Window::DropShadow( void ) const
{
    return drop_shadow;
}

void Window::Title( const char* Text )
{
    if ( strlen( Text ) < _MAX_WINDOW_TITLE ) {
        strcpy( title, Text );
    }
}

char* Window::Title( void ) const
{
    return (char*)title;
}

void Window::TitleJustify( const char Justify )
{
    if ( toupper( Justify ) == 'L' ) {
        title_justify = 'L';
    }
    else if ( toupper( Justify ) == 'C' ) {
        title_justify = 'C';
    }
    else if ( toupper( Justify ) == 'R' ) {
        title_justify = 'R';
    }
}

char Window::TitleJustify( void ) const
{
    return title_justify;
}

void Window::Label( const char* Text )
{
    if ( strlen( Text ) < _MAX_WINDOW_LABEL ) {
        strcpy( label, Text );
    }
}

char* Window::Label( void ) const
{
    return (char*)label;
}

void Window::Coords( const unsigned short Top, const unsigned short Left, const unsigned short Bottom, const unsigned short Right )
{
    if ( Top < _MAX_WINDOW_ROWS ) {
        top = Top;
    }
    if ( Left < _MAX_WINDOW_COLS ) {
        left = Left;
    }
    if ( Bottom < _MAX_WINDOW_ROWS ) {
        bottom = Bottom;
    }
    if ( Right < _MAX_WINDOW_COLS ) {
        right = Right;
    }
}