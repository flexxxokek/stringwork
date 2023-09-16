const int MAX_STR_LENGTH = 1024;
const int MAX_STR_NUM = 1024;
const int MAX_FLAG_LENGTH = 16;
const int MAX_FILE_NAME_LENGTH = 16;
const int FLAG_NUM = 1;

enum FilePointerErrors
{
    FILE_POINTER_IS_NULL = 102, NO_PERMISSION_FOR_FILE = 404
};

struct Fileinf
{
    char filename[MAX_FILE_NAME_LENGTH];
    
    size_t size;

    size_t trueSize;

    unsigned int nlines;

    char* buff;

    char ** strData;
};
