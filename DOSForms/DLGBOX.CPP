// DlgBox class implementation file

#include "dlgbox.hpp"
#include <disp.h>               // Symantec display functions
#include <msmouse.h>            // Symantec mouse functions
#include <stdlib.h>             // required for NULL
#include <stdio.h>              // _snprintf
#include <string.h>             // strncpy
#include <conio.h>              // kbhit, getch
#include <ctype.h>              // toupper

DlgBox::DlgBox( const foreground_color_t foreground, const background_color_t background )
    : Popup( foreground, background )
{
    text_justification = CENTER;
    message[0] = '\0';
    buttons = DB_OK;
}

DlgBox::DlgBox( const foreground_color_t foreground, const background_color_t background, const char* message )
    : Popup( foreground, background )
{
    text_justification = CENTER;

    this->message[0] = '\0';
    if ( message && message[0] != '\0' ) {
        strncpy( this->message, message, sizeof( this->message ) - 1 );
        this->message[ sizeof( this->message ) - 1 ] = '\0';
    }

    buttons = DB_OK;
}

DlgBox::DlgBox( const foreground_color_t foreground, const background_color_t background, const dialog_buttons_t* buttons )
    : Popup( foreground, background )
{
    text_justification = CENTER;
    message[0] = '\0';

    this->buttons = DB_OK;
    if ( buttons ) {
        this->buttons = *buttons;
    }
}

DlgBox::DlgBox( const foreground_color_t foreground, const background_color_t background, const dialog_buttons_t* buttons, const char* message )
    : Popup( foreground, background )
{
    text_justification = CENTER;

    this->message[0] = '\0';
    if ( message && message[0] != '\0' ) {
        strncpy( this->message, message, sizeof( this->message ) - 1 );
        this->message[ sizeof( this->message ) - 1 ] = '\0';
    }

    this->buttons = DB_OK;
    if ( buttons ) {
        this->buttons = *buttons;
    }
}

void DlgBox::Draw( void )
{
    if ( disp_inited == 0 ) return;

    // let Popup draw the box, border, shadow, and title
    Popup::Draw();

    // nothing more to draw if no message
    if ( message[0] == '\0' ) return;

    if ( IsMouseEnabled ) msm_hidecursor();

    // calculate usable width inside the border
    short inner_width = coordinates.end_column - coordinates.column - 2;
    if ( inner_width < 1 ) inner_width = 1;

    // split message into lines that fit within the window, breaking at word boundaries
    const short MAX_LINES = 5;
    const short MAX_LINE_LEN = 60;
    char lines[MAX_LINES][MAX_LINE_LEN] = { {'\0'} };
    short line_count = 0;

    size_t msg_len = strlen( message );
    size_t pos = 0;
    short max_width = ( inner_width < MAX_LINE_LEN - 1 ) ? inner_width : MAX_LINE_LEN - 1;

    while ( pos < msg_len && line_count < MAX_LINES ) {
        size_t remaining = msg_len - pos;
        size_t chunk = remaining;

        if ( chunk > (size_t)max_width ) {
            chunk = (size_t)max_width;

            // look backward for a space to break at a word boundary
            size_t break_pos = chunk;
            while ( break_pos > 0 && message[pos + break_pos] != ' ' ) {
                --break_pos;
            }

            // if we found a space, break there; otherwise force break at max_width
            if ( break_pos > 0 ) {
                chunk = break_pos;
            }
        }

        strncpy( lines[line_count], message + pos, chunk );
        lines[line_count][chunk] = '\0';
        pos += chunk;

        // skip the space at the break point
        if ( pos < msg_len && message[pos] == ' ' ) {
            ++pos;
        }

        line_count++;
    }

    // vertically center the lines above the button area
    short inner_top = coordinates.row + 1;
    short button_area_top = coordinates.end_row - 4;
    short inner_height = button_area_top - inner_top;
    if ( inner_height < 1 ) inner_height = 1;
    short start_row = inner_top + ( inner_height - line_count ) / 2;
    if ( start_row < inner_top ) start_row = inner_top;

    disp_setattr( ColorsToInt() );

    for ( short i = 0; i < line_count; i++ ) {
        short len = (short)strlen( lines[i] );
        short col;

        switch ( text_justification ) {
            case CENTER:
                col = coordinates.column + 1 + ( inner_width - len ) / 2;
                break;
            case RIGHT:
                col = coordinates.end_column - 1 - len;
                break;
            case LEFT:
            default:
                col = coordinates.column + 2;
                break;
        }

        disp_move( start_row + i, col );
        disp_puts( lines[i] );
    }

    if ( IsMouseEnabled ) msm_showcursor();
}

button_return_value_t DlgBox::Show( void )
{
    if ( disp_inited == 0 ) return BUTTON_CANCEL;

    // draw the dialog box with message
    Draw();

    // determine button count and labels based on dialog type
    short button_count = 1;
    const char* button_labels[3] = { (const char*)0, (const char*)0, (const char*)0 };
    button_return_value_t button_values[3] = { BUTTON_OK, BUTTON_OK, BUTTON_OK };

    switch ( buttons ) {
        case DB_OK: {
            button_count = 1;
            button_labels[0] = "OK";
            button_values[0] = BUTTON_OK;
            break;
        }
        case DB_OKCANCEL: {
            button_count = 2;
            button_labels[0] = "OK";
            button_values[0] = BUTTON_OK;
            button_labels[1] = "Cancel";
            button_values[1] = BUTTON_CANCEL;
            break;
        }
        case DB_YESNO: {
            button_count = 2;
            button_labels[0] = "Yes";
            button_values[0] = BUTTON_YES;
            button_labels[1] = "No";
            button_values[1] = BUTTON_NO;
            break;
        }
        case DB_NEXTBACK: {
            button_count = 2;
            button_labels[0] = "Back";
            button_values[0] = BUTTON_BACK;
            button_labels[1] = "Next";
            button_values[1] = BUTTON_NEXT;
            break;
        }
        case DB_INSTALLCANCEL: {
            button_count = 2;
            button_labels[0] = "Install";
            button_values[0] = BUTTON_INSTALL;
            button_labels[1] = "Cancel";
            button_values[1] = BUTTON_CANCEL;
            break;
        }
        default: {
            button_count = 1;
            button_labels[0] = "OK";
            button_values[0] = BUTTON_OK;
            break;
        }
    }

    // create and position buttons at the bottom of the dialog
    Button dlg_buttons[3];
    short button_width = 12;    // fixed width for uniform look
    short button_row = coordinates.end_row - 4;
    short inner_width = coordinates.end_column - coordinates.column - 2;

    // calculate total width of all buttons with spacing
    short total_buttons_width = ( button_count * button_width ) + ( ( button_count - 1 ) * 2 );
    short start_column = coordinates.column + 1 + ( inner_width - total_buttons_width ) / 2;

    for ( short i = 0; i < button_count; ++i ) {
        dlg_buttons[i] = Button( FG_BLACK, BG_WHITE );
        dlg_buttons[i].IsMouseEnabled = IsMouseEnabled;
        dlg_buttons[i].drop_shadow = TRUE;
        strncpy( dlg_buttons[i].label, button_labels[i], sizeof( dlg_buttons[i].label ) - 1 );
        dlg_buttons[i].label[sizeof( dlg_buttons[i].label ) - 1] = '\0';
        dlg_buttons[i].SetCoordinates(
            button_row,
            start_column + ( i * ( button_width + 2 ) ),
            button_row + 2,
            start_column + ( i * ( button_width + 2 ) ) + button_width
        );
        dlg_buttons[i].Draw();
    }

    // modal input loop
    button_return_value_t result = button_values[0];
    int done = 0;

    while ( !done ) {
        // check mouse input
        if ( IsMouseEnabled ) {
            int mouse_status = -1;
            static int old_mouse_status = -1;
            unsigned mouse_x = 0;
            unsigned mouse_y = 0;

            mouse_status = msm_getstatus( &mouse_x, &mouse_y );
            mouse_x /= 8;
            mouse_y /= 8;

            if ( ( mouse_status & LEFT_BUTTON ) && ( mouse_status != old_mouse_status ) ) {
                for ( short i = 0; i < button_count; ++i ) {
                    if ( (short)mouse_y >= dlg_buttons[i].coordinates.row
                         && (short)mouse_y <= dlg_buttons[i].coordinates.end_row
                         && (short)mouse_x >= dlg_buttons[i].coordinates.column
                         && (short)mouse_x <= dlg_buttons[i].coordinates.end_column ) {
                        result = button_values[i];
                        done = 1;
                        break;
                    }
                }
            }

            old_mouse_status = mouse_status;
        }

        // check keyboard input
        if ( !done && kbhit() ) {
            int key = getch();
            int upper_key = toupper( key );

            // Enter always selects the first button
            if ( key == '\r' || key == '\n' ) {
                result = button_values[0];
                done = 1;
            }
            // Escape selects the last button (cancel/no/back)
            else if ( key == _KB_ESC ) {
                result = button_values[button_count - 1];
                done = 1;
            }
            else {
                // check first letter of each button label
                for ( short i = 0; i < button_count; ++i ) {
                    if ( button_labels[i] && upper_key == toupper( button_labels[i][0] ) ) {
                        result = button_values[i];
                        done = 1;
                        break;
                    }
                }
            }
        }
    } // end modal loop

    // restore screen
    RestoreWindow();

    return result;
}
