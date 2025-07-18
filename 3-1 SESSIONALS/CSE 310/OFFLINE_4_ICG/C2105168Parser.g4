parser grammar C2105168Parser;

options {
	tokenVocab = C2105168Lexer;
}

@parser::header {
    #include <iostream>
    #include <fstream>
    #include <string>
    #include <cstdlib>

    #include "C2105168Lexer.h"

    

    extern std::ofstream parserLogFile;
    extern std::ofstream errorFile;
	extern std::ofstream lexLogFile;
    extern std::ofstream asmfile;


    extern int syntaxErrorCount;
    extern std::string currentFunctionReturnType;
    extern int argumentCount;
    extern int paramCount;
    extern int errorCount;
    extern bool multipleDeclaration;
    extern std::vector<std::string> argumentTypes;
    extern std::vector<bool> argumentIsArray;
    extern std::vector<std::pair<std::string, std::string>> plist;
    extern std::vector<std::string>returnTypes;
    extern std::vector<std::string>fndecreturnTypes;
    extern std::vector<std::string>fndefreturnTypes;
    extern bool isDATAEmpty;
    extern int label_count; 
    extern int stack_offset_local;
    extern int stack_offset_global;
    extern std::vector<std::string> elseStatements;
    extern std::vector<std::string> exitLabels;
    extern std::vector<std::string> loopStartLabels;
    extern std::vector<std::string> loopEndLabels;
    extern std::vector<std::string> loopUpdateLabels;


    extern std::vector<std::string> whileStartLabels;
    extern std::vector<std::string> whileEndLabels;
}

@parser::members {

    #include "2105168_header_files/2105168_SymbolInfo.h"
    #include "2105168_header_files/2105168_SymbolTable.h"

    SymbolTable* symbolTable = new SymbolTable(7);

    std::string to_upper(const std::string& input) {
    std::string result = input;
    std::transform(result.begin(), result.end(), result.begin(), ::toupper);
    return result;
}

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

    void writeIntoAsmFile(const std::string &message) {
        if (!asmfile.is_open()) {
            asmfile.open("mycode.asm", std::ios::app);
            if (!asmfile) {
                std::cerr << "Error opening code.asm" << std::endl;
                return;
            }
        }
        asmfile << message << std::endl;
        asmfile.flush();
    }

    std::string Print_assembly= R"(new_line proc
    push ax
    push dx
    mov ah,2
    mov dl,0Dh
    int 21h
    mov ah,2
    mov dl,0Ah
    int 21h
    pop dx
    pop ax
    ret
    new_line endp
print_output proc  ;print what is in ax
    push ax
    push bx
    push cx
    push dx
    push si
    lea si,number
    mov bx,10
    add si,4
    cmp ax,0
    jnge negate
    print:
    xor dx,dx
    div bx
    mov [si],dl
    add [si],'0'
    dec si
    cmp ax,0
    jne print
    inc si
    lea dx,si
    mov ah,9
    int 21h
    pop si
    pop dx
    pop cx
    pop bx
    pop ax
    ret
    negate:
    push ax
    mov ah,2
    mov dl,'-'
    int 21h
    pop ax
    neg ax
    jmp print
    print_output endp)";


    
}

start
	returns[std::string text, int line, std::string asm_header,std::string data_section , std::string code_section , std::string asm_footer]:
	{ writeIntoAsmFile(".MODEL SMALL\n.STACK 1000H\n.Data\n\tnumber DB \"00000$\"");} p = program {

        $text = $p.text;
        $line = $p.line;
        $data_section = $p.data_section_code;
        $code_section = ($p.code_section);
        std::cout << "DEBUG: start code_section = '" << $code_section << "'" << std::endl;
       // writeIntoparserLogFile("Parsing completed successfully with " + std::to_string(syntaxErrorCount) + " syntax errors.");


        writeIntoparserLogFile("Line "+std::to_string($line)+": start : program\n");
        symbolTable->print_current_scope_table(parserLogFile);


        writeIntoparserLogFile("\nTotal number of lines: "+std::to_string($line));
        writeIntoparserLogFile("Total number of errors: "+std::to_string(errorCount));

        writeIntoAsmFile(Print_assembly);
        writeIntoAsmFile("END main");
        std::cout << "here" <<std::endl;


        std::cout << $code_section <<std::endl;
	};

program
	returns[std::string text, int line,std::string data_section_code,std::string code_section]:
	pu = program u = unit {  
        $text = $pu.text +"\n"+$u.text;
        $line = $u.line;
        $data_section_code = $pu.data_section_code +$u.data_section_code;
        $code_section = $pu.code_section + $u.code_section;
        writeIntoparserLogFile("Line "+std::to_string($line)+": program : program unit\n\n"+$text+"\n");
        }
	| u = unit { 
        $text = $u.text;
        $line = $u.line;
        writeIntoparserLogFile("Line "+std::to_string($line)+": program : unit\n\n"+$text+"\n");

         };

unit
	returns[std::string text, int line,std::string data_section_code,std::string code_section]:
	vd = var_declaration {  
        $text = $vd.text;
        $line = $vd.line;


        std::cout << "DEBUG: unit var_declaration code_section = '" << $code_section << "'" << std::endl;
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
	returns[std::string text, int line ,std::string type , std::string code_section]:
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
        funcSymbol->setIsDeclared(true);
        plist = $pl.plist;  

        fndecreturnTypes.push_back($ts.text);


        SymbolInfo* existing = symbolTable->LookUP($ID->getText());
        if (existing && existing->getIsFunction() && existing->getIsFunctionDefined()) {
            // writeIntoparserLogFile("Error at line " + std::to_string($line) + ": Multiple definition of function " + $ID->getText());
        } else {
            if(symbolTable->Insert(funcSymbol)){ 
               // std::cout << funcSymbol->getSymbolName() << $ID->getText() << std::endl;

              //  writeIntoErrorFile("Error at line "+std::to_string($line)+": Multiple declaration of "+$ID->getText()+"\n");

            }


        }



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
        funcSymbol->setIsDeclared(true);



        SymbolInfo* existing = symbolTable->LookUP($ID->getText());
        if (existing && existing->getIsFunction() && existing->getIsFunctionDefined()) {
            writeIntoparserLogFile("Error at line " + std::to_string($line) + ": Redeclaration of function " + $ID->getText());
        } else {
            if(symbolTable->Insert(funcSymbol)){ 
                   // std::cout << funcSymbol->getSymbolName() << $ID->getText() << std::endl;
                         //       writeIntoErrorFile("Error at line "+std::to_string($line)+":  Multiple declaration of "+$ID->getText()+"\n");

            }        }

     

        writeIntoparserLogFile("Line "+std::to_string($line)+": func_declaration : type_specifier ID LPAREN RPAREN SEMICOLON\n\n"+$text+"\n");

        
    };

func_definition
	returns[std::string text, int line,std::string type,std::string returnType , std::string code_section]:
	ts = type_specifier ID LPAREN {    std::cout << "DEBUG: About to parse parameter_list" << std::endl;} pl = parameter_list {
            std::cout << "DEBUG: Successfully parsed parameter_list, pl.text = '" << $pl.text << "'" << std::endl;
        SymbolInfo* funcSymbol = new SymbolInfo($ID->getText(), "ID");
        funcSymbol->setIsFunction(true);
        funcSymbol->setIsFunctionDefined(true);
        funcSymbol->setReturnType($ts.text);


        funcSymbol->setParameterList($pl.plist);
        plist = $pl.plist;
        fndefreturnTypes.push_back($ts.text);

        SymbolInfo* existing = symbolTable->LookUP($ID->getText());

        if (existing && existing->getIsFunction() && existing->getIsFunctionDefined()) {
           // writeIntoparserLogFile("Error at line " + std::to_string($line) + ": Multiple definition of function " + $ID->getText());
        } else {
            symbolTable->Insert(funcSymbol);
        }


        SymbolInfo* lookup = symbolTable->LookUP($ID->getText());       
        if($ts.text != lookup->getReturnType() ){

        writeIntoparserLogFile("Error at line "+std::to_string($ts.line)+": Return type mismatch of "+lookup->getSymbolName()+"\n");
        writeIntoErrorFile("Error at line "+std::to_string($ts.line)+": Return type mismatch of "+lookup->getSymbolName()+"\n");

                errorCount++;
        }


     } RPAREN {    
        writeIntoAsmFile($ID->getText() + " PROC");
        writeIntoAsmFile("\tMOV AX, @DATA\n\tMOV DS, AX\n\tPUSH BP\n\tMOV BP, SP");

    } cs = compound_statement {  


        $text = $ts.text+" "  + $ID->getText() +  $LPAREN->getText()+ $pl.text + $RPAREN->getText() + $cs.text;
        $line = $cs.line;
        $type = $ts.text;
        $returnType = $cs.type;

        if ($ts.text == "void" && $returnType != "void") {
            writeIntoErrorFile("Error at line " + std::to_string($line) + ": Cannot return value from function "+  $ID->getText() + " with void return type\n");
             writeIntoparserLogFile("Error at line " + std::to_string($line) + ": Cannot return value from function "+  $ID->getText() + " with void return type\n");
            errorCount++;
        } 

        writeIntoAsmFile("\tMOV AX, 4CH\n\tINT 21H");
        writeIntoAsmFile($ID->getText()+ " ENDP");
        
        writeIntoparserLogFile("\nLine "+std::to_string($line)+": func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement\n\n"+$text+"\n");
 

    }
	| ts = type_specifier ID LPAREN RPAREN {    
        writeIntoAsmFile($ID->getText() + " PROC");
         writeIntoAsmFile("\tMOV AX, @DATA\n\tMOV DS, AX\n\tPUSH BP\n\tMOV BP, SP");

    } { 

        SymbolInfo* funcSymbol = new SymbolInfo($ID->getText(), "ID");
        funcSymbol->setIsFunction(true);
        funcSymbol->setReturnType($ts.text);

        SymbolInfo* existing = symbolTable->LookUP($ID->getText());
        if (existing && existing->getIsFunction() && existing->getIsFunctionDefined()) {
           // writeIntoparserLogFile("Error at line " + std::to_string($line) + ": Multiple definition of function " + $ID->getText());
        } else {
            symbolTable->Insert(funcSymbol);
            funcSymbol->setIsFunctionDefined(true);

        }

        } cs = compound_statement { 

        $text = $ts.text +" " + $ID->getText() +  $LPAREN->getText() + $RPAREN->getText() + $cs.text;
        $line = $cs.line;
        std::cout << "DEBUG: func_declaration code_section = '" << $code_section << "'" << std::endl;

        writeIntoAsmFile("\tMOV AX, 4CH\n\tINT 21H");

        writeIntoAsmFile($ID->getText()+ " ENDP");

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
    | pl = parameter_list COMMA ADDOP {
        $text = $pl.text;
        $line = $ADDOP->getLine();
        writeIntoparserLogFile("Error at line " + std::to_string($line) + 
            ": syntax error, unexpected ADDOP, expecting type_specifier\n");
        writeIntoErrorFile("Error at line " + std::to_string($line) + 
            ": syntax error, unexpected ADDOP, expecting type_specifier\n");
    }
	| ts = type_specifier ID {
        $text = $ts.text + " " + $ID->getText()   ;
        $line = $ID->getLine();
        $plist.push_back(std::make_pair($ts.text, $ID->getText()));

        SymbolInfo* paramSymbol = new SymbolInfo($ID->getText(), "ID");
        paramSymbol->setIsArray(false);
        paramSymbol->setType($ts.text);

        writeIntoparserLogFile("Line " + std::to_string($line) +": parameter_list : type_specifier ID\n\n" + $text + "\n");
		}
        | ts = type_specifier ADDOP {
        $text = $ts.text;
        $line = $ADDOP->getLine();
        writeIntoErrorFile("Error at line " + std::to_string($line) + ": syntax error, unexpected ADDOP, expecting RPAREN or COMMA\n");
        writeIntoparserLogFile("Error at line " + std::to_string($line) + ": syntax error, unexpected ADDOP, expecting RPAREN or COMMA\n");
        }
         |ts = type_specifier {

        $text = $ts.text ;
        $line = $ts.line;
            std::cout << "DEBUG: ts.text = '" << $ts.text << "'" << std::endl;
    std::cout << "DEBUG: ts.line = " << $ts.line << std::endl;
        $plist.push_back(std::make_pair($ts.text, ""));
        writeIntoparserLogFile("Line " + std::to_string($line) + ": parameter_list : type_specifier \n" +$ts.text+ "\n");
		}
        | ADDOP {
        $line = $ADDOP->getLine();
        writeIntoErrorFile("Error at line " + std::to_string($line) + ": syntax error, unexpected ADDOP, expecting RPAREN or COMMA\n");
        writeIntoparserLogFile("Error at line " + std::to_string($line) + ": syntax error, unexpected ADDOP, expecting RPAREN or COMMA\n");
        }
    
   ;

compound_statement
	returns[std::string text, int line , std::string type , std::string code_section]:
	LCURL { symbolTable->EnterScope();  

        for(const auto& param : plist) {

            $line = $LCURL->getLine();
            SymbolInfo* paramSymbol = new SymbolInfo(param.second, "ID");
            paramSymbol->setIsArray(false);
            paramSymbol->setSymbolDataType(param.first);
            if(!symbolTable->Insert(param.second, "ID")){
                writeIntoparserLogFile("Error at line " + std::to_string($line) + ": Multiple declaration of " + param.second + " in parameter\n");
                writeIntoErrorFile("Error at line " + std::to_string($line) + ": Multiple declaration of " + param.second + " in parameter\n");

                errorCount++;
            }
        }
        plist.clear();
        
         } ss = statements { 
        // std::cout << "ss  type"<<$ss.type <<std::endl;
        $type = $ss.type;
    } RCURL {
        $text = $LCURL->getText()+"\n" + $ss.text +"\n" + $RCURL->getText();
        $line = $RCURL.line;
        $code_section = $ss.code_section;
        writeIntoparserLogFile("Line "+std::to_string($line)+": compound_statement : LCURL statements RCURL\n\n"+$text+"\n");
        symbolTable->print_all_scope_table2(parserLogFile);
        symbolTable->ExitScope();


    }
	| LCURL {symbolTable->EnterScope();} RCURL {

        $text = $LCURL->getText()+$RCURL->getText();
        $line = $RCURL->getLine();
        $type = "void"; 
        writeIntoparserLogFile("Line "+std::to_string($line)+": compound_statement : LCURL RCURL\n\n"+$text+"\n");

        symbolTable->print_all_scope_table2(parserLogFile);
        symbolTable->ExitScope();

    };

var_declaration
	returns[std::string text, int line , std::string data_section_code,std::string code_section]:
	t = type_specifier dl = declaration_list sm = SEMICOLON {
        $text = $t.text +" "+ $dl.text + $sm->getText() ;
        $line = $t.line;
        $data_section_code = "";
        $code_section = "";
        bool pushbpprint = false;
        writeIntoparserLogFile("Line "+std::to_string($line)+": var_declaration : type_specifier declaration_list SEMICOLON\n\n"+$text+"\n");


        for(const auto& var : $dl.varList) {
            SymbolInfo* varSymbol = new SymbolInfo(var.first, "ID");
            varSymbol->setIsArray(var.second);
            varSymbol->setSymbolDataType($t.type);
            if(!symbolTable->Insert(varSymbol)){
                writeIntoparserLogFile("Error at line "+std::to_string($line)+":  Multiple declaration of "+var.first+"\n");
                writeIntoErrorFile("Error at line "+std::to_string($line)+": Multiple declaration of "+var.first+"\n");
                                errorCount++;
            }


            std::string currentScopeId = symbolTable->getCurrentScopeID();

            if(currentScopeId == "1"){

                isDATAEmpty = false;
                
                stack_offset_global += 2;
                varSymbol->setStackOffset(stack_offset_global);
                varSymbol->setIsGlobal(true);
                $data_section_code+="\t"+varSymbol->getSymbolName()+" DW 1 DUP (0000H)\n";

                std::cout << "data_section_code: " << $data_section_code << std::endl;
            }


            else if(currentScopeId !="1" ){
                if(!pushbpprint){
                    pushbpprint = true;
                }
                stack_offset_local += 2;
                varSymbol->setStackOffset(stack_offset_local);
                $code_section += "\tSUB SP, 2\n";

            }

        }
                    std::string currentScopeId = symbolTable->getCurrentScopeID();

        if(currentScopeId == "1"){
                writeIntoAsmFile($data_section_code+".CODE");
        }
         writeIntoAsmFile($code_section);




        if($t.text == "void"){
            writeIntoparserLogFile("Error at line "+std::to_string($line)+":  Variable type cannot be void\n");
            writeIntoErrorFile("Error at line "+std::to_string($line)+": Variable type cannot be void\n");
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
    | dl = declaration_list COMMA ID ADDOP {
        $text = $dl.text + $COMMA->getText() + $ID->getText();
        $line = $ADDOP->getLine();
        $varList = $dl.varList;
        $varList.push_back(std::make_pair($ID->getText(), false));
                std::cout<<"help"<<std::endl;

        writeIntoparserLogFile("Line " + std::to_string($line) + ": declaration_list : declaration_list COMMA ID\n\n" +$dl.text + "\n");        

        writeIntoErrorFile("Error at line " + std::to_string($line) + ": syntax error, unexpected ADDOP, expecting COMMA or SEMICOLON\n");
        writeIntoparserLogFile("Error at line " + std::to_string($line) + ": syntax error, unexpected ADDOP, expecting COMMA or SEMICOLON\n");
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

    }
        | ID ADDOP declaration_list {
        $text = $ID->getText() + "," + $declaration_list.text;
        $line = $ADDOP->getLine();
        $varList.push_back(std::make_pair($ID->getText(), false));
        for(auto var : $declaration_list.varList) {
            $varList.push_back(var);
        }
        writeIntoparserLogFile("Line " + std::to_string($line) + ": declaration_list : ID\n\n" + $ID->getText() + "\n");
        writeIntoErrorFile("Error at line " + std::to_string($line) + ": syntax error, unexpected ADDOP, expecting COMMA or SEMICOLON\n");
        writeIntoparserLogFile("Error at line " + std::to_string($line) + ": syntax error, unexpected ADDOP, expecting COMMA or SEMICOLON\n");
        writeIntoparserLogFile("Line " + std::to_string($declaration_list.line) + ": declaration_list : declaration_list COMMA ID\n\n" + $text + "\n");
        };

statements
	returns[std::string text , int line,std::string type, std::string code_section]:
	s = statement {
        $text = $s.text;
        $line = $s.line;
        $type = $s.type;
        $code_section = $s.code_section;
                // std::cout << "s  type"<<$s.type <<std::endl;

        writeIntoparserLogFile("Line " + std::to_string($line) + ": statements : statement\n\n" + $text+"\n"); 
    }
	| ss = statements s = statement {
        $text = $ss.text +"\n" + $s.text;
        $line = $s.line;
        $type = $s.type;
        $code_section = $ss.code_section +  $s.code_section;  
                // std::cout << "s  type"<<$s.type <<std::endl;

        writeIntoparserLogFile("Line " + std::to_string($line) + ": statements : statements statement\n\n" +$text+"\n"); 

    };

statement
	returns[std::string text, int line,std::string type, std::string code_section]:
	v = var_declaration {
        $text = $v.text;
        $line = $v.line;
        std::cout << "DEBUG: unit var_declaration code_section = '" << $code_section << "'" << std::endl;
        $type = "void";
        writeIntoparserLogFile("Line "+  std::to_string($line) +": statement : var_declaration\n\n"+$text + "\n" );
    }
	| es = expression_statement {
        $text = $es.text;
        $line = $es.line;
        $type = "void";
        writeIntoparserLogFile("Line "+  std::to_string($line) +": statement : expression_statement\n\n"+$text + "\n" );

    }
	| cs = compound_statement {
        $text = $cs.text;
        $line = $cs.line;
        $type = $cs.type;
        $type = "void";

        writeIntoparserLogFile("Line "+  std::to_string($line) +": statement : compound_statement\n\n"+$text + "\n" );

    }
	| FOR LPAREN es1 = expression_statement {

    std::string loopStartLabel = std::to_string(label_count++);
    std::string loopEndLabel = std::to_string(label_count++);
    std::string loopUpdateLabel = std::to_string(label_count++);
    
    loopStartLabels.push_back(loopStartLabel);
    loopEndLabels.push_back(loopEndLabel);
    loopUpdateLabels.push_back(loopUpdateLabel);
    
    writeIntoAsmFile("L" + loopStartLabel + ":");
    
} es2 = expression_statement {
    writeIntoAsmFile("\tPOP AX");
    writeIntoAsmFile("\tCMP AX, 0");
    writeIntoAsmFile("\tJE L" + loopEndLabels.back());
    
    std::string bodyLabel = std::to_string(label_count++);
    writeIntoAsmFile("\tJMP L" + bodyLabel);
    
    writeIntoAsmFile("L" + loopUpdateLabels.back() + ":");
    
} e = expression {
    if ($e.text != "") {
        writeIntoAsmFile("\tPOP AX"); 
    }
    
    writeIntoAsmFile("\tJMP L" + loopStartLabels.back());
    
    writeIntoAsmFile("L" + bodyLabel + ":");
    
} RPAREN s = statement {
    
    writeIntoAsmFile("\tJMP L" + loopUpdateLabels.back());
    
    writeIntoAsmFile("L" + loopEndLabels.back() + ":");
        loopStartLabels.pop_back();
    loopEndLabels.pop_back();
    loopUpdateLabels.pop_back();
    
    $text = $FOR.text + $LPAREN->getText() + $es1.text + $es2.text + $e.text + $RPAREN->getText() + $s.text;
    $line = $s.line;
    $type = "void";
    
    writeIntoparserLogFile("Line " + std::to_string($s.line) + ": statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement\n\n" + $text +"\n");
}
	| IF LPAREN e = expression {    
        std::string elseLabel = std::to_string(label_count++);
        elseStatements.push_back(elseLabel);

        writeIntoAsmFile("\tPOP AX\n");
        writeIntoAsmFile("\tCMP AX, 0\n");
        writeIntoAsmFile("\tJE L" + elseLabel);


        } RPAREN s = statement {

        $text = $IF->getText()+ $LPAREN->getText()+ $e.text  + $RPAREN->getText() +$s.text;
        $line = $IF->getLine();
        $type = "void";

        std::string exitLabel = std::to_string(label_count++);

        exitLabels.push_back(exitLabel);

        writeIntoAsmFile("\tJMP L" + exitLabel);
        writeIntoAsmFile("L" +elseStatements.back() + ":");
        elseStatements.pop_back();
        writeIntoAsmFile("\tJMP L" + exitLabel);
        writeIntoAsmFile("L" + exitLabel + ":");


        writeIntoparserLogFile("Line " + std::to_string($line) + ": statement : IF LPAREN expression RPAREN statement\n\n" + $text +"\n"); 

    }
	| IF LPAREN e = expression {

        std::string elseLabel = std::to_string(label_count++);
        elseStatements.push_back(elseLabel);

        writeIntoAsmFile("\tPOP AX\n");
        writeIntoAsmFile("\tCMP AX, 0\n");
        writeIntoAsmFile("\tJE L" + elseLabel);



    }
    RPAREN s1 = statement {  

        std::string exitLabel = std::to_string(label_count++);

        exitLabels.push_back(exitLabel);

        writeIntoAsmFile("\tJMP L" + exitLabel);
        writeIntoAsmFile("L" + elseStatements.back() + ":");
        elseStatements.pop_back();
        // writeIntoAsmFile("\tJMP L" + exitLabel);

     } ELSE s2 = statement {

        $text = $IF->getText() + $LPAREN->getText() + $e.text  + $RPAREN->getText() + $s1.text+ $ELSE->getText() +" "+  $s2.text ;
       $line = $IF->getLine();
        $type = "void";

        writeIntoAsmFile("L" + exitLabels.back() + ":");
        exitLabels.pop_back();


        writeIntoparserLogFile("Line " + std::to_string($line) + ": statement : IF LPAREN expression RPAREN statement ELSE statement\n\n" + $text +"\n"); 

    }
	|WHILE {
    std::string loopStartLabel = std::to_string(label_count++);
    std::string loopEndLabel = std::to_string(label_count++);
    loopStartLabels.push_back(loopStartLabel);
    loopEndLabels.push_back(loopEndLabel);
    writeIntoAsmFile("L" + loopStartLabel + ":");
} LPAREN e = expression {
    writeIntoAsmFile("\tPOP AX");
    writeIntoAsmFile("\tCMP AX, 0");
    writeIntoAsmFile("\tJE L" + loopEndLabels.back());
} RPAREN s = statement {
    writeIntoAsmFile("\tJMP L" + loopStartLabels.back());
    writeIntoAsmFile("L" + loopEndLabels.back() + ":");
    loopStartLabels.pop_back();
    loopEndLabels.pop_back();
    
    $text = $WHILE->getText() + $LPAREN->getText() + $e.text + $RPAREN->getText() + $s.text;
    $line = $s.line;
    $type = "void";
    writeIntoparserLogFile("Line " + std::to_string($line) + ": statement : WHILE LPAREN expression RPAREN statement\n\n" + $text +"\n");
}
	| PRINTLN LPAREN ID RPAREN SEMICOLON {

        $text = $PRINTLN->getText() + $LPAREN->getText() +  $ID->getText() +  $RPAREN->getText() +  $SEMICOLON->getText();
        $line = $SEMICOLON->getLine();

        $type = "void";

        SymbolInfo* lookup = symbolTable->LookUP($ID->getText());
        SymbolInfo* existing = symbolTable->LookUP($ID->getText());
            std::string currentScopeId = symbolTable->getCurrentScopeID();
            if(existing->getIsGlobal()){
                $code_section = "\tMOV AX, "+ $ID->getText();
            } else {
                $code_section = "\tMOV AX, [BP-" + std::to_string(existing->getStackOffset()) + "]";
            }

        writeIntoAsmFile("L" + std::to_string(label_count++)+":");
        writeIntoAsmFile($code_section+"       ; Line "+std::to_string($line));
        writeIntoAsmFile("\tCALL print_output");
        writeIntoAsmFile("\tCALL new_line");

        writeIntoparserLogFile("Line " + std::to_string($line) + ": statement : PRINTLN LPAREN ID RPAREN SEMICOLON\n"); 
        if(lookup == nullptr){
                writeIntoErrorFile("Error at line " + std::to_string($line) + ": Undeclared variable " +$ID->getText() + "\n");  
                writeIntoparserLogFile("Error at line " + std::to_string($line) + ": Undeclared variable " + $ID->getText() + "\n\n" +$text+"\n");
                                errorCount++;
        }

    }
	| RETURN e = expression SEMICOLON {
        $text = $RETURN->getText() + " " + $e.text + $SEMICOLON->getText();
        $line = $RETURN->getLine();
        
        $type = $e.type;




        SymbolInfo* lookup = symbolTable->LookUP($e.text);


        writeIntoparserLogFile("Line " + std::to_string($SEMICOLON->getLine()) + ": statement : RETURN expression SEMICOLON\n\n" + $RETURN->getText() +" "+ $e.text+ $SEMICOLON->getText() +"\n"); 

      };

expression_statement
	returns[std::string text, int line , std::string code_section]:
	SEMICOLON {
        $text = $SEMICOLON->getText();
        $line = $SEMICOLON->getLine();
        writeIntoparserLogFile("Line " + std::to_string($SEMICOLON->getLine()) + ": expression_statement : SEMICOLON\n\n" + $text +"\n"); 

    }
	| e = expression SEMICOLON {
        $text = $e.text + $SEMICOLON->getText();
        $line = $SEMICOLON->getLine();
        $code_section = $e.code_section;
        writeIntoparserLogFile("Line " + std::to_string($SEMICOLON->getLine()) + ": expression_statement : expression SEMICOLON\n\n" + $text +"\n"); 

    };

variable
	returns[std::string text, int line,std::string type, bool isArray, std::string code_section]:
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
                // std::cout << "ID type: " << $type <<"for "<< $ID->getText() << std::endl;
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
	returns[std::string text, int line,std::string type,bool argIsArray , std::string code_section]:
	l = logic_expression {
            $text=$l.text;
            $line=$l.line;
            $type = $l.type;
               $argIsArray = false;
            $code_section = $l.code_section;
            // std::cout << "l type"<<$l.type <<std::endl;

            writeIntoparserLogFile("Line "+  std::to_string($l.line)+": expression : logic_expression\n\n" + $l.text + "\n"); 
        }
	| v = variable ASSIGNOP le = logic_expression {
            $text= $v.text + $ASSIGNOP->getText() + $le.text;
            $line=$le.line;  
            $type = $le.type;
            $argIsArray = false;

            SymbolInfo* existing = symbolTable->LookUP($v.text);
            std::string currentScopeId = symbolTable->getCurrentScopeID();
            if(existing->getIsGlobal()){
                $code_section = "\tMOV " + $v.text + ", AX";
            } else {
                $code_section = "\tMOV [BP-" + std::to_string(existing->getStackOffset()) + "], AX";
            }

                        writeIntoAsmFile("\tPOP AX");

            writeIntoAsmFile($code_section);


            
            std::cout << "DEBUG: expression code_section = '" << $code_section << "'" << std::endl;
            SymbolInfo* lookup = symbolTable->LookUP($v.text);



            if (lookup && $v.type != $type) {
            
            writeIntoparserLogFile("Line "+  std::to_string($line)+": expression : variable ASSIGNOP logic_expression\n"); 

            if(lookup->getIsArray()){
                writeIntoErrorFile("Error at line " + std::to_string($line) + ": Type mismatch, "+$v.text+" is an array\n");
                writeIntoparserLogFile("Error at line " + std::to_string($line) + ": Type Mismatch, "+$v.text+"  is an array\n");
                                errorCount++;


            } else {

                writeIntoErrorFile("Error at line " + std::to_string($line) + ": Type Mismatch\n");  

            writeIntoparserLogFile("Error at line " + std::to_string($line) + ": Type Mismatch\n\n"+$text+"\n");
                            errorCount++;

             }


            }

            else{            
                writeIntoparserLogFile("Line "+  std::to_string($line)+": expression : variable ASSIGNOP logic_expression\n\n"+$text+"\n"); 
            }

            

       };

logic_expression
	returns[std::string text, int line,std::string type , bool argIsArr , std::string code_section]:
	r = rel_expression {
            $text = $r.text;
            $line = $r.line;
            $type = $r.type;
            $argIsArr = $r.argIsArray;
            // std::cout << "r  type"<<$r.type <<std::endl;

            writeIntoparserLogFile("Line "+  std::to_string($r.line)+": logic_expression : rel_expression\n\n" + $r.text + "\n"); 

        }
	| re1 = rel_expression LOGICOP re2 = rel_expression {
            $text = $re1.text+$LOGICOP->getText() + $re2.text;
            $line = $re2.line;
            $type = $re2.type;
            $argIsArr = false;
            int labelEnd = 0;

         writeIntoAsmFile("\tPOP DX");  
          writeIntoAsmFile("\tPOP AX");  
    
    if ($LOGICOP->getText() == "&&") {
        int labelFalse = label_count++;
        labelEnd = label_count++;
        
        writeIntoAsmFile("\tCMP AX, 0\n\tJE L" + std::to_string(labelFalse));  
        writeIntoAsmFile("\tCMP DX, 0\n\tJE L" + std::to_string(labelFalse));  
        
        writeIntoAsmFile("\tMOV AX, 1\n\tJMP L" + std::to_string(labelEnd));
        
        writeIntoAsmFile("L" + std::to_string(labelFalse) + ":");
        writeIntoAsmFile("\tMOV AX, 0");
        
    } else if ($LOGICOP->getText() == "||") {
        int labelTrue = label_count++;
        labelEnd = label_count++;
        
        writeIntoAsmFile("\tCMP AX, 0\n\tJNE L" + std::to_string(labelTrue));  
        writeIntoAsmFile("\tCMP DX, 0\n\tJNE L" + std::to_string(labelTrue));  
        
        writeIntoAsmFile("\tMOV AX, 0\n\tJMP L" + std::to_string(labelEnd));
        
        writeIntoAsmFile("L" + std::to_string(labelTrue) + ":");
        writeIntoAsmFile("\tMOV AX, 1");
    }

    writeIntoAsmFile("L" + std::to_string(labelEnd) + ":");
    writeIntoAsmFile("\n\tPUSH AX");
            writeIntoparserLogFile("Line "+  std::to_string($line)+": logic_expression : rel_expression LOGICOP rel_expression\n\n" + $text + "\n"); 

        };

rel_expression
	returns[std::string text, int line,std::string type, bool argIsArray, std::string code_section]:
	s = simple_expression {
            $text = $s.text;
            $line = $s.line;
            $type = $s.type;
            $argIsArray = $s.argIsArray;
            // std::cout << "s type"<<$s.type <<std::endl;
            writeIntoparserLogFile("Line "+  std::to_string($s.line)+": rel_expression : simple_expression\n\n" + $s.text + "\n"); 
            }
	| s1 = simple_expression RELOP s2 = simple_expression {
            $text = $s1.text + $RELOP->getText() + $s2.text;
            $line = $RELOP->getLine();
            $type = $s2.type;
            $argIsArray = false;
            int labelEnd = 0;

            writeIntoAsmFile("\tPOP DX");
            writeIntoAsmFile("\tPOP AX");
            if ($RELOP->getText() == "==") {
                int labelTrue = label_count++;
                int labelFalse = label_count++;
                labelEnd = label_count++;
                writeIntoAsmFile("\tCMP AX, DX\n\tJE L" + std::to_string(labelTrue));
                writeIntoAsmFile("\tJMP L" + std::to_string(labelFalse));
                writeIntoAsmFile("L" + std::to_string(labelTrue) + ":");
                writeIntoAsmFile("\tMOV AX, 1\n\tJMP L" + std::to_string(labelEnd));
                writeIntoAsmFile("L" + std::to_string(labelFalse) + ":");
                writeIntoAsmFile("\tMOV AX, 0");

            } else if ($RELOP->getText() == "!=") {
                int labelTrue = label_count++;
                int labelFalse = label_count++;
                labelEnd = label_count++;
                writeIntoAsmFile("\tCMP AX, DX\n\tJNE L" + std::to_string(labelTrue));
                writeIntoAsmFile("\tJMP L" + std::to_string(labelFalse));
                writeIntoAsmFile("L" + std::to_string(labelTrue) + ":");
                writeIntoAsmFile("\tMOV AX, 1\n\tJMP L" + std::to_string(labelEnd));
                writeIntoAsmFile("L" + std::to_string(labelFalse) + ":");
                writeIntoAsmFile("\tMOV AX, 0");
              } else if ($RELOP->getText() == "<") {
                int labelTrue = label_count++;
                int labelFalse = label_count++;
                labelEnd = label_count++;
                writeIntoAsmFile("\tCMP AX, DX\n\tJL L" + std::to_string(labelTrue));
                writeIntoAsmFile("\tJMP L" + std::to_string(labelFalse));
                writeIntoAsmFile("L" + std::to_string(labelTrue) + ":");
                writeIntoAsmFile("\tMOV AX, 1\n\tJMP L" + std::to_string(labelEnd));
                writeIntoAsmFile("L" + std::to_string(labelFalse) + ":");
                writeIntoAsmFile("\tMOV AX, 0");
            } else if ($RELOP->getText() == ">") {
                int labelTrue = label_count++;
                int labelFalse = label_count++;
                labelEnd = label_count++;
                writeIntoAsmFile("\tCMP AX, DX\n\tJG L" + std::to_string(labelTrue));
                writeIntoAsmFile("\tJMP L" + std::to_string(labelFalse));
                writeIntoAsmFile("L" + std::to_string(labelTrue) + ":");
                writeIntoAsmFile("\tMOV AX, 1\n\tJMP L" + std::to_string(labelEnd));
                writeIntoAsmFile("L" + std::to_string(labelFalse) + ":");
                writeIntoAsmFile("\tMOV AX, 0");
            } else if ($RELOP->getText() == "<=") {
                int labelTrue = label_count++;
                int labelFalse = label_count++;
                labelEnd = label_count++;
                writeIntoAsmFile("\tCMP AX, DX\n\tJLE L" + std::to_string(labelTrue));
                writeIntoAsmFile("\tJMP L" + std::to_string(labelFalse));
                writeIntoAsmFile("L" + std::to_string(labelTrue) + ":");
                writeIntoAsmFile("\tMOV AX, 1\n\tJMP L" + std::to_string(labelEnd));
                writeIntoAsmFile("L" + std::to_string(labelFalse) + ":");
                writeIntoAsmFile("\tMOV AX, 0");

            } 
            else if ($RELOP->getText() == ">=") {
                int labelTrue = label_count++;
                int labelFalse = label_count++;
                labelEnd = label_count++;
                writeIntoAsmFile("\tCMP AX, DX\n\tJGE L" + std::to_string(labelTrue));
                writeIntoAsmFile("\tJMP L" + std::to_string(labelFalse));
                writeIntoAsmFile("L" + std::to_string(labelTrue) + ":");
                writeIntoAsmFile("\tMOV AX, 1\n\tJMP L" + std::to_string(labelEnd));
                writeIntoAsmFile("L" + std::to_string(labelFalse) + ":");
                writeIntoAsmFile("\tMOV AX, 0");
            }

            writeIntoAsmFile("L" + std::to_string(labelEnd) + ":");
            writeIntoAsmFile("\n\tPUSH AX");

            // std::cout << "s2 type"<<$s2.type <<std::endl;
            writeIntoparserLogFile("Line "+  std::to_string($line)+": rel_expression : simple_expression RELOP simple_expression\n\n" + $text + "\n"); 

        };

simple_expression
	returns[std::string text, int line,std::string type, bool argIsArray, std::string code_section]:
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

            writeIntoAsmFile("\tPOP DX");
            writeIntoAsmFile("\tPOP AX");

            if ($ADDOP->getText() == "+") {

                $code_section = "\tADD AX, DX\n\tPUSH AX"    ;
            } else if ($ADDOP->getText() == "-") {
                $code_section = "\tSUB AX, DX\n\tPUSH AX\n";
            }

            writeIntoAsmFile($code_section);
            writeIntoparserLogFile("Line "+  std::to_string($line)+": simple_expression : simple_expression ADDOP term\n\n" + $text + "\n"); 

          };

term
	returns[std::string text, int line,std::string type, bool argIsArray, std::string code_section]:
	u = unary_expression {
         
            $text = $u.text;
            $line = $u.line;
            $type = $u.type;
           $argIsArray = $u.argIsArray; 
            writeIntoparserLogFile("Line "+  std::to_string($u.line)+": term : unary_expression\n\n" + $u.text + "\n");
            }
	| t = term MULOP ue = unary_expression {
    $text = $t.text + $MULOP->getText() + $ue.text;
    $line = $ue.line;
    bool print = true;
    bool zeroprint = false;
    if ($MULOP->getText() == "%") {
        if ($t.type != "int" || $ue.type != "int") {
            writeIntoErrorFile("Error at line " + std::to_string($line) + ": Non-Integer operand on modulus operator\n");
            writeIntoparserLogFile("Line " + std::to_string($line) + ": term : term MULOP unary_expression\n");
            writeIntoparserLogFile("Error at line " + std::to_string($line) + ": Non-Integer operand on modulus operator\n\n" + $text + "\n");
                            errorCount++;
            print = false;
        }
        else if($ue.text == "0"){
            zeroprint = true;
            errorCount++;
        }
     
        $type = "int"; 
    } else {
        if ($t.type == "float" || $ue.type == "float") {
            $type = "float";
        } else {
            $type = "int";
        }
    }
    if(print && zeroprint == false){
    writeIntoparserLogFile("Line " + std::to_string($line) + ": term : term MULOP unary_expression\n\n" + $text + "\n");
    }  

    if(zeroprint){
             writeIntoErrorFile("Error at line " + std::to_string($line) + ": Modulus by Zero\n");
    writeIntoparserLogFile("Line " + std::to_string($line) + ": term : term MULOP unary_expression\n");

            writeIntoparserLogFile("Error at line " + std::to_string($line) + ": Modulus by Zero\n\n" + $text + "\n");
    }

    

  

    if ($MULOP->getText() == "*") {
        writeIntoAsmFile("\tPOP DX");
        writeIntoAsmFile("\tPOP AX"); 
        $code_section = "\tMUL DX\n\tPUSH AX";
    } else if ($MULOP->getText() == "/") {
        $code_section = "\tXCHG AX, DX\n\tDIV DX\n\tPUSH AX";
    } else if ($MULOP->getText() == "%") {
        writeIntoAsmFile("\tPOP CX");
        writeIntoAsmFile("\tPOP AX");
        $code_section = "\tCWD\n\tDIV CX\n\tPUSH DX";
    }
    writeIntoAsmFile($code_section);
};
unary_expression
	returns[std::string text, int line,std::string type, bool argIsArray, std::string code_section]:
	ADDOP ue = unary_expression {
            $text = $ADDOP->getText() + $ue.text;
            $line = $ADDOP->getLine();
            $type = $ue.type;
            $code_section = $ue.code_section;


            writeIntoAsmFile("\tPOP AX");
            if ($ADDOP->getText() == "+") {
                $code_section = "\tPUSH AX";
            } else if ($ADDOP->getText() == "-") {
                $code_section = "\tNEG AX\n\tPUSH AX";
            }
            writeIntoAsmFile($code_section);
            writeIntoparserLogFile("Line "+  std::to_string($line)+": unary_expression : ADDOP unary_expression\n\n" + $text + "\n");

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
            $code_section = $f.code_section;
            writeIntoparserLogFile("Line "+  std::to_string($f.line)+": unary_expression : factor\n\n" + $f.text + "\n"); 
            };

factor
	returns[std::string text, int line,std::string type , bool argIsArray, std::string code_section]:
	v = variable {
        $text = $v.text;
        $line = $v.line;
        $type = $v.type;
        $argIsArray = $v.isArray;

        SymbolInfo* lookup = symbolTable->LookUP($v.text);

        if(lookup->getIsGlobal()){
            writeIntoAsmFile("\tMOV AX, "+$v.text+"       ; Line "+std::to_string($line));
            writeIntoAsmFile("\tPUSH AX");
          }

          else {   
            writeIntoAsmFile("L" + std::to_string(label_count++)+":");

            writeIntoAsmFile("\tMOV AX, [BP-" + std::to_string(lookup->getStackOffset()) + "]"+"       ; Line "+std::to_string($line));
            writeIntoAsmFile("\tPUSH AX");
          }

        // std::cout << "v type"<<$v.type <<std::endl;
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
                //            std::cout<<std::to_string($line)<<func->getSymbolName()<<(int)func->parameterList.size()<< argumentCount<<std::endl;

        if ((int)func->parameterList.size()!= argumentCount) {

            writeIntoErrorFile("Error at line " + std::to_string($line) + ": Total number of arguments mismatch with declaration in function " + $ID->getText() + "\n");
            writeIntoparserLogFile("Error at line " + std::to_string($line) + ": Total number of arguments mismatch with declaration in function " + $ID->getText() + "\n");

            errorCount++;
        } 
        else {
            for (int i = 0; i < argumentCount; i++) {
                std::string expectedType = func->parameterList[i].first;
              //  std::cout<<func->parameterList[i].first <<std::endl;
                std::string argType = argumentTypes[i];
                bool argIsArray = argumentIsArray[i];
                std::cout << "expectedType: " << expectedType << ", argType: " << argType << ", argIsArray: " << argIsArray << std::endl;
                if (argIsArray && expectedType !=argType) {
                   // std::cout<<"ekhane eshche"<<std::endl;
                    writeIntoErrorFile("Error at line " + std::to_string($line) + ": Type mismatch, " + func->parameterList[i].second + " is an array\n");
                    writeIntoparserLogFile("Error at line " + std::to_string($line) + ": Type mismatch " + func->parameterList[i].second + " is an array\n");
                    errorCount++;
                } 
                else if (!argIsArray && expectedType != argType) {
                    writeIntoErrorFile("Error at line " + std::to_string($line) + ": " + std::to_string(i + 1) + "th argument mismatch in function " + $ID->getText() + "\n");
                    writeIntoparserLogFile("Error at line " + std::to_string($line) + ": " + std::to_string(i + 1) + "th argument mismatch in function " + $ID->getText() + "\n");
                    errorCount++;
                    break;
                }
            }

            std::cout << "argumentCount: " << argumentCount << std::endl;

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
         $argIsArray = false;
        writeIntoparserLogFile("Line "+  std::to_string($line)+": factor : LPAREN expression RPAREN\n\n" + $text + "\n");

     }
	| CONST_INT {
        $text = $CONST_INT->getText();
        $line = $CONST_INT->getLine();
        $type = "int";
        $argIsArray = false;
        writeIntoAsmFile("L" + std::to_string(label_count++) + ":\n" + "\tMOV AX, "+$text +"       ; Line "+std::to_string($line));
        writeIntoAsmFile("\tPUSH AX");
        

        

        writeIntoparserLogFile("Line "+  std::to_string($line)+": factor : CONST_INT\n\n" + $text + "\n");

    }
	| CONST_FLOAT {
        $text = $CONST_FLOAT->getText();
        $line = $CONST_FLOAT->getLine();
        $type = "float";
         $argIsArray = false;
        writeIntoparserLogFile("Line "+  std::to_string($line)+": factor : CONST_FLOAT\n\n" + $text + "\n");

    }
	| v = variable INCOP {
        $text = $v.text+$INCOP->getText();
        $line = $INCOP->getLine();
        $type = $v.type;

        SymbolInfo* lookup = symbolTable->LookUP($v.text);
        writeIntoAsmFile("\tMOV AX, [BP-" + std::to_string(lookup->getStackOffset()) + "]"+"       ; Line "+std::to_string($line));
        writeIntoAsmFile("\tPUSH AX");
        writeIntoAsmFile("\tINC AX");
        writeIntoAsmFile("\tMOV [BP-" + std::to_string(lookup->getStackOffset()) + "], AX" + "       ; Line "+std::to_string($line));

        writeIntoparserLogFile("Line "+  std::to_string($line)+": factor : variable INCOP\n\n" + $text + "\n");

    }
	| v = variable DECOP {
        $text = $v.text+$DECOP->getText();
        $line = $DECOP->getLine();
        $type = $v.type;
         SymbolInfo* lookup = symbolTable->LookUP($v.text);
        writeIntoAsmFile("\tMOV AX, [BP-" + std::to_string(lookup->getStackOffset()) + "]"+"       ; Line "+std::to_string($line));
        writeIntoAsmFile("\tPUSH AX");
        writeIntoAsmFile("\tDEC AX");
     writeIntoAsmFile("\tMOV [BP-" + std::to_string(lookup->getStackOffset()) + "], AX" + "       ; Line "+std::to_string($line));

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