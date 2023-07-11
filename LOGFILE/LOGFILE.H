// LOGFILE.H : definition file for LOGFILE class

#ifndef LOGFILE_H
#define LOGFILE_H

#include <stdlib.h>		// _MAX_FNAME & _MAX_EXT etc.
#include <stdio.h>      // sprintf() and fprintf()
#include <string.h>     // strlen(), strcat(), strcpy()
#include <dos.h>        // _dos_getdate & _dos_gettime
#include <fstream.h>	// ofstream()

#ifndef FALSE
#define FALSE 0
#endif
#ifndef TRUE
#define TRUE !FALSE
#endif
#ifndef BOOL
typedef int BOOL;
#endif

class LOGFILE
{
    // private variables
    char *_filename;
    char *_filepath;

public:
    // constructors and destructor
    LOGFILE( void );
    LOGFILE( char *Filename );
    ~LOGFILE( void );

    // accessors and mutators
    void SetFileName( const char *Filename );
    char* GetFilePath( void ) const;

    // methods
    BOOL Write( const char *msg );
    BOOL Delete( void );
};

#endif // LOGFILE_H
