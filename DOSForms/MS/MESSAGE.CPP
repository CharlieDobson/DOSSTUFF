// MESSAGE.CPP : DOSForms message window implementation file

#include "message.hpp"

FormMessageWindow::FormMessageWindow( const forms_colors_t color, const window_coordinates_t coordinates, const char* title, const char* message, const dialog_buttons_t buttons )
{
    m_color = color;
    m_coordinates = coordinates;
    m_title = new char[m_coordinates.width / 2];
    m_message = new char[200];
    m_buttons = buttons;

    strncpy( m_title, title, m_coordinates.width / 2);

    if ( strlen( title ) > m_coordinates.width / 2 ) {
        m_title[m_coordinates.width / 2] = '\0';
    }

    strncpy( m_message, message, 200 );

    if ( strlen( message ) > 200 ) {
        m_message[200] = '\0';
    }
}

FormMessageWindow::FormMessageWindow( const foreground_colors_t foreground, const background_colors_t background, const short row, const short column, const short height, const short width, const char* title, const char* message, const dialog_buttons_t buttons )
{
    m_color.foreground = foreground;
    m_color.background = background;
    m_coordinates.row = row;
    m_coordinates.column = column;
    m_coordinates.height = height;
    m_coordinates.width = width;
    m_coordinates.end_row = row + height - 1;
    m_coordinates.end_column = column + width - 1;
    m_title = new char[m_coordinates.width / 2];
    m_message = new char[200];
    m_buttons = buttons;

    strncpy( m_title, title, m_coordinates.width / 2 );

    if ( strlen( title ) > m_coordinates.width / 2 ) {
        m_title[m_coordinates.width / 2] = '\0';
    }

    strncpy( m_message, message, 200 );

    if ( strlen( message ) > 200 ) {
        m_message[200] = '\0';
    }
}

FormMessageWindow::FormMessageWindow( const FormButton& messageWindow )
{
    m_color = messageWindow.color();
    m_coordinates = messageWindow.coordinates();
    m_title = new char[strlen( messageWindow.title() + 1 )];
    m_message = new char[strlen( messageWindow.message() + 1 )];
    m_buttons = messageWindow.buttons();

    strcpy( m_title, messageWindow.title() );
    strcpy( m_message, messageWindow.message() );
}

FormMessageWindow::~FormMessageWindow( void )
{
    delete[] m_message;
    delete[] m_title;
}

FormMessageWindow& FormMessageWindow::operator=( const FormMessageWindow& messageWindow )
{
    if ( this == &messageWindow ) {
        return *this;
    }

    m_color = messageWindow.color();
    m_coordinates = messageWindow.coordinates();
    delete[] m_title;
    m_title = new char[strlen( messageWindow.title() ) + 1];
    delete[] m_message;
    m_message = new char[strlen( messageWindow.message() ) + 1];
    m_buttons = messageWindow.buttons();

    strcpy( m_label, messageWindow.title() );
    strcpy( m_message, messageWindow.message() );

    return *this;
}

boolean FormMessageWindow::operator==( const FormMessageWindow& messageWindow )
{
    if ( m_color.foreground != messageWindow.color().foreground ) {
        return FALSE;
    }

    if ( m_color.background != messageWindow.color().background ) {
        return FALSE;
    }

    if ( m_coordinates.row != messageWindow.coordinates().row ) {
        return FALSE;
    }

    if ( m_coordinates.column != messageWindow.coordinates().column ) {
        return FALSE;
    }

    if ( m_coordinates.height != messageWindow.coordinates().height ) {
        return FALSE;
    }

    if ( m_coordinates.width != messageWindow.coordinates().width ) {
        return FALSE;
    }

    if ( m_coordinates.end_row != messageWindow.coordinates().end_row ) {
        return FALSE;
    }

    if ( m_coordinates.end_column != messageWindow.coordinates().end_column ) {
        return FALSE;
    }

    if ( strcmp( m_title, messageWindow.title() ) != 0 ) {
        return FALSE;
    }

    if ( strcmp( m_message, messageWindow.message() ) != 0 ) {
        return FALSE;
    }

    if ( m_buttons != messageWindow.buttons ) {
        return FALSE;
    }

    return TRUE;
}

forms_colors_t FormMessageWindow::color( void ) const
{
    return m_color;
}

window_coordinates_t FormMessageWindow::coordinates( void ) const
{
    return m_coordinates;
}

char* FormMessageWindow::title( void ) const
{
    return m_title;
}

char* FormMessageWindow::message( void ) const
{
    return m_message;
}

dialog_buttons_t FormMessageWindow::buttons( void ) const
{
    return m_buttons;
}

void FormMessageWindow::color( const forms_colors_t color )
{
    m_color = color;
}

void FormMessageWindow::coordinates( const window_coordinates_t coordinates )
{
    m_coordinates = coordinates;
}

void FormMessageWindow::title( const char* title )
{
    strncpy( m_title, title, m_coordinates.width / 2 );

    if ( strlen( title ) > m_coordinates.width / 2 ) {
        m_title[m_coordinates.width / 2] = '\0';
    }
}

void FormMessageWindow::message( const char* message )
{
    strncpy( m_message, message, 200 );

    if ( strlen( message ) > 200 ) {
        m_message[200] = '\0';
    }
}

void FormMessageWindow::buttons( const dialog_buttons_t buttons )
{
    m_buttons = buttons;
}
