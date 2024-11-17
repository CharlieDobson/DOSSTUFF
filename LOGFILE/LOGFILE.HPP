// LOGFILE.HPP : definition file for LOGFILE class

#ifndef LOGFILE_HPP
#define LOGFILE_HPP 1

#include <stdlib.h>	// _MAX_FNAME & _MAX_EXT etc.
#include <stdio.h>      // sprintf(), _snprintf()
#include <string.h>     // strlen(), strcat(), strcpy()
#include <dos.h>        // _dos_getdate & _dos_gettime
#include <fstream.h>	// ofstream
#include <iostream.h>   // seekg

class LOGFILE
{
    char *m_filename;

    void swap_pointers( char** first, char** second );

public:
    LOGFILE( void );
    LOGFILE( char *Filename );
    ~LOGFILE( void );

    // operators
    LOGFILE& operator=( const char* Filename );
    LOGFILE& operator=( const LOGFILE& log );

    // accessors and mutators
    char* ToCharString( void ) const;

    // methods
    int Write( const char* msg );
    int Delete( void );
    unsigned long Size( void );
};

#endif // LOGFILE_HPP
