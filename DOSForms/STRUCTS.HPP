// STRUCTS.HPP : structures used by DOSForms

#ifndef STRUCTS_HPP
#define STRUCTS_HPP 1

#ifndef _MAX_PATH
#define _MAX_PATH   260 /* max. length of full pathname */
#endif
#ifndef _MAX_DRIVE
#define _MAX_DRIVE  3   /* max. length of drive component */
#endif
#ifndef _MAX_DIR
#define _MAX_DIR    256 /* max. length of path component */
#endif
#ifndef _MAX_FNAME
#define _MAX_FNAME  256 /* max. length of file name component */
#endif
#ifndef _MAX_EXT
#define _MAX_EXT    256 /* max. length of extension component */
#endif

#if defined( _MSC_VER ) || defined( __WATCOMC__ )

typedef enum
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
} foreground_color_t;

typedef enum
{
    BG_BLACK = 0L,
    BG_BLUE = 1L,
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
} background_color_t;

typedef enum
{
    _KB_ESC = 27,

    _KB_F1 = 59,
    _KB_F2 = 60,
    _KB_F3 = 61,
    _KB_F4 = 62,
    _KB_F5 = 63,
    _KB_F6 = 64,
    _KB_F7 = 65,
    _KB_F8 = 66,
    _KB_F9 = 67,
    _KB_F10 = 68,

    _KB_HOME = 71,
    _KB_UP = 72,
    _KB_PGUP = 73,
    _KB_LEFT = 75,
    _KB_RIGHT = 77,
    _KB_END = 79,
    _KB_DOWN = 80,
    _KB_PGDN = 81,
    _KB_INS = 82,
    _KB_BACK_TAB = 15,

    _KB_SF1 = 84,
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
    _KB_CF4 = 97,
    _KB_CF5 = 98,
    _KB_CF6 = 99,
    _KB_CF7 = 100,
    _KB_CF8 = 101,
    _KB_CF9 = 102,
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
} extended_keyboard_scancodes_t;

#elif defined( __SC__ )

typedef enum
{
    FG_BLACK = 0,
    FG_BLUE,
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
} foreground_color_t;

typedef enum
{
    BG_BLACK = 0,
    BG_BLUE,
    BG_GREEN,
    BG_CYAN,
    BG_RED,
    BG_MAGENTA,
    BG_BROWN,
    BG_WHITE
    /* BG_DARK_GRAY,
    BG_LIGHT_BLUE,
    BG_LIGHT_GREEN,
    BG_LIGHT_CYAN,
    BG_LIGHT_RED,
    BG_LIGHT_MAGENTA,
    BG_YELLOW,
    BG_BRIGHT_WHITE */
} background_color_t;

typedef struct
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
} videoconfig_t;

#endif

typedef enum
{
    BORDER_DOUBLE_LINE = 0,
    BORDER_SINGLE_LINE,
    BORDER_SOLID,
    BORDER_DOUBLE_HORIZONTAL_SINGLE_VERTICAL,
    BORDER_SINGLE_VERTICAL_DOUBLE_HORIZONTAL,
    BORDER_NONE
} border_style_t;

typedef enum
{
    DB_OK = 0,
    DB_OKCANCEL,
    DB_YESNO,
    DB_NEXTBACK,
    DB_INSTALLCANCEL
} dialog_buttons_t;

typedef enum
{
    BUTTON_OK = 1,
    BUTTON_CANCEL,
    BUTTON_YES,
    BUTTON_NO,
    BUTTON_NEXT,
    BUTTON_BACK,
    BUTTON_INSTALL
} button_return_value_t;

typedef struct
{
    foreground_color_t foreground;
    background_color_t background;
    #if defined( __SC__ )
    const int ToInt( void ) const {
        return (int)( ( background << 4 ) | foreground );
    }
    #endif
} forms_colors_t;

typedef struct
{
    short row;          // starting y position, a.k.a. the "top" side
    short column;       // starting x position, a.k.a. the "left" side
    short end_row;      // ending row number, a.k.a. the "bottom" side
    short end_column;   // ending column number, a.k.a. the "right" side
} coordinates_t;

typedef enum
{
    FALSE = ( 1 == 0 ),
    TRUE = ( !FALSE )
} boolean;

typedef struct
{
    forms_colors_t color;
    coordinates_t coordinates;
    char label[16];
    boolean drop_shadow;
} forms_button_t;

typedef enum
{
    LEFT,
    CENTER,
    RIGHT
} text_justify_t;

typedef struct
{
    forms_colors_t color;
    coordinates_t coordinates;
    border_style_t border_style; // border style for the window
    struct screen_buffer_t {
        char character;  // character to display in the window
        char attribute;  // attribute for the character (color, etc.)
    } far* buffer;         // screen buffer to save the contents of the window
    char title[35];       // title text for the window
    enum justify_t {
        LEFT = 'L',
        CENTER = 'C',
        RIGHT = 'R'
    } justify;       // title justification, 'L' for left (default), 'C' for center
    boolean drop_shadow; // if TRUE, draw a drop shadow below and to the right of the window
} forms_window_t;

typedef enum
{
    SHOW = 0x0607,
    HIDE = 0x2607
} keyboard_cursor_t;

typedef struct filepath_t
{
	char drive[_MAX_DRIVE];
	char directory[_MAX_DIR];
	char name[_MAX_FNAME];
	char extension[_MAX_EXT];
} filepath_t;

typedef union filetime_t {
    unsigned int f_time;
    struct {
        unsigned int seconds:5,
        minute:6,
        hour:5;
    } bits;
} filetime_t;

typedef union filedate_t {
    unsigned int f_date;
    struct {
        unsigned int day:5,
        month:4,
        year:7;
    } bits;
} filedate_t;

typedef struct fileinfo_t
{
    filepath_t path;
    filedate_t date;
    filetime_t time;
	char attrib;
    unsigned long size;
} fileinfo_t;

// the following structure can be
// populated by calling intdosx
//
// REGS regs;
// SREGS sregs;
// countryinfo_t country;
// regs.x.ax = 0x3800;
// sregs.ds = FP_SEG( &country );
// regs.x.dx = FP_OFF( &country );
//
// intdosx( &regs, &regs, &sregs );
typedef struct countryinfo_t
{
	unsigned short country;
	unsigned short codepage;
	char datesep;
	char timesep;
	char curr[5];
	char thous[2];
	char dec[2];
	char datefmt;
	char timefmt;
	char currfmt;
	char digits;
	char listsep;
	char reserved[10];
} countryinfo_t;

#endif // STRUCTS_HPP
