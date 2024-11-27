// BUTTON.CPP : DOSForms button implementation file

#include "button.hpp"

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

FormButton::FormButton( const foreground_colors_t foreground, const background_colors_t background, const short column, const short row, const short width, const short height, char* label )
{
    m_color.foreground = foreground;
    m_color.background = background;
    m_coordinates.column = column;
    m_coordinates.row = row;
    m_coordinates.width = width;
    m_coordinates.height = height;
    m_coordinates.end_column = column + width;
    m_coordinates.end_row = row + height;
    m_label = new char[m_coordinates.width - 2];

    strncpy( m_label, label, m_coordinates.width - 2 );

    if ( strlen( label ) > m_coordinates.width - 2 ) {
        m_label[m_coordinates.width - 2] = '\0';
    }
}

FormButton::FormButton( const FormButton& button )
{
    m_color = button.color();
    m_coordinates = button.coordinates();
    m_label = new char[strlen( button.label() + 1 )];

    strcpy( m_label, button.label() );
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

    m_color = button.color();
    m_coordinates = button.coordinates();
    delete[] m_label;
    m_label = new char[strlen( button.label() ) + 1];

    strcpy( m_label, button.label() );

    return *this;
}

int FormButton::operator==( const FormButton& button )
{
    if ( m_color.foreground != button.color().foreground) {
        return 0;
    }

    if ( m_color.background != button.color().background ) {
        return 0;
    }

    if ( m_coordinates.column != button.coordinates().column ) {
        return 0;
    }

    if ( m_coordinates.row != button.coordinates().row ) {
        return 0;
    }

    if ( m_coordinates.width != button.coordinates().width ) {
        return 0;
    }

    if ( m_coordinates.height != button.coordinates().height ) {
        return 0;
    }

    if ( m_coordinates.end_column != button.coordinates().end_column ) {
        return 0;
    }

    if ( m_coordinates.end_row != button.coordinates().end_row ) {
        return 0;
    }

    if ( strcmp( m_label, button.label() ) != 0 ) {
        return 0;
    }

    return 1;
}

forms_colors_t FormButton::color( void ) const
{
    return m_color;
}

window_coordinates_t FormButton::coordinates( void ) const
{
    return m_coordinates;
}

char* FormButton::label( void ) const
{
    return m_label;
}

void FormButton::color( const forms_colors_t color )
{
    m_color = color;
}

void FormButton::coordinates( const window_coordinates_t coordinates )
{
    m_coordinates = coordinates;
}

void FormButton::label( const char* label )
{
    strncpy( m_label, label, m_coordinates.width - 2 );

    if ( strlen( label ) > m_coordinates.width - 2 ) {
        m_label[m_coordinates.width - 2] = '\0';
    }
}
