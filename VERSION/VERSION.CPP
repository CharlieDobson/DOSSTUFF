#include <iostream.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "Version.hpp"

Version::Version( void )
{
    Major = Minor = Build = Revision = 0;
}

Version::Version( unsigned int maj, unsigned int min, unsigned int b, unsigned int rev )
{
    Major = maj;
    Minor = min;
    Build = b;
    Revision = rev;
}

Version::Version( const Version& other )
{
    Major = other.Major;
    Minor = other.Minor;
    Build = other.Build;
    Revision = other.Revision;
}

Version::Version( const char* str )
{
    Major = Minor = Build = Revision = 0;

    if ( IsValidVersionString( str ) )
        ParseFromString( str );
}

Version& Version::operator=( const Version& other )
{
    if ( this != &other )
    {
        Major = other.Major;
        Minor = other.Minor;
        Build = other.Build;
        Revision = other.Revision;
    }
    return *this;
}

Version Version::operator+( const Version& other ) const
{
    Version result;
    result.Major = Major + other.Major;
    result.Minor = Minor + other.Minor;
    result.Build = Build + other.Build;
    result.Revision = Revision + other.Revision;
    return result;
}

int Version::operator==( const Version& other ) const
{
    return ( Major == other.Major &&
            Minor == other.Minor &&
            Build == other.Build &&
            Revision == other.Revision );
}

int Version::operator<( const Version& other ) const
{
    if ( Major != other.Major ) return Major < other.Major;
    if ( Minor != other.Minor ) return Minor < other.Minor;
    if ( Build != other.Build ) return Build < other.Build;
    return Revision < other.Revision;
}

int Version::operator>( const Version& other ) const
{
    if ( Major != other.Major ) return Major > other.Major;
    if ( Minor != other.Minor ) return Minor > other.Minor;
    if ( Build != other.Build ) return Build > other.Build;
    return Revision > other.Revision;
}

int Version::operator<=( const Version& other ) const
{
    return !( *this > other );
}

int Version::operator>=( const Version& other ) const
{
    return !( *this < other );
}

void Version::ToString( char* buffer, int bufferSize ) const
{
    if ( bufferSize > 0 ) {
        sprintf( buffer, "%u.%u.%u.%u", Major, Minor, Build, Revision );
    }
}

int Version::ParseFromString( const char* str )
{
    if ( !IsValidVersionString( str ) ) return 0;

    unsigned int tempMajor = 0, tempMinor = 0, tempBuild = 0, tempRevision = 0;
    int count = sscanf( str, "%u.%u.%u.%u", &tempMajor, &tempMinor, &tempBuild, &tempRevision );

    Major   = ( count >= 1 ) ? tempMajor : 0;
    Minor   = ( count >= 2 ) ? tempMinor : 0;
    Build   = ( count >= 3 ) ? tempBuild : 0;
    Revision = ( count == 4 ) ? tempRevision : 0;

    return 1;
}

int Version::IsValidVersionString( const char* str ) const
{
    if ( !str || *str == '\0' ) return 0;

    int dotCount = 0;
    const char* p = str;

    while ( *p ) {
        if ( *p == '-' ) return 0;
        if ( !isdigit( *p ) && *p != '.' ) return 0;
        if ( *p == '.' ) dotCount++;
        p++;
    }

    return dotCount <= 3;
}