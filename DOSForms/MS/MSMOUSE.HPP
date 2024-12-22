// MSMOUSE.HPP : Microsoft Mouse definition file

#ifndef MSMOUSE_HPP
#define MSMOUSE_HPP 1

#ifndef _WINDOWS

#include <dos.h>		// REGS
#include <limits.h>     // integral limits
#if defined( _MSC_VER ) || defined( __WATCOMC__ )
#include <graph.h>      // graphics libraries
#elif __SC__
#include <disp.h>
#endif
#include "structs.hpp"
#ifdef _DEBUG
#include <stdio.h>		// puts
#endif

/* 
   The mouse coordinate system is left-handed for both text and graphics modes,
   with 0,0 being the upper left corner.  Note that the DOS graphics library starts at 1,1.

   x = column
   y = row

   Mouse values from interrupt 33 are in "mickeys".  To convert to view coordinates we must
   determine the number of columns.  For 40 column displays we divide mickeys by 16 and for
   80 column displays we divide by 8.  This is reflected throughout the code.
*/

const unsigned int LEFT_BUTTON = 1;
const unsigned int RIGHT_BUTTON = 2;
const unsigned int MIDDLE_BUTTON = 0;

class msmouse
{
    int m_inited;
    int m_cursor_hidden;
    unsigned int m_y_position;
    unsigned int m_x_position;
    unsigned int m_cols_max;

public:
    msmouse( void );
    ~msmouse( void );

	int IsInited( void ) const;
	int IsCursorHidden( void ) const;
    unsigned int xPosition( void ) const;
    unsigned int yPosition( void ) const;
    void CursorPosition( const unsigned int x, const unsigned int y );
    void ShowCursor( void );
    void HideCursor( void );
    int Status( void );
    int Status( unsigned int *x, unsigned int *y );
    int GetButtonPress( int *button, unsigned int *x_position, unsigned int *y_position );
    int GetButtonRelease( int *button, unsigned int *x_position, unsigned int *y_position );
    void SetAreax( const unsigned int min, const unsigned int max );
    void SetAreay( const unsigned int min, const unsigned int max );
    void SetArea( const unsigned int x_min, const unsigned int y_min, const unsigned int x_max, const unsigned int y_max );
    void ReadCounters( int *x, int *y );
    void MovementSpeed( const unsigned int x, const unsigned int y );
    void HidePointerInRegion( const unsigned int x_min, const unsigned int y_min, const unsigned int x_max, const unsigned int y_max );
};

#endif  // _WINDOWS
#endif  // MSMOUSE_HPP