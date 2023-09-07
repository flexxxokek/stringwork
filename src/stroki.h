#include <stdio.h>

int MyPuts( const char* str);

char* MyStrchr( const char* str, int ch);

size_t MyStrlen( const char* str);

char* MyStrcpy( char* dest, char* src );

void MyStrncpy( char* dest, char* src, size_t count );

void MyStrcat( char* dest, char* src );

void MyStrncat( char* dest, char* src, size_t count );

int isNum( char ch );

void fgets( FILE* fp, char* str );

void fgets( FILE* fp );

/*int fstrTabSkip( FILE* fp );

int fgets( FILE* fp, char* s);

int fgetInt( FILE* fp, char* str );*/
