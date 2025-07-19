#include "String.hpp"
#include <string.h>
#include <stdlib.h>

#if defined( _M_I86TM ) || defined( __TINY__ )
    #error "Tiny model not supported by this library"
#elif defined( _M_I86SM ) || defined( __SMALL__ )
    #define ALLOC( size ) ( (char far*)malloc( size ) )
    #define DEALLOC( ptr ) free( ptr )

    #define STRLEN( s ) strlen( s )
    #define STRCPY( dst, src ) strcpy( dst, src )
    #define STRCAT( dst, src ) strcat( dst, src )
    #define STRCMP( a, b ) strcmp( a, b )
    #define STRNCMP( a, b, n ) strncmp( a, b, n )
    #define STRSTR( hay, needle ) strstr( hay, needle )
#else
    #define ALLOC( size ) ( (char far*)_fmalloc( size ) )
    #define DEALLOC( ptr ) _ffree( ptr )

    #define STRLEN( s ) _fstrlen( s )
    #define STRCPY( dst, src ) _fstrcpy( dst, src )
    #define STRCAT( dst, src ) _fstrcat( dst, src )
    #define STRCMP( a, b ) _fstrcmp( a, b )
    #define STRNCMP( a, b, n ) _fstrncmp( a, b, n )
    #define STRSTR( hay, needle ) _fstrstr( hay, needle )
#endif

String::String( void ) {
    data = ALLOC( 1 );
    if ( data ) data[0] = '\0';
}

String::String( const char* str ) {
    if ( str ) {
        data = ALLOC( STRLEN( str ) + 1 );
        if ( data ) STRCPY( data, str );
    } else {
        data = ALLOC( 1 );
        if ( data ) data[0] = '\0';
    }
}

String::String( const String& other ) {
    data = ALLOC( STRLEN( other.data ) + 1 );
    if ( data ) STRCPY( data, other.data );
}

String::~String( void ) {
    if ( data ) DEALLOC( data );
}

String& String::operator=( const String& other ) {
    if ( this != &other ) {
        if ( data ) DEALLOC( data );
        data = ALLOC( STRLEN( other.data ) + 1 );
        if ( data ) STRCPY( data, other.data );
    }
    return *this;
}

String& String::operator=( const char* str ) {
    if ( data ) DEALLOC( data );
    if ( str ) {
        data = ALLOC( STRLEN( str ) + 1 );
        if ( data ) STRCPY( data, str );
    } else {
        data = ALLOC( 1 );
        if ( data ) data[0] = '\0';
    }
    return *this;
}

String String::operator+( const String& other ) const {
    size_t len = STRLEN( data ) + STRLEN( other.data );
    char far* buffer = ALLOC( len + 1 );
    if ( buffer ) {
        STRCPY( buffer, data );
        STRCAT( buffer, other.data );
    }
    String result( buffer );
    DEALLOC( buffer );
    return result;
}

String String::operator+( const char* str ) const {
    if ( !str ) return *this;
    size_t len = STRLEN( data ) + STRLEN( str );
    char far* buffer = ALLOC( len + 1 );
    if ( buffer ) {
        STRCPY( buffer, data );
        STRCAT( buffer, str );
    }
    String result( buffer );
    DEALLOC( buffer );
    return result;
}

int String::operator==( const String& other ) const {
    if ( !data || !other.data ) return 0;
    return STRCMP( data, other.data ) == 0 ? 1 : 0;
}

int String::operator==( const char* str ) const {
    if ( !data || !str ) return 0;
    return STRCMP( data, str ) == 0 ? 1 : 0;
}

int String::operator!=( const String& other ) const {
    return !( *this == other );
}

int String::operator!=( const char* str ) const {
    return !( *this == str );
}

int String::StartsWith( const char* prefix ) const {
    if ( !prefix || !data ) return 0;
    size_t lenPrefix = STRLEN( prefix );
    size_t lenData = STRLEN( data );
    if ( lenPrefix > lenData ) return 0;
    return STRNCMP( data, prefix, lenPrefix ) == 0 ? 1 : 0;
}

int String::EndsWith( const char* suffix ) const {
    if ( !suffix || !data ) return 0;
    size_t lenSuffix = STRLEN( suffix );
    size_t lenData = STRLEN( data );
    if ( lenSuffix > lenData ) return 0;
    return STRCMP( data + lenData - lenSuffix, suffix ) == 0 ? 1 : 0;
}

int String::Contains( const char* substring ) const {
    if ( !substring || !data ) return 0;
    return STRSTR( data, substring ) != NULL ? 1 : 0;
}

const char* String::c_str( void ) const {
    return data;
}

const char& String::operator[]( size_t index ) const {
    static char nullChar = '\0';
    if ( !data || index >= STRLEN( data ) ) return nullChar;
    return data[index];
}

size_t String::Length( void ) const {
    return data ? STRLEN( data ) : 0;
}

short String::to_short( void ) const { return (short)atoi( data ); }
unsigned short String::to_ushort( void ) const { return (unsigned short)atoi( data ); }
int String::to_int( void ) const { return atoi( data ); }
unsigned int String::to_uint( void ) const { return (unsigned int)atol( data ); }
long String::to_long( void ) const { return atol( data ); }
unsigned long String::to_ulong( void ) const { return (unsigned long)atol( data ); }
float String::to_float( void ) const { return (float)atof( data ); }
double String::to_double( void ) const { return atof( data ); }

int operator==( const String& lhs, const char* rhs ) { return lhs == rhs; }
int operator==( const char* lhs, const String& rhs ) { return rhs == lhs; }

int operator!=( const String& lhs, const String& rhs ) { return !( lhs == rhs ); }
int operator!=( const String& lhs, const char* rhs ) { return !( lhs == rhs ); }
int operator!=( const char* lhs, const String& rhs ) { return !( lhs == rhs ); }

String operator+( const String& lhs, const char* rhs ) { return lhs + rhs; }

String operator+( const char* lhs, const String& rhs ) {
    if ( !lhs ) return rhs;
    size_t len = STRLEN( lhs ) + STRLEN( rhs.data );
    char far* buffer = ALLOC( len + 1 );
    if ( buffer ) {
        STRCPY( buffer, lhs );
        STRCAT( buffer, rhs.data );
    }
    String result( buffer );
    DEALLOC( buffer );
    return result;
}

ostream& operator<<( ostream& os, const String& str ) {
    if ( str.data ) os << str.data;
    return os;
}

istream& operator>>( istream& is, String& str ) {
    char buffer[256];
    is >> buffer;
    str = buffer;
    return is;
}