#include "dosforms.hpp"

int main( int argc, char* argv[] )
{
    int kb_input = 0;
    short mouse_status = -1;
    short old_mouse_status = -1;
    forms_colors_t forms_colors;
    forms_colors.foreground = FG_BLUE;
    forms_colors.background = BG_WHITE;
    forms_colors_t title_colors;
    title_colors.foreground = FG_WHITE;
    title_colors.background = BG_BLUE;
    forms_colors_t status_bar;
    status_bar.foreground = FG_LIGHT_CYAN;
    status_bar.background = BG_CYAN;
    DOSForms app( forms_colors, title_colors, "Form Demo Title", status_bar, " Form Demo Status Bar Text" );
    FormButton button1( FG_LIGHT_CYAN, BG_CYAN, 5, 4, 10, 3, "Test" );

    app.OpenForm();
    app.DrawButton( button1 );

    while ( kb_input != 27 ) {
        if ( app.mouse.isInited() ) {

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