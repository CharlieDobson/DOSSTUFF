// Application class implementation file

#include "app.hpp"
#include <disp.h>               // Symantec display functions
#include <msmouse.h>            // Symantec mouse functions

Application::Application( void ) : DOSForms( FG_BLUE, BG_WHITE )
{

}

Application::Application( const foreground_color_t foreground, const background_color_t background )
    : DOSForms( foreground, background )
{
    
}
