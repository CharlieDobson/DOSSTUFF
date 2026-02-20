// DlgBox class implementation file

#include "dlgbox.hpp"
#include <disp.h>               // Symantec display functions
#include <msmouse.h>            // Symantec mouse functions
#include <stdlib.h>             // required for NULL
#include <stdio.h>              // _snprintf
#include <string.h>             // strncpy

DlgBox::DlgBox( void ) : Popup()
{
    screen_buffer = (unsigned short PTYPE*)CALLOC( disp_numrows * disp_numcols + 1, sizeof( unsigned short ) );

    fg_color = FG_BLACK;
    bg_color = BG_DARK_GRAY;

    title[0] = '\0';
    message[0] = '\0';

    coordinates.row = 0;
    coordinates.column = 0;
    coordinates.end_row = 0;
    coordinates.end_column = 0;

    border_style = BORDER_NONE;
    text_justification = CENTER;
    drop_shadow = TRUE;
    buttons = DB_OK;
}

DlgBox::DlgBox( const foreground_color_t foreground, const background_color_t background )
{
    screen_buffer = (unsigned short PTYPE*)CALLOC( disp_numrows * disp_numcols + 1, sizeof( unsigned short ) );

    fg_color = foreground;
    bg_color = background;

    title[0] = '\0';
    message[0] = '\0';

    coordinates.row = 0;
    coordinates.column = 0;
    coordinates.end_row = 0;
    coordinates.end_column = 0;

    border_style = BORDER_NONE;
    text_justification = CENTER;
    drop_shadow = TRUE;
    buttons = DB_OK;
}

DlgBox::DlgBox( const foreground_color_t foreground, const background_color_t background, const char PTYPE* message )
{
    screen_buffer = (unsigned short PTYPE*)CALLOC( disp_numrows * disp_numcols + 1, sizeof( unsigned short ) );

    fg_color = foreground;
    bg_color = background;
    
    title[0] = '\0';
    if( NULL != message ) {
        strncpy( this->message, message, sizeof( this->message ) - 1 );
        this->message[ sizeof( this->message ) - 1 ] = '\0';
    } else {
        this->message[0] = '\0';
    }

    coordinates.row = 0;
    coordinates.column = 0;
    coordinates.end_row = 0;
    coordinates.end_column = 0;
    border_style = BORDER_NONE;
    
    text_justification = CENTER;
    drop_shadow = TRUE;
}

DlgBox( const foreground_color_t foreground, const background_color_t background, const dialog_buttons_t* buttons )
{
    screen_buffer = (unsigned short PTYPE*)CALLOC( disp_numrows * disp_numcols + 1, sizeof( unsigned short ) );

    fg_color = foreground;
    bg_color = background;

    title[0] = '\0';
    message[0] = '\0';

    coordinates.row = 0;
    coordinates.column = 0;
    coordinates.end_row = 0;
    coordinates.end_column = 0;

    border_style = BORDER_NONE;
    text_justification = CENTER;
    drop_shadow = TRUE;

    if ( NULL != buttons ) {
        this->buttons = *buttons;
    } else {
        this->buttons = DB_OK;
    }
}

DlgBox( const foreground_color_t foreground, const background_color_t background, const dialog_buttons_t* buttons, const char PTYPE* message )
{
    screen_buffer = (unsigned short PTYPE*)CALLOC( disp_numrows * disp_numcols + 1, sizeof( unsigned short ) );

    fg_color = foreground;
    bg_color = background;

    title[0] = '\0';
    if ( NULL != message ) {
        strncpy( this->message, message, sizeof( this->message ) - 1 );
        this->message[ sizeof( this->message ) - 1 ] = '\0';
    } else {
        this->message[0] = '\0';
    }

    coordinates.row = 0;
    coordinates.column = 0;
    coordinates.end_row = 0;
    coordinates.end_column = 0;

    border_style = BORDER_NONE;
    text_justification = CENTER;
    drop_shadow = TRUE;

    if ( NULL != buttons ) {
        this->buttons = *buttons;
    } else {
        this->buttons = DB_OK;
    }
}

DlgBox::~DlgBox( void )
{
    FREE( screen_buffer );
}

int Popup::ColorsToInt( void )
{
    return (int)( ( bg_color << 4 ) | fg_color );
}

boolean DlgBox::SaveWindow( void )
{
    if ( disp_inited == 0 ) return FALSE;

    // define save area
    unsigned short start_row = Window.coordinates.row;
    unsigned short start_column = Window.coordinates.column;
    unsigned short end_row = Window.coordinates.end_row;
    unsigned short end_column = Window.coordinates.end_column;

    // account for dropshadow
    if ( Window.drop_shadow ) {
        ++end_row;
        ++end_column;
    }

    if ( IsMouseEnabled ) msm_hidecursor();

    // save screen contents to buffer
    disp_peekbox( screen_buffer, start_row, start_column, end_row, end_column );

    if ( IsMouseEnabled ) msm_showcursor();

    return TRUE;
}

boolean DlgBox::RestoreWindow( void )
{
    if ( disp_inited == 0 ) return FALSE;

    // define restore area
    unsigned short start_row = Window.coordinates.row;
    unsigned short start_column = Window.coordinates.column;
    unsigned short end_row = Window.coordinates.end_row;
    unsigned short end_column = Window.coordinates.end_column;

    // account for dropshadow
    if ( Window.drop_shadow ) {
        ++end_row;
        ++end_column;
    }

    if ( IsMouseEnabled ) msm_hidecursor();

    // restore screen contents from buffer
    disp_pokebox( screen_buffer, start_row, start_column, end_row, end_column );

    if ( IsMouseEnabled ) msm_showcursor();

    return TRUE;
}

void DlgBox::Draw( void )
{
    if ( disp_inited == 0 ) return;

    // save screen area
    if ( !SaveWindow() ) return;

    if ( Window.coordinates.row == 0 && Window.coordinates.column == 0 &&
         Window.coordinates.end_row == 0 && Window.coordinates.end_column == 0 ) return;

    if ( IsMouseEnabled ) msm_hidecursor();

    if ( Window.drop_shadow ) {
        // draw drop shadow
        disp_fillbox( BG_BLACK * 256 + ' ',
                      Window.coordinates.row + 1,
                      Window.coordinates.column + 1,
                      Window.coordinates.end_row + 1,
                      Window.coordinates.end_column + 1 );
    }

    // draw window box
    disp_setattr( Window.color.ToInt() );
    disp_box( Window.border_style, Window.color.ToInt(),
              Window.coordinates.row, Window.coordinates.column,
              Window.coordinates.end_row, Window.coordinates.end_column );
    // fill window area
    disp_fillbox( Window.color.ToInt() * 256 + ' ',
                  Window.coordinates.row + 1,
                  Window.coordinates.column + 1,
                  Window.coordinates.end_row - 1,
                  Window.coordinates.end_column - 1 );

    // draw title if specified
    if ( Window.title[0] != '\0' ) {
        char temp[38] = { '\0' };
        short title_length = (short)strlen( Window.title );
        short title_column = Window.coordinates.column + 3;

        switch ( Window.justify ) {
            case forms_window_t::justify_t::LEFT: {
                title_column = Window.coordinates.column + 3;
                break;
            }
            case forms_window_t::justify_t::CENTER: {
                title_column = Window.coordinates.column +
                               ( ( Window.coordinates.end_column - Window.coordinates.column ) / 2 ) -
                               ( title_length / 2 );
                break;
            }
            case forms_window_t::justify_t::RIGHT: {
                title_column = Window.coordinates.end_column - title_length - 3;
                break;
            }
            default: {
                break;
            }
        }

        _snprintf( temp, sizeof( temp ), " %s ", Window.title ); // ensure spaces surround title
        disp_setattr( Window.color.ToInt() );
        disp_move( Window.coordinates.row, title_column );
        disp_puts( temp );
    }

    // display message if specified
    if ( message[0] != '\0' ) {
        // if message is larger than window, split it into multiple lines (not implemented yet)
        char* line1 = new char[60];
        char* line2 = new char[60];
        char* line3 = new char[60];
        char* line4 = new char[60];
        char* line5 = new char[60];
        size_t msg_len = strlen( message );

        // copy strings in 60 byte chunks
        if( msg_len > 240 ) {
            strncpy( line1, message, 60 ); line1[59] = '\0';
            strncpy( line2, message + 60, 60 ); line2[59] = '\0';
            strncpy( line3, message + 120, 60 ); line3[59] = '\0';
            strncpy( line4, message + 180, 60 ); line4[59] = '\0';
            strncpy( line5, message + 240, 60 ); line5[59] = '\0';
        } else if( msg_len > 180 ) {
            strncpy( line1, message, 60 ); line1[59] = '\0';
            strncpy( line2, message + 60, 60 ); line2[59] = '\0';
            strncpy( line3, message + 120, 60 ); line3[59] = '\0';
            strncpy( line4, message + 180, 60 ); line4[59] = '\0';
            line5[0] = '\0';
        } else if( msg_len > 120 ) {
            strncpy( line1, message, 60 ); line1[59] = '\0';
            strncpy( line2, message + 60, 60 ); line2[59] = '\0';
            strncpy( line3, message + 120, 60 ); line3[59] = '\0';
            line4[0] = '\0';
            line5[0] = '\0';
        } else if( msg_len > 60 ) {
            strncpy( line1, message, 60 ); line1[59] = '\0';
            strncpy( line2, message + 60, 60 ); line2[59] = '\0';
            line3[0] = '\0';
            line4[0] = '\0';
            line5[0] = '\0';
        } else {
            strncpy( line1, message, 60 ); line1[59] = '\0';
            line2[0] = '\0';
            line3[0] = '\0';
            line4[0] = '\0';
            line5[0] = '\0';
        }


        disp_setattr( Window.color.ToInt() );
        short msg_row = ( Window.coordinates.row + Window.coordinates.end_row ) / 2;
        short msg_col = ( Window.coordinates.column + Window.coordinates.end_column ) / 2 - ( short )( strlen( message ) / 2 );
        disp_move( msg_row, msg_col );
        disp_puts( message );
    }

    if ( IsMouseEnabled ) msm_showcursor();
}

button_return_value_t DlgBox::Open( void )
{
    if ( disp_inited == 0 ) return BUTTON_OK;

    if ( NULL == buttons ) return BUTTON_OK;

    if ( message[0] == '\0' ) return BUTTON_OK;

    // get message length and determine lines needed
    short msg_length = (short)strlen( message );
    short lines_needed = 1;

    // set lines needed based on message length
    if ( msg_length > 240 ) {
        lines_needed = 5;
    } else if( msg_length > 180 ) {
        lines_needed = 4;
    } else if( msg_length > 120 ) {
        lines_needed = 3;
    } else if( msg_length > 60 ) {
        lines_needed = 2;
    } else if( msg_length > 0 ) {
        lines_needed = 1;
    }

    // set display coordinates based on message length


    // not implemented yet
}