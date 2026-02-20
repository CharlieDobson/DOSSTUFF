// Application class implementation file

#include "app.hpp"
#include <disp.h>               // Symantec display functions
#include <msmouse.h>            // Symantec mouse functions
#include <stdlib.h>             // required for NULL

Application::Application( void ) : DOSForms()
{
    fg_color = FG_BLUE;
    bg_color = BG_WHITE;
    IsMouseEnabled = FALSE;
}

Application::Application( const foreground_color_t foreground, const background_color_t background )
{
    fg_color = foreground;
    bg_color = background;
    IsMouseEnabled = FALSE;
}

Application::~Application( void )
{
    // destructor code here
}

int Application::ColorsToInt( void )
{
    return (int)( ( bg_color << 4 ) | fg_color );
}

void Application::Draw( void )
{
    if ( disp_inited == 0 ) return;

    if ( IsMouseEnabled ) msm_hidecursor();

    disp_move( 0, 0 );
    disp_setattr( ColorsToInt() );
    disp_eeop();

    if ( IsMouseEnabled ) msm_showcursor();
}
