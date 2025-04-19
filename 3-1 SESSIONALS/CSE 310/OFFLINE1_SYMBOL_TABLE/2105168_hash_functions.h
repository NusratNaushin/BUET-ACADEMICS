#ifndef HASH_FUNCTIONS_H
#define HASH_FUNCTIONS_H

#include <string>
using namespace std;

static unsigned int SDBMHash(string str)
{
    unsigned int hash = 0;
    unsigned int i = 0;
    unsigned int len = str.length();

    for (i = 0; i < len; i++)
    {
        hash = (str[i]) + (hash << 6) + (hash << 16) - hash;
    }

    return hash;
}

#endif
