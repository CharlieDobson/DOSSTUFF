// LOGFILE.CPP : Main implementation file for log function

#include "logfile.hpp"

LOGFILE::LOGFILE( void )
{
    filename = new char[_MAX_PATH + 1];

    if ( getenv( "TEMP" ) != NULL ) {
        sprintf( filename, "%s\\LOGFILE.TXT", getenv( "TEMP" ) );
    }
    else {
        strcpy( filename, "LOGFILE.TXT" );
    }
}

LOGFILE::LOGFILE( const char* Filename )
{
    filename = new char[_MAX_PATH + 1];

    if ( getenv( "TEMP" ) != NULL ) {
        sprintf( filename, "%s\\%s", getenv( "TEMP" ), Filename );
    }
    else {
        strcpy( filename, Filename );
    }
}

LOGFILE::~LOGFILE( void )
{
    delete[] filename;
}

void LOGFILE::FileName( const char* Filename )
{
    if ( strlen( Filename ) < _MAX_FNAME + _MAX_EXT + 2 ) {
        if ( getenv( "TEMP" ) != NULL ) {
            sprintf( filename, "%s\\%s", getenv( "TEMP" ), filename );
        }
        else {
            strcpy( filename, Filename );
        }
    }
    else {
        filename[0] = NULL;
    }
}

char* LOGFILE::FileName( void ) const
{
    return filename;
}

int LOGFILE::Delete( void )
{
	return remove( filename ) == 0 ? 1 : 0;
}

int LOGFILE::Write( const char* msg )
{
    if ( filename == NULL ) {
        return 0;
    }

    ofstream logfile( filename, ios::app, filebuf::sh_read );

    if ( logfile.is_open() ) {
    	char* timestamp = new char[22];
    	char* message = new char[255]; // pre-pended space, null term, & newline
    	struct _dosdate_t date;
    	struct _dostime_t time;
    	_dos_getdate( &date );
    	_dos_gettime( &time );

    	sprintf( timestamp, "[%d/%02d/%02d @ %02d:%02d:%02d]\0", date.year, date.month,
        	date.day, time.hour, time.minute, time.second );

        _snprintf( message, 258, " %s\n", msg );

		logfile.write( timestamp, strlen( timestamp ) );
		logfile.write( message, strlen( message ) );

        logfile.close();
	    delete[] message;
        delete[] timestamp;
	    return 1;
    }

    return 0;
}
