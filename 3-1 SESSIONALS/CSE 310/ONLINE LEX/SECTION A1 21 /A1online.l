%option noyywrap
%x VECTOR 

%{

#include <iostream>
#include <string>
using namespace std;

int line_count = 1;
string vec_line = "";
int bracket_count = 0;
bool error_in_vector = false;

FILE *logout;
FILE *tokenout;

%}



%%


[ \t\v]+    {       }
\r?\n       {
    line_count++; 
    vec_line = "" ;
    }
^[ \t]*[^v\n]([^\n]*) {
    fprintf(logout, "Line no %d: Invalid input\n", line_count);
    vec_line = "";
}


vector {
    BEGIN VECTOR;
    vec_line += "vector";
    bracket_count = 0;
    error_in_vector = false;
}


<VECTOR>[ \t]*\<[ \t]*(int|float|double|char|vector)[ \t]* {
  vec_line += yytext;
  bracket_count++;

}

<VECTOR>[ \t]*\> {
   
    vec_line += yytext;
    bracket_count--;
    if(bracket_count < 0) {
        error_in_vector = true;
       
        
    }
    

   

    
}



<VECTOR>. {
    vec_line += yytext;
    error_in_vector = true;
}


<VECTOR>\r?\n {
        // End of the vector line
    if (bracket_count == 0 && !error_in_vector) {
        fprintf(logout, "Line no %d: Token Lexeme %s found\n", line_count, vec_line.c_str());
    } else {
        fprintf(logout, "Line no %d: Error %s\n", line_count, vec_line.c_str());
    }
    line_count++;
    vec_line = "";
    bracket_count = 0;
    error_in_vector = false;
    BEGIN INITIAL;
}

<VECTOR><<EOF>> {
    //  if(bracket_count == 0) {
    //     if(!error_in_vector) {
    //         fprintf(logout,"Line no %d: Token Lexeme %s found\n",line_count,vec_line.c_str());
    //         fprintf(logout, "\n");
    //         //cout << "Line No. " << line_count << ": Lexeme " << vec_line << " found\n";
    //     }
        
        
        
    // }
    
    // if(bracket_count != 0 || error_in_vector)
    // { 
    //     fprintf(logout,"Line no %d: Error %s \n",line_count,vec_line.c_str());
    //     fprintf(logout, "\n");
    //     //cout << "Line No. " << line_count << " Error " << vec_line << "\n";
    // }  
    
    // vec_line = "";
    // bracket_count = 0;
    // error_in_vector = false;
    // BEGIN INITIAL;
    // return 0;
}



%%

int main(int argc , char *argv[]){   
        
        if(argc!=2){
            printf("Please provide input filename and try again\n");
            return 0;
        }

        FILE *fin=fopen(argv[1],"r");

        if(fin==NULL){
            printf("Cannot open specified file\n");
            return 0;
        }

	logout= fopen("log.txt","w");
	tokenout= fopen("token.txt","w");
    yyin = fin;
    yylex();
    fclose(yyin);
    fclose(logout);
    fclose(tokenout);
    return 0;
}