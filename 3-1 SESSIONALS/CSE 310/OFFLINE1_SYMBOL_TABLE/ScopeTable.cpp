#include <bits/stdc++.h>
#include <string>
#include "SymbolInfo.h"
#include "hash_functions.h"
using namespace std;


class ScopeTable
{
private:
    /* data */

    unsigned int getSDBMHashIndex(string str){

    }
    
public:
   
    int num_buckets;
    string id;
    SymbolInfo **hashtable;
    ScopeTable *parent_scope;

    ScopeTable(int num_buckets , ScopeTable *parent_scope){

        this->num_buckets = num_buckets;
        hashtable = new SymbolInfo *[num_buckets];
        this->parent_scope = parent_scope;
        this->id ="1";

        for (int i = 0; i < num_buckets; i++)
        {
            /* code */

            hashtable[i] = NULL;
        }
        
        




    }

    ~ScopeTable(){

        for (int i = 0; i < num_buckets; i++)
        {
            /* code */
            SymbolInfo *temp = hashtable[i];
            while(temp!= NULL){

                SymbolInfo *next = temp->getNext();
                delete temp;
                temp = next;
            }
        }
        
        delete [] hashtable;
    }



    bool Insert(string symbole_name , string symbol_type){

        if(check_present_in_scopetable(symbole_name)){
            return false;
        }

        else{

            unsigned int index = getSDBMHashIndex(symbole_name) % num_buckets;

            SymbolInfo *new_symbol = new SymbolInfo(symbole_name , symbol_type);

            if(hashtable[index] == NULL){
                hashtable[index] = new_symbol;
                return true;
            }

            else{

                SymbolInfo *temp = hashtable[index];
                while(temp->getNext() != NULL){
                    temp = temp->getNext();
                }

                temp->setNext(new_symbol);
                return true;
            }


        }


    }


    // bool Delete(string symbol_name){

    //     unsigned int index = getSDBMHashIndex(symbol_name) % num_buckets;

    //     SymbolInfo *temp = hashtable[index];
    //     SymbolInfo *prev = NULL;

    
        

    // }


    bool check_present_in_scopetable(string symbol_name){

        for (int i = 0; i < num_buckets; i++)
        {
            /* code */
            SymbolInfo *temp = hashtable[i];
            while (temp != NULL){

                if(temp->getSymbolName()  == symbol_name){

                    return true;
                }
                
                temp = temp->getNext();

            }
            
            
        }
        
        return false;
        
    }

    SymbolInfo *Look_Up(string symbol_name){

    }

    bool Delete(string sybol_name){

    }

    void Print(){

    }


};

