#include <stdio.h>

void printData( const struct Fileinf* text );

void getFilename( struct Fileinf* text );

void fscanData( FILE* fp, char* strData[], const size_t rows );

void fscanData( FILE* fp, char* strData[] );

void freeData( const char** strData );

void getFileSize( struct Fileinf* text );

void fileToBuff( struct Fileinf* text );

int parseBuff( struct Fileinf* text );

void freeFileinf( struct Fileinf* text );

void fillFileinf( struct Fileinf* text );

void printFileinfBuff( struct Fileinf* text );

int getNlines( struct Fileinf* text );
