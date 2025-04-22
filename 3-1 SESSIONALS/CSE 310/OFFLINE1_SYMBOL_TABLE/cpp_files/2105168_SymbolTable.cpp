#include <bits/stdc++.h>
#include <string>
#include "cpp_files/2105168_ScopeTable.h"

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

        string new_id = to_string(scope_id_counter++);

        // if (current_scope == nullptr)
        // {
        //     new_id = "1";
        // }

        // else
        // {
            // current_scope->child_count++;
            // // new_id = current_scope->id + "." + to_string(current_scope->child_count);
            // new_id = to_string(stoi(current_scope->id) + 1);
       // }

        ScopeTable *new_scope = new ScopeTable(num_buckets, new_id, current_scope);

        current_scope = new_scope;
    }

    void ExitScope()
    {
        
            ScopeTable *temp = current_scope;
            current_scope = current_scope->getParentScope();
            temp->setParentScope(NULL);
            delete temp;
        

       
    }

    bool Insert(string symbol_name, string type)
    {
        

            
            return current_scope->Insert(symbol_name, type);
        
    }

    bool Remove(string symbol_name)
    {

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

    void print_current_scope_table()
    {
        current_scope->print();
    }

    void print_all_scope_table() {
        print_all_helper(current_scope, 0);
    }
    
    void print_all_helper(ScopeTable* scope, int depth) {
        if (scope == NULL) return;
    
        // First print current scope with indentation
        for (int i = 0; i < depth; i++) cout << "\t";
        cout << "ScopeTable# " << scope->id << endl;
    
        for (int i = 0; i < scope->num_buckets; i++) {
            for (int j = 0; j < depth; j++) cout << "\t";
            cout << i + 1 << "-->";
            SymbolInfo* temp = scope->hashtable[i];
            while (temp != NULL) {
                cout << " <" << temp->getSymbolName() << "," << temp->getSymbolType() << ">";
                temp = temp->getNext();
            }
            cout << endl;
        }
    
        // Then recursively print parent scopes with increased indentation
        print_all_helper(scope->getParentScope(), depth + 1);
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
        cout << "ScopeTable# " << current_scope->id << " created" << endl;
    }
};

int main()
{

    string input_filename = "sample_input.txt";
    string output_filename = "myoutput.txt";

    freopen(input_filename.c_str(), "r", stdin);
    freopen(output_filename.c_str(), "w", stdout);
    SymbolTable *st = new SymbolTable(NULL, 7);

    int command_count = 0;

    st->EnterScope();

    st->printCurrentScopeID();

    string line;

    while (getline(cin, line))
    {
        string command;
        stringstream ss(line);

        ss >> command;

        if (command == "Q")
        {
            command_count++;
            cout << "Cmd " << command_count << ": " << line << endl;
           
            while(st->getCurrentScope() != NULL){
                string dlt_id = st->getCurrentScopeID();
                st->ExitScope();
                cout << "\t";

                cout << "ScopeTable# " << dlt_id << " removed" << endl;
              }
            break;
        }

        // else if (command == "I")
        // {

        //     command_count++;
        //     string name, type, word;
        //     ss >> name;

        //     type = "";
        //     while (ss >> word)
        //     {
        //         if (!type.empty())
        //         {
        //             type += " ";
        //         }

        //         type += word;
        //     }

        //     st->Insert(name, type);
        //     SymbolInfo *found = st->LookUP(name);

        //     cout << "Cmd " << command_count << ": " << line << endl;

        //     cout << "\t";

            // if (found)
            // {

            //     cout << "Inserted in ScopeTable# " << st->getCurrentScopeID()
            //          << " at position " << st->getIndex() + 1 << ", " << st->getCurrPos() << endl;
            // }
        //     // cout << found->getSymbolName() << " " << found->getSymbolType() << endl;

        //     // cout << "insert " << found->getSymbolName() << " at scope table # " << st->getCurrentScopeID() << " and <" << st->getIndex() + 1 << "," << st->getCurrPos() << ">" << endl;

        //     // cout << found->getSymbolName() << endl;
        // }


        else if (command == "I"){
            command_count++;
            string  name , type , word;
            ss >> name;
            ss >> type ;

            string full_type = type;
            if(type == "STRUCT" || type == "UNION"){

                full_type += " ,{";
                bool flag_for_placing_comma = false;
                string field_type , field_name;
                
                while(ss >> field_type >> field_name){
                    if(flag_for_placing_comma){
                        full_type += ",";
                    }
                    full_type += "(" + field_type + "," + field_name + ")";
                    flag_for_placing_comma = true;
                }

                full_type += "}";

            }

            else if(type == "FUNCTION"){
                string return_type;
                ss >> return_type;

                string arg_type;
                string formatted_args = "";
                bool flag = true;

                while(ss >> arg_type){
                    if(!flag){
                        formatted_args += ",";
                    }

                    formatted_args += arg_type;
                    flag = false;
                }

                full_type = "FUNCTION, " +return_type + "<==(" + formatted_args + ")";
            }

            else{
                while(ss>>word){
                    full_type +=" "+word;
                }
            }

            bool inserted = st->Insert(name , full_type);
            
            SymbolInfo *found = st->LookUP(name);
            cout << "Cmd " << command_count << ": " << line << endl;
            cout << "\t";
            if (inserted)
            {

                cout << "Inserted in ScopeTable# " << st->getCurrentScopeID()
                     << " at position " << st->getIndex() + 1 << ", " << st->getCurrPos() << endl;
            }

            else{
                cout << "'" << name << "' already exists in the current ScopeTable" << endl;
            }
            


        }

        else if (command == "L")
        {

            command_count++;

            string name, type, word;
            ss >> name;

            cout << "Cmd " << command_count << ": " << line << endl;
            cout << "\t";

            if (ss >> word)
            {

                cout << "Number of parameters mismatch for the command L" << endl;
            }

            else
            {
                SymbolInfo *found = st->LookUP(name);

                if (found)
                {
                    cout << "'" << name << "' found in ScopeTable# " << st->getFoundScopeID() << " at position " << st->getFoundIndex() + 1 << ", " << st->getFoundChainPos() << endl;
                }

                else
                {

                    cout << "'" << name << "' not found in any of the ScopeTables" << endl;
                }
            }
        }

        else if (command == "S")
        {
            command_count++;

            string name, type, word;
            if (ss >> name)
            {
                cout << "Number of parameters mismatch for the command L" << endl;
            }

            cout << "Cmd " << command_count << ": " << line << endl;
            cout << "\t";

            st->EnterScope();

            st->printCurrentScopeID();
        }

        else if (command == "D")
        {
            command_count++;
            string name, word , extra;
            cout << "Cmd " << command_count << ": " << line << endl;
            cout << "\t";

            if (!(ss >> name) || ss >> extra) {
                cout << "Number of parameters mismatch for the command D" << endl;
                continue;
            }

            else
            {
                

                if (st->getCurrentScope()->check_present_in_scopetable(name))
                {
                    st->Remove(name);
                    cout << "Deleted '" << name << "' from ScopeTable# " << st->getCurrentScopeID() << " at position " << st->getIndex() + 1 << ", " << st->getCurrPos() << endl;
                }

                else
                {
                    cout << "Not found in the current ScopeTable" << endl;
                }
            }
        }

        else if (command == "P")
        {
            command_count++;
            string argument;
            ss >> argument;

            cout << "Cmd " << command_count << ": " << line << endl;
            cout << "\t";
            if (argument == "A")
            {
                st->print_all_scope_table();
            }
            else if (argument == "C")
            {
                st->print_current_scope_table();
            }

            else
            {
                cout << "Number of parameters mismatch for the command P" << endl;
            }
        }

        else if (command == "E"){

            command_count++;
            cout << "Cmd " << command_count << ": " << line << endl;
            cout << "\t";
            string argument = "";
            ss >> argument;

            if(argument!=""){

                cout << "Number of parameters mismatch for the command P" << endl;
            }
            else{

                if(st->getCurrentScope()->getParentScope() == NULL){
                    cout << "No scope to exit" << endl;
                }
                else{

                    string dlt_id = st->getCurrentScopeID() ;
                    st->ExitScope();
                    cout << "ScopeTable# " << dlt_id << " removed" << endl;
                }
                
            }
        
        }
    }


    
}
