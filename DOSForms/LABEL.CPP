// Label class implementation file

#include "label.hpp"
#include <disp.h>               // Symantec display functions
#include <msmouse.h>            // Symantec mouse functions
#include <stdio.h>              // _vsnprintf
#include <string.h>             // strncpy, strlen

Label::Label( void ) : DOSForms( FG_BLACK, BG_WHITE )
{
    row = 0;
    column = 0;
    text[0] = '\0';
}

Label::Label( const char* text ) : DOSForms( FG_BLACK, BG_WHITE )
{
    row = 0;
    column = 0;
    this->text[0] = '\0';

    if ( text && text[0] != '\0' ) {
        strncpy( this->text, text, sizeof( this->text ) - 1 );
        this->text[sizeof( this->text ) - 1] = '\0';
    }
}

Label::Label( const unsigned short row, const unsigned short column, const char* text )
    : DOSForms( FG_BLACK, BG_WHITE )
{
    this->row = row;
    this->column = column;
    this->text[0] = '\0';

    if ( text && text[0] != '\0' ) {
        strncpy( this->text, text, sizeof( this->text ) - 1 );
        this->text[sizeof( this->text ) - 1] = '\0';
    }
}

Label::Label( const foreground_color_t foreground, const background_color_t background )
    : DOSForms( foreground, background )
{
    row = 0;
    column = 0;
    text[0] = '\0';
}

Label::Label( const foreground_color_t foreground, const background_color_t background, const char* text )
    : DOSForms( foreground, background )
{
    row = 0;
    column = 0;
    this->text[0] = '\0';

    if ( text && text[0] != '\0' ) {
        strncpy( this->text, text, sizeof( this->text ) - 1 );
        this->text[sizeof( this->text ) - 1] = '\0';
    }
}

Label::Label( const foreground_color_t foreground, const background_color_t background, const unsigned short row, const unsigned short column, const char* text )
    : DOSForms( foreground, background )
{
    this->row = row;
    this->column = column;
    this->text[0] = '\0';

    if ( text && text[0] != '\0' ) {
        strncpy( this->text, text, sizeof( this->text ) - 1 );
        this->text[sizeof( this->text ) - 1] = '\0';
    }
}

void Label::SetPosition( const unsigned short row, const unsigned short column )
{
    this->row = row;
    this->column = column;
}

void Label::SetText( const char* format, ... )
{
    this->text[0] = '\0';

    if ( !format || format[0] == '\0' ) return;

    va_list args;
    va_start( args, format );
    _vsnprintf( this->text, sizeof( this->text ) - 1, format, args );
    this->text[sizeof( this->text ) - 1] = '\0';
    va_end( args );
}

void Label::Draw( void )
{
    if ( disp_inited == 0 ) return;

    if ( text[0] == '\0' ) return;

    if ( IsMouseEnabled ) msm_hidecursor();

    disp_move( row, column );
    disp_setattr( ColorsToInt() );
    disp_puts( text );

    if ( IsMouseEnabled ) msm_showcursor();
}
