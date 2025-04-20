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

        if (current_scope == nullptr)
        {
            new_id = "1";
        }

        else
        {
            current_scope->child_count++;
            // new_id = current_scope->id + "." + to_string(current_scope->child_count);
            new_id = to_string(stoi(current_scope->id) + 1);
        }

        ScopeTable *new_scope = new ScopeTable(num_buckets, new_id, current_scope);

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
                unsigned int index = current->getSDBMHashIndex(symbol_name) % current->num_buckets;
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

    void print_all_scope_table()
    {
        ScopeTable *current = current_scope;

        while (current != NULL)
        {
            current->print();
            current = current->getParentScope();
        }
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

    void printCurrentScopeID()
    {
        // cout << "\t";
        cout << "ScopeTable# " << current_scope->id <<" created" <<endl;
    }
};

int main()
{


    string input_filename = "myinput.txt";
    string output_filename = "myoutput.txt";

    freopen(input_filename.c_str(), "r", stdin);
    freopen(output_filename.c_str(), "w", stdout);
    SymbolTable *st = new SymbolTable(NULL, 7);

    int command_count = 0 ;

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
            break;
        }

        else if (command == "I")
        {

            command_count++;
            string name, type, word;
            ss >> name;

            type = "";
            while (ss >> word)
            {
                if (!type.empty())
                {
                    type += " ";
                }

                type += word;
            }

            st->Insert(name, type);
            SymbolInfo *found = st->LookUP(name);


            cout <<"Cmd "<<command_count << ": " <<  line << endl;

            cout << "\t" ;

            if (found)
            {

                cout << "Inserted in ScopeTable# " << st->getCurrentScopeID()
                     << " at position " << st->getIndex() + 1 << ", " << st->getCurrPos()<< endl;
            }
            // cout << found->getSymbolName() << " " << found->getSymbolType() << endl;

            // cout << "insert " << found->getSymbolName() << " at scope table # " << st->getCurrentScopeID() << " and <" << st->getIndex() + 1 << "," << st->getCurrPos() << ">" << endl;

            // cout << found->getSymbolName() << endl;
        }


        else if(command == "L"){

            command_count++;


            string name, type, word;
            ss >> name;

            cout <<"Cmd "<<command_count << ": " <<  line << endl;
            cout << "\t" ;


            if (ss >> word)
            {
               
                    cout << "Number of parameters mismatch for the command L" << endl;
            }

            else {
                SymbolInfo* found = st->LookUP(name);



                if(found){
                    cout <<"'" <<name << "' found in ScopeTable# " << st->getCurrentScopeID() << " at position " << st->getIndex() + 1 << ", " << st->getCurrentScopeID() << endl;
                }
    
                else{
    
                    cout <<"'" <<name << "' not found in any of the ScopeTables" << endl;
    
                }

            }
           

        }

        else if(command == "S"){
            command_count++;

            string name, type, word;
            if(ss >> name){
                cout << "Number of parameters mismatch for the command L" << endl;

            }

            cout <<"Cmd "<<command_count << ": " <<  line << endl;
            cout << "\t" ;

            st->EnterScope();

            st->printCurrentScopeID();

        }
    }
}

// int main()
// {
//     SymbolTable *st = new SymbolTable(NULL, 7);
//     st->EnterScope();

//     string line;
//     while (getline(cin, line))
//     {
//         if (line.empty()) continue; // skip empty lines

//         stringstream ss(line);
//         string command;
//         ss >> command;

//         cout << endl;

//         if (command == "Q")
//         {
//             break;
//         }

//         else if (command == "I")
//         {
//             string name, type, word;
//             ss >> name;

//             type = "";
//             while (ss >> word)
//             {
//                 if (!type.empty()) type += " ";
//                 type += word;
//             }

//             st->Insert(name, type);
//             SymbolInfo *found = st->LookUP(name);
//             if (found)
//             {
//                 cout << "Inserted " << found->getSymbolName() << " of type " << found->getSymbolType()
//                      << " in ScopeTable# " << st->getCurrentScopeID()
//                      << " at position <" << st->getIndex() + 1 << "," << st->getCurrPos() << ">" << endl;
//             }
//         }

//         // You can handle other commands like this
//         else if (command == "S")
//         {
//             st->EnterScope();
//         }

//         else if (command == "E")
//         {
//             st->ExitScope();
//         }

//         else if (command == "D")
//         {
//             string name;
//             ss >> name;
//             st->Remove(name);
//         }

//         else if (command == "L")
//         {
//             string name;
//             ss >> name;
//             st->LookUP(name);
//         }

//         else if (command == "P")
//         {
//             string mode;
//             ss >> mode;
//             if (mode == "A")
//                 st->print_all_scope_table();
//             else if (mode == "C")
//                 st->print_current_scope_table();
//         }

//         cout << endl;
//     }

//     return 0;
// }
