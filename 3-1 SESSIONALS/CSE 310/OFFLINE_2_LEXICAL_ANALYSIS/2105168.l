%option noyywrap
%x STRING
%x COMMENT
%x MULTICOMMENT
%{
    #include<stdio.h>
    #include<stdlib.h>
    #include "2105168_header_files/2105168_SymbolTable.h"

    FILE *logout;
    FILE *tokenout;


    SymbolTable* symboltable;

    int word_count=0;
    int line_count=1;
    int error_count=0;
    int string_start_line=0;
    int comment_start_line=0;

    string log_file_string;
    string resulting_string;
    string comments;
    int line_count_inside_comment=0;
    void IncWc(){
        word_count++;
    }

    char convertCharacterLiterals(const char* yytext){            /*ei fn er kaaj er example hocche string nibe quote mukto korbe then extra slash mukto kore pathabe jeno thik thak kaaj kore
                                                                  `'\\0'`-> `\\0` ->`'\0'` .. flex e string reperesentation pai je tai eto nokhra*/ 
        std::string lex = yytext;
        std::string val = lex.substr(1, lex.length() - 2);

        if(val == "\\n"){
            return '\n';
        }
        else if(val == "\\t"){
            return '\t';
        }
        else if(val == "\\\\"){
            return '\\';            
        }
        else if(val == "\\\'"){
            return '\'';           
        }
        else if(val == "\\\""){
            return '\"';            
        }
        else if(val == "\\a"){
            return '\a';            
        }
        else if(val == "\\b"){
            return '\b';           
        }
        else if(val == "\\f"){
            return '\f';           
        }
        else if(val == "\\r"){
            return '\r';            
        }
        else if(val == "\\v"){
            return '\v';           
        }
        else if(val == "\\0"){
            return '\0';
        }
        else{
            return val[0];
        }


    }
%}
Digit [0-9]
TooManyDecimalPoint {Digit}+(\.{Digit}+){2,}({Exponent}?\.{Digit}*)?  
ILlFormedNumber {Digit}+\.?{Digit}*{Exponent}\.{Digit}+             
InvalidSuffixPrefix [0-9]+[_a-zA-Z]+                                 
Constant_Integer [0-9]+

MultiCharError \'([^\'\\\n]{2,})\'  
UnfinishedCharacter \'([^\'\\\n]|\\[^\'\n])                         
UnfinishedEmptyBackSlash \'\\\'                                    
EmptyCharacterConstantError \'\'                                   

Identifier [_a-zA-Z][_a-zA-Z0-9]*
Char_Literals \'(\\[nt\\'"abfrv0]|[^\'\\\n])\'                      
UnterminatedQuote \'
Exponent ([Ee][+-]?{Constant_Integer})
Fraction \.{Constant_Integer}
Float ({Digit}+{Fraction}?|{Fraction}){Exponent}?
INCOP (\+\+|--)
ADDOP [+-] 
MULOP [*/%]
RELOP (<|<=|>|>=|==|!=)
ASSIGNOP [=]
LOGICOP (&&|\|\|)
NOT [!]
LPAREN [(]
RPAREN [)]
LCURL [{]
RCURL [}]
LTHIRD (\[)
RTHIRD (\])
COMMA  [,]
SEMICOLON [;]


Newline \n



%%


[ \t\v]+ {    }
{Newline} {line_count++;}
"if"	{
			fprintf(tokenout,"<IF> ");
			fprintf(logout,"Line no %d: Token <IF> Lexeme %s found\n",line_count,yytext);
            fprintf(logout,"\n");
}
"else"  {
            fprintf(tokenout,"<ELSE> ");
			fprintf(logout,"Line no %d: Token <ELSE> Lexeme %s found\n",line_count,yytext);
            fprintf(logout,"\n");
}
"for"   {
            fprintf(tokenout,"<FOR> ");
			fprintf(logout,"Line no %d: Token <FOR> Lexeme %s found\n",line_count,yytext);
            fprintf(logout,"\n");
}
"goto" {
        fprintf(tokenout,"<GOTO> ");
		fprintf(logout,"Line no %d: Token <GOTO> Lexeme %s found\n",line_count,yytext);
        fprintf(logout,"\n");
        
}
"while" {
        fprintf(tokenout,"<WHILE> ");
		fprintf(logout,"Line no %d: Token <WHILE> Lexeme %s found\n",line_count,yytext);
        fprintf(logout,"\n");
}

"long" {
        fprintf(tokenout,"<LONG> ");
		fprintf(logout,"Line no %d: Token <LONG> Lexeme %s found\n",line_count,yytext);
        fprintf(logout,"\n");
}
"do" {
        fprintf(tokenout,"<DO> ");
		fprintf(logout,"Line no %d: Token <DO> Lexeme %s found\n",line_count,yytext);
        fprintf(logout,"\n");
}

"break" {
        fprintf(tokenout,"<BREAK> ");
		fprintf(logout,"Line no %d: Token <BREAK> Lexeme %s found\n",line_count,yytext);
        fprintf(logout,"\n");
}

"short" {
        fprintf(tokenout,"<SHORT> ");
		fprintf(logout,"Line no %d: Token <SHORT> Lexeme %s found\n",line_count,yytext);
        fprintf(logout,"\n");
}
"int" {
        fprintf(tokenout,"<INT> ");
		fprintf(logout,"Line no %d: Token <INT> Lexeme %s found\n",line_count,yytext);
        fprintf(logout,"\n");
}

"char" {
        fprintf(tokenout,"<CHAR> ");
		fprintf(logout,"Line no %d: Token <CHAR> Lexeme %s found\n",line_count,yytext);
        fprintf(logout,"\n");
} 

"static" {
        fprintf(tokenout,"<STATIC> ");
		fprintf(logout,"Line no %d: Token <STATIC> Lexeme %s found\n",line_count,yytext);
        fprintf(logout,"\n");
}

"float" {
        fprintf(tokenout,"<FLOAT> ");
		fprintf(logout,"Line no %d: Token <FLOAT> Lexeme %s found\n",line_count,yytext);
        fprintf(logout,"\n");
}
"double" {
        fprintf(tokenout,"<DOUBLE> ");
		fprintf(logout,"Line no %d: Token <DOUBLE> Lexeme %s found\n",line_count,yytext);
        fprintf(logout,"\n");
}

"unsigned" {
        fprintf(tokenout,"<UNSIGNED> ");
		fprintf(logout,"Line no %d: Token <UNSIGNED> Lexeme %s found\n",line_count,yytext);
        fprintf(logout,"\n");
}

"void" {
        fprintf(tokenout,"<VOID> ");
		fprintf(logout,"Line no %d: Token <VOID> Lexeme %s found\n",line_count,yytext);
}

"return" {
        fprintf(tokenout,"<RETURN> ");
		fprintf(logout,"Line no %d: Token <RETURN> Lexeme %s found\n",line_count,yytext);
        fprintf(logout,"\n");
}


"switch" {
        fprintf(tokenout,"<SWITCH> ");
		fprintf(logout,"Line no %d: Token <SWITCH> Lexeme %s found\n",line_count,yytext);
        fprintf(logout,"\n");
}

"case" {
        fprintf(tokenout,"<CASE> ");
		fprintf(logout,"Line no %d: Token <CASE> Lexeme %s found\n",line_count,yytext);
        fprintf(logout,"\n");
}


"default" {
        fprintf(tokenout,"<DEFAULT> ");
		fprintf(logout,"Line no %d: Token <DEFAULT> Lexeme %s found\n",line_count,yytext);
        fprintf(logout,"\n");
}


"continue" {
        fprintf(tokenout,"<CONTINUE> ");
		fprintf(logout,"Line no %d: Token <CONTINUE> Lexeme %s found\n",line_count,yytext);
        fprintf(logout,"\n");
}



{Identifier} {
    fprintf(tokenout,"<ID, %s> " , yytext);
	fprintf(logout,"Line no %d: Token <ID> Lexeme %s found\n",line_count,yytext);
    IncWc();
        if(symboltable->Insert(yytext,"ID")){
        fprintf(logout,"\n");
        symboltable->print_all_scope_table2(logout);
        fprintf(logout,"\n");
       
    }
    else{

        fprintf(logout,"\n");
        fprintf(logout, "< %s : ID > already exists in ScopeTable# %s at position %d, %d\n",yytext,symboltable->getCurrentScopeID().c_str(),symboltable->getIndex(),symboltable->getCurrPos());
        fprintf(logout,"\n");
    }
    
        
}

{Constant_Integer} {

        fprintf(tokenout,"<CONST_INT, %s> " , yytext);
		fprintf(logout,"Line no %d: Token <CONST_INT> Lexeme %s found\n",line_count,yytext);
        
        if(symboltable->Insert(yytext,"CONST_INT")){
            fprintf(logout,"\n");
            symboltable->print_all_scope_table2(logout);
            fprintf(logout,"\n");

        }
        else{
        fprintf(logout,"\n");
        fprintf(logout, "< %s : CONST_INT > already exists in ScopeTable# %s at position %d, %d\n",yytext,symboltable->getCurrentScopeID().c_str(),symboltable->getIndex(),symboltable->getCurrPos());
        fprintf(logout,"\n");
        }
        
}
{InvalidSuffixPrefix} {
    fprintf(logout,"Error at line no %d: Invalid prefix on ID or invalid suffix on Number %s\n",line_count,yytext);
    fprintf(logout,"\n");

    error_count++;
}

{TooManyDecimalPoint} {

	fprintf(logout,"Error at line no %d: Too many decimal points %s\n",line_count,yytext);
    fprintf(logout,"\n");
    fprintf(logout,"\n");

    error_count++;

}

{ILlFormedNumber} {
	fprintf(logout,"Error at line no %d: Ill formed number %s\n",line_count,yytext);
    fprintf(logout,"\n");
    fprintf(logout,"\n");

    error_count++;
}


{Float} {
    fprintf(tokenout,"<CONST_FLOAT, %s> " , yytext);
	fprintf(logout,"Line no %d: Token <CONST_FLOAT> Lexeme %s found\n",line_count,yytext);
    if(symboltable->Insert(yytext,"CONST_FLOAT")){
        // fprintf(logout, "\tInserted into SymbolTable\n");
        fprintf(logout,"\n");
        symboltable->print_all_scope_table2(logout);
        fprintf(logout,"\n");
    }
    else{
        fprintf(logout,"\n");
        fprintf(logout, "< %s : CONST_FLOAT > already exists in ScopeTable# %s at position %d, %d\n",yytext,symboltable->getCurrentScopeID().c_str(),symboltable->getIndex(),symboltable->getCurrPos());
        fprintf(logout,"\n");

    }
}

{Char_Literals} {
    char val=convertCharacterLiterals(yytext);
    // if(val.length() > 1){
	// fprintf(logout,"Line no %d: error\n",line_count);
      
    // }

   // std::string pritnt_c;

//     switch(val){
//         case '\n':  pritnt_c = "\\n"; break;
//         case '\t':  pritnt_c = "\\t"; break;
//         case '\\':  pritnt_c = "\\\\"; break;
//         case '\"':  pritnt_c = "\\\""; break;
//         case '\'':  pritnt_c = "\\\'"; break;
//         case '\a':  pritnt_c = "\\a"; break;
//         case '\b':  pritnt_c = "\\b"; break;
//         case '\f':  pritnt_c = "\\f"; break;
//         case '\r':  pritnt_c = "\\r"; break;
//         case '\v':  pritnt_c = "\\v"; break;
//         case '\0':  pritnt_c = "\\0"; break;
//         dafault:  pritnt_c = val ; break;

// }
    
    fprintf(tokenout,"<CONST_CHAR, %c> " , val);
	fprintf(logout,"Line no %d: Token <CONST_CHAR> Lexeme %s found --> <CONST_CHAR, %c>\n",line_count,yytext,val);
    if(symboltable->Insert(yytext,"CONST_CHAR")){
        fprintf(logout,"\n");

        symboltable->print_all_scope_table2(logout);
        fprintf(logout,"\n");

    }
    else{
        fprintf(logout,"\n");
        fprintf(logout, "< %s : CONST_CHAR > already exists in ScopeTable# %s at position %d, %d\n",yytext,symboltable->getCurrentScopeID().c_str(),symboltable->getIndex(),symboltable->getCurrPos());
        fprintf(logout,"\n");

    }
}

{MultiCharError} {
    fprintf(logout,"Error at line no %d: Multi character constant error %s\n",line_count,yytext);
    fprintf(logout,"\n");
    fprintf(logout,"\n");

    error_count++;
}

{UnfinishedEmptyBackSlash} {
    fprintf(logout,"Error at line no %d: Unterminated character %s\n",line_count,yytext);
    fprintf(logout,"\n");
    fprintf(logout,"\n");

    error_count++;
}

{UnfinishedCharacter} {
    fprintf(logout,"Error at line no %d: Unterminated character %s\n",line_count,yytext);
    fprintf(logout,"\n");
    fprintf(logout,"\n");

    error_count++;    
}
{EmptyCharacterConstantError} {
    fprintf(logout,"Error at line no %d: Empty character constant error %s\n",line_count,yytext);
    fprintf(logout,"\n");
    fprintf(logout,"\n");

    error_count++;   
}
{UnterminatedQuote} {
    fprintf(logout,"Error at line no %d: Unterminated character %s\n",line_count,yytext);
    fprintf(logout,"\n");
    fprintf(logout,"\n");

    error_count++;   
}
{INCOP} {
    fprintf(tokenout,"<INCOP, %s> " , yytext);
	fprintf(logout,"Line no %d: Token <INCOP> Lexeme %s found\n",line_count,yytext);
    fprintf(logout,"\n");
}
{ADDOP} {
    fprintf(tokenout,"<ADDOP, %s> " , yytext);
	fprintf(logout,"Line no %d: Token <ADDOP> Lexeme %s found\n",line_count,yytext);
    fprintf(logout,"\n");
}
{MULOP} {
    fprintf(tokenout,"<MULOP, %s> " , yytext);
	fprintf(logout,"Line no %d: Token <MULOP> Lexeme %s found\n",line_count,yytext);
    fprintf(logout,"\n");
}
{RELOP} {
    fprintf(tokenout,"<RELOP, %s> " , yytext);
	fprintf(logout,"Line no %d: Token <RELOP> Lexeme %s found\n",line_count,yytext);
    fprintf(logout,"\n");
}
{ASSIGNOP} {
    fprintf(tokenout,"<ASSIGNOP, %s> " , yytext);
	fprintf(logout,"Line no %d: Token <ASSIGNOP> Lexeme %s found\n",line_count,yytext);
    fprintf(logout,"\n");
}
{LOGICOP} {
    fprintf(tokenout,"<LOGICOP, %s> " , yytext);
	fprintf(logout,"Line no %d: Token <LOGICOP> Lexeme %s found\n",line_count,yytext);
    fprintf(logout,"\n");
}

{NOT} {
    fprintf(tokenout,"<NOT, %s> " , yytext);
	fprintf(logout,"Line no %d: Token <NOT> Lexeme %s found\n",line_count,yytext);
    fprintf(logout,"\n");
}

{LPAREN} {
    fprintf(tokenout,"<LPAREN, %s> " , yytext);
	fprintf(logout,"Line no %d: Token <LPAREN> Lexeme %s found\n",line_count,yytext);
    fprintf(logout,"\n");
}
{RPAREN} {
    fprintf(tokenout,"<RPAREN, %s> " , yytext);
	fprintf(logout,"Line no %d: Token <RPAREN> Lexeme %s found\n",line_count,yytext);
    fprintf(logout,"\n");
}


{LCURL} {
    fprintf(tokenout,"<LCURL, %s> " , yytext);
	fprintf(logout,"Line no %d: Token <LCURL> Lexeme %s found\n",line_count,yytext);
    fprintf(logout,"\n");
    symboltable->EnterScope();

}

{RCURL} {
    fprintf(tokenout,"<RCURL, %s> " , yytext);
	fprintf(logout,"Line no %d: Token <RCURL> Lexeme %s found\n",line_count,yytext);
    fprintf(logout,"\n");
     symboltable->ExitScope();
}

{LTHIRD} {
    fprintf(tokenout,"<LTHIRD, %s> " , yytext);
	fprintf(logout,"Line no %d: Token <LTHIRD> Lexeme %s found\n",line_count,yytext);
    fprintf(logout,"\n");
}

{RTHIRD} {
    fprintf(tokenout,"<RTHIRD, %s> " , yytext);
	fprintf(logout,"Line no %d: Token <RTHIRD> Lexeme %s found\n",line_count,yytext);
    fprintf(logout,"\n");
}

{COMMA} {
    fprintf(tokenout,"<COMMA, %s> " , yytext);
	fprintf(logout,"Line no %d: Token <COMMA> Lexeme %s found\n",line_count,yytext);
    fprintf(logout,"\n");
}
{SEMICOLON} {
    fprintf(tokenout,"<SEMICOLON, %s> " , yytext);
	fprintf(logout,"Line no %d: Token <SEMICOLON> Lexeme %s found\n",line_count,yytext);
    fprintf(logout,"\n");
}

\" {
    resulting_string.clear();
    log_file_string.clear();  
    string_start_line=line_count;

    BEGIN STRING;
}

\/\/ {

    comments.clear();
    comments += "//";
    comment_start_line=line_count;
    BEGIN COMMENT;
}

\/\* {
    comments.clear();
    comments += "/*";
    comment_start_line=line_count;
    BEGIN MULTICOMMENT;
}


<STRING>\\\\ {
    resulting_string += "\\";
    log_file_string += "\\\\";    

}
<STRING>\\\' {
    resulting_string += "\'";
    log_file_string += "\\\'";    

}
<STRING>\\\" {
    resulting_string += "\"";
    log_file_string += "\\\""  ;  

}

<STRING>\\t {
    resulting_string += '\t';
    log_file_string += "\\t"  ;  
   
}

<STRING>\\\n {
    line_count++;
    log_file_string += "\\\n" ;   
  
}


<STRING>\\n {
    line_count++;
    resulting_string += "\n";
    log_file_string += "\\n"  ;  

}

<STRING>\\ {
    resulting_string += "\n";
    log_file_string += "\\"; 

}
<STRING>\" {

        std::string print = "\"" + log_file_string + "\"";
        fprintf(tokenout,"<STRING, %s> " , resulting_string.c_str());

        fprintf(logout, "Line no %d: Token <STRING> Lexeme %s found --> <STRING, %s>\n", line_count, print.c_str(), resulting_string.c_str());
        fprintf(logout,"\n");
        BEGIN INITIAL;       
}


<STRING>[\r]?\n {
    
    error_count++;
	fprintf(logout,"Error at line no %d: Unterminated string \"%s\n",string_start_line, log_file_string.c_str());
    line_count++;
    fprintf(logout,"\n");
    BEGIN INITIAL;
}


<STRING><<EOF>> {
    error_count++;
    fprintf(logout,"Error at line %d: Unterminated string \"%s\n",string_start_line, log_file_string.c_str());
    fprintf(logout,"\n");
    BEGIN INITIAL;
    
}

<STRING>. {
    resulting_string += yytext[0];
    log_file_string += yytext[0]; 


}


<COMMENT>\\\r\n {
    
    comments +="\\\r\n";
}

<COMMENT>\\\n {
    line_count++;
    comments += "\\\n";
}

<COMMENT>[\r]?\n {                      /*joid comment state e thaka obosthate abar new line e chole jay tahole kemon kore hobe
                                        eta to single line comment  */
    
	fprintf(logout,"Line no %d: Token <COMMENT> Lexeme %s found\n",line_count,comments.c_str());
    line_count++;
    fprintf(logout,"\n");
    BEGIN INITIAL;
}
<COMMENT>\\ {
    comments += "\\";
}
<COMMENT>. {
    comments += yytext[0];
}


<MULTICOMMENT>\*\/ {

    comments += "*/";
	fprintf(logout,"Line no %d: Token <COMMENT> Lexeme %s found\n",line_count,comments.c_str());
    fprintf(logout,"\n");
    BEGIN INITIAL;

}


<MULTICOMMENT>\r {
    comments += "\r";
}
<MULTICOMMENT>\n {
    line_count++;
    comments += "\n";
}

<MULTICOMMENT>. {
    comments += yytext[0];
}

<MULTICOMMENT><<EOF>> {                                      /*closing tag pawar age file end hoye gele toh error taijonne eta*/
    error_count++;
    fprintf(logout,"Error at line no %d: Unterminated comment %s\n",comment_start_line, comments.c_str());
    fprintf(logout,"\n");
    BEGIN INITIAL;
    
}
<<EOF>> {
    symboltable->print_all_scope_table2(logout);
    fprintf(logout,"\n");
    return 0;

}


. {                                                          /*shob kichu pore toreo kono kichur shathe match holo na abar end of file o pelo na tahole to unrecognized character*/
    error_count++;
    fprintf(logout, "Error at line no %d: Unrecognized character %s\n", line_count, yytext);
    fprintf(logout,"\n");
}


%%

int main(int argc , char *argv[]){
    if(argc!=2){
        printf("Please provide input filename and try again\n");
        return 0;
    }
    symboltable = new SymbolTable(7);
    symboltable->setHashFucntion(1);


    FILE *fin=fopen(argv[1],"r");
    if(fin==NULL){
        printf("Cannot open specified file\n");
        return 0;
    }

	logout= fopen("log.txt","w");
	tokenout= fopen("token.txt","w");



    yyin= fin;
    yylex();
    fprintf(logout , "Total lines: %d\n",line_count);
    fprintf(logout, "Total errors: %d",error_count);
    fprintf(logout,"\n");
    fclose(yyin);
    fclose(logout);
    fclose(tokenout);
    return 0;
}

