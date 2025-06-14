#ifndef SYMBOLINFO_H
#define SYMBOLINFO_H
#include <string>
#include <iostream>


// using namespace std;
class SymbolInfo
{
private:
    /* data */
    std::string symbol_name;
    std::string symbol_type;
    SymbolInfo *next;


    
public:

    SymbolInfo(std::string symbol_name , std::string symbol_type){
        this->symbol_name = symbol_name;
        this->symbol_type = symbol_type;
        this->next = NULL;

      //  cout << "Constructor called in symbolinfo class" << endl;


    }
    

    std::string getSymbolName(){
        return symbol_name;
    }

    std::string getSymbolType(){
        return symbol_type;
    }

    void setSymbolName(std::string symbol_name){
        this->symbol_name = symbol_name;
    }

    void setSymbolType(std::string symbol_type){
        this->symbol_type = symbol_type;
    }

    SymbolInfo *getNext(){
        return next;
    }

    void setNext(SymbolInfo *next){
        this->next = next;
    }
};

// SymbolInfo::~SymbolInfo()
// {
//     //cout << "Destructor called in symbolinfo class" << endl;
// }


// int main(){
//     SymbolInfo *symbol = new SymbolInfo("x" , "int");
// }

#endif //SYMBOLINFO_H