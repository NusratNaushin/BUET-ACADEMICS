#ifndef HASH_FUNCTIONS_H
#define HASH_FUNCTIONS_H

#include <string>
using namespace std;
// unsigned int SDBMHash(string str, unsigned int num_buckets)
// {
//     unsigned int hash = 0;

//     unsigned int len = str.length();

//     for (unsigned int i = 0; i < len; i++)
//     {
//         hash = ((str[i]) + (hash << 6) + (hash << 16) - hash) %
//                num_buckets;
//     }

//     return hash;


// }

unsigned int SDBMHash(const char *p) {
unsigned int hash = 0;
auto *str = (unsigned char *) p;
int c{};
while ((c = *str++)) {
hash = c + (hash << 6) + (hash << 16) - hash;
}
return hash;
}

unsigned int aux_hash(string str  , unsigned int num_buckets){

    int  hash = 1;
        //  long long N = n;
        for (int i = 0; i < str.length(); i++)
        {
            hash = ((hash * 37) + ((unsigned int)str[i])) % num_buckets;
        }
        hash = (hash * 10 + 1) % num_buckets;
        if (hash < 0)
            hash += num_buckets;
        return hash;

}


unsigned int polynomial_rolling_hash(string str , unsigned int num_buckets){

    unsigned int hash = 0;
    for (unsigned int i = 0; i < str.length(); i++)
    {
        hash = (unsigned int)37 * hash + (unsigned int)str[i];
    }
    hash %= num_buckets;
    return hash;

}
#endif 
