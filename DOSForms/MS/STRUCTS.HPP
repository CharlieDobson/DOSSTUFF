// STRUCTS.HPP : structures used by DOSForms

#ifndef STRUCTS_HPP
#define STRUCTS_HPP 1

#if defined( _MSC_VER ) || defined( __WATCOMC__ )

enum dialog_buttons_t
{
    DB_OK = 0,
    DB_OKCANCEL = 1,
    DB_YESNO,
    DB_NEXTBACK,
    DB_INSTALLCANCEL
};

enum return_button_t
{
    BUTTON_OK = 1,
    BUTTON_CANCEL = 2,
    BUTTON_YES,
    BUTTON_NO,
    BUTTON_NEXT,
    BUTTON_BACK,
    BUTTON_INSTALL
};

enum foreground_colors_t
{ 
    FG_NO_COLOR = -1,
    FG_BLACK = 0,
    FG_BLUE = 1,
    FG_GREEN = 2,
    FG_CYAN,
    FG_RED,
    FG_MAGENTA,
    FG_BROWN,
    FG_WHITE,
    FG_DARK_GRAY,
    FG_LIGHT_BLUE,
    FG_LIGHT_GREEN,
    FG_LIGHT_CYAN,
    FG_LIGHT_RED,
    FG_LIGHT_MAGENTA,
    FG_YELLOW,
    FG_BRIGHT_WHITE,
    FG_BLINK_BLACK,
    FG_BLINK_BLUE,
    FG_BLINK_GREEN,
    FG_BLINK_CYAN,
    FG_BLINK_RED,
    FG_BLINK_MAGENTA,
    FG_BLINK_BROWN,
    FG_BLINK_WHITE,
    FG_BLINK_DARK_GRAY,
    FG_BLINK_LIGHT_BLUE,
    FG_BLINK_LIGHT_GREEN,
    FG_BLINK_LIGHT_CYAN,
    FG_BLINK_LIGHT_RED,
    FG_BLINK_LIGHT_MAGENTA,
    FG_BLINK_YELLOW,
    FG_BLINK_BRIGHT_WHITE
};

enum background_colors_t
{
    BG_NO_COLOR = -1L,
    BG_BLACK = 0L,
    BG_BLUE = 1L,
    BG_GREEN = 2L,
    BG_CYAN,
    BG_RED,
    BG_MAGENTA,
    BG_BROWN,
    BG_WHITE,
    BG_DARK_GRAY,
    BG_LIGHT_BLUE,
    BG_LIGHT_GREEN,
    BG_LIGHT_CYAN,
    BG_LIGHT_RED,
    BG_LIGHT_MAGENTA,
    BG_YELLOW,
    BG_BRIGHT_WHITE
};

struct forms_colors_t
{
    foreground_colors_t foreground;
    background_colors_t background;
};

struct window_coordinates_t
{
    short column;       // x position
    short row;          // y position
    short width;        // number of columns to span
    short height;       // number of rows to span
    short end_column;   // ending column number, should be equal to column + width
    short end_row;      // ending row number, should be equal to row + height
};

#endif
#endif