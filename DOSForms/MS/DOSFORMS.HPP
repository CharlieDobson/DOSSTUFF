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

/*
const unsigned int mouse_row_1 = 0;
const unsigned int mouse_row_2 = 8;
const unsigned int mouse_row_3 = 16;
const unsigned int mouse_row_4 = 24;
const unsigned int mouse_row_5 = 32;
const unsigned int mouse_row_6 = 40;
const unsigned int mouse_row_7 = 48;
const unsigned int mouse_row_8 = 56;
const unsigned int mouse_row_9 = 64;
const unsigned int mouse_row_10 = 72;
const unsigned int mouse_row_11 = 80;
const unsigned int mouse_row_12 = 88;
const unsigned int mouse_row_13 = 96;
const unsigned int mouse_row_14 = 104;
const unsigned int mouse_row_15 = 112;
const unsigned int mouse_row_16 = 120;
const unsigned int mouse_row_17 = 128;
const unsigned int mouse_row_18 = 136;
const unsigned int mouse_row_19 = 144;
const unsigned int mouse_row_20 = 152;
const unsigned int mouse_row_21 = 160;
const unsigned int mouse_row_22 = 168;
const unsigned int mouse_row_23 = 176;
const unsigned int mouse_row_24 = 184;
const unsigned int mouse_row_25 = 192;
const unsigned int mouse_row_26 = 200;
const unsigned int mouse_row_27 = 208;
const unsigned int mouse_row_28 = 216;
const unsigned int mouse_row_29 = 224;
const unsigned int mouse_row_30 = 232;
const unsigned int mouse_row_31 = 240;
const unsigned int mouse_row_32 = 248;
const unsigned int mouse_row_33 = 256;
const unsigned int mouse_row_34 = 264;
const unsigned int mouse_row_35 = 272;
const unsigned int mouse_row_36 = 280;
const unsigned int mouse_row_37 = 288;
const unsigned int mouse_row_38 = 296;
const unsigned int mouse_row_39 = 304;
const unsigned int mouse_row_40 = 312;
const unsigned int mouse_row_41 = 320;
const unsigned int mouse_row_42 = 328;
const unsigned int mouse_row_43 = 336;
const unsigned int mouse_row_44 = 344;
const unsigned int mouse_row_45 = 352;
const unsigned int mouse_row_46 = 360;
const unsigned int mouse_row_47 = 368;
const unsigned int mouse_row_48 = 376;
const unsigned int mouse_row_49 = 384;
const unsigned int mouse_row_50 = 392;

const unsigned int mouse_column_1 = 0;
const unsigned int mouse_column_2 = 8;
const unsigned int mouse_column_3 = 16;
const unsigned int mouse_column_4 = 24;
const unsigned int mouse_column_5 = 32;
const unsigned int mouse_column_6 = 40;
const unsigned int mouse_column_7 = 48;
const unsigned int mouse_column_8 = 56;
const unsigned int mouse_column_9 = 64;
const unsigned int mouse_column_10 = 72;
const unsigned int mouse_column_11 = 80;
const unsigned int mouse_column_12 = 88;
const unsigned int mouse_column_13 = 96;
const unsigned int mouse_column_14 = 104;
const unsigned int mouse_column_15 = 112;
const unsigned int mouse_column_16 = 120;
const unsigned int mouse_column_17 = 128;
const unsigned int mouse_column_18 = 136;
const unsigned int mouse_column_19 = 144;
const unsigned int mouse_column_20 = 152;
const unsigned int mouse_column_21 = 160;
const unsigned int mouse_column_22 = 168;
const unsigned int mouse_column_23 = 176;
const unsigned int mouse_column_24 = 184;
const unsigned int mouse_column_25 = 192;
const unsigned int mouse_column_26 = 200;
const unsigned int mouse_column_27 = 208;
const unsigned int mouse_column_28 = 216;
const unsigned int mouse_column_29 = 224;
const unsigned int mouse_column_30 = 232;
const unsigned int mouse_column_31 = 240;
const unsigned int mouse_column_32 = 248;
const unsigned int mouse_column_33 = 256;
const unsigned int mouse_column_34 = 264;
const unsigned int mouse_column_35 = 272;
const unsigned int mouse_column_36 = 280;
const unsigned int mouse_column_37 = 288;
const unsigned int mouse_column_38 = 296;
const unsigned int mouse_column_39 = 304;
const unsigned int mouse_column_40 = 312;
const unsigned int mouse_column_41 = 320;
const unsigned int mouse_column_42 = 328;
const unsigned int mouse_column_43 = 336;
const unsigned int mouse_column_44 = 344;
const unsigned int mouse_column_45 = 352;
const unsigned int mouse_column_46 = 360;
const unsigned int mouse_column_47 = 368;
const unsigned int mouse_column_48 = 376;
const unsigned int mouse_column_49 = 384;
const unsigned int mouse_column_50 = 392;
const unsigned int mouse_column_51 = 400;
const unsigned int mouse_column_52 = 408;
const unsigned int mouse_column_53 = 416;
const unsigned int mouse_column_54 = 424;
const unsigned int mouse_column_55 = 432;
const unsigned int mouse_column_56 = 440;
const unsigned int mouse_column_57 = 448;
const unsigned int mouse_column_58 = 456;
const unsigned int mouse_column_59 = 464;
const unsigned int mouse_column_60 = 472;
const unsigned int mouse_column_61 = 480;
const unsigned int mouse_column_62 = 488;
const unsigned int mouse_column_63 = 496;
const unsigned int mouse_column_64 = 504;
const unsigned int mouse_column_65 = 512;
const unsigned int mouse_column_66 = 520;
const unsigned int mouse_column_67 = 528;
const unsigned int mouse_column_68 = 536;
const unsigned int mouse_column_69 = 544;
const unsigned int mouse_column_70 = 552;
const unsigned int mouse_column_71 = 560;
const unsigned int mouse_column_72 = 568;
const unsigned int mouse_column_73 = 576;
const unsigned int mouse_column_74 = 584;
const unsigned int mouse_column_75 = 592;
const unsigned int mouse_column_76 = 600;
const unsigned int mouse_column_77 = 608;
const unsigned int mouse_column_78 = 616;
const unsigned int mouse_column_79 = 624;
const unsigned int mouse_column_80 = 630;
*/

class DOSForms
{
    boolean isFormOpen;
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
    void SaveWindow( const window_coordinates_t coordinates );
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
    void TitleColor( const foreground_colors_t foreground, const background_colors_t background );
    void TitleText( const char* Text );
    void StatusBarColor( const forms_colors_t Color );
    void StatusBarColor( const foreground_colors_t foreground, const background_colors_t background );
    void StatusBarText( const char* Text );

    // methods
    void OpenForm( void );
    void RemoveTitleBar( void );
    void RemoveStatusBar( void );
    void DrawButton( const FormButton button );
    //button_t MessageBox( const FormMessage message );
};

#endif // MSC or WATCOM
#endif // DOS
#endif // DOSFORMS_HPP