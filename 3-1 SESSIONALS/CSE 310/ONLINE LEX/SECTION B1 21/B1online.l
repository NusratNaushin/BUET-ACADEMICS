%option noyywrap
%x BRACKET


%{
    #include <iostream>
    #include <string>
    #include <stack>
    using namespace std;

    FILE *logout;
    FILE *tokenout;

    bool Bracket_mismatch_error = false;
    int bracket_count = 0;


    stack<char> st;
    bool matched = true;

%}






%%


\( {
    st.push('(');
}

\{ {
    st.push('{');
}

\[ {
    st.push('[');
}


\) {
    if(!st.empty() && st.top() == '('){
        st.pop();
    }

    else {
        matched = false;
    }
}

\} {

    if(!st.empty() && st.top() == '{'){
        st.pop();
    }

    else {
        matched = false;
    }
}

\] {
    if(!st.empty() && st.top() == '['){
        st.pop();
    }

    else {
        matched = false;
    }
}













<<EOF>> {

    if(st.empty() && matched){
        fprintf(logout,"matched\n");

    }
    else {
        fprintf(logout,"Unmatched\n");

    }
    return 0;
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