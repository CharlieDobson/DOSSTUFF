// LOGFILE.H : definition file for LOGFILE class

#ifndef LOGFILE_HPP
#define LOGFILE_HPP

#include <stdlib.h>		// _MAX_FNAME & _MAX_EXT etc.
#include <stdio.h>      // sprintf(), _snprintf()
#include <string.h>     // strlen(), strcat(), strcpy()
#include <dos.h>        // _dos_getdate & _dos_gettime
#include <fstream.h>	// ofstream()

class LOGFILE
{
    char* filename;

  public:
    LOGFILE( void );
    LOGFILE( const char* Filename );
    ~LOGFILE( void );

    // accessors and mutators
    void FileName( const char* Filename );
    char* FileName( void ) const;

    // methods
    int Write( const char* msg );
    int Delete( void );
};

#endif // LOGFILE_HPP
