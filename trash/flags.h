#include "constants.h"

void parseFlags( const int argc, const char** argv );

char* flagOpen( const int argc, const char** argv );

struct flagData
{
    char name[MAX_FLAG_LENGTH];
    char* ( *action )( const int argc, const char** argv );
};

const struct flagData FLAGS[1] =
{
    {"-o", &flagOpen}
};