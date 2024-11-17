// Window.cpp : class implementation file

#include "window.hpp"

const int max_window_rows = 24;
const int max_window_cols = 79;

const int max_window_title = 20;
const int max_window_label = 40;

Window::Window( void )
{
    m_top = 0;
    m_left = 0;
    m_bottom = 0;
    m_right = 0;
    m_color = 0x81; // BLUE_ON_GRAY
    m_borderstyle = 5; // no border
    m_drop_shadow = 1; // drop shadow on
    m_title[0] = NULL;
    m_title_justify = 'L';
    m_label[0] = NULL;
}

Window::Window( const unsigned short Top, const unsigned short Left, const unsigned short Bottom, const unsigned short Right )
{
    m_top = Top;
    m_left = Left;
    m_bottom = Bottom;
    m_right = Right;
    m_color = 0x81; // BLUE_ON_GRAY
    m_borderstyle = 5; // no border
    m_drop_shadow = 1; // drop shadow on
    m_title[0] = NULL;
    m_title_justify = 'L';
    m_label[0] = NULL;
}

Window::Window( const unsigned short Top, const unsigned short Left, const unsigned short Bottom, const unsigned short Right, const unsigned short color, const unsigned short Style )
{
    m_top = Top;
    m_left = Left;
    m_bottom = Bottom;
    m_right = Right;
    m_color = color;
    m_borderstyle = Style;
    m_drop_shadow = 1; // drop shadow on
    m_title[0] = NULL;
    m_title_justify = 'L';
    m_label[0] = NULL;
}

Window::~Window( void )
{

}

void Window::Top( const unsigned short point )
{
    if ( point < max_window_rows ) {
        m_top = point;
    }
}

unsigned short Window::Top( void ) const
{
    return m_top;
}

void Window::Left( const unsigned short point )
{
    if ( point < max_window_cols ) {
        m_left = point;
    }
}

unsigned short Window::Left( void ) const
{
    return m_left;
}

void Window::Bottom( const unsigned short point )
{
    if ( point < max_window_rows ) {
        m_bottom = point;
    }
}

unsigned short Window::Bottom( void ) const
{
    return m_bottom;
}

void Window::Right( const unsigned short point )
{
    if ( point < max_window_cols ) {
        m_right = point;
    }
}

unsigned short Window::Right( void ) const
{
    return m_right;
}

void Window::Color( const unsigned short color )
{
    m_color = color;
}

unsigned short Window::Color( void ) const
{
    return m_color;
}

void Window::BorderStyle( const unsigned short Style )
{
    if ( Style > 0 && Style < 6 ) {
        m_borderstyle = Style;
    }
}

unsigned short Window::BorderStyle( void ) const
{
    return m_borderstyle;
}

void Window::DropShadow( const short dropshadow )
{
    if ( dropshadow == 0 ) {
        m_drop_shadow = 0;
    }
    else {
        m_drop_shadow = 1;
    }
    //dropshadow == 0 ? m_drop_shadow = 0 : m_drop_shadow = 1;
}

short Window::DropShadow( void ) const
{
    return m_drop_shadow;
}

void Window::Title( const char* Text )
{
    if ( strlen( Text ) < max_window_title ) {
        strcpy( m_title, Text );
    }
}

char* Window::Title( void ) const
{
    return (char*)m_title;
}

void Window::TitleJustify( const char Justify )
{
    if ( toupper( Justify ) == 'L' ) {
        m_title_justify = 'L';
    }
    else if ( toupper( Justify ) == 'C' ) {
        m_title_justify = 'C';
    }
    else if ( toupper( Justify ) == 'R' ) {
        m_title_justify = 'R';
    }
}

char Window::TitleJustify( void ) const
{
    return m_title_justify;
}

void Window::Label( const char* Text )
{
    if ( strlen( Text ) < max_window_label ) {
        strcpy( m_label, Text );
    }
}

char* Window::Label( void ) const
{
    return (char*)m_label;
}

void Window::Coords( const unsigned short Top, const unsigned short Left, const unsigned short Bottom, const unsigned short Right )
{
    if ( Top < max_window_rows ) {
        m_top = Top;
    }
    if ( Left < max_window_cols ) {
        m_left = Left;
    }
    if ( Bottom < max_window_rows ) {
        m_bottom = Bottom;
    }
    if ( Right < max_window_cols ) {
        m_right = Right;
    }
}