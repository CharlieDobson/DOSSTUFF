// DOSForms demonstration file

#include "dosforms.hpp"

int main( int argc, char* argv[] )
{
    int kb_input = 0;
    unsigned int mouse_x = 0, mouse_y = 0;

    DOSForms app;
    app.TitleColor( FG_WHITE, BG_BLUE );
    app.StatusBarColor( FG_LIGHT_CYAN, BG_CYAN );
    app.TitleText( "Form Demo Title" );
    app.StatusBarText( " Form Demo Status Bar - Press ESC to exit" );

    FormButton buttons[3] = {
        FormButton( FG_LIGHT_CYAN, BG_CYAN, 4, 10, 3, 12, "Button 1" ),
        FormButton( FG_LIGHT_CYAN, BG_CYAN, 10, 10, 3, 12, "Button 2" ),
        FormButton( FG_LIGHT_CYAN, BG_CYAN, 16, 10, 3, 12, "Button 3" )
    };

    app.OpenForm();

    if ( app.mouse.isInited() ) {
        app.mouse.showCursor();
    }

    for ( int i = 0; i < sizeof( buttons ) / sizeof( buttons[0] ); ++i ) {
        app.DrawButton( buttons[i] );
    }

    while ( kb_input != 27 ) {
        if ( app.mouse.isInited() ) {
            static int mouse_status = -1;
            static int old_mouse_status = -1;

            mouse_status = app.mouse.status();
            mouse_x = app.mouse.xPosition();
            mouse_y = app.mouse.yPosition();

            #ifdef _DEBUG
            static char buffer[21];
            sprintf( buffer, "Col: %2i, Row: %2i", app.mouse.xPosition(), app.mouse.yPosition() );
            _settextposition( 24, 3 );
            _settextcolor( FG_BLUE );
            _setbkcolor( BG_WHITE );
            _outtext( buffer );
            #endif

            if ( mouse_status != old_mouse_status ) {
                if ( mouse_status & LEFT_BUTTON ) {
                    if ( mouse_x == 1 && mouse_y == 0 ) {
                        break;
                    }
                }
            }

            old_mouse_status = mouse_status;
        }
        
        if ( kbhit() ) {
            kb_input = getch();

            if ( kb_input == 0 || kb_input == 0xE0 ) {
                kb_input = getch();
            }
        }
    }


    return 0;
}