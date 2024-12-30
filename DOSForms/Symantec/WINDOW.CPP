// Window.cpp : class implementation file

#include "window.hpp"

Window::Window( void )
{
    #if defined( _MSC_VER ) || defined( __WATCOMC__ )
    videoconfig vc;
    _getvideoconfig( &vc );
    m_cols_max = vc.numtextcols;
    m_rows_max = vc.numtextrows;
    #elif __SC__
    if ( disp_inited ) {
        m_cols_max = disp_numcols;
        m_rows_max = disp_numrows;
    }
    else {
        disp_open();
        m_cols_max = disp_numcols;
        m_rows_max = disp_numrows;
        disp_close();
    }
    #endif
    Coordinates( 3, 3, m_rows_max - 4, m_cols_max - 4 );
    m_color.foreground = FG_BLUE;
    m_color.background = BG_WHITE;
    m_border_style = BORDER_NONE;
    m_drop_shadow = TRUE; // drop shadow on
    m_title = new char[21];
    *m_title = '\0';
    m_title_justify = 'L';
}

Window::Window( const foreground_colors_t Foreground, const background_colors_t Background )
{
    #if defined( _MSC_VER ) || defined( __WATCOMC__ )
    videoconfig vc;
    _getvideoconfig( &vc );
    m_cols_max = vc.numtextcols;
    m_rows_max = vc.numtextrows;
    #elif __SC__
    if ( disp_inited ) {
        m_cols_max = disp_numcols;
        m_rows_max = disp_numrows;
    }
    else {
        disp_open();
        m_cols_max = disp_numcols;
        m_rows_max = disp_numrows;
        disp_close();
    }
    #endif
    Coordinates( 3, 3, m_rows_max - 4, m_cols_max - 4 );
    m_color.foreground = Foreground;
    m_color.background = Background;
    m_border_style = BORDER_NONE;
    m_drop_shadow = TRUE; // drop shadow on
    m_title = new char[21];
    *m_title = '\0';
    m_title_justify = 'L';
}

Window::Window( const short Row, const short Column, const short EndRow, const short EndColumn )
{
    #if defined( _MSC_VER ) || defined( __WATCOMC__ )
    videoconfig vc;
    _getvideoconfig( &vc );
    m_cols_max = vc.numtextcols;
    m_rows_max = vc.numtextrows;
    #elif __SC__
    if ( disp_inited ) {
        m_cols_max = disp_numcols;
        m_rows_max = disp_numrows;
    }
    else {
        disp_open();
        m_cols_max = disp_numcols;
        m_rows_max = disp_numrows;
        disp_close();
    }
    #endif
    Coordinates( Row, Column, EndRow, EndColumn );
    m_color.foreground = FG_BLUE;
    m_color.background = BG_WHITE;
    m_border_style = BORDER_NONE;
    m_drop_shadow = TRUE; // drop shadow on
    m_title = new char[21];
    *m_title = '\0';
    m_title_justify = 'L';
}

Window::Window( const short Row, const short Column, const short EndRow, const short EndColumn, const foreground_colors_t Foreground, const background_colors_t Background, const window_border_style_t Style )
{
    #if defined( _MSC_VER ) || defined( __WATCOMC__ )
    videoconfig vc;
    _getvideoconfig( &vc );
    m_cols_max = vc.numtextcols;
    m_rows_max = vc.numtextrows;
    #elif __SC__
    if ( disp_inited ) {
        m_cols_max = disp_numcols;
        m_rows_max = disp_numrows;
    }
    else {
        disp_open();
        m_cols_max = disp_numcols;
        m_rows_max = disp_numrows;
        disp_close();
    }
    #endif
    Coordinates( Row, Column, EndRow, EndColumn );
    m_color.foreground = Foreground;
    m_color.background = Background;
    m_border_style = Style;
    m_drop_shadow = TRUE; // drop shadow on
    m_title = new char[21];
    *m_title = '\0';
    m_title_justify = 'L';
}

Window::Window( const short Row, const short Column, const short EndRow, const short EndColumn, const foreground_colors_t Foreground, const background_colors_t Background, const window_border_style_t Style, const char* TitleText )
{
    #if defined( _MSC_VER ) || defined( __WATCOMC__ )
    videoconfig vc;
    _getvideoconfig( &vc );
    m_cols_max = vc.numtextcols;
    m_rows_max = vc.numtextrows;
    #elif __SC__
    if ( disp_inited ) {
        m_cols_max = disp_numcols;
        m_rows_max = disp_numrows;
    }
    else {
        disp_open();
        m_cols_max = disp_numcols;
        m_rows_max = disp_numrows;
        disp_close();
    }
    #endif
    Coordinates( Row, Column, EndRow, EndColumn );
    m_color.foreground = Foreground;
    m_color.background = Background;
    m_border_style = Style;
    m_drop_shadow = TRUE; // drop shadow on
    m_title = new char[21];
    *m_title = '\0';
    m_title_justify = 'L';

    Title( TitleText );
}

Window::~Window( void )
{
	delete[] m_title;
}

// accessors
const window_coordinates_t Window::Coordinates( void ) const
{
    return m_coordinates;
}

const forms_colors_t Window::Color( void ) const
{
    return m_color;
}

const window_border_style_t Window::BorderStyle( void ) const
{
    return m_border_style;
}

boolean Window::DropShadow( void ) const
{
    return m_drop_shadow;
}

const char* Window::Title( void ) const
{
    return m_title;
}

const char Window::TitleJustify( void ) const
{
    return m_title_justify;
}

// mutators
void Window::Coordinates( const window_coordinates_t Coordinates )
{
    m_coordinates = Coordinates;
}

void Window::Coordinates( const short Row, const short Column, const short EndRow, const short EndColumn )
{
    m_coordinates.row = ( Row > 0 && Row < m_rows_max ) ? Row : 1;
    m_coordinates.column = ( Column > 0 && Column < m_cols_max ) ? Column : 1;
    m_coordinates.end_row = ( EndRow > Row && EndRow < m_rows_max ) ? EndRow : m_coordinates.row + 4;
    m_coordinates.end_column = ( EndColumn > Column && EndColumn < m_cols_max ) ? EndColumn : m_coordinates.column + 6;
    m_coordinates.height = m_coordinates.end_row - m_coordinates.row;
    m_coordinates.width = m_coordinates.end_column - m_coordinates.column;
}

void Window::Color( const forms_colors_t Color )
{
    m_color = Color;
}

void Window::Color( const foreground_colors_t Foreground, const background_colors_t Background )
{
    m_color.foreground = Foreground;
    m_color.background = Background;
}

void Window::BorderStyle( const window_border_style_t Style )
{
    m_border_style = Style;
}

void Window::DropShadow( const boolean DropShadow )
{
    m_drop_shadow = DropShadow;
}

void Window::Title( const char* Text )
{
    if ( strlen( Text ) < 21 ) {
        strcpy( m_title, Text );
    }
    else {
    	strncpy( m_title, Text, 21 );
    	m_title[21] = '\0';
    }
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
