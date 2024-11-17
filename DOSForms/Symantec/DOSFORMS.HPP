// dosforms.hpp : class definition file

#ifndef DOSFORMS_HPP
#define DOSFORMS_HPP 1

#if __SC__
#include <conio.h>      // kbhit
#include <string.h>     // strlen, strcpy, memset
#include <stdio.h>      // kbhit
#include <disp.h>       // disp
#include <msmouse.h>    // msm
#include "colors.h"
#include "window.hpp"

const unsigned short mouse_row_0 = 0;
const unsigned short mouse_row_1 = 8;
const unsigned short mouse_row_2 = mouse_row_1 * 2;
const unsigned short mouse_row_3 = mouse_row_1 * 3;
const unsigned short mouse_row_4 = mouse_row_1 * 4;
const unsigned short mouse_row_5 = mouse_row_1 * 5;
const unsigned short mouse_row_6 = mouse_row_1 * 6;
const unsigned short mouse_row_7 = mouse_row_1 * 7;
const unsigned short mouse_row_8 = mouse_row_1 * 8;
const unsigned short mouse_row_9 = mouse_row_1 * 9;
const unsigned short mouse_row_10 = mouse_row_1 * 10;
const unsigned short mouse_row_11 = mouse_row_1 * 11;
const unsigned short mouse_row_12 = mouse_row_1 * 12;
const unsigned short mouse_row_13 = mouse_row_1 * 13;
const unsigned short mouse_row_14 = mouse_row_1 * 14;
const unsigned short mouse_row_15 = mouse_row_1 * 15;
const unsigned short mouse_row_16 = mouse_row_1 * 16;
const unsigned short mouse_row_17 = mouse_row_1 * 17;
const unsigned short mouse_row_18 = mouse_row_1 * 18;
const unsigned short mouse_row_19 = mouse_row_1 * 19;
const unsigned short mouse_row_20 = mouse_row_1 * 20;
const unsigned short mouse_row_21 = mouse_row_1 * 21;
const unsigned short mouse_row_22 = mouse_row_1 * 22;
const unsigned short mouse_row_23 = mouse_row_1 * 23;
const unsigned short mouse_row_24 = mouse_row_1 * 24;
const unsigned short mouse_row_25 = mouse_row_1 * 25;

const unsigned short mouse_column_0 = 0;
const unsigned short mouse_column_1 = 8;
const unsigned short mouse_column_2 = mouse_column_1 * 2;
const unsigned short mouse_column_3 = mouse_column_1 * 3;
const unsigned short mouse_column_4 = mouse_column_1 * 4;
const unsigned short mouse_column_5 = mouse_column_1 * 5;
const unsigned short mouse_column_6 = mouse_column_1 * 6;
const unsigned short mouse_column_7 = mouse_column_1 * 7;
const unsigned short mouse_column_8 = mouse_column_1 * 8;
const unsigned short mouse_column_9 = mouse_column_1 * 9;
const unsigned short mouse_column_10 = mouse_column_1 * 10;
const unsigned short mouse_column_11 = mouse_column_1 * 11;
const unsigned short mouse_column_12 = mouse_column_1 * 12;
const unsigned short mouse_column_13 = mouse_column_1 * 13;
const unsigned short mouse_column_14 = mouse_column_1 * 14;
const unsigned short mouse_column_15 = mouse_column_1 * 15;
const unsigned short mouse_column_16 = mouse_column_1 * 16;
const unsigned short mouse_column_17 = mouse_column_1 * 17;
const unsigned short mouse_column_18 = mouse_column_1 * 18;
const unsigned short mouse_column_19 = mouse_column_1 * 19;
const unsigned short mouse_column_20 = mouse_column_1 * 20;
const unsigned short mouse_column_21 = mouse_column_1 * 21;
const unsigned short mouse_column_22 = mouse_column_1 * 22;
const unsigned short mouse_column_23 = mouse_column_1 * 23;
const unsigned short mouse_column_24 = mouse_column_1 * 24;
const unsigned short mouse_column_25 = mouse_column_1 * 25;
const unsigned short mouse_column_26 = mouse_column_1 * 26;
const unsigned short mouse_column_27 = mouse_column_1 * 27;
const unsigned short mouse_column_28 = mouse_column_1 * 28;
const unsigned short mouse_column_29 = mouse_column_1 * 29;
const unsigned short mouse_column_30 = mouse_column_1 * 30;
const unsigned short mouse_column_31 = mouse_column_1 * 31;
const unsigned short mouse_column_32 = mouse_column_1 * 32;
const unsigned short mouse_column_33 = mouse_column_1 * 33;
const unsigned short mouse_column_34 = mouse_column_1 * 34;
const unsigned short mouse_column_35 = mouse_column_1 * 35;
const unsigned short mouse_column_36 = mouse_column_1 * 36;
const unsigned short mouse_column_37 = mouse_column_1 * 37;
const unsigned short mouse_column_38 = mouse_column_1 * 38;
const unsigned short mouse_column_39 = mouse_column_1 * 39;
const unsigned short mouse_column_40 = mouse_column_1 * 40;
const unsigned short mouse_column_41 = mouse_column_1 * 41;
const unsigned short mouse_column_42 = mouse_column_1 * 42;
const unsigned short mouse_column_43 = mouse_column_1 * 43;
const unsigned short mouse_column_44 = mouse_column_1 * 44;
const unsigned short mouse_column_45 = mouse_column_1 * 45;
const unsigned short mouse_column_46 = mouse_column_1 * 46;
const unsigned short mouse_column_47 = mouse_column_1 * 47;
const unsigned short mouse_column_48 = mouse_column_1 * 48;
const unsigned short mouse_column_49 = mouse_column_1 * 49;
const unsigned short mouse_column_50 = mouse_column_1 * 50;
const unsigned short mouse_column_51 = mouse_column_1 * 51;
const unsigned short mouse_column_52 = mouse_column_1 * 52;
const unsigned short mouse_column_53 = mouse_column_1 * 53;
const unsigned short mouse_column_54 = mouse_column_1 * 54;
const unsigned short mouse_column_55 = mouse_column_1 * 55;
const unsigned short mouse_column_56 = mouse_column_1 * 56;
const unsigned short mouse_column_57 = mouse_column_1 * 57;
const unsigned short mouse_column_58 = mouse_column_1 * 58;
const unsigned short mouse_column_59 = mouse_column_1 * 59;
const unsigned short mouse_column_60 = mouse_column_1 * 60;
const unsigned short mouse_column_61 = mouse_column_1 * 61;
const unsigned short mouse_column_62 = mouse_column_1 * 62;
const unsigned short mouse_column_63 = mouse_column_1 * 63;
const unsigned short mouse_column_64 = mouse_column_1 * 64;
const unsigned short mouse_column_65 = mouse_column_1 * 65;
const unsigned short mouse_column_66 = mouse_column_1 * 66;
const unsigned short mouse_column_67 = mouse_column_1 * 67;
const unsigned short mouse_column_68 = mouse_column_1 * 68;
const unsigned short mouse_column_69 = mouse_column_1 * 69;
const unsigned short mouse_column_70 = mouse_column_1 * 70;
const unsigned short mouse_column_71 = mouse_column_1 * 71;
const unsigned short mouse_column_72 = mouse_column_1 * 72;
const unsigned short mouse_column_73 = mouse_column_1 * 73;
const unsigned short mouse_column_74 = mouse_column_1 * 74;
const unsigned short mouse_column_75 = mouse_column_1 * 75;
const unsigned short mouse_column_76 = mouse_column_1 * 76;
const unsigned short mouse_column_77 = mouse_column_1 * 77;
const unsigned short mouse_column_78 = mouse_column_1 * 78;
const unsigned short mouse_column_79 = mouse_column_1 * 79;
const unsigned short mouse_column_80 = mouse_column_1 * 80;


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
};

#pragma warning( default: 4091 )

#endif // SC
#endif // DOSFORMS_HPP