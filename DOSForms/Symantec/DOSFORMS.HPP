// dosforms.hpp : class definition file

#ifndef DOSFORMS_HPP
#define DOSFORMS_HPP 1

#ifdef __SC__

#include <conio.h>      // kbhit
#include <string.h>     // strlen, strcpy, memset
#include <stdio.h>      // kbhit
#include <disp.h>       // disp
#include <msmouse.h>    // mouse functions
#include "window.hpp"
#include "button.hpp"
#include "structs.hpp"

static unsigned int mouse_x = 0, mouse_y = 0;

class DOSForms
{
    int m_old_display_attributes;
    short m_old_display_mode;

    forms_colors_t m_forms_colors;
    forms_colors_t m_title_colors;
    forms_colors_t m_status_bar_colors;
    int m_text_columns;
    int m_text_rows;
    char *m_title_text;
    char *m_status_bar_text;
    unsigned short *m_screen_buffer;
    char *m_mouse_control;
    int is_screen_buffer_used;
    int m_mouse_inited;
    boolean has_title_bar;
    boolean has_status_bar;

    // private methods
    void ClearScreen( void );
    void ClearRow( const unsigned int row );
    unsigned int CenterScreen( const char* Text ) const;

public:
    // constructors and destructor
    DOSForms( void );
    DOSForms( const foreground_colors_t FormForeground, const background_colors_t FormBackground );
    DOSForms( const foreground_colors_t FormForeground, const background_colors_t FormBackground, const foreground_colors_t TitleForeground, const background_colors_t TitleBackground, const char* TitleText );
    DOSForms( const foreground_colors_t FormForeground, const background_colors_t FormBackground, const foreground_colors_t TitleForeground, const background_colors_t TitleBackground, const char* TitleText, const foreground_colors_t StatusBarForeground, const background_colors_t StatusBarBackground );
    ~DOSForms( void );

    // accessors
    int IsMouseEnabled( void );
    const forms_colors_t FormColor( void ) const;
    const forms_colors_t TitleColor( void ) const;
    const char* TitleText( void ) const;
    const forms_colors_t StatusBarColor( void ) const;
    const char* StatusBarText( void ) const;

    // mutators
    void TitleColor( const foreground_colors_t Foreground, const background_colors_t Background );
    void TitleText( const char* Text );
    void StatusBarColor( const foreground_colors_t Foreground, const background_colors_t Background );
    void StatusBarText( const char* Text );

    // methods
    void RemoveTitleBar( void );
    void RemoveStatusBar( void );
    void OpenForm( void );
    void DrawButton( const FormButton* Button );
    boolean OpenWindow( const Window* Window );
    void CloseWindow( void );
    const button_t MessageBox( const Window* window, const FormButton* Button, const dialog_buttons_t Choices ) const;
    //void ProgressBar( const Window window );
};

#endif // end __SC__
#endif // DOSFORMS_HPP