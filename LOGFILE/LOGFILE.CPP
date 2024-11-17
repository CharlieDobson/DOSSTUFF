// LOGFILE.CPP : Main implementation file for log function

#include "logfile.hpp"

LOGFILE::LOGFILE( void )
{
    if ( getenv( "TEMP" ) != NULL ) {
        m_filename = new char[strlen( getenv( "TEMP" ) ) + strlen( "LOGFILE.TXT" ) + 2];
        sprintf( m_filename, "%s\\%s", getenv( "TEMP" ), "LOGFILE.TXT" );
    }
    else {
        m_filename = new char[strlen( "LOGFILE.TXT" ) + 1];
        strcpy( m_filename, "LOGFILE.TXT" );
    }
}

LOGFILE::LOGFILE( char *Filename )
{
    if ( getenv( "TEMP" ) != NULL ) {
        m_filename = new char[strlen( getenv( "TEMP" ) ) + _MAX_FNAME + _MAX_EXT + 2];
        _snprintf( m_filename, strlen( getenv( "TEMP" ) ) + _MAX_FNAME + _MAX_EXT + 1, "%s\\%s", getenv( "TEMP" ), Filename );
    }
    else {
        m_filename = new char[_MAX_PATH + 1];
        strcpy( m_filename, Filename );
    }
}

LOGFILE::~LOGFILE( void )
{
    delete[] m_filename;
}

void LOGFILE::swap_pointers( char** first, char** second )
{
    char* temp = *first;
    *first = *second;
    *second = temp;
}

LOGFILE& LOGFILE::operator=( const LOGFILE& log )
{
    LOGFILE temp( log );

    swap_pointers( &temp.m_filename, &m_filename );

    return *this;
}

char* LOGFILE::ToCharString( void ) const
{
    return m_filename;
}

int LOGFILE::Delete( void )
{
	return remove( m_filename ) == 0 ? 1 : 0;
}

int LOGFILE::Write( const char* msg )
{
    if ( *m_filename == NULL ) {
        return 0;
    }

    ofstream logfile( m_filename, ios::app, filebuf::sh_read );

    if ( logfile.is_open() ) {
    	char *timestamp = new char[22];
    	char *message = new char[255]; // pre-pended space, null term, & newline
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

unsigned long LOGFILE::Size( void )
{
    if ( *m_filename == NULL ) {
        return 0L;
    }

    ifstream file( m_filename, ios::in, filebuf::sh_read );

    if ( !file.is_open() ) {
        return 0L;
    }

    file.seekg( 0, file.end );
    unsigned long file_size = file.tellg();
    file.seekg( 0, file.beg );
    file.close();

    return file_size;
}