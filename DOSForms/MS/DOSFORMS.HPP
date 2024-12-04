// dosforms.hpp : class definition file

#ifndef DOSFORMS_HPP
#define DOSFORMS_HPP 1

#ifdef _DOS
#if defined( _MSC_VER ) || defined( __WATCOMC__ )
#include <stdio.h>      // _getvideoconfig, _videoconfig
#include <conio.h>      // kbhit
#include <string.h>     // strlen, strcpy, memset
#include <dos.h>
#include <graph.h>      // _getvideoconfig
#include "structs.hpp"
#include "msmouse.hpp"
#include "button.hpp"
#include "message.hpp"


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

#endif // msc or watcom
#endif // DOS
#endif // DOSFORMS_HPP