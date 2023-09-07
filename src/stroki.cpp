#include <stdio.h>
#include <assert.h>

#include "stroki.h"

//puts, strchr, strlen, strcpy, strncpy, strcat, strncat, fgets, strdup, getline

int MyPuts( const char* str)
{
    assert( str != NULL);

    for( size_t i; str[i]; i++ )
        if( putchar( str[i] ) != 1 )
            return EOF;

    printf( "\n" );

    return 0;
}

char* MyStrchr( const char* str, int ch)
{
    assert( str != NULL);
    // ( str )
    for( size_t i = 0; str[i]; i++ )
        if( str[i] == ch )
            return ( char*) str + i;

    return NULL;
}

size_t MyStrlen( const char* str)
{
    assert( str != NULL);

    size_t i = 0;

    for( ; str[i] != '\0'; i++)
        ;

    return i;
}

char* MyStrcpy( char* dest, char* src )
{
    assert( dest != NULL);
    assert( src != NULL);
    assert( src != dest);

    while( *src )
        *dest++ = *src++;

    *dest = '\0';

    return dest;
}

void MyStrncpy( char* dest, char* src, size_t count )
{
    assert( dest != NULL);
    assert( src != NULL);
    assert( src != dest);

    for( size_t i = 0; i < count; i++)
    {
        if( !*src )  
            *dest++ = *src++;
        else
        {
            for( int j = i; j < count; i++ )
                *dest++ = '\0';
            
            return;
        }
    }
}

void MyStrcat( char* dest, char* src )
{
    dest += MyStrlen( dest );

    MyStrcpy( dest, src );
}


void MyStrncat( char* dest, char* src, size_t count )
{
    while( *dest++ )
        ;
    
    dest--;

    MyStrncpy( dest, src, count );
}

int isNum( char ch )
{
    if( ch <= '9' && ch >= '0' )
        return true;
    
    return false;
}

void fgets( FILE* fp, char* str )
{
    for( int ch = 0; ( ch = getc( fp ) ) != EOF && ch != '\n'; )
        *str++ = ch;
    
    *str = '\0';
}

void fgets( FILE* fp )
{
    for( int ch = 0; ( ch = getc( fp ) ) != EOF && ch != '\n'; )
        ;
}
