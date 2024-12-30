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
    m_label = new char[m_coordinates.width];
    *m_label = '\0';
    m_drop_shadow = TRUE;
}

FormButton::FormButton( const foreground_colors_t Foreground, const background_colors_t Background )
{
    m_color.foreground = Foreground;
    m_color.background = Background;
    m_coordinates.row = 0;
    m_coordinates.column = 0;
    m_coordinates.height = 5;
    m_coordinates.width = 10;
    m_coordinates.end_row = m_coordinates.row + m_coordinates.height;
    m_coordinates.end_column = m_coordinates.column + m_coordinates.width;
    m_label = new char[m_coordinates.width];
    *m_label = '\0';
    m_drop_shadow = TRUE;
}

FormButton::FormButton( const forms_colors_t Color, const window_coordinates_t Coordinates, char* Label )
{
    m_color = Color;
    m_coordinates = Coordinates;
    m_label = new char[m_coordinates.width - 2];
    m_drop_shadow = TRUE;

    strncpy( m_label, Label, m_coordinates.width - 2 );

    if ( (short)strlen( Label ) > m_coordinates.width - 2 ) {
        m_label[m_coordinates.width - 2] = '\0';
    }
}

FormButton::FormButton( const foreground_colors_t Foreground, const background_colors_t Background, const short Row, const short Column, const short EndRow, const short EndColumn, char* Label )
{
    m_color.foreground = Foreground;
    m_color.background = Background;
    m_coordinates.row = Row;
    m_coordinates.column = Column;
    m_coordinates.end_row = EndRow;
    m_coordinates.end_column = EndColumn;
    m_coordinates.height = m_coordinates.end_row - m_coordinates.row;
    m_coordinates.width = m_coordinates.end_column - m_coordinates.column;
    m_label = new char[m_coordinates.width - 2];
    m_drop_shadow = TRUE;

    strncpy( m_label, Label, m_coordinates.width - 2 );

    if ( (short)strlen( Label ) > m_coordinates.width - 2 ) {
        m_label[m_coordinates.width - 2] = '\0';
    }
}

FormButton::FormButton( const short Row, const short Column, const short EndRow, const short EndColumn, char* Label )
{
    m_color.foreground = FG_BLACK;
    m_color.background = BG_WHITE;
    m_coordinates.row = Row;
    m_coordinates.column = Column;
    m_coordinates.end_row = EndRow;
    m_coordinates.end_column = EndColumn;
    m_coordinates.height = m_coordinates.end_row - m_coordinates.row;
    m_coordinates.width = m_coordinates.end_column - m_coordinates.column;
    m_label = new char[m_coordinates.width];
    m_drop_shadow = TRUE;

    strncpy( m_label, Label, m_coordinates.width - 2 );

    if ( (short)strlen( Label ) > m_coordinates.width - 2 ) {
        m_label[m_coordinates.width - 2] = '\0';
    }
}

FormButton::FormButton( const FormButton& Button )
{
    m_color = Button.Color();
    m_coordinates = Button.Coordinates();
    delete[] m_label;
    m_label = new char[strlen( Button.Label() + 1 )];
    m_drop_shadow = Button.DropShadow();

    strcpy( m_label, Button.Label() );
}

FormButton::~FormButton( void )
{
    delete[] m_label;
}

const FormButton& FormButton::operator=( const FormButton& Button )
{
    if ( this == &Button ) {
        return *this;
    }

    m_color = Button.Color();
    m_coordinates = Button.Coordinates();
    delete[] m_label;
    m_label = new char[strlen( Button.Label() ) + 1];

    strcpy( m_label, Button.Label() );

    return *this;
}

boolean FormButton::operator==( const FormButton& Button )
{
    if ( m_color.foreground != Button.Color().foreground) {
        return FALSE;
    }

    if ( m_color.background != Button.Color().background ) {
        return FALSE;
    }

    if ( m_coordinates.row != Button.Coordinates().row ) {
        return FALSE;
    }

    if ( m_coordinates.column != Button.Coordinates().column ) {
        return FALSE;
    }

    if ( m_coordinates.height != Button.Coordinates().height ) {
        return FALSE;
    }

    if ( m_coordinates.width != Button.Coordinates().width ) {
        return FALSE;
    }

    if ( m_coordinates.end_row != Button.Coordinates().end_row ) {
        return FALSE;
    }

    if ( m_coordinates.end_column != Button.Coordinates().end_column ) {
        return FALSE;
    }

    if ( strcmp( m_label, Button.Label() ) != 0 ) {
        return FALSE;
    }

    if ( m_drop_shadow != Button.DropShadow() ) {
        return FALSE;
    }

    return TRUE;
}

const forms_colors_t FormButton::Color( void ) const
{
    return m_color;
}

const window_coordinates_t FormButton::Coordinates( void ) const
{
    return m_coordinates;
}

const char* FormButton::Label( void ) const
{
    return m_label;
}

boolean FormButton::DropShadow( void ) const
{
    return m_drop_shadow;
}

void FormButton::Color( const forms_colors_t Color )
{
    m_color = Color;
}

void FormButton::Color( const foreground_colors_t Foreground, const background_colors_t Background )
{
    m_color.foreground = Foreground;
    m_color.background = Background;
}

void FormButton::Coordinates( const short Row, const short Column, const short EndRow, const short EndColumn )
{
    m_coordinates.row = Row;
    m_coordinates.column = Column;
    m_coordinates.end_row = EndRow;
    m_coordinates.end_column = EndColumn;
    m_coordinates.height = m_coordinates.end_row - m_coordinates.row;
    m_coordinates.width = m_coordinates.end_column - m_coordinates.column;
}

void FormButton::Coordinates( const window_coordinates_t Coordinates )
{
    m_coordinates = Coordinates;
}

void FormButton::Label( const char* Label )
{
    delete[] m_label;
    m_label = new char[strlen( Label ) + 1];
    strncpy( m_label, Label, m_coordinates.width - 2 );

    if ( (short)strlen( Label ) > m_coordinates.width - 2 ) {
        m_label[m_coordinates.width - 2] = '\0';
    }
}

void FormButton::DropShadow( const boolean DropShadow )
{
    m_drop_shadow = DropShadow;
}