// Generated from /home/nidhi/3-1/LABS/BUET-ACADEMICS/3-1 SESSIONALS/CSE 310/OFFLINE_4_ICG/C2105168Parser.g4 by ANTLR 4.13.1

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

    extern bool isInsideFunctionDefinition;
    extern bool isParamsymbol;

    extern int paramsize;
    extern int param_offset;
    extern int spcount;

import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.misc.*;
import org.antlr.v4.runtime.tree.*;
import java.util.List;
import java.util.Iterator;
import java.util.ArrayList;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast", "CheckReturnValue"})
public class C2105168Parser extends Parser {
	static { RuntimeMetaData.checkVersion("4.13.1", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		LINE_COMMENT=1, BLOCK_COMMENT=2, STRING=3, WS=4, IF=5, ELSE=6, FOR=7, 
		WHILE=8, PRINTLN=9, RETURN=10, INT=11, FLOAT=12, VOID=13, LPAREN=14, RPAREN=15, 
		LCURL=16, RCURL=17, LTHIRD=18, RTHIRD=19, SEMICOLON=20, COMMA=21, HASH=22, 
		ADDOP=23, SUBOP=24, MULOP=25, INCOP=26, DECOP=27, NOT=28, RELOP=29, LOGICOP=30, 
		ASSIGNOP=31, ID=32, CONST_INT=33, CONST_FLOAT=34;
	public static final int
		RULE_start = 0, RULE_program = 1, RULE_unit = 2, RULE_func_declaration = 3, 
		RULE_func_definition = 4, RULE_parameter_list = 5, RULE_compound_statement = 6, 
		RULE_var_declaration = 7, RULE_declaration_list_err = 8, RULE_type_specifier = 9, 
		RULE_declaration_list = 10, RULE_statements = 11, RULE_statement = 12, 
		RULE_expression_statement = 13, RULE_variable = 14, RULE_expression = 15, 
		RULE_logic_expression = 16, RULE_rel_expression = 17, RULE_simple_expression = 18, 
		RULE_term = 19, RULE_unary_expression = 20, RULE_factor = 21, RULE_argument_list = 22, 
		RULE_arguments = 23;
	private static String[] makeRuleNames() {
		return new String[] {
			"start", "program", "unit", "func_declaration", "func_definition", "parameter_list", 
			"compound_statement", "var_declaration", "declaration_list_err", "type_specifier", 
			"declaration_list", "statements", "statement", "expression_statement", 
			"variable", "expression", "logic_expression", "rel_expression", "simple_expression", 
			"term", "unary_expression", "factor", "argument_list", "arguments"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, null, null, null, null, "'if'", "'else'", "'for'", "'while'", "'println'", 
			"'return'", "'int'", "'float'", "'void'", "'('", "')'", "'{'", "'}'", 
			"'['", "']'", "';'", "','", "'#'", null, null, null, "'++'", "'--'", 
			"'!'", null, null, "'='"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, "LINE_COMMENT", "BLOCK_COMMENT", "STRING", "WS", "IF", "ELSE", 
			"FOR", "WHILE", "PRINTLN", "RETURN", "INT", "FLOAT", "VOID", "LPAREN", 
			"RPAREN", "LCURL", "RCURL", "LTHIRD", "RTHIRD", "SEMICOLON", "COMMA", 
			"HASH", "ADDOP", "SUBOP", "MULOP", "INCOP", "DECOP", "NOT", "RELOP", 
			"LOGICOP", "ASSIGNOP", "ID", "CONST_INT", "CONST_FLOAT"
		};
	}
	private static final String[] _SYMBOLIC_NAMES = makeSymbolicNames();
	public static final Vocabulary VOCABULARY = new VocabularyImpl(_LITERAL_NAMES, _SYMBOLIC_NAMES);

	/**
	 * @deprecated Use {@link #VOCABULARY} instead.
	 */
	@Deprecated
	public static final String[] tokenNames;
	static {
		tokenNames = new String[_SYMBOLIC_NAMES.length];
		for (int i = 0; i < tokenNames.length; i++) {
			tokenNames[i] = VOCABULARY.getLiteralName(i);
			if (tokenNames[i] == null) {
				tokenNames[i] = VOCABULARY.getSymbolicName(i);
			}

			if (tokenNames[i] == null) {
				tokenNames[i] = "<INVALID>";
			}
		}
	}

	@Override
	@Deprecated
	public String[] getTokenNames() {
		return tokenNames;
	}

	@Override

	public Vocabulary getVocabulary() {
		return VOCABULARY;
	}

	@Override
	public String getGrammarFileName() { return "C2105168Parser.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public ATN getATN() { return _ATN; }



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


	    

	public C2105168Parser(TokenStream input) {
		super(input);
		_interp = new ParserATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	@SuppressWarnings("CheckReturnValue")
	public static class StartContext extends ParserRuleContext {
		public std::string text;
		public int line;
		public std::string asm_header;
		public std::string data_section;
		public std::string code_section;
		public std::string asm_footer;
		public ProgramContext p;
		public ProgramContext program() {
			return getRuleContext(ProgramContext.class,0);
		}
		public StartContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_start; }
	}

	public final StartContext start() throws RecognitionException {
		StartContext _localctx = new StartContext(_ctx, getState());
		enterRule(_localctx, 0, RULE_start);
		try {
			enterOuterAlt(_localctx, 1);
			{
			 writeIntoAsmFile(".MODEL SMALL\n.STACK 1000H\n.Data\n\tnumber DB \"00000$\"");
			setState(49);
			((StartContext)_localctx).p = program(0);


			        ((StartContext)_localctx).text =  ((StartContext)_localctx).p.text;
			        ((StartContext)_localctx).line =  ((StartContext)_localctx).p.line;
			        ((StartContext)_localctx).data_section =  ((StartContext)_localctx).p.data_section_code;
			        ((StartContext)_localctx).code_section =  (((StartContext)_localctx).p.code_section);
			        std::cout << "DEBUG: start code_section = '" << _localctx.code_section << "'" << std::endl;
			       // writeIntoparserLogFile("Parsing completed successfully with " + std::to_string(syntaxErrorCount) + " syntax errors.");


			        writeIntoparserLogFile("Line "+std::to_string(_localctx.line)+": start : program\n");
			        symbolTable->print_current_scope_table(parserLogFile);


			        writeIntoparserLogFile("\nTotal number of lines: "+std::to_string(_localctx.line));
			        writeIntoparserLogFile("Total number of errors: "+std::to_string(errorCount));

			        writeIntoAsmFile(Print_assembly);
			        writeIntoAsmFile("END main");
			        std::cout << "here" <<std::endl;


			        std::cout << _localctx.code_section <<std::endl;
				
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ProgramContext extends ParserRuleContext {
		public std::string text;
		public int line;
		public std::string data_section_code;
		public std::string code_section;
		public ProgramContext pu;
		public UnitContext u;
		public UnitContext unit() {
			return getRuleContext(UnitContext.class,0);
		}
		public ProgramContext program() {
			return getRuleContext(ProgramContext.class,0);
		}
		public ProgramContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_program; }
	}

	public final ProgramContext program() throws RecognitionException {
		return program(0);
	}

	private ProgramContext program(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		ProgramContext _localctx = new ProgramContext(_ctx, _parentState);
		ProgramContext _prevctx = _localctx;
		int _startState = 2;
		enterRecursionRule(_localctx, 2, RULE_program, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			{
			setState(53);
			((ProgramContext)_localctx).u = unit();
			 
			        ((ProgramContext)_localctx).text =  ((ProgramContext)_localctx).u.text;
			        ((ProgramContext)_localctx).line =  ((ProgramContext)_localctx).u.line;
			        writeIntoparserLogFile("Line "+std::to_string(_localctx.line)+": program : unit\n\n"+_localctx.text+"\n");

			         
			}
			_ctx.stop = _input.LT(-1);
			setState(62);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,0,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					{
					_localctx = new ProgramContext(_parentctx, _parentState);
					_localctx.pu = _prevctx;
					pushNewRecursionContext(_localctx, _startState, RULE_program);
					setState(56);
					if (!(precpred(_ctx, 2))) throw new FailedPredicateException(this, "precpred(_ctx, 2)");
					setState(57);
					((ProgramContext)_localctx).u = unit();
					  
					                  ((ProgramContext)_localctx).text =  ((ProgramContext)_localctx).pu.text +"\n"+((ProgramContext)_localctx).u.text;
					                  ((ProgramContext)_localctx).line =  ((ProgramContext)_localctx).u.line;
					                  ((ProgramContext)_localctx).data_section_code =  ((ProgramContext)_localctx).pu.data_section_code +((ProgramContext)_localctx).u.data_section_code;
					                  ((ProgramContext)_localctx).code_section =  ((ProgramContext)_localctx).pu.code_section + ((ProgramContext)_localctx).u.code_section;
					                  writeIntoparserLogFile("Line "+std::to_string(_localctx.line)+": program : program unit\n\n"+_localctx.text+"\n");
					                  
					}
					} 
				}
				setState(64);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,0,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class UnitContext extends ParserRuleContext {
		public std::string text;
		public int line;
		public std::string data_section_code;
		public std::string code_section;
		public Var_declarationContext vd;
		public Func_declarationContext fdec;
		public Func_definitionContext fdef;
		public Var_declarationContext var_declaration() {
			return getRuleContext(Var_declarationContext.class,0);
		}
		public Func_declarationContext func_declaration() {
			return getRuleContext(Func_declarationContext.class,0);
		}
		public Func_definitionContext func_definition() {
			return getRuleContext(Func_definitionContext.class,0);
		}
		public UnitContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_unit; }
	}

	public final UnitContext unit() throws RecognitionException {
		UnitContext _localctx = new UnitContext(_ctx, getState());
		enterRule(_localctx, 4, RULE_unit);
		try {
			setState(74);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,1,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(65);
				((UnitContext)_localctx).vd = var_declaration();
				  
				        ((UnitContext)_localctx).text =  ((UnitContext)_localctx).vd.text;
				        ((UnitContext)_localctx).line =  ((UnitContext)_localctx).vd.line;


				        std::cout << "DEBUG: unit var_declaration code_section = '" << _localctx.code_section << "'" << std::endl;
				        writeIntoparserLogFile("Line "+std::to_string(_localctx.line)+": unit : var_declaration\n\n"+_localctx.text+"\n");

				    
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(68);
				((UnitContext)_localctx).fdec = func_declaration();
				  

				        ((UnitContext)_localctx).text =  ((UnitContext)_localctx).fdec.text;  
				        ((UnitContext)_localctx).line =  ((UnitContext)_localctx).fdec.line;
				        writeIntoparserLogFile("Line "+std::to_string(_localctx.line)+": unit : func_declaration\n\n"+_localctx.text+"\n");

				    
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(71);
				((UnitContext)_localctx).fdef = func_definition();
				  
				        ((UnitContext)_localctx).text =  ((UnitContext)_localctx).fdef.text;
				        ((UnitContext)_localctx).line =  ((UnitContext)_localctx).fdef.line;
				        writeIntoparserLogFile("Line "+std::to_string(_localctx.line)+": unit : func_definition\n\n"+_localctx.text+"\n");
				        
				    
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Func_declarationContext extends ParserRuleContext {
		public std::string text;
		public int line;
		public std::string type;
		public std::string code_section;
		public Type_specifierContext ts;
		public Token ID;
		public Token LPAREN;
		public Parameter_listContext pl;
		public Token RPAREN;
		public Token SEMICOLON;
		public TerminalNode ID() { return getToken(C2105168Parser.ID, 0); }
		public TerminalNode LPAREN() { return getToken(C2105168Parser.LPAREN, 0); }
		public TerminalNode RPAREN() { return getToken(C2105168Parser.RPAREN, 0); }
		public TerminalNode SEMICOLON() { return getToken(C2105168Parser.SEMICOLON, 0); }
		public Type_specifierContext type_specifier() {
			return getRuleContext(Type_specifierContext.class,0);
		}
		public Parameter_listContext parameter_list() {
			return getRuleContext(Parameter_listContext.class,0);
		}
		public Func_declarationContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_func_declaration; }
	}

	public final Func_declarationContext func_declaration() throws RecognitionException {
		Func_declarationContext _localctx = new Func_declarationContext(_ctx, getState());
		enterRule(_localctx, 6, RULE_func_declaration);
		try {
			setState(92);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,2,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(76);
				((Func_declarationContext)_localctx).ts = type_specifier();
				setState(77);
				((Func_declarationContext)_localctx).ID = match(ID);

				        paramCount = 0;
				    
				setState(79);
				((Func_declarationContext)_localctx).LPAREN = match(LPAREN);
				setState(80);
				((Func_declarationContext)_localctx).pl = parameter_list(0);
				setState(81);
				((Func_declarationContext)_localctx).RPAREN = match(RPAREN);
				setState(82);
				((Func_declarationContext)_localctx).SEMICOLON = match(SEMICOLON);
				  

				        ((Func_declarationContext)_localctx).text =  ((Func_declarationContext)_localctx).ts.text +" "+ ((Func_declarationContext)_localctx).ID->getText() + ((Func_declarationContext)_localctx).LPAREN->getText() + ((Func_declarationContext)_localctx).pl.text+ ((Func_declarationContext)_localctx).RPAREN->getText() +  ((Func_declarationContext)_localctx).SEMICOLON->getText();
				        ((Func_declarationContext)_localctx).line =  ((Func_declarationContext)_localctx).SEMICOLON->getLine(); 
				        ((Func_declarationContext)_localctx).type =  ((Func_declarationContext)_localctx).ts.text;

				        SymbolInfo* funcSymbol = new SymbolInfo(((Func_declarationContext)_localctx).ID->getText(), "ID");

				        funcSymbol->setIsFunction(true);
				        funcSymbol->setIsFunctionDefined(true);
				        funcSymbol->setReturnType(((Func_declarationContext)_localctx).ts.text);
				        funcSymbol->setParameterList(((Func_declarationContext)_localctx).pl.plist);
				        funcSymbol->setIsDeclared(true);
				        plist = ((Func_declarationContext)_localctx).pl.plist;  

				        fndecreturnTypes.push_back(((Func_declarationContext)_localctx).ts.text);


				        SymbolInfo* existing = symbolTable->LookUP(((Func_declarationContext)_localctx).ID->getText());
				        if (existing && existing->getIsFunction() && existing->getIsFunctionDefined()) {
				            // writeIntoparserLogFile("Error at line " + std::to_string(_localctx.line) + ": Multiple definition of function " + ((Func_declarationContext)_localctx).ID->getText());
				        } else {
				            if(symbolTable->Insert(funcSymbol)){ 
				               // std::cout << funcSymbol->getSymbolName() << ((Func_declarationContext)_localctx).ID->getText() << std::endl;

				              //  writeIntoErrorFile("Error at line "+std::to_string(_localctx.line)+": Multiple declaration of "+((Func_declarationContext)_localctx).ID->getText()+"\n");

				            }


				        }



				        writeIntoparserLogFile("Line "+std::to_string(_localctx.line)+": func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON\n\n"+_localctx.text+"\n");



				    
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(85);
				((Func_declarationContext)_localctx).ts = type_specifier();
				setState(86);
				((Func_declarationContext)_localctx).ID = match(ID);
				setState(87);
				((Func_declarationContext)_localctx).LPAREN = match(LPAREN);
				setState(88);
				((Func_declarationContext)_localctx).RPAREN = match(RPAREN);
				setState(89);
				((Func_declarationContext)_localctx).SEMICOLON = match(SEMICOLON);
				  
				        ((Func_declarationContext)_localctx).text =  ((Func_declarationContext)_localctx).ts.text + " "+((Func_declarationContext)_localctx).ID->getText() + ((Func_declarationContext)_localctx).LPAREN->getText() + ((Func_declarationContext)_localctx).RPAREN->getText() +  ((Func_declarationContext)_localctx).SEMICOLON->getText();
				        ((Func_declarationContext)_localctx).line =  ((Func_declarationContext)_localctx).SEMICOLON->getLine(); 
				        ((Func_declarationContext)_localctx).type =  ((Func_declarationContext)_localctx).ts.text;

				        

				        SymbolInfo* funcSymbol = new SymbolInfo(((Func_declarationContext)_localctx).ID->getText(), "ID");
				        funcSymbol->setIsFunction(true);
				        funcSymbol->setIsFunctionDefined(true);
				        funcSymbol->setReturnType(((Func_declarationContext)_localctx).ts.text);
				        funcSymbol->setIsDeclared(true);



				        SymbolInfo* existing = symbolTable->LookUP(((Func_declarationContext)_localctx).ID->getText());
				        if (existing && existing->getIsFunction() && existing->getIsFunctionDefined()) {
				            writeIntoparserLogFile("Error at line " + std::to_string(_localctx.line) + ": Redeclaration of function " + ((Func_declarationContext)_localctx).ID->getText());
				        } else {
				            if(symbolTable->Insert(funcSymbol)){ 
				                   // std::cout << funcSymbol->getSymbolName() << ((Func_declarationContext)_localctx).ID->getText() << std::endl;
				                         //       writeIntoErrorFile("Error at line "+std::to_string(_localctx.line)+":  Multiple declaration of "+((Func_declarationContext)_localctx).ID->getText()+"\n");

				            }        }

				     

				        writeIntoparserLogFile("Line "+std::to_string(_localctx.line)+": func_declaration : type_specifier ID LPAREN RPAREN SEMICOLON\n\n"+_localctx.text+"\n");

				        
				    
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Func_definitionContext extends ParserRuleContext {
		public std::string text;
		public int line;
		public std::string type;
		public std::string returnType;
		public std::string code_section;
		public Type_specifierContext ts;
		public Token ID;
		public Token LPAREN;
		public Parameter_listContext pl;
		public Token RPAREN;
		public Compound_statementContext cs;
		public TerminalNode ID() { return getToken(C2105168Parser.ID, 0); }
		public TerminalNode LPAREN() { return getToken(C2105168Parser.LPAREN, 0); }
		public TerminalNode RPAREN() { return getToken(C2105168Parser.RPAREN, 0); }
		public Type_specifierContext type_specifier() {
			return getRuleContext(Type_specifierContext.class,0);
		}
		public Parameter_listContext parameter_list() {
			return getRuleContext(Parameter_listContext.class,0);
		}
		public Compound_statementContext compound_statement() {
			return getRuleContext(Compound_statementContext.class,0);
		}
		public Func_definitionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_func_definition; }
	}

	public final Func_definitionContext func_definition() throws RecognitionException {
		Func_definitionContext _localctx = new Func_definitionContext(_ctx, getState());
		enterRule(_localctx, 8, RULE_func_definition);
		try {
			setState(114);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,3,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(94);
				((Func_definitionContext)_localctx).ts = type_specifier();
				setState(95);
				((Func_definitionContext)_localctx).ID = match(ID);
				setState(96);
				((Func_definitionContext)_localctx).LPAREN = match(LPAREN);
				    std::cout << "DEBUG: About to parse parameter_list" << std::endl;
				setState(98);
				((Func_definitionContext)_localctx).pl = parameter_list(0);

				            std::cout << "DEBUG: Successfully parsed parameter_list, pl.text = '" << ((Func_definitionContext)_localctx).pl.text << "'" << std::endl;
				        SymbolInfo* funcSymbol = new SymbolInfo(((Func_definitionContext)_localctx).ID->getText(), "ID");
				        funcSymbol->setIsFunction(true);
				        funcSymbol->setIsFunctionDefined(true);
				        funcSymbol->setReturnType(((Func_definitionContext)_localctx).ts.text);


				        funcSymbol->setParameterList(((Func_definitionContext)_localctx).pl.plist);
				        plist = ((Func_definitionContext)_localctx).pl.plist;
				        fndefreturnTypes.push_back(((Func_definitionContext)_localctx).ts.text);

				        SymbolInfo* existing = symbolTable->LookUP(((Func_definitionContext)_localctx).ID->getText());

				        if (existing && existing->getIsFunction() && existing->getIsFunctionDefined()) {
				           // writeIntoparserLogFile("Error at line " + std::to_string(_localctx.line) + ": Multiple definition of function " + ((Func_definitionContext)_localctx).ID->getText());
				        } else {
				            symbolTable->Insert(funcSymbol);
				        }


				        SymbolInfo* lookup = symbolTable->LookUP(((Func_definitionContext)_localctx).ID->getText());       
				        if(((Func_definitionContext)_localctx).ts.text != lookup->getReturnType() ){

				        writeIntoparserLogFile("Error at line "+std::to_string(((Func_definitionContext)_localctx).ts.line)+": Return type mismatch of "+lookup->getSymbolName()+"\n");
				        writeIntoErrorFile("Error at line "+std::to_string(((Func_definitionContext)_localctx).ts.line)+": Return type mismatch of "+lookup->getSymbolName()+"\n");

				                errorCount++;
				        }



				        paramsize = ((Func_definitionContext)_localctx).pl.plist.size();
				        // for(const auto& param : ((Func_definitionContext)_localctx).pl.plist) {
				        //     SymbolInfo* paramSymbol = new SymbolInfo(param.second, "ID");

				        //     paramSymbol->setStackOffset(2+ (paramsize * 2));
				        //     std::cout << "DEBUG: paramSymbol:" << paramSymbol->getSymbolName() << " stack offset: " << paramSymbol->getStackOffset() << std::endl;
				        // }






				     
				setState(100);
				((Func_definitionContext)_localctx).RPAREN = match(RPAREN);
				    
				        writeIntoAsmFile(((Func_definitionContext)_localctx).ID->getText() + " PROC");
				        if(((Func_definitionContext)_localctx).ID->getText() == "main"){
				        writeIntoAsmFile("\tMOV AX, @DATA\n\tMOV DS, AX");
				        }
				        writeIntoAsmFile("L" + std::to_string(label_count++) + ":");
				        writeIntoAsmFile("\tPUSH BP\n\tMOV BP, SP");
				        isInsideFunctionDefinition = true;
				                isParamsymbol = true;

				    
				setState(102);
				((Func_definitionContext)_localctx).cs = compound_statement();
				  
				        isParamsymbol = false;
				        isInsideFunctionDefinition = false;
				        ((Func_definitionContext)_localctx).text =  ((Func_definitionContext)_localctx).ts.text+" "  + ((Func_definitionContext)_localctx).ID->getText() +  ((Func_definitionContext)_localctx).LPAREN->getText()+ ((Func_definitionContext)_localctx).pl.text + ((Func_definitionContext)_localctx).RPAREN->getText() + ((Func_definitionContext)_localctx).cs.text;
				        ((Func_definitionContext)_localctx).line =  ((Func_definitionContext)_localctx).cs.line;
				        ((Func_definitionContext)_localctx).type =  ((Func_definitionContext)_localctx).ts.text;
				        ((Func_definitionContext)_localctx).returnType =  ((Func_definitionContext)_localctx).cs.type;
				        paramsize = ((Func_definitionContext)_localctx).pl.plist.size();
				        if (((Func_definitionContext)_localctx).ts.text == "void" && _localctx.returnType != "void") {
				            writeIntoErrorFile("Error at line " + std::to_string(_localctx.line) + ": Cannot return value from function "+  ((Func_definitionContext)_localctx).ID->getText() + " with void return type\n");
				             writeIntoparserLogFile("Error at line " + std::to_string(_localctx.line) + ": Cannot return value from function "+  ((Func_definitionContext)_localctx).ID->getText() + " with void return type\n");
				            errorCount++;
				        } 

				        if(((Func_definitionContext)_localctx).ID->getText() == "main"){
				            writeIntoAsmFile("ADD SP, "+std::to_string(spcount * 2)+"\n\tPOP BP");
				            writeIntoAsmFile("\tMOV AX, 4CH\n\tINT 21H");
				        }

				        if(((Func_definitionContext)_localctx).ID->getText() != "main" && paramsize == 0){
				            writeIntoAsmFile("L" + std::to_string(label_count++) + ":");
				            writeIntoAsmFile("\tRET");
				        }

				        else if(((Func_definitionContext)_localctx).ID->getText() != "main" && paramsize > 0){
				            writeIntoAsmFile("L" + std::to_string(label_count++) + ":");
				            writeIntoAsmFile("\tPOP AX\n\tMOV SP, BP\n\tPOP BP\n\tRET "+std::to_string(paramsize * 2)); 
				        }


				        writeIntoAsmFile(((Func_definitionContext)_localctx).ID->getText()+ " ENDP");



				        
				        writeIntoparserLogFile("\nLine "+std::to_string(_localctx.line)+": func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement\n\n"+_localctx.text+"\n");
				 

				    
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(105);
				((Func_definitionContext)_localctx).ts = type_specifier();
				setState(106);
				((Func_definitionContext)_localctx).ID = match(ID);
				setState(107);
				((Func_definitionContext)_localctx).LPAREN = match(LPAREN);
				setState(108);
				((Func_definitionContext)_localctx).RPAREN = match(RPAREN);
				    
				        writeIntoAsmFile(((Func_definitionContext)_localctx).ID->getText() + " PROC");
				        if(((Func_definitionContext)_localctx).ID->getText() == "main"){
				        writeIntoAsmFile("\tMOV AX, @DATA\n\tMOV DS, AX");
				        }

				        writeIntoAsmFile("\tPUSH BP\n\tMOV BP, SP");
				    
				 

				        SymbolInfo* funcSymbol = new SymbolInfo(((Func_definitionContext)_localctx).ID->getText(), "ID");
				        funcSymbol->setIsFunction(true);
				        funcSymbol->setReturnType(((Func_definitionContext)_localctx).ts.text);

				        SymbolInfo* existing = symbolTable->LookUP(((Func_definitionContext)_localctx).ID->getText());
				        if (existing && existing->getIsFunction() && existing->getIsFunctionDefined()) {
				           // writeIntoparserLogFile("Error at line " + std::to_string(_localctx.line) + ": Multiple definition of function " + ((Func_definitionContext)_localctx).ID->getText());
				        } else {
				            symbolTable->Insert(funcSymbol);
				            funcSymbol->setIsFunctionDefined(true);

				        }

				        
				setState(111);
				((Func_definitionContext)_localctx).cs = compound_statement();
				 

				        ((Func_definitionContext)_localctx).text =  ((Func_definitionContext)_localctx).ts.text +" " + ((Func_definitionContext)_localctx).ID->getText() +  ((Func_definitionContext)_localctx).LPAREN->getText() + ((Func_definitionContext)_localctx).RPAREN->getText() + ((Func_definitionContext)_localctx).cs.text;
				        ((Func_definitionContext)_localctx).line =  ((Func_definitionContext)_localctx).cs.line;
				        std::cout << "DEBUG: func_declaration code_section = '" << _localctx.code_section << "'" << std::endl;

				        if(((Func_definitionContext)_localctx).ID->getText() == "main"){
				                        writeIntoAsmFile("\tADD SP, "+std::to_string(spcount * 2)+"\n\tPOP BP");

				            writeIntoAsmFile("\tMOV AX, 4CH\n\tINT 21H");
				        }

				        if(((Func_definitionContext)_localctx).ID->getText() != "main"){
				            writeIntoAsmFile("L" + std::to_string(label_count++) + ":");
				            writeIntoAsmFile("\tPOP AX\n\tMOV SP, BP\n\tPOP BP\n\tRET");
				        }
				        writeIntoAsmFile(((Func_definitionContext)_localctx).ID->getText()+ " ENDP");


				        writeIntoparserLogFile("\nLine "+std::to_string(_localctx.line)+": func_definition : type_specifier ID LPAREN RPAREN compound_statement\n\n"+_localctx.text+"\n");


				    
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Parameter_listContext extends ParserRuleContext {
		public std::string text;
		public int line;
		public std::vector<std::pair<std::string, std::string>> plist;
		public Parameter_listContext pl;
		public Type_specifierContext ts;
		public Token ID;
		public Token ADDOP;
		public Token COMMA;
		public TerminalNode ID() { return getToken(C2105168Parser.ID, 0); }
		public Type_specifierContext type_specifier() {
			return getRuleContext(Type_specifierContext.class,0);
		}
		public TerminalNode ADDOP() { return getToken(C2105168Parser.ADDOP, 0); }
		public TerminalNode COMMA() { return getToken(C2105168Parser.COMMA, 0); }
		public Parameter_listContext parameter_list() {
			return getRuleContext(Parameter_listContext.class,0);
		}
		public Parameter_listContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_parameter_list; }
	}

	public final Parameter_listContext parameter_list() throws RecognitionException {
		return parameter_list(0);
	}

	private Parameter_listContext parameter_list(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		Parameter_listContext _localctx = new Parameter_listContext(_ctx, _parentState);
		Parameter_listContext _prevctx = _localctx;
		int _startState = 10;
		enterRecursionRule(_localctx, 10, RULE_parameter_list, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(130);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,4,_ctx) ) {
			case 1:
				{
				setState(117);
				((Parameter_listContext)_localctx).ts = type_specifier();
				setState(118);
				((Parameter_listContext)_localctx).ID = match(ID);

				        ((Parameter_listContext)_localctx).text =  ((Parameter_listContext)_localctx).ts.text + " " + ((Parameter_listContext)_localctx).ID->getText()   ;
				        ((Parameter_listContext)_localctx).line =  ((Parameter_listContext)_localctx).ID->getLine();
				        _localctx.plist.push_back(std::make_pair(((Parameter_listContext)_localctx).ts.text, ((Parameter_listContext)_localctx).ID->getText()));

				        SymbolInfo* paramSymbol = new SymbolInfo(((Parameter_listContext)_localctx).ID->getText(), "ID");
				        paramSymbol->setIsArray(false);
				        paramSymbol->setType(((Parameter_listContext)_localctx).ts.text);


				        writeIntoparserLogFile("Line " + std::to_string(_localctx.line) +": parameter_list : type_specifier ID\n\n" + _localctx.text + "\n");
						
				}
				break;
			case 2:
				{
				setState(121);
				((Parameter_listContext)_localctx).ts = type_specifier();
				setState(122);
				((Parameter_listContext)_localctx).ADDOP = match(ADDOP);

				        ((Parameter_listContext)_localctx).text =  ((Parameter_listContext)_localctx).ts.text;
				        ((Parameter_listContext)_localctx).line =  ((Parameter_listContext)_localctx).ADDOP->getLine();
				        writeIntoErrorFile("Error at line " + std::to_string(_localctx.line) + ": syntax error, unexpected ADDOP, expecting RPAREN or COMMA\n");
				        writeIntoparserLogFile("Error at line " + std::to_string(_localctx.line) + ": syntax error, unexpected ADDOP, expecting RPAREN or COMMA\n");
				        
				}
				break;
			case 3:
				{
				setState(125);
				((Parameter_listContext)_localctx).ts = type_specifier();


				        ((Parameter_listContext)_localctx).text =  ((Parameter_listContext)_localctx).ts.text ;
				        ((Parameter_listContext)_localctx).line =  ((Parameter_listContext)_localctx).ts.line;
				            std::cout << "DEBUG: ts.text = '" << ((Parameter_listContext)_localctx).ts.text << "'" << std::endl;
				    std::cout << "DEBUG: ts.line = " << ((Parameter_listContext)_localctx).ts.line << std::endl;
				        _localctx.plist.push_back(std::make_pair(((Parameter_listContext)_localctx).ts.text, ""));
				        writeIntoparserLogFile("Line " + std::to_string(_localctx.line) + ": parameter_list : type_specifier \n" +((Parameter_listContext)_localctx).ts.text+ "\n");
						
				}
				break;
			case 4:
				{
				setState(128);
				((Parameter_listContext)_localctx).ADDOP = match(ADDOP);

				        ((Parameter_listContext)_localctx).line =  ((Parameter_listContext)_localctx).ADDOP->getLine();
				        writeIntoErrorFile("Error at line " + std::to_string(_localctx.line) + ": syntax error, unexpected ADDOP, expecting RPAREN or COMMA\n");
				        writeIntoparserLogFile("Error at line " + std::to_string(_localctx.line) + ": syntax error, unexpected ADDOP, expecting RPAREN or COMMA\n");
				        
				}
				break;
			}
			_ctx.stop = _input.LT(-1);
			setState(149);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,6,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					setState(147);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,5,_ctx) ) {
					case 1:
						{
						_localctx = new Parameter_listContext(_parentctx, _parentState);
						_localctx.pl = _prevctx;
						pushNewRecursionContext(_localctx, _startState, RULE_parameter_list);
						setState(132);
						if (!(precpred(_ctx, 7))) throw new FailedPredicateException(this, "precpred(_ctx, 7)");
						setState(133);
						((Parameter_listContext)_localctx).COMMA = match(COMMA);
						setState(134);
						((Parameter_listContext)_localctx).ts = type_specifier();
						setState(135);
						((Parameter_listContext)_localctx).ID = match(ID);

						                  ((Parameter_listContext)_localctx).text = ((Parameter_listContext)_localctx).pl.text+((Parameter_listContext)_localctx).COMMA->getText()+ ((Parameter_listContext)_localctx).ts.text +" " + ((Parameter_listContext)_localctx).ID->getText();
						                  ((Parameter_listContext)_localctx).line =  ((Parameter_listContext)_localctx).ID->getLine();
						                  ((Parameter_listContext)_localctx).plist =  ((Parameter_listContext)_localctx).pl.plist;
						                          paramCount++;

						                  _localctx.plist.push_back(std::make_pair(((Parameter_listContext)_localctx).ts.text, ((Parameter_listContext)_localctx).ID->getText()));
						                  
						                   writeIntoparserLogFile("Line " + std::to_string(_localctx.line) + ": parameter_list : parameter_list COMMA type_specifier ID\n\n"+_localctx.text+"\n");
						              
						}
						break;
					case 2:
						{
						_localctx = new Parameter_listContext(_parentctx, _parentState);
						_localctx.pl = _prevctx;
						pushNewRecursionContext(_localctx, _startState, RULE_parameter_list);
						setState(138);
						if (!(precpred(_ctx, 6))) throw new FailedPredicateException(this, "precpred(_ctx, 6)");
						setState(139);
						((Parameter_listContext)_localctx).COMMA = match(COMMA);
						setState(140);
						((Parameter_listContext)_localctx).ts = type_specifier();

						                  ((Parameter_listContext)_localctx).text = ((Parameter_listContext)_localctx).pl.text + ((Parameter_listContext)_localctx).COMMA->getText() +  ((Parameter_listContext)_localctx).ts.text ;
						                  ((Parameter_listContext)_localctx).line =  ((Parameter_listContext)_localctx).ts.line;
						                  ((Parameter_listContext)_localctx).plist =  ((Parameter_listContext)_localctx).pl.plist;
						                  _localctx.plist.push_back(std::make_pair(((Parameter_listContext)_localctx).ts.text, ""));
						                  writeIntoparserLogFile("Line " + std::to_string(_localctx.line) + ": parameter_list : parameter_list COMMA type_specifier \n" +_localctx.text + "\n");
						          		
						}
						break;
					case 3:
						{
						_localctx = new Parameter_listContext(_parentctx, _parentState);
						_localctx.pl = _prevctx;
						pushNewRecursionContext(_localctx, _startState, RULE_parameter_list);
						setState(143);
						if (!(precpred(_ctx, 5))) throw new FailedPredicateException(this, "precpred(_ctx, 5)");
						setState(144);
						((Parameter_listContext)_localctx).COMMA = match(COMMA);
						setState(145);
						((Parameter_listContext)_localctx).ADDOP = match(ADDOP);

						                  ((Parameter_listContext)_localctx).text =  ((Parameter_listContext)_localctx).pl.text;
						                  ((Parameter_listContext)_localctx).line =  ((Parameter_listContext)_localctx).ADDOP->getLine();
						                  writeIntoparserLogFile("Error at line " + std::to_string(_localctx.line) + 
						                      ": syntax error, unexpected ADDOP, expecting type_specifier\n");
						                  writeIntoErrorFile("Error at line " + std::to_string(_localctx.line) + 
						                      ": syntax error, unexpected ADDOP, expecting type_specifier\n");
						              
						}
						break;
					}
					} 
				}
				setState(151);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,6,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Compound_statementContext extends ParserRuleContext {
		public std::string text;
		public int line;
		public std::string type;
		public std::string code_section;
		public Token LCURL;
		public StatementsContext ss;
		public Token RCURL;
		public TerminalNode LCURL() { return getToken(C2105168Parser.LCURL, 0); }
		public TerminalNode RCURL() { return getToken(C2105168Parser.RCURL, 0); }
		public StatementsContext statements() {
			return getRuleContext(StatementsContext.class,0);
		}
		public Compound_statementContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_compound_statement; }
	}

	public final Compound_statementContext compound_statement() throws RecognitionException {
		Compound_statementContext _localctx = new Compound_statementContext(_ctx, getState());
		enterRule(_localctx, 12, RULE_compound_statement);
		try {
			setState(163);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,7,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(152);
				((Compound_statementContext)_localctx).LCURL = match(LCURL);
				 symbolTable->EnterScope();  
				        


				        //stack e param pop age pore hoye gondogol kortese ,, list ultaye dibo

				        for (auto it = plist.rbegin(); it != plist.rend(); ++it) {
				            ((Compound_statementContext)_localctx).line =  ((Compound_statementContext)_localctx).LCURL->getLine();
				            SymbolInfo* paramSymbol = new SymbolInfo(it->second, "ID");
				            paramSymbol->setIsArray(false);
				            paramSymbol->setSymbolDataType(it->first);
				            
				            param_offset += 2;
				            paramSymbol->setStackOffset(param_offset);

				            std::cout << "DEBUG: paramSymbol: " << paramSymbol->getSymbolName() 
				                    << " stack offset: " << paramSymbol->getStackOffset() << std::endl;

				            if (!symbolTable->Insert(paramSymbol)) {
				                writeIntoparserLogFile("Error at line " + std::to_string(_localctx.line) + 
				                    ": Multiple declaration of " + it->second + " in parameter\n");
				                writeIntoErrorFile("Error at line " + std::to_string(_localctx.line) + 
				                    ": Multiple declaration of " + it->second + " in parameter\n");
				                errorCount++;
				            }
				        }

				        plist.clear();
				        
				         
				setState(154);
				((Compound_statementContext)_localctx).ss = statements(0);
				 
				            std::cout<<"kire"<<std::endl;
				            for(const auto& param : plist) {

				            std::cout<<"kire mannager nati loop e ahos na kere"<<std::endl;

				                SymbolInfo* paramSymbol = new SymbolInfo(param.second, "ID");

				                std::cout << "HELLO: paramSymbol:" << param.second << " stack offset: " << paramSymbol->getStackOffset() << std::endl;
				            }
				                        std::cout<<"kire maannger nati"<<std::endl;

				        ((Compound_statementContext)_localctx).type =  ((Compound_statementContext)_localctx).ss.type;
				    
				setState(156);
				((Compound_statementContext)_localctx).RCURL = match(RCURL);

				        ((Compound_statementContext)_localctx).text =  ((Compound_statementContext)_localctx).LCURL->getText()+"\n" + ((Compound_statementContext)_localctx).ss.text +"\n" + ((Compound_statementContext)_localctx).RCURL->getText();
				        ((Compound_statementContext)_localctx).line =  (((Compound_statementContext)_localctx).RCURL!=null?((Compound_statementContext)_localctx).RCURL.getLine():0);
				        ((Compound_statementContext)_localctx).code_section =  ((Compound_statementContext)_localctx).ss.code_section;
				        writeIntoparserLogFile("Line "+std::to_string(_localctx.line)+": compound_statement : LCURL statements RCURL\n\n"+_localctx.text+"\n");
				        symbolTable->print_all_scope_table2(parserLogFile);
				        symbolTable->ExitScope();


				    
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(159);
				((Compound_statementContext)_localctx).LCURL = match(LCURL);
				symbolTable->EnterScope();
				setState(161);
				((Compound_statementContext)_localctx).RCURL = match(RCURL);


				        ((Compound_statementContext)_localctx).text =  ((Compound_statementContext)_localctx).LCURL->getText()+((Compound_statementContext)_localctx).RCURL->getText();
				        ((Compound_statementContext)_localctx).line =  ((Compound_statementContext)_localctx).RCURL->getLine();
				        ((Compound_statementContext)_localctx).type =  "void"; 
				        writeIntoparserLogFile("Line "+std::to_string(_localctx.line)+": compound_statement : LCURL RCURL\n\n"+_localctx.text+"\n");

				        symbolTable->print_all_scope_table2(parserLogFile);
				        symbolTable->ExitScope();

				    
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Var_declarationContext extends ParserRuleContext {
		public std::string text;
		public int line;
		public std::string data_section_code;
		public std::string code_section;
		public Type_specifierContext t;
		public Declaration_listContext dl;
		public Token sm;
		public Declaration_list_errContext de;
		public Type_specifierContext type_specifier() {
			return getRuleContext(Type_specifierContext.class,0);
		}
		public Declaration_listContext declaration_list() {
			return getRuleContext(Declaration_listContext.class,0);
		}
		public TerminalNode SEMICOLON() { return getToken(C2105168Parser.SEMICOLON, 0); }
		public Declaration_list_errContext declaration_list_err() {
			return getRuleContext(Declaration_list_errContext.class,0);
		}
		public Var_declarationContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_var_declaration; }
	}

	public final Var_declarationContext var_declaration() throws RecognitionException {
		Var_declarationContext _localctx = new Var_declarationContext(_ctx, getState());
		enterRule(_localctx, 14, RULE_var_declaration);
		try {
			setState(175);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,8,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(165);
				((Var_declarationContext)_localctx).t = type_specifier();
				setState(166);
				((Var_declarationContext)_localctx).dl = declaration_list(0);
				setState(167);
				((Var_declarationContext)_localctx).sm = match(SEMICOLON);

				        ((Var_declarationContext)_localctx).text =  ((Var_declarationContext)_localctx).t.text +" "+ ((Var_declarationContext)_localctx).dl.text + ((Var_declarationContext)_localctx).sm->getText() ;
				        ((Var_declarationContext)_localctx).line =  ((Var_declarationContext)_localctx).t.line;
				        ((Var_declarationContext)_localctx).data_section_code =  "";
				        ((Var_declarationContext)_localctx).code_section =  "";
				        bool pushbpprint = false;
				        writeIntoparserLogFile("Line "+std::to_string(_localctx.line)+": var_declaration : type_specifier declaration_list SEMICOLON\n\n"+_localctx.text+"\n");


				        for(const auto& var : ((Var_declarationContext)_localctx).dl.varList) {
				            SymbolInfo* varSymbol = new SymbolInfo(var.first, "ID");
				            varSymbol->setIsArray(var.second);
				            varSymbol->setSymbolDataType(((Var_declarationContext)_localctx).t.type);
				            if(!symbolTable->Insert(varSymbol)){
				                writeIntoparserLogFile("Error at line "+std::to_string(_localctx.line)+":  Multiple declaration of "+var.first+"\n");
				                writeIntoErrorFile("Error at line "+std::to_string(_localctx.line)+": Multiple declaration of "+var.first+"\n");
				                                errorCount++;
				            }


				            std::string currentScopeId = symbolTable->getCurrentScopeID();

				            if(currentScopeId == "1"){

				                isDATAEmpty = false;
				                
				                stack_offset_global += 2;

				                if(!isInsideFunctionDefinition){
				                    varSymbol->setStackOffset(stack_offset_global);
				                    varSymbol->setIsGlobal(true);
				                }
				                if(isInsideFunctionDefinition && isParamsymbol){
				                    varSymbol->setStackOffset(2 + (paramsize * 2));
				                }

				                _localctx.data_section_code+="\t"+varSymbol->getSymbolName()+" DW 1 DUP (0000H)\n";

				                std::cout << "data_section_code: " << _localctx.data_section_code << std::endl;
				            }


				            else if(currentScopeId !="1" ){
				                if(!pushbpprint){
				                    pushbpprint = true;
				                }

				                std::cout<<"BAAL "<<isInsideFunctionDefinition<< " isParamsymbol: " << isParamsymbol << std::endl;
				                if(isInsideFunctionDefinition && isParamsymbol){
				                    varSymbol->setStackOffset(2 + (paramsize * 2));
				                    std::cout << "DEBUG: paramSymbol: inside var_dec" << varSymbol->getSymbolName() << " stack offset: " << varSymbol->getStackOffset() << std::endl;
				                }
				                else{
				                    stack_offset_local += 2;
				                    varSymbol->setStackOffset(stack_offset_local);
				                }

				                _localctx.code_section += "\tSUB SP, 2\n";
				            spcount++;

				            }
				        }
				                    std::string currentScopeId = symbolTable->getCurrentScopeID();

				        if(currentScopeId == "1"){
				                writeIntoAsmFile(_localctx.data_section_code+".CODE");
				        }
				         writeIntoAsmFile(_localctx.code_section);




				        if(((Var_declarationContext)_localctx).t.text == "void"){
				            writeIntoparserLogFile("Error at line "+std::to_string(_localctx.line)+":  Variable type cannot be void\n");
				            writeIntoErrorFile("Error at line "+std::to_string(_localctx.line)+": Variable type cannot be void\n");
				                            errorCount++;
				        }

				        

				        
				      
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(170);
				((Var_declarationContext)_localctx).t = type_specifier();
				setState(171);
				((Var_declarationContext)_localctx).de = declaration_list_err();
				setState(172);
				((Var_declarationContext)_localctx).sm = match(SEMICOLON);

				        ((Var_declarationContext)_localctx).text =  ((Var_declarationContext)_localctx).t.text;
				        ((Var_declarationContext)_localctx).line =  ((Var_declarationContext)_localctx).t.line;
				        writeIntoErrorFile(
				            std::string("Line# ") + std::to_string(((Var_declarationContext)_localctx).sm->getLine()) +
				            " with error name: " + ((Var_declarationContext)_localctx).de.error_name +
				            " - Syntax error at declaration list of variable declaration"
				        );


				        syntaxErrorCount++;
				      
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Declaration_list_errContext extends ParserRuleContext {
		public std::string error_name;
		public Declaration_list_errContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_declaration_list_err; }
	}

	public final Declaration_list_errContext declaration_list_err() throws RecognitionException {
		Declaration_list_errContext _localctx = new Declaration_list_errContext(_ctx, getState());
		enterRule(_localctx, 16, RULE_declaration_list_err);
		try {
			enterOuterAlt(_localctx, 1);
			{

			        ((Declaration_list_errContext)_localctx).error_name =  "Error in declaration list";
			    
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Type_specifierContext extends ParserRuleContext {
		public std::string text;
		public int line;
		public std::string type;
		public Token INT;
		public Token FLOAT;
		public Token VOID;
		public TerminalNode INT() { return getToken(C2105168Parser.INT, 0); }
		public TerminalNode FLOAT() { return getToken(C2105168Parser.FLOAT, 0); }
		public TerminalNode VOID() { return getToken(C2105168Parser.VOID, 0); }
		public Type_specifierContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_type_specifier; }
	}

	public final Type_specifierContext type_specifier() throws RecognitionException {
		Type_specifierContext _localctx = new Type_specifierContext(_ctx, getState());
		enterRule(_localctx, 18, RULE_type_specifier);
		try {
			setState(185);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case INT:
				enterOuterAlt(_localctx, 1);
				{
				setState(179);
				((Type_specifierContext)_localctx).INT = match(INT);

				            ((Type_specifierContext)_localctx).text =  ((Type_specifierContext)_localctx).INT->getText();
				            ((Type_specifierContext)_localctx).line =  ((Type_specifierContext)_localctx).INT->getLine();
				            ((Type_specifierContext)_localctx).type =  "int";
							writeIntoparserLogFile("Line " + std::to_string(((Type_specifierContext)_localctx).INT->getLine()) + ": type_specifier : INT\n\n" + ((Type_specifierContext)_localctx).INT->getText() + "\n");
				            if(multipleDeclaration){

				            }
				        
				}
				break;
			case FLOAT:
				enterOuterAlt(_localctx, 2);
				{
				setState(181);
				((Type_specifierContext)_localctx).FLOAT = match(FLOAT);

				            ((Type_specifierContext)_localctx).text =  ((Type_specifierContext)_localctx).FLOAT->getText();
				            ((Type_specifierContext)_localctx).line =  ((Type_specifierContext)_localctx).FLOAT->getLine();
				            ((Type_specifierContext)_localctx).type =  "float";
							writeIntoparserLogFile("Line " + std::to_string(((Type_specifierContext)_localctx).FLOAT->getLine()) + ": type_specifier : FLOAT\n\n" +((Type_specifierContext)_localctx).FLOAT->getText() + "\n");        
						
				}
				break;
			case VOID:
				enterOuterAlt(_localctx, 3);
				{
				setState(183);
				((Type_specifierContext)_localctx).VOID = match(VOID);

				            ((Type_specifierContext)_localctx).text =  ((Type_specifierContext)_localctx).VOID->getText();
				            ((Type_specifierContext)_localctx).line =  ((Type_specifierContext)_localctx).VOID->getLine();
				            ((Type_specifierContext)_localctx).type =  "void";
				            writeIntoparserLogFile("Line " + std::to_string(((Type_specifierContext)_localctx).VOID->getLine()) + ": type_specifier : VOID\n\n" +((Type_specifierContext)_localctx).VOID->getText() + "\n");        
				        
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Declaration_listContext extends ParserRuleContext {
		public std::string text;
		public int line;
		public std::string type;
		public std::vector<std::pair<std::string, bool>> varList;
		public Declaration_listContext dl;
		public Token ID;
		public Token LTHIRD;
		public Token CONST_INT;
		public Token RTHIRD;
		public Token ADDOP;
		public Declaration_listContext declaration_list;
		public Token COMMA;
		public TerminalNode ID() { return getToken(C2105168Parser.ID, 0); }
		public TerminalNode LTHIRD() { return getToken(C2105168Parser.LTHIRD, 0); }
		public TerminalNode CONST_INT() { return getToken(C2105168Parser.CONST_INT, 0); }
		public TerminalNode RTHIRD() { return getToken(C2105168Parser.RTHIRD, 0); }
		public TerminalNode ADDOP() { return getToken(C2105168Parser.ADDOP, 0); }
		public Declaration_listContext declaration_list() {
			return getRuleContext(Declaration_listContext.class,0);
		}
		public TerminalNode COMMA() { return getToken(C2105168Parser.COMMA, 0); }
		public Declaration_listContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_declaration_list; }
	}

	public final Declaration_listContext declaration_list() throws RecognitionException {
		return declaration_list(0);
	}

	private Declaration_listContext declaration_list(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		Declaration_listContext _localctx = new Declaration_listContext(_ctx, _parentState);
		Declaration_listContext _prevctx = _localctx;
		int _startState = 20;
		enterRecursionRule(_localctx, 20, RULE_declaration_list, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(200);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,10,_ctx) ) {
			case 1:
				{
				setState(188);
				((Declaration_listContext)_localctx).ID = match(ID);
				 
				        ((Declaration_listContext)_localctx).text =  ((Declaration_listContext)_localctx).ID->getText();
				        ((Declaration_listContext)_localctx).line =  ((Declaration_listContext)_localctx).ID->getLine();
				        _localctx.varList.push_back(std::make_pair(((Declaration_listContext)_localctx).ID->getText(), false));
				        writeIntoparserLogFile("Line " + std::to_string(_localctx.line) + ": declaration_list : ID\n\n" +_localctx.text + "\n");        

				    
				}
				break;
			case 2:
				{
				setState(190);
				((Declaration_listContext)_localctx).ID = match(ID);
				setState(191);
				((Declaration_listContext)_localctx).LTHIRD = match(LTHIRD);
				setState(192);
				((Declaration_listContext)_localctx).CONST_INT = match(CONST_INT);
				setState(193);
				((Declaration_listContext)_localctx).RTHIRD = match(RTHIRD);
				 
				        ((Declaration_listContext)_localctx).text =  ((Declaration_listContext)_localctx).ID->getText() + ((Declaration_listContext)_localctx).LTHIRD->getText() + ((Declaration_listContext)_localctx).CONST_INT->getText() + ((Declaration_listContext)_localctx).RTHIRD->getText();
				        ((Declaration_listContext)_localctx).line =  ((Declaration_listContext)_localctx).ID->getLine();

				        ((Declaration_listContext)_localctx).type =  "array";
				        _localctx.varList.push_back(std::make_pair(((Declaration_listContext)_localctx).ID->getText(), true));

				        
				        writeIntoparserLogFile("Line " + std::to_string(_localctx.line) + ": declaration_list : ID LTHIRD CONST_INT RTHIRD\n\n" +_localctx.text + "\n");        

				    
				}
				break;
			case 3:
				{
				setState(195);
				((Declaration_listContext)_localctx).ID = match(ID);
				setState(196);
				((Declaration_listContext)_localctx).ADDOP = match(ADDOP);
				setState(197);
				((Declaration_listContext)_localctx).declaration_list = declaration_list(1);

				        ((Declaration_listContext)_localctx).text =  ((Declaration_listContext)_localctx).ID->getText() + "," + ((Declaration_listContext)_localctx).declaration_list.text;
				        ((Declaration_listContext)_localctx).line =  ((Declaration_listContext)_localctx).ADDOP->getLine();
				        _localctx.varList.push_back(std::make_pair(((Declaration_listContext)_localctx).ID->getText(), false));
				        for(auto var : ((Declaration_listContext)_localctx).declaration_list.varList) {
				            _localctx.varList.push_back(var);
				        }
				        writeIntoparserLogFile("Line " + std::to_string(_localctx.line) + ": declaration_list : ID\n\n" + ((Declaration_listContext)_localctx).ID->getText() + "\n");
				        writeIntoErrorFile("Error at line " + std::to_string(_localctx.line) + ": syntax error, unexpected ADDOP, expecting COMMA or SEMICOLON\n");
				        writeIntoparserLogFile("Error at line " + std::to_string(_localctx.line) + ": syntax error, unexpected ADDOP, expecting COMMA or SEMICOLON\n");
				        writeIntoparserLogFile("Line " + std::to_string(((Declaration_listContext)_localctx).declaration_list.line) + ": declaration_list : declaration_list COMMA ID\n\n" + _localctx.text + "\n");
				        
				}
				break;
			}
			_ctx.stop = _input.LT(-1);
			setState(220);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,12,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					setState(218);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,11,_ctx) ) {
					case 1:
						{
						_localctx = new Declaration_listContext(_parentctx, _parentState);
						_localctx.dl = _prevctx;
						pushNewRecursionContext(_localctx, _startState, RULE_declaration_list);
						setState(202);
						if (!(precpred(_ctx, 6))) throw new FailedPredicateException(this, "precpred(_ctx, 6)");
						setState(203);
						((Declaration_listContext)_localctx).COMMA = match(COMMA);
						setState(204);
						((Declaration_listContext)_localctx).ID = match(ID);
						 

						                  ((Declaration_listContext)_localctx).text =  ((Declaration_listContext)_localctx).dl.text + ((Declaration_listContext)_localctx).COMMA->getText() + ((Declaration_listContext)_localctx).ID->getText();
						                  ((Declaration_listContext)_localctx).line =  ((Declaration_listContext)_localctx).ID->getLine();

						                  ((Declaration_listContext)_localctx).varList =  ((Declaration_listContext)_localctx).dl.varList;
						          		_localctx.varList.push_back(std::make_pair(((Declaration_listContext)_localctx).ID->getText(), false));
						                  
						                  writeIntoparserLogFile("Line " + std::to_string(_localctx.line) + ": declaration_list : declaration_list COMMA ID\n\n" +_localctx.text + "\n");        

						              
						}
						break;
					case 2:
						{
						_localctx = new Declaration_listContext(_parentctx, _parentState);
						_localctx.dl = _prevctx;
						pushNewRecursionContext(_localctx, _startState, RULE_declaration_list);
						setState(206);
						if (!(precpred(_ctx, 5))) throw new FailedPredicateException(this, "precpred(_ctx, 5)");
						setState(207);
						((Declaration_listContext)_localctx).COMMA = match(COMMA);
						setState(208);
						((Declaration_listContext)_localctx).ID = match(ID);
						setState(209);
						((Declaration_listContext)_localctx).LTHIRD = match(LTHIRD);
						setState(210);
						((Declaration_listContext)_localctx).CONST_INT = match(CONST_INT);
						setState(211);
						((Declaration_listContext)_localctx).RTHIRD = match(RTHIRD);
						 
						                  ((Declaration_listContext)_localctx).text =  ((Declaration_listContext)_localctx).dl.text + ((Declaration_listContext)_localctx).COMMA->getText() + ((Declaration_listContext)_localctx).ID->getText() + ((Declaration_listContext)_localctx).LTHIRD->getText() + ((Declaration_listContext)_localctx).CONST_INT->getText() + ((Declaration_listContext)_localctx).RTHIRD->getText();
						                  ((Declaration_listContext)_localctx).line =  ((Declaration_listContext)_localctx).RTHIRD->getLine();
						                  ((Declaration_listContext)_localctx).varList =  ((Declaration_listContext)_localctx).dl.varList;
						          		_localctx.varList.push_back(std::make_pair(((Declaration_listContext)_localctx).ID->getText(), true));
						                  
						                  writeIntoparserLogFile("Line " + std::to_string(_localctx.line) + ": declaration_list : declaration_list COMMA ID LTHIRD CONST_INT RTHIRD\n\n" +_localctx.text + "\n");        

						              
						}
						break;
					case 3:
						{
						_localctx = new Declaration_listContext(_parentctx, _parentState);
						_localctx.dl = _prevctx;
						pushNewRecursionContext(_localctx, _startState, RULE_declaration_list);
						setState(213);
						if (!(precpred(_ctx, 4))) throw new FailedPredicateException(this, "precpred(_ctx, 4)");
						setState(214);
						((Declaration_listContext)_localctx).COMMA = match(COMMA);
						setState(215);
						((Declaration_listContext)_localctx).ID = match(ID);
						setState(216);
						((Declaration_listContext)_localctx).ADDOP = match(ADDOP);

						                  ((Declaration_listContext)_localctx).text =  ((Declaration_listContext)_localctx).dl.text + ((Declaration_listContext)_localctx).COMMA->getText() + ((Declaration_listContext)_localctx).ID->getText();
						                  ((Declaration_listContext)_localctx).line =  ((Declaration_listContext)_localctx).ADDOP->getLine();
						                  ((Declaration_listContext)_localctx).varList =  ((Declaration_listContext)_localctx).dl.varList;
						                  _localctx.varList.push_back(std::make_pair(((Declaration_listContext)_localctx).ID->getText(), false));
						                          std::cout<<"help"<<std::endl;

						                  writeIntoparserLogFile("Line " + std::to_string(_localctx.line) + ": declaration_list : declaration_list COMMA ID\n\n" +((Declaration_listContext)_localctx).dl.text + "\n");        

						                  writeIntoErrorFile("Error at line " + std::to_string(_localctx.line) + ": syntax error, unexpected ADDOP, expecting COMMA or SEMICOLON\n");
						                  writeIntoparserLogFile("Error at line " + std::to_string(_localctx.line) + ": syntax error, unexpected ADDOP, expecting COMMA or SEMICOLON\n");
						                  
						}
						break;
					}
					} 
				}
				setState(222);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,12,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class StatementsContext extends ParserRuleContext {
		public std::string text;
		public int line;
		public std::string type;
		public std::string code_section;
		public StatementsContext ss;
		public StatementContext s;
		public StatementContext statement() {
			return getRuleContext(StatementContext.class,0);
		}
		public StatementsContext statements() {
			return getRuleContext(StatementsContext.class,0);
		}
		public StatementsContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_statements; }
	}

	public final StatementsContext statements() throws RecognitionException {
		return statements(0);
	}

	private StatementsContext statements(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		StatementsContext _localctx = new StatementsContext(_ctx, _parentState);
		StatementsContext _prevctx = _localctx;
		int _startState = 22;
		enterRecursionRule(_localctx, 22, RULE_statements, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			{
			setState(224);
			((StatementsContext)_localctx).s = statement();

			        ((StatementsContext)_localctx).text =  ((StatementsContext)_localctx).s.text;
			        ((StatementsContext)_localctx).line =  ((StatementsContext)_localctx).s.line;
			        ((StatementsContext)_localctx).type =  ((StatementsContext)_localctx).s.type;
			        ((StatementsContext)_localctx).code_section =  ((StatementsContext)_localctx).s.code_section;
			                // std::cout << "s  type"<<((StatementsContext)_localctx).s.type <<std::endl;

			        writeIntoparserLogFile("Line " + std::to_string(_localctx.line) + ": statements : statement\n\n" + _localctx.text+"\n"); 
			    
			}
			_ctx.stop = _input.LT(-1);
			setState(233);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,13,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					{
					_localctx = new StatementsContext(_parentctx, _parentState);
					_localctx.ss = _prevctx;
					pushNewRecursionContext(_localctx, _startState, RULE_statements);
					setState(227);
					if (!(precpred(_ctx, 1))) throw new FailedPredicateException(this, "precpred(_ctx, 1)");
					setState(228);
					((StatementsContext)_localctx).s = statement();

					                  ((StatementsContext)_localctx).text =  ((StatementsContext)_localctx).ss.text +"\n" + ((StatementsContext)_localctx).s.text;
					                  ((StatementsContext)_localctx).line =  ((StatementsContext)_localctx).s.line;
					                  ((StatementsContext)_localctx).type =  ((StatementsContext)_localctx).s.type;
					                  ((StatementsContext)_localctx).code_section =  ((StatementsContext)_localctx).ss.code_section +  ((StatementsContext)_localctx).s.code_section;  
					                          // std::cout << "s  type"<<((StatementsContext)_localctx).s.type <<std::endl;

					                  writeIntoparserLogFile("Line " + std::to_string(_localctx.line) + ": statements : statements statement\n\n" +_localctx.text+"\n"); 

					              
					}
					} 
				}
				setState(235);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,13,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class StatementContext extends ParserRuleContext {
		public std::string text;
		public int line;
		public std::string type;
		public std::string code_section;
		public Var_declarationContext v;
		public Expression_statementContext es;
		public Compound_statementContext cs;
		public Token FOR;
		public Token LPAREN;
		public Expression_statementContext es1;
		public Expression_statementContext es2;
		public ExpressionContext e;
		public Token RPAREN;
		public StatementContext s;
		public Token IF;
		public StatementContext s1;
		public Token ELSE;
		public StatementContext s2;
		public Token WHILE;
		public Token PRINTLN;
		public Token ID;
		public Token SEMICOLON;
		public Token RETURN;
		public Var_declarationContext var_declaration() {
			return getRuleContext(Var_declarationContext.class,0);
		}
		public List<Expression_statementContext> expression_statement() {
			return getRuleContexts(Expression_statementContext.class);
		}
		public Expression_statementContext expression_statement(int i) {
			return getRuleContext(Expression_statementContext.class,i);
		}
		public Compound_statementContext compound_statement() {
			return getRuleContext(Compound_statementContext.class,0);
		}
		public TerminalNode FOR() { return getToken(C2105168Parser.FOR, 0); }
		public TerminalNode LPAREN() { return getToken(C2105168Parser.LPAREN, 0); }
		public TerminalNode RPAREN() { return getToken(C2105168Parser.RPAREN, 0); }
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public List<StatementContext> statement() {
			return getRuleContexts(StatementContext.class);
		}
		public StatementContext statement(int i) {
			return getRuleContext(StatementContext.class,i);
		}
		public TerminalNode IF() { return getToken(C2105168Parser.IF, 0); }
		public TerminalNode ELSE() { return getToken(C2105168Parser.ELSE, 0); }
		public TerminalNode WHILE() { return getToken(C2105168Parser.WHILE, 0); }
		public TerminalNode PRINTLN() { return getToken(C2105168Parser.PRINTLN, 0); }
		public TerminalNode ID() { return getToken(C2105168Parser.ID, 0); }
		public TerminalNode SEMICOLON() { return getToken(C2105168Parser.SEMICOLON, 0); }
		public TerminalNode RETURN() { return getToken(C2105168Parser.RETURN, 0); }
		public StatementContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_statement; }
	}

	public final StatementContext statement() throws RecognitionException {
		StatementContext _localctx = new StatementContext(_ctx, getState());
		enterRule(_localctx, 24, RULE_statement);
		try {
			setState(296);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,14,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(236);
				((StatementContext)_localctx).v = var_declaration();

				        ((StatementContext)_localctx).text =  ((StatementContext)_localctx).v.text;
				        ((StatementContext)_localctx).line =  ((StatementContext)_localctx).v.line;
				        std::cout << "DEBUG: unit var_declaration code_section = '" << _localctx.code_section << "'" << std::endl;
				        ((StatementContext)_localctx).type =  "void";
				        writeIntoparserLogFile("Line "+  std::to_string(_localctx.line) +": statement : var_declaration\n\n"+_localctx.text + "\n" );
				    
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(239);
				((StatementContext)_localctx).es = expression_statement();

				        ((StatementContext)_localctx).text =  ((StatementContext)_localctx).es.text;
				        ((StatementContext)_localctx).line =  ((StatementContext)_localctx).es.line;
				        ((StatementContext)_localctx).type =  "void";
				        writeIntoparserLogFile("Line "+  std::to_string(_localctx.line) +": statement : expression_statement\n\n"+_localctx.text + "\n" );

				    
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(242);
				((StatementContext)_localctx).cs = compound_statement();

				        ((StatementContext)_localctx).text =  ((StatementContext)_localctx).cs.text;
				        ((StatementContext)_localctx).line =  ((StatementContext)_localctx).cs.line;
				        ((StatementContext)_localctx).type =  ((StatementContext)_localctx).cs.type;
				        ((StatementContext)_localctx).type =  "void";

				        writeIntoparserLogFile("Line "+  std::to_string(_localctx.line) +": statement : compound_statement\n\n"+_localctx.text + "\n" );

				    
				}
				break;
			case 4:
				enterOuterAlt(_localctx, 4);
				{
				setState(245);
				((StatementContext)_localctx).FOR = match(FOR);
				setState(246);
				((StatementContext)_localctx).LPAREN = match(LPAREN);
				setState(247);
				((StatementContext)_localctx).es1 = expression_statement();


				    std::string loopStartLabel = std::to_string(label_count++);
				    std::string loopEndLabel = std::to_string(label_count++);
				    std::string loopUpdateLabel = std::to_string(label_count++);
				    
				    loopStartLabels.push_back(loopStartLabel);
				    loopEndLabels.push_back(loopEndLabel);
				    loopUpdateLabels.push_back(loopUpdateLabel);
				    
				    writeIntoAsmFile("L" + loopStartLabel + ":");
				    

				setState(249);
				((StatementContext)_localctx).es2 = expression_statement();

				    writeIntoAsmFile("\tPOP AX");
				    writeIntoAsmFile("\tCMP AX, 0");
				    writeIntoAsmFile("\tJE L" + loopEndLabels.back());
				    
				    std::string bodyLabel = std::to_string(label_count++);
				    writeIntoAsmFile("\tJMP L" + bodyLabel);
				    
				    writeIntoAsmFile("L" + loopUpdateLabels.back() + ":");
				    

				setState(251);
				((StatementContext)_localctx).e = expression();

				    if (((StatementContext)_localctx).e.text != "") {
				        writeIntoAsmFile("\tPOP AX"); 
				    }
				    
				    writeIntoAsmFile("\tJMP L" + loopStartLabels.back());
				    
				    writeIntoAsmFile("L" + bodyLabel + ":");
				    

				setState(253);
				((StatementContext)_localctx).RPAREN = match(RPAREN);
				setState(254);
				((StatementContext)_localctx).s = statement();

				    
				    writeIntoAsmFile("\tJMP L" + loopUpdateLabels.back());
				    
				    writeIntoAsmFile("L" + loopEndLabels.back() + ":");
				        loopStartLabels.pop_back();
				    loopEndLabels.pop_back();
				    loopUpdateLabels.pop_back();
				    
				    ((StatementContext)_localctx).text =  (((StatementContext)_localctx).FOR!=null?((StatementContext)_localctx).FOR.getText():null) + ((StatementContext)_localctx).LPAREN->getText() + ((StatementContext)_localctx).es1.text + ((StatementContext)_localctx).es2.text + ((StatementContext)_localctx).e.text + ((StatementContext)_localctx).RPAREN->getText() + ((StatementContext)_localctx).s.text;
				    ((StatementContext)_localctx).line =  ((StatementContext)_localctx).s.line;
				    ((StatementContext)_localctx).type =  "void";
				    
				    writeIntoparserLogFile("Line " + std::to_string(((StatementContext)_localctx).s.line) + ": statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement\n\n" + _localctx.text +"\n");

				}
				break;
			case 5:
				enterOuterAlt(_localctx, 5);
				{
				setState(257);
				((StatementContext)_localctx).IF = match(IF);
				setState(258);
				((StatementContext)_localctx).LPAREN = match(LPAREN);
				setState(259);
				((StatementContext)_localctx).e = expression();
				    
				        std::string elseLabel = std::to_string(label_count++);
				        elseStatements.push_back(elseLabel);

				        writeIntoAsmFile("\tPOP AX\n");
				        writeIntoAsmFile("\tCMP AX, 0\n");
				        writeIntoAsmFile("\tJE L" + elseLabel);


				        
				setState(261);
				((StatementContext)_localctx).RPAREN = match(RPAREN);
				setState(262);
				((StatementContext)_localctx).s = statement();


				        ((StatementContext)_localctx).text =  ((StatementContext)_localctx).IF->getText()+ ((StatementContext)_localctx).LPAREN->getText()+ ((StatementContext)_localctx).e.text  + ((StatementContext)_localctx).RPAREN->getText() +((StatementContext)_localctx).s.text;
				        ((StatementContext)_localctx).line =  ((StatementContext)_localctx).IF->getLine();
				        ((StatementContext)_localctx).type =  "void";

				        std::string exitLabel = std::to_string(label_count++);

				        exitLabels.push_back(exitLabel);

				        writeIntoAsmFile("\tJMP L" + exitLabel);
				        writeIntoAsmFile("L" +elseStatements.back() + ":");
				        elseStatements.pop_back();
				        writeIntoAsmFile("\tJMP L" + exitLabel);
				        writeIntoAsmFile("L" + exitLabel + ":");


				        writeIntoparserLogFile("Line " + std::to_string(_localctx.line) + ": statement : IF LPAREN expression RPAREN statement\n\n" + _localctx.text +"\n"); 

				    
				}
				break;
			case 6:
				enterOuterAlt(_localctx, 6);
				{
				setState(265);
				((StatementContext)_localctx).IF = match(IF);
				setState(266);
				((StatementContext)_localctx).LPAREN = match(LPAREN);
				setState(267);
				((StatementContext)_localctx).e = expression();


				        std::string elseLabel = std::to_string(label_count++);
				        elseStatements.push_back(elseLabel);

				        writeIntoAsmFile("\tPOP AX\n");
				        writeIntoAsmFile("\tCMP AX, 0\n");
				        writeIntoAsmFile("\tJE L" + elseLabel);



				    
				setState(269);
				((StatementContext)_localctx).RPAREN = match(RPAREN);
				setState(270);
				((StatementContext)_localctx).s1 = statement();
				  

				        std::string exitLabel = std::to_string(label_count++);

				        exitLabels.push_back(exitLabel);

				        writeIntoAsmFile("\tJMP L" + exitLabel);
				        writeIntoAsmFile("L" + elseStatements.back() + ":");
				        elseStatements.pop_back();
				        // writeIntoAsmFile("\tJMP L" + exitLabel);

				     
				setState(272);
				((StatementContext)_localctx).ELSE = match(ELSE);
				setState(273);
				((StatementContext)_localctx).s2 = statement();


				        ((StatementContext)_localctx).text =  ((StatementContext)_localctx).IF->getText() + ((StatementContext)_localctx).LPAREN->getText() + ((StatementContext)_localctx).e.text  + ((StatementContext)_localctx).RPAREN->getText() + ((StatementContext)_localctx).s1.text+ ((StatementContext)_localctx).ELSE->getText() +" "+  ((StatementContext)_localctx).s2.text ;
				       ((StatementContext)_localctx).line =  ((StatementContext)_localctx).IF->getLine();
				        ((StatementContext)_localctx).type =  "void";

				        writeIntoAsmFile("L" + exitLabels.back() + ":");
				        exitLabels.pop_back();


				        writeIntoparserLogFile("Line " + std::to_string(_localctx.line) + ": statement : IF LPAREN expression RPAREN statement ELSE statement\n\n" + _localctx.text +"\n"); 

				    
				}
				break;
			case 7:
				enterOuterAlt(_localctx, 7);
				{
				setState(276);
				((StatementContext)_localctx).WHILE = match(WHILE);

				    std::string loopStartLabel = std::to_string(label_count++);
				    std::string loopEndLabel = std::to_string(label_count++);
				    loopStartLabels.push_back(loopStartLabel);
				    loopEndLabels.push_back(loopEndLabel);
				    writeIntoAsmFile("L" + loopStartLabel + ":");

				setState(278);
				((StatementContext)_localctx).LPAREN = match(LPAREN);
				setState(279);
				((StatementContext)_localctx).e = expression();

				    writeIntoAsmFile("\tPOP AX");
				    writeIntoAsmFile("\tCMP AX, 0");
				    writeIntoAsmFile("\tJE L" + loopEndLabels.back());

				setState(281);
				((StatementContext)_localctx).RPAREN = match(RPAREN);
				setState(282);
				((StatementContext)_localctx).s = statement();

				    writeIntoAsmFile("\tJMP L" + loopStartLabels.back());
				    writeIntoAsmFile("L" + loopEndLabels.back() + ":");
				    loopStartLabels.pop_back();
				    loopEndLabels.pop_back();
				    
				    ((StatementContext)_localctx).text =  ((StatementContext)_localctx).WHILE->getText() + ((StatementContext)_localctx).LPAREN->getText() + ((StatementContext)_localctx).e.text + ((StatementContext)_localctx).RPAREN->getText() + ((StatementContext)_localctx).s.text;
				    ((StatementContext)_localctx).line =  ((StatementContext)_localctx).s.line;
				    ((StatementContext)_localctx).type =  "void";
				    writeIntoparserLogFile("Line " + std::to_string(_localctx.line) + ": statement : WHILE LPAREN expression RPAREN statement\n\n" + _localctx.text +"\n");

				}
				break;
			case 8:
				enterOuterAlt(_localctx, 8);
				{
				setState(285);
				((StatementContext)_localctx).PRINTLN = match(PRINTLN);
				setState(286);
				((StatementContext)_localctx).LPAREN = match(LPAREN);
				setState(287);
				((StatementContext)_localctx).ID = match(ID);
				setState(288);
				((StatementContext)_localctx).RPAREN = match(RPAREN);
				setState(289);
				((StatementContext)_localctx).SEMICOLON = match(SEMICOLON);


				        ((StatementContext)_localctx).text =  ((StatementContext)_localctx).PRINTLN->getText() + ((StatementContext)_localctx).LPAREN->getText() +  ((StatementContext)_localctx).ID->getText() +  ((StatementContext)_localctx).RPAREN->getText() +  ((StatementContext)_localctx).SEMICOLON->getText();
				        ((StatementContext)_localctx).line =  ((StatementContext)_localctx).SEMICOLON->getLine();

				        ((StatementContext)_localctx).type =  "void";

				        SymbolInfo* lookup = symbolTable->LookUP(((StatementContext)_localctx).ID->getText());
				        SymbolInfo* existing = symbolTable->LookUP(((StatementContext)_localctx).ID->getText());
				            std::string currentScopeId = symbolTable->getCurrentScopeID();
				            if(existing->getIsGlobal()){
				                ((StatementContext)_localctx).code_section =  "\tMOV AX, "+ ((StatementContext)_localctx).ID->getText();
				            } else {
				                ((StatementContext)_localctx).code_section =  "\tMOV AX, [BP-" + std::to_string(existing->getStackOffset()) + "]";
				            }

				        writeIntoAsmFile("L" + std::to_string(label_count++)+":");
				        writeIntoAsmFile(_localctx.code_section+"       ; Line "+std::to_string(_localctx.line));
				        writeIntoAsmFile("\tCALL print_output");
				        writeIntoAsmFile("\tCALL new_line");

				        writeIntoparserLogFile("Line " + std::to_string(_localctx.line) + ": statement : PRINTLN LPAREN ID RPAREN SEMICOLON\n"); 
				        if(lookup == nullptr){
				                writeIntoErrorFile("Error at line " + std::to_string(_localctx.line) + ": Undeclared variable " +((StatementContext)_localctx).ID->getText() + "\n");  
				                writeIntoparserLogFile("Error at line " + std::to_string(_localctx.line) + ": Undeclared variable " + ((StatementContext)_localctx).ID->getText() + "\n\n" +_localctx.text+"\n");
				                                errorCount++;
				        }

				    
				}
				break;
			case 9:
				enterOuterAlt(_localctx, 9);
				{
				setState(291);
				((StatementContext)_localctx).RETURN = match(RETURN);
				setState(292);
				((StatementContext)_localctx).e = expression();
				setState(293);
				((StatementContext)_localctx).SEMICOLON = match(SEMICOLON);

				        ((StatementContext)_localctx).text =  ((StatementContext)_localctx).RETURN->getText() + " " + ((StatementContext)_localctx).e.text + ((StatementContext)_localctx).SEMICOLON->getText();
				        ((StatementContext)_localctx).line =  ((StatementContext)_localctx).RETURN->getLine();
				        
				        ((StatementContext)_localctx).type =  ((StatementContext)_localctx).e.type;


				        if(_localctx.type != "void" && ((StatementContext)_localctx).e.text != "0"){


				        }



				        SymbolInfo* lookup = symbolTable->LookUP(((StatementContext)_localctx).e.text);


				        writeIntoparserLogFile("Line " + std::to_string(((StatementContext)_localctx).SEMICOLON->getLine()) + ": statement : RETURN expression SEMICOLON\n\n" + ((StatementContext)_localctx).RETURN->getText() +" "+ ((StatementContext)_localctx).e.text+ ((StatementContext)_localctx).SEMICOLON->getText() +"\n"); 

				      
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Expression_statementContext extends ParserRuleContext {
		public std::string text;
		public int line;
		public std::string code_section;
		public Token SEMICOLON;
		public ExpressionContext e;
		public TerminalNode SEMICOLON() { return getToken(C2105168Parser.SEMICOLON, 0); }
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public Expression_statementContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_expression_statement; }
	}

	public final Expression_statementContext expression_statement() throws RecognitionException {
		Expression_statementContext _localctx = new Expression_statementContext(_ctx, getState());
		enterRule(_localctx, 26, RULE_expression_statement);
		try {
			setState(304);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case SEMICOLON:
				enterOuterAlt(_localctx, 1);
				{
				setState(298);
				((Expression_statementContext)_localctx).SEMICOLON = match(SEMICOLON);

				        ((Expression_statementContext)_localctx).text =  ((Expression_statementContext)_localctx).SEMICOLON->getText();
				        ((Expression_statementContext)_localctx).line =  ((Expression_statementContext)_localctx).SEMICOLON->getLine();
				        writeIntoparserLogFile("Line " + std::to_string(((Expression_statementContext)_localctx).SEMICOLON->getLine()) + ": expression_statement : SEMICOLON\n\n" + _localctx.text +"\n"); 

				    
				}
				break;
			case LPAREN:
			case ADDOP:
			case NOT:
			case ID:
			case CONST_INT:
			case CONST_FLOAT:
				enterOuterAlt(_localctx, 2);
				{
				setState(300);
				((Expression_statementContext)_localctx).e = expression();
				setState(301);
				((Expression_statementContext)_localctx).SEMICOLON = match(SEMICOLON);

				        ((Expression_statementContext)_localctx).text =  ((Expression_statementContext)_localctx).e.text + ((Expression_statementContext)_localctx).SEMICOLON->getText();
				        ((Expression_statementContext)_localctx).line =  ((Expression_statementContext)_localctx).SEMICOLON->getLine();
				        ((Expression_statementContext)_localctx).code_section =  ((Expression_statementContext)_localctx).e.code_section;
				        writeIntoparserLogFile("Line " + std::to_string(((Expression_statementContext)_localctx).SEMICOLON->getLine()) + ": expression_statement : expression SEMICOLON\n\n" + _localctx.text +"\n"); 

				    
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class VariableContext extends ParserRuleContext {
		public std::string text;
		public int line;
		public std::string type;
		public bool isArray;
		public std::string code_section;
		public Token ID;
		public Token LTHIRD;
		public ExpressionContext e;
		public Token RTHIRD;
		public TerminalNode ID() { return getToken(C2105168Parser.ID, 0); }
		public TerminalNode LTHIRD() { return getToken(C2105168Parser.LTHIRD, 0); }
		public TerminalNode RTHIRD() { return getToken(C2105168Parser.RTHIRD, 0); }
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public VariableContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_variable; }
	}

	public final VariableContext variable() throws RecognitionException {
		VariableContext _localctx = new VariableContext(_ctx, getState());
		enterRule(_localctx, 28, RULE_variable);
		try {
			setState(314);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,16,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(306);
				((VariableContext)_localctx).ID = match(ID);

				        ((VariableContext)_localctx).text =  ((VariableContext)_localctx).ID->getText();
				        ((VariableContext)_localctx).line =  ((VariableContext)_localctx).ID->getLine();
				        ((VariableContext)_localctx).type =  "int";
				        SymbolInfo* lookup = symbolTable->LookUP(((VariableContext)_localctx).ID->getText());

				            if(lookup && lookup->getIsArray()){
				                ((VariableContext)_localctx).type =  "array";
				                ((VariableContext)_localctx).isArray =  true;
				            }
				            else if (lookup){
				                ((VariableContext)_localctx).type =  lookup->getSymbolDataType();

				            }
				            if (lookup == nullptr) {
				                        writeIntoparserLogFile("Line " + std::to_string(((VariableContext)_localctx).ID->getLine()) + ": variable : ID\n"); 

				                writeIntoErrorFile("Error at line " + std::to_string(_localctx.line) + ": Undeclared variable " +((VariableContext)_localctx).ID->getText() + "\n");  
				                writeIntoparserLogFile("Error at line " + std::to_string(_localctx.line) + ": Undeclared variable " + ((VariableContext)_localctx).ID->getText() + "\n\n" +((VariableContext)_localctx).ID->getText()+"\n");
				                                errorCount++;

				            }

				            else{  
				            writeIntoparserLogFile("Line " + std::to_string(((VariableContext)_localctx).ID->getLine()) + ": variable : ID\n\n"+((VariableContext)_localctx).ID->getText()+"\n"); 

				            }
				                // std::cout << "ID type: " << _localctx.type <<"for "<< ((VariableContext)_localctx).ID->getText() << std::endl;
				                // if (lookup)
				                // std::cout << "DEBUG: " << lookup->getSymbolName() << " has type: " << lookup->getType() << std::endl;
				                //                 std::cout << "DEBUG: " << lookup->getSymbolName() << " has type: " << lookup->getSymbolDataType() << std::endl;

				                std::cout << "DEBUG: inside variable " << lookup->getSymbolName() << " stack offset: " << lookup->getStackOffset() <<" "<< isParamsymbol << std::endl;
				        
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(308);
				((VariableContext)_localctx).ID = match(ID);
				setState(309);
				((VariableContext)_localctx).LTHIRD = match(LTHIRD);
				setState(310);
				((VariableContext)_localctx).e = expression();
				setState(311);
				((VariableContext)_localctx).RTHIRD = match(RTHIRD);
				 
				        ((VariableContext)_localctx).text =  ((VariableContext)_localctx).ID->getText() + ((VariableContext)_localctx).LTHIRD->getText() + ((VariableContext)_localctx).e.text + ((VariableContext)_localctx).RTHIRD->getText();
				        ((VariableContext)_localctx).line =  ((VariableContext)_localctx).RTHIRD->getLine();
				        ((VariableContext)_localctx).type =  ((VariableContext)_localctx).e.type;
				        if (_localctx.type != "int"){  
				            writeIntoErrorFile("Error at line "+std::to_string(_localctx.line)+": Expression inside third brackets not an integer\n");

				            writeIntoparserLogFile("Line " + std::to_string(_localctx.line) + ": variable : ID LTHIRD expression RTHIRD" +"\n"); 

				            writeIntoparserLogFile("Error at line "+std::to_string(_localctx.line)+": Expression inside third brackets not an integer\n\n"+_localctx.text +"\n");
				                            errorCount++;



				        }
				        else{
				        writeIntoparserLogFile("Line " + std::to_string(_localctx.line) + ": variable : ID LTHIRD expression RTHIRD\n\n"+_localctx.text+"\n"); 

				        }

				    
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ExpressionContext extends ParserRuleContext {
		public std::string text;
		public int line;
		public std::string type;
		public bool argIsArray;
		public std::string code_section;
		public Logic_expressionContext l;
		public VariableContext v;
		public Token ASSIGNOP;
		public Logic_expressionContext le;
		public Logic_expressionContext logic_expression() {
			return getRuleContext(Logic_expressionContext.class,0);
		}
		public TerminalNode ASSIGNOP() { return getToken(C2105168Parser.ASSIGNOP, 0); }
		public VariableContext variable() {
			return getRuleContext(VariableContext.class,0);
		}
		public ExpressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_expression; }
	}

	public final ExpressionContext expression() throws RecognitionException {
		ExpressionContext _localctx = new ExpressionContext(_ctx, getState());
		enterRule(_localctx, 30, RULE_expression);
		try {
			setState(324);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,17,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(316);
				((ExpressionContext)_localctx).l = logic_expression();

				            ((ExpressionContext)_localctx).text = ((ExpressionContext)_localctx).l.text;
				            ((ExpressionContext)_localctx).line = ((ExpressionContext)_localctx).l.line;
				            ((ExpressionContext)_localctx).type =  ((ExpressionContext)_localctx).l.type;
				               ((ExpressionContext)_localctx).argIsArray =  false;
				            ((ExpressionContext)_localctx).code_section =  ((ExpressionContext)_localctx).l.code_section;
				            // std::cout << "l type"<<((ExpressionContext)_localctx).l.type <<std::endl;

				            writeIntoparserLogFile("Line "+  std::to_string(((ExpressionContext)_localctx).l.line)+": expression : logic_expression\n\n" + ((ExpressionContext)_localctx).l.text + "\n"); 
				        
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(319);
				((ExpressionContext)_localctx).v = variable();
				setState(320);
				((ExpressionContext)_localctx).ASSIGNOP = match(ASSIGNOP);
				setState(321);
				((ExpressionContext)_localctx).le = logic_expression();

				            ((ExpressionContext)_localctx).text =  ((ExpressionContext)_localctx).v.text + ((ExpressionContext)_localctx).ASSIGNOP->getText() + ((ExpressionContext)_localctx).le.text;
				            ((ExpressionContext)_localctx).line = ((ExpressionContext)_localctx).le.line;  
				            ((ExpressionContext)_localctx).type =  ((ExpressionContext)_localctx).le.type;
				            ((ExpressionContext)_localctx).argIsArray =  false;

				            SymbolInfo* existing = symbolTable->LookUP(((ExpressionContext)_localctx).v.text);
				            std::string currentScopeId = symbolTable->getCurrentScopeID();
				            if(existing->getIsGlobal() && !isInsideFunctionDefinition ){
				                ((ExpressionContext)_localctx).code_section =  "\tMOV " + ((ExpressionContext)_localctx).v.text + ", AX";
				                
				            }
				             else if(!existing->getIsGlobal() && !isInsideFunctionDefinition && !isParamsymbol){

				                ((ExpressionContext)_localctx).code_section =  "\tMOV [BP-" + std::to_string(existing->getStackOffset()) + "], AX";
				            }
				            
				           else if(!existing->getIsGlobal() && isInsideFunctionDefinition && isParamsymbol){    
				                ((ExpressionContext)_localctx).code_section =  "\tMOV [BP+" + std::to_string(existing->getStackOffset()) + "], AX";

				            }

				            else if(existing->getIsGlobal() && isInsideFunctionDefinition ){   

				                ((ExpressionContext)_localctx).code_section =  "\tMOV " + ((ExpressionContext)_localctx).v.text + ", AX";
				            }



				          //  writeIntoAsmFile("\tPOP1 AX");

				            writeIntoAsmFile(_localctx.code_section);


				            
				            std::cout << "DEBUG: expression code_section = '" << _localctx.code_section << "'" << std::endl;
				            SymbolInfo* lookup = symbolTable->LookUP(((ExpressionContext)_localctx).v.text);



				            if (lookup && ((ExpressionContext)_localctx).v.type != _localctx.type) {
				            
				            writeIntoparserLogFile("Line "+  std::to_string(_localctx.line)+": expression : variable ASSIGNOP logic_expression\n"); 

				            if(lookup->getIsArray()){
				                writeIntoErrorFile("Error at line " + std::to_string(_localctx.line) + ": Type mismatch, "+((ExpressionContext)_localctx).v.text+" is an array\n");
				                writeIntoparserLogFile("Error at line " + std::to_string(_localctx.line) + ": Type Mismatch, "+((ExpressionContext)_localctx).v.text+"  is an array\n");
				                                errorCount++;


				            } else {

				                writeIntoErrorFile("Error at line " + std::to_string(_localctx.line) + ": Type Mismatch\n");  

				            writeIntoparserLogFile("Error at line " + std::to_string(_localctx.line) + ": Type Mismatch\n\n"+_localctx.text+"\n");
				                            errorCount++;

				             }


				            }

				            else{            
				                writeIntoparserLogFile("Line "+  std::to_string(_localctx.line)+": expression : variable ASSIGNOP logic_expression\n\n"+_localctx.text+"\n"); 
				            }

				            

				       
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Logic_expressionContext extends ParserRuleContext {
		public std::string text;
		public int line;
		public std::string type;
		public bool argIsArr;
		public std::string code_section;
		public Rel_expressionContext r;
		public Rel_expressionContext re1;
		public Token LOGICOP;
		public Rel_expressionContext re2;
		public List<Rel_expressionContext> rel_expression() {
			return getRuleContexts(Rel_expressionContext.class);
		}
		public Rel_expressionContext rel_expression(int i) {
			return getRuleContext(Rel_expressionContext.class,i);
		}
		public TerminalNode LOGICOP() { return getToken(C2105168Parser.LOGICOP, 0); }
		public Logic_expressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_logic_expression; }
	}

	public final Logic_expressionContext logic_expression() throws RecognitionException {
		Logic_expressionContext _localctx = new Logic_expressionContext(_ctx, getState());
		enterRule(_localctx, 32, RULE_logic_expression);
		try {
			setState(334);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,18,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(326);
				((Logic_expressionContext)_localctx).r = rel_expression();

				            ((Logic_expressionContext)_localctx).text =  ((Logic_expressionContext)_localctx).r.text;
				            ((Logic_expressionContext)_localctx).line =  ((Logic_expressionContext)_localctx).r.line;
				            ((Logic_expressionContext)_localctx).type =  ((Logic_expressionContext)_localctx).r.type;
				            ((Logic_expressionContext)_localctx).argIsArr =  ((Logic_expressionContext)_localctx).r.argIsArray;
				            // std::cout << "r  type"<<((Logic_expressionContext)_localctx).r.type <<std::endl;

				            writeIntoparserLogFile("Line "+  std::to_string(((Logic_expressionContext)_localctx).r.line)+": logic_expression : rel_expression\n\n" + ((Logic_expressionContext)_localctx).r.text + "\n"); 

				        
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(329);
				((Logic_expressionContext)_localctx).re1 = rel_expression();
				setState(330);
				((Logic_expressionContext)_localctx).LOGICOP = match(LOGICOP);
				setState(331);
				((Logic_expressionContext)_localctx).re2 = rel_expression();

				            ((Logic_expressionContext)_localctx).text =  ((Logic_expressionContext)_localctx).re1.text+((Logic_expressionContext)_localctx).LOGICOP->getText() + ((Logic_expressionContext)_localctx).re2.text;
				            ((Logic_expressionContext)_localctx).line =  ((Logic_expressionContext)_localctx).re2.line;
				            ((Logic_expressionContext)_localctx).type =  ((Logic_expressionContext)_localctx).re2.type;
				            ((Logic_expressionContext)_localctx).argIsArr =  false;
				            int labelEnd = 0;

				         writeIntoAsmFile("\tPOP DX");  
				          writeIntoAsmFile("\tPOP AX");  
				    
				    if (((Logic_expressionContext)_localctx).LOGICOP->getText() == "&&") {
				        int labelFalse = label_count++;
				        labelEnd = label_count++;
				        
				        writeIntoAsmFile("\tCMP AX, 0\n\tJE L" + std::to_string(labelFalse));  
				        writeIntoAsmFile("\tCMP DX, 0\n\tJE L" + std::to_string(labelFalse));  
				        
				        writeIntoAsmFile("\tMOV AX, 1\n\tJMP L" + std::to_string(labelEnd));
				        
				        writeIntoAsmFile("L" + std::to_string(labelFalse) + ":");
				        writeIntoAsmFile("\tMOV AX, 0");
				        
				    } else if (((Logic_expressionContext)_localctx).LOGICOP->getText() == "||") {
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
				            writeIntoparserLogFile("Line "+  std::to_string(_localctx.line)+": logic_expression : rel_expression LOGICOP rel_expression\n\n" + _localctx.text + "\n"); 

				        
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Rel_expressionContext extends ParserRuleContext {
		public std::string text;
		public int line;
		public std::string type;
		public bool argIsArray;
		public std::string code_section;
		public Simple_expressionContext s;
		public Simple_expressionContext s1;
		public Token RELOP;
		public Simple_expressionContext s2;
		public List<Simple_expressionContext> simple_expression() {
			return getRuleContexts(Simple_expressionContext.class);
		}
		public Simple_expressionContext simple_expression(int i) {
			return getRuleContext(Simple_expressionContext.class,i);
		}
		public TerminalNode RELOP() { return getToken(C2105168Parser.RELOP, 0); }
		public Rel_expressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_rel_expression; }
	}

	public final Rel_expressionContext rel_expression() throws RecognitionException {
		Rel_expressionContext _localctx = new Rel_expressionContext(_ctx, getState());
		enterRule(_localctx, 34, RULE_rel_expression);
		try {
			setState(344);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,19,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(336);
				((Rel_expressionContext)_localctx).s = simple_expression(0);

				            ((Rel_expressionContext)_localctx).text =  ((Rel_expressionContext)_localctx).s.text;
				            ((Rel_expressionContext)_localctx).line =  ((Rel_expressionContext)_localctx).s.line;
				            ((Rel_expressionContext)_localctx).type =  ((Rel_expressionContext)_localctx).s.type;
				            ((Rel_expressionContext)_localctx).argIsArray =  ((Rel_expressionContext)_localctx).s.argIsArray;
				            // std::cout << "s type"<<((Rel_expressionContext)_localctx).s.type <<std::endl;
				            writeIntoparserLogFile("Line "+  std::to_string(((Rel_expressionContext)_localctx).s.line)+": rel_expression : simple_expression\n\n" + ((Rel_expressionContext)_localctx).s.text + "\n"); 
				            
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(339);
				((Rel_expressionContext)_localctx).s1 = simple_expression(0);
				setState(340);
				((Rel_expressionContext)_localctx).RELOP = match(RELOP);
				setState(341);
				((Rel_expressionContext)_localctx).s2 = simple_expression(0);

				            ((Rel_expressionContext)_localctx).text =  ((Rel_expressionContext)_localctx).s1.text + ((Rel_expressionContext)_localctx).RELOP->getText() + ((Rel_expressionContext)_localctx).s2.text;
				            ((Rel_expressionContext)_localctx).line =  ((Rel_expressionContext)_localctx).RELOP->getLine();
				            ((Rel_expressionContext)_localctx).type =  ((Rel_expressionContext)_localctx).s2.type;
				            ((Rel_expressionContext)_localctx).argIsArray =  false;
				            int labelEnd = 0;

				            writeIntoAsmFile("\tPOP DX");
				            writeIntoAsmFile("\tPOP AX");
				            if (((Rel_expressionContext)_localctx).RELOP->getText() == "==") {
				                int labelTrue = label_count++;
				                int labelFalse = label_count++;
				                labelEnd = label_count++;
				                writeIntoAsmFile("\tCMP AX, DX\n\tJE L" + std::to_string(labelTrue));
				                writeIntoAsmFile("\tJMP L" + std::to_string(labelFalse));
				                writeIntoAsmFile("L" + std::to_string(labelTrue) + ":");
				                writeIntoAsmFile("\tMOV AX, 1\n\tJMP L" + std::to_string(labelEnd));
				                writeIntoAsmFile("L" + std::to_string(labelFalse) + ":");
				                writeIntoAsmFile("\tMOV AX, 0");

				            } else if (((Rel_expressionContext)_localctx).RELOP->getText() == "!=") {
				                int labelTrue = label_count++;
				                int labelFalse = label_count++;
				                labelEnd = label_count++;
				                writeIntoAsmFile("\tCMP AX, DX\n\tJNE L" + std::to_string(labelTrue));
				                writeIntoAsmFile("\tJMP L" + std::to_string(labelFalse));
				                writeIntoAsmFile("L" + std::to_string(labelTrue) + ":");
				                writeIntoAsmFile("\tMOV AX, 1\n\tJMP L" + std::to_string(labelEnd));
				                writeIntoAsmFile("L" + std::to_string(labelFalse) + ":");
				                writeIntoAsmFile("\tMOV AX, 0");
				              } else if (((Rel_expressionContext)_localctx).RELOP->getText() == "<") {
				                int labelTrue = label_count++;
				                int labelFalse = label_count++;
				                labelEnd = label_count++;
				                writeIntoAsmFile("\tCMP AX, DX\n\tJL L" + std::to_string(labelTrue));
				                writeIntoAsmFile("\tJMP L" + std::to_string(labelFalse));
				                writeIntoAsmFile("L" + std::to_string(labelTrue) + ":");
				                writeIntoAsmFile("\tMOV AX, 1\n\tJMP L" + std::to_string(labelEnd));
				                writeIntoAsmFile("L" + std::to_string(labelFalse) + ":");
				                writeIntoAsmFile("\tMOV AX, 0");
				            } else if (((Rel_expressionContext)_localctx).RELOP->getText() == ">") {
				                int labelTrue = label_count++;
				                int labelFalse = label_count++;
				                labelEnd = label_count++;
				                writeIntoAsmFile("\tCMP AX, DX\n\tJG L" + std::to_string(labelTrue));
				                writeIntoAsmFile("\tJMP L" + std::to_string(labelFalse));
				                writeIntoAsmFile("L" + std::to_string(labelTrue) + ":");
				                writeIntoAsmFile("\tMOV AX, 1\n\tJMP L" + std::to_string(labelEnd));
				                writeIntoAsmFile("L" + std::to_string(labelFalse) + ":");
				                writeIntoAsmFile("\tMOV AX, 0");
				            } else if (((Rel_expressionContext)_localctx).RELOP->getText() == "<=") {
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
				            else if (((Rel_expressionContext)_localctx).RELOP->getText() == ">=") {
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

				            // std::cout << "s2 type"<<((Rel_expressionContext)_localctx).s2.type <<std::endl;
				            writeIntoparserLogFile("Line "+  std::to_string(_localctx.line)+": rel_expression : simple_expression RELOP simple_expression\n\n" + _localctx.text + "\n"); 

				        
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Simple_expressionContext extends ParserRuleContext {
		public std::string text;
		public int line;
		public std::string type;
		public bool argIsArray;
		public std::string code_section;
		public Simple_expressionContext s;
		public TermContext t;
		public Token ADDOP;
		public TermContext term() {
			return getRuleContext(TermContext.class,0);
		}
		public TerminalNode ADDOP() { return getToken(C2105168Parser.ADDOP, 0); }
		public Simple_expressionContext simple_expression() {
			return getRuleContext(Simple_expressionContext.class,0);
		}
		public Simple_expressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_simple_expression; }
	}

	public final Simple_expressionContext simple_expression() throws RecognitionException {
		return simple_expression(0);
	}

	private Simple_expressionContext simple_expression(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		Simple_expressionContext _localctx = new Simple_expressionContext(_ctx, _parentState);
		Simple_expressionContext _prevctx = _localctx;
		int _startState = 36;
		enterRecursionRule(_localctx, 36, RULE_simple_expression, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			{
			setState(347);
			((Simple_expressionContext)_localctx).t = term(0);

			            ((Simple_expressionContext)_localctx).text =  ((Simple_expressionContext)_localctx).t.text;
			            ((Simple_expressionContext)_localctx).line =  ((Simple_expressionContext)_localctx).t.line;
			            ((Simple_expressionContext)_localctx).type =  ((Simple_expressionContext)_localctx).t.type;
			            ((Simple_expressionContext)_localctx).argIsArray =  ((Simple_expressionContext)_localctx).t.argIsArray;



			            writeIntoparserLogFile("Line "+  std::to_string(((Simple_expressionContext)_localctx).t.line)+": simple_expression : term\n\n" + ((Simple_expressionContext)_localctx).t.text + "\n"); 
			            
			}
			_ctx.stop = _input.LT(-1);
			setState(357);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,20,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					{
					_localctx = new Simple_expressionContext(_parentctx, _parentState);
					_localctx.s = _prevctx;
					pushNewRecursionContext(_localctx, _startState, RULE_simple_expression);
					setState(350);
					if (!(precpred(_ctx, 1))) throw new FailedPredicateException(this, "precpred(_ctx, 1)");
					setState(351);
					((Simple_expressionContext)_localctx).ADDOP = match(ADDOP);
					setState(352);
					((Simple_expressionContext)_localctx).t = term(0);

					                      ((Simple_expressionContext)_localctx).text =  ((Simple_expressionContext)_localctx).s.text+((Simple_expressionContext)_localctx).ADDOP->getText()+((Simple_expressionContext)_localctx).t.text;
					                      ((Simple_expressionContext)_localctx).line =  ((Simple_expressionContext)_localctx).t.line;
					                      ((Simple_expressionContext)_localctx).argIsArray =  false;
					                      if (((Simple_expressionContext)_localctx).s.type == "float" || ((Simple_expressionContext)_localctx).t.type == "float") {
					                          ((Simple_expressionContext)_localctx).type =  "float";
					                      } else {
					                           ((Simple_expressionContext)_localctx).type =  "int";
					                      }

					                      writeIntoAsmFile("\tPOP DX");
					                      writeIntoAsmFile("\tPOP AX");

					                      if (((Simple_expressionContext)_localctx).ADDOP->getText() == "+") {

					                          ((Simple_expressionContext)_localctx).code_section =  "\tADD AX, DX\n\tPUSH AX"    ;
					                      } else if (((Simple_expressionContext)_localctx).ADDOP->getText() == "-") {
					                          ((Simple_expressionContext)_localctx).code_section =  "\tSUB AX, DX\n\tPUSH AX\n";
					                      }

					                      writeIntoAsmFile(_localctx.code_section);
					                      writeIntoparserLogFile("Line "+  std::to_string(_localctx.line)+": simple_expression : simple_expression ADDOP term\n\n" + _localctx.text + "\n"); 

					                    
					}
					} 
				}
				setState(359);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,20,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class TermContext extends ParserRuleContext {
		public std::string text;
		public int line;
		public std::string type;
		public bool argIsArray;
		public std::string code_section;
		public TermContext t;
		public Unary_expressionContext u;
		public Token MULOP;
		public Unary_expressionContext ue;
		public Unary_expressionContext unary_expression() {
			return getRuleContext(Unary_expressionContext.class,0);
		}
		public TerminalNode MULOP() { return getToken(C2105168Parser.MULOP, 0); }
		public TermContext term() {
			return getRuleContext(TermContext.class,0);
		}
		public TermContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_term; }
	}

	public final TermContext term() throws RecognitionException {
		return term(0);
	}

	private TermContext term(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		TermContext _localctx = new TermContext(_ctx, _parentState);
		TermContext _prevctx = _localctx;
		int _startState = 38;
		enterRecursionRule(_localctx, 38, RULE_term, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			{
			setState(361);
			((TermContext)_localctx).u = unary_expression();

			         
			            ((TermContext)_localctx).text =  ((TermContext)_localctx).u.text;
			            ((TermContext)_localctx).line =  ((TermContext)_localctx).u.line;
			            ((TermContext)_localctx).type =  ((TermContext)_localctx).u.type;
			           ((TermContext)_localctx).argIsArray =  ((TermContext)_localctx).u.argIsArray; 
			            writeIntoparserLogFile("Line "+  std::to_string(((TermContext)_localctx).u.line)+": term : unary_expression\n\n" + ((TermContext)_localctx).u.text + "\n");
			            
			}
			_ctx.stop = _input.LT(-1);
			setState(371);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,21,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					{
					_localctx = new TermContext(_parentctx, _parentState);
					_localctx.t = _prevctx;
					pushNewRecursionContext(_localctx, _startState, RULE_term);
					setState(364);
					if (!(precpred(_ctx, 1))) throw new FailedPredicateException(this, "precpred(_ctx, 1)");
					setState(365);
					((TermContext)_localctx).MULOP = match(MULOP);
					setState(366);
					((TermContext)_localctx).ue = unary_expression();

					              ((TermContext)_localctx).text =  ((TermContext)_localctx).t.text + ((TermContext)_localctx).MULOP->getText() + ((TermContext)_localctx).ue.text;
					              ((TermContext)_localctx).line =  ((TermContext)_localctx).ue.line;
					              bool print = true;
					              bool zeroprint = false;
					              if (((TermContext)_localctx).MULOP->getText() == "%") {
					                  if (((TermContext)_localctx).t.type != "int" || ((TermContext)_localctx).ue.type != "int") {
					                      writeIntoErrorFile("Error at line " + std::to_string(_localctx.line) + ": Non-Integer operand on modulus operator\n");
					                      writeIntoparserLogFile("Line " + std::to_string(_localctx.line) + ": term : term MULOP unary_expression\n");
					                      writeIntoparserLogFile("Error at line " + std::to_string(_localctx.line) + ": Non-Integer operand on modulus operator\n\n" + _localctx.text + "\n");
					                                      errorCount++;
					                      print = false;
					                  }
					                  else if(((TermContext)_localctx).ue.text == "0"){
					                      zeroprint = true;
					                      errorCount++;
					                  }
					               
					                  ((TermContext)_localctx).type =  "int"; 
					              } else {
					                  if (((TermContext)_localctx).t.type == "float" || ((TermContext)_localctx).ue.type == "float") {
					                      ((TermContext)_localctx).type =  "float";
					                  } else {
					                      ((TermContext)_localctx).type =  "int";
					                  }
					              }
					              if(print && zeroprint == false){
					              writeIntoparserLogFile("Line " + std::to_string(_localctx.line) + ": term : term MULOP unary_expression\n\n" + _localctx.text + "\n");
					              }  

					              if(zeroprint){
					                       writeIntoErrorFile("Error at line " + std::to_string(_localctx.line) + ": Modulus by Zero\n");
					              writeIntoparserLogFile("Line " + std::to_string(_localctx.line) + ": term : term MULOP unary_expression\n");

					                      writeIntoparserLogFile("Error at line " + std::to_string(_localctx.line) + ": Modulus by Zero\n\n" + _localctx.text + "\n");
					              }

					              

					            

					              if (((TermContext)_localctx).MULOP->getText() == "*") {
					                  writeIntoAsmFile("\tPOP DX");
					                  writeIntoAsmFile("\tPOP AX"); 
					                  ((TermContext)_localctx).code_section =  "\tMUL DX\n\tPUSH AX";
					              } else if (((TermContext)_localctx).MULOP->getText() == "/") {
					                  ((TermContext)_localctx).code_section =  "\tXCHG AX, DX\n\tDIV DX\n\tPUSH AX";
					              } else if (((TermContext)_localctx).MULOP->getText() == "%") {
					                  writeIntoAsmFile("\tPOP CX");
					                  writeIntoAsmFile("\tPOP AX");
					                  ((TermContext)_localctx).code_section =  "\tCWD\n\tDIV CX\n\tPUSH DX";
					              }
					              writeIntoAsmFile(_localctx.code_section);
					          
					}
					} 
				}
				setState(373);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,21,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Unary_expressionContext extends ParserRuleContext {
		public std::string text;
		public int line;
		public std::string type;
		public bool argIsArray;
		public std::string code_section;
		public Token ADDOP;
		public Unary_expressionContext ue;
		public Token NOT;
		public FactorContext f;
		public TerminalNode ADDOP() { return getToken(C2105168Parser.ADDOP, 0); }
		public Unary_expressionContext unary_expression() {
			return getRuleContext(Unary_expressionContext.class,0);
		}
		public TerminalNode NOT() { return getToken(C2105168Parser.NOT, 0); }
		public FactorContext factor() {
			return getRuleContext(FactorContext.class,0);
		}
		public Unary_expressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_unary_expression; }
	}

	public final Unary_expressionContext unary_expression() throws RecognitionException {
		Unary_expressionContext _localctx = new Unary_expressionContext(_ctx, getState());
		enterRule(_localctx, 40, RULE_unary_expression);
		try {
			setState(385);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case ADDOP:
				enterOuterAlt(_localctx, 1);
				{
				setState(374);
				((Unary_expressionContext)_localctx).ADDOP = match(ADDOP);
				setState(375);
				((Unary_expressionContext)_localctx).ue = unary_expression();

				            ((Unary_expressionContext)_localctx).text =  ((Unary_expressionContext)_localctx).ADDOP->getText() + ((Unary_expressionContext)_localctx).ue.text;
				            ((Unary_expressionContext)_localctx).line =  ((Unary_expressionContext)_localctx).ADDOP->getLine();
				            ((Unary_expressionContext)_localctx).type =  ((Unary_expressionContext)_localctx).ue.type;
				            ((Unary_expressionContext)_localctx).code_section =  ((Unary_expressionContext)_localctx).ue.code_section;


				            writeIntoAsmFile("\tPOP AX");
				            if (((Unary_expressionContext)_localctx).ADDOP->getText() == "+") {
				                ((Unary_expressionContext)_localctx).code_section =  "\tPUSH AX";
				            } else if (((Unary_expressionContext)_localctx).ADDOP->getText() == "-") {
				                ((Unary_expressionContext)_localctx).code_section =  "\tNEG AX\n\tPUSH AX";
				            }
				            writeIntoAsmFile(_localctx.code_section);
				            writeIntoparserLogFile("Line "+  std::to_string(_localctx.line)+": unary_expression : ADDOP unary_expression\n\n" + _localctx.text + "\n");

				        
				}
				break;
			case NOT:
				enterOuterAlt(_localctx, 2);
				{
				setState(378);
				((Unary_expressionContext)_localctx).NOT = match(NOT);
				setState(379);
				((Unary_expressionContext)_localctx).ue = unary_expression();

				            ((Unary_expressionContext)_localctx).text =  ((Unary_expressionContext)_localctx).NOT->getText() + ((Unary_expressionContext)_localctx).ue.text;
				            ((Unary_expressionContext)_localctx).line =  ((Unary_expressionContext)_localctx).ue.line;
				            ((Unary_expressionContext)_localctx).type =  ((Unary_expressionContext)_localctx).ue.type;
				            writeIntoparserLogFile("Line "+  std::to_string(_localctx.line)+": unary_expression : NOT unary_expression\n\n" + _localctx.text + "\n");

				        
				}
				break;
			case LPAREN:
			case ID:
			case CONST_INT:
			case CONST_FLOAT:
				enterOuterAlt(_localctx, 3);
				{
				setState(382);
				((Unary_expressionContext)_localctx).f = factor();

				            ((Unary_expressionContext)_localctx).text =  ((Unary_expressionContext)_localctx).f.text;
				            ((Unary_expressionContext)_localctx).line =  ((Unary_expressionContext)_localctx).f.line;
				            ((Unary_expressionContext)_localctx).type =  ((Unary_expressionContext)_localctx).f.type;
				            ((Unary_expressionContext)_localctx).argIsArray =  ((Unary_expressionContext)_localctx).f.argIsArray;
				            ((Unary_expressionContext)_localctx).code_section =  ((Unary_expressionContext)_localctx).f.code_section;
				            writeIntoparserLogFile("Line "+  std::to_string(((Unary_expressionContext)_localctx).f.line)+": unary_expression : factor\n\n" + ((Unary_expressionContext)_localctx).f.text + "\n"); 
				            
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class FactorContext extends ParserRuleContext {
		public std::string text;
		public int line;
		public std::string type;
		public bool argIsArray;
		public std::string code_section;
		public VariableContext v;
		public Token ID;
		public Token LPAREN;
		public Argument_listContext a;
		public Token RPAREN;
		public ExpressionContext e;
		public Token CONST_INT;
		public Token CONST_FLOAT;
		public Token INCOP;
		public Token DECOP;
		public VariableContext variable() {
			return getRuleContext(VariableContext.class,0);
		}
		public TerminalNode ID() { return getToken(C2105168Parser.ID, 0); }
		public TerminalNode LPAREN() { return getToken(C2105168Parser.LPAREN, 0); }
		public TerminalNode RPAREN() { return getToken(C2105168Parser.RPAREN, 0); }
		public Argument_listContext argument_list() {
			return getRuleContext(Argument_listContext.class,0);
		}
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public TerminalNode CONST_INT() { return getToken(C2105168Parser.CONST_INT, 0); }
		public TerminalNode CONST_FLOAT() { return getToken(C2105168Parser.CONST_FLOAT, 0); }
		public TerminalNode INCOP() { return getToken(C2105168Parser.INCOP, 0); }
		public TerminalNode DECOP() { return getToken(C2105168Parser.DECOP, 0); }
		public FactorContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_factor; }
	}

	public final FactorContext factor() throws RecognitionException {
		FactorContext _localctx = new FactorContext(_ctx, getState());
		enterRule(_localctx, 42, RULE_factor);
		try {
			setState(414);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,23,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(387);
				((FactorContext)_localctx).v = variable();

				        ((FactorContext)_localctx).text =  ((FactorContext)_localctx).v.text;
				        ((FactorContext)_localctx).line =  ((FactorContext)_localctx).v.line;
				        ((FactorContext)_localctx).type =  ((FactorContext)_localctx).v.type;
				        ((FactorContext)_localctx).argIsArray =  ((FactorContext)_localctx).v.isArray;

				        SymbolInfo* lookup = symbolTable->LookUP(((FactorContext)_localctx).v.text);

				        if(lookup->getIsGlobal()){
				            writeIntoAsmFile("\tMOV AX, "+((FactorContext)_localctx).v.text+"       ; Line "+std::to_string(_localctx.line));
				            writeIntoAsmFile("\tPUSH AX");
				          }

				          else {   
				            writeIntoAsmFile("L" + std::to_string(label_count++)+":");

				            if(isInsideFunctionDefinition && lookup->getSymbolName() != "main"){
				                writeIntoAsmFile("\tMOV AX, [BP+" + std::to_string(lookup->getStackOffset()) + "]"+"       ; Line "+std::to_string(_localctx.line));

				                std::cout << "DEBUG: variable " << ((FactorContext)_localctx).v.text << " is inside function definition, stack offset: " << lookup->getStackOffset() << std::endl;
				                std::cout<<"lookupsymbolname: "<<lookup->getSymbolName()<<" "<<isParamsymbol<<std::endl;
				                writeIntoAsmFile("\tPUSH AX");


				            }
				            else{
				                //ghapla
				            writeIntoAsmFile("\tMOV AX, [BP-" + std::to_string(lookup->getStackOffset()) + "]"+"       ; Line "+std::to_string(_localctx.line));
				            
				            writeIntoAsmFile("\tPUSH AX");
				              std::cout << "DEBUG: variable " << ((FactorContext)_localctx).v.text << " is inside function definition, stack offset: " << lookup->getStackOffset() << std::endl;
				                std::cout<<"lookupsymbolname: "<<lookup->getSymbolName()<<" "<<isParamsymbol<<std::endl;
				            }
				          }

				        // std::cout << "v type"<<((FactorContext)_localctx).v.type <<std::endl;
				        writeIntoparserLogFile("Line "+  std::to_string(((FactorContext)_localctx).v.line)+": factor : variable\n\n" + ((FactorContext)_localctx).v.text + "\n");
				        
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(390);
				((FactorContext)_localctx).ID = match(ID);
				setState(391);
				((FactorContext)_localctx).LPAREN = match(LPAREN);

				        argumentCount = 0;
				        argumentTypes.clear();
				        argumentIsArray.clear();
				    
				setState(393);
				((FactorContext)_localctx).a = argument_list();
				setState(394);
				((FactorContext)_localctx).RPAREN = match(RPAREN);

				    ((FactorContext)_localctx).text =  ((FactorContext)_localctx).ID->getText() + ((FactorContext)_localctx).LPAREN->getText() + ((FactorContext)_localctx).a.text + ((FactorContext)_localctx).RPAREN->getText();
				    ((FactorContext)_localctx).line =  ((FactorContext)_localctx).ID->getLine();
				    ((FactorContext)_localctx).type =  ((FactorContext)_localctx).ID->getType();

				    SymbolInfo* func = symbolTable->LookUP(((FactorContext)_localctx).ID->getText());

				    if (func == nullptr) {
				        writeIntoErrorFile("Error at line " + std::to_string(_localctx.line) + ": Undefined function " + ((FactorContext)_localctx).ID->getText() + "\n");
				        errorCount++;
				    } 
				    else if (func->getIsFunction() && func->getIsFunctionDefined()) {
				                //            std::cout<<std::to_string(_localctx.line)<<func->getSymbolName()<<(int)func->parameterList.size()<< argumentCount<<std::endl;

				        if ((int)func->parameterList.size()!= argumentCount) {

				            writeIntoErrorFile("Error at line " + std::to_string(_localctx.line) + ": Total number of arguments mismatch with declaration in function " + ((FactorContext)_localctx).ID->getText() + "\n");
				            writeIntoparserLogFile("Error at line " + std::to_string(_localctx.line) + ": Total number of arguments mismatch with declaration in function " + ((FactorContext)_localctx).ID->getText() + "\n");

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
				                    writeIntoErrorFile("Error at line " + std::to_string(_localctx.line) + ": Type mismatch, " + func->parameterList[i].second + " is an array\n");
				                    writeIntoparserLogFile("Error at line " + std::to_string(_localctx.line) + ": Type mismatch " + func->parameterList[i].second + " is an array\n");
				                    errorCount++;
				                } 
				                else if (!argIsArray && expectedType != argType) {
				                    writeIntoErrorFile("Error at line " + std::to_string(_localctx.line) + ": " + std::to_string(i + 1) + "th argument mismatch in function " + ((FactorContext)_localctx).ID->getText() + "\n");
				                    writeIntoparserLogFile("Error at line " + std::to_string(_localctx.line) + ": " + std::to_string(i + 1) + "th argument mismatch in function " + ((FactorContext)_localctx).ID->getText() + "\n");
				                    errorCount++;
				                    break;
				                }
				            }

				            std::cout << "argumentCount: " << argumentCount << std::endl;

				        }
				    } 
				    else {
				        writeIntoErrorFile("Error at line " + std::to_string(_localctx.line) + ": Undefined function " + ((FactorContext)_localctx).ID->getText() + "\n");
				        errorCount++;
				    }
				    

				    //ekhne function call hbe
				    writeIntoAsmFile("\tCALL " + ((FactorContext)_localctx).ID->getText());
				    writeIntoAsmFile("\tPUSH AX");
				    writeIntoparserLogFile("Line " + std::to_string(_localctx.line) + ": factor : ID LPAREN argument_list RPAREN\n\n" + _localctx.text + "\n");

				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(397);
				((FactorContext)_localctx).LPAREN = match(LPAREN);
				setState(398);
				((FactorContext)_localctx).e = expression();
				setState(399);
				((FactorContext)_localctx).RPAREN = match(RPAREN);
				 
				        ((FactorContext)_localctx).text =  ((FactorContext)_localctx).LPAREN->getText() + ((FactorContext)_localctx).e.text + ((FactorContext)_localctx).RPAREN->getText();
				        ((FactorContext)_localctx).line =  ((FactorContext)_localctx).RPAREN->getLine();
				        ((FactorContext)_localctx).type =  ((FactorContext)_localctx).e.type;
				         ((FactorContext)_localctx).argIsArray =  false;
				        writeIntoparserLogFile("Line "+  std::to_string(_localctx.line)+": factor : LPAREN expression RPAREN\n\n" + _localctx.text + "\n");

				     
				}
				break;
			case 4:
				enterOuterAlt(_localctx, 4);
				{
				setState(402);
				((FactorContext)_localctx).CONST_INT = match(CONST_INT);

				        ((FactorContext)_localctx).text =  ((FactorContext)_localctx).CONST_INT->getText();
				        ((FactorContext)_localctx).line =  ((FactorContext)_localctx).CONST_INT->getLine();
				        ((FactorContext)_localctx).type =  "int";
				        ((FactorContext)_localctx).argIsArray =  false;
				        writeIntoAsmFile("L" + std::to_string(label_count++) + ":\n" + "\tMOV AX, "+_localctx.text +"       ; Line "+std::to_string(_localctx.line));
				        writeIntoAsmFile("\tPUSH AX");
				        

				        

				        writeIntoparserLogFile("Line "+  std::to_string(_localctx.line)+": factor : CONST_INT\n\n" + _localctx.text + "\n");

				    
				}
				break;
			case 5:
				enterOuterAlt(_localctx, 5);
				{
				setState(404);
				((FactorContext)_localctx).CONST_FLOAT = match(CONST_FLOAT);

				        ((FactorContext)_localctx).text =  ((FactorContext)_localctx).CONST_FLOAT->getText();
				        ((FactorContext)_localctx).line =  ((FactorContext)_localctx).CONST_FLOAT->getLine();
				        ((FactorContext)_localctx).type =  "float";
				         ((FactorContext)_localctx).argIsArray =  false;
				        writeIntoparserLogFile("Line "+  std::to_string(_localctx.line)+": factor : CONST_FLOAT\n\n" + _localctx.text + "\n");

				    
				}
				break;
			case 6:
				enterOuterAlt(_localctx, 6);
				{
				setState(406);
				((FactorContext)_localctx).v = variable();
				setState(407);
				((FactorContext)_localctx).INCOP = match(INCOP);

				        ((FactorContext)_localctx).text =  ((FactorContext)_localctx).v.text+((FactorContext)_localctx).INCOP->getText();
				        ((FactorContext)_localctx).line =  ((FactorContext)_localctx).INCOP->getLine();
				        ((FactorContext)_localctx).type =  ((FactorContext)_localctx).v.type;

				        SymbolInfo* lookup = symbolTable->LookUP(((FactorContext)_localctx).v.text);
				        writeIntoAsmFile("\tMOV AX, [BP-" + std::to_string(lookup->getStackOffset()) + "]"+"       ; Line "+std::to_string(_localctx.line));
				        writeIntoAsmFile("\tPUSH AX");
				        writeIntoAsmFile("\tINC AX");
				        writeIntoAsmFile("\tMOV [BP-" + std::to_string(lookup->getStackOffset()) + "], AX" + "       ; Line "+std::to_string(_localctx.line));

				        writeIntoparserLogFile("Line "+  std::to_string(_localctx.line)+": factor : variable INCOP\n\n" + _localctx.text + "\n");

				    
				}
				break;
			case 7:
				enterOuterAlt(_localctx, 7);
				{
				setState(410);
				((FactorContext)_localctx).v = variable();
				setState(411);
				((FactorContext)_localctx).DECOP = match(DECOP);

				        ((FactorContext)_localctx).text =  ((FactorContext)_localctx).v.text+((FactorContext)_localctx).DECOP->getText();
				        ((FactorContext)_localctx).line =  ((FactorContext)_localctx).DECOP->getLine();
				        ((FactorContext)_localctx).type =  ((FactorContext)_localctx).v.type;
				         SymbolInfo* lookup = symbolTable->LookUP(((FactorContext)_localctx).v.text);
				        writeIntoAsmFile("\tMOV AX, [BP-" + std::to_string(lookup->getStackOffset()) + "]"+"       ; Line "+std::to_string(_localctx.line));
				        writeIntoAsmFile("\tPUSH AX");
				        writeIntoAsmFile("\tDEC AX");
				     writeIntoAsmFile("\tMOV [BP-" + std::to_string(lookup->getStackOffset()) + "], AX" + "       ; Line "+std::to_string(_localctx.line));

				        writeIntoparserLogFile("Line "+  std::to_string(_localctx.line)+": factor : variable DECOP\n\n" + _localctx.text + "\n");

				    
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Argument_listContext extends ParserRuleContext {
		public std::string text;
		public int line;
		public std::string type;
		public ArgumentsContext a;
		public ArgumentsContext arguments() {
			return getRuleContext(ArgumentsContext.class,0);
		}
		public Argument_listContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_argument_list; }
	}

	public final Argument_listContext argument_list() throws RecognitionException {
		Argument_listContext _localctx = new Argument_listContext(_ctx, getState());
		enterRule(_localctx, 44, RULE_argument_list);
		try {
			setState(420);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case LPAREN:
			case ADDOP:
			case NOT:
			case ID:
			case CONST_INT:
			case CONST_FLOAT:
				enterOuterAlt(_localctx, 1);
				{
				setState(416);
				((Argument_listContext)_localctx).a = arguments(0);
				   
				            ((Argument_listContext)_localctx).text =  ((Argument_listContext)_localctx).a.text;
				            ((Argument_listContext)_localctx).line =  ((Argument_listContext)_localctx).a.line;
				            ((Argument_listContext)_localctx).type =  ((Argument_listContext)_localctx).a.type;
				            
				            writeIntoparserLogFile("Line "+ std::to_string(_localctx.line)+": argument_list : arguments\n\n"+_localctx.text+"\n");
				          
				}
				break;
			case RPAREN:
				enterOuterAlt(_localctx, 2);
				{
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ArgumentsContext extends ParserRuleContext {
		public std::string text;
		public int line;
		public std::string type;
		public ArgumentsContext a;
		public Logic_expressionContext le;
		public Token COMMA;
		public Logic_expressionContext logic_expression() {
			return getRuleContext(Logic_expressionContext.class,0);
		}
		public TerminalNode COMMA() { return getToken(C2105168Parser.COMMA, 0); }
		public ArgumentsContext arguments() {
			return getRuleContext(ArgumentsContext.class,0);
		}
		public ArgumentsContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_arguments; }
	}

	public final ArgumentsContext arguments() throws RecognitionException {
		return arguments(0);
	}

	private ArgumentsContext arguments(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		ArgumentsContext _localctx = new ArgumentsContext(_ctx, _parentState);
		ArgumentsContext _prevctx = _localctx;
		int _startState = 46;
		enterRecursionRule(_localctx, 46, RULE_arguments, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			{
			setState(423);
			((ArgumentsContext)_localctx).le = logic_expression();


			            ((ArgumentsContext)_localctx).text = ((ArgumentsContext)_localctx).le.text;
			            ((ArgumentsContext)_localctx).line = ((ArgumentsContext)_localctx).le.line;
			            ((ArgumentsContext)_localctx).type =  ((ArgumentsContext)_localctx).le.type; 
			            argumentCount++;  
			            argumentTypes.push_back(((ArgumentsContext)_localctx).le.type);
			            argumentIsArray.push_back(((ArgumentsContext)_localctx).le.argIsArr);
			            writeIntoparserLogFile("Line "+ std::to_string(_localctx.line)+": arguments : logic_expression\n\n"+_localctx.text+"\n");


			        
			}
			_ctx.stop = _input.LT(-1);
			setState(433);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,25,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					{
					_localctx = new ArgumentsContext(_parentctx, _parentState);
					_localctx.a = _prevctx;
					pushNewRecursionContext(_localctx, _startState, RULE_arguments);
					setState(426);
					if (!(precpred(_ctx, 2))) throw new FailedPredicateException(this, "precpred(_ctx, 2)");
					setState(427);
					((ArgumentsContext)_localctx).COMMA = match(COMMA);
					setState(428);
					((ArgumentsContext)_localctx).le = logic_expression();
					    
					                      ((ArgumentsContext)_localctx).text = ((ArgumentsContext)_localctx).a.text +  ((ArgumentsContext)_localctx).COMMA->getText()+  ((ArgumentsContext)_localctx).le.text;
					                      ((ArgumentsContext)_localctx).line = ((ArgumentsContext)_localctx).le.line;
					                      ((ArgumentsContext)_localctx).type =  ((ArgumentsContext)_localctx).le.type;
					                      argumentCount++;
					                      argumentTypes.push_back(((ArgumentsContext)_localctx).le.type);
					                      argumentIsArray.push_back(((ArgumentsContext)_localctx).le.argIsArr);
					                      writeIntoparserLogFile("Line "+ std::to_string(_localctx.line)+": arguments : arguments COMMA logic_expression\n\n"+_localctx.text+"\n");

					                   
					}
					} 
				}
				setState(435);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,25,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	public boolean sempred(RuleContext _localctx, int ruleIndex, int predIndex) {
		switch (ruleIndex) {
		case 1:
			return program_sempred((ProgramContext)_localctx, predIndex);
		case 5:
			return parameter_list_sempred((Parameter_listContext)_localctx, predIndex);
		case 10:
			return declaration_list_sempred((Declaration_listContext)_localctx, predIndex);
		case 11:
			return statements_sempred((StatementsContext)_localctx, predIndex);
		case 18:
			return simple_expression_sempred((Simple_expressionContext)_localctx, predIndex);
		case 19:
			return term_sempred((TermContext)_localctx, predIndex);
		case 23:
			return arguments_sempred((ArgumentsContext)_localctx, predIndex);
		}
		return true;
	}
	private boolean program_sempred(ProgramContext _localctx, int predIndex) {
		switch (predIndex) {
		case 0:
			return precpred(_ctx, 2);
		}
		return true;
	}
	private boolean parameter_list_sempred(Parameter_listContext _localctx, int predIndex) {
		switch (predIndex) {
		case 1:
			return precpred(_ctx, 7);
		case 2:
			return precpred(_ctx, 6);
		case 3:
			return precpred(_ctx, 5);
		}
		return true;
	}
	private boolean declaration_list_sempred(Declaration_listContext _localctx, int predIndex) {
		switch (predIndex) {
		case 4:
			return precpred(_ctx, 6);
		case 5:
			return precpred(_ctx, 5);
		case 6:
			return precpred(_ctx, 4);
		}
		return true;
	}
	private boolean statements_sempred(StatementsContext _localctx, int predIndex) {
		switch (predIndex) {
		case 7:
			return precpred(_ctx, 1);
		}
		return true;
	}
	private boolean simple_expression_sempred(Simple_expressionContext _localctx, int predIndex) {
		switch (predIndex) {
		case 8:
			return precpred(_ctx, 1);
		}
		return true;
	}
	private boolean term_sempred(TermContext _localctx, int predIndex) {
		switch (predIndex) {
		case 9:
			return precpred(_ctx, 1);
		}
		return true;
	}
	private boolean arguments_sempred(ArgumentsContext _localctx, int predIndex) {
		switch (predIndex) {
		case 10:
			return precpred(_ctx, 2);
		}
		return true;
	}

	public static final String _serializedATN =
		"\u0004\u0001\"\u01b5\u0002\u0000\u0007\u0000\u0002\u0001\u0007\u0001\u0002"+
		"\u0002\u0007\u0002\u0002\u0003\u0007\u0003\u0002\u0004\u0007\u0004\u0002"+
		"\u0005\u0007\u0005\u0002\u0006\u0007\u0006\u0002\u0007\u0007\u0007\u0002"+
		"\b\u0007\b\u0002\t\u0007\t\u0002\n\u0007\n\u0002\u000b\u0007\u000b\u0002"+
		"\f\u0007\f\u0002\r\u0007\r\u0002\u000e\u0007\u000e\u0002\u000f\u0007\u000f"+
		"\u0002\u0010\u0007\u0010\u0002\u0011\u0007\u0011\u0002\u0012\u0007\u0012"+
		"\u0002\u0013\u0007\u0013\u0002\u0014\u0007\u0014\u0002\u0015\u0007\u0015"+
		"\u0002\u0016\u0007\u0016\u0002\u0017\u0007\u0017\u0001\u0000\u0001\u0000"+
		"\u0001\u0000\u0001\u0000\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001"+
		"\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0005\u0001=\b\u0001"+
		"\n\u0001\f\u0001@\t\u0001\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002"+
		"\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0003\u0002"+
		"K\b\u0002\u0001\u0003\u0001\u0003\u0001\u0003\u0001\u0003\u0001\u0003"+
		"\u0001\u0003\u0001\u0003\u0001\u0003\u0001\u0003\u0001\u0003\u0001\u0003"+
		"\u0001\u0003\u0001\u0003\u0001\u0003\u0001\u0003\u0001\u0003\u0003\u0003"+
		"]\b\u0003\u0001\u0004\u0001\u0004\u0001\u0004\u0001\u0004\u0001\u0004"+
		"\u0001\u0004\u0001\u0004\u0001\u0004\u0001\u0004\u0001\u0004\u0001\u0004"+
		"\u0001\u0004\u0001\u0004\u0001\u0004\u0001\u0004\u0001\u0004\u0001\u0004"+
		"\u0001\u0004\u0001\u0004\u0001\u0004\u0003\u0004s\b\u0004\u0001\u0005"+
		"\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005"+
		"\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005"+
		"\u0001\u0005\u0003\u0005\u0083\b\u0005\u0001\u0005\u0001\u0005\u0001\u0005"+
		"\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005"+
		"\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005"+
		"\u0005\u0005\u0094\b\u0005\n\u0005\f\u0005\u0097\t\u0005\u0001\u0006\u0001"+
		"\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0001"+
		"\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0003\u0006\u00a4\b\u0006\u0001"+
		"\u0007\u0001\u0007\u0001\u0007\u0001\u0007\u0001\u0007\u0001\u0007\u0001"+
		"\u0007\u0001\u0007\u0001\u0007\u0001\u0007\u0003\u0007\u00b0\b\u0007\u0001"+
		"\b\u0001\b\u0001\t\u0001\t\u0001\t\u0001\t\u0001\t\u0001\t\u0003\t\u00ba"+
		"\b\t\u0001\n\u0001\n\u0001\n\u0001\n\u0001\n\u0001\n\u0001\n\u0001\n\u0001"+
		"\n\u0001\n\u0001\n\u0001\n\u0001\n\u0003\n\u00c9\b\n\u0001\n\u0001\n\u0001"+
		"\n\u0001\n\u0001\n\u0001\n\u0001\n\u0001\n\u0001\n\u0001\n\u0001\n\u0001"+
		"\n\u0001\n\u0001\n\u0001\n\u0001\n\u0005\n\u00db\b\n\n\n\f\n\u00de\t\n"+
		"\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b"+
		"\u0001\u000b\u0001\u000b\u0005\u000b\u00e8\b\u000b\n\u000b\f\u000b\u00eb"+
		"\t\u000b\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001"+
		"\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001"+
		"\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001"+
		"\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001"+
		"\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001"+
		"\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001"+
		"\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0003\f\u0129"+
		"\b\f\u0001\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001\r\u0003\r\u0131\b\r"+
		"\u0001\u000e\u0001\u000e\u0001\u000e\u0001\u000e\u0001\u000e\u0001\u000e"+
		"\u0001\u000e\u0001\u000e\u0003\u000e\u013b\b\u000e\u0001\u000f\u0001\u000f"+
		"\u0001\u000f\u0001\u000f\u0001\u000f\u0001\u000f\u0001\u000f\u0001\u000f"+
		"\u0003\u000f\u0145\b\u000f\u0001\u0010\u0001\u0010\u0001\u0010\u0001\u0010"+
		"\u0001\u0010\u0001\u0010\u0001\u0010\u0001\u0010\u0003\u0010\u014f\b\u0010"+
		"\u0001\u0011\u0001\u0011\u0001\u0011\u0001\u0011\u0001\u0011\u0001\u0011"+
		"\u0001\u0011\u0001\u0011\u0003\u0011\u0159\b\u0011\u0001\u0012\u0001\u0012"+
		"\u0001\u0012\u0001\u0012\u0001\u0012\u0001\u0012\u0001\u0012\u0001\u0012"+
		"\u0001\u0012\u0005\u0012\u0164\b\u0012\n\u0012\f\u0012\u0167\t\u0012\u0001"+
		"\u0013\u0001\u0013\u0001\u0013\u0001\u0013\u0001\u0013\u0001\u0013\u0001"+
		"\u0013\u0001\u0013\u0001\u0013\u0005\u0013\u0172\b\u0013\n\u0013\f\u0013"+
		"\u0175\t\u0013\u0001\u0014\u0001\u0014\u0001\u0014\u0001\u0014\u0001\u0014"+
		"\u0001\u0014\u0001\u0014\u0001\u0014\u0001\u0014\u0001\u0014\u0001\u0014"+
		"\u0003\u0014\u0182\b\u0014\u0001\u0015\u0001\u0015\u0001\u0015\u0001\u0015"+
		"\u0001\u0015\u0001\u0015\u0001\u0015\u0001\u0015\u0001\u0015\u0001\u0015"+
		"\u0001\u0015\u0001\u0015\u0001\u0015\u0001\u0015\u0001\u0015\u0001\u0015"+
		"\u0001\u0015\u0001\u0015\u0001\u0015\u0001\u0015\u0001\u0015\u0001\u0015"+
		"\u0001\u0015\u0001\u0015\u0001\u0015\u0001\u0015\u0001\u0015\u0003\u0015"+
		"\u019f\b\u0015\u0001\u0016\u0001\u0016\u0001\u0016\u0001\u0016\u0003\u0016"+
		"\u01a5\b\u0016\u0001\u0017\u0001\u0017\u0001\u0017\u0001\u0017\u0001\u0017"+
		"\u0001\u0017\u0001\u0017\u0001\u0017\u0001\u0017\u0005\u0017\u01b0\b\u0017"+
		"\n\u0017\f\u0017\u01b3\t\u0017\u0001\u0017\u0000\u0007\u0002\n\u0014\u0016"+
		"$&.\u0018\u0000\u0002\u0004\u0006\b\n\f\u000e\u0010\u0012\u0014\u0016"+
		"\u0018\u001a\u001c\u001e \"$&(*,.\u0000\u0000\u01ca\u00000\u0001\u0000"+
		"\u0000\u0000\u00024\u0001\u0000\u0000\u0000\u0004J\u0001\u0000\u0000\u0000"+
		"\u0006\\\u0001\u0000\u0000\u0000\br\u0001\u0000\u0000\u0000\n\u0082\u0001"+
		"\u0000\u0000\u0000\f\u00a3\u0001\u0000\u0000\u0000\u000e\u00af\u0001\u0000"+
		"\u0000\u0000\u0010\u00b1\u0001\u0000\u0000\u0000\u0012\u00b9\u0001\u0000"+
		"\u0000\u0000\u0014\u00c8\u0001\u0000\u0000\u0000\u0016\u00df\u0001\u0000"+
		"\u0000\u0000\u0018\u0128\u0001\u0000\u0000\u0000\u001a\u0130\u0001\u0000"+
		"\u0000\u0000\u001c\u013a\u0001\u0000\u0000\u0000\u001e\u0144\u0001\u0000"+
		"\u0000\u0000 \u014e\u0001\u0000\u0000\u0000\"\u0158\u0001\u0000\u0000"+
		"\u0000$\u015a\u0001\u0000\u0000\u0000&\u0168\u0001\u0000\u0000\u0000("+
		"\u0181\u0001\u0000\u0000\u0000*\u019e\u0001\u0000\u0000\u0000,\u01a4\u0001"+
		"\u0000\u0000\u0000.\u01a6\u0001\u0000\u0000\u000001\u0006\u0000\uffff"+
		"\uffff\u000012\u0003\u0002\u0001\u000023\u0006\u0000\uffff\uffff\u0000"+
		"3\u0001\u0001\u0000\u0000\u000045\u0006\u0001\uffff\uffff\u000056\u0003"+
		"\u0004\u0002\u000067\u0006\u0001\uffff\uffff\u00007>\u0001\u0000\u0000"+
		"\u000089\n\u0002\u0000\u00009:\u0003\u0004\u0002\u0000:;\u0006\u0001\uffff"+
		"\uffff\u0000;=\u0001\u0000\u0000\u0000<8\u0001\u0000\u0000\u0000=@\u0001"+
		"\u0000\u0000\u0000><\u0001\u0000\u0000\u0000>?\u0001\u0000\u0000\u0000"+
		"?\u0003\u0001\u0000\u0000\u0000@>\u0001\u0000\u0000\u0000AB\u0003\u000e"+
		"\u0007\u0000BC\u0006\u0002\uffff\uffff\u0000CK\u0001\u0000\u0000\u0000"+
		"DE\u0003\u0006\u0003\u0000EF\u0006\u0002\uffff\uffff\u0000FK\u0001\u0000"+
		"\u0000\u0000GH\u0003\b\u0004\u0000HI\u0006\u0002\uffff\uffff\u0000IK\u0001"+
		"\u0000\u0000\u0000JA\u0001\u0000\u0000\u0000JD\u0001\u0000\u0000\u0000"+
		"JG\u0001\u0000\u0000\u0000K\u0005\u0001\u0000\u0000\u0000LM\u0003\u0012"+
		"\t\u0000MN\u0005 \u0000\u0000NO\u0006\u0003\uffff\uffff\u0000OP\u0005"+
		"\u000e\u0000\u0000PQ\u0003\n\u0005\u0000QR\u0005\u000f\u0000\u0000RS\u0005"+
		"\u0014\u0000\u0000ST\u0006\u0003\uffff\uffff\u0000T]\u0001\u0000\u0000"+
		"\u0000UV\u0003\u0012\t\u0000VW\u0005 \u0000\u0000WX\u0005\u000e\u0000"+
		"\u0000XY\u0005\u000f\u0000\u0000YZ\u0005\u0014\u0000\u0000Z[\u0006\u0003"+
		"\uffff\uffff\u0000[]\u0001\u0000\u0000\u0000\\L\u0001\u0000\u0000\u0000"+
		"\\U\u0001\u0000\u0000\u0000]\u0007\u0001\u0000\u0000\u0000^_\u0003\u0012"+
		"\t\u0000_`\u0005 \u0000\u0000`a\u0005\u000e\u0000\u0000ab\u0006\u0004"+
		"\uffff\uffff\u0000bc\u0003\n\u0005\u0000cd\u0006\u0004\uffff\uffff\u0000"+
		"de\u0005\u000f\u0000\u0000ef\u0006\u0004\uffff\uffff\u0000fg\u0003\f\u0006"+
		"\u0000gh\u0006\u0004\uffff\uffff\u0000hs\u0001\u0000\u0000\u0000ij\u0003"+
		"\u0012\t\u0000jk\u0005 \u0000\u0000kl\u0005\u000e\u0000\u0000lm\u0005"+
		"\u000f\u0000\u0000mn\u0006\u0004\uffff\uffff\u0000no\u0006\u0004\uffff"+
		"\uffff\u0000op\u0003\f\u0006\u0000pq\u0006\u0004\uffff\uffff\u0000qs\u0001"+
		"\u0000\u0000\u0000r^\u0001\u0000\u0000\u0000ri\u0001\u0000\u0000\u0000"+
		"s\t\u0001\u0000\u0000\u0000tu\u0006\u0005\uffff\uffff\u0000uv\u0003\u0012"+
		"\t\u0000vw\u0005 \u0000\u0000wx\u0006\u0005\uffff\uffff\u0000x\u0083\u0001"+
		"\u0000\u0000\u0000yz\u0003\u0012\t\u0000z{\u0005\u0017\u0000\u0000{|\u0006"+
		"\u0005\uffff\uffff\u0000|\u0083\u0001\u0000\u0000\u0000}~\u0003\u0012"+
		"\t\u0000~\u007f\u0006\u0005\uffff\uffff\u0000\u007f\u0083\u0001\u0000"+
		"\u0000\u0000\u0080\u0081\u0005\u0017\u0000\u0000\u0081\u0083\u0006\u0005"+
		"\uffff\uffff\u0000\u0082t\u0001\u0000\u0000\u0000\u0082y\u0001\u0000\u0000"+
		"\u0000\u0082}\u0001\u0000\u0000\u0000\u0082\u0080\u0001\u0000\u0000\u0000"+
		"\u0083\u0095\u0001\u0000\u0000\u0000\u0084\u0085\n\u0007\u0000\u0000\u0085"+
		"\u0086\u0005\u0015\u0000\u0000\u0086\u0087\u0003\u0012\t\u0000\u0087\u0088"+
		"\u0005 \u0000\u0000\u0088\u0089\u0006\u0005\uffff\uffff\u0000\u0089\u0094"+
		"\u0001\u0000\u0000\u0000\u008a\u008b\n\u0006\u0000\u0000\u008b\u008c\u0005"+
		"\u0015\u0000\u0000\u008c\u008d\u0003\u0012\t\u0000\u008d\u008e\u0006\u0005"+
		"\uffff\uffff\u0000\u008e\u0094\u0001\u0000\u0000\u0000\u008f\u0090\n\u0005"+
		"\u0000\u0000\u0090\u0091\u0005\u0015\u0000\u0000\u0091\u0092\u0005\u0017"+
		"\u0000\u0000\u0092\u0094\u0006\u0005\uffff\uffff\u0000\u0093\u0084\u0001"+
		"\u0000\u0000\u0000\u0093\u008a\u0001\u0000\u0000\u0000\u0093\u008f\u0001"+
		"\u0000\u0000\u0000\u0094\u0097\u0001\u0000\u0000\u0000\u0095\u0093\u0001"+
		"\u0000\u0000\u0000\u0095\u0096\u0001\u0000\u0000\u0000\u0096\u000b\u0001"+
		"\u0000\u0000\u0000\u0097\u0095\u0001\u0000\u0000\u0000\u0098\u0099\u0005"+
		"\u0010\u0000\u0000\u0099\u009a\u0006\u0006\uffff\uffff\u0000\u009a\u009b"+
		"\u0003\u0016\u000b\u0000\u009b\u009c\u0006\u0006\uffff\uffff\u0000\u009c"+
		"\u009d\u0005\u0011\u0000\u0000\u009d\u009e\u0006\u0006\uffff\uffff\u0000"+
		"\u009e\u00a4\u0001\u0000\u0000\u0000\u009f\u00a0\u0005\u0010\u0000\u0000"+
		"\u00a0\u00a1\u0006\u0006\uffff\uffff\u0000\u00a1\u00a2\u0005\u0011\u0000"+
		"\u0000\u00a2\u00a4\u0006\u0006\uffff\uffff\u0000\u00a3\u0098\u0001\u0000"+
		"\u0000\u0000\u00a3\u009f\u0001\u0000\u0000\u0000\u00a4\r\u0001\u0000\u0000"+
		"\u0000\u00a5\u00a6\u0003\u0012\t\u0000\u00a6\u00a7\u0003\u0014\n\u0000"+
		"\u00a7\u00a8\u0005\u0014\u0000\u0000\u00a8\u00a9\u0006\u0007\uffff\uffff"+
		"\u0000\u00a9\u00b0\u0001\u0000\u0000\u0000\u00aa\u00ab\u0003\u0012\t\u0000"+
		"\u00ab\u00ac\u0003\u0010\b\u0000\u00ac\u00ad\u0005\u0014\u0000\u0000\u00ad"+
		"\u00ae\u0006\u0007\uffff\uffff\u0000\u00ae\u00b0\u0001\u0000\u0000\u0000"+
		"\u00af\u00a5\u0001\u0000\u0000\u0000\u00af\u00aa\u0001\u0000\u0000\u0000"+
		"\u00b0\u000f\u0001\u0000\u0000\u0000\u00b1\u00b2\u0006\b\uffff\uffff\u0000"+
		"\u00b2\u0011\u0001\u0000\u0000\u0000\u00b3\u00b4\u0005\u000b\u0000\u0000"+
		"\u00b4\u00ba\u0006\t\uffff\uffff\u0000\u00b5\u00b6\u0005\f\u0000\u0000"+
		"\u00b6\u00ba\u0006\t\uffff\uffff\u0000\u00b7\u00b8\u0005\r\u0000\u0000"+
		"\u00b8\u00ba\u0006\t\uffff\uffff\u0000\u00b9\u00b3\u0001\u0000\u0000\u0000"+
		"\u00b9\u00b5\u0001\u0000\u0000\u0000\u00b9\u00b7\u0001\u0000\u0000\u0000"+
		"\u00ba\u0013\u0001\u0000\u0000\u0000\u00bb\u00bc\u0006\n\uffff\uffff\u0000"+
		"\u00bc\u00bd\u0005 \u0000\u0000\u00bd\u00c9\u0006\n\uffff\uffff\u0000"+
		"\u00be\u00bf\u0005 \u0000\u0000\u00bf\u00c0\u0005\u0012\u0000\u0000\u00c0"+
		"\u00c1\u0005!\u0000\u0000\u00c1\u00c2\u0005\u0013\u0000\u0000\u00c2\u00c9"+
		"\u0006\n\uffff\uffff\u0000\u00c3\u00c4\u0005 \u0000\u0000\u00c4\u00c5"+
		"\u0005\u0017\u0000\u0000\u00c5\u00c6\u0003\u0014\n\u0001\u00c6\u00c7\u0006"+
		"\n\uffff\uffff\u0000\u00c7\u00c9\u0001\u0000\u0000\u0000\u00c8\u00bb\u0001"+
		"\u0000\u0000\u0000\u00c8\u00be\u0001\u0000\u0000\u0000\u00c8\u00c3\u0001"+
		"\u0000\u0000\u0000\u00c9\u00dc\u0001\u0000\u0000\u0000\u00ca\u00cb\n\u0006"+
		"\u0000\u0000\u00cb\u00cc\u0005\u0015\u0000\u0000\u00cc\u00cd\u0005 \u0000"+
		"\u0000\u00cd\u00db\u0006\n\uffff\uffff\u0000\u00ce\u00cf\n\u0005\u0000"+
		"\u0000\u00cf\u00d0\u0005\u0015\u0000\u0000\u00d0\u00d1\u0005 \u0000\u0000"+
		"\u00d1\u00d2\u0005\u0012\u0000\u0000\u00d2\u00d3\u0005!\u0000\u0000\u00d3"+
		"\u00d4\u0005\u0013\u0000\u0000\u00d4\u00db\u0006\n\uffff\uffff\u0000\u00d5"+
		"\u00d6\n\u0004\u0000\u0000\u00d6\u00d7\u0005\u0015\u0000\u0000\u00d7\u00d8"+
		"\u0005 \u0000\u0000\u00d8\u00d9\u0005\u0017\u0000\u0000\u00d9\u00db\u0006"+
		"\n\uffff\uffff\u0000\u00da\u00ca\u0001\u0000\u0000\u0000\u00da\u00ce\u0001"+
		"\u0000\u0000\u0000\u00da\u00d5\u0001\u0000\u0000\u0000\u00db\u00de\u0001"+
		"\u0000\u0000\u0000\u00dc\u00da\u0001\u0000\u0000\u0000\u00dc\u00dd\u0001"+
		"\u0000\u0000\u0000\u00dd\u0015\u0001\u0000\u0000\u0000\u00de\u00dc\u0001"+
		"\u0000\u0000\u0000\u00df\u00e0\u0006\u000b\uffff\uffff\u0000\u00e0\u00e1"+
		"\u0003\u0018\f\u0000\u00e1\u00e2\u0006\u000b\uffff\uffff\u0000\u00e2\u00e9"+
		"\u0001\u0000\u0000\u0000\u00e3\u00e4\n\u0001\u0000\u0000\u00e4\u00e5\u0003"+
		"\u0018\f\u0000\u00e5\u00e6\u0006\u000b\uffff\uffff\u0000\u00e6\u00e8\u0001"+
		"\u0000\u0000\u0000\u00e7\u00e3\u0001\u0000\u0000\u0000\u00e8\u00eb\u0001"+
		"\u0000\u0000\u0000\u00e9\u00e7\u0001\u0000\u0000\u0000\u00e9\u00ea\u0001"+
		"\u0000\u0000\u0000\u00ea\u0017\u0001\u0000\u0000\u0000\u00eb\u00e9\u0001"+
		"\u0000\u0000\u0000\u00ec\u00ed\u0003\u000e\u0007\u0000\u00ed\u00ee\u0006"+
		"\f\uffff\uffff\u0000\u00ee\u0129\u0001\u0000\u0000\u0000\u00ef\u00f0\u0003"+
		"\u001a\r\u0000\u00f0\u00f1\u0006\f\uffff\uffff\u0000\u00f1\u0129\u0001"+
		"\u0000\u0000\u0000\u00f2\u00f3\u0003\f\u0006\u0000\u00f3\u00f4\u0006\f"+
		"\uffff\uffff\u0000\u00f4\u0129\u0001\u0000\u0000\u0000\u00f5\u00f6\u0005"+
		"\u0007\u0000\u0000\u00f6\u00f7\u0005\u000e\u0000\u0000\u00f7\u00f8\u0003"+
		"\u001a\r\u0000\u00f8\u00f9\u0006\f\uffff\uffff\u0000\u00f9\u00fa\u0003"+
		"\u001a\r\u0000\u00fa\u00fb\u0006\f\uffff\uffff\u0000\u00fb\u00fc\u0003"+
		"\u001e\u000f\u0000\u00fc\u00fd\u0006\f\uffff\uffff\u0000\u00fd\u00fe\u0005"+
		"\u000f\u0000\u0000\u00fe\u00ff\u0003\u0018\f\u0000\u00ff\u0100\u0006\f"+
		"\uffff\uffff\u0000\u0100\u0129\u0001\u0000\u0000\u0000\u0101\u0102\u0005"+
		"\u0005\u0000\u0000\u0102\u0103\u0005\u000e\u0000\u0000\u0103\u0104\u0003"+
		"\u001e\u000f\u0000\u0104\u0105\u0006\f\uffff\uffff\u0000\u0105\u0106\u0005"+
		"\u000f\u0000\u0000\u0106\u0107\u0003\u0018\f\u0000\u0107\u0108\u0006\f"+
		"\uffff\uffff\u0000\u0108\u0129\u0001\u0000\u0000\u0000\u0109\u010a\u0005"+
		"\u0005\u0000\u0000\u010a\u010b\u0005\u000e\u0000\u0000\u010b\u010c\u0003"+
		"\u001e\u000f\u0000\u010c\u010d\u0006\f\uffff\uffff\u0000\u010d\u010e\u0005"+
		"\u000f\u0000\u0000\u010e\u010f\u0003\u0018\f\u0000\u010f\u0110\u0006\f"+
		"\uffff\uffff\u0000\u0110\u0111\u0005\u0006\u0000\u0000\u0111\u0112\u0003"+
		"\u0018\f\u0000\u0112\u0113\u0006\f\uffff\uffff\u0000\u0113\u0129\u0001"+
		"\u0000\u0000\u0000\u0114\u0115\u0005\b\u0000\u0000\u0115\u0116\u0006\f"+
		"\uffff\uffff\u0000\u0116\u0117\u0005\u000e\u0000\u0000\u0117\u0118\u0003"+
		"\u001e\u000f\u0000\u0118\u0119\u0006\f\uffff\uffff\u0000\u0119\u011a\u0005"+
		"\u000f\u0000\u0000\u011a\u011b\u0003\u0018\f\u0000\u011b\u011c\u0006\f"+
		"\uffff\uffff\u0000\u011c\u0129\u0001\u0000\u0000\u0000\u011d\u011e\u0005"+
		"\t\u0000\u0000\u011e\u011f\u0005\u000e\u0000\u0000\u011f\u0120\u0005 "+
		"\u0000\u0000\u0120\u0121\u0005\u000f\u0000\u0000\u0121\u0122\u0005\u0014"+
		"\u0000\u0000\u0122\u0129\u0006\f\uffff\uffff\u0000\u0123\u0124\u0005\n"+
		"\u0000\u0000\u0124\u0125\u0003\u001e\u000f\u0000\u0125\u0126\u0005\u0014"+
		"\u0000\u0000\u0126\u0127\u0006\f\uffff\uffff\u0000\u0127\u0129\u0001\u0000"+
		"\u0000\u0000\u0128\u00ec\u0001\u0000\u0000\u0000\u0128\u00ef\u0001\u0000"+
		"\u0000\u0000\u0128\u00f2\u0001\u0000\u0000\u0000\u0128\u00f5\u0001\u0000"+
		"\u0000\u0000\u0128\u0101\u0001\u0000\u0000\u0000\u0128\u0109\u0001\u0000"+
		"\u0000\u0000\u0128\u0114\u0001\u0000\u0000\u0000\u0128\u011d\u0001\u0000"+
		"\u0000\u0000\u0128\u0123\u0001\u0000\u0000\u0000\u0129\u0019\u0001\u0000"+
		"\u0000\u0000\u012a\u012b\u0005\u0014\u0000\u0000\u012b\u0131\u0006\r\uffff"+
		"\uffff\u0000\u012c\u012d\u0003\u001e\u000f\u0000\u012d\u012e\u0005\u0014"+
		"\u0000\u0000\u012e\u012f\u0006\r\uffff\uffff\u0000\u012f\u0131\u0001\u0000"+
		"\u0000\u0000\u0130\u012a\u0001\u0000\u0000\u0000\u0130\u012c\u0001\u0000"+
		"\u0000\u0000\u0131\u001b\u0001\u0000\u0000\u0000\u0132\u0133\u0005 \u0000"+
		"\u0000\u0133\u013b\u0006\u000e\uffff\uffff\u0000\u0134\u0135\u0005 \u0000"+
		"\u0000\u0135\u0136\u0005\u0012\u0000\u0000\u0136\u0137\u0003\u001e\u000f"+
		"\u0000\u0137\u0138\u0005\u0013\u0000\u0000\u0138\u0139\u0006\u000e\uffff"+
		"\uffff\u0000\u0139\u013b\u0001\u0000\u0000\u0000\u013a\u0132\u0001\u0000"+
		"\u0000\u0000\u013a\u0134\u0001\u0000\u0000\u0000\u013b\u001d\u0001\u0000"+
		"\u0000\u0000\u013c\u013d\u0003 \u0010\u0000\u013d\u013e\u0006\u000f\uffff"+
		"\uffff\u0000\u013e\u0145\u0001\u0000\u0000\u0000\u013f\u0140\u0003\u001c"+
		"\u000e\u0000\u0140\u0141\u0005\u001f\u0000\u0000\u0141\u0142\u0003 \u0010"+
		"\u0000\u0142\u0143\u0006\u000f\uffff\uffff\u0000\u0143\u0145\u0001\u0000"+
		"\u0000\u0000\u0144\u013c\u0001\u0000\u0000\u0000\u0144\u013f\u0001\u0000"+
		"\u0000\u0000\u0145\u001f\u0001\u0000\u0000\u0000\u0146\u0147\u0003\"\u0011"+
		"\u0000\u0147\u0148\u0006\u0010\uffff\uffff\u0000\u0148\u014f\u0001\u0000"+
		"\u0000\u0000\u0149\u014a\u0003\"\u0011\u0000\u014a\u014b\u0005\u001e\u0000"+
		"\u0000\u014b\u014c\u0003\"\u0011\u0000\u014c\u014d\u0006\u0010\uffff\uffff"+
		"\u0000\u014d\u014f\u0001\u0000\u0000\u0000\u014e\u0146\u0001\u0000\u0000"+
		"\u0000\u014e\u0149\u0001\u0000\u0000\u0000\u014f!\u0001\u0000\u0000\u0000"+
		"\u0150\u0151\u0003$\u0012\u0000\u0151\u0152\u0006\u0011\uffff\uffff\u0000"+
		"\u0152\u0159\u0001\u0000\u0000\u0000\u0153\u0154\u0003$\u0012\u0000\u0154"+
		"\u0155\u0005\u001d\u0000\u0000\u0155\u0156\u0003$\u0012\u0000\u0156\u0157"+
		"\u0006\u0011\uffff\uffff\u0000\u0157\u0159\u0001\u0000\u0000\u0000\u0158"+
		"\u0150\u0001\u0000\u0000\u0000\u0158\u0153\u0001\u0000\u0000\u0000\u0159"+
		"#\u0001\u0000\u0000\u0000\u015a\u015b\u0006\u0012\uffff\uffff\u0000\u015b"+
		"\u015c\u0003&\u0013\u0000\u015c\u015d\u0006\u0012\uffff\uffff\u0000\u015d"+
		"\u0165\u0001\u0000\u0000\u0000\u015e\u015f\n\u0001\u0000\u0000\u015f\u0160"+
		"\u0005\u0017\u0000\u0000\u0160\u0161\u0003&\u0013\u0000\u0161\u0162\u0006"+
		"\u0012\uffff\uffff\u0000\u0162\u0164\u0001\u0000\u0000\u0000\u0163\u015e"+
		"\u0001\u0000\u0000\u0000\u0164\u0167\u0001\u0000\u0000\u0000\u0165\u0163"+
		"\u0001\u0000\u0000\u0000\u0165\u0166\u0001\u0000\u0000\u0000\u0166%\u0001"+
		"\u0000\u0000\u0000\u0167\u0165\u0001\u0000\u0000\u0000\u0168\u0169\u0006"+
		"\u0013\uffff\uffff\u0000\u0169\u016a\u0003(\u0014\u0000\u016a\u016b\u0006"+
		"\u0013\uffff\uffff\u0000\u016b\u0173\u0001\u0000\u0000\u0000\u016c\u016d"+
		"\n\u0001\u0000\u0000\u016d\u016e\u0005\u0019\u0000\u0000\u016e\u016f\u0003"+
		"(\u0014\u0000\u016f\u0170\u0006\u0013\uffff\uffff\u0000\u0170\u0172\u0001"+
		"\u0000\u0000\u0000\u0171\u016c\u0001\u0000\u0000\u0000\u0172\u0175\u0001"+
		"\u0000\u0000\u0000\u0173\u0171\u0001\u0000\u0000\u0000\u0173\u0174\u0001"+
		"\u0000\u0000\u0000\u0174\'\u0001\u0000\u0000\u0000\u0175\u0173\u0001\u0000"+
		"\u0000\u0000\u0176\u0177\u0005\u0017\u0000\u0000\u0177\u0178\u0003(\u0014"+
		"\u0000\u0178\u0179\u0006\u0014\uffff\uffff\u0000\u0179\u0182\u0001\u0000"+
		"\u0000\u0000\u017a\u017b\u0005\u001c\u0000\u0000\u017b\u017c\u0003(\u0014"+
		"\u0000\u017c\u017d\u0006\u0014\uffff\uffff\u0000\u017d\u0182\u0001\u0000"+
		"\u0000\u0000\u017e\u017f\u0003*\u0015\u0000\u017f\u0180\u0006\u0014\uffff"+
		"\uffff\u0000\u0180\u0182\u0001\u0000\u0000\u0000\u0181\u0176\u0001\u0000"+
		"\u0000\u0000\u0181\u017a\u0001\u0000\u0000\u0000\u0181\u017e\u0001\u0000"+
		"\u0000\u0000\u0182)\u0001\u0000\u0000\u0000\u0183\u0184\u0003\u001c\u000e"+
		"\u0000\u0184\u0185\u0006\u0015\uffff\uffff\u0000\u0185\u019f\u0001\u0000"+
		"\u0000\u0000\u0186\u0187\u0005 \u0000\u0000\u0187\u0188\u0005\u000e\u0000"+
		"\u0000\u0188\u0189\u0006\u0015\uffff\uffff\u0000\u0189\u018a\u0003,\u0016"+
		"\u0000\u018a\u018b\u0005\u000f\u0000\u0000\u018b\u018c\u0006\u0015\uffff"+
		"\uffff\u0000\u018c\u019f\u0001\u0000\u0000\u0000\u018d\u018e\u0005\u000e"+
		"\u0000\u0000\u018e\u018f\u0003\u001e\u000f\u0000\u018f\u0190\u0005\u000f"+
		"\u0000\u0000\u0190\u0191\u0006\u0015\uffff\uffff\u0000\u0191\u019f\u0001"+
		"\u0000\u0000\u0000\u0192\u0193\u0005!\u0000\u0000\u0193\u019f\u0006\u0015"+
		"\uffff\uffff\u0000\u0194\u0195\u0005\"\u0000\u0000\u0195\u019f\u0006\u0015"+
		"\uffff\uffff\u0000\u0196\u0197\u0003\u001c\u000e\u0000\u0197\u0198\u0005"+
		"\u001a\u0000\u0000\u0198\u0199\u0006\u0015\uffff\uffff\u0000\u0199\u019f"+
		"\u0001\u0000\u0000\u0000\u019a\u019b\u0003\u001c\u000e\u0000\u019b\u019c"+
		"\u0005\u001b\u0000\u0000\u019c\u019d\u0006\u0015\uffff\uffff\u0000\u019d"+
		"\u019f\u0001\u0000\u0000\u0000\u019e\u0183\u0001\u0000\u0000\u0000\u019e"+
		"\u0186\u0001\u0000\u0000\u0000\u019e\u018d\u0001\u0000\u0000\u0000\u019e"+
		"\u0192\u0001\u0000\u0000\u0000\u019e\u0194\u0001\u0000\u0000\u0000\u019e"+
		"\u0196\u0001\u0000\u0000\u0000\u019e\u019a\u0001\u0000\u0000\u0000\u019f"+
		"+\u0001\u0000\u0000\u0000\u01a0\u01a1\u0003.\u0017\u0000\u01a1\u01a2\u0006"+
		"\u0016\uffff\uffff\u0000\u01a2\u01a5\u0001\u0000\u0000\u0000\u01a3\u01a5"+
		"\u0001\u0000\u0000\u0000\u01a4\u01a0\u0001\u0000\u0000\u0000\u01a4\u01a3"+
		"\u0001\u0000\u0000\u0000\u01a5-\u0001\u0000\u0000\u0000\u01a6\u01a7\u0006"+
		"\u0017\uffff\uffff\u0000\u01a7\u01a8\u0003 \u0010\u0000\u01a8\u01a9\u0006"+
		"\u0017\uffff\uffff\u0000\u01a9\u01b1\u0001\u0000\u0000\u0000\u01aa\u01ab"+
		"\n\u0002\u0000\u0000\u01ab\u01ac\u0005\u0015\u0000\u0000\u01ac\u01ad\u0003"+
		" \u0010\u0000\u01ad\u01ae\u0006\u0017\uffff\uffff\u0000\u01ae\u01b0\u0001"+
		"\u0000\u0000\u0000\u01af\u01aa\u0001\u0000\u0000\u0000\u01b0\u01b3\u0001"+
		"\u0000\u0000\u0000\u01b1\u01af\u0001\u0000\u0000\u0000\u01b1\u01b2\u0001"+
		"\u0000\u0000\u0000\u01b2/\u0001\u0000\u0000\u0000\u01b3\u01b1\u0001\u0000"+
		"\u0000\u0000\u001a>J\\r\u0082\u0093\u0095\u00a3\u00af\u00b9\u00c8\u00da"+
		"\u00dc\u00e9\u0128\u0130\u013a\u0144\u014e\u0158\u0165\u0173\u0181\u019e"+
		"\u01a4\u01b1";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}