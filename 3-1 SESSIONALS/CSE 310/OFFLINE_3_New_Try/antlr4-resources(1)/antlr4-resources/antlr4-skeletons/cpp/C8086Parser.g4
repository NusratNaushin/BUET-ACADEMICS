parser grammar C8086Parser;

options {
	tokenVocab = C8086Lexer;
}

@parser::header {
    #include <iostream>
    #include <fstream>
    #include <string>
    #include <cstdlib>
    #include "C8086Lexer.h"

    extern std::ofstream parserLogFile;
    extern std::ofstream errorFile;
	extern std::ofstream lexLogFile;


    extern int syntaxErrorCount;
}

@parser::members {
    void writeIntoparserLogFile(const std::string message) {
        if (!parserLogFile) {
            std::cout << "Error opening parserLogFile.txt" << std::endl;
            return;
        }

        parserLogFile << message << std::endl;
        parserLogFile.flush();
    }

    void writeIntoErrorFile(const std::string message) {
        if (!errorFile) {
            std::cout << "Error opening errorFile.txt" << std::endl;
            return;
        }
        errorFile << message << std::endl;
        errorFile.flush();
    }

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

start:
	program {
        writeIntoparserLogFile("Parsing completed successfully with " + std::to_string(syntaxErrorCount) + " syntax errors.");
	};

program
    returns[std::string text, int line]:
        pu=program unit {  
            $text = $pu.text;
        $line = $pu.line;
        writeIntoLexLogFile("Line "+std::to_string($line)+": program :program_unit\n\n"+$text+"\n");
        }

        |u=unit { 
        $text = $u.text;
        $line = $u.line;
        writeIntoLexLogFile("Line "+std::to_string($line)+": program : unit\n\n"+$text+"\n");

         }
        ;

unit 
    returns[std::string text, int line]:
    vd=var_declaration {  
        $text = $vd.text;
        $line = $vd.line;
        writeIntoLexLogFile("Line "+std::to_string($line)+": unit : var_declaration\n\n"+$text+"\n");

    }

    | fdec=func_declaration {  
        $text = $fdec.text;
        $line = $fdec.line;
        writeIntoLexLogFile("Line "+std::to_string($line)+": unit : func_declaration\n\n"+$text+"\n");

    }

    | fdef=func_definition {  
        $text = $fdef.text;
        $line = $fdef.line;
        writeIntoLexLogFile("Line "+std::to_string($line)+": unit : func_definition\n\n"+$text+"\n");
        
    }; 

func_declaration
    returns[std::string text, int line]:

	ts=type_specifier ID LPAREN pl=parameter_list RPAREN SEMICOLON {  
        $text = $ts.text + $ID->getText() + $LPAREN->getText() + $pl.text+ $RPAREN->getText() +  $SEMICOLON->getText();
        $line = $SEMICOLON->getLine(); 
    }
	| ts=type_specifier ID LPAREN RPAREN SEMICOLON {  
        $text = $ts.text + $ID->getText() + $LPAREN->getText() + $RPAREN->getText() +  $SEMICOLON->getText();
        $line = $SEMICOLON->getLine(); 
        
    };

func_definition
    returns[std::string text, int line]:
	ts=type_specifier ID LPAREN pl=parameter_list RPAREN cs=compound_statement {  
        $text = $ts.name_line+" "  + $ID->getText() +  $LPAREN->getText()+ $pl.text + $RPAREN->getText() + $cs.text;
        $line = $cs.line;
        writeIntoLexLogFile("Line "+std::to_string($line)+": func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement\n\n"+$text+"\n");


    }
	| ts=type_specifier ID LPAREN RPAREN cs=compound_statement { 
        $text = $ts.name_line +" " + $ID->getText() +  $LPAREN->getText() + $RPAREN->getText() + $cs.text;
        $line = $cs.line;
        writeIntoLexLogFile("Line "+std::to_string($line)+": func_definition : type_specifier ID LPAREN RPAREN compound_statement\n\n"+$text+"\n");


    };


parameter_list
    returns[std::string text, int line]:
	parameter_list COMMA type_specifier ID {
        $text = $type_specifier.name_line +" " + $ID->getText();
        $line = $ID->getLine();
        writeIntoLexLogFile("Line " + std::to_string($ID->getLine()) + ": parameter_list : type_specifier ID\n" +$type_specifier.name_line +" " + $ID->getText() + "\n");
		}
	| parameter_list COMMA type_specifier {
        $text = $type_specifier.name_line ;
        $line = $ID->getLine();
        writeIntoLexLogFile("Line " + std::to_string($COMMA->getLine()) + ": parameter_list : type_specifier \n" +$type_specifier.name_line + "\n");
		}
	| type_specifier ID {
        $text = $type_specifier.name_line + " " + $ID->getText()   ;
        $line = $ID->getLine();
        writeIntoLexLogFile("Line " + std::to_string($ID->getLine()) +": parameter_list : type_specifier ID\n\n" + $type_specifier.name_line + " " + $ID->getText() + "\n");
		}
	| type_specifier {

        $text = $type_specifier.name_line ;
        $line = $ID->getLine();
        writeIntoLexLogFile("Line " + std::to_string($type_specifier.start->getLine()) + ": parameter_list : type_specifier \n" +$type_specifier.name_line+ "\n");
		};

compound_statement
    returns[std::string text, int line]:
    LCURL ss=statements RCURL  {
        $text = $LCURL->getText()+"\n" + $ss.text +"\n" + $RCURL->getText();
        $line = $RCURL.line;
        writeIntoLexLogFile("Line "+std::to_string($line)+": compound_statement : LCURL statements RCURL\n\n"+$text+"\n");
    }
    | LCURL RCURL {
        $text = $LCURL->getText();
        $line = $LCURL->getLine();
    };

var_declaration
    returns[std::string text, int line]:
	t = type_specifier dl = declaration_list sm = SEMICOLON {
        $text = $t.name_line +" "+ $dl.text + $sm->getText() ;
        $line = $t.line;
        writeIntoLexLogFile("Line "+std::to_string($line)+": var_declaration : type_specifier declaration_list SEMICOLON\n\n"+$text+"\n");

        writeIntoparserLogFile(
            std::string("Variable Declaration: type_specifier declaration_list ") +
            std::to_string($sm->getType()) +
            " at line " + std::to_string($sm->getLine())
        );

        writeIntoparserLogFile("type_specifier name_line: " + $t.name_line);

        
      }

	| t = type_specifier de = declaration_list_err sm = SEMICOLON {
        $text = $t.name_line;
        $line = $t.line;
        writeIntoErrorFile(
            std::string("Line# ") + std::to_string($sm->getLine()) +
            " with error name: " + $de.error_name +
            " - Syntax error at declaration list of variable declaration"
        );

        syntaxErrorCount++;
      };

declaration_list_err
	returns[std::string error_name]:
	{
        $error_name = "Error in declaration list";
    };

type_specifier
	returns[std::string name_line , int line]:
	INT {
            $name_line = $INT->getText();
            $line = $INT->getLine();
			writeIntoLexLogFile("Line " + std::to_string($INT->getLine()) + ": type_specifier : INT\n\n" + $INT->getText() + "\n");
        }
	| FLOAT {
            $name_line = $FLOAT->getText();
            $line = $FLOAT->getLine();
			writeIntoLexLogFile("Line " + std::to_string($FLOAT->getLine()) + ": type_specifier : FLOAT\n\n" +$FLOAT->getText() + "\n");        
		}
	| VOID {
            $name_line = $VOID->getText();
            $line = $VOID->getLine();
            writeIntoLexLogFile("Line " + std::to_string($VOID->getLine()) + ": type_specifier : VOID\n\n" +$VOID->getText() + "\n");        
        };

declaration_list
    returns[std::string text , int line]:
	dl=declaration_list COMMA ID { 

        $text = $dl.text + $COMMA->getText() + $ID->getText();
        $line = $ID->getLine();

        writeIntoLexLogFile("Line " + std::to_string($line) + ": declaration_list : declaration_list COMMA ID\n\n" +$text + "\n");        

    }
	| dl=declaration_list COMMA ID LTHIRD CONST_INT RTHIRD
    { 
        $text = $dl.text + $COMMA->getText() + $ID->getText() + $LTHIRD->getText() + $CONST_INT->getText() + $RTHIRD->getText();
        $line = $RTHIRD->getLine();
        writeIntoLexLogFile("Line " + std::to_string($line) + ": declaration_list : declaration_list COMMA ID LTHIRD CONST_INT RTHIRD\n\n" +$text + "\n");        

    }
	| ID { 
        $text = $ID->getText();
        $line = $ID->getLine();
        writeIntoLexLogFile("Line " + std::to_string($line) + ": declaration_list : ID\n\n" +$text + "\n");        

    }
    
	| ID LTHIRD CONST_INT RTHIRD { 
        $text = $ID->getText() + $LTHIRD->getText() + $CONST_INT->getText() + $RTHIRD->getText();
        $line = $ID->getLine();
        writeIntoLexLogFile("Line " + std::to_string($line) + ": declaration_list : ID LTHIRD CONST_INT RTHIRD\n\n" +$text + "\n");        

    }
    ; 

statements
    returns[std::string text , int line]:
	s=statement {
        $text = $s.text;
        $line = $s.line;
        writeIntoLexLogFile("Line " + std::to_string($s.line) + ": statements : statement\n\n" + $s.text+"\n"); 
    }
	| ss=statements s=statement {
        $text = $ss.text +"\n" + $s.text;
        $line = $s.line;
        writeIntoLexLogFile("Line " + std::to_string($s.line) + ": statements : statements statement\n\n" +$text+"\n"); 

    };


statement
	returns[std::string text, int line]:
	v=var_declaration {
        $text = $v.text;
        $line = $v.line;
        writeIntoLexLogFile("Line "+  std::to_string($line) +": statement : var_declaration\n\n"+$text + "\n" );
    }
	| es=expression_statement {
        $text = $es.text;
        $line = $es.line;
        writeIntoLexLogFile("Line "+  std::to_string($line) +": statement : expression_statement\n\n"+$text + "\n" );

    }
	| cs=compound_statement {
        $text = $cs.text;
        $line = $cs.line;
        writeIntoLexLogFile("Line "+  std::to_string($line) +": statement : compound_statement\n\n"+$text + "\n" );

    }
	| FOR LPAREN es1=expression_statement es2=expression_statement e=expression RPAREN s=statement {
        $text = $FOR.text + " " + $LPAREN->getText() + " " +  $es1.text + " " + $es2.text + " " + $e.text  +" " + $RPAREN->getText() +" " + $s.text;
        $line = $s.line;
        writeIntoLexLogFile("Line " + std::to_string($s.line) + ": FOR LPAREN expression_statement expression_statement expression RPAREN statement\n\n" + $text +"\n"); 

    }
	| IF LPAREN e=expression RPAREN s=statement {
        $text = $IF->getText() + " " + $LPAREN->getText() + " " + $e.text  +" " + $RPAREN->getText() +" " + $s.text;
        $line = $IF->getLine();
    }
	| IF LPAREN e=expression RPAREN s1=statement ELSE s2=statement {
        $text = $IF->getText() + " " + $LPAREN->getText() + " " + $e.text  +" " + $RPAREN->getText() +" " + $s1.text+ " " + $ELSE->getText() + " " + $s2.text ;
        $line = $IF->getLine();
    }
	| WHILE LPAREN e=expression RPAREN s=statement {
        $text = $WHILE->getText() + " " + $LPAREN->getText() + " " + $e.text  +" " + $RPAREN->getText() +" " + $s.text;
        $line = $WHILE->getLine();
    }
	| PRINTLN LPAREN ID RPAREN SEMICOLON {
        $text = $PRINTLN->getText() + " " + $LPAREN->getText() + " " + $ID->getText() + " " +  $RPAREN->getText() + " " + $SEMICOLON->getText();
        $line = $PRINTLN->getLine();
    }
	| RETURN e=expression SEMICOLON {
        $text = $RETURN->getText() + " " + $e.text + $SEMICOLON->getText();
        $line = $RETURN->getLine();
        
        writeIntoLexLogFile("Line " + std::to_string($SEMICOLON->getLine()) + ": statement : RETURN expression SEMICOLON\n\n" + $RETURN->getText() +" "+ $e.text+ $SEMICOLON->getText() +"\n"); 

      };

expression_statement returns[std::string text, int line]: 
    SEMICOLON {
        $text = $SEMICOLON->getText();
        $line = $SEMICOLON->getLine();
        writeIntoLexLogFile("Line " + std::to_string($SEMICOLON->getLine()) + ": expression_statement : expression SEMICOLON\n\n" + $text +"\n"); 

    }
    | e=expression SEMICOLON {
        $text = $e.text + $SEMICOLON->getText();
        $line = $SEMICOLON->getLine();
        writeIntoLexLogFile("Line " + std::to_string($SEMICOLON->getLine()) + ": expression_statement : expression SEMICOLON\n\n" + $text +"\n"); 

    };

variable
	returns[std::string text, int line]:
	ID {
        $text = $ID->getText();
        $line = $ID->getLine();
        writeIntoLexLogFile("Line " + std::to_string($ID->getLine()) + ": variable : ID\n\n" + $ID->getText() +"\n"); 
    
        }
	| ID LTHIRD e=expression RTHIRD { 
        $text = $ID->getText() + $LTHIRD->getText() + $e.text + $RTHIRD->getText();
        $line = $RTHIRD->getLine();
        writeIntoLexLogFile("Line " + std::to_string($line) + ": variable : ID LTHIRD expression RTHIRD\n\n" + $text +"\n"); 

    };

expression
	returns[std::string text, int line]:
	l = logic_expression {
            $text=$l.text;
            $line=$l.line;
            writeIntoLexLogFile("Line "+  std::to_string($l.line)+": expression : logic_expression\n\n" + $l.text + "\n"); 
        }
	| v=variable ASSIGNOP le=logic_expression {
            $text= $v.text + $ASSIGNOP->getText() + $le.text;
            $line=$le.line;  
            writeIntoLexLogFile("Line "+  std::to_string($line)+": expression : variable ASSIGNOP logic_expression\n\n" + $text + "\n"); 
 

       };

logic_expression
	returns[std::string text, int line]:
	r = rel_expression {
            $text = $r.text;
            $line = $r.line;
            writeIntoLexLogFile("Line "+  std::to_string($r.line)+": logic_expression : rel_expression\n\n" + $r.text + "\n"); 

        }
	| re1=rel_expression LOGICOP re2=rel_expression {
            $text = $re1.text+$LOGICOP->getText() + $re2.text;
            $line = $re2.line;
            writeIntoLexLogFile("Line "+  std::to_string($line)+": logic_expression : rel_expression LOGICOP rel_expression\n\n" + $text + "\n"); 

        };

rel_expression
	returns[std::string text, int line]:
	s = simple_expression {
            $text = $s.text;
            $line = $s.line;
            writeIntoLexLogFile("Line "+  std::to_string($s.line)+": rel_expression : simple_expression\n\n" + $s.text + "\n"); 
            }
	| s1=simple_expression RELOP s2=simple_expression {
            $text = $s1.text + $RELOP->getText() + $s2.text;
            $line = $RELOP->getLine();
            writeIntoLexLogFile("Line "+  std::to_string($line)+": rel_expression : simple_expression RELOP simple_expression\n\n" + $text + "\n"); 

        };

simple_expression
	returns[std::string text, int line]:
	t = term {
            $text = $t.text;
            $line = $t.line;
            writeIntoLexLogFile("Line "+  std::to_string($t.line)+": simple_expression : term\n\n" + $t.text + "\n"); 
            }
	| s=simple_expression ADDOP t=term {
            $text = $s.text+$ADDOP->getText()+$t.text;
            $line = $t.line;
            writeIntoLexLogFile("Line "+  std::to_string($line)+": simple_expression : simple_expression term\n\n" + $text + "\n"); 

          };

term
	returns[std::string text, int line]:
	u = unary_expression {
         
            $text = $u.text;
            $line = $u.line;
            writeIntoLexLogFile("Line "+  std::to_string($u.line)+": term : unary_expression\n\n" + $u.text + "\n"); 
            }
	| term MULOP unary_expression {
            $text = $MULOP->getText();
            $line = $MULOP->getLine();
        };

unary_expression
	returns[std::string text, int line]:
	ADDOP unary_expression {
            $text = $ADDOP->getText();
            $line = $ADDOP->getLine();
        }
	| NOT unary_expression {
            $text = $NOT->getText();
            $line = $NOT->getLine();
        }
	| f = factor {
            $text = $f.text;
            $line = $f.line;
            writeIntoLexLogFile("Line "+  std::to_string($f.line)+": unary_expression : factor\n\n" + $f.text + "\n"); 
            };

factor
	returns[std::string text, int line]:
	v = variable {
        $text = $v.text;
        $line = $v.line;
        writeIntoLexLogFile("Line "+  std::to_string($v.line)+": factor : variable\n\n" + $v.text + "\n");
        }
	| ID LPAREN a = argument_list RPAREN {
        $text = $ID->getText()+$LPAREN->getText()+ $a.text + $RPAREN->getText();
        $line = $ID->getLine();
        writeIntoLexLogFile("Line "+  std::to_string($line)+": factor : ID LPAREN argument_list RPAREN\n\n" + $text + "\n");

    }
	| LPAREN e = expression RPAREN { 
        $text = $LPAREN->getText() + $e.text + $RPAREN->getText();
        $line = $RPAREN->getLine();
        writeIntoLexLogFile("Line "+  std::to_string($line)+": factor : LPAREN expression RPAREN\n\n" + $text + "\n");

     }
	| CONST_INT {
        $text = $CONST_INT->getText();
        $line = $CONST_INT->getLine();
        writeIntoLexLogFile("Line "+  std::to_string($line)+": factor : CONST_INT\n\n" + $text + "\n");

    }
	| CONST_FLOAT {
        $text = $CONST_FLOAT->getText();
        $line = $CONST_FLOAT->getLine();
        writeIntoLexLogFile("Line "+  std::to_string($line)+": factor : CONST_FLOAT\n\n" + $text + "\n");

    }
	| v = variable INCOP {
        $text = $INCOP->getText();
        $line = $INCOP->getLine();
    }
	| v = variable DECOP {
        $text = $DECOP->getText();
        $line = $DECOP->getLine();
    };

argument_list: arguments |;

arguments: arguments COMMA logic_expression | logic_expression;