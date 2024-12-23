// MESSAGE.CPP : DOSForms message window implementation file

#include "message.hpp"

FormMessage::FormMessage( const forms_colors_t color, const window_coordinates_t coordinates, const char* title, const char* message, const dialog_buttons_t buttons )
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

FormMessage::FormMessage( const foreground_colors_t foreground, const background_colors_t background, const short row, const short column, const short height, const short width, const char* title, const char* message, const dialog_buttons_t buttons )
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

FormMessage::FormMessage( const FormMessage& formMessage )
{
    m_color = formMessage.color();
    m_coordinates = formMessage.coordinates();
    m_title = new char[strlen( formMessage.title() + 1 )];
    m_message = new char[strlen( formMessage.message() + 1 )];
    m_buttons = formMessage.buttons();

    strcpy( m_title, formMessage.title() );
    strcpy( m_message, formMessage.message() );
}

FormMessage::~FormMessage( void )
{
    delete[] m_message;
    delete[] m_title;
}

FormMessage& FormMessage::operator=( const FormMessage& formMessage )
{
    if ( this == &formMessage ) {
        return *this;
    }

    m_color = formMessage.color();
    m_coordinates = formMessage.coordinates();
    delete[] m_title;
    m_title = new char[strlen( formMessage.title() ) + 1];
    delete[] m_message;
    m_message = new char[strlen( formMessage.message() ) + 1];
    m_buttons = formMessage.buttons();

    strcpy( m_title, formMessage.title() );
    strcpy( m_message, formMessage.message() );

    return *this;
}

boolean FormMessage::operator==( const FormMessage& formMessage )
{
    if ( m_color.foreground != formMessage.color().foreground ) {
        return FALSE;
    }

    if ( m_color.background != formMessage.color().background ) {
        return FALSE;
    }

    if ( m_coordinates.row != formMessage.coordinates().row ) {
        return FALSE;
    }

    if ( m_coordinates.column != formMessage.coordinates().column ) {
        return FALSE;
    }

    if ( m_coordinates.height != formMessage.coordinates().height ) {
        return FALSE;
    }

    if ( m_coordinates.width != formMessage.coordinates().width ) {
        return FALSE;
    }

    if ( m_coordinates.end_row != formMessage.coordinates().end_row ) {
        return FALSE;
    }

    if ( m_coordinates.end_column != formMessage.coordinates().end_column ) {
        return FALSE;
    }

    if ( strcmp( m_title, formMessage.title() ) != 0 ) {
        return FALSE;
    }

    if ( strcmp( m_message, formMessage.message() ) != 0 ) {
        return FALSE;
    }

    if ( m_buttons != formMessage.buttons() ) {
        return FALSE;
    }

    return TRUE;
}

forms_colors_t FormMessage::color( void ) const
{
    return m_color;
}

window_coordinates_t FormMessage::coordinates( void ) const
{
    return m_coordinates;
}

char* FormMessage::title( void ) const
{
    return m_title;
}

char* FormMessage::message( void ) const
{
    return m_message;
}

dialog_buttons_t FormMessage::buttons( void ) const
{
    return m_buttons;
}

void FormMessage::color( const forms_colors_t color )
{
    if ( color.foreground != FG_NO_COLOR || color.background != BG_NO_COLOR ) {
        m_color = color;
    }
}

void FormMessage::color( const foreground_colors_t foreground, const background_colors_t background )
{
    if ( foreground != FG_NO_COLOR ) {
        m_color.foreground = foreground;
    }

    if ( background != BG_NO_COLOR ) {
        m_color.background = background;
    }
}

void FormMessage::coordinates( const window_coordinates_t coordinates )
{
    m_coordinates = coordinates;
}

void FormMessage::coordinates( const short row, const short column, const short height, const short width )
{
    m_coordinates.row = row;
    m_coordinates.column = column;
    m_coordinates.height = height;
    m_coordinates.width = width;
    m_coordinates.end_row = row + height - 1;
    m_coordinates.end_column = column + width - 1;
}

void FormMessage::title( const char* title )
{
    strncpy( m_title, title, m_coordinates.width / 2 );

    if ( strlen( title ) > m_coordinates.width / 2 ) {
        m_title[m_coordinates.width / 2] = '\0';
    }
}

void FormMessage::message( const char* message )
{
    strncpy( m_message, message, 200 );

    if ( strlen( message ) > 200 ) {
        m_message[200] = '\0';
    }
}

void FormMessage::buttons( const dialog_buttons_t buttons )
{
    m_buttons = buttons;
}
