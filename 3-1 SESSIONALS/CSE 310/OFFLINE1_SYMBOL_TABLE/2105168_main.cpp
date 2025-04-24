#include <bits/stdc++.h>
#include <string>
#include "2105168_header_files/2105168_SymbolTable.h"

using namespace std;

int main(int argc , char* argv[])
{
    

    // string input_filename = "2105168_input_output_txt/sample_input.txt";
    // string output_filename = "2105168_input_output_txt/myoutput1.txt";

    if(argc != 4){
        cout << "Invalid number of arguments" << endl;
        return 1;
    }


    string input_filename = argv[1];
    string output_filename = argv[2];
    string hashchoice = argv[3];
    freopen(input_filename.c_str(), "r", stdin);
    freopen(output_filename.c_str(), "w", stdout);

    // ofstream collision_log("input_output_txt/collision_log.txt" , ios::app);
    // if (!collision_log.is_open()) {
    //     cout << "Error: Cannot open collision_log.txt" << endl;
    //     return 1;
    // }
    
    int num_buckets ;
    cin >> num_buckets;
    cin.ignore();

    SymbolTable *st = new SymbolTable(num_buckets);
    
    st->setHashFucntion(stoi(hashchoice));


    int command_count = 0;

    cout << "\t" ;

    st->printCurrentScopeID();

    string line;

    while (getline(cin, line))
    {
        string command;
        stringstream ss(line);

        line = line.erase(line.find_last_not_of(" \n\r\t") + 1);

        ss >> command;

        if (command == "Q")
        {

            command_count++;
            cout << "Cmd " << command_count << ": " << line << endl;
           
            while(st->getCurrentScope() != NULL){
                string dlt_id = st->getCurrentScopeID();
               // int collisions = st->getCollsionCount();
               // collision_log << hashchoice << "," << dlt_id << "," << collisions << "," << num_buckets << endl;
                st->ExitScope();
                cout << "\t";

                cout << "ScopeTable# " << dlt_id << " removed" << endl;
              }
              
            //   int collisions = st->getCurrentScope()->getNumberOfCollisions();
            //   collision_log << hashchoice << ",1," << collisions << "," << num_buckets << endl;
            break;
        }

        else if (command == "I"){
            command_count++;
            string  name , type , word;
            ss >> name;
            ss >> type ;

            string full_type = type;
            if(type == "STRUCT" || type == "UNION"){

                full_type += ",{";
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

                full_type = "FUNCTION," +return_type + "<==(" + formatted_args + ")";
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
            
            if (argument == "A")
            {
                st->print_all_scope_table2();
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

  //  collision_log.close();
    delete st;
    return 0;
    
    
}





//g++ -fsanitize=address -g 2105168_main.cpp -o 2105168main
//./2105168_main 2105168_input_output_txt/sample_input.txt 2105168_input_output_txt/check.txt