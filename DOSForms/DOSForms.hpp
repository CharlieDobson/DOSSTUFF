// dosforms.hpp : class definition file

#ifndef DOSFORMS_H
#define DOSFORMS_H

#if __SC__ || __RCC__

#pragma warning( disable: 4091 ) // don't show missing symbols

#include <string.h>		// strlen, strcpy, memset
#include <stdio.h>      // _kbhit
#include <conio.h>      // _kbhit
#include <disp.h>
#include <msmouse.h>
#include "window.hpp"
#include "..\colors.h"

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


#define TITLE_MAX		35
#define STATUSBAR_MAX	( disp_numcols - 2 )

#define BTN_OK          1
#define BTN_OKCANCEL    2
#define BTN_YESNO       3
#define BTN_NEXTBACK    4
#define BTN_INSTALLCANCEL 5

static BOOL dosforms_inited = FALSE;
static unsigned int mouse_x = 0, mouse_y = 0;


class DOSForms
{
    BYTE OldDisplayMode;
	int OldDisplayAttributes;
    unsigned int formColor;
    unsigned int titleColor;
    unsigned int statusBarColor;
    unsigned short *ScreenBuffer;
    char *titleText;
    char *statusBarText;
    BOOL isMouseEnabled;
    BOOL screenBufferUsed;

    // private methods
    BOOL ClearScreen( void );
    BOOL ClearRow( const unsigned int row );
    unsigned int GetCenterScreen( const char *Text ) const;

  public:
    // constructors and destructors
    DOSForms( void );
    DOSForms( const unsigned int FormColor );
    DOSForms( const unsigned int FormColor, const unsigned int TitleColor, const char *TitleText );
    DOSForms( const unsigned int FormColor, const unsigned int TitleColor, const char *TitleText, const unsigned int StatusBarColor, const char *StatusBarText );
    ~DOSForms( void );

    // accessors
    BOOL IsMouseEnabled( void ) const { return isMouseEnabled; }
    unsigned int GetFormColor( void ) const { return formColor; }
    unsigned int GetTitleColor( void ) const { return titleColor; }
    unsigned int GetStatusBarColor( void ) const { return statusBarColor; }
    char *GetTitleText( void ) const { return titleText; }
    char *GetStatusBarText( void ) const { return statusBarText; }

    // mutators
    BOOL SetTitleColor( const unsigned int Color );
    BOOL SetStatusBarColor( const unsigned int Color );
    BOOL SetTitleText( const char *Text );
    BOOL SetStatusBarText( const char *Text );

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

#pragma warning( default: 4091 )

#endif // __SC__ || __RCC__

#endif // MENU_H
