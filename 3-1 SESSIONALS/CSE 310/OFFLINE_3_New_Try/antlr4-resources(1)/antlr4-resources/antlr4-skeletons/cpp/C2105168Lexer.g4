lexer grammar C2105168Lexer;

@lexer::header {
    #pragma once
    #include <iostream>
    #include <fstream>
    #include <string>
    extern std::ofstream lexLogFile;
}

@lexer::members {
    void writeIntoLexLogFile(const std::string &message) {
        if (!lexLogFile.is_open()) {
            lexLogFile.open("lexLogFile.txt", std::ios::app);
            if (!lexLogFile) {
                std::cerr << "Error opening lexLogFile.txt" << std::endl;
                return;
            }
        }
        lexLogFile << message << std::endl;
        lexLogFile.flush();
    }
}

// ------------------------------
// 1) Comments (skipped + logged)
// ------------------------------

// Single-line comments: '//' then anything except newline
LINE_COMMENT
    : '//' ~[\r\n]* {
        writeIntoLexLogFile(
          "Line# " + std::to_string(getLine())
          + ": Token <SINGLE LINE COMMENT> Lexeme "
          + getText()
        );
    } -> skip
    ;

// Multi-line comments
BLOCK_COMMENT
  : '/*' ( . | '\r' | '\n' )*? '*/' {
      // extra braces create a new scope for your variables
      {
        std::string txt = getText();
        std::string content = txt.substr(2, txt.size() - 4);
        writeIntoLexLogFile(
          "Line# " + std::to_string(getLine())
          + ": Token <MULTI LINE COMMENT> Lexeme /*"
          + content + "*/"
        );
      }
    }
    -> skip
  ;


// ------------------------------
// 2) String literals (skipped + logged)
// ------------------------------

// A basic string rule with escape support :contentReference[oaicite:5]{index=5}
STRING
    : '"' ( '\\' . | ~["\\\r\n] )* '"' {
        writeIntoLexLogFile(
          "Line# " + std::to_string(getLine())
          + ": Token <STRING> Lexeme " + getText()
        );
    } -> skip
    ;

// ------------------------------
// 3) Whitespace & Newlines (skipped)
// ------------------------------

WS      : [ \t\f\r\n]+ -> skip ;

// ------------------------------
// 4) Keywords & Symbols
// ------------------------------

IF       : 'if' ;
ELSE     : 'else' ;
FOR      : 'for' ;
WHILE    : 'while' ;
PRINTLN  : 'printf' ;
RETURN   : 'return' ;
INT      : 'int';
FLOAT    : 'float' ;
VOID     : 'void' ;

LPAREN   : '(' ;
RPAREN   : ')' ;
LCURL    : '{' ;
RCURL    : '}' ;
LTHIRD   : '[' ;
RTHIRD   : ']' ;
SEMICOLON: ';' ;
COMMA    : ',' ;
HASH     : '#' -> skip;

ADDOP    : [+\-] ;
SUBOP    : [+\-] ;
MULOP    : [*/%] ;
INCOP    : '++' ;
DECOP    : '--' ;
NOT      : '!' ;
RELOP    : '<=' | '==' | '>=' | '>' | '<' | '!=' ;
LOGICOP  : '&&' | '||' ;
ASSIGNOP : '=' ;

// ------------------------------
// 5) Identifiers & Numbers
// ------------------------------


ID         : [A-Za-z_] [A-Za-z0-9_]* ;
CONST_INT  : [0-9]+ ;
CONST_FLOAT
    : [0-9]+ ('.' [0-9]*)? ([Ee][+\-]? [0-9]+)? 
    | '.' [0-9]+ 
    | [0-9]+ '.' 
    ;
