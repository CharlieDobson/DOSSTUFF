// MYSTRING.CPP class implementation file

#include "mystring.h"

STRING::STRING( void )
{
    _string = NULL;
}

STRING::STRING( char *String )
{
    set( String );
}

STRING::STRING( STRING *String )
{
    set( String );
}

STRING::~STRING( void )
{
    if ( _string != NULL )
        free( _string );
}

STRING* STRING::Set( const char *String )
{
    if ( _string == NULL )
        _string = (char*)malloc( strlen( String ) + 1 );
    else
        _string = (char*)realloc( _string, strlen( String ) + 1 );

    if ( _string != NULL )
        strcpy( _string, String );
    return (STRING*)_string;
}

STRING* STRING::Set( const STRING *String )
{
    if ( _string == NULL )
        _string = (char*)malloc( String->length() + 1 );
    else
        _string = (char*)realloc( _string, String->length() + 1 );

    if ( _string != NULL )
        strcpy( _string, (char*)String );
    return (STRING*)_string;
}

STRING STRING::Set( const STRING String )
{
    if ( _string == NULL )
        _string = (char*)malloc( String.length() + 1 );
    else
        _string = (char*)realloc( _string, String.length() + 1 );

    if ( _string != NULL )
        strcpy( _string, String.GetCharString() );
    return (STRING)_string;
}

STRING* STRING::set( const char *String )
{
	return Set( String );
}

STRING* STRING::set( const STRING *String )
{
	return Set( String );
}

STRING STRING::set( const STRING String )
{
	return Set( String );
}

STRING* STRING::Get( void ) const
{
	return (STRING*)_string;
}

STRING* STRING::get( void ) const
{
    return (STRING*)_string;
}

char* STRING::getcharstring( void ) const
{
    return _string;
}

char* STRING::GetCharString( void ) const
{
	return _string;
}

STRING* STRING::Concat( const char *String )
{
    if ( _string == NULL )
        return set( String );

    _string = (char*)realloc( _string, strlen( _string ) + strlen( String ) + 1 );
    if ( _string != NULL )
        strcat( _string, String );
    return (STRING*)_string;
}

STRING* STRING::Concat( const STRING *String )
{
    if ( _string == NULL )
        return set( String );

    _string = (char*)realloc( _string, strlen( _string ) + String->length() + 1 );
    if ( _string != NULL )
        strcat( _string, (char*)String );
    return (STRING*)_string;
}

STRING STRING::Concat( const STRING String )
{
    if ( _string == NULL )
        return set( String );

    _string = (char*)realloc( _string, strlen( _string ) + String.length() + 1 );
    if ( _string != NULL )
        strcat( _string, String.GetCharString() );
    return (STRING)_string;
}

STRING* STRING::concat( const char *String )
{
	return Concat( String );
}

STRING* STRING::concat( const STRING *String )
{
	return Concat( String );
}

STRING STRING::concat( const STRING String )
{
	return Concat( String );
}

BOOL STRING::IsEqual( const char *String )
{
    return strcmp( _string, String ) == 0 ? TRUE : FALSE;
}

BOOL STRING::IsEqual( const STRING *String )
{
    return strcmp( _string, (char*)String ) == 0 ? TRUE : FALSE;
}

BOOL STRING::IsEqual( const STRING String )
{
    return strcmp( _string, String.getcharstring() ) == 0 ? TRUE : FALSE;
}

BOOL STRING::isequal( const char *String )
{
    return IsEqual( String );
}

BOOL STRING::isequal( const STRING *String )
{
    return IsEqual( String );
}

BOOL STRING::isequal( const STRING String )
{
    return IsEqual( String );
}

unsigned int STRING::Length( void ) const
{
	return strlen( _string );
}

unsigned int STRING::Count( void ) const
{
	return Length();
}

unsigned int STRING::length( void ) const
{
    return Length();
}

unsigned int STRING::count( void ) const
{
    return Length();
}

STRING& STRING::operator=( const STRING& String )
{
    return Set( String );
}

STRING* STRING::operator=( const STRING *String )
{
    return Set( String );
}

STRING* STRING::operator=( const char *String )
{
    return Set( String );
}

STRING STRING::operator=( const STRING String )
{
    return Set( String );
}

STRING& STRING::operator+( const STRING& String )
{
    return Concat( String );
}

STRING* STRING::operator+( const STRING *String )
{
    return concat( String );
}

STRING* STRING::operator+( const char *String )
{
    return concat( String );
}

STRING STRING::operator+( const STRING String )
{
    return concat( String );
}

BOOL STRING::operator==( const STRING *String )
{
    return IsEqual( String );
}

BOOL STRING::operator==( const char *String )
{
    return IsEqual( String );
}

BOOL STRING::operator==( const STRING String )
{
    return IsEqual( String );
}

BOOL STRING::operator==( const STRING& String )
{
    return IsEqual( String );
}

BOOL STRING::operator!=( const STRING *String )
{
    return !IsEqual( String );
}

BOOL STRING::operator!=( const char *String )
{
    return !IsEqual( String );
}

BOOL STRING::operator!=( const STRING String )
{
    return !IsEqual( String );
}

BOOL STRING::operator!=( const STRING& String )
{
    return !IsEqual( String );
}
