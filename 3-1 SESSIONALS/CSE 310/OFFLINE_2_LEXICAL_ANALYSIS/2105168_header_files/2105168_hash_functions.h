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


/*
Digit [0-9]
TooManyDecimalPoint {Digit}+(\.{Digit}+){2,}({Exponent}?\.{Digit}*)?  
ILlFormedNumber {Digit}+\.?{Digit}*{Exponent}\.{Digit}+             ekhaneo first e ekta digit thakbe minimum 
                                                                    then hocche je dot thakteo pare nao thakte pare erpore dot er pore digit thakbe 
                                                                    ei obdi thik ache erpore hocche exponent thakbe ar exponent e jodi doshomik thake tahle
                                                                    wrong ar erporer digit plus hocche dot er pore number thake je ogulit jonne
                                                                    
InvalidSuffixPrefix [0-9]+[_a-zA-Z]+                                 ltter er age number thakle shtea invalid suffix
Constant_Integer [0-9]+
MultiCharError \'([^\'\\\n]{2,})\'                                  ekhane single quote dekhe bujhbo je eta character abar last e arekta single quote ache eta 
                                                                    indicates eta character howa uchit kintu hocche je ermoddhe abar jodi charc 2 bar repeat hoy 
                                                                    tahole toh wrong . tobe jodi kina \ thake tahole to oita escape sequence er shuru hote pare shejonne amra 
                                                                    ^ chinho use korlam
UnfinishedCharacter \'([^\'\\\n]|\\[^\'\n])                         union ache ekhane 
                                                                    unior er first part e shegula catch kori jader shurte single quote thakleo
                                                                    sheshe nei ar second part e escape sequence capture kori mane hocche 
                                                                    end quote nei abar invalid escape sequence o capture kore 
UnfinishedEmptyBackSlash \'\\\'                                     '\'
EmptyCharacterConstantError \'\'                                    ''

Identifier [_a-zA-Z][_a-zA-Z0-9]*
Char_Literals \'(\\[nt\\'"abfrv0]|[^\'\\\n])\'                      shuru sheshe single quote ache 
                                                                    ar etka union ache. union er first part determine kore escape sequence kina 
                                                                    ar second part determine kore hocche je jodi escape sequence na hole kono character kina
UnterminatedQuote \'
Exponent ([Ee][+-]?{Constant_Integer})
Fraction \.{Constant_Integer}
Float ({Digit}+{Fraction}?|{Fraction}){Exponent}?
INCOP (\+\+|--)
ADDOP [+-] 
MULOP [%]
RELOP (<|<=|>|>=|==|!=)
ASSIGNOP [=]
LOGICOP (&&|\|\|)
NOT [!]
LPAREN [(]
RPAREN [)]
LCURL [{]
RCURL [}]
LTHIRD (\[)
RTHIRD (\])
COMMA  [,]
SEMICOLON [;]


Newline \n
 */