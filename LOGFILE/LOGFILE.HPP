// logfile.hpp : class definition file

#ifndef LOGFILE_HPP
#define LOGFILE_HPP

#include <iostream.h>
#include <stdarg.h>

class LogFile
{
    char* filename;

public:
    LogFile( const char* Filename );
    ~LogFile( void );

    LogFile& operator=( const char* Filename );

    int Write( const char* Message );
    int Write( const char* fmt, ... );
    long LogSize( void );
    int Exists( void );
    int Clear( void );
    const char* GetFilename( void );

    friend ostream& operator<<( LogFile& log, const char* str );
};

#endif