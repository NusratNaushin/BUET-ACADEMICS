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
    SymbolTable(ScopeTable *current_scope , int num_buckets)
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

    void EnterScope(){

        ScopeTable *new_scope = new ScopeTable(num_buckets , current_scope);

        current_scope = new_scope;


    }
};
