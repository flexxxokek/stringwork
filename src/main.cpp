#include <stdio.h>
#include <assert.h>

#include "constants.h"

void printData( const char a[], const size_t rows, const size_t colls );

void printData( const char a[] );

void scanData( char a[], const size_t rows, const size_t colls );

void fscanData( FILE* fp, char a[], const size_t rows, const size_t colls );

int main( const int argc, const char** argv )
{
    char text[MAX_STR_NUM][MAX_STR_LENGTH] = {};

    FILE* fp = fopen( "text.txt", "r" );

    fscanData( fp, text[0], MAX_STR_NUM, MAX_STR_LENGTH );

    printData( text[0], MAX_STR_NUM, MAX_STR_LENGTH );
    
    return 0;
}

void printData( const char a[], const size_t rows, const size_t colls )
{
    assert( a != NULL );
    
    for( int i = 0; i < rows; i++ )
    {
        for( int j = 0; j < colls; j++ )
        {
            putchar( a[i * colls + j] );
        }
        putchar( '\n' );
    }
}

void printData( const char a[] )
{
    assert( a != NULL );

    int rows = a[0];
    int colls = a[1];
    int gap = 2;

    for( int i = 0; i < rows; i++ )
    {
        for( int j = 0; j < colls; j++ )
        {
            putchar( a[i * colls + j + gap] );
        }
        putchar( '\n' );
    }
}

void fscanData( FILE* fp, char a[], const size_t rows, const size_t colls )
{
    assert( fp != NULL );
    assert( a != NULL );

    for( int i = 0; i < rows; i++ )
    {
        if( fscanf( fp, "%s", a + i * colls ) != 1 )
            return;
    }
}

void scanData( char a[], const size_t rows, const size_t colls )
{
    assert( a != NULL );

    fscanData( stdin, a, rows, colls );
}
