#include <stdio.h>
#include <assert.h>
#include <sys/stat.h>

#include "constants.h"
#include "stroki.h"
#include "dataFuncs.h"
#include "io.h"

int main( void )
{
    Fileinf text = {};
    
    fillFileinf( &text );

    qsort( text.strData, text.nlines, sizeof( struct String ), MyReverseStrcmp );

    myBubbleSort( text.strData, text.nlines, sizeof( struct String ), MyReverseStrcmp );

    printData( &text );

    putchar( '\n' );

    printFileinfBuff( &text );

    putchar( '\n' );
    
    freeFileinf( &text );

    tapEnter();

    return 0;
}
