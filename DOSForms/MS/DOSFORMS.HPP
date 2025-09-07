// dosforms.hpp : class definition file

#ifndef DOSFORMS_HPP
#define DOSFORMS_HPP 1

#if defined( _MSC_VER ) || defined( __WATCOMC__ )

#include "memmod.hpp"
#include "msmouse.hpp"    // mouse functions
#include "structs.hpp"

static unsigned int mouse_x = 0, mouse_y = 0, old_mouse_x = 0, old_mouse_y = 0;
static int mouse_status = -1, old_mouse_status = -1;

class DOSForms
{
    forms_colors_t m_old_display_attributes;
    short m_old_display_mode;

    forms_colors_t m_forms_colors;
    forms_colors_t m_title_colors;
    forms_colors_t m_status_bar_colors;
    int m_text_columns;
    int m_text_rows;
    char PTR_TYPE* m_title_text;
    char PTR_TYPE* m_status_bar_text;
    char* m_mouse_control;
    boolean has_title_bar;
    boolean has_status_bar;

    // private methods
    unsigned int CenterScreen( const char PTR_TYPE* Text ) const;
    boolean SaveScreenRegion( forms_window_t& Window );
    boolean RestoreScreenRegion( forms_window_t& Window );

public:
    // constructors and destructor
    DOSForms( void );
    DOSForms( const foreground_colors_t FormForeground, const background_colors_t FormBackground );
    DOSForms( const foreground_colors_t FormForeground, const background_colors_t FormBackground,
            const foreground_colors_t TitleForeground, const background_colors_t TitleBackground, const char* TitleText );
    DOSForms( const foreground_colors_t FormForeground, const background_colors_t FormBackground,
            const foreground_colors_t TitleForeground, const background_colors_t TitleBackground,
            const char* TitleText, const foreground_colors_t StatusBarForeground, const background_colors_t StatusBarBackground );
    ~DOSForms( void );

    MSMouse mouse;

    // accessors
    forms_colors_t FormColor( void ) const;
    forms_colors_t TitleColor( void ) const;
    const char* TitleText( void ) const;
    forms_colors_t StatusBarColor( void ) const;
    const char* StatusBarText( void ) const;

    // mutators
    void TitleColor( const foreground_colors_t Foreground, const background_colors_t Background );
    void TitleText( const char PTR_TYPE* Text );
    void StatusBarColor( const foreground_colors_t Foreground, const background_colors_t Background );
    void StatusBarText( const char PTR_TYPE* Text );

    // methods
    void RemoveTitleBar( void );
    void RemoveStatusBar( void );
    void OpenForm( void );
    void DrawButton( const forms_button_t Button );
    boolean OpenWindow( forms_window_t& Window );
    boolean WriteToWindow( forms_window_t& Window, const short row, const char PTR_TYPE* Text );
    void CloseWindow( forms_window_t& Window );
    // button_return_value_t MessageBox( const forms_window_t Window, const forms_button_t Button, const dialog_buttons_t Choices );
    //void ProgressBar( const forms_window_t window );
};

#endif // end _MSC_VER || __WATCOMC__
#endif // DOSFORMS_HPP