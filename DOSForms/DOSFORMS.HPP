// dosforms.hpp : class definition file

#ifndef DOSFORMS_HPP
#define DOSFORMS_HPP

#include <stdio.h> // _kbhit
#include <conio.h> // _kbhit
#include <string.h> // strlen, strcpy, memset
#ifdef __SC__
#include <disp.h>
#include <msmouse.h>
#include "..\colors.h"
#elif ( _MSC_VER || __WATCOMC__ )
#include <graph.h>
#include <dos.h>
#endif
#ifdef __WATCOMC__
#include <i86.h>
#endif
#include "window.hpp"


#ifdef __SC__
/*****************************************************************************************************
* Symantec C++ / Digital Mars C++ Class                                                              *
*****************************************************************************************************/

#pragma warning( disable: 4091 ) // don't show missing symbols

static unsigned int mouse_x = 0, mouse_y = 0;
const enum DIALOG_BUTTONS { BTN_OK = 1, BTN_OKCANCEL, BTN_YESNO, BTN_NEXTBACK, BTN_INSTALLCANCEL };

class DOSForms
{
    int old_display_attributes;
    short old_display_mode;

    short text_columns;
    short text_rows;
    char *title_text;
    char *status_bar_text;
    int is_mouse_enabled;
    unsigned int form_color;
    unsigned int title_color;
    unsigned int status_bar_color;
    unsigned short *screen_buffer;
    int is_screen_buffer_used;

    // private methods
    int ClearScreen( void );
    int ClearRow( const unsigned int row );
    unsigned int CenterScreen( const char* Text ) const;

  public:
    // constructors and destructor
    DOSForms( void );
    DOSForms( const unsigned int FormColor );
    DOSForms( const unsigned int FormColor, const unsigned int TitleColor, const char* szTitleText );
    DOSForms( const unsigned int FormColor, const unsigned int TitleColor, const char* szTitleText, const unsigned int StatusBarColor, const char* szStatusBarText );
    ~DOSForms( void );

    // accessors
    unsigned int FormColor( void ) const;
    unsigned int TitleColor( void ) const;
    char* TitleText( void ) const;
    unsigned int StatusBarColor( void ) const;
    char* StatusBarText( void ) const;

    // mutators
    void TitleColor( const unsigned int Color );
    void StatusBarColor( const unsigned int Color );
    void TitleText( const char* Text );
    void StatusBarText( const char* Text );

    // methods
    int IsMouseEnabled( void ) const;
    int RemoveTitleBar( void );
    int RemoveStatusBar( void );
    int OpenForm( void );
    int DrawButton( const Window window );
    int OpenPopupWindow( const Window window );
    int ClosePopupWindow( void );
    short MessageBox( const Window window, const DIALOG_BUTTONS Buttons, unsigned int ButtonColor ) const;
    //void ProgressBar( const Window window );
};

#pragma warning( default: 4091 )

#elif ( _MSC_VER || __WATCOMC__ )
/*****************************************************************************************************
* Microsoft C++ / Open Watcom C++ Class                                                              *
*****************************************************************************************************/

// bitmap for dialog_button
// binary   = int = button label(s)
// 00000001 =   1 = OK
// 00000010 =   2 = Cancel
// 00000011 =   3 = OK + Cancel

// 00000101 =   5 = Yes
// 00000110 =   6 = No
// 00000111 =   7 = Yes + No

// 00001001 =   9 = Next
// 00001010 =  10 = Back
// 00001011 =  11 = Next + Back

// 00010000 =  16 = Install
// 00010010 =  18 = Install + Cancel
const enum DIALOG_BUTTON { BTN_OK = 1, BTN_CANCEL, BTN_YES = 5, BTN_NO, BTN_NEXT = 9, BTN_BACK, BTN_INSTALL = 16 };
const enum TEXT_COLOR { T_BLACK = 0, T_BLUE, T_GREEN, T_CYAN, T_RED, T_MAGENTA, T_BROWN, T_WHITE, T_DARKGRAY, T_LIGHTBLUE, T_LIGHTGREEN, T_LIGHTCYAN, T_LIGHTRED, T_LIGHTMAGENTA, T_YELLOW, T_BRIGHTWHITE };
const enum BACKGROUND_COLOR { B_BLACK = 0L, B_BLUE, B_GREEN, B_CYAN, B_RED, B_MAGENTA, B_BROWN, B_WHITE };
static unsigned int mouse_x = 0;
static unsigned int mouse_y = 0;

class DOSForms
{
    short text_columns;
    short text_rows;
    short old_display_mode;
    short old_text_display;
    long old_background_display;
    short old_text_cursor;
    int is_display_inited;

    char* title_text;
    char* status_bar_text;
    short form_text_color;
    long form_background_color;
    short title_text_color;
    long title_background_color;
    short status_bar_text_color;
    long status_bar_background_color;

	int mouse_inited;
	int mouse_visible;
	int mouse_position_x;
	int mouse_position_y;

    // private methods
    void ClearScreen( void );
    void ClearRow( unsigned int row );
    unsigned int CenterScreen( char* Text ) const;

  public:
    DOSForms( void );
    DOSForms( const short FormTextColor, const long FormBackgroundColor );
    DOSForms( const short FormTextColor, const long FormBackgroundColor, const short TitleTextColor, const long TitleBackgroundColor, const char* TitleText );
    ~DOSForms( void );

    // accessors
    short FormTextColor( void ) const;
    long FormBackgroundColor( void ) const;
    short TitleTextColor( void ) const;
    long TitleBackgroundColor( void ) const;
    char* TitleText( void ) const;
    short StatusBarTextColor( void ) const;
    long StatusBarBackgroundColor( void ) const;
    char* StatusBarText( void ) const;

    // mutators
    void TitleTextColor( const short Color );
    void TitleBackgroundColor( const long Color );
    void TitleText( const char* Text );
    void StatusBarTextColor( const short Color );
    void StatusBarBackgroundColor( const long Color );
    void StatusBarText( const char* Text );

    // methods
    int OpenForm( void );
    void WriteLine( const short Row, const short Column, const char* Text );
    void RemoveTitleBar( void );
    void RemoveStatusBar( void );

    int DrawButton( const Window window );
    int OpenPopupWindow( const Window window );
    int ClosePopupWindow( void );
    DIALOG_BUTTON MessageBox( const Window& window, const DIALOG_BUTTON Buttons, unsigned int ButtonColor );
    //void ProgressBar( const Window window );

    int IsMouseEnabled( void ) const;
    void ShowMouse( void );
    void HideMouse( void );
    int MouseStatus( void );
    void MousePosition( const unsigned x, const unsigned y );
    int MousePress( unsigned button, unsigned x, unsigned y ) const;
    int MouseRelease( unsigned button, unsigned x, unsigned y ) const;
    void MouseAreaX( const unsigned min, const unsigned max );
    void MouseAreaY( const unsigned min, const unsigned max );
    void ReadMouseCounters( int x, int y );
};

#endif // end MS / OWC class

#endif // DOSFORMS_HPP