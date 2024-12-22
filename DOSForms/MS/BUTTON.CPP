// BUTTON.CPP : DOSForms button implementation file

#include "button.hpp"

FormButton::FormButton( void )
{
    m_color.foreground = FG_BLACK;
    m_color.background = BG_WHITE;
    m_coordinates.row = 0;
    m_coordinates.column = 0;
    m_coordinates.height = 5;
    m_coordinates.width = 10;
    m_coordinates.end_row = m_coordinates.row + m_coordinates.height;
    m_coordinates.end_column = m_coordinates.column + m_coordinates.width;
    *m_label = NULL;
}

FormButton::FormButton( const forms_colors_t color, const window_coordinates_t coordinates, char* label )
{
    m_color = color;
    m_coordinates = coordinates;
    m_label = new char[m_coordinates.width - 2];

    strncpy( m_label, label, m_coordinates.width - 2 );

    if ( strlen( label ) > m_coordinates.width - 2 ) {
        m_label[m_coordinates.width - 2] = '\0';
    }
}

FormButton::FormButton( const foreground_colors_t foreground, const background_colors_t background, const short row, const short column, const short height, const short width, char* label )
{
    m_color.foreground = foreground;
    m_color.background = background;
    m_coordinates.row = row;
    m_coordinates.column = column;
    m_coordinates.height = height;
    m_coordinates.width = width;
    m_coordinates.end_row = row + height - 1;
    m_coordinates.end_column = column + width - 1;
    m_label = new char[m_coordinates.width - 2];

    strncpy( m_label, label, m_coordinates.width - 2 );

    if ( strlen( label ) > m_coordinates.width - 2 ) {
        m_label[m_coordinates.width - 2] = '\0';
    }
}

FormButton::FormButton( const FormButton& button )
{
    m_color = button.Color();
    m_coordinates = button.Coordinates();
    delete[] m_label;
    m_label = new char[strlen( button.Label() + 1 )];

    strcpy( m_label, button.Label() );
}

FormButton::~FormButton( void )
{
    delete[] m_label;
}

FormButton& FormButton::operator=( const FormButton& button )
{
    if ( this == &button ) {
        return *this;
    }

    m_color = button.Color();
    m_coordinates = button.Coordinates();
    delete[] m_label;
    m_label = new char[strlen( button.Label() ) + 1];

    strcpy( m_label, button.Label() );

    return *this;
}

boolean FormButton::operator==( const FormButton& button )
{
    if ( m_color.foreground != button.Color().foreground) {
        return FALSE;
    }

    if ( m_color.background != button.Color().background ) {
        return FALSE;
    }

    if ( m_coordinates.row != button.Coordinates().row ) {
        return FALSE;
    }

    if ( m_coordinates.column != button.Coordinates().column ) {
        return FALSE;
    }

    if ( m_coordinates.height != button.Coordinates().height ) {
        return FALSE;
    }

    if ( m_coordinates.width != button.Coordinates().width ) {
        return FALSE;
    }

    if ( m_coordinates.end_row != button.Coordinates().end_row ) {
        return FALSE;
    }

    if ( m_coordinates.end_column != button.Coordinates().end_column ) {
        return FALSE;
    }

    if ( strcmp( m_label, button.Label() ) != 0 ) {
        return FALSE;
    }

    return TRUE;
}

forms_colors_t FormButton::Color( void ) const
{
    return m_color;
}

window_coordinates_t FormButton::Coordinates( void ) const
{
    return m_coordinates;
}

char* FormButton::Label( void ) const
{
    return m_label;
}

void FormButton::Color( const forms_colors_t color )
{
    m_color = color;
}

void FormButton::Color( const foreground_colors_t foreground, const background_colors_t background )
{
    m_color.foreground = foreground;
    m_color.background = background;
}

void FormButton::Coordinates( const short start_x, const short start_y, const short end_x, const short end_y )
{
    m_coordinates.row = start_y;
    m_coordinates.column = start_x;
    m_coordinates.end_row = end_y;
    m_coordinates.end_column = end_x;
    m_coordinates.height = m_coordinates.end_row - m_coordinates.row;
    m_coordinates.width = m_coordinates.end_column - m_coordinates.column;
}

void FormButton::Coordinates( const window_coordinates_t coordinates )
{
    m_coordinates = coordinates;
}

void FormButton::Label( const char* label )
{
    delete[] m_label;
    m_label = new char[strlen( label ) + 1];
    strncpy( m_label, label, m_coordinates.width - 2 );

    if ( strlen( label ) > m_coordinates.width - 2 ) {
        m_label[m_coordinates.width - 2] = '\0';
    }
}
