#ifndef SCOPETABLE_H
#define SCOPETABLE_H

#include <bits/stdc++.h>
#include <string>
#include "2105168_SymbolInfo.h"
#include "2105168_hash_functions.h"
using namespace std;

class ScopeTable
{
private:
    /* data */

    int chain_position = 1;
    int number_of_collisions = 0;
    int choice_hash = 1;

public:
    int num_buckets;
    string id;
    SymbolInfo **hashtable;
    ScopeTable *parent_scope;
    int child_count = 0;
    unsigned int index;

    ScopeTable(int num_buckets, string id, ScopeTable *parent_scope)
    {

        this->num_buckets = num_buckets;
        hashtable = new SymbolInfo *[num_buckets];
        this->parent_scope = parent_scope;
        this->id = id;

        for (int i = 0; i < num_buckets; i++)
        {
            /* code */

            hashtable[i] = NULL;
        }
    }

    ~ScopeTable()
    {

        for (int i = 0; i < num_buckets; i++)
        {
            /* code */
            SymbolInfo *temp = hashtable[i];
            while (temp != NULL)
            {

                SymbolInfo *next = temp->getNext();
                delete temp;
                temp = next;
            }
        }

        delete[] hashtable;
    }

    unsigned int getSDBMHashIndex(string str)
    {
        return SDBMHash(str, num_buckets);
    }

    unsigned int getHashIndex(string str){
        return calculateHash(str , choice_hash);
    }
    bool Insert(string symbole_name, string symbol_type)
    {

        if (check_present_in_scopetable(symbole_name))
        {
            return false;
        }

        else
        {

            number_of_collisions++;
            index = getHashIndex(symbole_name) % num_buckets;

            SymbolInfo *new_symbol = new SymbolInfo(symbole_name, symbol_type);

            chain_position = 1;
            if (hashtable[index] == NULL)
            {
                hashtable[index] = new_symbol;
                return true;
            }

            else
            {


                SymbolInfo *temp = hashtable[index];
                // chain_position = 2;

                while (temp->getNext() != NULL)
                {
                    temp = temp->getNext();
                    chain_position++;
                }

                temp->setNext(new_symbol);
                chain_position++;
            }

            return true;
        }
    }

    bool Delete(string symbol_name)
    {

        unsigned int idx = getHashIndex(symbol_name) % num_buckets;
        int pos = 1;
        SymbolInfo *temp = hashtable[idx];
        SymbolInfo *prev = NULL;

        while (temp != NULL)
        {

            if (temp->getSymbolName() == symbol_name)
            {

                if (prev == NULL)
                {
                    hashtable[idx] = temp->getNext();
                }
                else
                {
                    prev->setNext(temp->getNext());
                }

                index = idx;
                chain_position = pos;
                delete temp;
                return true;
            }

            prev = temp;
            temp = temp->getNext();
            pos++;
        }

        return false;
    }

    bool check_present_in_scopetable(string symbol_name)
    {
        // unsigned int index = getSDBMHashIndex(symbol_name)% num_buckets;

        for (int i = 0; i < num_buckets; i++)
        {
            /* code */
            SymbolInfo *temp = hashtable[i];
            while (temp != NULL)
            {

                if (temp->getSymbolName() == symbol_name)
                {

                    return true;
                }

                temp = temp->getNext();
            }
        }

        return false;
    }

    SymbolInfo *LookUP(string symbol_name)
    {

        unsigned int index = calculateHash(symbol_name , choice_hash) % num_buckets;
        SymbolInfo *temp = hashtable[index];
        int chain_pos = 1;

        while (temp != NULL)
        {
            if (temp->getSymbolName() == symbol_name)
            {
                return temp;
            }

            temp = temp->getNext();
            chain_pos++;
        }

        return NULL;
    }

    ScopeTable *getParentScope()
    {
        return parent_scope;
    }

    void setParentScope(ScopeTable *parent)
    {

        this->parent_scope = parent;
    }

    int getScopeTableID()
    {
        return stoi(id);
    }

    int getIndex()
    {
        return this->index;
    }

    int getChainPos()
    {
        return this->chain_position;
    }

    int getNumberOfCollisions(){
        return number_of_collisions;
    }


    void setChoiceHash(int choice_hash){
        this->choice_hash = choice_hash;
    }
    unsigned int calculateHash(string symbol_name , int choice_hash){


        switch (choice_hash)
        {
        case 1:
            return SDBMHash(symbol_name, num_buckets);
            break;
        case 2:
            return aux_hash(symbol_name , num_buckets);
            break;
        case 3:
            return polynomial_rolling_hash(symbol_name , num_buckets);
            break;
        
        default:
            return SDBMHash(symbol_name, num_buckets);
            break;
        }
        
        
    }
    void print(int indent) {
        for (int i =1; i <= indent; i++) cout << "\t";
        cout << "ScopeTable# " << id << endl;
        for (int i = 0; i < num_buckets; i++) {
            for (int i =1; i <= indent; i++) cout << "\t";
            cout << i + 1 << "--> "; 
            SymbolInfo* temp = hashtable[i];
            while (temp != NULL) {
                cout << "<" << temp->getSymbolName() << "," << temp->getSymbolType() << "> ";
                temp = temp->getNext();
            }
            cout << endl;
        }
    }
    
};

#endif