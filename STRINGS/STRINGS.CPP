// implementation file for custom string class

#include "string.hpp"

STRING::STRING( void )
{
    m_string = NULL;
}

STRING::STRING( const char* String )
{
    if ( String != NULL ) {
        m_string = new char[strlen( String ) + 1];
        strcpy( m_string, String );
    }
}

STRING::STRING( const STRING& String )
{
    m_string = new char[String.Length() + 1];
    strcpy( m_string, String.ToCharString() );
}

STRING::~STRING( void )
{
    delete[] m_string;
}

void STRING::swap_pointers( char** first, char** second )
{
    char* temp = *first;
    *first = *second;
    *second = temp;
}

STRING& STRING::operator=( const char* String )
{
    STRING temp( String );

    swap_pointers( &temp.m_string, &m_string );

    return *this;
}

STRING& STRING::operator=( const STRING& String )
{
    STRING temp( String );

    swap_pointers( &temp.m_string, &m_string );

    return *this;
}

int STRING::operator==( const char* String )
{
    return strcmp( m_string, String ) == 0 ? 1 : 0;
}

int STRING::operator==( const STRING& String )
{
    return strcmp( m_string, String.ToCharString() ) == 0 ? 1 : 0;
}

STRING& STRING::operator+( const char* String )
{
    STRING temp( m_string );

    swap_pointers( &temp.m_string, &m_string );

    delete[] m_string;
    m_string = new char[strlen( temp.m_string ) + strlen( String ) + 1];
    strcpy( m_string, temp.m_string );
    strcat( m_string, String );

    return *this;
}

STRING& STRING::operator+( const STRING& String )
{
    STRING temp( m_string );

    swap_pointers( &temp.m_string, &m_string );

    delete[] m_string;
    m_string = new char[strlen( temp.m_string ) + String.Length() + 1];
    strcpy( m_string, temp.m_string );
    strcat( m_string, String.ToCharString() );

    return *this;
}

STRING& STRING::operator+=( const char* String )
{
    STRING temp( m_string );

    swap_pointers( &temp.m_string, &m_string );

    delete[] m_string;
    m_string = new char[strlen( temp.m_string ) + strlen( String ) + 1];
    strcpy( m_string, temp.m_string );
    strcat( m_string, String );

    return *this;
}

STRING& STRING::operator+=( const STRING& String )
{
    STRING temp( m_string );

    swap_pointers( &temp.m_string, &m_string );

    delete[] m_string;
    m_string = new char[strlen( temp.m_string ) + String.Length() + 1];
    strcpy( m_string, temp.m_string );
    strcat( m_string, String.ToCharString() );

    return *this;
}

STRING::operator char*() const
{
    return m_string;
}

unsigned int STRING::Length( void ) const
{
    return strlen( m_string );
}

char* STRING::ToCharString( void ) const
{
    return m_string;
}

void STRING::Clear( void )
{
    memset( m_string, '\0', strlen( m_string ) + 1 );
}

char& STRING::FirstChar( void )
{
    return m_string[0];
}

char& STRING::LastChar( void )
{
    return m_string[strlen( m_string ) - 1];
}

STRING& STRING::SubString( const unsigned int position, unsigned int length )
{
    if ( position > strlen( m_string ) ) {
        return *this;
    }

    if ( length > strlen( m_string ) ) {
        length = strlen( m_string );
    }

    STRING temp( m_string );

    swap_pointers( &temp.m_string, &m_string );

    delete[] m_string;
    m_string = new char[length + 1];
    strncpy( m_string, &temp.m_string[position], length );
    m_string[length] = '\0';

    return *this;
}

STRING& STRING::Insert( const int position, const char* String )
{
    STRING temp( m_string );

    swap_pointers( &temp.m_string, &m_string );

    delete[] m_string;
    m_string = new char[strlen( temp.m_string ) + strlen( String ) + 1];

    if ( position == 0 ) {
        strcpy( m_string, String );
        strcat( m_string, temp.m_string );
    }
    else if ( position < strlen( temp.m_string ) ) {
        strncpy( m_string, temp.m_string, position );
        strcat( m_string, String );
        strncat( m_string, &temp.m_string[position], strlen( temp.m_string ) - position );
    }
    else if ( position >= strlen( temp.m_string ) ) {
        strcpy( m_string, temp.m_string );
        strcat( m_string, String );
    }

    return *this;
}

STRING& STRING::Insert( const int position, const STRING& String )
{
    STRING temp( m_string );

    swap_pointers( &temp.m_string, &m_string );

    delete[] m_string;
    m_string = new char[strlen( temp.m_string ) + String.Length() + 1];

    if ( position == 0 ) {
        strcpy( m_string, String.ToCharString() );
        strcat( m_string, temp.m_string );
    }
    else if ( position < strlen( temp.m_string ) ) {
        strncpy( m_string, temp.m_string, position );
        strcat( m_string, String.ToCharString() );
        strncat( m_string, &temp.m_string[position], strlen( temp.m_string ) - position );
    }
    else if ( position >= strlen( temp.m_string ) ) {
        strcpy( m_string, temp.m_string );
        strcat( m_string, String.ToCharString() );
    }

    return *this;
}

STRING& STRING::Remove( const int position, unsigned int length )
{
    if ( position >= strlen( m_string ) ) {
        return *this;
    }

    if ( length > strlen( m_string ) ) {
        length = strlen( m_string );
    }

    STRING temp( m_string );

    swap_pointers( &temp.m_string, &m_string );

    delete[] m_string;
    m_string = new char[strlen( temp.m_string ) - position - length + 1];

    if ( position == 0 ) {
        strncpy( m_string, &temp.m_string[position], strlen( temp.m_string ) - position - length );
    }
    else {
        strncpy( m_string, temp.m_string, position );
        strncat( m_string, &temp.m_string[length], strlen( temp.m_string ) - position - length );
    }

    m_string[strlen( m_string )] = '\0';

    return *this;
}
