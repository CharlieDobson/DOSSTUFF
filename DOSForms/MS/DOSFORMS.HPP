// dosforms.hpp : class definition file

#ifndef DOSFORMS_HPP
#define DOSFORMS_HPP 1

#ifdef _DOS
#if defined( _MSC_VER ) || defined( __WATCOMC__ )
#include <stdio.h>      // _getvideoconfig, _videoconfig
#include <conio.h>      // kbhit
#include <string.h>     // strlen, strcpy, memset
#include <graph.h>      // _getvideoconfig
#include <dos.h>
#include "structs.hpp"
#include "msmouse.hpp"
#include "button.hpp"
#include "message.hpp"

const unsigned short mouse_row_1 = 0;
const unsigned short mouse_row_2 = 8;
const unsigned short mouse_row_3 = mouse_row_2 * 2;
const unsigned short mouse_row_4 = mouse_row_2 * 3;
const unsigned short mouse_row_5 = mouse_row_2 * 4;
const unsigned short mouse_row_6 = mouse_row_2 * 5;
const unsigned short mouse_row_7 = mouse_row_2 * 6;
const unsigned short mouse_row_8 = mouse_row_2 * 7;
const unsigned short mouse_row_9 = mouse_row_2 * 8;
const unsigned short mouse_row_10 = mouse_row_2 * 9;
const unsigned short mouse_row_11 = mouse_row_2 * 10;
const unsigned short mouse_row_12 = mouse_row_2 * 11;
const unsigned short mouse_row_13 = mouse_row_2 * 12;
const unsigned short mouse_row_14 = mouse_row_2 * 13;
const unsigned short mouse_row_15 = mouse_row_2 * 14;
const unsigned short mouse_row_16 = mouse_row_2 * 15;
const unsigned short mouse_row_17 = mouse_row_2 * 16;
const unsigned short mouse_row_18 = mouse_row_2 * 17;
const unsigned short mouse_row_19 = mouse_row_2 * 18;
const unsigned short mouse_row_20 = mouse_row_2 * 19;
const unsigned short mouse_row_21 = mouse_row_2 * 20;
const unsigned short mouse_row_22 = mouse_row_2 * 21;
const unsigned short mouse_row_23 = mouse_row_2 * 22;
const unsigned short mouse_row_24 = mouse_row_2 * 23;
const unsigned short mouse_row_25 = mouse_row_2 * 24;
const unsigned short mouse_row_26 = mouse_row_2 * 25;
const unsigned short mouse_row_27 = mouse_row_2 * 26;
const unsigned short mouse_row_28 = mouse_row_2 * 27;
const unsigned short mouse_row_29 = mouse_row_2 * 28;
const unsigned short mouse_row_30 = mouse_row_2 * 29;
const unsigned short mouse_row_31 = mouse_row_2 * 30;
const unsigned short mouse_row_32 = mouse_row_2 * 31;
const unsigned short mouse_row_33 = mouse_row_2 * 32;
const unsigned short mouse_row_34 = mouse_row_2 * 33;
const unsigned short mouse_row_35 = mouse_row_2 * 34;
const unsigned short mouse_row_36 = mouse_row_2 * 35;
const unsigned short mouse_row_37 = mouse_row_2 * 36;
const unsigned short mouse_row_38 = mouse_row_2 * 37;
const unsigned short mouse_row_39 = mouse_row_2 * 38;
const unsigned short mouse_row_40 = mouse_row_2 * 39;
const unsigned short mouse_row_41 = mouse_row_2 * 40;
const unsigned short mouse_row_42 = mouse_row_2 * 41;
const unsigned short mouse_row_43 = mouse_row_2 * 42;
const unsigned short mouse_row_44 = mouse_row_2 * 43;
const unsigned short mouse_row_45 = mouse_row_2 * 44;
const unsigned short mouse_row_46 = mouse_row_2 * 45;
const unsigned short mouse_row_47 = mouse_row_2 * 46;
const unsigned short mouse_row_48 = mouse_row_2 * 47;
const unsigned short mouse_row_49 = mouse_row_2 * 48;
const unsigned short mouse_row_50 = mouse_row_2 * 49;

const unsigned short mouse_column_1 = 0;
const unsigned short mouse_column_2 = 8;
const unsigned short mouse_column_3 = mouse_column_2 * 2;
const unsigned short mouse_column_4 = mouse_column_2 * 3;
const unsigned short mouse_column_5 = mouse_column_2 * 4;
const unsigned short mouse_column_6 = mouse_column_2 * 5;
const unsigned short mouse_column_7 = mouse_column_2 * 6;
const unsigned short mouse_column_8 = mouse_column_2 * 7;
const unsigned short mouse_column_9 = mouse_column_2 * 8;
const unsigned short mouse_column_10 = mouse_column_2 * 9;
const unsigned short mouse_column_11 = mouse_column_2 * 10;
const unsigned short mouse_column_12 = mouse_column_2 * 11;
const unsigned short mouse_column_13 = mouse_column_2 * 12;
const unsigned short mouse_column_14 = mouse_column_2 * 13;
const unsigned short mouse_column_15 = mouse_column_2 * 14;
const unsigned short mouse_column_16 = mouse_column_2 * 15;
const unsigned short mouse_column_17 = mouse_column_2 * 16;
const unsigned short mouse_column_18 = mouse_column_2 * 17;
const unsigned short mouse_column_19 = mouse_column_2 * 18;
const unsigned short mouse_column_20 = mouse_column_2 * 19;
const unsigned short mouse_column_21 = mouse_column_2 * 20;
const unsigned short mouse_column_22 = mouse_column_2 * 21;
const unsigned short mouse_column_23 = mouse_column_2 * 22;
const unsigned short mouse_column_24 = mouse_column_2 * 23;
const unsigned short mouse_column_25 = mouse_column_2 * 24;
const unsigned short mouse_column_26 = mouse_column_2 * 25;
const unsigned short mouse_column_27 = mouse_column_2 * 26;
const unsigned short mouse_column_28 = mouse_column_2 * 27;
const unsigned short mouse_column_29 = mouse_column_2 * 28;
const unsigned short mouse_column_30 = mouse_column_2 * 29;
const unsigned short mouse_column_31 = mouse_column_2 * 30;
const unsigned short mouse_column_32 = mouse_column_2 * 31;
const unsigned short mouse_column_33 = mouse_column_2 * 32;
const unsigned short mouse_column_34 = mouse_column_2 * 33;
const unsigned short mouse_column_35 = mouse_column_2 * 34;
const unsigned short mouse_column_36 = mouse_column_2 * 35;
const unsigned short mouse_column_37 = mouse_column_2 * 36;
const unsigned short mouse_column_38 = mouse_column_2 * 37;
const unsigned short mouse_column_39 = mouse_column_2 * 38;
const unsigned short mouse_column_40 = mouse_column_2 * 39;
const unsigned short mouse_column_41 = mouse_column_2 * 40;
const unsigned short mouse_column_42 = mouse_column_2 * 41;
const unsigned short mouse_column_43 = mouse_column_2 * 42;
const unsigned short mouse_column_44 = mouse_column_2 * 43;
const unsigned short mouse_column_45 = mouse_column_2 * 44;
const unsigned short mouse_column_46 = mouse_column_2 * 45;
const unsigned short mouse_column_47 = mouse_column_2 * 46;
const unsigned short mouse_column_48 = mouse_column_2 * 47;
const unsigned short mouse_column_49 = mouse_column_2 * 48;
const unsigned short mouse_column_50 = mouse_column_2 * 49;
const unsigned short mouse_column_51 = mouse_column_2 * 50;
const unsigned short mouse_column_52 = mouse_column_2 * 51;
const unsigned short mouse_column_53 = mouse_column_2 * 52;
const unsigned short mouse_column_54 = mouse_column_2 * 53;
const unsigned short mouse_column_55 = mouse_column_2 * 54;
const unsigned short mouse_column_56 = mouse_column_2 * 55;
const unsigned short mouse_column_57 = mouse_column_2 * 56;
const unsigned short mouse_column_58 = mouse_column_2 * 57;
const unsigned short mouse_column_59 = mouse_column_2 * 58;
const unsigned short mouse_column_60 = mouse_column_2 * 59;
const unsigned short mouse_column_61 = mouse_column_2 * 60;
const unsigned short mouse_column_62 = mouse_column_2 * 61;
const unsigned short mouse_column_63 = mouse_column_2 * 62;
const unsigned short mouse_column_64 = mouse_column_2 * 63;
const unsigned short mouse_column_65 = mouse_column_2 * 64;
const unsigned short mouse_column_66 = mouse_column_2 * 65;
const unsigned short mouse_column_67 = mouse_column_2 * 66;
const unsigned short mouse_column_68 = mouse_column_2 * 67;
const unsigned short mouse_column_69 = mouse_column_2 * 68;
const unsigned short mouse_column_70 = mouse_column_2 * 69;
const unsigned short mouse_column_71 = mouse_column_2 * 70;
const unsigned short mouse_column_72 = mouse_column_2 * 71;
const unsigned short mouse_column_73 = mouse_column_2 * 72;
const unsigned short mouse_column_74 = mouse_column_2 * 73;
const unsigned short mouse_column_75 = mouse_column_2 * 74;
const unsigned short mouse_column_76 = mouse_column_2 * 75;
const unsigned short mouse_column_77 = mouse_column_2 * 76;
const unsigned short mouse_column_78 = mouse_column_2 * 77;
const unsigned short mouse_column_79 = mouse_column_2 * 78;
const unsigned short mouse_column_80 = mouse_column_2 * 79;

//static unsigned int mouse_x = 0, mouse_y = 0, mouse_status = -1, old_mouse_status = -1;

class DOSForms
{
    forms_colors_t m_form_color;
    forms_colors_t m_title_color;
    forms_colors_t m_status_bar_color;
    short m_old_display_mode;
    short m_text_columns;
    short m_text_rows;
    char *m_title_text;
    char *m_status_bar_text;
    char *m_screen_buffer;
    window_coordinates_t m_save_window;
    char *m_mouse_control;


    // private methods
    void ClearRow( const unsigned short row );
    unsigned short CenterScreen( const char* Text ) const;
    void SaveWindow( const short x, const short y, const short width, const short height );
    void RestoreWindow( void );

public:
    // constructors and destructor
    DOSForms( void );
    DOSForms( const forms_colors_t FormColor );
    DOSForms( const forms_colors_t FormColor, const forms_colors_t TitleColor, const char* TitleText );
    DOSForms( const forms_colors_t FormColor, const forms_colors_t TitleColor, const char* TitleText, const forms_colors_t StatusBarColor, const char* StatusBarText );
    ~DOSForms( void );

    // mouse class
    msmouse mouse;

    // accessors
    forms_colors_t FormColor( void ) const;
    forms_colors_t TitleColor( void ) const;
    forms_colors_t StatusBarColor( void ) const;
    char* TitleText( void ) const;
    char* StatusBarText( void ) const;

    // mutators
    void TitleColor( const forms_colors_t Color );
    void TitleText( const char* Text );
    void StatusBarColor( const forms_colors_t Color );
    void StatusBarText( const char* Text );

    // methods
    void OpenForm( void );
    void RemoveTitleBar( void );
    void RemoveStatusBar( void );
    void DrawButton( const FormButton button );
    //return_button_t MessageBox( const FormMessageWindow message );
    //short MessageBox( const Window window, const dialog_buttons_t Buttons, unsigned int ButtonColor ) const;
};

#endif // MSC or WATCOM
#endif // DOS
#endif // DOSFORMS_HPP