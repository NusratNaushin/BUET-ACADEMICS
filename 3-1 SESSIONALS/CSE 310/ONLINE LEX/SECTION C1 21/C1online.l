%option noyywrap

%{
#include <iostream>
#include <cstring>
using namespace std;

#define MAX_STACK 1000
char* stack[MAX_STACK];
int top = -1;
bool error = false;

void push(const char* tag) {
    if (top >= MAX_STACK - 1) {
        fprintf(stderr, "Stack overflow\n");
        exit(1);
    }
    stack[++top] = strdup(tag);
}

char* pop() {
    if (top < 0) return NULL;
    return stack[top--];
}

char* peek() {
    if (top < 0) return NULL;
    return stack[top];
}

FILE *logout;
%}

%%

"<html>"    { push("html"); }
"<body>"    { push("body"); }
"<p>"       { push("p"); }

"</html>"   { if (top >= 0 && strcmp(peek(), "html") == 0) pop(); else error = true; }
"</body>"   { if (top >= 0 && strcmp(peek(), "body") == 0) pop(); else error = true; }
"</p>"      { if (top >= 0 && strcmp(peek(), "p") == 0) pop(); else error = true; }

[ \t\n]+    { /* Skip whitespace */ }
.           { /* Consume any single unmatched character */ }

<<EOF>> {
    if (error || top != -1) {
        fprintf(logout, "Invalid HTML structure %s\n",yytext);
    } else {
        fprintf(logout, "Valid HTML structure.\n");
    }

    return 0;
}

%%

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Please provide input filename and try again\n");
        return 0;
    }

    FILE* fin = fopen(argv[1], "r");
    if (!fin) {
        printf("Cannot open specified file\n");
        return 0;
    }

    logout = fopen("log.txt", "w");
    yyin = fin;
    yylex();
    fclose(fin);
    fclose(logout);
    return 0;
}
