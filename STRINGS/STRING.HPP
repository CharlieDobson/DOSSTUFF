#ifndef STRING_HPP
#define STRING_HPP

#include <iostream.h>

class String {
private:
    char far* data;

public:
    // Constructors & Destructor
    String( void );
    String( const char* str );
    String( const String& other );
    ~String( void );

    // Assignment
    String& operator=( const String& other );
    String& operator=( const char* str );

    // Concatenation
    String operator+( const String& other ) const;
    String operator+( const char* str ) const;

    // Comparison
    int operator==( const String& other ) const;
    int operator==( const char* str ) const;
    int operator!=( const String& other ) const;
    int operator!=( const char* str ) const;

    // Access & Info
    const char* c_str( void ) const;
    const char& operator[]( size_t index ) const;
    size_t Length( void ) const;

    // Search
    int StartsWith( const char* prefix ) const;
    int EndsWith( const char* suffix ) const;
    int Contains( const char* substring ) const;

    // Conversion
    short to_short( void ) const;
    unsigned short to_ushort( void ) const;
    int to_int( void ) const;
    unsigned int to_uint( void ) const;
    long to_long( void ) const;
    unsigned long to_ulong( void ) const;
    float to_float( void ) const;
    double to_double( void ) const;

    // Friend functions
    friend int operator==( const char* lhs, const String& rhs );
    friend int operator!=( const char* lhs, const String& rhs );
    friend String operator+( const char* lhs, const String& rhs );
    friend ostream& operator<<( ostream& os, const String& str );
    friend istream& operator>>( istream& is, String& str );
};

#endif