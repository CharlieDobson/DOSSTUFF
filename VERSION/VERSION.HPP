#ifndef VERSION_HPP
#define VERSION_HPP

class Version
{
    int IsValidVersionString( const char* str ) const;

public:
    unsigned int Major;
    unsigned int Minor;
    unsigned int Build;
    unsigned int Revision;

    Version( void );
    Version( unsigned int maj, unsigned int min, unsigned int b, unsigned int rev );
    Version( const Version& other );
    Version( const char* str );  // Parse-from-string constructor

    Version& operator=( const Version& other );
    Version operator+( const Version& other ) const;

    int operator==( const Version& other ) const;
    int operator<( const Version& other ) const;
    int operator>( const Version& other ) const;
    int operator<=( const Version& other ) const;
    int operator>=( const Version& other ) const;

    void ToString( char* buffer, int bufferSize ) const;
    int ParseFromString( const char* str );
};

#endif