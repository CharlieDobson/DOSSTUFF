// STRUCTS.HPP : structures used by DOSForms

#ifndef STRUCTS_HPP
#define STRUCTS_HPP 1

#if defined( _MSC_VER ) || defined( __WATCOMC__ )

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

typedef enum extended_keyboard_scancodes_t
{
    _KB_F1 = 59,
    _KB_F2 = 60,
    _KB_F3 = 61,
    _KB_F4 = 62,
    _KB_F5 = 63,
    _KB_F6 = 64,
    _KB_F7 = 65,
    _KB_F8 = 66,
    _KB_F9 = 67,
    _KB_F10	= 68,

    _KB_HOME = 71,
    _KB_UP = 72,
    _KB_PGUP = 73,
    _KB_LEFT = 75,
    _KB_RIGHT = 77,
    _KB_END	= 79,
    _KB_DOWN = 80,
    _KB_PGDN = 81,
    _KB_INS	= 82,
    _KB_BACK_TAB = 15,

    _KB_SF1	= 84,
    _KB_SF2 = 85,
    _KB_SF3 = 86,
    _KB_SF4 = 87,
    _KB_SF5 = 88,
    _KB_SF6 = 89,
    _KB_SF7 = 90,
    _KB_SF8 = 91,
    _KB_SF9 = 92,
    _KB_SF10 = 93,

    _KB_CF1 = 94,
    _KB_CF2 = 95,
    _KB_CF3 = 96,
    _KB_CF4	= 97,
    _KB_CF5 = 98,
    _KB_CF6	= 99,
    _KB_CF7	= 100,
    _KB_CF8	= 101,
    _KB_CF9	= 102,
    _KB_CF10 = 103,

    _KB_AF1	= 104,
    _KB_AF2	= 105,
    _KB_AF3	= 106,
    _KB_AF4	= 107,
    _KB_AF5	= 108,
    _KB_AF6 = 109,
    _KB_AF7	= 110,
    _KB_AF8	= 111,
    _KB_AF9	= 112,
    _KB_AF10 = 113,

    _KB_DEL	= 83,
    _KB_CPGUP = 132,
    _KB_CLEFT = 115,
    _KB_CRIGHT = 116,
    _KB_CEND = 117,
    _KB_CPGDN = 118,
    _KB_CHOME = 119,
    _KB_A1 = 120,
    _KB_A2 = 121,
    _KB_A3 = 122,
    _KB_A4 = 123,
    _KB_A5 = 124,
    _KB_A6 = 125,
    _KB_A7 = 126,
    _KB_A8 = 127,
    _KB_A9 = 128,
    _KB_A0 = 129,
    _KB_AMINUS = 130,
    _KB_APLUS = 131
} extended_keyboard_scancodes;

#elif __SC__

enum foreground_colors_t
{
    FG_BLACK = 0,
    FG_BLUE = 1,
    FG_GREEN,
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
    FG_BRIGHT_WHITE
};

enum background_colors_t
{
    BG_BLACK = 0,
    BG_BLUE = 1,
    BG_GREEN,
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

struct videoconfig
{
    short numxpixels;
    short numypixels;
    short numtextcols;
    short numtextrows;
    short numcolors;
    short bitsperpixel;
    short numvideopages;
    short mode;
    short adapter;
    short monitor;
    short memory;
};

enum window_border_style_t
{
    BORDER_DOUBLE_LINE = 0,
    BORDER_SINGLE_LINE,
    BORDER_SOLID,
    BORDER_DOUBLE_HORIZONTAL_SINGLE_VERTICAL,
    BORDER_SINGLE_VERTICAL_DOUBLE_HORIZONTAL,
    BORDER_NONE
};

#endif

enum dialog_buttons_t
{
    DB_OK = 0,
    DB_OKCANCEL = 1,
    DB_YESNO,
    DB_NEXTBACK,
    DB_INSTALLCANCEL
};

enum button_t
{
    BUTTON_OK = 1,
    BUTTON_CANCEL = 2,
    BUTTON_YES,
    BUTTON_NO,
    BUTTON_NEXT,
    BUTTON_BACK,
    BUTTON_INSTALL
};

struct forms_colors_t
{
    foreground_colors_t foreground;
    background_colors_t background;
    #if __SC__
    int ToInt( void ) {
        return ( background << 4 ) | foreground;
    }
    #endif
};

struct window_coordinates_t
{
    short row;          // starting y position, a.k.a. the "top" side
    short column;       // starting x position, a.k.a. the "left" side
    short height;       // number of rows to span
    short width;        // number of columns to span
    short end_row;      // ending row number, should be equal to row + height, a.k.a. the "bottom" side
    short end_column;   // ending column number, should be equal to column + width, a.k.a. the "right" side
};

typedef enum boolean_t
{
    FALSE = ( 1 == 0 ),
    TRUE = ( !FALSE )
} boolean;

typedef enum keyboard_cursor_t
{
    HIDE = 0,
    SHOW
} keyboard_cursor;

#endif