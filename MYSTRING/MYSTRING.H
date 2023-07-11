// STRING.H class defintiion file

#if __DMC__ || __SC__ || __RCC__
#ifndef MYSTRING_H
#define MYSTRING_H 1

#include <stdlib.h>
#include <string.h>

#ifndef BOOL
typedef int BOOL;
#endif
#ifndef FALSE
#define FALSE 0
#endif
#ifndef TRUE
#define TRUE !FALSE
#endif

class STRING
{
    char* _string;

  public:
    STRING( void );
    STRING( char *String );
    STRING( STRING *String );
    ~STRING( void );

    // accessors and mutators
    STRING* set( const char *String );
    STRING* set( const STRING *String );
    STRING set( const STRING String );
    STRING* get( void ) const;
    char* getcharstring( void ) const;
    STRING* concat( const char *String );
    STRING* concat( const STRING *String );
    STRING concat( const STRING String );

    // methods
    BOOL IsEqual( const char *String );
    BOOL IsEqual( const STRING *String );
    BOOL IsEqual( const STRING String );
    BOOL isequal( const char *String );
    BOOL isequal( const STRING *String );
    BOOL isequal( const STRING String );
    unsigned int length( void ) const;
    unsigned int count( void ) const;

  protected:
    STRING* operator=( const STRING *String );
    STRING* operator=( const char *String );
    STRING* operator+( const STRING *String );
    STRING* operator+( const char *String );
    BOOL operator==( const STRING *String );
    BOOL operator==( const char *String );
};

#endif // end MYSTRING_H
#endif