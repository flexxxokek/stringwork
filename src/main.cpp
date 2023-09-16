#include <stdio.h>
#include <assert.h>
#include <sys/stat.h>

#include "constants.h"
#include "stroki.h"
#include "dataFuncs.h"

void tapAnyKey( void )
{
    printf( "Tap any key to exit...\n");

    getc( stdin );
}

int main( void )
{
    Fileinf text = {};
    
    fillFileinf( &text );

    qsort( text.strData, text.nlines, sizeof( char* ), MyStrcmp );

    printData( &text );

    putchar( '\n' );

    printFileinfBuff( &text );

    putchar( '\n' );
    
    freeFileinf( &text );

    tapAnyKey();
    
    return 0;
}
