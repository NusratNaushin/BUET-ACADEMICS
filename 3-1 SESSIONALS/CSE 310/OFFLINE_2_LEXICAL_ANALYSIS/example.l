%option noyywrap
%{
    #include<stdio.h>
    #include<stdlib.h>
    #include "2105168_header_files/2105168_SymbolTable.h"

    FILE *logout;
    FILE *tokenout;


    SymbolTable symboltable(20);

    int word_count=0;
    int line_count=1;

    void IncWc(){
        word_count++;
    }
%}

Constant_Integer [0-9]+
WhiteSpace [ \t\f\r\v]+
Letter [a-zA-Z]
Digit [0-9]
Newline \n


%%

"if"	{
			fprintf(tokenout,"<IF>");
			fprintf(logout,"Line no %d: TOKEN <IF> Lexeme %s found\n",line_count,yytext);
}
"else"  {
            fprintf(tokenout,"<ELSE>");
			fprintf(logout,"Line no %d: TOKEN <ELSE> Lexeme %s found\n",line_count,yytext);
}
"for"   {
            fprintf(tokenout,"<FOR>");
			fprintf(logout,"Line no %d: TOKEN <FOR> Lexeme %s found\n",line_count,yytext);
}
"goto" {
        fprintf(tokenout,"<GOTO>");
		fprintf(logout,"Line no %d: TOKEN <GOTO> Lexeme %s found\n",line_count,yytext);
}
"while" {
        fprintf(tokenout,"<WHILE>");
		fprintf(logout,"Line no %d: TOKEN <WHILE Lexeme %s found\n",line_count,yytext);
}

"long" {
        fprintf(tokenout,"<LONG>");
		fprintf(logout,"Line no %d: TOKEN <LONG> Lexeme %s found\n",line_count,yytext);
}
"do" {
        fprintf(tokenout,"<DO>");
		fprintf(logout,"Line no %d: TOKEN <DO> Lexeme %s found\n",line_count,yytext);
}

"break" {
        fprintf(tokenout,"<BREAK>");
		fprintf(logout,"Line no %d: TOKEN <BREAK> Lexeme %s found\n",line_count,yytext);
}

"short" {
        fprintf(tokenout,"<SHORT>");
		fprintf(logout,"Line no %d: TOKEN <SHORT> Lexeme %s found\n",line_count,yytext);
}
"int" {
        fprintf(tokenout,"<INT>");
		fprintf(logout,"Line no %d: TOKEN <INT> Lexeme %s found\n",line_count,yytext);
}

"char" {
        fprintf(tokenout,"<CHAR>");
		fprintf(logout,"Line no %d: TOKEN <CHAR> Lexeme %s found\n",line_count,yytext);
} 

"static" {
        fprintf(tokenout,"<STATIC>");
		fprintf(logout,"Line no %d: TOKEN <STATIC> Lexeme %s found\n",line_count,yytext);
}

"float" {
        fprintf(tokenout,"<FLOAT>");
		fprintf(logout,"Line no %d: TOKEN <FLOAT> Lexeme %s found\n",line_count,yytext);
}
"double" {
        fprintf(tokenout,"<DOUBLE>");
		fprintf(logout,"Line no %d: TOKEN <DOUBLE> Lexeme %s found\n",line_count,yytext);
}

"unsigned" {
        fprintf(tokenout,"<UNSIGNED>");
		fprintf(logout,"Line no %d: TOKEN <UNSIGNED> Lexeme %s found\n",line_count,yytext);
}

"void" {
        fprintf(tokenout,"<VOID>");
		fprintf(logout,"Line no %d: TOKEN <VOID> Lexeme %s found\n",line_count,yytext);
}

"return" {
        fprintf(tokenout,"<RETURN>");
		fprintf(logout,"Line no %d: TOKEN <RETURN> Lexeme %s found\n",line_count,yytext);
}


"switch" {
        fprintf(tokenout,"<SWITCH>");
		fprintf(logout,"Line no %d: TOKEN <SWITCH> Lexeme %s found\n",line_count,yytext);
}

"case" {
        fprintf(tokenout,"<CASE>");
		fprintf(logout,"Line no %d: TOKEN <CASE> Lexeme %s found\n",line_count,yytext);
}


"default" {
        fprintf(tokenout,"<DEFAULT>");
		fprintf(logout,"Line no %d: TOKEN <DEFAULT> Lexeme %s found\n",line_count,yytext);
}


"continue" {
        fprintf(tokenout,"<CONTINUE>");
		fprintf(logout,"Line no %d: TOKEN <CONTINUE> Lexeme %s found\n",line_count,yytext);
}

{Constant_Integer} {

        fprintf(tokenout,"<CONST_INT>, %s>\n" , yytext);
		fprintf(logout,"Line no %d: TOKEN <CONST_INT> Lexeme %s found\n",line_count,yytext);
        
        if(symboltable.Insert(yytext,"CONST_INT")){
            fprintf(logout, "\tInserted into SymbolTable\n");
        }
        else{
            fprintf(logout, "\tAlready exists in current scope\n");
        }
}


[ \t\v]+ {    }
{Letter}+ {IncWc(); printf("%s word found\n",yytext);}
[\n] {line_count++;}
<<EOF>> {printf("Total Line NUmber: %d and word number : %d\n",line_count,word_count); return 0;}
. {}

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

    yyin= fin;
    yylex();
    fclose(yyin);
    fclose(logout);
    fclose(tokenout);
    return 0;
}