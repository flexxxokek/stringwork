#include <stdio.h>
#include <assert.h>
#include <sys\stat.h>
#include <sys\file.h>

#include "stroki.h"
#include "constants.h"
#include "dataFuncs.h"

static void* pushVoidPtr( void* ptr, size_t bytes )
{
    return ( void* )( ( ( char* ) ptr ) + bytes );
}

void printData( const struct Fileinf* text )
{
    assert( text->strData != NULL );
    
    for( int i = 0; i < text->nlines; i++ )
    {
        printf( "%d ", text->strData[i].len );
    
        MyPuts( text->strData[i].ptr );
    }
}

void getFilename( struct Fileinf* text )
{
    printf( "Enter file name: ");

    fgets( stdin, text->filename );
}

static void swap( void* a, void* b, size_t elSize )
{
    void* temp = calloc( 1, elSize );
    memcpy( temp, a, elSize );

    memcpy( a, b, elSize );

    memcpy( b, temp, elSize );

    free( temp );
}

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

void freeData( char ** strData )
{
    assert( strData != NULL );

    for( int i = 0; i < MAX_STR_NUM; i++ )
    {
        free( *strData );

        *strData = nullptr;

        strData++;
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

int parseBuff( struct Fileinf* text ) // нулевой эл. 
{
    text->strData[0].ptr = text->buff;

    int nlines = 1;

    for( int i = 0; i < text->trueSize; i++ )
    {
        if( text->buff[i] == '\n' )
        {
            text->strData[nlines - 1].len = ( size_t )( text->buff + i - text->strData[nlines - 1].ptr );

            text->strData[nlines].ptr = text->buff + i + 1;

            nlines++;

            text->buff[i] = '\0';
        }
    }

    text->strData[nlines - 1].len = ( size_t )( text->buff + text->trueSize - text->strData[nlines - 1].ptr );

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

    text->strData = ( struct String* ) calloc( text->nlines, sizeof( String* ) );

    parseBuff( text );
}

void printFileinfBuff( struct Fileinf* text )
{
    for( int i = 0, currPos = 0; i < text->nlines; i++ )
    {
        currPos += MyPuts( text->buff + currPos ) + 1;
    }
}

int getNlines( struct Fileinf* text )
{
    int nlines = 1;

    for( int i = 0; i < text->trueSize; i++ )
        if( text->buff[i] == '\n' )
            nlines++;

    text->nlines = nlines;
    
    return nlines;
}

void myBubbleSort( void* arr, size_t len, size_t elSize, int ( *cmp )( const void* a, const void* b ) )
{
    for( int i = 0; i < 1; i++ )
        for( int j = 0; j < len - 1; j++ )
            if( cmp( pushVoidPtr( arr, j * elSize ), pushVoidPtr( arr, ( j + 1 ) * elSize ) ) > 0 )
                swap( pushVoidPtr( arr, j * elSize ), pushVoidPtr( arr, ( j + 1 ) * elSize ), elSize );
}