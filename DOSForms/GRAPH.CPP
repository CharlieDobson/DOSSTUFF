// graph.cpp : implenentation file for MSC to SC graphics routines

#include "graph.hpp"
#include <disp.h>

void _getvideoconfig( struct videoconfig __far* Config )
{
    Config->mode = disp_getmode();
    if ( disp_inited ) {
        Config->numtextrows = disp_numrows;
        Config->numtextcols = disp_numcols;
    }
    else {
        disp_open();
        Config->numtextrows = disp_numrows;
        Config->numtextcols = disp_numcols;
        disp_close();
    }
}

void _setvideomode( const short Mode )
{
    disp_setmode( Mode );
}

void _settextposition( const short Row, const short Column ) 
{
    if ( !disp_inited ) {
        return;
    }

    disp_move( Row - 1, Column - 1 );
}

void _settextcursor( const short Cursor )
{

}

void _settextwindow( const short StartColumn, const short StartRow, const short EndColumn, const short EndRow )
{

}

void _outtext( const char* Text )
{
    if ( !disp_inited ) {
        return;
    }

    disp_puts( Text );
}

void _clearscreen( const short Area )
{

}
