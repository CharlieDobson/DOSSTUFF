// implementation for DOSForms base class

#include "dosforms.hpp"
#include <disp.h>
#include <msmouse.h>
#include <stdlib.h>

boolean DOSForms::IsMouseEnabled = FALSE;

DOSForms::DOSForms( void )
{
    fg_color = FG_BLUE;
    bg_color = BG_WHITE;
}

DOSForms::DOSForms( const foreground_color_t foreground, const background_color_t background )
{
    fg_color = foreground;
    bg_color = background;
}

DOSForms::~DOSForms( void )
{
    // destructor code here
}

int DOSForms::ColorsToInt( void )
{
    return (int)( ( bg_color << 4 ) | fg_color );
}

void DOSForms::Draw( void )
{
    if ( disp_inited == 0 ) return;

    if ( IsMouseEnabled ) msm_hidecursor();

    disp_move( 0, 0 );
    disp_setattr( ColorsToInt() );
    disp_eeop();

    if ( IsMouseEnabled ) msm_showcursor();
}