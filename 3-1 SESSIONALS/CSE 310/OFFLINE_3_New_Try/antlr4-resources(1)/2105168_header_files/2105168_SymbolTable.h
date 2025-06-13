#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H

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
    int last_found_index = -1 ;
    int last_found_chain_position = -1;
    string last_found_scope_id ;


    
public:
int destructor_calls = 0;

    int scope_id_counter = 1;
    SymbolTable(int num_buckets)
    {
        //this->current_scope = nullptr;
        this->current_scope = new ScopeTable(num_buckets , "1" , nullptr);
        this->num_buckets = num_buckets;
        this->scope_id_counter = 1;
       // EnterScope();
    }
    ~SymbolTable()
    {


        while (current_scope != nullptr)
        {
            ScopeTable *temp = current_scope->getParentScope();
            delete current_scope; // current delete korlam
            current_scope = temp; // current er moddhe current er parent
        }
        //destructor_calls++;

    }
   
    void EnterScope()
    {
        string new_id;
        
        if (current_scope == nullptr) {
            new_id = "1";  // global scope
        } 
        else {
            current_scope->child_count++;
            new_id = current_scope->id + "." + to_string(current_scope->child_count);
        }

        ScopeTable *new_scope = new ScopeTable(num_buckets, new_id, current_scope);
        current_scope = new_scope;

      //  cout << "ScopeTable# " << current_scope->id << " created" << endl;
    }


    void ExitScope()
    {
        
            if(current_scope == NULL) return;
           // cout << "Exited ScopeTable # " << current_scope->id << endl;

            ScopeTable *temp = current_scope;
            current_scope = current_scope->getParentScope();
            temp->setParentScope(NULL);
            delete temp;
        
            //cout << "Exited ScopeTable # " << current_scope->id << endl;
       
    }

    bool Insert(string symbol_name, string type)
    {
        
            if (!current_scope) return false;
           // cout << "insert " << endl;
            return current_scope->Insert(symbol_name, type);
        
    }

    bool Remove(string symbol_name)
    {

       if (!current_scope) return false;
       return current_scope->Delete(symbol_name);
    }

    SymbolInfo *LookUP(string symbol_name)
    {
        ScopeTable *current = current_scope;

        while (current != NULL)
        {
            SymbolInfo *lookup = current->LookUP(symbol_name);
            if (lookup != NULL)
            {
                unsigned int index = current->getSDBMHashIndex(symbol_name) % current->num_buckets;
                SymbolInfo *temp = current->hashtable[index];
                int chain_position = 1;
                while (temp != NULL)
                {
                    if (temp->getSymbolName() == symbol_name)
                    {
                        last_found_index  = index;
                        last_found_chain_position = chain_position;
                        last_found_scope_id = current->id;

                        break;
                    }
                    temp = temp->getNext();
                    chain_position++;
                }

                // cout << "Found in ScopeTable# " << current->id
                //      << " at position <" << index + 1 << ", " << chain_position << ">" << endl;
                return lookup;
            }

            current = current->getParentScope();
        }
        return NULL;
    }

    void print_current_scope_table(FILE* out)
    {
        current_scope->print(out, 1);
    }


    void print_all_scope_table2(FILE* out) {
        ScopeTable *temp = current_scope;
        int i = 1;
        while(temp != NULL){
            temp->print(out,i);
            temp = temp->getParentScope();

            i++;
        }
    }
    

    // void print_all_scope_table(FILE* out) {
    //     print_all_helper(current_scope, 0,out);
    // }
    
    // void print_all_helper(ScopeTable* scope, int depth , FILE* out) {
    //     if (scope == NULL) return;
    
    //     for (int i = 0; i < depth+1; i++) fprintf(out, "\t");
    //     fprintf(out, "ScopeTable# %s\n", scope->id.c_str());    
    //     for (int i = 0; i < scope->num_buckets; i++) {
            
    //         for (int j = 0; j < depth+1; j++) fprintf(out, "\t");;
    //         fprintf(out, "%d-->", i + 1);
    //         SymbolInfo* temp = scope->hashtable[i];
    //         while (temp != NULL) {
    //             fprintf(out, " <%s,%s>", temp->getSymbolName().c_str(), temp->getSymbolType().c_str());              
    //             temp = temp->getNext();
    //         }

    //         fprintf(out, "\n");   
    //         }
    //         print_all_helper(scope->getParentScope(), depth + 1, out);
    // }
    
    void setHashFucntion(int choice){
        current_scope->setChoiceHash(choice);
    }

    int getCollsionCount(){
        return current_scope->getNumberOfCollisions();
    }

    

    string getCurrentScopeID()
    {
        return current_scope->id;
    }

    int getIndex()
    {
        return current_scope->getIndex();
    }

    int getCurrPos()
    {
        return current_scope->getChainPos();
    }

    int getFoundIndex(){
        return last_found_index;
    }
    int getFoundChainPos(){
        return last_found_chain_position;
    }

    string getFoundScopeID(){
        return last_found_scope_id;
    }

    ScopeTable *getCurrentScope(){
        return current_scope;
    }

    void printCurrentScopeID()
    {
        // cout << "\t";
        //cout << "ScopeTable# " << current_scope->id << " created" << endl;
    }

    int getDestructorCalls(){
        return destructor_calls;
    }
};

#endif