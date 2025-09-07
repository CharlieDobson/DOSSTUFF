// dosforms.cpp : class implementation file

#include "dosforms.hpp"
#include "memmod.hpp"
#include <stdlib.h>     // malloc, _fmalloc, free, _ffree
#include <stdio.h>      // printf, puts, _snprintf
#include <malloc.h>     // malloc, _fmalloc, free, _ffree
#include <string.h>     // strlen, memset, strncpy
#include <graph.h>      // display functions


static boolean dosforms_inited = FALSE;

DOSForms::DOSForms( void )
{
    if ( dosforms_inited ) {
        return;
    }

    _videoconfig vc;
    _getvideoconfig( &vc );
    m_old_display_mode = vc.mode;

    if ( m_old_display_mode != 3 || m_old_display_mode != 7 ) {
        _setvideomode( _TEXTC80 );
    }

    m_text_columns = vc.numtextcols;;
    m_text_rows = vc.numtextrows;

    m_old_display_attributes.foreground = (foreground_colors_t)_gettextcolor();
    m_old_display_attributes.background = (background_colors_t)_getbkcolor();
    m_forms_colors.foreground = FG_BLUE;
    m_forms_colors.background = BG_WHITE;
    m_title_colors.foreground = FG_WHITE;
    m_title_colors.background = BG_BLUE;
    m_status_bar_colors.foreground = FG_YELLOW;
    m_status_bar_colors.background = BG_BLUE;
    m_title_text = (char PTR_TYPE*)ALLOC( 1, m_text_columns / 2 );
    m_status_bar_text = (char PTR_TYPE*)ALLOC( 1, m_text_columns - 2 );
    m_mouse_control = new char[4];
    has_title_bar = FALSE;
    has_status_bar = FALSE;
    dosforms_inited = TRUE;

    _snprintf( m_mouse_control, 4, "[%c]", 196 ); // 196 - ASCII "em dash"

    // hide keyboard cursor
    __asm {
        mov ah, 0x01
        mov cx, 0x2607 // 0x2607 = hide keyboard cursor
        int 0x10 // BIOS interrupt to set keyboard cursor visibility
    }
}

DOSForms::DOSForms( const foreground_colors_t FormForeground, const background_colors_t FormBackground )
{
    if ( dosforms_inited ) {
        return;
    }

    _videoconfig vc;
    _getvideoconfig( &vc );
    m_old_display_mode = vc.mode;

    if ( m_old_display_mode != 3 || m_old_display_mode != 7 ) {
        _setvideomode( _TEXTC80 );
    }

    m_text_columns = vc.numtextcols;;
    m_text_rows = vc.numtextrows;

    m_old_display_attributes.foreground = (foreground_colors_t)_gettextcolor();
    m_old_display_attributes.background = (background_colors_t)_getbkcolor();
    m_forms_colors.foreground = FormForeground;
    m_forms_colors.background = FormBackground;
    m_title_colors.foreground = FG_WHITE;
    m_title_colors.background = BG_BLUE;
    m_status_bar_colors.foreground = FG_YELLOW;
    m_status_bar_colors.background = BG_BLUE;
    m_title_text = (char PTR_TYPE*)ALLOC( 1, m_text_columns / 2 );
    m_status_bar_text = (char PTR_TYPE*)ALLOC( 1, m_text_columns - 2 );
    m_mouse_control = new char[4];
    has_title_bar = FALSE;
    has_status_bar = FALSE;
    dosforms_inited = TRUE;

    _snprintf( m_mouse_control, 4, "[%c]", 196 ); // 196 - ASCII "em dash"

    // hide keyboard cursor
    __asm {
        mov ah, 0x01
        mov cx, 0x2607 // 0x2607 = hide keyboard cursor
        int 0x10 // BIOS interrupt to set keyboard cursor visibility
    }
}

DOSForms::DOSForms( const foreground_colors_t FormForeground, const background_colors_t FormBackground, const foreground_colors_t TitleForeground,
    const background_colors_t TitleBackground, const char* TitleText )
{
    if ( dosforms_inited ) {
        return;
    }

    _videoconfig vc;
    _getvideoconfig( &vc );
    m_old_display_mode = vc.mode;

    if ( m_old_display_mode != 3 || m_old_display_mode != 7 ) {
        _setvideomode( _TEXTC80 );
    }

    m_text_columns = vc.numtextcols;;
    m_text_rows = vc.numtextrows;

    m_old_display_attributes.foreground = (foreground_colors_t)_gettextcolor();
    m_old_display_attributes.background = (background_colors_t)_getbkcolor();
    m_forms_colors.foreground = FormForeground;
    m_forms_colors.background = FormBackground;
    m_title_colors.foreground = TitleForeground;
    m_title_colors.background = TitleBackground;
    m_status_bar_colors.foreground = FG_YELLOW;
    m_status_bar_colors.background = BG_BLUE;
    m_title_text = (char PTR_TYPE*)ALLOC( 1, m_text_columns / 2 );
    m_status_bar_text = (char PTR_TYPE*)ALLOC( 1, m_text_columns - 2 );
    m_mouse_control = new char[4];
    has_title_bar = TRUE;
    has_status_bar = FALSE;
    dosforms_inited = TRUE;

    _snprintf( m_mouse_control, 4, "[%c]", 196 ); // 196 - ASCII "em dash"

    if ( NULL != TitleText ) {
        STRNCPY( m_title_text, TitleText, m_text_columns / 2 );
        if ( STRLEN( TitleText ) > (size_t)( m_text_columns / 2 ) ) {
            m_title_text[m_text_columns / 2 - 1] = '\0'; // ensure null-termination
        }
    }

    // hide keyboard cursor
    __asm {
        mov ah, 0x01
        mov cx, 0x2607 // 0x2607 = hide keyboard cursor
        int 0x10 // BIOS interrupt to set keyboard cursor visibility
    }
}

DOSForms::DOSForms( const foreground_colors_t FormForeground, const background_colors_t FormBackground, const foreground_colors_t TitleForeground,
    const background_colors_t TitleBackground, const char* TitleText, const foreground_colors_t StatusBarForeground, const background_colors_t StatusBarBackground )
{
    if ( dosforms_inited ) {
        return;
    }

    _videoconfig vc;
    _getvideoconfig( &vc );
    m_old_display_mode = vc.mode;

    if ( m_old_display_mode != 3 || m_old_display_mode != 7 ) {
        _setvideomode( _TEXTC80 );
    }

    m_text_columns = vc.numtextcols;;
    m_text_rows = vc.numtextrows;

    m_old_display_attributes.foreground = (foreground_colors_t)_gettextcolor();
    m_old_display_attributes.background = (background_colors_t)_getbkcolor();
    m_forms_colors.foreground = FormForeground;
    m_forms_colors.background = FormBackground;
    m_title_colors.foreground = TitleForeground;
    m_title_colors.background = TitleBackground;
    m_status_bar_colors.foreground = StatusBarForeground;
    m_status_bar_colors.background = StatusBarBackground;
    m_title_text = (char PTR_TYPE*)ALLOC( 1, m_text_columns / 2 );
    m_status_bar_text = (char PTR_TYPE*)ALLOC( 1, m_text_columns - 2 );
    m_mouse_control = new char[4];
    has_title_bar = TRUE;
    has_status_bar = TRUE;
    dosforms_inited = TRUE;

    _snprintf( m_mouse_control, 4, "[%c]", 196 ); // 196 - ASCII "em dash"

    if ( NULL != TitleText ) {
        STRNCPY( m_title_text, TitleText, m_text_columns / 2 );
        if ( STRLEN( TitleText ) > (size_t)( m_text_columns / 2 ) ) {
            m_title_text[m_text_columns / 2 - 1] = '\0'; // ensure null-termination
        }
    }

    // hide keyboard cursor
    __asm {
        mov ah, 0x01
        mov cx, 0x2607 // 0x2607 = hide keyboard cursor
        int 0x10 // BIOS interrupt to set keyboard cursor visibility
    }
}

DOSForms::~DOSForms( void )
{
    if ( dosforms_inited ) {
        _setbkcolor( m_old_display_attributes.background );
        _settextcolor( m_old_display_attributes.foreground );
        _settextposition( 1, 1 );
        _clearscreen( _GCLEARSCREEN );
        _setvideomode( m_old_display_mode );

        // restore keyboard cursor visibility
        __asm {
            mov ah, 0x01
            mov cx, 0x0607 // 0x0607 = show keyboard cursor
            int 0x10 // BIOS interrupt to set keyboard cursor visibility
        }
    }

    if ( mouse.IsInited() ) {
        mouse.HideCursor();
    }

    FREE( m_mouse_control );
    FREE( m_title_text );
    FREE( m_status_bar_text );

    dosforms_inited = FALSE;
}

/************************
*  Private methods
************************/
unsigned int DOSForms::CenterScreen( const char PTR_TYPE* Text ) const
{
    return ( STRLEN( Text ) + m_text_columns ) / 2 - STRLEN( Text );
}

boolean DOSForms::SaveScreenRegion( forms_window_t& Window )
{
    if ( NULL != Window.buffer ) {
        return FALSE;
    }

    unsigned char far* video = (unsigned char far*)0xB8000000L; // video memory address for text mode
    short start_row = Window.coordinates.row - 1;
    short start_column = Window.coordinates.column - 1;
    short end_row = Window.coordinates.end_row;
    short end_column = Window.coordinates.end_column;

    if ( Window.drop_shadow ) {
        ++end_row;
        ++end_column;
    }

    short height = end_row - start_row + 1;
    short width = end_column - start_column + 1;
    Window.buffer = (forms_window_t::screen_buffer_t far*)ALLOC(1,  height * width * sizeof( forms_window_t::screen_buffer_t ) );

    // verify memory allocation
    if ( NULL == Window.buffer ) {
        return FALSE;
    }

    for ( short r = 0; r < height; ++r ) {
        for ( short c = 0; c < width; ++c ) {
            short screen_row = start_row + r;
            short screen_col = start_column + c;
            short screen_offset = ( screen_row * m_text_columns + + screen_col ) * 2;
            Window.buffer[r * width + c].character = video[screen_offset];
            Window.buffer[r * width + c].attribute = video[screen_offset + 1];
        }
    }

    return TRUE;
}

boolean DOSForms::RestoreScreenRegion( forms_window_t& Window )
{
    if ( NULL == Window.buffer ) {
        return FALSE;
    }

    unsigned char far* video = (unsigned char far*)0xB8000000L; // video memory address for text mode
    short start_row = Window.coordinates.row - 1;
    short start_column = Window.coordinates.column - 1;
    short end_row = Window.coordinates.end_row;
    short end_column = Window.coordinates.end_column;

    if ( Window.drop_shadow ) {
        ++end_row;
        ++end_column;
    }

    short height = end_row - start_row + 1;
    short width = end_column - start_column + 1;

    for ( short r = 0; r < height; ++r ) {
        for ( short c = 0; c < width; ++c ) {
            short screen_row = start_row + r;
            short screen_col = start_column + c;
            short screen_offset = ( screen_row * m_text_columns + screen_col ) * 2;
            video[screen_offset] = Window.buffer[r * width + c].character;
            video[screen_offset + 1] = Window.buffer[r * width + c].attribute;
        }
    }

    FREE( Window.buffer );
    Window.buffer = NULL;
    return TRUE;
}


/************************
* Accessors
************************/
forms_colors_t DOSForms::FormColor( void ) const
{
    return m_forms_colors;
}

forms_colors_t DOSForms::TitleColor( void ) const
{
    return m_title_colors;
}

const char* DOSForms::TitleText( void ) const
{
    char return_buffer[80]; // ensure enough space for the title text

    if ( NULL != m_title_text ) {
        STRNCPY( return_buffer, m_title_text, 80 );
    }
    else {
        return_buffer[0] = '\0'; // ensure null-termination
    }

    return return_buffer;
}

forms_colors_t DOSForms::StatusBarColor( void ) const
{
    return m_status_bar_colors;
}

const char* DOSForms::StatusBarText( void ) const
{
    char return_buffer[80]; // ensure enough space for the status bar text

    if ( NULL != m_status_bar_text ) {
        STRNCPY( return_buffer, m_status_bar_text, 80 );
    }
    else {
        return_buffer[0] = '\0'; // ensure null-termination
    }

    return return_buffer;
}


/************************
* Mutators
************************/
void DOSForms::TitleColor( const foreground_colors_t Foreground, const background_colors_t Background )
{
    m_title_colors.foreground = Foreground;
    m_title_colors.background = Background;
    has_title_bar = TRUE;

    if ( !dosforms_inited ) {
        return;
    }

    if ( mouse.IsInited() ) {
        mouse.HideCursor();
    }

    _settextwindow( 1, 1, 1, m_text_columns ); // set text window to the first row
    _setbkcolor( m_title_colors.background );
    _settextcolor( m_title_colors.foreground );
    _clearscreen( _GWINDOW );

    _settextwindow( 1, 1, m_text_rows, m_text_columns ); // reset text window to the full screen
    _setbkcolor( m_forms_colors.background );
    _settextcolor( m_forms_colors.foreground );

    if ( !mouse.IsInited() ) {
        mouse.ShowCursor();
    }
}

void DOSForms::TitleText( const char PTR_TYPE* Text )
{
    if ( NULL == Text ) {
        return;
    }

    STRNCPY( m_title_text, Text, m_text_columns / 2 );

    if ( STRLEN( Text ) > (size_t)( m_text_columns / 2 ) ) {
        m_title_text[m_text_columns / 2 - 1] = '\0'; // ensure null-termination
    }

    if ( !dosforms_inited ) {
        return;
    }

    if ( mouse.IsInited() ) {
        mouse.HideCursor();
    }

    _settextcolor( m_title_colors.foreground ); 
    _setbkcolor( m_title_colors.background );
    _settextposition( 1, CenterScreen( m_title_text ) );
    _outtext( m_title_text );

    _settextcolor( m_forms_colors.foreground );
    _setbkcolor( m_forms_colors.background );

    if ( mouse.IsInited() ) {
        mouse.ShowCursor();
    }
}

void DOSForms::StatusBarColor( const foreground_colors_t Foreground, const background_colors_t Background )
{
    m_status_bar_colors.foreground = Foreground;
    m_status_bar_colors.background = Background;
    has_status_bar = TRUE;

    if ( dosforms_inited == 0 ) {
        return;
    }

    if ( mouse.IsInited() ) {
        mouse.HideCursor();
    }

    _settextwindow( m_text_rows, 1, m_text_rows, m_text_columns ); // set text window to the last row
    _setbkcolor( m_status_bar_colors.background );
    _settextcolor( m_status_bar_colors.foreground );
    _clearscreen( _GWINDOW );

    _setbkcolor( m_forms_colors.background );
    _settextcolor( m_forms_colors.foreground );

    if ( mouse.IsInited() ) {
        mouse.ShowCursor();
    }
}

void DOSForms::StatusBarText( const char PTR_TYPE* Text )
{
    if ( NULL == Text ) {
        return;
    }

    STRNCPY( m_status_bar_text, Text, m_text_columns - 2 );

    if ( STRLEN( Text ) > (size_t)( m_text_columns - 2 ) ) {
        m_status_bar_text[m_text_columns - 2 - 1] = '\0'; // ensure null-termination
    }

    if ( !dosforms_inited ) {
        return;
    }

    if ( mouse.IsInited() ) {
        mouse.HideCursor();
    }

    _settextcolor( m_status_bar_colors.foreground );
    _setbkcolor( m_status_bar_colors.background );
    _settextposition( m_text_rows, 2 );
    _outtext( m_status_bar_text );

    _setbkcolor( m_forms_colors.background );
    _settextcolor( m_forms_colors.foreground );

    if ( mouse.IsInited() ) {
        mouse.ShowCursor();
    }
}


/************************
* Methods
************************/
void DOSForms::RemoveTitleBar( void )
{
    if ( !dosforms_inited ) {
        return;
    }

    if ( mouse.IsInited() ) {
        mouse.HideCursor();
    }

    _settextwindow( 1, 1, 1, m_text_columns ); // set text window to the first row
    _setbkcolor( m_forms_colors.background );
    _settextcolor( m_forms_colors.foreground );
    _clearscreen( _GWINDOW );

    _settextwindow( 1, 1, m_text_rows, m_text_columns ); // reset text window to the full screen

    if ( mouse.IsInited() ) {
        _setbkcolor( m_title_colors.background );
        _settextcolor( m_title_colors.foreground );
        _settextposition( 1, 1 );
        _outtext( m_mouse_control ); // draw mouse control character

        mouse.ShowCursor();
    }

    has_title_bar = FALSE;
}

void DOSForms::RemoveStatusBar( void )
{
    if ( !dosforms_inited ) {
        return;
    }

    if ( mouse.IsInited() ) {
        mouse.HideCursor();
    }

    _settextwindow( m_text_rows, 1, m_text_rows, m_text_columns ); // set text window to the last row
    _setbkcolor( m_forms_colors.background );
    _settextcolor( m_forms_colors.foreground );
    _clearscreen( _GWINDOW );

    _settextwindow( 1, 1, m_text_rows, m_text_columns ); // reset text window to the full screen

    if ( mouse.IsInited() ) {
        mouse.ShowCursor();
    }

    has_status_bar = FALSE;
}

void DOSForms::OpenForm( void )
{
    if ( !dosforms_inited ) {
        return;
    }

    // check for B&W (mono) display and set colors
    /*
    if ( disp_getmode() != 3 ) {
        if ( m_form_color != WHITE_ON_BLACK ) {
            m_form_color = WHITE_ON_BLACK;
        }
        if ( m_title_color != BLACK_ON_WHITE ) {
            m_title_color = BLACK_ON_WHITE;
        }
        if ( m_status_bar_color != BLACK_ON_WHITE ) {
            m_status_bar_color = BLACK_ON_WHITE;
        }
    }
    */

    if ( mouse.IsInited() ) {
        mouse.HideCursor();
    }

    _settextwindow( 1, 1, m_text_rows, m_text_columns ); // set text window to the full screen
    _setbkcolor( m_forms_colors.background );
    _settextcolor( m_forms_colors.foreground );
    _clearscreen( _GCLEARSCREEN );

    if ( mouse.IsInited() ) {
        mouse.ShowCursor();
    }

    if ( has_title_bar ) {
        TitleColor( m_title_colors.foreground, m_title_colors.background );
    }

    if ( NULL != m_title_text && *m_title_text != '\0' ) {
        char temp_text[80]; // ensure enough space for the title text
        STRNCPY( temp_text, m_title_text, 80 );
        TitleText( temp_text );
    }

    if ( mouse.IsInited() ) {
        mouse.HideCursor();

        if ( has_title_bar ) {
            _settextcolor( m_title_colors.foreground );
            _setbkcolor( m_title_colors.background );
        }
        else {
            _settextcolor( m_forms_colors.foreground );
            _setbkcolor( m_forms_colors.background );
        }

        _settextposition( 1, 1 );
        _outtext( m_mouse_control ); // draw mouse control character
        mouse.ShowCursor();
    }

    _settextcolor( m_forms_colors.foreground );
    _setbkcolor( m_forms_colors.background );

    if ( has_status_bar ) {
        StatusBarColor( m_status_bar_colors.foreground, m_status_bar_colors.background );
    }

    if ( NULL != m_status_bar_text && NULL != *m_status_bar_text ) {
        char temp_text[80]; // ensure enough space for the status bar text
        STRNCPY( temp_text, m_status_bar_text, 80 );
        StatusBarText( temp_text );
    }
}

void DOSForms::DrawButton( const forms_button_t Button )
{
    if ( !dosforms_inited ) {
        return;
    }

    // draw dropshadow
    if ( Button.drop_shadow ) {
        _settextcolor( FG_BLACK );
        _setbkcolor( BG_BLACK );
        _settextwindow( Button.coordinates.row + 1, Button.coordinates.column + 1,
                        Button.coordinates.end_row + 1, Button.coordinates.end_column + 1 );
        _clearscreen( _GWINDOW );
    }

    // draw button
    _settextcolor( Button.color.foreground );
    _setbkcolor( Button.color.background );
    _settextwindow( Button.coordinates.row, Button.coordinates.column,
                    Button.coordinates.end_row, Button.coordinates.end_column );
    _clearscreen( _GWINDOW );

    if ( NULL == Button.label || *Button.label == '\0' ) {
        _settextwindow( 1, 1, m_text_rows, m_text_columns ); // reset text window to full screen
        return;
    }

    // calculate center position for the button label
    unsigned int row = ( Button.coordinates.end_row - Button.coordinates.row + 2 ) / 2;
    unsigned int col = ( ( Button.coordinates.end_column - Button.coordinates.column + 1 ) / 2 ) - ( strlen( Button.label ) / 2 ) + 1;
    _settextposition( row, col );
    _outtext( Button.label );

    _settextwindow( 1, 1, m_text_rows, m_text_columns ); // reset text window to the full screen
    _settextcolor( m_forms_colors.foreground );
    _setbkcolor( m_forms_colors.background );
}

// general window
boolean DOSForms::OpenWindow( forms_window_t& Window )
{
    if ( !dosforms_inited ) {
        return FALSE;
    }

    if ( Window.coordinates.end_row > m_text_rows || Window.coordinates.end_column > m_text_columns ) {
        return FALSE;
    }

    if ( mouse.IsInited() ) {
        mouse.HideCursor();
    }

    SaveScreenRegion( Window ); // save current screen region to buffer

    // draw drop shadow if specified
    if ( Window.drop_shadow ) {
        _settextcolor( FG_BLACK );
        _setbkcolor( BG_BLACK );
        _settextwindow( Window.coordinates.row + 1, Window.coordinates.column + 1,
                        Window.coordinates.end_row + 1, Window.coordinates.end_column + 1 );
        _clearscreen( _GWINDOW );
    }

    // draw window
    _settextcolor( Window.color.foreground );
    _setbkcolor( Window.color.background );
    _settextwindow( Window.coordinates.row, Window.coordinates.column,
                    Window.coordinates.end_row, Window.coordinates.end_column );
    _clearscreen( _GWINDOW );

    // set title if specified
    if ( NULL != Window.title && Window.title[0] != '\0' ) {
        char* title = new char[STRLEN( Window.title ) + 1];

        if ( Window.justify == 'C' ) {
            _settextposition( 1, ( Window.coordinates.end_column - Window.coordinates.column / 2 ) - STRLEN( Window.title ) );
        }
        else {
            _settextposition( 1, 4 );
        }

        _outtext( Window.title );
        delete[] title;
    }
    else {
        // border with no title
    }

    _settextcolor( m_forms_colors.foreground );
    _setbkcolor( m_forms_colors.background );
    _settextwindow( 1, 1, m_text_rows, m_text_columns );

    if ( mouse.IsInited() ) {
        mouse.ShowCursor();
    }

    return TRUE;
}

boolean DOSForms::WriteToWindow( forms_window_t& Window, const short row, const char PTR_TYPE* Text )
{
    if ( !dosforms_inited ) {
        return FALSE;
    }

    if ( NULL == Text || Text[0] == '\0' ) {
        return FALSE;
    }

    if ( STRLEN( Text ) > (size_t)( Window.coordinates.end_column - Window.coordinates.column - 4 ) ) {
        return FALSE;
    }

    if ( row < 1 || row > Window.coordinates.end_row - 1 ) {
        return FALSE;
    }

    if ( mouse.IsInited() ) {
        mouse.HideCursor();
    }

    _settextcolor( Window.color.foreground );
    _setbkcolor( Window.color.background );
    _settextwindow( Window.coordinates.row, Window.coordinates.column,
                    Window.coordinates.end_row, Window.coordinates.end_column );
    _settextposition( row + 1, Window.coordinates.column + 2 );
    _outtext( Text );

    _settextcolor( m_forms_colors.foreground );
    _setbkcolor( m_forms_colors.background );
    _settextwindow( 1, 1, m_text_rows, m_text_columns );

    if ( mouse.IsInited() ) {
        mouse.ShowCursor();
    }

    return TRUE;
}

void DOSForms::CloseWindow( forms_window_t& Window )
{
    if ( !dosforms_inited ) {
        return;
    }

    if ( NULL == Window.buffer ) {
        return;
    }

    if ( mouse.IsInited() ) {
        mouse.HideCursor();
    }

    RestoreScreenRegion( Window );

    if ( mouse.IsInited() ) {
        mouse.ShowCursor();
    }
}

// message box
// Window window provides color, coordinates, and Label provides dialog text
// return 0 on error, or number of button pressed
// button_return_value_t DOSForms::MessageBox( const forms_window_t& Window, const forms_button_t Buttons, const dialog_buttons_t Choices )
// {
//     button_t selected_choice = BUTTON_CANCEL;
//     button_t choice1, choice2;
//     char button_text[2][9] = { NULL, NULL };

//     switch( Choices ) {
//         case DB_YESNO:
//             strncpy( button_text[0], "Yes", 9 );
//             choice1 = BUTTON_YES;
//             strncpy( button_text[1], "No", 9 );
//             choice2 = BUTTON_NO;
//             break;
//         case DB_NEXTBACK:
//             strncpy( button_text[0], "Next", 9 );
//             choice1 = BUTTON_NEXT;
//             strncpy( button_text[1], "Back", 9 );
//             choice2 = BUTTON_BACK;
//             break;
//         case DB_INSTALLCANCEL:
//             strncpy( button_text[0], "Install", 9 );
//             choice1 = BUTTON_INSTALL;
//             strncpy( button_text[1], "Cancel", 9 );
//             choice2 = BUTTON_CANCEL;
//             break;
//         case DB_OKCANCEL:
//             strncpy( button_text[0], "OK", 9 );
//             choice1 = BUTTON_OK;
//             strncpy( button_text[1], "Cancel", 9 );
//             choice2 = BUTTON_CANCEL;
//             break;
//         default:
//             strncpy( button_text[0], "OK", 9 );
//             choice1 = BUTTON_OK;
//             memset( button_text[1], '\0', 9 );
//     }

//     if ( disp_inited == 0 ) {
//         return BUTTON_CANCEL;
//     }

//     if ( m_mouse_inited ) {
//         msm_hidecursor();
//     }

//     unsigned short *scrnBuffer = new unsigned short[50*10];

//     disp_peekbox( scrnBuffer, Window->Coordinates().row, Window->Coordinates().column, Window->Coordinates().row + 7 + 1, Window->Coordinates().column + 44 + 1 ); // save current contents to buffer
//     disp_fillbox( 0 * 256 + ' ', Window->Coordinates().row + 1, Window->Coordinates().column + 1, Window->Coordinates().row + 7, Window->Coordinates().column + 44 + 1 ); // draw drop shadow
//     disp_box( Window->BorderStyle(), Window->Color().ToInt(), Window->Coordinates().row, Window->Coordinates().column, Window->Coordinates().row + 6, Window->Coordinates().column + 44 ); //draw popup
//     disp_fillbox( Window->Color().ToInt() * 256 + ' ', Window->Coordinates().row + 1, Window->Coordinates().column + 1, Window->Coordinates().row + 5, Window->Coordinates().column + 43 ); // fill popup box

//     if ( Button->Label() != NULL ) {
//         disp_setattr( Button->Color().ToInt() );
//         int centerColumn = ( strlen( Button->Label() ) + 44 ) / 2 - strlen( Button->Label() );
//         disp_move( Window->Coordinates().row + 2, Window->Coordinates().column + centerColumn );
//         disp_printf( "%s", Button->Label() );
//     }

//     if ( Choices == DB_OK ) {
//         //int center = ( ( 8 + 44 ) / 2 - 8 ) + 1;
//         disp_box( 5, Button->Color().ToInt(), Window->Coordinates().row + 4, Window->Coordinates().column + 17, Window->Coordinates().row + 4, Window->Coordinates().column + 25 );
//     }
//     else {
//         disp_box( 5, Button->Color().ToInt(), Window->Coordinates().row + 4, Window->Coordinates().column + 7, Window->Coordinates().row + 4, Window->Coordinates().column + 15 );
//         disp_box( 5, Button->Color().ToInt(), Window->Coordinates().row + 4, Window->Coordinates().column + 27, Window->Coordinates().row + 4, Window->Coordinates().column + 35 );
//     }

//     disp_setattr( Button->Color().ToInt() );

//     if ( Choices == DB_OKCANCEL ) {
//         disp_move( Window->Coordinates().row + 4, Window->Coordinates().column + 10 );
//         disp_puts( button_text[0] );
//         disp_move( Window->Coordinates().row + 4, Window->Coordinates().column + 28 );
//         disp_puts( button_text[1] );
//     }
//     else if ( Choices == DB_YESNO ) {
//         disp_move( Window->Coordinates().row + 4, Window->Coordinates().column + 10 );
//         disp_puts( button_text[0] );
//         disp_move( Window->Coordinates().row + 4, Window->Coordinates().column + 30 );
//         disp_puts( button_text[1] );
//     }
//     else if ( Choices == DB_NEXTBACK ) {
//         disp_move( Window->Coordinates().row + 4, Window->Coordinates().column + 9 );
//         disp_puts( button_text[0] );
//         disp_move( Window->Coordinates().row + 4, Window->Coordinates().column + 29 );
//         disp_puts( button_text[1] );
//     }
//     else if ( Choices == DB_INSTALLCANCEL ) {
//         disp_move( Window->Coordinates().row + 4, Window->Coordinates().column + 8 );
//         disp_puts( button_text[0] );
//         disp_move( Window->Coordinates().row + 4, Window->Coordinates().column + 28 );
//         disp_puts( button_text[1] );
//     }
//     else {
//         disp_move( Window->Coordinates().row + 4, Window->Coordinates().column + 20 );
//         disp_puts( button_text[0] );
//     }

//     disp_setattr( Window->Color().ToInt() );

//     if ( m_mouse_inited ) {
//         msm_showcursor();
//     }

//     do {
//         if ( m_mouse_inited ) {
//             static int mouse_status = -1;
//             static int old_mouse_status = -1;

//             mouse_status = msm_getstatus( &mouse_x, &mouse_y );

//             if ( (mouse_status & LEFT_BUTTON) && (mouse_status != old_mouse_status) ) {
//                 // multiply button positions by 8 to get mouse location
//                 if ( mouse_y == ( ( Window->Coordinates().row + 4 ) * 8 ) ) {
//                     if ( Choices == DB_OK ) {
//                         if ( mouse_x >= ( ( Window->Coordinates().column + 17 ) * 8 ) && mouse_x <= ( ( Window->Coordinates().column + 25 ) * 8 ) ) {
//                             selected_choice = choice1;
//                             break;
//                         }
//                     }
//                     else {
//                         if ( mouse_x >= ( ( Window->Coordinates().column + 7 ) * 8 ) && mouse_x <= ( ( Window->Coordinates().column + 15 ) * 8 ) ) {
//                             selected_choice = choice1;
//                             break;
//                         }
//                         if ( mouse_x >= ( ( Window->Coordinates().column + 27 ) * 8 ) && mouse_x <= ( ( Window->Coordinates().column + 35 ) * 8 ) ) {
//                             selected_choice = choice2;
//                             break;
//                         }
//                     }
//                 }
//             }

//             old_mouse_status = mouse_status;
//         }
//         if ( kbhit() ) {
//             static int kb_input = -1;
//             kb_input = getch();

//             if ( kb_input == 27 ) {
//                 selected_choice = BUTTON_CANCEL;
//                 break;
//             }
//             if ( Choices == DB_OK ) {
//                 if ( kb_input == 'O' || kb_input == 'o' || kb_input == 13 ) {
//                     selected_choice = BUTTON_OK;
//                     break;
//                 }
//             }
//             if ( Choices == DB_OKCANCEL ) {
//                 if ( kb_input == 'O' || kb_input == 'o' ) {
//                     selected_choice = BUTTON_OK;
//                     break;
//                 }
//                 else if ( kb_input == 'C' || kb_input == 'c' ) {
//                     selected_choice = BUTTON_CANCEL;
//                     break;
//                 }
//             }
//             if ( Choices == DB_YESNO ) {
//                 if ( kb_input == 'Y' || kb_input == 'y' ) {
//                     selected_choice = BUTTON_YES;
//                     break;
//                 }
//                 else if ( kb_input == 'N' || kb_input == 'n' ) {
//                     selected_choice = BUTTON_NO;
//                     break;
//                 }
//             }
//             if ( Choices == DB_NEXTBACK ) {
//                 if ( kb_input == 'N' || kb_input == 'n' ) {
//                     selected_choice = BUTTON_NEXT;
//                     break;
//                 }
//                 else if ( kb_input == 'B' || kb_input == 'b' ) {
//                     selected_choice = BUTTON_BACK;
//                     break;
//                 }
//             }
//             if ( Choices == DB_INSTALLCANCEL ) {
//                 if ( kb_input == 'I' || kb_input == 'i' ) {
//                     selected_choice = BUTTON_INSTALL;
//                     break;
//                 }
//                 else if ( kb_input == 'C' || kb_input == 'c' ) {
//                     selected_choice = BUTTON_CANCEL;
//                     break;
//                 }
//             }
//         }
//     } while ( 1 );

//     if ( m_mouse_inited ) {
//         msm_hidecursor();
//     }

//     disp_pokebox( scrnBuffer, Window->Coordinates().row, Window->Coordinates().column, Window->Coordinates().row + 7 + 1, Window->Coordinates().column + 44 + 1 );
//     delete[] scrnBuffer;

//     if ( m_mouse_inited ) {
//         msm_showcursor();
//     }

//     return selected_choice;
// }
