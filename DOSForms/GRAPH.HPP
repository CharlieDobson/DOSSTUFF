// graph.hpp for __SC__

#ifndef GRAPH_HPP
#define GRAPH_HPP 1

#ifndef __SC__
#error This file should only be compiled by Symantec C++ compiler
#else

#include "structs.hpp"

/********************************************
 * The disp coordinate system starts at 0,0
 * but the videoconfig coordinate system
 * starts at 1,1 so we must remember to sub-
 * tract 1 from any coordinate system in-
 * tended for the videoconfig coordinates
 *******************************************/

void _getvideoconfig( videoconfig __far* Config );
void _setvideomode( const short Mode );

void _settextposition( const short Row, const short Column );
void _settextcursor( const short Cursor );
void _settextwindow( const short StartColumn, const short StartRow, const short EndColumn, const short EndRow );

void _outtext( const char* Text );

void _clearscreen( const short Area );

#endif // GRAPH_HPP