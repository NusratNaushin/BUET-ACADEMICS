#include <bits/stdc++.h>
#include <string>
#include "header_files/2105168_SymbolTable.h"

using namespace std;

int main()
{

    string input_filename = "input_output_txt/sample_input.txt";
    string output_filename = "input_output_txt/myoutput1.txt";

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