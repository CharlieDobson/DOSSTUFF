// LOGFILE.CPP : Main implementation file for log function

#include "logfile.h"

LOGFILE::LOGFILE( void )
{
    _filename = new char[_MAX_FNAME + _MAX_EXT + 2];
    _filepath = new char[_MAX_PATH + 1];

    SetFileName( "TEMP.LOG" );
}

LOGFILE::LOGFILE( char *Filename )
{
    _filename = new char[_MAX_FNAME + _MAX_EXT + 2];
    _filepath = new char[_MAX_PATH + 1];

    SetFileName( Filename );
}

LOGFILE::~LOGFILE( void )
{
    delete[] _filename;
    delete[] _filepath;
}

void LOGFILE::SetFileName( const char *Filename )
{
    if ( strlen( Filename ) < _MAX_FNAME + _MAX_EXT + 2 ) {
        _filename = (char*)Filename;

        if ( getenv( "TEMP" ) != NULL ) {
            strcpy( _filepath, getenv( "TEMP" ) );
            strcat( _filepath, "\\" );
            strcat( _filepath, _filename );
        }
        else {
            _filepath = _filename;
        }
    }
    else {
        _filename = NULL;
        _filepath = NULL;
    }
}

char* LOGFILE::GetFilePath( void ) const
{
    return _filepath;
}

BOOL LOGFILE::Delete( void )
{
    return remove( _filepath ) == 0 ? TRUE : FALSE;
}

BOOL LOGFILE::Write( const char *msg )
{
    if ( _filepath == NULL )
        return FALSE;

    ofstream *logfile = new ofstream( _filepath, ios::app, filebuf::sh_read );

    if ( logfile->is_open() ) {
    	char *timestamp = new char[26];
    	char *message = new char[strlen( msg ) + 3]; // pre-pended space, null term, & newline
    	struct _dosdate_t date;
    	struct _dostime_t time;
    	_dos_getdate( &date );
    	_dos_gettime( &time );
    	
    	sprintf( timestamp, "[%d/%02d/%02d @ %02d:%02d:%02d]\0", date.year, date.month, 
        	date.day, time.hour, time.minute, time.second );
        
        sprintf( message, " %s\n", msg );

		logfile->write( timestamp, strlen( timestamp ) );
		logfile->write( message, strlen( message ) );

        logfile->close();
        delete[] timestamp;
	delete[] message;
	delete logfile;
	return TRUE;
    }
    
    delete logfile;

    return FALSE;
}
