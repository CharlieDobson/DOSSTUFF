// COLORS.H : This file contains display attributes to be used by the
//   menuing system of text-based Dobson Utilities programs
//

#ifndef COLORS_H
#define COLORS_H

#ifndef __NT__

//
// color values as short integers
//

#define __BLACK                     0
#define __BLUE                      1
#define __GREEN                     2
#define __CYAN                      3
#define __RED                       4
#define __MAGENTA                   5
#define __BROWN                     6
#define __WHITE                     7
#define __GRAY                      8
#define __LIGHTBLUE                 9
#define __LIGHTGREEN                10
#define __LIGHTCYAN                 11
#define __LIGHTRED                  12
#define __LIGHTMAGENTA              13
#define __LIGHTYELLOW               14
#define __YELLOW                    14
#define __BRIGHTWHITE               15

#define __BLACK_BLINK               16
#define __BLUE_BLINK                17
#define __GREEN_BLINK               18
#define __CYAN_BLINK                19
#define __RED_BLINK                 20
#define __MAGENTA_BLINK             21
#define __BROWN_BLINK               22
#define __WHITE_BLINK               23
#define __GRAY_BLINK                24
#define __LIGHTBLUE_BLINK           25
#define __LIGHTGREEN_BLINK          26
#define __LIGHTCYAN_BLINK           27
#define __LIGHTRED_BLINK            28
#define __LIGHTMAGENTA_BLINK        29
#define __LIGHTYELLOW_BLINK         30
#define __YELLOW_BLINK              30
#define __BRIGHTWHITE_BLINK         31

//const unsigned int __BLACK = 0;
//const unsigned int __BLUE = 1;
//const unsigned int __GREEN = 2;
//const unsigned int __CYAN = 3;
//const unsigned int __RED = 4;
//const unsigned int __MAGENTA = 5;
//const unsigned int __BROWN = 6;
//const unsigned int __WHITE = 7;
//const unsigned int __GRAY = 8;
//const unsigned int __LIGHTBLUE = 9;
//const unsigned int __LIGHTGREEN = 10;
//const unsigned int __LIGHTCYAN = 11;
//const unsigned int __LIGHTRED = 12;
//const unsigned int __LIGHTMAGENTA = 13;
//const unsigned int __LIGHTYELLOW = 14;
//const unsigned int __YELLOW = 14;
//const unsigned int __BRIGHTWHITE = 15;

//const unsigned int __BLACK_BLINK = 16;
//const unsigned int __BLUE_BLINK = 17;
//const unsigned int __GREEN_BLINK = 18;
//const unsigned int __CYAN_BLINK = 19;
//const unsigned int __RED_BLINK = 20;
//const unsigned int __MAGENTA_BLINK = 21;
//const unsigned int __BROWN_BLINK = 22;
//const unsigned int __WHITE_BLINK = 23;
//const unsigned int __GRAY_BLINK = 24;
//const unsigned int __LIGHTBLUE_BLINK = 25;
//const unsigned int __LIGHTGREEN_BLINK = 26;
//const unsigned int __LIGHTCYAN_BLINK = 27;
//const unsigned int __LIGHTRED_BLINK = 28;
//const unsigned int __LIGHTMAGENTA_BLINK = 29;
//const unsigned int __LIGHTYELLOW_BLINK = 30;
//const unsigned int __YELLOW_BLINK = 30;
//const unsigned int __BRIGHTWHITE_BLINK = 31;

#ifndef __SC__

#define __CTEXT_BLACK               0
#define __CTEXT_BLUE                1
#define __CTEXT_GREEN               2
#define __CTEXT_CYAN                3
#define __CTEXT_RED                 4
#define __CTEXT_MAGENTA             5
#define __CTEXT_BROWN               6
#define __CTEXT_WHITE               7
#define __CTEXT_GRAY                8
#define __CTEXT_LIGHTBLUE           9
#define __CTEXT_LIGHTGREEN          10
#define __CTEXT_LIGHTCYAN           11
#define __CTEXT_LIGHTRED            12
#define __CTEXT_LIGHTMAGENTA        13
#define __CTEXT_LIGHTYELLOW         14
#define __CTEXT_YELLOW              14
#define __CTEXT_BRIGHTWHITE         15

#define __CBACKGROUND_BLACK         0x000000L
#define __CBACKGROUND_BLUE          0x2a0000L
#define __CBACKGROUND_GREEN         0x002a00L
#define __CBACKGROUND_CYAN          0x2a2a00L
#define __CBACKGROUND_RED           0x00002aL
#define __CBACKGROUND_MAGENTA       0x2a002aL
#define __CBACKGROUND_BROWN         0x00152aL
#define __CBACKGROUND_WHITE         0x2a2a2aL
#define __CBACKGROUND_GRAY          0x151515L
#define __CBACKGROUND_LIGHTBLUE     0x3F1515L
#define __CBACKGROUND_LIGHTGREEN    0x153f15L
#define __CBACKGROUND_LIGHTCYAN     0x3f3f15L
#define __CBACKGROUND_LIGHTRED      0x15153fL
#define __CBACKGROUND_LIGHTMAGENTA  0x3f153fL
#define __CBACKGROUND_LIGHTYELLOW   0x153f3fL
#define __CBACKGROUND_YELLOW        0x153f3fL
#define __CBACKGROUND_BRIGHTWHITE   0x3f3f3fL

#endif

#ifdef __SC__

//
// color values as hexidecimal
//

//const unsigned int __BLACK_ON_BLACK = 0x0000;
//const unsigned int __BLUE_ON_BLACK = 0x0001;
//const unsigned int __GREEN_ON_BLACK = 0x0002;
//const unsigned int __CYAN_ON_BLACK = 0x0003;
//const unsigned int __RED_ON_BLACK = 0x0004;
//const unsigned int __MAGENTA_ON_BLACK = 0x0005;
//const unsigned int __BROWN_ON_BLACK = 0x0006;
//const unsigned int __WHITE_ON_BLACK = 0x0007;
//const unsigned int __GRAY_ON_BLACK = 0x0008;
//const unsigned int __LIGHTBLUE_ON_BLACK = 0x0009;
//const unsigned int __LIGHTGREEN_ON_BLACK = 0x000a;
//const unsigned int __LIGHTCYAN_ON_BLACK = 0x000b;
//const unsigned int __LIGHTRED_ON_BLACK = 0x009c;
//const unsigned int __LIGHTMAGENTA_ON_BLACK = 0x000d;
//const unsigned int __YELLOW_ON_BLACK = 0x000e;
//const unsigned int __LIGHTYELLOW_ON_BLACK = 0x000e;
//const unsigned int __BRIGHTWHITE_ON_BLACK = 0x000f;

//const unsigned int __BLACK_ON_BLUE = 0x0010;
//const unsigned int __GREEN_ON_BLUE = 0x0012;
//const unsigned int __CYAN_ON_BLUE = 0x0013;
//const unsigned int __RED_ON_BLUE = 0x0014;
//const unsigned int __MAGENTA_ON_BLUE = 0x0015;
//const unsigned int __BROWN_ON_BLUE = 0x0016;
//const unsigned int __WHITE_ON_BLUE = 0x0017;
//const unsigned int __GRAY_ON_BLUE = 0x0018;
//const unsigned int __LIGHTBLUE_ON_BLUE = 0x0019;
//const unsigned int __LIGHTGREEN_ON_BLUE = 0x001a;
//const unsigned int __LIGHTCYAN_ON_BLUE = 0x001b;
//const unsigned int __LIGHTRED_ON_BLUE = 0x001c;
//const unsigned int __LIGHTMAGENTA_ON_BLUE = 0x001d;
//const unsigned int __YELLOW_ON_BLUE = 0x001e;
//const unsigned int __LIGHTYELLOW_ON_BLUE = 0x001e;
//const unsigned int __BRIGHTWHITE_ON_BLUE = 0x001f;

//const unsigned int __BLACK_ON_GREEN = 0x0020;
//const unsigned int __BLUE_ON_GREEN = 0x0021;
//const unsigned int __CYAN_ON_GREEN = 0x0023;
//const unsigned int __RED_ON_GREEN = 0x0024;
//const unsigned int __MAGENTA_ON_GREEN = 0x0025;
//const unsigned int __BROWN_ON_GREEN = 0x0026;
//const unsigned int __WHITE_ON_GREEN = 0x0027;
//const unsigned int __GRAY_ON_GREEN = 0x0028;
//const unsigned int __LIGHTBLUE_ON_GREEN = 0x0029;
//const unsigned int __LIGHTGREEN_ON_GREEN = 0x002a;
//const unsigned int __LIGHTCYAN_ON_GREEN = 0x002b;
//const unsigned int __LIGHTRED_ON_GREEN = 0x002c;
//const unsigned int __LIGHTMAGENTA_ON_GREEN = 0x002d;
//const unsigned int __YELLOW_ON_GREEN = 0x002e;
//const unsigned int __LIGHTYELLOW_ON_GREEN = 0x002e;
//const unsigned int __BRIGHTWHITE_ON_GREEN = 0x002f;

//const unsigned int __BLACK_ON_CYAN = 0x0030;
//const unsigned int __BLUE_ON_CYAN = 0x0031;
//const unsigned int __GREEN_ON_CYAN = 0x0032;
//const unsigned int __RED_ON_CYAN = 0x0034;
//const unsigned int __MAGENTA_ON_CYAN = 0x0035;
//const unsigned int __BROWN_ON_CYAN = 0x0036;
//const unsigned int __WHITE_ON_CYAN = 0x0037;
//const unsigned int __GRAY_ON_CYAN = 0x0038;
//const unsigned int __LIGHTBLUE_ON_CYAN = 0x0039;
//const unsigned int __LIGHTGREEN_ON_CYAN = 0x003a;
//const unsigned int __LIGHTCYAN_ON_CYAN = 0x003b;
//const unsigned int __LIGHTRED_ON_CYAN = 0x003c;
//const unsigned int __LIGHTMAGENTA_ON_CYAN = 0x003d;
//const unsigned int __YELLOW_ON_CYAN = 0x003e;
//const unsigned int __LIGHTYELLOW_ON_CYAN = 0x003e;
//const unsigned int __BRIGHTWHITE_ON_CYAN = 0x003f;

//const unsigned int __BLACK_ON_RED = 0x0040;
//const unsigned int __BLUE_ON_RED = 0x0041;
//const unsigned int __GREEN_ON_RED = 0x0042;
//const unsigned int __CYAN_ON_RED = 0x0043;
//const unsigned int __MAGENTA_ON_RED = 0x0045;
//const unsigned int __BROWN_ON_RED = 0x0046;
//const unsigned int __WHITE_ON_RED = 0x0047;
//const unsigned int __GRAY_ON_RED = 0x0048;
//const unsigned int __LIGHTBLUE_ON_RED = 0x0049;
//const unsigned int __LIGHTGREEN_ON_RED = 0x004a;
//const unsigned int __LIGHTCYAN_ON_RED = 0x004b;
//const unsigned int __LIGHTRED_ON_RED = 0x004c;
//const unsigned int __LIGHTMAGENTA_ON_RED = 0x004d;
//const unsigned int __YELLOW_ON_RED = 0x004e;
//const unsigned int __LIGHTYELLOW_ON_RED = 0x004e;
//const unsigned int __BRIGHTWHITE_ON_RED = 0x004f;

//const unsigned int __BLACK_ON_MAGENTA = 0x0050;
//const unsigned int __BLUE_ON_MAGENTA = 0x0051;
//const unsigned int __GREEN_ON_MAGENTA = 0x0052;
//const unsigned int __CYAN_ON_MAGENTA = 0x0053;
//const unsigned int __RED_ON_MAGENTA = 0x0054;
//const unsigned int __BROWN_ON_MAGENTA = 0x0056;
//const unsigned int __WHITE_ON_MAGENTA = 0x0057;
//const unsigned int __GRAY_ON_MAGENTA = 0x0058;
//const unsigned int __LIGHTBLUE_ON_MAGENTA = 0x0059;
//const unsigned int __LIGHTGREEN_ON_MAGENTA = 0x005a;
//const unsigned int __LIGHTCYAN_ON_MAGENTA = 0x005b;
//const unsigned int __LIGHTRED_ON_MAGENTA = 0x005c;
//const unsigned int __LIGHTMAGENTA_ON_MAGENTA = 0x005d;
//const unsigned int __YELLOW_ON_MAGENTA = 0x005e;
//const unsigned int __LIGHTYELLOW_ON_MAGENTA = 0x005e;
//const unsigned int __BRIGHTWHITE_ON_MAGENTA = 0x005f;

//const unsigned int __BLACK_ON_BROWN = 0x0060;
//const unsigned int __BLUE_ON_BROWN = 0x0061;
//const unsigned int __GREEN_ON_BROWN = 0x0062;
//const unsigned int __CYAN_ON_BROWN = 0x0063;
//const unsigned int __RED_ON_BROWN = 0x0064;
//const unsigned int __MAGENTA_ON_BROWN = 0x0065;
//const unsigned int __WHITE_ON_BROWN = 0x0067;
//const unsigned int __GRAY_ON_BROWN = 0x0068;
//const unsigned int __LIGHTBLUE_ON_BROWN = 0x0069;
//const unsigned int __LIGHTGREEN_ON_BROWN = 0x006a;
//const unsigned int __LIGHTCYAN_ON_BROWN = 0x006b;
//const unsigned int __LIGHTRED_ON_BROWN = 0x006c;
//const unsigned int __LIGHTMAGENTA_ON_BROWN = 0x006d;
//const unsigned int __YELLOW_ON_BROWN = 0x006e;
//const unsigned int __LIGHTYELLOW_ON_BROWN = 0x006e;
//const unsigned int __BRIGHTWHITE_ON_BROWN = 0x006f;

//const unsigned int __BLACK_ON_WHITE = 0x0070;
//const unsigned int __BLUE_ON_WHITE = 0x0071;
//const unsigned int __GREEN_ON_WHITE = 0x0072;
//const unsigned int __CYAN_ON_WHITE = 0x0073;
//const unsigned int __RED_ON_WHITE = 0x0074;
//const unsigned int __MAGENTA_ON_WHITE = 0x0075;
//const unsigned int __BROWN_ON_WHITE = 0x0076;
//const unsigned int __GRAY_ON_WHITE = 0x0078;
//const unsigned int __LIGHTBLUE_ON_WHITE = 0x0079;
//const unsigned int __LIGHTGREEN_ON_WHITE = 0x007a;
//const unsigned int __LIGHTCYAN_ON_WHITE = 0x007b;
//const unsigned int __LIGHTRED_ON_WHITE = 0x007c;
//const unsigned int __LIGHTMAGENTA_ON_WHITE = 0x007d;
//const unsigned int __YELLOW_ON_WHITE = 0x007e;
//const unsigned int __LIGHTYELLOW_ON_WHITE = 0x007e;
//const unsigned int __BRIGHTWHITE_ON_WHITE = 0x007f;

//const unsigned int __BLACK_ON_GRAY = 0x0080;
//const unsigned int __BLUE_ON_GRAY = 0x0081;
//const unsigned int __GREEN_ON_GRAY = 0x0082;
//const unsigned int __CYAN_ON_GRAY = 0x0083;
//const unsigned int __RED_ON_GRAY = 0x0084;
//const unsigned int __MAGENTA_ON_GRAY = 0x0085;
//const unsigned int __BROWN_ON_GRAY = 0x0086;
//const unsigned int __WHITE_ON_GRAY = 0x0087;
//const unsigned int __LIGHTBLUE_ON_GRAY = 0x0089;
//const unsigned int __LIGHTGREEN_ON_GRAY = 0x008a;
//const unsigned int __LIGHTCYAN_ON_GRAY = 0x008b;
//const unsigned int __LIGHTRED_ON_GRAY = 0x008c;
//const unsigned int __LIGHTMAGENTA_ON_GRAY = 0x008d;
//const unsigned int __YELLOW_ON_GRAY = 0x008e;
//const unsigned int __LIGHTYELLOW_ON_GRAY = 0x008e;
//const unsigned int __BRIGHTWHITE_ON_GRAY = 0x008f;

//const unsigned int __BLACK_ON_LIGHTBLUE = 0x0090;
//const unsigned int __BLUE_ON_LIGHTBLUE = 0x0091;
//const unsigned int __GREEN_ON_LIGHTBLUE = 0x0092;
//const unsigned int __CYAN_ON_LIGHTBLUE = 0x0093;
//const unsigned int __RED_ON_LIGHTBLUE = 0x0094;
//const unsigned int __MAGENTA_ON_LIGHTBLUE = 0x0095;
//const unsigned int __BROWN_ON_LIGHTBLUE = 0x0096;
//const unsigned int __WHITE_ON_LIGHTBLUE = 0x0097;
//const unsigned int __GRAY_ON_LIGHTBLUE = 0x0098;
//const unsigned int __LIGHTGREEN_ON_LIGHTBLUE = 0x009a;
//const unsigned int __LIGHTCYAN_ON_LIGHTBLUE = 0x009b;
//const unsigned int __LIGHTRED_ON_LIGHTBLUE = 0x009c;
//const unsigned int __LIGHTMAGENTA_ON_LIGHTBLUE = 0x009d;
//const unsigned int __YELLOW_ON_LIGHTBLUE = 0x009e;
//const unsigned int __LIGHTYELLOW_ON_LIGHTBLUE = 0x009e;
//const unsigned int __BRIGHTWHITE_ON_LIGHTBLUE = 0x009f;

//const unsigned int __BLACK_ON_LIGHTGREEN = 0x00a0;
//const unsigned int __BLUE_ON_LIGHTGREEN = 0x00a1;
//const unsigned int __GREEN_ON_LIGHTGREEN = 0x00a2;
//const unsigned int __CYAN_ON_LIGHTGREEN = 0x00a3;
//const unsigned int __RED_ON_LIGHTGREEN = 0x00a4;
//const unsigned int __MAGENTA_ON_LIGHTGREEN = 0x00a5;
//const unsigned int __BROWN_ON_LIGHTGREEN = 0x00a6;
//const unsigned int __WHITE_ON_LIGHTGREEN = 0x00a7;
//const unsigned int __GRAY_ON_LIGHTGREEN = 0x00a8;
//const unsigned int __LIGHTBLUE_ON_LIGHTGREEN = 0x00a9;
//const unsigned int __LIGHTCYAN_ON_LIGHTGREEN = 0x00ab;
//const unsigned int __LIGHTRED_ON_LIGHTGREEN = 0x00ac;
//const unsigned int __LIGHTMAGENTA_ON_LIGHTGREEN = 0x00ad;
//const unsigned int __YELLOW_ON_LIGHTGREEN = 0x00ae;
//const unsigned int __LIGHTYELLOW_ON_LIGHTGREEN = 0x00ae;
//const unsigned int __BRIGHTWHITE_ON_LIGHTGREEN = 0x00af;

//const unsigned int __BLACK_ON_LIGHTCYAN = 0x00b0;
//const unsigned int __BLUE_ON_LIGHTCYAN = 0x00b1;
//const unsigned int __GREEN_ON_LIGHTCYAN = 0x00b2;
//const unsigned int __CYAN_ON_LIGHTCYAN = 0x00b3;
//const unsigned int __RED_ON_LIGHTCYAN = 0x00b4;
//const unsigned int __MAGENTA_ON_LIGHTCYAN = 0x00b5;
//const unsigned int __BROWN_ON_LIGHTCYAN = 0x00b6;
//const unsigned int __WHITE_ON_LIGHTCYAN = 0x00b7;
//const unsigned int __GRAY_ON_LIGHTCYAN = 0x00b8;
//const unsigned int __LIGHTBLUE_ON_LIGHTCYAN = 0x00b9;
//const unsigned int __LIGHTGREEN_ON_LIGHTCYAN = 0x00ba;
//const unsigned int __LIGHTRED_ON_LIGHTCYAN = 0x00bc;
//const unsigned int __LIGHTMAGENTA_ON_LIGHTCYAN = 0x00bd;
//const unsigned int __YELLOW_ON_LIGHTCYAN = 0x00be;
//const unsigned int __LIGHTYELLOW_ON_LIGHTCYAN = 0x00be;
//const unsigned int __BRIGHTWHITE_ON_LIGHTCYAN = 0x00bf;

//const unsigned int __BLACK_ON_LIGHTRED = 0x00c0;
//const unsigned int __BLUE_ON_LIGHTRED = 0x00c1;
//const unsigned int __GREEN_ON_LIGHTRED = 0x00c2;
//const unsigned int __CYAN_ON_LIGHTRED = 0x00c3;
//const unsigned int __RED_ON_LIGHTRED = 0x00c4;
//const unsigned int __MAGENTA_ON_LIGHTRED = 0x00c5;
//const unsigned int __BROWN_ON_LIGHTRED = 0x00c6;
//const unsigned int __WHITE_ON_LIGHTRED = 0x00c7;
//const unsigned int __GRAY_ON_LIGHTRED = 0x00c8;
//const unsigned int __LIGHTBLUE_ON_LIGHTRED = 0x00c9;
//const unsigned int __LIGHTGREEN_ON_LIGHTRED = 0x00ca;
//const unsigned int __LIGHTCYAN_ON_LIGHTRED = 0x00cb;
//const unsigned int __LIGHTMAGENTA_ON_LIGHTRED = 0x00cd;
//const unsigned int __YELLOW_ON_LIGHTRED = 0x00ce;
//const unsigned int __LIGHTYELLOW_ON_LIGHTRED = 0x00ce;
//const unsigned int __BRIGHTWHITE_ON_LGHTRED = 0x00cf;

//const unsigned int __BLACK_ON_LIGHTMAGENTA = 0x00d0;
//const unsigned int __BLUE_ON_LIGHTMAGENTA = 0x00d1;
//const unsigned int __GREEN_ON_LIGHTMAGENTA = 0x00d2;
//const unsigned int __CYAN_ON_LIGHTMAGENTA = 0x00d3;
//const unsigned int __RED_ON_LIGHTMAGENTA = 0x00d4;
//const unsigned int __MAGENTA_ON_LIGHTMAGENTA = 0x00d5;
//const unsigned int __BROWN_ON_LIGHTMAGENTA = 0x00d6;
//const unsigned int __WHITE_ON_LIGHTMAGENTA = 0x00d7;
//const unsigned int __GRAY_ON_LIGHTMAGENTA = 0x00d8;
//const unsigned int __LIGHTBLUE_ON_LIGHTMAGENTA = 0x00d9;
//const unsigned int __LIGHTGREEN_ON_LIGHTMAGENTA = 0x00da;
//const unsigned int __LIGHTCYAN_ON_LIGHTMAGENTA = 0x00db;
//const unsigned int __LIGHTRED_ON_LIGHTMAGENTA = 0x00dc;
//const unsigned int __YELLOW_ON_LIGHTMAGENTA = 0x00de;
//const unsigned int __LIGHTYELLOW_ON_LIGHTMAGENTA = 0x00de;
//const unsigned int __BRIGHTWHITE_ON_LIGHTMAGENTA = 0x00df;

//const unsigned int __BLACK_ON_YELLOW = 0x00e0;
//const unsigned int __BLUE_ON_YELLOW = 0x00e1;
//const unsigned int __GREEN_ON_YELLOW = 0x00e2;
//const unsigned int __CYAN_ON_YELLOW = 0x00e3;
//const unsigned int __RED_ON_YELLOW = 0x00e4;
//const unsigned int __MAGENTA_ON_YELLOW = 0x00e5;
//const unsigned int __BROWN_ON_YELLOW = 0x00e6;
//const unsigned int __WHITE_ON_YELLOW = 0x00e7;
//const unsigned int __GRAY_ON_YELLOW = 0x00e8;
//const unsigned int __LIGHTBLUE_ON_YELLOW = 0x00e9;
//const unsigned int __LIGHTGREEN_ON_YELLOW = 0x00ea;
//const unsigned int __LIGHTCYAN_ON_YELLOW = 0x00eb;
//const unsigned int __LIGHTRED_ON_YELLOW = 0x00ec;
//const unsigned int __LIGHTMAGENTA_ON_YELLOW = 0x00ed;
//const unsigned int __BRIGHTWHITE_ON_YELLOW = 0x00ef;

//const unsigned int __BLACK_ON_LIGHTYELLOW = 0x00e0;
//const unsigned int __BLUE_ON_LIGHTYELLOW = 0x00e1;
//const unsigned int __GREEN_ON_LIGHTYELLOW = 0x00e2;
//const unsigned int __CYAN_ON_LIGHTYELLOW = 0x00e3;
//const unsigned int __RED_ON_LIGHTYELLOW = 0x00e4;
//const unsigned int __MAGENTA_ON_LIGHTYELLOW = 0x00e5;
//const unsigned int __BROWN_ON_LIGHTYELLOW = 0x00e6;
//const unsigned int __WHITE_ON_LIGHTYELLOW = 0x00e7;
//const unsigned int __GRAY_ON_LIGHTYELLOW = 0x00e8;
//const unsigned int __LIGHTBLUE_ON_LIGHTYELLOW = 0x00e9;
//const unsigned int __LIGHTGREEN_ON_LIGHTYELLOW = 0x00ea;
//const unsigned int __LIGHTCYAN_ON_LIGHTYELLOW = 0x00eb;
//const unsigned int __LIGHTRED_ON_LIGHTYELLOW = 0x00ec;
//const unsigned int __LIGHTMAGENTA_ON_LIGHTYELLOW = 0x00ed;
//const unsigned int __BRIGHTWHITE_ON_LIGHTYELLOW = 0x00ef;

//const unsigned int __BLACK_ON_BRIGHTWHITE = 0x00f0;
//const unsigned int __BLUE_ON_BRIGHTWHITE = 0x00f1;
//const unsigned int __GREEN_ON_BRIGHTWHITE = 0x00f2;
//const unsigned int __CYAN_ON_BRIGHTWHITE = 0x00f3;
//const unsigned int __RED_ON_BRIGHTWHITE = 0x00f4;
//const unsigned int __MAGENTA_ON_BRIGHTWHITE = 0x00f5;
//const unsigned int __BROWN_ON_BRIGHTWHITE = 0x00f6;
//const unsigned int __WHITE_ON_BRIGHTWHITE = 0x00f7;
//const unsigned int __GRAY_ON_BRIGHTWHITE = 0x00f8;
//const unsigned int __LIGHTBLUE_ON_BRIGHTWHITE = 0x00f9;
//const unsigned int __LIGHTGREEN_ON_BRIGHTWHITE = 0x00fa;
//const unsigned int __LIGHTCYAN_ON_BRIGHTWHITE = 0x00fb;
//const unsigned int __LIGHTRED_ON_BRIGHTWHITE = 0x00fc;
//const unsigned int __LIGHTMAGENTA_ON_BRIGHTWHITE = 0x00fd;
//const unsigned int __YELLOW_ON_BRIGHTWHITE = 0x00fe;
//const unsigned int __LIGHTYELLOW_ON_BRIGHTWHITE = 0x00fe;
//const unsigned int __BRIGHTWHITE_ON_BRIGHTWHITE = 0x00ff;

//#define __BLACK_ON_BLACK                0x0000
#define __BLUE_ON_BLACK                 0x0001
#define __GREEN_ON_BLACK                0x0002
#define __CYAN_ON_BLACK                 0x0003
#define __RED_ON_BLACK                  0x0004
#define __MAGENTA_ON_BLACK              0x0005
#define __BROWN_ON_BLACK                0x0006
#define __WHITE_ON_BLACK                0x0007
#define __GRAY_ON_BLACK                 0x0008
#define __LIGHTBLUE_ON_BLACK            0x0009
#define __LIGHTGREEN_ON_BLACK           0x000a
#define __LIGHTCYAN_ON_BLACK            0x000b
#define __LIGHTRED_ON_BLACK             0x000c
#define __LIGHTMAGENTA_ON_BLACK         0x000d
#define __YELLOW_ON_BLACK               0x000e
#define __BRIGHTWHITE_ON_BLACK          0x000f

#define __BLACK_ON_BLUE                 0x0010
#define __GREEN_ON_BLUE                 0x0012
#define __CYAN_ON_BLUE                  0x0013
#define __RED_ON_BLUE                   0x0014
#define __MAGENTA_ON_BLUE               0x0015
#define __BROWN_ON_BLUE                 0x0016
#define __WHITE_ON_BLUE                 0x0017
#define __GRAY_ON_BLUE                  0x0018
#define __LIGHTBLUE_ON_BLUE             0x0019
#define __LIGHTGREEN_ON_BLUE            0x001a
#define __LIGHTCYAN_ON_BLUE             0x001b
#define __LIGHTRED_ON_BLUE              0x001c
#define __LIGHTMAGENTA_ON_BLUE          0x001d
#define __YELLOW_ON_BLUE                0x001e
#define __BRIGHTWHITE_ON_BLUE           0x001f

#define __BLACK_ON_GREEN                0x0020
#define __BLUE_ON_GREEN                 0x0021
#define __CYAN_ON_GREEN                 0x0023
#define __RED_ON_GREEN                  0x0024
#define __MAGENTA_ON_GREEN              0x0025
#define __BROWN_ON_GREEN                0x0026
#define __WHITE_ON_GREEN                0x0027
#define __GRAY_ON_GREEN                 0x0028
#define __LIGHTBLUE_ON_GREEN            0x0029
#define __LIGHTGREEN_ON_GREEN           0x002a
#define __LIGHTCYAN_ON_GREEN            0x002b
#define __LIGHTRED_ON_GREEN             0x002c
#define __LIGHTMAGENTA_ON_GREEN         0x002d
#define __YELLOW_ON_GREEN               0x002e
#define __BRIGHTWHITE_ON_GREEN          0x002f

#define __BLACK_ON_CYAN                 0x0030
#define __BLUE_ON_CYAN                  0x0031
#define __GREEN_ON_CYAN                 0x0032
#define __RED_ON_CYAN                   0x0034
#define __MAGENTA_ON_CYAN               0x0035
#define __BROWN_ON_CYAN                 0x0036
#define __WHITE_ON_CYAN                 0x0037
#define __GRAY_ON_CYAN                  0x0038
#define __LIGHTBLUE_ON_CYAN             0x0039
#define __LIGHTGREEN_ON_CYAN            0x003a
#define __LIGHTCYAN_ON_CYAN             0x003b
#define __LIGHTRED_ON_CYAN              0x003c
#define __LIGHTMAGENTA_ON_CYAN          0x003d
#define __YELLOW_ON_CYAN                0x003e
#define __BRIGHTWHITE_ON_CYAN           0x003f

#define __BLACK_ON_RED                  0x0040
#define __BLUE_ON_RED                   0x0041
#define __GREEN_ON_RED                  0x0042
#define __CYAN_ON_RED                   0x0043
#define __MAGENTA_ON_RED                0x0045
#define __BROWN_ON_RED                  0x0046
#define __WHITE_ON_RED                  0x0047
#define __GRAY_ON_RED                   0x0048
#define __LIGHTBLUE_ON_RED              0x0049
#define __LIGHTGREEN_ON_RED             0x004a
#define __LIGHTCYAN_ON_RED              0x004b
#define __LIGHTRED_ON_RED               0x004c
#define __LIGHTMAGENTA_ON_RED           0x004d
#define __YELLOW_ON_RED                 0x004e
#define __BRIGHTWHITE_ON_RED            0x004f

#define __BLACK_ON_MAGENTA              0x0050
#define __BLUE_ON_MAGENTA               0x0051
#define __GREEN_ON_MAGENTA              0x0052
#define __CYAN_ON_MAGENTA               0x0053
#define __RED_ON_MAGENTA                0x0054
#define __BROWN_ON_MAGENTA              0x0056
#define __WHITE_ON_MAGENTA              0x0057
#define __GRAY_ON_MAGENTA               0x0058
#define __LIGHTBLUE_ON_MAGENTA          0x0059
#define __LIGHTGREEN_ON_MAGENTA         0x005a
#define __LIGHTCYAN_ON_MAGENTA          0x005b
#define __LIGHTRED_ON_MAGENTA           0x005c
#define __LIGHTMAGENTA_ON_MAGENTA       0x005d
#define __YELLOW_ON_MAGENTA             0x005e
#define __BRIGHTWHITE_ON_MAGENTA        0x005f

#define __BLACK_ON_BROWN                0x0060
#define __BLUE_ON_BROWN                 0x0061
#define __GREEN_ON_BROWN                0x0062
#define __CYAN_ON_BROWN                 0x0063
#define __RED_ON_BROWN                  0x0064
#define __MAGENTA_ON_BROWN              0x0065
#define __WHITE_ON_BROWN                0x0067
#define __GRAY_ON_BROWN                 0x0068
#define __LIGHTBLUE_ON_BROWN            0x0069
#define __LIGHTGREEN_ON_BROWN           0x006a
#define __LIGHTCYAN_ON_BROWN            0x006b
#define __LIGHTRED_ON_BROWN             0x006c
#define __LIGHTMAGENTA_ON_BROWN         0x006d
#define __YELLOW_ON_BROWN               0x006e
#define __BRIGHTWHITE_ON_BROWN          0x006f

#define __BLACK_ON_WHITE                0x0070
#define __BLUE_ON_WHITE                 0x0071
#define __GREEN_ON_WHITE                0x0072
#define __CYAN_ON_WHITE                 0x0073
#define __RED_ON_WHITE                  0x0074
#define __MAGENTA_ON_WHITE              0x0075
#define __BROWN_ON_WHITE                0x0076
#define __GRAY_ON_WHITE                 0x0078
#define __LIGHTBLUE_ON_WHITE            0x0079
#define __LIGHTGREEN_ON_WHITE           0x007a
#define __LIGHTCYAN_ON_WHITE            0x007b
#define __LIGHTRED_ON_WHITE             0x007c
#define __LIGHTMAGENTA_ON_WHITE         0x007d
#define __YELLOW_ON_WHITE               0x007e
#define __BRIGHTWHITE_ON_WHITE          0x007f

#define __BLACK_ON_GRAY                 0x0080
#define __BLUE_ON_GRAY                  0x0081
#define __GREEN_ON_GRAY                 0x0082
#define __CYAN_ON_GRAY                  0x0083
#define __RED_ON_GRAY                   0x0084
#define __MAGENTA_ON_GRAY               0x0085
#define __BROWN_ON_GRAY                 0x0086
#define __WHITE_ON_GRAY                 0x0087
#define __LIGHTBLUE_ON_GRAY             0x0089
#define __LIGHTGREEN_ON_GRAY            0x008a
#define __LIGHTCYAN_ON_GRAY             0x008b
#define __LIGHTRED_ON_GRAY              0x008c
#define __LIGHTMAGENTA_ON_GRAY          0x008d
#define __YELLOW_ON_GRAY                0x008e
#define __BRIGHTWHITE_ON_GRAY           0x008f

#define __BLACK_ON_LIGHTBLUE            0x0090
#define __BLUE_ON_LIGHTBLUE             0x0091
#define __GREEN_ON_LIGHTBLUE            0x0092
#define __CYAN_ON_LIGHTBLUE             0x0093
#define __RED_ON_LIGHTBLUE              0x0094
#define __MAGENTA_ON_LIGHTBLUE          0x0095
#define __BROWN_ON_LIGHTBLUE            0x0096
#define __WHITE_ON_LIGHTBLUE            0x0097
#define __GRAY_ON_LIGHTBLUE             0x0098
#define __LIGHTGREEN_ON_LIGHTBLUE       0x009a
#define __LIGHTCYAN_ON_LIGHTBLUE        0x009b
#define __LIGHTRED_ON_LIGHTBLUE         0x009c
#define __LIGHTMAGENTA_ON_LIGHTBLUE     0x009d
#define __YELLOW_ON_LIGHTBLUE           0x009e
#define __LIGHTYELLOW_ON_LIGHTBLUE      0x009e
#define __BRIGHTWHITE_ON_LIGHTBLUE      0x009f

#define __BLACK_ON_LIGHTGREEN           0x00a0
#define __BLUE_ON_LIGHTGREEN            0x00a1
#define __GREEN_ON_LIGHTGREEN           0x00a2
#define __CYAN_ON_LIGHTGREEN            0x00a3
#define __RED_ON_LIGHTGREEN             0x00a4
#define __MAGENTA_ON_LIGHTGREEN         0x00a5
#define __BROWN_ON_LIGHTGREEN           0x00a6
#define __WHITE_ON_LIGHTGREEN           0x00a7
#define __GRAY_ON_LIGHTGREEN            0x00a8
#define __LIGHTBLUE_ON_LIGHTGREEN       0x00a9
#define __LIGHTCYAN_ON_LIGHTGREEN       0x00ab
#define __LIGHTRED_ON_LIGHTGREEN        0x00ac
#define __LIGHTMAGENTA_ON_LIGHTGREEN    0x00ad
#define __YELLOW_ON_LIGHTGREEN          0x00ae
#define __LIGHTYELLOW_ON_LIGHTGREEN     0x00ae
#define __BRIGHTWHITE_ON_LIGHTGREEN     0x00af

#define __BLACK_ON_LIGHTCYAN            0x00b0
#define __BLUE_ON_LIGHTCYAN             0x00b1
#define __GREEN_ON_LIGHTCYAN            0x00b2
#define __CYAN_ON_LIGHTCYAN             0x00b3
#define __RED_ON_LIGHTCYAN              0x00b4
#define __MAGENTA_ON_LIGHTCYAN          0x00b5
#define __BROWN_ON_LIGHTCYAN            0x00b6
#define __WHITE_ON_LIGHTCYAN            0x00b7
#define __GRAY_ON_LIGHTCYAN             0x00b8
#define __LIGHTBLUE_ON_LIGHTCYAN        0x00b9
#define __LIGHTGREEN_ON_LIGHTCYAN       0x00ba
#define __LIGHTRED_ON_LIGHTCYAN         0x00bc
#define __LIGHTMAGENTA_ON_LIGHTCYAN     0x00bd
#define __YELLOW_ON_LIGHTCYAN           0x00be
#define __LIGHTYELLOW_ON_LIGHTCYAN      0x00be
#define __BRIGHTWHITE_ON_LIGHTCYAN      0x00bf

#define __BLACK_ON_LIGHTRED             0x00c0
#define __BLUE_ON_LIGHTRED              0x00c1
#define __GREEN_ON_LIGHTRED             0x00c2
#define __CYAN_ON_LIGHTRED              0x00c3
#define __RED_ON_LIGHTRED               0x00c4
#define __MAGENTA_ON_LIGHTRED           0x00c5
#define __BROWN_ON_LIGHTRED             0x00c6
#define __WHITE_ON_LIGHTRED             0x00c7
#define __GRAY_ON_LIGHTRED              0x00c8
#define __LIGHTBLUE_ON_LIGHTRED         0x00c9
#define __LIGHTGREEN_ON_LIGHTRED        0x00ca
#define __LIGHTCYAN_ON_LIGHTRED         0x00cb
#define __LIGHTMAGENTA_ON_LIGHTRED      0x00cd
#define __YELLOW_ON_LIGHTRED            0x00ce
#define __LIGHTYELLOW_ON_LIGHTRED       0x00ce
#define __BRIGHTWHITE_ON_LGHTRED        0x00cf

#define __BLACK_ON_LIGHTMAGENTA         0x00d0
#define __BLUE_ON_LIGHTMAGENTA          0x00d1
#define __GREEN_ON_LIGHTMAGENTA         0x00d2
#define __CYAN_ON_LIGHTMAGENTA          0x00d3
#define __RED_ON_LIGHTMAGENTA           0x00d4
#define __MAGENTA_ON_LIGHTMAGENTA       0x00d5
#define __BROWN_ON_LIGHTMAGENTA         0x00d6
#define __WHITE_ON_LIGHTMAGENTA         0x00d7
#define __GRAY_ON_LIGHTMAGENTA          0x00d8
#define __LIGHTBLUE_ON_LIGHTMAGENTA     0x00d9
#define __LIGHTGREEN_ON_LIGHTMAGENTA    0x00da
#define __LIGHTCYAN_ON_LIGHTMAGENTA     0x00db
#define __LIGHTRED_ON_LIGHTMAGENTA      0x00dc
#define __YELLOW_ON_LIGHTMAGENTA        0x00de
#define __LIGHTYELLOW_ON_LIGHTMAGENTA   0x00de
#define __BRIGHTWHITE_ON_LIGHTMAGENTA   0x00df

#define __BLACK_ON_YELLOW               0x00e0
#define __BLUE_ON_YELLOW                0x00e1
#define __GREEN_ON_YELLOW               0x00e2
#define __CYAN_ON_YELLOW                0x00e3
#define __RED_ON_YELLOW                 0x00e4
#define __MAGENTA_ON_YELLOW             0x00e5
#define __BROWN_ON_YELLOW               0x00e6
#define __WHITE_ON_YELLOW               0x00e7
#define __GRAY_ON_YELLOW                0x00e8
#define __LIGHTBLUE_ON_YELLOW           0x00e9
#define __LIGHTGREEN_ON_YELLOW          0x00ea
#define __LIGHTCYAN_ON_YELLOW           0x00eb
#define __LIGHTRED_ON_YELLOW            0x00ec
#define __LIGHTMAGENTA_ON_YELLOW        0x00ed
#define __BRIGHTWHITE_ON_YELLOW         0x00ef

#define __BLACK_ON_LIGHTYELLOW          0x00e0
#define __BLUE_ON_LIGHTYELLOW           0x00e1
#define __GREEN_ON_LIGHTYELLOW          0x00e2
#define __CYAN_ON_LIGHTYELLOW           0x00e3
#define __RED_ON_LIGHTYELLOW            0x00e4
#define __MAGENTA_ON_LIGHTYELLOW        0x00e5
#define __BROWN_ON_LIGHTYELLOW          0x00e6
#define __WHITE_ON_LIGHTYELLOW          0x00e7
#define __GRAY_ON_LIGHTYELLOW           0x00e8
#define __LIGHTBLUE_ON_LIGHTYELLOW      0x00e9
#define __LIGHTGREEN_ON_LIGHTYELLOW     0x00ea
#define __LIGHTCYAN_ON_LIGHTYELLOW      0x00eb
#define __LIGHTRED_ON_LIGHTYELLOW       0x00ec
#define __LIGHTMAGENTA_ON_LIGHTYELLOW   0x00ed
#define __BRIGHTWHITE_ON_LIGHTYELLOW    0x00ef

#define __BLACK_ON_BRIGHTWHITE          0x00f0
#define __BLUE_ON_BRIGHTWHITE           0x00f1
#define __GREEN_ON_BRIGHTWHITE          0x00f2
#define __CYAN_ON_BRIGHTWHITE           0x00f3
#define __RED_ON_BRIGHTWHITE            0x00f4
#define __MAGENTA_ON_BRIGHTWHITE        0x00f5
#define __BROWN_ON_BRIGHTWHITE          0x00f6
#define __WHITE_ON_BRIGHTWHITE          0x00f7
#define __GRAY_ON_BRIGHTWHITE           0x00f8
#define __LIGHTBLUE_ON_BRIGHTWHITE      0x00f9
#define __LIGHTGREEN_ON_BRIGHTWHITE     0x00fa
#define __LIGHTCYAN_ON_BRIGHTWHITE      0x00fb
#define __LIGHTRED_ON_BRIGHTWHITE       0x00fc
#define __LIGHTMAGENTA_ON_BRIGHTWHITE   0x00fd
#define __YELLOW_ON_BRIGHTWHITE         0x00fe
#define __LIGHTYELLOW_ON_BRIGHTWHITE    0x00fe

#endif // __SC__

#endif // __NT__

//
// color values as RGB (not a complete list)
//

#ifdef _INC_WINDOWS
const COLORREF __RGB_BLACK = RGB( 0, 0, 0 );
const COLORREF __RGB_WHITE = RGB( 255, 255, 255 );
const COLORREF __RGB_GAINSBORO = RGB( 220, 220, 220 );
const COLORREF __RGB_LTGRAY = RGB( 211, 211, 211 );
const COLORREF __RGB_GRAY = RGB( 128, 128, 128 );
const COLORREF __RGB_SILVER = RGB( 192, 192, 192 );
const COLORREF __RGB_BLUE = RGB( 0, 0, 255 );
const COLORREF __RGB_RED = RGB( 255, 0, 0 );
const COLORREF __RGB_GREEN = RGB( 0, 255, 0 );
const COLORREF __RGB_YELLOW = RGB( 255, 255, 0 );
const COLORREF __RGB_CYAN = RGB( 0, 255, 255 );
#define RGB_BLACK                       RGB( 0, 0,0 )
#define RGB_WHITE                       RGB( 255, 255, 255 )
#define RGB_GAINSBORO                   RGB( 220, 220, 220 )
#define RGB_LTGRAY                      RGB( 211, 211, 211 )
#define RGB_GRAY                        RGB( 128, 128, 128 )
#define RGB_SILVER                      RGB( 192, 192, 192 )
#define RGB_BLUE                        RGB( 0, 0, 255 )
#define RGB_RED                         RGB( 255, 0, 0 )
#define RGB_GREEN                       RGB( 0, 255, 0 )
#define RGB_YELLOW                      RGB( 255, 255, 0 )
#define RGB_CYAN                        RGB( 0, 255, 255 )
#endif // _INC_WINDOWS

#endif // COLORS_H