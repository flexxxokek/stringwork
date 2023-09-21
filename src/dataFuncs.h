#include <stdio.h>

void printData( const struct Fileinf* text );

void getFilename( struct Fileinf* text );

void fscanData( FILE* fp, char* strData[], const size_t rows );

void fscanData( FILE* fp, char* strData[] );

void freeData( const char** strData );

void getFileSize( struct Fileinf* text );

void fileToBuff( struct Fileinf* text );

size_t parseBuff( struct Fileinf* text );

void freeFileinf( struct Fileinf* text );

void fillFileinf( struct Fileinf* text );

void printFileinfBuff( struct Fileinf* text );

size_t getNlines( struct Fileinf* text );

void myBubbleSort( void* arr, size_t len, size_t elSize, int ( *cmp )( const void* a, const void* b ) );
