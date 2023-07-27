// STRING.H class definition file

#pragma warning( disable : 4091 )

#ifndef MYSTRING_H
#define MYSTRING_H

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
    STRING* Set( const char *String );
    STRING* Set( const STRING *String );
    STRING Set( const STRING String );
    STRING* set( const char *String );
    STRING* set( const STRING *String );
    STRING set( const STRING String );
    STRING* Get( void ) const;
    STRING* get( void ) const;
    char* GetCharString( void ) const;
    char* getcharstring( void ) const;
    STRING* Concat( const char *String );
    STRING* Concat( const STRING *String );
    STRING Concat( const STRING String );
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
    unsigned int Length( void ) const;
    unsigned int Count( void ) const;
    unsigned int length( void ) const;
    unsigned int count( void ) const;

    // operator overloads
    STRING& operator=( const STRING& String );
    STRING* operator=( const STRING *String );
    STRING* operator=( const char *String );
    STRING operator=( const STRING String );
    STRING& operator+( const STRING& String );
    STRING* operator+( const STRING *String );
    STRING* operator+( const char *String );
    STRING operator+( const STRING String );
    BOOL operator==( const STRING& String );
    BOOL operator==( const STRING *String );
    BOOL operator==( const char *String );
    BOOL operator==( const STRING String );
    BOOL operator!=( const STRING& String );
    BOOL operator!=( const STRING *String );
    BOOL operator!=( const char *String );
    BOOL operator!=( const STRING String );
};

#endif // end MYSTRING_H
//#endif

#pragma warning( default : 4091 )
