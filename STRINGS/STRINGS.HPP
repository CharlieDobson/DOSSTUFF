// class definition file for custom string class

#ifndef STRING_HPP
#define STRING_HPP 1

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <memory.h>

class STRING

{
    char* m_string;

    void swap_pointers( char** first, char** second );

public:
    STRING( void );
    STRING( const char* String );
    STRING( const STRING& String );
    ~STRING( void );

    STRING& operator=( const char* String );
    STRING& operator=( const STRING& String );
    int operator==( const char* String );
    int operator==( const STRING& String );
    STRING& operator+( const char* String );
    STRING& operator+( const STRING& String );
    STRING& operator+=( const char* String );
    STRING& operator+=( const STRING& String );
    operator char*() const;

    unsigned int Length( void ) const;
    char* ToCharString( void ) const;
    void Clear( void );
    char& FirstChar( void );
    char& LastChar( void );
    STRING& SubString( const unsigned int position, unsigned int length );
    STRING& Insert( const int position, const char* String );
    STRING& Insert( const int position, const STRING& String );
    STRING& Remove( const int position, unsigned int length );
};

#endif
