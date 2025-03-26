// class definition file for custom string class

#ifndef STRING_HPP
#define STRING_HPP 1

#include <stdlib.h>         // NULL, strtol, strtoul, strtof, strtod
#include <stdio.h>          // sprintf, _snprintf
#include <string.h>         // strlen, strcpy, strcmp, strcat
#include <iostream.h>       // operator<<, operator>>
#include <limits.h>         // for integral limits

class String
{
    char* m_string;

    void swap_pointers( char** first, char** second );

public:
    String( void );
    String( const char* string );
    String( const String& string );
    ~String( void );

    // operator overloads
    String& operator=( const char* string );
    String& operator=( const String& string );
    String& operator+=( const char* string );
    String& operator+=( const String& string );
    friend int operator==( const char* lhs, const String& rhs );
    friend int operator==( const String& lhs, const char* rhs );
    friend int operator==( const String& lhs, const String& rhs );
    friend int operator!=( const char* lhs, const String& rhs );
    friend int operator!=( const String& lhs, const char* rhs );
    friend int operator!=( const String& lhs, const String& rhs );
    friend String operator+( const char* lhs, const String& rhs );
    friend String operator+( const String& lhs, const char* rhs );
    friend String operator+( const String& lhs, const String& rhs );
    friend ostream& operator<<( ostream& output, const String& string );
    friend istream& operator>>( istream& input, String& string );
    operator char*() const;
    int operator!() const;
    const char& operator[]( size_t index ) const;

    // methods
    int empty( void ) const;
    size_t Length( void ) const;
    size_t count( void ) const;
    char* ToCharString( void ) const;
    char* c_str( void ) const;
    char front( void ) const;
    char back( void ) const;
    void push_back( const char ch );
    void pop_back( void );
    int starts_with( const char* string );
    int ends_with( const char* string );
    int find( const char* string );
    String substr( const size_t position, size_t length ) const;
    String to_string( const short value ) const;
    String to_string( const unsigned short value ) const;
    String to_string( const int value ) const;
    String to_string( const unsigned int value ) const;
    String to_string( const long value ) const;
    String to_string( const unsigned long value ) const;
    String to_string( const float value ) const;
    String to_string( const double value ) const;
    short to_short( void ) const;
    unsigned short to_ushort( void ) const;
    int to_int( void ) const;
    unsigned int to_uint( void ) const;
    long to_long( void ) const;
    unsigned long to_ulong( void ) const;
    float to_float( void ) const;
    double to_double( void ) const;
};

#endif
