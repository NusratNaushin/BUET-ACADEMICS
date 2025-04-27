#include <bits/stdc++.h>
#include <string>
#include "2105168_header_files/2105168_SymbolTable.h"

using namespace std;

int main()
{
    

    string input_filename = "2105168_input_output_txt/sample_input.txt";
    string output_filename = "2105168_input_output_txt/repgen2.txt";

   

    
    freopen(input_filename.c_str(), "r", stdin);
    freopen(output_filename.c_str(), "a", stdout);

    // ofstream collision_log("input_output_txt/collision_log.txt" , ios::app);
    // if (!collision_log.is_open()) {
    //     cout << "Error: Cannot open collision_log.txt" << endl;
    //     return 1;
    // }
    
    int num_buckets ;
    int number_of_collision_count = 0;
    int hashchoice = 1;
    cin >> num_buckets;
    cin.ignore();

    SymbolTable *st1 = new SymbolTable(num_buckets);
    SymbolTable *st2 = new SymbolTable(num_buckets);
    SymbolTable *st3 = new SymbolTable(num_buckets);

    st1->setHashFucntion(hashchoice);

    int command_count = 0;

   // cout << "\t" ;

    //st1->printCurrentScopeID();

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
            cout << number_of_collision_count << endl;

            //cout << "Cmd " << command_count << ": " << line << endl;
           
            while(st1->getCurrentScope() != NULL){
                string dlt_id = st1->getCurrentScopeID();

                //int collisions = st1->getCollsionCount();
                //cout << hashchoice << "," << dlt_id << "," << collisions << "," << num_buckets << endl;
                st1->ExitScope();
                //cout << "\t";

                //cout << "ScopeTable# " << dlt_id << " removed" << endl;
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

            bool inserted = st1->Insert(name , full_type);
            
            SymbolInfo *found = st1->LookUP(name);
            // cout << "Cmd " << command_count << ": " << line << endl;
            // cout << "\t";
            if (inserted)
            {

                number_of_collision_count = number_of_collision_count + st1->getCollsionCount();
               // cout << "Inserted in ScopeTable# " << st->getCurrentScopeID()
                   //  << " at position " << st->getIndex() + 1 << ", " << st->getCurrPos() << endl;
            }

            else{
               // cout << "'" << name << "' already exists in the current ScopeTable" << endl;
            }
            


        }

        else if (command == "L")
        {

            command_count++;

            string name, type, word;
            ss >> name;

            // cout << "Cmd " << command_count << ": " << line << endl;
            // cout << "\t";

            if (ss >> word)
            {

               // cout << "Number of parameters mismatch for the command L" << endl;
            }

            else
            {
                SymbolInfo *found = st1->LookUP(name);

                if (found)
                {
                    // cout << "'" << name << "' found in ScopeTable# " << st->getFoundScopeID() << " at position " << st->getFoundIndex() + 1 << ", " << st->getFoundChainPos() << endl;
                }

                else
                {

                    // cout << "'" << name << "' not found in any of the ScopeTables" << endl;
                }
            }
        }

        else if (command == "S")
        {
            command_count++;

            string name, type, word;
            if (ss >> name)
            {
              //  cout << "Number of parameters mismatch for the command L" << endl;
            }

            // cout << "Cmd " << command_count << ": " << line << endl;
            // cout << "\t";

            st1->EnterScope();

           // st1->printCurrentScopeID();
        }

        else if (command == "D")
        {
            command_count++;
            string name, word , extra;
            // cout << "Cmd " << command_count << ": " << line << endl;
            // cout << "\t";

            if (!(ss >> name) || ss >> extra) {
                //cout << "Number of parameters mismatch for the command D" << endl;
                continue;
            }

            else
            {
                

                if (st1->getCurrentScope()->check_present_in_scopetable(name))
                {
                    st1->Remove(name);
                   // cout << "Deleted '" << name << "' from ScopeTable# " << st->getCurrentScopeID() << " at position " << st->getIndex() + 1 << ", " << st->getCurrPos() << endl;
                }

                else
                {
                   // cout << "Not found in the current ScopeTable" << endl;
                }
            }
        }

        else if (command == "P")
        {
            command_count++;
            string argument;
            ss >> argument;

           // cout << "Cmd " << command_count << ": " << line << endl;
            
            if (argument == "A")
            {
              //  st1->print_all_scope_table2();
            }
            else if (argument == "C")
            {
               // st1->print_current_scope_table();
            }

            else
            {
                //cout << "Number of parameters mismatch for the command P" << endl;
            }
        }

        else if (command == "E"){

            command_count++;
            // cout << "Cmd " << command_count << ": " << line << endl;
            // cout << "\t";
            string argument = "";
            ss >> argument;

            if(argument!=""){

               // cout << "Number of parameters mismatch for the command P" << endl;
            }
            else{

                if(st1->getCurrentScope()->getParentScope() == NULL){
                   // cout << "No scope to exit" << endl;
                }
                else{

                    string dlt_id = st1->getCurrentScopeID() ;
                    st1->ExitScope();
                   // cout << "ScopeTable# " << dlt_id << " removed" << endl;
                }
                
            }
        
        }
    }

    string line2;
    int number_of_collision_count2 = 0 ;

    while (getline(cin, line2))
    {
        string command;
        stringstream ss(line);

        line = line.erase(line.find_last_not_of(" \n\r\t") + 1);

        ss >> command;

        if (command == "Q")
        {

            command_count++;
            cout << number_of_collision_count2 << endl;

            //cout << "Cmd " << command_count << ": " << line << endl;
           
            while(st2->getCurrentScope() != NULL){
                string dlt_id = st2->getCurrentScopeID();

                //int collisions = st1->getCollsionCount();
                //cout << hashchoice << "," << dlt_id << "," << collisions << "," << num_buckets << endl;
                st2->ExitScope();
                //cout << "\t";

                //cout << "ScopeTable# " << dlt_id << " removed" << endl;
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

            bool inserted = st2->Insert(name , full_type);
            
            SymbolInfo *found = st2->LookUP(name);
            // cout << "Cmd " << command_count << ": " << line << endl;
            // cout << "\t";
            if (inserted)
            {

                number_of_collision_count2 = number_of_collision_count2 + st2->getCollsionCount();
               // cout << "Inserted in ScopeTable# " << st->getCurrentScopeID()
                   //  << " at position " << st->getIndex() + 1 << ", " << st->getCurrPos() << endl;
            }

            else{
               // cout << "'" << name << "' already exists in the current ScopeTable" << endl;
            }
            


        }

        else if (command == "L")
        {

            command_count++;

            string name, type, word;
            ss >> name;

            // cout << "Cmd " << command_count << ": " << line << endl;
            // cout << "\t";

            if (ss >> word)
            {

               // cout << "Number of parameters mismatch for the command L" << endl;
            }

            else
            {
                SymbolInfo *found = st2->LookUP(name);

                if (found)
                {
                    // cout << "'" << name << "' found in ScopeTable# " << st->getFoundScopeID() << " at position " << st->getFoundIndex() + 1 << ", " << st->getFoundChainPos() << endl;
                }

                else
                {

                    // cout << "'" << name << "' not found in any of the ScopeTables" << endl;
                }
            }
        }

        else if (command == "S")
        {
            command_count++;

            string name, type, word;
            if (ss >> name)
            {
              //  cout << "Number of parameters mismatch for the command L" << endl;
            }

            // cout << "Cmd " << command_count << ": " << line << endl;
            // cout << "\t";

            st2->EnterScope();

           // st1->printCurrentScopeID();
        }

        else if (command == "D")
        {
            command_count++;
            string name, word , extra;
            // cout << "Cmd " << command_count << ": " << line << endl;
            // cout << "\t";

            if (!(ss >> name) || ss >> extra) {
                //cout << "Number of parameters mismatch for the command D" << endl;
                continue;
            }

            else
            {
                

                if (st2->getCurrentScope()->check_present_in_scopetable(name))
                {
                    st2->Remove(name);
                   // cout << "Deleted '" << name << "' from ScopeTable# " << st->getCurrentScopeID() << " at position " << st->getIndex() + 1 << ", " << st->getCurrPos() << endl;
                }

                else
                {
                   // cout << "Not found in the current ScopeTable" << endl;
                }
            }
        }

        else if (command == "P")
        {
            command_count++;
            string argument;
            ss >> argument;

           // cout << "Cmd " << command_count << ": " << line << endl;
            
            if (argument == "A")
            {
              //  st1->print_all_scope_table2();
            }
            else if (argument == "C")
            {
               // st1->print_current_scope_table();
            }

            else
            {
                //cout << "Number of parameters mismatch for the command P" << endl;
            }
        }

        else if (command == "E"){

            command_count++;
            // cout << "Cmd " << command_count << ": " << line << endl;
            // cout << "\t";
            string argument = "";
            ss >> argument;

            if(argument!=""){

               // cout << "Number of parameters mismatch for the command P" << endl;
            }
            else{

                if(st2->getCurrentScope()->getParentScope() == NULL){
                   // cout << "No scope to exit" << endl;
                }
                else{

                    string dlt_id = st2->getCurrentScopeID() ;
                    st2->ExitScope();
                   // cout << "ScopeTable# " << dlt_id << " removed" << endl;
                }
                
            }
        
        }
    }

    delete st2;
    delete st1;
    return 0;
    
    
}





//g++ -fsanitize=address -g 2105168_main.cpp -o 2105168main
//./2105168_main 2105168_input_output_txt/sample_input.txt 2105168_input_output_txt/finaloutput.txt "1"