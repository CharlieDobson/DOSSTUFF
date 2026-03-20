// logfile.cpp : class implementation file

#include "LogFile.hpp"
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <time.h>

LogFile::LogFile( const char* Filename )
{
    if ( !Filename || !*Filename ) {
        filename = new char[1];
        filename[0] = '\0';
        return;
    }

    filename = new char[strlen( Filename ) + 1];
    strcpy( filename, Filename );
}

LogFile::~LogFile( void )
{
    delete[] filename;
}

LogFile& LogFile::operator=( const char* Filename )
{
    if ( !Filename || !*Filename ) {
        return *this;
    }

    delete[] filename;
    filename = new char[strlen( Filename ) + 1];
    strcpy( filename, Filename );
    return *this;
}

int LogFile::Write( const char* Message )
{
    time_t now = time( NULL );
    struct tm* t = localtime( &now );
    char ts[20];
    strftime( ts, sizeof( ts ), "%Y-%m-%dT%H:%M:%S", t );

    ofstream outFile( filename, ios::app );
    if ( !outFile ) return 0;

    outFile << '[' << ts << "] " << Message << '\n';
    outFile.close();
    return 1;
}

int LogFile::Write( const char* fmt, ... )
{
    char buffer[512];
    va_list args;
    va_start( args, fmt );
    vsprintf( buffer, fmt, args );
    va_end( args );
    return Write( buffer );
}

long LogFile::LogSize( void )
{
    ifstream inFile( filename, ios::in | ios::binary );
    if ( !inFile ) return 0;

    inFile.seekg( 0, ios::end );
    long size = inFile.tellg();
    inFile.close();

    return size;
}

int LogFile::Exists( void )
{
    ifstream inFile( filename );
    return inFile ? 1 : 0;
}

int LogFile::Clear( void )
{
    ofstream outFile( filename, ios::trunc );
    return outFile ? 1 : 0;
}

const char* LogFile::GetFilename( void )
{
    return filename;
}

ostream& operator<<( LogFile& log, const char* str )
{
    log.Write( str );
    return cout;
}
