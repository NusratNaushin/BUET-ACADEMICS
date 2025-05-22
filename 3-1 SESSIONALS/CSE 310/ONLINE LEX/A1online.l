%option noyywrap


%{
    #include <stdio.h>
    #include <string.h>

    FILE *logout;
    FILE *tokenout;

    
    
    
    
    
    
%}


whitespace [ \t\v]+ 
validvector [Vv]ector[[:space:]]*<[[:space:]]*(int|float|double|char)[[:space:]]*>



%%

{whitespace} {    }

{validvector} {
    fprintf(logout, "Token <VECTOR_TYPE> Lexeme %s found\n", yytext);
}

. {

}

\n {

}
%%
int main(int argc , char *argv[]){
 

    FILE *fin=fopen(argv[1],"r");
    if(fin==NULL){
        printf("Cannot open specified file\n");
        return 0;
    }



	logout= fopen("log.txt","w");
	tokenout= fopen("token.txt","w");


    yyin= fin;

    yylex();
    fclose(fin);
    fclose(logout);
    fclose(tokenout);
    return 0;
}
