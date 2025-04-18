#ifndef SYMBOLINFO_H
#define SYMBOLINFO_H
#include <bits/stdc++.h>
#include <string>

using namespace std;
class SymbolInfo
{
private:
    /* data */
    string symbol_name;
    string symbol_type;
    SymbolInfo *next;


    
public:

    SymbolInfo(string symbol_name , string symbol_type){
        this->symbol_name = symbol_name;
        this->symbol_type = symbol_type;
        this->next = NULL;

        cout << "Constructor called in symbolinfo class" << endl;


    }
    ~SymbolInfo();

    string getSymbolName(){
        return symbol_name;
    }

    string getSymbolType(){
        return symbol_type;
    }

    void setSymbolName(string symbol_name){
        this->symbol_name = symbol_name;
    }

    void setSymbolType(string symbol_type){
        this->symbol_type = symbol_type;
    }

    SymbolInfo *getNext(){
        return next;
    }

    void setNext(SymbolInfo *next){
        this->next = next;
    }
};

SymbolInfo::~SymbolInfo()
{
    cout << "Destructor called in symbolinfo class" << endl;
}


// int main(){
//     SymbolInfo *symbol = new SymbolInfo("x" , "int");
// }

#endif // SYMBOLINFO_H