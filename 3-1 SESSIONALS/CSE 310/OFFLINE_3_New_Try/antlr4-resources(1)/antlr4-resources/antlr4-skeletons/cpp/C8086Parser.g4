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
    extern std::string currentFunctionReturnType;
    extern int argumentCount;
    extern int paramCount;
    extern int errorCount;
    extern bool multipleDeclaration;
    extern std::vector<std::string> argumentTypes;
    extern std::vector<bool> argumentIsArray;
    extern std::vector<std::pair<std::string, std::string>> plist;
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
	p = program {
        
        $text = $p.text;
        $line = $p.line;
       // writeIntoparserLogFile("Parsing completed successfully with " + std::to_string(syntaxErrorCount) + " syntax errors.");


        writeIntoparserLogFile("Line "+std::to_string($line)+": start : program\n");
        symbolTable->print_current_scope_table(parserLogFile);


        writeIntoparserLogFile("\nTotal number of lines: "+std::to_string($line));
        writeIntoparserLogFile("Total number of errors: "+std::to_string(errorCount));




	};

program
	returns[std::string text, int line]:
	pu = program u = unit {  
        $text = $pu.text +"\n"+$u.text;
        $line = $u.line;
        writeIntoparserLogFile("Line "+std::to_string($line)+": program : program unit\n\n"+$text+"\n");
        }
	| u = unit { 
        $text = $u.text;
        $line = $u.line;
        writeIntoparserLogFile("Line "+std::to_string($line)+": program : unit\n\n"+$text+"\n");

         };

unit
	returns[std::string text, int line]:
	vd = var_declaration {  
        $text = $vd.text;
        $line = $vd.line;
        writeIntoparserLogFile("Line "+std::to_string($line)+": unit : var_declaration\n\n"+$text+"\n");

    }
	| fdec = func_declaration {  
        $text = $fdec.text;
        $line = $fdec.line;
        writeIntoparserLogFile("Line "+std::to_string($line)+": unit : func_declaration\n\n"+$text+"\n");

    }
	| fdef = func_definition {  
        $text = $fdef.text;
        $line = $fdef.line;
        writeIntoparserLogFile("Line "+std::to_string($line)+": unit : func_definition\n\n"+$text+"\n");
        
    };

func_declaration
	returns[std::string text, int line ,std::string type]:
	ts = type_specifier ID {
        paramCount = 0;
    } LPAREN pl = parameter_list RPAREN SEMICOLON {  

        $text = $ts.text +" "+ $ID->getText() + $LPAREN->getText() + $pl.text+ $RPAREN->getText() +  $SEMICOLON->getText();
        $line = $SEMICOLON->getLine(); 
        $type = $ts.text;


        SymbolInfo* funcSymbol = new SymbolInfo($ID->getText(), "ID");

        funcSymbol->setIsFunction(true);
        funcSymbol->setIsFunctionDefined(true);
        funcSymbol->setReturnType($ts.text);
        funcSymbol->setParameterList($pl.plist);



        SymbolInfo* existing = symbolTable->LookUP($ID->getText());
        if (existing && existing->getIsFunction() && existing->getIsFunctionDefined()) {
            // writeIntoparserLogFile("Error at line " + std::to_string($line) + ": Multiple definition of function " + $ID->getText());
        } else {
            if(symbolTable->Insert(funcSymbol)){ 
                std::cout << funcSymbol->getSymbolName() << $ID->getText() << std::endl;

              //  writeIntoErrorFile("Error at line "+std::to_string($line)+": Multiple declaration of "+$ID->getText()+"\n");

            }
        }

    // for (auto& param : $pl.plist) {
    //     symbolTable->Insert(param.second, "ID");
    // }


        writeIntoparserLogFile("Line "+std::to_string($line)+": func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON\n\n"+$text+"\n");


    }
	| ts = type_specifier ID LPAREN RPAREN SEMICOLON {  
        $text = $ts.text + " "+$ID->getText() + $LPAREN->getText() + $RPAREN->getText() +  $SEMICOLON->getText();
        $line = $SEMICOLON->getLine(); 
        $type = $ts.text;


        SymbolInfo* funcSymbol = new SymbolInfo($ID->getText(), "ID");
        funcSymbol->setIsFunction(true);
        funcSymbol->setIsFunctionDefined(true);
        funcSymbol->setReturnType($ts.text);



        SymbolInfo* existing = symbolTable->LookUP($ID->getText());
        if (existing && existing->getIsFunction() && existing->getIsFunctionDefined()) {
            writeIntoparserLogFile("Error at line " + std::to_string($line) + ": Redeclaration of function " + $ID->getText());
        } else {
            if(symbolTable->Insert(funcSymbol)){ 
                    std::cout << funcSymbol->getSymbolName() << $ID->getText() << std::endl;
                         //       writeIntoErrorFile("Error at line "+std::to_string($line)+":  Multiple declaration of "+$ID->getText()+"\n");

            }        }

     

        writeIntoparserLogFile("Line "+std::to_string($line)+": func_declaration : type_specifier ID LPAREN RPAREN SEMICOLON\n\n"+$text+"\n");

        
    };

func_definition
	returns[std::string text, int line,std::string type]:
	ts = type_specifier ID LPAREN pl = parameter_list {
        
        SymbolInfo* funcSymbol = new SymbolInfo($ID->getText(), "ID");
        funcSymbol->setIsFunction(true);
        funcSymbol->setIsFunctionDefined(true);
        funcSymbol->setReturnType($ts.text);
        funcSymbol->setParameterList($pl.plist);
        plist = $pl.plist;
        // std::cout << $cs.type << " " << $ts.text << std::endl;

        // if($cs.type != $ts.text){ 
        //     writeIntoErrorFile("Error at line "+std::to_string($line)+": Return Type mismatch of "+funcSymbol->getSymbolName()+"\n");
        // }
        
        SymbolInfo* existing = symbolTable->LookUP($ID->getText());

        if (existing && existing->getIsFunction() && existing->getIsFunctionDefined()) {
           // writeIntoparserLogFile("Error at line " + std::to_string($line) + ": Multiple definition of function " + $ID->getText());
        } else {
            symbolTable->Insert(funcSymbol);
        }



        // for(const auto& param : $pl.plist) {
        //     SymbolInfo* paramSymbol = new SymbolInfo(param.second, "ID");
        //     paramSymbol->setIsArray(false);
        //     paramSymbol->setSymbolDataType(param.first);
        //     if(!symbolTable->Insert(param.second, "ID")){
        //         // writeIntoparserLogFile("Error at line "+std::to_string($pl.line)+": Multiple declaration of "+param.second+" in parameter\n");
        //         // writeIntoErrorFile("Error at line "+std::to_string($line)+": Multiple declaration of "+param.second+" in parameter\n");
        //         errorCount++;
        //     }
        // }
     } RPAREN 
     cs = compound_statement {  


        $text = $ts.text+" "  + $ID->getText() +  $LPAREN->getText()+ $pl.text + $RPAREN->getText() + $cs.text;
        $line = $cs.line;
        $type = $ts.text;

        //symbolTable->print_current_scope_table(parserLogFile);

        writeIntoparserLogFile("\nLine "+std::to_string($line)+": func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement\n\n"+$text+"\n");
 

    }
	| ts = type_specifier ID LPAREN RPAREN { 

        SymbolInfo* funcSymbol = new SymbolInfo($ID->getText(), "ID");
        funcSymbol->setIsFunction(true);
        funcSymbol->setIsFunctionDefined(true);
        funcSymbol->setReturnType($ts.text);

        // if($cs.type != $ts.text){ 
        //     writeIntoErrorFile("Error at line "+std::to_string($line)+": Return Type mismatch of "+funcSymbol->getSymbolName()+"\n");
        // }
        
        SymbolInfo* existing = symbolTable->LookUP($ID->getText());
        if (existing && existing->getIsFunction() && existing->getIsFunctionDefined()) {
           // writeIntoparserLogFile("Error at line " + std::to_string($line) + ": Multiple definition of function " + $ID->getText());
        } else {
            symbolTable->Insert(funcSymbol);
        }

        } 
        cs = compound_statement { 

        $text = $ts.text +" " + $ID->getText() +  $LPAREN->getText() + $RPAREN->getText() + $cs.text;
        $line = $cs.line;


     //   symbolTable->print_current_scope_table(parserLogFile);


        writeIntoparserLogFile("\nLine "+std::to_string($line)+": func_definition : type_specifier ID LPAREN RPAREN compound_statement\n\n"+$text+"\n");


    };

parameter_list
	returns[std::string text, int line,std::vector<std::pair<std::string, std::string>> plist]:
	pl = parameter_list COMMA ts = type_specifier ID {
        $text =$pl.text+$COMMA->getText()+ $ts.text +" " + $ID->getText();
        $line = $ID->getLine();
        $plist = $pl.plist;
                paramCount++;

        $plist.push_back(std::make_pair($ts.text, $ID->getText()));
        


         writeIntoparserLogFile("Line " + std::to_string($line) + ": parameter_list : parameter_list COMMA type_specifier ID\n\n"+$text+"\n");
		}
	| pl = parameter_list COMMA ts = type_specifier {
        $text =$pl.text + $COMMA->getText() +  $ts.text ;
        $line = $ts.line;
        $plist = $pl.plist;
        $plist.push_back(std::make_pair($ts.text, ""));
        writeIntoparserLogFile("Line " + std::to_string($line) + ": parameter_list : parameter_list COMMA type_specifier \n" +$text + "\n");
		}
	| ts = type_specifier ID {
        $text = $ts.text + " " + $ID->getText()   ;
        $line = $ID->getLine();
        $plist.push_back(std::make_pair($ts.text, $ID->getText()));

        SymbolInfo* paramSymbol = new SymbolInfo($ID->getText(), "ID");
        paramSymbol->setIsArray(false);
        paramSymbol->setType($ts.text);
        // if(!symbolTable->Insert(paramSymbol)){
        //     writeIntoparserLogFile("Error at line "+std::to_string($line)+": Multiple declaration of "+$ID->getText()+" in parameter\n");
        //     writeIntoErrorFile("Error at line "+std::to_string($line)+": Multiple declaration of "+$ID->getText()+" in parameter\n");
        // }
        writeIntoparserLogFile("Line " + std::to_string($line) +": parameter_list : type_specifier ID\n\n" + $text + "\n");
		}
	| ts = type_specifier {

        $text = $ts.text ;
        $line = $ts.line;
        $plist.push_back(std::make_pair($ts.text, ""));
        writeIntoparserLogFile("Line " + std::to_string($line) + ": parameter_list : type_specifier \n" +$ts.text+ "\n");
		};

compound_statement
	returns[std::string text, int line , std::string type]:
	LCURL { symbolTable->EnterScope();  

        for(const auto& param : plist) {
            SymbolInfo* paramSymbol = new SymbolInfo(param.second, "ID");
            paramSymbol->setIsArray(false);
            paramSymbol->setSymbolDataType(param.first);
            if(!symbolTable->Insert(param.second, "ID")){
           //     errorCount++;
            }
        }
        plist.clear();
        
         }
     ss = statements { 
        std::cout << "ss  type"<<$ss.type <<std::endl;
        $type = $ss.type;
    } RCURL {
        $text = $LCURL->getText()+"\n" + $ss.text +"\n" + $RCURL->getText();
        $line = $RCURL.line;
        writeIntoparserLogFile("Line "+std::to_string($line)+": compound_statement : LCURL statements RCURL\n\n"+$text+"\n");
        symbolTable->print_all_scope_table2(parserLogFile);
        symbolTable->ExitScope();


    }
	| LCURL RCURL {

        $text = $LCURL->getText();
        $line = $LCURL->getLine();
        $type = "void"; 
    //    symbolTable->print_current_scope_table(parserLogFile);


    };

var_declaration
	returns[std::string text, int line]:
	t = type_specifier dl = declaration_list sm = SEMICOLON {
        $text = $t.text +" "+ $dl.text + $sm->getText() ;
        $line = $t.line;
        writeIntoparserLogFile("Line "+std::to_string($line)+": var_declaration : type_specifier declaration_list SEMICOLON\n\n"+$text+"\n");

        // writeIntoparserLogFile(
        //     std::string("Variable Declaration: type_specifier declaration_list ") +
        //     std::to_string($sm->getType()) +
        //     " at line " + std::to_string($sm->getLine())
        // );

        // writeIntoparserLogFile("type_specifier name_line: " + $t.text);

        // std::stringstream ss($dl.text);

        // std::string name;

        // while(std::getline(ss,name,',')){ 
        //     name.erase(0, name.find_first_not_of(" \t"));
        //     name.erase(name.find_last_not_of(" \t") + 1);

        //     if(!symbolTable->Insert(name,"ID")){   
        //         writeIntoparserLogFile("Error at line "+std::to_string($line)+": Multiple declaration of "+name+"\n");
        //         writeIntoErrorFile("Error at line "+std::to_string($line)+":  Multiple declaration of "+name+"\n");
        //     }
        //  }

        for(const auto& var : $dl.varList) {
            SymbolInfo* varSymbol = new SymbolInfo(var.first, "ID");
            varSymbol->setIsArray(var.second);
            std::cout<<"is array true nakke"<<varSymbol->getIsArray()<<var.second << std::endl;
            varSymbol->setSymbolDataType($t.type);
            std::cout<<"vartype ki set hocche check"<<varSymbol->getSymbolDataType() << std::endl;
            if(!symbolTable->Insert(varSymbol)){
                writeIntoparserLogFile("Error at line "+std::to_string($line)+":  Multiple declaration of "+var.first+"\n");
                writeIntoErrorFile("Error at line "+std::to_string($line)+": Multiple declaration of "+var.first+"\n");
                                errorCount++;

            }
        }

        if($t.text == "void"){
            writeIntoparserLogFile("Error at line "+std::to_string($line)+":  Variable type cannot be void\n");
                            errorCount++;

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
	returns[std::string text , int line, std::string type]:
	INT {
            $text = $INT->getText();
            $line = $INT->getLine();
            $type = "int";
			writeIntoparserLogFile("Line " + std::to_string($INT->getLine()) + ": type_specifier : INT\n\n" + $INT->getText() + "\n");
            if(multipleDeclaration){

            }
        }
	| FLOAT {
            $text = $FLOAT->getText();
            $line = $FLOAT->getLine();
            $type = "float";
			writeIntoparserLogFile("Line " + std::to_string($FLOAT->getLine()) + ": type_specifier : FLOAT\n\n" +$FLOAT->getText() + "\n");        
		}
	| VOID {
            $text = $VOID->getText();
            $line = $VOID->getLine();
            $type = "void";
            writeIntoparserLogFile("Line " + std::to_string($VOID->getLine()) + ": type_specifier : VOID\n\n" +$VOID->getText() + "\n");        
        };

declaration_list
	returns[std::string text , int line,std::string type,std::vector<std::pair<std::string, bool>> varList]
		:
	dl = declaration_list COMMA ID { 

        $text = $dl.text + $COMMA->getText() + $ID->getText();
        $line = $ID->getLine();

        $varList = $dl.varList;
		$varList.push_back(std::make_pair($ID->getText(), false));
        
        writeIntoparserLogFile("Line " + std::to_string($line) + ": declaration_list : declaration_list COMMA ID\n\n" +$text + "\n");        

    }
	| dl = declaration_list COMMA ID LTHIRD CONST_INT RTHIRD { 
        $text = $dl.text + $COMMA->getText() + $ID->getText() + $LTHIRD->getText() + $CONST_INT->getText() + $RTHIRD->getText();
        $line = $RTHIRD->getLine();
        $varList = $dl.varList;
		$varList.push_back(std::make_pair($ID->getText(), true));
        
        writeIntoparserLogFile("Line " + std::to_string($line) + ": declaration_list : declaration_list COMMA ID LTHIRD CONST_INT RTHIRD\n\n" +$text + "\n");        

    }
	| ID { 
        $text = $ID->getText();
        $line = $ID->getLine();
        $varList.push_back(std::make_pair($ID->getText(), false));
        writeIntoparserLogFile("Line " + std::to_string($line) + ": declaration_list : ID\n\n" +$text + "\n");        

    }
	| ID LTHIRD CONST_INT RTHIRD { 
        $text = $ID->getText() + $LTHIRD->getText() + $CONST_INT->getText() + $RTHIRD->getText();
        $line = $ID->getLine();

        $type = "array";
        $varList.push_back(std::make_pair($ID->getText(), true));

        
        writeIntoparserLogFile("Line " + std::to_string($line) + ": declaration_list : ID LTHIRD CONST_INT RTHIRD\n\n" +$text + "\n");        

    };

statements
	returns[std::string text , int line,std::string type]:
	s = statement {
        $text = $s.text;
        $line = $s.line;
        $type = $s.type;
                std::cout << "s  type"<<$s.type <<std::endl;

        writeIntoparserLogFile("Line " + std::to_string($line) + ": statements : statement\n\n" + $text+"\n"); 
    }
	| ss = statements s = statement {
        $text = $ss.text +"\n" + $s.text;
        $line = $s.line;
        $type = $s.type;
                std::cout << "s  type"<<$s.type <<std::endl;

        writeIntoparserLogFile("Line " + std::to_string($line) + ": statements : statements statement\n\n" +$text+"\n"); 

    };

statement
	returns[std::string text, int line,std::string type]:
	v = var_declaration {
        $text = $v.text;
        $line = $v.line;
        writeIntoparserLogFile("Line "+  std::to_string($line) +": statement : var_declaration\n\n"+$text + "\n" );
    }
	| es = expression_statement {
        $text = $es.text;
        $line = $es.line;
        writeIntoparserLogFile("Line "+  std::to_string($line) +": statement : expression_statement\n\n"+$text + "\n" );

    }
	| cs = compound_statement {
        $text = $cs.text;
        $line = $cs.line;
        $type = $cs.type;

        writeIntoparserLogFile("Line "+  std::to_string($line) +": statement : compound_statement\n\n"+$text + "\n" );

    }
	| FOR LPAREN es1 = expression_statement es2 = expression_statement e = expression RPAREN s =
		statement {
        $text = $FOR.text +  $LPAREN->getText() +  $es1.text + $es2.text + $e.text   + $RPAREN->getText() + $s.text;
        $line = $s.line;
        writeIntoparserLogFile("Line " + std::to_string($s.line) + ": statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement\n\n" + $text +"\n"); 

    }
	| IF LPAREN  
     e = expression RPAREN s = statement {

        $text = $IF->getText()+ $LPAREN->getText()+ $e.text  + $RPAREN->getText() +$s.text;
        $line = $IF->getLine();
        writeIntoparserLogFile("Line " + std::to_string($line) + ": statement : IF LPAREN expression RPAREN statement\n\n" + $text +"\n"); 

    }
	| IF LPAREN e = expression RPAREN s1 = statement ELSE s2 = statement {
        $text = $IF->getText() + $LPAREN->getText() + $e.text  + $RPAREN->getText() + $s1.text+ $ELSE->getText() +" "+  $s2.text ;
       $line = $IF->getLine();
        writeIntoparserLogFile("Line " + std::to_string($line) + ": statement : IF LPAREN expression RPAREN statement ELSE statement\n\n" + $text +"\n"); 

    }
	| WHILE LPAREN e = expression RPAREN s = statement {
        $text = $WHILE->getText() + $LPAREN->getText() + $e.text  + $RPAREN->getText() + $s.text;
        $line = $s.line;
        writeIntoparserLogFile("Line " + std::to_string($line) + ": statement : WHILE LPAREN expression RPAREN statement\n\n" + $text +"\n"); 

    }
	| PRINTLN LPAREN ID RPAREN SEMICOLON {
        $text = $PRINTLN->getText() + $LPAREN->getText() +  $ID->getText() +  $RPAREN->getText() +  $SEMICOLON->getText();
        $line = $SEMICOLON->getLine();
        writeIntoparserLogFile("Line " + std::to_string($line) + ": statement : PRINTLN LPAREN ID RPAREN SEMICOLON\n\n" + $text +"\n"); 

    }
	| RETURN e = expression SEMICOLON {
        $text = $RETURN->getText() + " " + $e.text + $SEMICOLON->getText();
        $line = $RETURN->getLine();
        
        $type = $e.type;
                std::cout << "e type"<<$e.type<<"e.text" <<$e.text <<std::endl;


        // SymbolInfo* paramSymbol = new SymbolInfo($e.text, "ID");
        // if($e.text != "0"){
        // if(!symbolTable->Insert($e.text, "ID")){ 
        //     writeIntoErrorFile("Error at line "+ std::to_string($line) +": Multiple declaration of "+$e.text+" in parameter\n");
        // }    
        // else{   
        //     std::cout << "inserted return : "<< $e.text <<std::endl;
        // }
        // }
        writeIntoparserLogFile("Line " + std::to_string($SEMICOLON->getLine()) + ": statement : RETURN expression SEMICOLON\n\n" + $RETURN->getText() +" "+ $e.text+ $SEMICOLON->getText() +"\n"); 

      }

      ;

expression_statement
	returns[std::string text, int line]:
	SEMICOLON {
        $text = $SEMICOLON->getText();
        $line = $SEMICOLON->getLine();

        writeIntoparserLogFile("Line " + std::to_string($SEMICOLON->getLine()) + ": expression_statement : SEMICOLON\n\n" + $text +"\n"); 

    }
	| e = expression SEMICOLON {
        $text = $e.text + $SEMICOLON->getText();
        $line = $SEMICOLON->getLine();
        writeIntoparserLogFile("Line " + std::to_string($SEMICOLON->getLine()) + ": expression_statement : expression SEMICOLON\n\n" + $text +"\n"); 

    };

variable
	returns[std::string text, int line,std::string type, bool isArray]:
	ID {
        $text = $ID->getText();
        $line = $ID->getLine();
        $type = "int";
        SymbolInfo* lookup = symbolTable->LookUP($ID->getText());

            if(lookup && lookup->getIsArray()){
                $type = "array";
                $isArray = true;
            }
            else if (lookup){
                $type = lookup->getSymbolDataType();

            }
            if (lookup == nullptr) {
                        writeIntoparserLogFile("Line " + std::to_string($ID->getLine()) + ": variable : ID\n"); 

                writeIntoErrorFile("Error at line " + std::to_string($line) + ": Undeclared variable " +$ID->getText() + "\n");  
                writeIntoparserLogFile("Error at line " + std::to_string($line) + ": Undeclared variable " + $ID->getText() + "\n\n" +$ID->getText()+"\n");
                                errorCount++;

            }

            else{  
            writeIntoparserLogFile("Line " + std::to_string($ID->getLine()) + ": variable : ID\n\n"+$ID->getText()+"\n"); 

            }
                std::cout << "ID type: " << $type <<"for "<< $ID->getText() << std::endl;
                // if (lookup)
                // std::cout << "DEBUG: " << lookup->getSymbolName() << " has type: " << lookup->getType() << std::endl;
                //                 std::cout << "DEBUG: " << lookup->getSymbolName() << " has type: " << lookup->getSymbolDataType() << std::endl;


        }
	| ID LTHIRD e = expression RTHIRD { 
        $text = $ID->getText() + $LTHIRD->getText() + $e.text + $RTHIRD->getText();
        $line = $RTHIRD->getLine();
        $type = $e.type;
        if ($type != "int"){  
            writeIntoErrorFile("Error at line "+std::to_string($line)+": Expression inside third brackets not an integer\n");

            writeIntoparserLogFile("Line " + std::to_string($line) + ": variable : ID LTHIRD expression RTHIRD" +"\n"); 

            writeIntoparserLogFile("Error at line "+std::to_string($line)+": Expression inside third brackets not an integer\n\n"+$text +"\n");
                            errorCount++;



        }
        else{
        writeIntoparserLogFile("Line " + std::to_string($line) + ": variable : ID LTHIRD expression RTHIRD\n\n"+$text+"\n"); 

        }

    };

expression
	returns[std::string text, int line,std::string type]:
	l = logic_expression {
            $text=$l.text;
            $line=$l.line;
            $type = $l.type;
            std::cout << "l type"<<$l.type <<std::endl;

            writeIntoparserLogFile("Line "+  std::to_string($l.line)+": expression : logic_expression\n\n" + $l.text + "\n"); 
        }
	| v = variable ASSIGNOP le = logic_expression {
            $text= $v.text + $ASSIGNOP->getText() + $le.text;
            $line=$le.line;  
            $type = $le.type;
            SymbolInfo* lookup = symbolTable->LookUP($v.text);

            if (lookup && $v.type != $type) {
            
            std::cout<<std::to_string($line)<<" v=le er bhitor type check"<<lookup->getSymbolDataType() << " " << $type << std::endl;
            writeIntoparserLogFile("Line "+  std::to_string($line)+": expression : variable ASSIGNOP logic_expression\n"); 

            if(lookup->getIsArray()){
                writeIntoErrorFile("Error at line " + std::to_string($line) + ": Type mismatch, "+$v.text+" is an array\n");
                writeIntoparserLogFile("Error at line " + std::to_string($line) + ": Type Mismatch, "+$v.text+"  is an array\n");
                                errorCount++;


            } else {

                writeIntoErrorFile("Error at line " + std::to_string($line) + ": Type Mismatch yellow\n");  

            writeIntoparserLogFile("Error at line " + std::to_string($line) + ": Type Mismatch yellow\n\n"+$text+"\n");
                            errorCount++;

             }


            }

            else{            
                writeIntoparserLogFile("Line "+  std::to_string($line)+": expression : variable ASSIGNOP logic_expression\n\n"+$text+"\n"); 
            }

            

       };

logic_expression
	returns[std::string text, int line,std::string type , bool argIsArr ]:
	r = rel_expression {
            $text = $r.text;
            $line = $r.line;
            $type = $r.type;
            $argIsArr = $r.argIsArray;
            std::cout << "r  type"<<$r.type <<std::endl;

            writeIntoparserLogFile("Line "+  std::to_string($r.line)+": logic_expression : rel_expression\n\n" + $r.text + "\n"); 

        }
	| re1 = rel_expression LOGICOP re2 = rel_expression {
            $text = $re1.text+$LOGICOP->getText() + $re2.text;
            $line = $re2.line;
            $type = $re2.type;
            $argIsArr = false;

            std::cout << "re2 type"<<$re2.type <<std::endl;
            writeIntoparserLogFile("Line "+  std::to_string($line)+": logic_expression : rel_expression LOGICOP rel_expression\n\n" + $text + "\n"); 

        };

rel_expression
	returns[std::string text, int line,std::string type, bool argIsArray]:
	s = simple_expression {
            $text = $s.text;
            $line = $s.line;
            $type = $s.type;
            $argIsArray = $s.argIsArray;
            std::cout << "s type"<<$s.type <<std::endl;
            writeIntoparserLogFile("Line "+  std::to_string($s.line)+": rel_expression : simple_expression\n\n" + $s.text + "\n"); 
            }
	| s1 = simple_expression RELOP s2 = simple_expression {
            $text = $s1.text + $RELOP->getText() + $s2.text;
            $line = $RELOP->getLine();
            $type = $s2.type;
            $argIsArray = false;
            std::cout << "s2 type"<<$s2.type <<std::endl;
            writeIntoparserLogFile("Line "+  std::to_string($line)+": rel_expression : simple_expression RELOP simple_expression\n\n" + $text + "\n"); 

        };

simple_expression
	returns[std::string text, int line,std::string type, bool argIsArray]:
	t = term {
            $text = $t.text;
            $line = $t.line;
            $type = $t.type;
            $argIsArray = $t.argIsArray;
            writeIntoparserLogFile("Line "+  std::to_string($t.line)+": simple_expression : term\n\n" + $t.text + "\n"); 
            }
	| s = simple_expression ADDOP t = term {
            $text = $s.text+$ADDOP->getText()+$t.text;
            $line = $t.line;
            $argIsArray = false;
            if ($s.type == "float" || $t.type == "float") {
                $type = "float";
            } else {
                 $type = "int";
            }
            writeIntoparserLogFile("Line "+  std::to_string($line)+": simple_expression : simple_expression ADDOP term\n\n" + $text + "\n"); 

          };

term
	returns[std::string text, int line,std::string type, bool argIsArray]:
	u = unary_expression {
         
            $text = $u.text;
            $line = $u.line;
            $type = $u.type;
           $argIsArray = $u.argIsArray; ;
            writeIntoparserLogFile("Line "+  std::to_string($u.line)+": term : unary_expression\n\n" + $u.text + "\n");
            }
	| t = term MULOP ue = unary_expression {
    $text = $t.text + $MULOP->getText() + $ue.text;
    $line = $ue.line;
    bool print = true;
    
    if ($MULOP->getText() == "%") {
        if ($t.type != "int" || $ue.type != "int") {
            writeIntoErrorFile("Error at line " + std::to_string($line) + ": Non-Integer operand on modulus operator\n");
            writeIntoparserLogFile("Line " + std::to_string($line) + ": term : term MULOP unary_expression\n");
            writeIntoparserLogFile("Error at line " + std::to_string($line) + ": Non-Integer operand on modulus operator\n\n" + $text + "\n");
                            errorCount++;
            print = false;
        }
     
        $type = "int"; 
    } else {
        if ($t.type == "float" || $ue.type == "float") {
            $type = "float";
        } else {
            $type = "int";
        }
    }
    if(print){
    writeIntoparserLogFile("Line " + std::to_string($line) + ": term : term MULOP unary_expression\n\n" + $text + "\n");
    }  

};
unary_expression
	returns[std::string text, int line,std::string type, bool argIsArray]:
	ADDOP ue = unary_expression {
            $text = $ADDOP->getText() + $ue.text;
            $line = $ADDOP->getLine();
            $type = $ue.type;
        }
	| NOT ue = unary_expression {
            $text = $NOT->getText() + $ue.text;
            $line = $ue.line;
            $type = $ue.type;
            writeIntoparserLogFile("Line "+  std::to_string($line)+": unary_expression : NOT unary_expression\n\n" + $text + "\n");

        }
	| f = factor {
            $text = $f.text;
            $line = $f.line;
            $type = $f.type;
            $argIsArray = $f.argIsArray;
            writeIntoparserLogFile("Line "+  std::to_string($f.line)+": unary_expression : factor\n\n" + $f.text + "\n"); 
            };

factor
	returns[std::string text, int line,std::string type , bool argIsArray]:
	v = variable {
        $text = $v.text;
        $line = $v.line;
        $type = $v.type;
        $argIsArray = $v.isArray;
        std::cout << "v type"<<$v.type <<std::endl;
        writeIntoparserLogFile("Line "+  std::to_string($v.line)+": factor : variable\n\n" + $v.text + "\n");
        }
	| ID LPAREN {
        argumentCount = 0;
        argumentTypes.clear();
        argumentIsArray.clear();
    } a = argument_list RPAREN {
    $text = $ID->getText() + $LPAREN->getText() + $a.text + $RPAREN->getText();
    $line = $ID->getLine();
    $type = $ID->getType();

    SymbolInfo* func = symbolTable->LookUP($ID->getText());
    
    if (func == nullptr) {
        writeIntoErrorFile("Error at line " + std::to_string($line) + ": Undefined function " + $ID->getText() + "\n");
        errorCount++;
    } 
    else if (func->getIsFunction() && func->getIsFunctionDefined()) {
        if ((int)func->parameterList.size() != argumentCount) {
            writeIntoErrorFile("Error at line " + std::to_string($line) + ": Total number of arguments mismatch with definition in function " + $ID->getText() + "\n");
            errorCount++;
        } 
        else {
            for (int i = 0; i < argumentCount; i++) {
                std::string expectedType = func->parameterList[i].first;
                std::string argType = argumentTypes[i];
                bool argIsArray = argumentIsArray[i];
                std::cout << "expectedType: " << expectedType << ", argType: " << argType << ", argIsArray: " << argIsArray << std::endl;
                if (argIsArray && expectedType == "array") {
                    std::cout<<"ekhane eshche"<<std::endl;
                    writeIntoErrorFile("Error at line " + std::to_string($line) + ": Type mismatch" + func->parameterList[i].second + " is an array\n");
                    writeIntoparserLogFile("Error at line " + std::to_string($line) + ": Type mismatch " + func->parameterList[i].second + " is an array\n");
                    errorCount++;
                } 
                else if (!argIsArray && expectedType != argType) {
                    writeIntoErrorFile("Error at line " + std::to_string($line) + ": " + std::to_string(i + 1) + "th argument mismatch in function " + $ID->getText() + "\n");
                    writeIntoparserLogFile("Error at line " + std::to_string($line) + ": " + std::to_string(i + 1) + "th argument mismatch in function " + $ID->getText() + "\n");
                    errorCount++;
                }
            }
        }
    } 
    else {
        writeIntoErrorFile("Error at line " + std::to_string($line) + ": Undefined function " + $ID->getText() + "\n");
        errorCount++;
    }

    writeIntoparserLogFile("Line " + std::to_string($line) + ": factor : ID LPAREN argument_list RPAREN\n\n" + $text + "\n");
}

	| LPAREN e = expression RPAREN { 
        $text = $LPAREN->getText() + $e.text + $RPAREN->getText();
        $line = $RPAREN->getLine();
        $type = $e.type;
        writeIntoparserLogFile("Line "+  std::to_string($line)+": factor : LPAREN expression RPAREN\n\n" + $text + "\n");

     }
	| CONST_INT {
        $text = $CONST_INT->getText();
        $line = $CONST_INT->getLine();
        $type = "int";
        std::cout << "CONST_INT type"<<$type <<std::endl;
        writeIntoparserLogFile("Line "+  std::to_string($line)+": factor : CONST_INT\n\n" + $text + "\n");

    }
	| CONST_FLOAT {
        $text = $CONST_FLOAT->getText();
        $line = $CONST_FLOAT->getLine();
        $type = "float";
        writeIntoparserLogFile("Line "+  std::to_string($line)+": factor : CONST_FLOAT\n\n" + $text + "\n");

    }
	| v = variable INCOP {
        $text = $v.text+$INCOP->getText();
        $line = $INCOP->getLine();
        $type = $v.type;
        writeIntoparserLogFile("Line "+  std::to_string($line)+": factor : variable INCOP\n\n" + $text + "\n");

    }
	| v = variable DECOP {
        $text = $v.text+$DECOP->getText();
        $line = $DECOP->getLine();
        $type = $v.type;
        writeIntoparserLogFile("Line "+  std::to_string($line)+": factor : variable DECOP\n\n" + $text + "\n");

    };

argument_list
	returns[std::string text, int line,std::string type]:
	a = arguments {   
            $text = $a.text;
            $line = $a.line;
            $type = $a.type;
            
            writeIntoparserLogFile("Line "+ std::to_string($line)+": argument_list : arguments\n\n"+$text+"\n");
          }
	|;

arguments
	returns[std::string text, int line,std::string type]:
	a = arguments COMMA le = logic_expression {    
            $text=$a.text +  $COMMA->getText()+  $le.text;
            $line=$le.line;
            $type = $le.type;
            argumentCount++;
            argumentTypes.push_back($le.type);
            argumentIsArray.push_back($le.argIsArr);
            writeIntoparserLogFile("Line "+ std::to_string($line)+": arguments : arguments COMMA logic_expression\n\n"+$text+"\n");

         }
	| le = logic_expression {

            $text=$le.text;
            $line=$le.line;
            $type = $le.type; 
            argumentCount++;  
            argumentTypes.push_back($le.type);
            argumentIsArray.push_back($le.argIsArr);
            writeIntoparserLogFile("Line "+ std::to_string($line)+": arguments : logic_expression\n\n"+$text+"\n");


        };