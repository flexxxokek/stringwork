#include <stdio.h>
#include <assert.h>

#include "constants.h"
#include "stroki.h"

void printData( const char strData[], const size_t rows, const size_t cols );

void printData( const char strData[] );

void fscanData( FILE* fp, char* strData[], char* buffer, const size_t rows );

void fscanData( FILE* fp, char* strData[], char* buffer );

int main( const int argc, const char** argv )
{
    char buffer[MAX_STR_LENGTH] = {};

    char* text2[MAX_STR_NUM] = {};

    FILE* fp = fopen( "text1.txt", "r" );

    fscanData( fp, text2, buffer );

    for( int i = 0; i < MAX_STR_NUM / 128; i++ )
    {
        printf( "%p %s\n", text2[i],  text2[i] );
    }

    for( int i = 0; i < MAX_STR_NUM / 128; i++ )
    {
        free( text2[i] );
    }
    
    return 0;
}

/*void printData( const char strData[], const size_t rows, const size_t cols )
{
    assert( strData != NULL );
    
    for( int i = 0; i < rows; i++ )
    {
        for( int j = 0; j < cols; j++ )
        {
            putchar( strData[i * cols + j] );
        }
        putchar( '\n' );
    }
}

void printData( const char strData[] )
{
    assert( strData != NULL );

    int rows = strData[0];
    int cols = strData[1];
    int gap = 2;

    for( int i = 0; i < rows; i++ )
    {
        for( int j = 0; j < cols; j++ )
        {
            putchar( strData[i * cols + j + gap] );
        }
    }
}*/

void fscanData( FILE* fp, char* strData[], char* buffer, const size_t rows )
{
    assert( fp != NULL );
    assert( strData != NULL );

    for( int i = 0; i < rows; i++ )
    {
        fgets( fp, buffer );

        strData[i] = ( char* ) calloc( MyStrlen( buffer ) + 1, sizeof( char ) );

        MyStrcpy( strData[i], buffer );
    }
}

void fscanData( FILE* fp, char* strData[], char* buffer )
{
    assert( fp != NULL );
    assert( strData != NULL );

    size_t rows = 0;

    fscanf( fp, "%d", &rows );

    fgets( fp );

    fscanData( fp, strData, buffer, rows );
}