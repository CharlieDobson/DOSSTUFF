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
    struct tm* timeinfo = localtime( &now );
    char ts[20];
    strftime( ts, sizeof( ts ), "%Y-%m-%dT%H:%M:%S", timeinfo );

    FILE* outFile = fopen( filename, "a" );
    if ( !outFile ) return 0;

    fprintf( outFile, "[%s] %s\n", ts, Message );
    fclose( outFile );
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
    FILE* inFile = fopen( filename, "rb" );
    if ( !inFile ) return 0;

    fseek( inFile, 0, SEEK_END );
    long size = ftell( inFile );
    fclose( inFile );

    return size;
}

int LogFile::Exists( void )
{
    FILE* inFile = fopen( filename, "r" );
    if ( !inFile ) return 0;
    fclose( inFile );
    return 1;
}

int LogFile::Clear( void )
{
    FILE* outFile = fopen( filename, "w" );
    if ( !outFile ) return 0;
    fclose( outFile );
    return 1;
}

const char* LogFile::GetFilename( void )
{
    return filename;
}

