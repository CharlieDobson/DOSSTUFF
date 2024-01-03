// dosforms.hpp : class definition file

#ifndef DOSFORMS_H
#define DOSFORMS_H

#pragma warning( disable: 4091 ) // don't show missing symbols

#include <string.h>		// strlen, strcpy, memset
#include <stdio.h>      // _kbhit
#include <conio.h>      // _kbhit
#ifdef __SC__
#include <disp.h>
#include <msmouse.h>
#else
#include <graph.h>
#include "msmouse.hpp"
#endif
#include "window.hpp"
#include "..\colors.h"

#ifndef _INC_WINDOWS
#ifndef BOOL
typedef int				BOOL;
#endif
#ifndef BYTE
typedef unsigned char	BYTE;
#endif
#ifndef FALSE
#define FALSE			0
#endif
#ifndef TRUE
#define TRUE			!FALSE
#endif
#endif // _INC_WINDOWS

static unsigned int mouse_x = 0, mouse_y = 0;

#ifdef __SC__
const BYTE BTN_OK = 1;
const BYTE BTN_OKCANCEL = 2;
const BYTE BTN_YESNO = 3;
const BYTE BTN_NEXTBACK = 4;
const BYTE BTN_INSTALLCANCEL = 5;

class DOSForms
{
    short numTextCols;
    short numTextRows;
	int oldDisplayAttributes;
    unsigned int formColor;
    unsigned int titleColor;
    unsigned int statusBarColor;
    short oldDisplayMode;
    unsigned short *screenBuffer;
    char *titleText;
    char *statusBarText;
    BOOL isMouseEnabled;
    BOOL screenBufferUsed;

    // private methods
    BOOL ClearScreen( void );
    BOOL ClearRow( const unsigned int row );
    unsigned int CenterScreen( const char *Text ) const;

  public:
    // constructors and destructors
    DOSForms( void );
    DOSForms( const unsigned int FormColor );
    DOSForms( const unsigned int FormColor, const unsigned int TitleColor, const char *szTitleText );
    DOSForms( const unsigned int FormColor, const unsigned int TitleColor, const char *szTitleText, const unsigned int StatusBarColor, const char *szStatusBarText );
    ~DOSForms( void );

    // accessors
    BOOL IsMouseEnabled( void ) const;
    unsigned int FormColor( void ) const { return formColor; }
    unsigned int TitleColor( void ) const { return titleColor; }
    unsigned int StatusBarColor( void ) const { return statusBarColor; }
    char *TitleText( void ) const;
    char *StatusBarText( void ) const;

    // mutators
    BOOL TitleColor( const unsigned int Color );
    BOOL StatusBarColor( const unsigned int Color );
    BOOL TitleText( const char *Text );
    BOOL StatusBarText( const char *Text );

    // methods
    BOOL RemoveTitleBar( void );
    BOOL RemoveStatusBar( void );
    BOOL OpenForm( void );
    BOOL DrawButton( const Window window );
    BOOL OpenPopupWindow( const Window window );
    BOOL ClosePopupWindow( void );
    BYTE MessageBox( const Window window );
    BYTE MessageBox( const Window window, const BYTE Buttons, unsigned int ButtonColor ) const;
    //void ProgressBar( const Window window );
};
#else // __SC__
class DOSForms
{
	short numTextCols;
	short numTextRows;
	BOOL dispInited;
    short oldDisplayMode;
	short oldTextDisplay;
	long oldBackgroundDisplay;
	short formTextColor;
	long formBackgroundColor;
	short titleTextColor;
	long titleBackgroundColor;
	short statusBarTextColor;
	long statusBarBackgroundColor;
    unsigned short *screenBuffer;
    char *titleText;
    char *statusBarText;
    BOOL screenBufferUsed;
    MSMouse mouse;
    BOOL isMouseEnabled;

    // private methods
    //BOOL ClearScreen( void );
    //BOOL ClearRow( const unsigned int row );
    unsigned int CenterScreen( const char *Text ) const;

  public:
    DOSForms( void );
    DOSForms( const short FormTextColor, const long FormBackgroundColor );
    DOSForms( const short FormTextColor, const long FormBackgroundColor, const short TitleTextColor, const long TitleBackgroundColor, const char *TitleText );
    ~DOSForms( void );

	enum _MB_BUTTONS { BTN_OK = 1, BTN_OKCANCEL, BTN_YESNO, BTN_NEXTBACK, BTN_INSTALLCANCEL } MBButtons;

    // accessors
    BOOL IsMouseEnabled( void ) const;
    short FormTextColor( void ) const;
    long FormBackgroundColor( void ) const;
    short TitleTextColor( void ) const;
    long TitleBackgroundColor( void ) const;
    short StatusBarTextColor( void ) const;
    long StatusBarBackgroundColor( void ) const;
    char *TitleText( void ) const;
    char *StatusBarText( void ) const;

    // mutators
    BOOL TitleTextColor( const short Color );
    BOOL TitleBackgroundColor( const long Color );
    BOOL StatusBarTextColor( const short Color );
    BOOL StatusBarBackgroundColor( const long Color );
    BOOL TitleText( const char *Text );
    BOOL StatusBarText( const char *Text );

    // methods
    //BOOL RemoveTitleBar( void );
    //BOOL RemoveStatusBar( void );
    BOOL OpenForm( void );
    //BOOL DrawButton( const Window window );
    //BOOL OpenPopupWindow( const Window window );
    //BOOL ClosePopupWindow( void );
    //BYTE MessageBox( const Window window );
    //BYTE MessageBox( const Window window, const BYTE Buttons, unsigned int ButtonColor ) const;
    //void ProgressBar( const Window window );
};
#endif // __SC__

#pragma warning( default: 4091 )

#endif // DOSFORMS_H