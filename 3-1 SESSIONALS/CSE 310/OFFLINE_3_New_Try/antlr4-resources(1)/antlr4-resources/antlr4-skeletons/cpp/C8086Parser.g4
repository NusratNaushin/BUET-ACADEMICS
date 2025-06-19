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

    #include "2105168_header_files/2105168_SymbolInfo.h"
    #include "2105168_header_files/2105168_SymbolTable.h"

    SymbolTable* symbolTable = new SymbolTable(7);

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

start
  
	returns[std::string text, int line]:
    p=program {
        
        $text = $p.text;
        $line = $p.line;
        writeIntoparserLogFile("Parsing completed successfully with " + std::to_string(syntaxErrorCount) + " syntax errors.");


        writeIntoLexLogFile("Line "+std::to_string($line)+": start : program\n\n");
                symbolTable->print_current_scope_table(lexLogFile);

        writeIntoLexLogFile("Total number of lines: "+std::to_string($line)+"\n");
        writeIntoLexLogFile("Total number of errors:");




	};


program
    returns[std::string text, int line]:
        pu=program u=unit {  
        $text = $pu.text +"\n"+$u.text;
        $line = $u.line;
        writeIntoLexLogFile("Line "+std::to_string($line)+": program : program unit\n\n"+$text+"\n");
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

	ts=type_specifier ID LPAREN pl=parameter_list
     RPAREN SEMICOLON {  
        $text = $ts.text +" "+ $ID->getText() + $LPAREN->getText() + $pl.text+ $RPAREN->getText() +  $SEMICOLON->getText();
        $line = $SEMICOLON->getLine(); 
         SymbolInfo* funcSymbol = new SymbolInfo($ID->getText(), "ID");
        funcSymbol->isFunction = true;
        funcSymbol->isFunctiondefined = false;
        funcSymbol->returnType = $ts.text;
        funcSymbol->parameterList = $pl.plist;

        SymbolInfo* existing = symbolTable->LookUP($ID->getText());
        if (existing && existing->isFunction) {
            writeIntoLexLogFile("Error at line " + std::to_string($line) + ": Redeclaration of function " + $ID->getText());
        } else {
            symbolTable->Insert(funcSymbol->getSymbolName(), funcSymbol->getSymbolType());
        }
    for (auto& param : $pl.plist) {




        symbolTable->Insert(param.second, "ID");
    }

        writeIntoLexLogFile("Line "+std::to_string($line)+": func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON\n\n"+$text+"\n");

    }
	| ts=type_specifier ID LPAREN RPAREN SEMICOLON {  
        $text = $ts.text + " "+$ID->getText() + $LPAREN->getText() + $RPAREN->getText() +  $SEMICOLON->getText();
        $line = $SEMICOLON->getLine(); 
          SymbolInfo* funcSymbol = new SymbolInfo($ID->getText(), "ID");
        funcSymbol->isFunction = true;
        funcSymbol->isFunctiondefined = false;
        funcSymbol->returnType = $ts.text;

        SymbolInfo* existing = symbolTable->LookUP($ID->getText());
        if (existing && 
        
        existing->isFunction) {
            writeIntoLexLogFile("Error at line " + std::to_string($line) + ": Redeclaration of function " + $ID->getText());
        } else {
            symbolTable->Insert(funcSymbol->getSymbolName(), funcSymbol->getSymbolType());
        }


        writeIntoLexLogFile("Line "+std::to_string($line)+": func_declaration : type_specifier ID LPAREN RPAREN SEMICOLON\n\n"+$text+"\n");

        
    };

func_definition
    returns[std::string text, int line]:
	ts=type_specifier ID LPAREN 
     pl=parameter_list RPAREN 
      cs=compound_statement {  
        $text = $ts.text+" "  + $ID->getText() +  $LPAREN->getText()+ $pl.text + $RPAREN->getText() + $cs.text;
        $line = $cs.line;
        SymbolInfo* funcSymbol = new SymbolInfo($ID->getText(), "ID");
        funcSymbol->isFunction = true;
        funcSymbol->isFunctiondefined = true;
        funcSymbol->returnType = $ts.text;
        funcSymbol->parameterList = $pl.plist;

        SymbolInfo* existing = symbolTable->LookUP($ID->getText());
        if (existing && existing->isFunction && existing->isFunctiondefined) {
            writeIntoLexLogFile("Error at line " + std::to_string($line) + ": Multiple definition of function " + $ID->getText());
        } else {
            symbolTable->Insert(funcSymbol->getSymbolName(), funcSymbol->getSymbolType());
        }



        symbolTable->print_current_scope_table(lexLogFile);
        writeIntoLexLogFile("Line "+std::to_string($line)+": func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement\n\n"+$text+"\n");


    }
	| ts=type_specifier ID LPAREN RPAREN cs=compound_statement { 
        $text = $ts.text +" " + $ID->getText() +  $LPAREN->getText() + $RPAREN->getText() + $cs.text;
        $line = $cs.line;
        SymbolInfo* funcSymbol = new SymbolInfo($ID->getText(), "ID");
        funcSymbol->isFunction = true;
        funcSymbol->isFunctiondefined = true;
        funcSymbol->returnType = $ts.text;

        SymbolInfo* existing = symbolTable->LookUP($ID->getText());
        if (existing && existing->isFunction && existing->isFunctiondefined) {
            writeIntoLexLogFile("Error at line " + std::to_string($line) + ": Multiple definition of function " + $ID->getText());
        } else {
            symbolTable->Insert(funcSymbol->getSymbolName(), funcSymbol->getSymbolType());
        }
        symbolTable->print_current_scope_table(lexLogFile);
        writeIntoLexLogFile("Line "+std::to_string($line)+": func_definition : type_specifier ID LPAREN RPAREN compound_statement\n\n"+$text+"\n");


    };


parameter_list
    returns[std::string text, int line,std::vector<std::pair<std::string, std::string>> plist]:
	pl=parameter_list COMMA ts=type_specifier ID {
        $text =$pl.text+$COMMA->getText()+ $ts.text +" " + $ID->getText();
        $line = $ID->getLine();
        $plist = $pl.plist;
        $plist.push_back(std::make_pair($ts.text, $ID->getText()));
        symbolTable->Insert($ID->getText(), "ID");
        writeIntoLexLogFile("Line " + std::to_string($line) + ": parameter_list : parameter_list COMMA type_specifier ID\n\n"+$text+"\n");
		}
	| pl=parameter_list COMMA ts=type_specifier {
        $text =$pl.text + $COMMA->getText() +  $ts.text ;
        $line = $ts.line;
        $plist = $pl.plist;
        $plist.push_back(std::make_pair($ts.text, ""));
        writeIntoLexLogFile("Line " + std::to_string($line) + ": parameter_list : parameter_list COMMA type_specifier \n" +$text + "\n");
		}
	| ts=type_specifier ID {
        $text = $ts.text + " " + $ID->getText()   ;
        $line = $ID->getLine();
        $plist.push_back(std::make_pair($ts.text, $ID->getText()));
        symbolTable->Insert($ID->getText(), "ID");
        writeIntoLexLogFile("Line " + std::to_string($line) +": parameter_list : type_specifier ID\n\n" + $text + "\n");
		}
	| ts=type_specifier {

        $text = $ts.text ;
        $line = $ts.line;
        $plist.push_back(std::make_pair($ts.text, ""));
        writeIntoLexLogFile("Line " + std::to_string($line) + ": parameter_list : type_specifier \n" +$ts.text+ "\n");
		};

compound_statement
    returns[std::string text, int line]:
    LCURL {  symbolTable->EnterScope(); }
    ss=statements 
    RCURL  {
        $text = $LCURL->getText()+"\n" + $ss.text +"\n" + $RCURL->getText();
        $line = $RCURL.line;
        writeIntoLexLogFile("Line "+std::to_string($line)+": compound_statement : LCURL statements RCURL\n\n"+$text+"\n");
        symbolTable->print_current_scope_table(lexLogFile);
        symbolTable->ExitScope();
    }
    | LCURL {  symbolTable->EnterScope(); }
    RCURL {
        $text = $LCURL->getText();
        $line = $LCURL->getLine();
        symbolTable->print_current_scope_table(lexLogFile);
        symbolTable->ExitScope();

    };

var_declaration
    returns[std::string text, int line]:
	t = type_specifier dl = declaration_list sm = SEMICOLON {
        $text = $t.text +" "+ $dl.text + $sm->getText() ;
        $line = $t.line;
        writeIntoLexLogFile("Line "+std::to_string($line)+": var_declaration : type_specifier declaration_list SEMICOLON\n\n"+$text+"\n");

        writeIntoparserLogFile(
            std::string("Variable Declaration: type_specifier declaration_list ") +
            std::to_string($sm->getType()) +
            " at line " + std::to_string($sm->getLine())
        );

        writeIntoparserLogFile("type_specifier name_line: " + $t.text);

        std::stringstream ss($dl.text);

        std::string name;

        while(std::getline(ss,name,',')){ 
            name.erase(0, name.find_first_not_of(" \t"));
            name.erase(name.find_last_not_of(" \t") + 1);

            if(!symbolTable->Insert(name,"ID")){   
                writeIntoLexLogFile("Error at line "+std::to_string($line)+":  Multiple declaration of "+name+"\n");

            }
         }

        
      }

	| t = type_specifier de = declaration_list_err sm = SEMICOLON {
        $text = $t.text;
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
	returns[std::string text , int line]:
	INT {
            $text = $INT->getText();
            $line = $INT->getLine();
			writeIntoLexLogFile("Line " + std::to_string($INT->getLine()) + ": type_specifier : INT\n\n" + $INT->getText() + "\n");
        }
	| FLOAT {
            $text = $FLOAT->getText();
            $line = $FLOAT->getLine();
			writeIntoLexLogFile("Line " + std::to_string($FLOAT->getLine()) + ": type_specifier : FLOAT\n\n" +$FLOAT->getText() + "\n");        
		}
	| VOID {
            $text = $VOID->getText();
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
    | ID LTHIRD CONST_FLOAT RTHIRD { 
        $text = $ID->getText() + $LTHIRD->getText() + $CONST_INT->getText() + $RTHIRD->getText();
        $line = $ID->getLine();
        
        writeIntoLexLogFile("Error at line " + std::to_string($line) + ":  Expression inside third brackets not an integer\n\n" +$text + "\n");        

    }
    ; 

statements
    returns[std::string text , int line]:
	s=statement {
        $text = $s.text;
        $line = $s.line;
        writeIntoLexLogFile("Line " + std::to_string($line) + ": statements : statement\n\n" + $text+"\n"); 
    }
	| ss=statements s=statement {
        $text = $ss.text +"\n" + $s.text;
        $line = $s.line;
        writeIntoLexLogFile("Line " + std::to_string($line) + ": statements : statements statement\n\n" +$text+"\n"); 

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
        $text = $FOR.text +  $LPAREN->getText() +  $es1.text + $es2.text + $e.text   + $RPAREN->getText() + $s.text;
        $line = $s.line;
        writeIntoLexLogFile("Line " + std::to_string($s.line) + ": statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement\n\n" + $text +"\n"); 

    }
	| IF LPAREN e=expression RPAREN s=statement {
        $text = $IF->getText()+ $LPAREN->getText()+ $e.text  + $RPAREN->getText() +$s.text;
        $line = $IF->getLine();
        writeIntoLexLogFile("Line " + std::to_string($line) + ": statement : IF LPAREN expression RPAREN statement\n\n" + $text +"\n"); 

    }
	| IF LPAREN e=expression RPAREN s1=statement ELSE s2=statement {
        $text = $IF->getText() + $LPAREN->getText() + $e.text  + $RPAREN->getText() + $s1.text+ $ELSE->getText() +" "+  $s2.text ;
       $line = $IF->getLine();
        writeIntoLexLogFile("Line " + std::to_string($line) + ": statement : IF LPAREN expression RPAREN statement ELSE statement\n\n" + $text +"\n"); 

    }
	| WHILE LPAREN e=expression RPAREN s=statement {
        $text = $WHILE->getText() + $LPAREN->getText() + $e.text  + $RPAREN->getText() + $s.text;
        $line = $s.line;
        writeIntoLexLogFile("Line " + std::to_string($line) + ": statement : WHILE LPAREN expression RPAREN statement\n\n" + $text +"\n"); 

    }
	| PRINTLN LPAREN ID RPAREN SEMICOLON {
        $text = $PRINTLN->getText() + $LPAREN->getText() +  $ID->getText() +  $RPAREN->getText() +  $SEMICOLON->getText();
        $line = $SEMICOLON->getLine();
        writeIntoLexLogFile("Line " + std::to_string($line) + ": statement : PRINTLN LPAREN ID RPAREN SEMICOLON\n\n" + $text +"\n"); 

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
        writeIntoLexLogFile("Line " + std::to_string($SEMICOLON->getLine()) + ": expression_statement : SEMICOLON\n\n" + $text +"\n"); 

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
            writeIntoLexLogFile("Line "+  std::to_string($line)+": simple_expression : simple_expression ADDOP term\n\n" + $text + "\n"); 

          };

term
	returns[std::string text, int line]:
	u = unary_expression {
         
            $text = $u.text;
            $line = $u.line;
            writeIntoLexLogFile("Line "+  std::to_string($u.line)+": term : unary_expression\n\n" + $u.text + "\n"); 
            }
	| t=term MULOP ue=unary_expression {
            $text = $t.text+ $MULOP->getText() + $ue.text;
            $line = $ue.line;
            writeIntoLexLogFile("Line "+  std::to_string($ue.line)+": term : term MULOP unary_expression\n\n" + $text + "\n"); 

        };

unary_expression
	returns[std::string text, int line]:
	ADDOP ue=unary_expression {
            $text = $ADDOP->getText() + $ue.text;
            $line = $ADDOP->getLine();
        }
	| NOT ue=unary_expression {
            $text = $NOT->getText() + $ue.text;
            $line = $ue.line;
            writeIntoLexLogFile("Line "+  std::to_string($line)+": unary_expression : NOT unary_expression\n\n" + $text + "\n"); 

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
        $text = $v.text+$INCOP->getText();
        $line = $INCOP->getLine();
        writeIntoLexLogFile("Line "+  std::to_string($line)+": factor : variable INCOP\n\n" + $text + "\n");

    }
	| v = variable DECOP {
        $text = $v.text+$DECOP->getText();
        $line = $DECOP->getLine();
        writeIntoLexLogFile("Line "+  std::to_string($line)+": factor : variable DECOP\n\n" + $text + "\n");

    };

argument_list 
	returns[std::string text, int line]:
          a=arguments {   
            $text = $a.text;
            $line = $a.line;
            writeIntoLexLogFile("Line "+ std::to_string($line)+": argument_list : arguments\n\n"+$text+"\n");
          }
         |;

arguments	
    returns[std::string text, int line]:
         a=arguments COMMA le=logic_expression {    
            $text=$a.text +  $COMMA->getText()+  $le.text;
            $line=$le.line;
            writeIntoLexLogFile("Line "+ std::to_string($line)+": arguments : arguments COMMA logic_expression\n\n"+$text+"\n");

         }
        | le=logic_expression{

            $text=$le.text;
            $line=$le.line;
            writeIntoLexLogFile("Line "+ std::to_string($line)+": arguments : logic_expression\n\n"+$text+"\n");


        };


