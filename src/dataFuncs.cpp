#include <stdio.h>
#include <assert.h>
#include <sys\stat.h>
#include <sys\file.h>

#include "stroki.h"
#include "constants.h"
#include "dataFuncs.h"

void printData( const struct Fileinf* text )
{
    assert( text->strData != NULL );
    
    for( int i = 0; i < text->nlines; i++ )
        MyPuts( text->strData[i] );
}

void getFilename( struct Fileinf* text )
{
    printf( "Enter file name: ");

    fgets( stdin, text->filename );
}

void swapp( void** a, void** b )
{
    void* temp = *a;
    *a = *b;
    *b = temp;
}

/*
1. strDate create
2. strData fill
*/
void fscanData( FILE* fp, char* strData[], const size_t rows )
{
    assert( fp != NULL );
    assert( strData != NULL );

    char buffer[MAX_STR_LENGTH] = {};

    for( int i = 0; i < rows; i++ )
    {
        size_t len = fgets( fp, buffer );

        strData[i] = ( char* ) calloc( MyStrlen( buffer ) + 1, sizeof( char ) );

        printf( "%d", len );

        MyStrncpy( strData[i], buffer, len + 1 );
    }
}

void fscanData( FILE* fp, char* strData[] )
{
    assert( fp != NULL );
    assert( strData != NULL );

    size_t rows = 0;

    fscanf( fp, "%d", &rows );

    fscanData( fp, strData, rows );
}

void freeData( const char ** strData )
{
    assert( strData != NULL );

    const char* p = NULL;

    for( int i = 0; i < MAX_STR_NUM; i++ )
    {
        p = *strData++;
        
        free( ( void* ) p );
    }
}

static int checkFilePointer( FILE* fp, int* err = 0 )
{
    if( fp == NULL )
    {
        *err = FILE_POINTER_IS_NULL;

        printf( "File pointer is NULL" );

        return FILE_POINTER_IS_NULL;
    }

    return 0;
}

void getFileSize( struct Fileinf* text )
{   
    struct stat fileStat = {};

    stat( text->filename, &fileStat );

    text->size = fileStat.st_size;
}

void fileToBuff( struct Fileinf* text )
{
    if( !text->size )
    {
        printf( "File \"%s\" doesn't exist\n", text->filename );

        return;
    }

    FILE* fp = fopen( text->filename, "r" );
    checkFilePointer( fp );

    text->buff = ( char* ) calloc( text->size + 1, sizeof( char ) );

    text->trueSize = fread( text->buff, sizeof( char ), text->size / sizeof( char ), fp );

    if( text->trueSize == 0 )
    {
        printf( "File wasn't read successfully!\n" );

        return;
    }
}

int parseBuff( struct Fileinf* text )
{
    text->strData[0] = text->buff;

    int nlines = 1;

    for( int i = 0; i < text->trueSize; i++ )
    {
        if( text->buff[i] == '\n' )
        {
            text->strData[nlines] = text->buff + i + 1;

            nlines++;

            text->buff[i] = '\0';
        }
    }

    text->nlines = nlines;

    return text->trueSize;
}

void freeFileinf( struct Fileinf* text )
{
    free( text->buff );
    free( text->strData );
}

void fillFileinf( struct Fileinf* text )
{
    getFilename( text );

    getFileSize( text );    

    fileToBuff( text );

    getNlines( text );

    text->strData = ( char** ) calloc( text->nlines, sizeof( char* ) );

    parseBuff( text );
}

void printFileinfBuff( struct Fileinf* text )
{
    for( int i = 0, k = 0; i < text->nlines; i++ )
    {
        k += MyPuts( text->buff + k ) + 1;
    }
}

int getNlines( struct Fileinf* text )
{
    int nlines = 0;

    for( int i = 0; i < text->trueSize; i++ )
        if( text->buff[i] == '\n' )
            nlines++;

    text->nlines = nlines;
    
    return nlines;
}