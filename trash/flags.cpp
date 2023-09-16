#include <string.h>

#include "constants.h"
#include "flags.h"

/*void parseFlags( const int argc, const char** argv )
{
    for( int i = 1; i < argc; i++ )
    {
        for( int j = 0; i < FLAG_NUM; j++ )
        {
            if( strcmp(argv[i], FLAGS[j].name ) )
            {
                FLAGS[j].action( argc, argv );
            }
        }
    }
}*/

char* flagOpen( const int /*argc*/, const char** argv)
{
    return ;
}