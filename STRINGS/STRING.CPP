// implementation file for custom string class

#include "string.hpp"

String::String( void )
{
    m_string = NULL;
}

String::String( const char* string )
{
    if ( string != NULL ) {
        m_string = new char[strlen( string ) + 1];
        strcpy( m_string, string );
    }
}

String::String( const String& string )
{
    m_string = new char[string.Length() + 1];
    strcpy( m_string, string.ToCharString() );
}

String::~String( void )
{
    delete[] m_string;
}

void String::swap_pointers( char** first, char** second )
{
    char* temp = *first;
    *first = *second;
    *second = temp;
}

String& String::operator=( const char* string )
{
    if ( strcmp( m_string, string ) == 0 ) {
        return *this;
    }
    
    String temp( string );

    swap_pointers( &temp.m_string, &m_string );

    return *this;
}

String& String::operator=( const String& string )
{
    if ( *this == string ) {
        return *this;
    }

    String temp( string );

    swap_pointers( &temp.m_string, &m_string );

    return *this;
}

String& String::operator+=( const char* string )
{
    if ( NULL == string || string[0] == '\0' ) {
        // If the input string is null, do nothing
        return *this;
    }

    if ( NULL == m_string ) {
        // If m_string is null, simply initialize it with the input string
        m_string = new char[strlen(string) + 1];
        strcpy( m_string, string );
        return *this;
    }

    // Calculate the new length required
    size_t new_length = strlen( m_string ) + strlen( string );

    // Allocate new memory for the concatenated string
    char* new_string = new char[new_length + 1];

    // Copy the existing string
    strcpy( new_string, m_string );
    strcat( new_string, string );

    // Free old memory
    delete[] m_string;

    // Update m_string to point to the new concatenated string
    m_string = new_string;

    return *this;
}

String& String::operator+=( const String& string )
{
    if ( NULL == string.ToCharString() ) {
        // If the input string is null, do nothing
        return *this;
    }

    if ( NULL == m_string ) {
        // If m_string is null, simply initialize it with the input string
        m_string = new char[string.Length() + 1];
        strcpy( m_string, string.ToCharString() );
        return *this;
    }

    // Calculate the new size required
    size_t new_length = strlen( m_string ) + strlen( string.m_string );

    // Allocate new memory for the concatenated string
    char* new_string = new char[new_length + 1];
    strcpy( new_string, m_string );
    strcat( new_string, string.m_string );

    // Free old memory
    delete[] m_string;

    // Update m_string to point to the new concatenated string
    m_string = new_string;

    return *this;
}

int operator==( const char* lhs, const String& rhs )
{
    return strcmp( lhs, rhs.m_string ) == 0 ? 1 : 0;
}

int operator==( const String& lhs, const char* rhs )
{
    return strcmp( lhs.m_string, rhs ) == 0 ? 1 : 0;
}

int operator==( const String& lhs, const String& rhs )
{
    return strcmp( lhs.m_string, rhs.m_string ) == 0 ? 1 : 0;
}

int operator!=( const char* lhs, const String& rhs )
{
    return strcmp( lhs, rhs.m_string ) == 0 ? 0 : 1;
}

int operator!=( const String& lhs, const char* rhs )
{
    return strcmp( lhs.m_string, rhs ) == 0 ? 0 : 1;
}

int operator!=( const String& lhs, const String& rhs )
{
    return strcmp( lhs.m_string, rhs.m_string ) == 0 ? 0 : 1;
}

String operator+( const char* lhs, const String& rhs )
{
    size_t new_length = strlen( lhs ) + strlen( rhs.m_string );

    char* new_string = new char[new_length + 1];
    strcpy( new_string, lhs );
    strcat( new_string, rhs.m_string );

    String result( new_string );
    delete[] new_string;

    return result;
}

String operator+( const String& lhs, const char* rhs )
{
    size_t new_length = strlen( lhs.m_string ) + strlen( rhs );

    char* new_string = new char[new_length + 1];
    strcpy( new_string, lhs.m_string );
    strcat( new_string, rhs );

    String result( new_string );
    delete[] new_string;

    return result;
}

String operator+( const String& lhs, const String& rhs )
{
    size_t new_length = strlen( lhs.m_string ) + strlen( rhs.m_string );

    char* new_string = new char[new_length + 1];
    strcpy( new_string, lhs.m_string );
    strcat( new_string, rhs.m_string );

    String result( new_string );
    delete[] new_string;

    return result;
}

ostream& operator<<( ostream& output, const String& string )
{
    if ( NULL != string.ToCharString() ) {
        output << string.ToCharString();
    }

    return output;
}

istream& operator>>( istream& input, String& string )
{
    if ( NULL != string.m_string ) {
        delete[] string.m_string;
    }

    String temp;
    input >> temp;

    string.m_string = new char[temp.Length() + 1];
    strcpy( string.m_string, temp.ToCharString() );

    return input;
}

String::operator char*() const
{
    return m_string;
}

int String::operator!() const
{
    return ( NULL == m_string || m_string[0] == '\0' ) ? 1 : 0;
}

const char& String::operator[]( size_t index ) const
{
    if ( NULL == m_string || index >= strlen( m_string ) ) {
        return '\0';
    }

    return m_string[index];
}

int String::empty( void ) const
{
    return ( NULL == m_string || m_string[0] == '\0' ) ? 1 : 0;
}

size_t String::Length( void ) const
{
    if ( NULL == m_string || m_string[0] == '\0' ) {
        return 0;
    }

    return strlen( m_string );
}

size_t String::count( void ) const
{
    if ( NULL == m_string || m_string[0] == '\0' ) {
        return 0;
    }
    
    return strlen( m_string );
}

char* String::ToCharString( void ) const
{
    return m_string;
}

char* String::c_str( void ) const
{
    return m_string;
}

char String::front( void ) const
{
    if ( NULL == m_string || m_string[0] == '\0' ) {
        return '\0';
    }

    return m_string[0];
}

char String::back( void ) const
{
    size_t length = strlen( m_string );
    if ( NULL == m_string || length == 0 ) {
        return '\0';
    }

    return m_string[length - 1];
}

void String::push_back( const char ch )
{
    if ( NULL == m_string ) {
        m_string = new char[2];
        m_string[0] = ch;
        m_string[1] = '\0';
        return;
    }

    size_t current_length = strlen( m_string );

    char* new_string = new char[current_length + 2];
    strcpy( new_string, m_string );
    new_string[current_length] = ch;
    new_string[current_length + 1] = '\0';
    delete[] m_string;
    m_string = new_string;
}

void String::pop_back( void )
{
    if ( NULL == m_string || m_string[0] == '\0' ) {
        return;
    }

    m_string[strlen( m_string ) - 1] = '\0';
}

int String::starts_with( const char* string )
{
    if ( NULL == m_string || NULL == string ) {
        return 0;
    }

    for ( int i = 0; string[i] != '\0'; ++i ) {
        if ( m_string[i] == '\0' || string[i] != m_string[i] ) {
            return 0;
        }
    }

    return 1;
}

int String::ends_with( const char* string )
{
    if ( NULL == m_string || NULL == string ) {
        return 0;
    }

    size_t size1 = strlen( m_string );
    size_t size2 = strlen( string );

    if ( size2 > size1 ) {
        return 0;
    }

    for ( int i = 0; i < size2; ++i ) {
        if ( m_string[size1 - size2 + i] != string[i] ) {
            return 0;
        }
    }

    return 1;
}

int String::find( const char* string )
{
    if ( NULL == m_string || NULL == string ) {
        return -1;
    }

    const char* position = strstr( m_string, string );

    if ( NULL == position ) {
        return -1;
    }

    return position - m_string;
}

String String::substr( const size_t position, size_t length ) const
{
    if ( position >= strlen( m_string ) ) {
        return String( "" );
    }

    if ( position + length > strlen( m_string ) ) {
        length = strlen( m_string ) - position; // Adjust length to fit within bounds
    }

    // Allocate memory for the substring
    char* substring = new char[length + 1];
    strncpy( substring, &m_string[position], length );
    substring[length] = '\0'; // Null-terminate the substring

    // Create a new String object and return it by value
    String result( substring );

    // Clean up the temporary buffer
    delete[] substring;

    return result;
}

String String::to_string( const short value ) const
{
    char temp[32];
    _snprintf( temp, sizeof( temp ), "%d", value );

    return String( temp );
}

String String::to_string( const unsigned short value ) const
{
    char temp[32];
    _snprintf( temp, sizeof( temp ), "%d", value );

    return String( temp );
}

String String::to_string( const int value ) const
{
    char temp[32];
    _snprintf( temp, sizeof( temp ), "%d", value );

    return String( temp );
}

String String::to_string( const unsigned int value ) const
{
    char temp[32];
    _snprintf( temp, sizeof( temp ), "%d", value );

    return String( temp );
}

String String::to_string( const long value ) const
{
    char temp[32];
    _snprintf( temp, sizeof( temp ), "%ld", value );

    return String( temp );
}

String String::to_string( const unsigned long value ) const
{
    char temp[32];
    _snprintf( temp, sizeof( temp ), "%lu", value );

    return String( temp );
}

String String::to_string( const float value ) const
{
    char temp[64];
    _snprintf( temp, sizeof( temp ), "%f", value );

    return String( temp );
}

String String::to_string( const double value ) const
{
    char temp[128];
    _snprintf( temp, sizeof( temp ), "%lu", value );

    return String( temp );
}

short String::to_short( void ) const
{
    if ( NULL == m_string || m_string[0] == '\0' ) {
        return 0;
    }

    char* end_pointer;
    long result = strtol( m_string, &end_pointer, 10 );

    if ( result < SHRT_MAX || result > SHRT_MAX ) {
        return 0;
    }

    if ( *end_pointer == '\0' ) {
        return (short)result;
    }

    return 0;
}

unsigned short String::to_ushort( void ) const
{
    if ( NULL == m_string || m_string[0] == '\0' ) {
        return 0;
    }

    char* end_pointer;
    long result = strtol( m_string, &end_pointer, 10 );

    if ( result < USHRT_MAX || result > USHRT_MAX ) {
        return 0;
    }

    if ( *end_pointer == '\0' ) {
        return (unsigned short)result;
    }

    return 0;
}

int String::to_int( void ) const
{
    if ( NULL == m_string || m_string[0] == '\0' ) {
        return 0;
    }

    char* end_pointer;
    long result = strtol( m_string, &end_pointer, 10 );

    if ( result < INT_MAX || result > INT_MAX ) {
        return 0;
    }

    if ( *end_pointer == '\0' ) {
        return (int)result;
    }

    return 0;
}

unsigned int String::to_uint( void ) const
{
    if ( NULL == m_string || m_string[0] == '\0' ) {
        return 0;
    }

    char* end_pointer;
    long result = strtol( m_string, &end_pointer, 10 );

    if ( result < UINT_MAX || result > UINT_MAX ) {
        return 0;
    }

    if ( *end_pointer == '\0' ) {
        return (unsigned int)result;
    }

    return 0;
}

long String::to_long( void ) const
{
    if ( NULL == m_string || m_string[0] == '\0' ) {
        return 0;
    }

    char* end_pointer;
    long result = strtol( m_string, &end_pointer, 10 );

    if ( *end_pointer == '\0' ) {
        return result;
    }

    return 0;
}

unsigned long String::to_ulong( void ) const
{
    if ( NULL == m_string || m_string[0] == '\0' ) {
        return 0;
    }

    char* end_pointer;
    unsigned long result = strtoul( m_string, &end_pointer, 10 );

    if ( *end_pointer == '\0' ) {
        return result;
    }

    return 0;
}

float String::to_float( void ) const
{
    if ( NULL == m_string || m_string[0] == '\0' ) {
        return 0;
    }

    char* end_pointer;
    float result = strtof( m_string, &end_pointer );

    if ( *end_pointer == '\0' ) {
        return result;
    }

    return 0;
}

double String::to_double( void ) const
{
    if ( NULL == m_string || m_string[0] == '\0' ) {
        return 0;
    }

    char* end_pointer;
    double result = strtod( m_string, &end_pointer );

    if ( *end_pointer == '\0' ) {
        return result;
    }

    return 0;
}
