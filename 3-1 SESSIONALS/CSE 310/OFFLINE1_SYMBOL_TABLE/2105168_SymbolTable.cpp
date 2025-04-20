#include <bits/stdc++.h>
#include <string>
#include "2105168_ScopeTable.h"

using namespace std;

class SymbolTable
{
private:
    /* data */

    int num_buckets;
    ScopeTable *current_scope;

public:

    int scope_id_counter = 1;
    SymbolTable(ScopeTable *current_scope, int num_buckets)
    {

        this->current_scope = current_scope;
        this->num_buckets = num_buckets;
    }
    ~SymbolTable()
    {

        while (current_scope != NULL)
        {
            ScopeTable *temp = current_scope->getParentScope();
            delete current_scope; // current delete korlam
            current_scope = temp; // current er moddhe current er parent
        }
    }

    void EnterScope()
    {
        string new_id;

        if(current_scope == nullptr){
            new_id = "1";
        }

        else{
            current_scope->child_count++;
            new_id = current_scope->id + "." + to_string(current_scope->child_count);
        }

        ScopeTable *new_scope = new ScopeTable(num_buckets, new_id ,current_scope);

        this->current_scope = new_scope;
    }

    void ExitScope()
    {
        if (current_scope->getParentScope() != NULL)
        {
            ScopeTable *temp = current_scope;
            current_scope = current_scope->getParentScope();
            temp->setParentScope(NULL);
            delete temp;
        }

        else
        {
            cout << "No scope to exit" << endl;
        }
    }

    void Insert(string symbol_name, string type)
    {
        if (current_scope->Insert(symbol_name, type) == false)
        {
            cout << "Already exists in current scope" << endl;
        }
        else
        {

            current_scope->Insert(symbol_name, type);
        }
    }

    void Remove(string symbol_name)
    {

        if (current_scope->Delete(symbol_name) == false)
        {
            cout << "Not found in the current scope" << endl;
        }

        else
        {
            current_scope->Delete(symbol_name);
        }
    }

    SymbolInfo *LookUP(string symbol_name)
    {
        ScopeTable *current = current_scope;

        while (current != NULL)
        {
            SymbolInfo *lookup = current->LookUP(symbol_name);
            if (lookup != NULL)
            {
                unsigned int index = current->getSDBMHashIndex(symbol_name)%current->num_buckets;
                SymbolInfo *temp = current->hashtable[index];
                int chain_position = 1;
                while (temp != NULL)
                {
                    if (temp->getSymbolName() == symbol_name)
                    {
                        break;
                    }
                    temp = temp->getNext();
                    chain_position++;
                }

                cout << "Found in ScopeTable# " << current->id
                     << " at position <" << index + 1 << ", " << chain_position << ">" << endl;
                return lookup;
            }

            current = current->getParentScope();
        }

        cout << " Not  Found " << endl;
        return NULL;
    }

    void print_current_scope_table()
    {
        current_scope->print();
    }

    void print_all_scope_table()
    {
        ScopeTable *current = current_scope;

        while (current != NULL)
        {
            current->print();
            current = current->getParentScope();
        }
    }
};

