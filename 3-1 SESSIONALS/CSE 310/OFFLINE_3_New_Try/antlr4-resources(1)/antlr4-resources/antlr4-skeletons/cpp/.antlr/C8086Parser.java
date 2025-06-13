// Generated from /home/nidhi/3-1/LABS/BUET-ACADEMICS/3-1 SESSIONALS/CSE 310/OFFLINE_3_New_Try/antlr4-resources(1)/antlr4-resources/antlr4-skeletons/cpp/C8086Parser.g4 by ANTLR 4.13.1

    #include <iostream>
    #include <fstream>
    #include <string>
    #include <cstdlib>
    #include "C8086Lexer.h"

    extern std::ofstream parserLogFile;
    extern std::ofstream errorFile;
	extern std::ofstream lexLogFile;


    extern int syntaxErrorCount;

import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.misc.*;
import org.antlr.v4.runtime.tree.*;
import java.util.List;
import java.util.Iterator;
import java.util.ArrayList;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast", "CheckReturnValue"})
public class C8086Parser extends Parser {
	static { RuntimeMetaData.checkVersion("4.13.1", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		LINE_COMMENT=1, BLOCK_COMMENT=2, STRING=3, WS=4, IF=5, ELSE=6, FOR=7, 
		WHILE=8, PRINTLN=9, RETURN=10, INT=11, FLOAT=12, VOID=13, LPAREN=14, RPAREN=15, 
		LCURL=16, RCURL=17, LTHIRD=18, RTHIRD=19, SEMICOLON=20, COMMA=21, ADDOP=22, 
		SUBOP=23, MULOP=24, INCOP=25, DECOP=26, NOT=27, RELOP=28, LOGICOP=29, 
		ASSIGNOP=30, ID=31, CONST_INT=32, CONST_FLOAT=33;
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
			"'['", "']'", "';'", "','", null, null, null, "'++'", "'--'", "'!'", 
			null, null, "'='"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, "LINE_COMMENT", "BLOCK_COMMENT", "STRING", "WS", "IF", "ELSE", 
			"FOR", "WHILE", "PRINTLN", "RETURN", "INT", "FLOAT", "VOID", "LPAREN", 
			"RPAREN", "LCURL", "RCURL", "LTHIRD", "RTHIRD", "SEMICOLON", "COMMA", 
			"ADDOP", "SUBOP", "MULOP", "INCOP", "DECOP", "NOT", "RELOP", "LOGICOP", 
			"ASSIGNOP", "ID", "CONST_INT", "CONST_FLOAT"
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
	public String getGrammarFileName() { return "C8086Parser.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public ATN getATN() { return _ATN; }


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

	public C8086Parser(TokenStream input) {
		super(input);
		_interp = new ParserATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	@SuppressWarnings("CheckReturnValue")
	public static class StartContext extends ParserRuleContext {
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
			setState(48);
			program(0);

			        writeIntoparserLogFile("Parsing completed successfully with " + std::to_string(syntaxErrorCount) + " syntax errors.");
				
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
			setState(52);
			unit();
			}
			_ctx.stop = _input.LT(-1);
			setState(58);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,0,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					{
					_localctx = new ProgramContext(_parentctx, _parentState);
					pushNewRecursionContext(_localctx, _startState, RULE_program);
					setState(54);
					if (!(precpred(_ctx, 2))) throw new FailedPredicateException(this, "precpred(_ctx, 2)");
					setState(55);
					unit();
					}
					} 
				}
				setState(60);
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
			setState(64);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,1,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(61);
				var_declaration();
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(62);
				func_declaration();
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(63);
				func_definition();
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
		public Type_specifierContext type_specifier() {
			return getRuleContext(Type_specifierContext.class,0);
		}
		public TerminalNode ID() { return getToken(C8086Parser.ID, 0); }
		public TerminalNode LPAREN() { return getToken(C8086Parser.LPAREN, 0); }
		public Parameter_listContext parameter_list() {
			return getRuleContext(Parameter_listContext.class,0);
		}
		public TerminalNode RPAREN() { return getToken(C8086Parser.RPAREN, 0); }
		public TerminalNode SEMICOLON() { return getToken(C8086Parser.SEMICOLON, 0); }
		public Func_declarationContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_func_declaration; }
	}

	public final Func_declarationContext func_declaration() throws RecognitionException {
		Func_declarationContext _localctx = new Func_declarationContext(_ctx, getState());
		enterRule(_localctx, 6, RULE_func_declaration);
		try {
			setState(79);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,2,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(66);
				type_specifier();
				setState(67);
				match(ID);
				setState(68);
				match(LPAREN);
				setState(69);
				parameter_list(0);
				setState(70);
				match(RPAREN);
				setState(71);
				match(SEMICOLON);
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(73);
				type_specifier();
				setState(74);
				match(ID);
				setState(75);
				match(LPAREN);
				setState(76);
				match(RPAREN);
				setState(77);
				match(SEMICOLON);
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
		public Type_specifierContext type_specifier() {
			return getRuleContext(Type_specifierContext.class,0);
		}
		public TerminalNode ID() { return getToken(C8086Parser.ID, 0); }
		public TerminalNode LPAREN() { return getToken(C8086Parser.LPAREN, 0); }
		public Parameter_listContext parameter_list() {
			return getRuleContext(Parameter_listContext.class,0);
		}
		public TerminalNode RPAREN() { return getToken(C8086Parser.RPAREN, 0); }
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
			setState(94);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,3,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(81);
				type_specifier();
				setState(82);
				match(ID);
				setState(83);
				match(LPAREN);
				setState(84);
				parameter_list(0);
				setState(85);
				match(RPAREN);
				setState(86);
				compound_statement();
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(88);
				type_specifier();
				setState(89);
				match(ID);
				setState(90);
				match(LPAREN);
				setState(91);
				match(RPAREN);
				setState(92);
				compound_statement();
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
		public Type_specifierContext type_specifier;
		public Token ID;
		public Token COMMA;
		public Type_specifierContext type_specifier() {
			return getRuleContext(Type_specifierContext.class,0);
		}
		public TerminalNode ID() { return getToken(C8086Parser.ID, 0); }
		public Parameter_listContext parameter_list() {
			return getRuleContext(Parameter_listContext.class,0);
		}
		public TerminalNode COMMA() { return getToken(C8086Parser.COMMA, 0); }
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
			setState(104);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,4,_ctx) ) {
			case 1:
				{
				setState(97);
				((Parameter_listContext)_localctx).type_specifier = type_specifier();
				setState(98);
				((Parameter_listContext)_localctx).ID = match(ID);
				writeIntoLexLogFile("Line " + std::to_string(((Parameter_listContext)_localctx).ID->getLine()) +": parameter_list : type_specifier ID\n\n" + ((Parameter_listContext)_localctx).type_specifier.name_line + " " + ((Parameter_listContext)_localctx).ID->getText() + "\n");
						
				}
				break;
			case 2:
				{
				setState(101);
				((Parameter_listContext)_localctx).type_specifier = type_specifier();
				writeIntoLexLogFile("Line " + std::to_string((((Parameter_listContext)_localctx).type_specifier!=null?(((Parameter_listContext)_localctx).type_specifier.start):null)->getLine()) + ": parameter_list : type_specifier \n" +((Parameter_listContext)_localctx).type_specifier.name_line+ "\n");
						
				}
				break;
			}
			_ctx.stop = _input.LT(-1);
			setState(119);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,6,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					setState(117);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,5,_ctx) ) {
					case 1:
						{
						_localctx = new Parameter_listContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_parameter_list);
						setState(106);
						if (!(precpred(_ctx, 4))) throw new FailedPredicateException(this, "precpred(_ctx, 4)");
						setState(107);
						((Parameter_listContext)_localctx).COMMA = match(COMMA);
						setState(108);
						((Parameter_listContext)_localctx).type_specifier = type_specifier();
						setState(109);
						((Parameter_listContext)_localctx).ID = match(ID);
						writeIntoLexLogFile("Line " + std::to_string(((Parameter_listContext)_localctx).ID->getLine()) + ": parameter_list : type_specifier ID\n" +((Parameter_listContext)_localctx).type_specifier.name_line +" " + ((Parameter_listContext)_localctx).ID->getText() + "\n");
						          		
						}
						break;
					case 2:
						{
						_localctx = new Parameter_listContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_parameter_list);
						setState(112);
						if (!(precpred(_ctx, 3))) throw new FailedPredicateException(this, "precpred(_ctx, 3)");
						setState(113);
						((Parameter_listContext)_localctx).COMMA = match(COMMA);
						setState(114);
						((Parameter_listContext)_localctx).type_specifier = type_specifier();
						writeIntoLexLogFile("Line " + std::to_string(((Parameter_listContext)_localctx).COMMA->getLine()) + ": parameter_list : type_specifier \n" +((Parameter_listContext)_localctx).type_specifier.name_line + "\n");
						          		
						}
						break;
					}
					} 
				}
				setState(121);
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
		public Token LCURL;
		public StatementsContext ss;
		public Token RCURL;
		public TerminalNode LCURL() { return getToken(C8086Parser.LCURL, 0); }
		public TerminalNode RCURL() { return getToken(C8086Parser.RCURL, 0); }
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
			setState(130);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,7,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(122);
				((Compound_statementContext)_localctx).LCURL = match(LCURL);
				setState(123);
				((Compound_statementContext)_localctx).ss = statements(0);
				setState(124);
				((Compound_statementContext)_localctx).RCURL = match(RCURL);

				        ((Compound_statementContext)_localctx).text =  ((Compound_statementContext)_localctx).LCURL->getText()+"\n" + ((Compound_statementContext)_localctx).ss.text +"\n" + ((Compound_statementContext)_localctx).RCURL->getText();
				        ((Compound_statementContext)_localctx).line =  ((Compound_statementContext)_localctx).ss.line;

				    
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(127);
				((Compound_statementContext)_localctx).LCURL = match(LCURL);
				setState(128);
				match(RCURL);

				        ((Compound_statementContext)_localctx).text =  ((Compound_statementContext)_localctx).LCURL->getText();
				        ((Compound_statementContext)_localctx).line =  ((Compound_statementContext)_localctx).LCURL->getLine();
				    
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
		public TerminalNode SEMICOLON() { return getToken(C8086Parser.SEMICOLON, 0); }
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
			setState(142);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,8,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(132);
				((Var_declarationContext)_localctx).t = type_specifier();
				setState(133);
				((Var_declarationContext)_localctx).dl = declaration_list(0);
				setState(134);
				((Var_declarationContext)_localctx).sm = match(SEMICOLON);

				        ((Var_declarationContext)_localctx).text =  ((Var_declarationContext)_localctx).t.name_line +" "+ ((Var_declarationContext)_localctx).dl.text + ((Var_declarationContext)_localctx).sm->getText() ;
				        ((Var_declarationContext)_localctx).line =  ((Var_declarationContext)_localctx).t.line;
				        writeIntoparserLogFile(
				            std::string("Variable Declaration: type_specifier declaration_list ") +
				            std::to_string(((Var_declarationContext)_localctx).sm->getType()) +
				            " at line " + std::to_string(((Var_declarationContext)_localctx).sm->getLine())
				        );

				        writeIntoparserLogFile("type_specifier name_line: " + ((Var_declarationContext)_localctx).t.name_line);

				        
				      
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(137);
				((Var_declarationContext)_localctx).t = type_specifier();
				setState(138);
				((Var_declarationContext)_localctx).de = declaration_list_err();
				setState(139);
				((Var_declarationContext)_localctx).sm = match(SEMICOLON);

				        ((Var_declarationContext)_localctx).text =  ((Var_declarationContext)_localctx).t.name_line;
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
		public std::string name_line;
		public int line;
		public Token INT;
		public Token FLOAT;
		public Token VOID;
		public TerminalNode INT() { return getToken(C8086Parser.INT, 0); }
		public TerminalNode FLOAT() { return getToken(C8086Parser.FLOAT, 0); }
		public TerminalNode VOID() { return getToken(C8086Parser.VOID, 0); }
		public Type_specifierContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_type_specifier; }
	}

	public final Type_specifierContext type_specifier() throws RecognitionException {
		Type_specifierContext _localctx = new Type_specifierContext(_ctx, getState());
		enterRule(_localctx, 18, RULE_type_specifier);
		try {
			setState(152);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case INT:
				enterOuterAlt(_localctx, 1);
				{
				setState(146);
				((Type_specifierContext)_localctx).INT = match(INT);

				            ((Type_specifierContext)_localctx).name_line =  ((Type_specifierContext)_localctx).INT->getText();
				            ((Type_specifierContext)_localctx).line =  ((Type_specifierContext)_localctx).INT->getLine();
							writeIntoLexLogFile("Line " + std::to_string(((Type_specifierContext)_localctx).INT->getLine()) + ": type_specifier : INT\n\n" + ((Type_specifierContext)_localctx).INT->getText() + "\n");
				        
				}
				break;
			case FLOAT:
				enterOuterAlt(_localctx, 2);
				{
				setState(148);
				((Type_specifierContext)_localctx).FLOAT = match(FLOAT);

				            ((Type_specifierContext)_localctx).name_line =  ((Type_specifierContext)_localctx).FLOAT->getText();
				            ((Type_specifierContext)_localctx).line =  ((Type_specifierContext)_localctx).FLOAT->getLine();
							writeIntoLexLogFile("Line " + std::to_string(((Type_specifierContext)_localctx).FLOAT->getLine()) + ": type_specifier : FLOAT\n\n" +((Type_specifierContext)_localctx).FLOAT->getText() + "\n");        
						
				}
				break;
			case VOID:
				enterOuterAlt(_localctx, 3);
				{
				setState(150);
				((Type_specifierContext)_localctx).VOID = match(VOID);

				            ((Type_specifierContext)_localctx).name_line =  ((Type_specifierContext)_localctx).VOID->getText();
				            ((Type_specifierContext)_localctx).line =  ((Type_specifierContext)_localctx).VOID->getLine();
				            writeIntoLexLogFile("Line " + std::to_string(((Type_specifierContext)_localctx).VOID->getLine()) + ": type_specifier : VOID\n\n" +((Type_specifierContext)_localctx).VOID->getText() + "\n");        
				        
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
		public Declaration_listContext dl;
		public Token ID;
		public Token LTHIRD;
		public Token CONST_INT;
		public Token RTHIRD;
		public Token COMMA;
		public TerminalNode ID() { return getToken(C8086Parser.ID, 0); }
		public TerminalNode LTHIRD() { return getToken(C8086Parser.LTHIRD, 0); }
		public TerminalNode CONST_INT() { return getToken(C8086Parser.CONST_INT, 0); }
		public TerminalNode RTHIRD() { return getToken(C8086Parser.RTHIRD, 0); }
		public TerminalNode COMMA() { return getToken(C8086Parser.COMMA, 0); }
		public Declaration_listContext declaration_list() {
			return getRuleContext(Declaration_listContext.class,0);
		}
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
			setState(162);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,10,_ctx) ) {
			case 1:
				{
				setState(155);
				((Declaration_listContext)_localctx).ID = match(ID);
				 
				        ((Declaration_listContext)_localctx).text =  ((Declaration_listContext)_localctx).ID->getText();
				        ((Declaration_listContext)_localctx).line =  ((Declaration_listContext)_localctx).ID->getLine();
				    
				}
				break;
			case 2:
				{
				setState(157);
				((Declaration_listContext)_localctx).ID = match(ID);
				setState(158);
				((Declaration_listContext)_localctx).LTHIRD = match(LTHIRD);
				setState(159);
				((Declaration_listContext)_localctx).CONST_INT = match(CONST_INT);
				setState(160);
				((Declaration_listContext)_localctx).RTHIRD = match(RTHIRD);
				 
				        ((Declaration_listContext)_localctx).text =  ((Declaration_listContext)_localctx).ID->getText() + ((Declaration_listContext)_localctx).LTHIRD->getText() + ((Declaration_listContext)_localctx).CONST_INT->getText() + ((Declaration_listContext)_localctx).RTHIRD->getText();
				        ((Declaration_listContext)_localctx).line =  ((Declaration_listContext)_localctx).ID->getLine();
				    
				}
				break;
			}
			_ctx.stop = _input.LT(-1);
			setState(177);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,12,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					setState(175);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,11,_ctx) ) {
					case 1:
						{
						_localctx = new Declaration_listContext(_parentctx, _parentState);
						_localctx.dl = _prevctx;
						pushNewRecursionContext(_localctx, _startState, RULE_declaration_list);
						setState(164);
						if (!(precpred(_ctx, 4))) throw new FailedPredicateException(this, "precpred(_ctx, 4)");
						setState(165);
						((Declaration_listContext)_localctx).COMMA = match(COMMA);
						setState(166);
						((Declaration_listContext)_localctx).ID = match(ID);
						 
						                  ((Declaration_listContext)_localctx).text =  ((Declaration_listContext)_localctx).dl.text + ((Declaration_listContext)_localctx).COMMA->getText() + ((Declaration_listContext)_localctx).ID->getText();
						                  ((Declaration_listContext)_localctx).line =  ((Declaration_listContext)_localctx).ID->getLine();
						              
						}
						break;
					case 2:
						{
						_localctx = new Declaration_listContext(_parentctx, _parentState);
						_localctx.dl = _prevctx;
						pushNewRecursionContext(_localctx, _startState, RULE_declaration_list);
						setState(168);
						if (!(precpred(_ctx, 3))) throw new FailedPredicateException(this, "precpred(_ctx, 3)");
						setState(169);
						((Declaration_listContext)_localctx).COMMA = match(COMMA);
						setState(170);
						((Declaration_listContext)_localctx).ID = match(ID);
						setState(171);
						((Declaration_listContext)_localctx).LTHIRD = match(LTHIRD);
						setState(172);
						((Declaration_listContext)_localctx).CONST_INT = match(CONST_INT);
						setState(173);
						((Declaration_listContext)_localctx).RTHIRD = match(RTHIRD);
						 
						                  ((Declaration_listContext)_localctx).text =  ((Declaration_listContext)_localctx).dl.text + ((Declaration_listContext)_localctx).COMMA->getText() + ((Declaration_listContext)_localctx).ID->getText();
						                  ((Declaration_listContext)_localctx).line =  ((Declaration_listContext)_localctx).ID->getLine();
						              
						}
						break;
					}
					} 
				}
				setState(179);
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
			setState(181);
			((StatementsContext)_localctx).s = statement();

			        ((StatementsContext)_localctx).text =  ((StatementsContext)_localctx).s.text;
			        ((StatementsContext)_localctx).line =  ((StatementsContext)_localctx).s.line;
			        writeIntoLexLogFile("Line " + std::to_string(((StatementsContext)_localctx).s.line) + ": statements : statement\n\n" + ((StatementsContext)_localctx).s.text+"\n"); 
			    
			}
			_ctx.stop = _input.LT(-1);
			setState(190);
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
					setState(184);
					if (!(precpred(_ctx, 1))) throw new FailedPredicateException(this, "precpred(_ctx, 1)");
					setState(185);
					((StatementsContext)_localctx).s = statement();

					                  ((StatementsContext)_localctx).text =  ((StatementsContext)_localctx).ss.text +"\n" + ((StatementsContext)_localctx).s.text;
					                  ((StatementsContext)_localctx).line =  ((StatementsContext)_localctx).s.line;
					                  writeIntoLexLogFile("Line " + std::to_string(((StatementsContext)_localctx).s.line) + ": statements : statements statement\n\n" +_localctx.text+"\n"); 

					              
					}
					} 
				}
				setState(192);
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
		public TerminalNode FOR() { return getToken(C8086Parser.FOR, 0); }
		public TerminalNode LPAREN() { return getToken(C8086Parser.LPAREN, 0); }
		public TerminalNode RPAREN() { return getToken(C8086Parser.RPAREN, 0); }
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public List<StatementContext> statement() {
			return getRuleContexts(StatementContext.class);
		}
		public StatementContext statement(int i) {
			return getRuleContext(StatementContext.class,i);
		}
		public TerminalNode IF() { return getToken(C8086Parser.IF, 0); }
		public TerminalNode ELSE() { return getToken(C8086Parser.ELSE, 0); }
		public TerminalNode WHILE() { return getToken(C8086Parser.WHILE, 0); }
		public TerminalNode PRINTLN() { return getToken(C8086Parser.PRINTLN, 0); }
		public TerminalNode ID() { return getToken(C8086Parser.ID, 0); }
		public TerminalNode SEMICOLON() { return getToken(C8086Parser.SEMICOLON, 0); }
		public TerminalNode RETURN() { return getToken(C8086Parser.RETURN, 0); }
		public StatementContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_statement; }
	}

	public final StatementContext statement() throws RecognitionException {
		StatementContext _localctx = new StatementContext(_ctx, getState());
		enterRule(_localctx, 24, RULE_statement);
		try {
			setState(245);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,14,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(193);
				((StatementContext)_localctx).v = var_declaration();

				        ((StatementContext)_localctx).text =  ((StatementContext)_localctx).v.text;
				        ((StatementContext)_localctx).line =  ((StatementContext)_localctx).v.line;
				    
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(196);
				((StatementContext)_localctx).es = expression_statement();

				        ((StatementContext)_localctx).text =  ((StatementContext)_localctx).es.text;
				        ((StatementContext)_localctx).line =  ((StatementContext)_localctx).es.line;
				    
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(199);
				((StatementContext)_localctx).cs = compound_statement();

				        ((StatementContext)_localctx).text =  ((StatementContext)_localctx).cs.text;
				        ((StatementContext)_localctx).line =  ((StatementContext)_localctx).cs.line;
				    
				}
				break;
			case 4:
				enterOuterAlt(_localctx, 4);
				{
				setState(202);
				((StatementContext)_localctx).FOR = match(FOR);
				setState(203);
				((StatementContext)_localctx).LPAREN = match(LPAREN);
				setState(204);
				((StatementContext)_localctx).es1 = expression_statement();
				setState(205);
				((StatementContext)_localctx).es2 = expression_statement();
				setState(206);
				((StatementContext)_localctx).e = expression();
				setState(207);
				((StatementContext)_localctx).RPAREN = match(RPAREN);
				setState(208);
				((StatementContext)_localctx).s = statement();

				        ((StatementContext)_localctx).text =  (((StatementContext)_localctx).FOR!=null?((StatementContext)_localctx).FOR.getText():null) + " " + ((StatementContext)_localctx).LPAREN->getText() + " " +  ((StatementContext)_localctx).es1.text + " " + ((StatementContext)_localctx).es2.text + " " + ((StatementContext)_localctx).e.text  +" " + ((StatementContext)_localctx).RPAREN->getText() +" " + ((StatementContext)_localctx).s.text;
				        ((StatementContext)_localctx).line =  ((StatementContext)_localctx).FOR->getLine();
				        writeIntoLexLogFile("Line " + std::to_string(((StatementContext)_localctx).FOR->getLine()) + ": FOR LPAREN expression_statement expression_statement expression RPAREN statement\n\n" + _localctx.text +"\n"); 

				    
				}
				break;
			case 5:
				enterOuterAlt(_localctx, 5);
				{
				setState(211);
				((StatementContext)_localctx).IF = match(IF);
				setState(212);
				((StatementContext)_localctx).LPAREN = match(LPAREN);
				setState(213);
				((StatementContext)_localctx).e = expression();
				setState(214);
				((StatementContext)_localctx).RPAREN = match(RPAREN);
				setState(215);
				((StatementContext)_localctx).s = statement();

				        ((StatementContext)_localctx).text =  ((StatementContext)_localctx).IF->getText() + " " + ((StatementContext)_localctx).LPAREN->getText() + " " + ((StatementContext)_localctx).e.text  +" " + ((StatementContext)_localctx).RPAREN->getText() +" " + ((StatementContext)_localctx).s.text;
				        ((StatementContext)_localctx).line =  ((StatementContext)_localctx).IF->getLine();
				    
				}
				break;
			case 6:
				enterOuterAlt(_localctx, 6);
				{
				setState(218);
				((StatementContext)_localctx).IF = match(IF);
				setState(219);
				((StatementContext)_localctx).LPAREN = match(LPAREN);
				setState(220);
				((StatementContext)_localctx).e = expression();
				setState(221);
				((StatementContext)_localctx).RPAREN = match(RPAREN);
				setState(222);
				((StatementContext)_localctx).s1 = statement();
				setState(223);
				((StatementContext)_localctx).ELSE = match(ELSE);
				setState(224);
				((StatementContext)_localctx).s2 = statement();

				        ((StatementContext)_localctx).text =  ((StatementContext)_localctx).IF->getText() + " " + ((StatementContext)_localctx).LPAREN->getText() + " " + ((StatementContext)_localctx).e.text  +" " + ((StatementContext)_localctx).RPAREN->getText() +" " + ((StatementContext)_localctx).s1.text+ " " + ((StatementContext)_localctx).ELSE->getText() + " " + ((StatementContext)_localctx).s2.text ;
				        ((StatementContext)_localctx).line =  ((StatementContext)_localctx).IF->getLine();
				    
				}
				break;
			case 7:
				enterOuterAlt(_localctx, 7);
				{
				setState(227);
				((StatementContext)_localctx).WHILE = match(WHILE);
				setState(228);
				((StatementContext)_localctx).LPAREN = match(LPAREN);
				setState(229);
				((StatementContext)_localctx).e = expression();
				setState(230);
				((StatementContext)_localctx).RPAREN = match(RPAREN);
				setState(231);
				((StatementContext)_localctx).s = statement();

				        ((StatementContext)_localctx).text =  ((StatementContext)_localctx).WHILE->getText() + " " + ((StatementContext)_localctx).LPAREN->getText() + " " + ((StatementContext)_localctx).e.text  +" " + ((StatementContext)_localctx).RPAREN->getText() +" " + ((StatementContext)_localctx).s.text;
				        ((StatementContext)_localctx).line =  ((StatementContext)_localctx).WHILE->getLine();
				    
				}
				break;
			case 8:
				enterOuterAlt(_localctx, 8);
				{
				setState(234);
				((StatementContext)_localctx).PRINTLN = match(PRINTLN);
				setState(235);
				((StatementContext)_localctx).LPAREN = match(LPAREN);
				setState(236);
				((StatementContext)_localctx).ID = match(ID);
				setState(237);
				((StatementContext)_localctx).RPAREN = match(RPAREN);
				setState(238);
				((StatementContext)_localctx).SEMICOLON = match(SEMICOLON);

				        ((StatementContext)_localctx).text =  ((StatementContext)_localctx).PRINTLN->getText() + " " + ((StatementContext)_localctx).LPAREN->getText() + " " + ((StatementContext)_localctx).ID->getText() + " " +  ((StatementContext)_localctx).RPAREN->getText() + " " + ((StatementContext)_localctx).SEMICOLON->getText();
				        ((StatementContext)_localctx).line =  ((StatementContext)_localctx).PRINTLN->getLine();
				    
				}
				break;
			case 9:
				enterOuterAlt(_localctx, 9);
				{
				setState(240);
				((StatementContext)_localctx).RETURN = match(RETURN);
				setState(241);
				((StatementContext)_localctx).e = expression();
				setState(242);
				((StatementContext)_localctx).SEMICOLON = match(SEMICOLON);

				        ((StatementContext)_localctx).text =  ((StatementContext)_localctx).RETURN->getText() + " " + ((StatementContext)_localctx).e.text + ((StatementContext)_localctx).SEMICOLON->getText();
				        ((StatementContext)_localctx).line =  ((StatementContext)_localctx).RETURN->getLine();
				        
				        writeIntoLexLogFile("Line " + std::to_string(((StatementContext)_localctx).SEMICOLON->getLine()) + ": statement : RETURN expression SEMICOLON\n\n" + ((StatementContext)_localctx).RETURN->getText() +" "+ ((StatementContext)_localctx).e.text+ ((StatementContext)_localctx).SEMICOLON->getText() +"\n"); 

				      
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
		public Token SEMICOLON;
		public ExpressionContext e;
		public TerminalNode SEMICOLON() { return getToken(C8086Parser.SEMICOLON, 0); }
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
			setState(253);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case SEMICOLON:
				enterOuterAlt(_localctx, 1);
				{
				setState(247);
				((Expression_statementContext)_localctx).SEMICOLON = match(SEMICOLON);

				        ((Expression_statementContext)_localctx).text =  ((Expression_statementContext)_localctx).SEMICOLON->getText();
				        ((Expression_statementContext)_localctx).line =  ((Expression_statementContext)_localctx).SEMICOLON->getLine();
				    
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
				setState(249);
				((Expression_statementContext)_localctx).e = expression();
				setState(250);
				((Expression_statementContext)_localctx).SEMICOLON = match(SEMICOLON);

				        ((Expression_statementContext)_localctx).text =  ((Expression_statementContext)_localctx).e.text + ((Expression_statementContext)_localctx).SEMICOLON->getText();
				        ((Expression_statementContext)_localctx).line =  ((Expression_statementContext)_localctx).SEMICOLON->getLine();
				    
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
		public Token ID;
		public Token LTHIRD;
		public ExpressionContext e;
		public Token RTHIRD;
		public TerminalNode ID() { return getToken(C8086Parser.ID, 0); }
		public TerminalNode LTHIRD() { return getToken(C8086Parser.LTHIRD, 0); }
		public TerminalNode RTHIRD() { return getToken(C8086Parser.RTHIRD, 0); }
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
			setState(263);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,16,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(255);
				((VariableContext)_localctx).ID = match(ID);

				        ((VariableContext)_localctx).text =  ((VariableContext)_localctx).ID->getText();
				        ((VariableContext)_localctx).line =  ((VariableContext)_localctx).ID->getLine();
				        writeIntoLexLogFile("Line " + std::to_string(((VariableContext)_localctx).ID->getLine()) + ": variable : ID\n\n" + ((VariableContext)_localctx).ID->getText() +"\n"); 
				    
				        
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(257);
				((VariableContext)_localctx).ID = match(ID);
				setState(258);
				((VariableContext)_localctx).LTHIRD = match(LTHIRD);
				setState(259);
				((VariableContext)_localctx).e = expression();
				setState(260);
				((VariableContext)_localctx).RTHIRD = match(RTHIRD);
				 
				        ((VariableContext)_localctx).text =  ((VariableContext)_localctx).ID->getText() + ((VariableContext)_localctx).LTHIRD->getText() + ((VariableContext)_localctx).e.text + ((VariableContext)_localctx).RTHIRD->getText();
				        ((VariableContext)_localctx).line =  ((VariableContext)_localctx).RTHIRD->getLine();
				    
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
		public Logic_expressionContext l;
		public Token ASSIGNOP;
		public Logic_expressionContext logic_expression() {
			return getRuleContext(Logic_expressionContext.class,0);
		}
		public VariableContext variable() {
			return getRuleContext(VariableContext.class,0);
		}
		public TerminalNode ASSIGNOP() { return getToken(C8086Parser.ASSIGNOP, 0); }
		public ExpressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_expression; }
	}

	public final ExpressionContext expression() throws RecognitionException {
		ExpressionContext _localctx = new ExpressionContext(_ctx, getState());
		enterRule(_localctx, 30, RULE_expression);
		try {
			setState(273);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,17,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(265);
				((ExpressionContext)_localctx).l = logic_expression();

				            ((ExpressionContext)_localctx).text = ((ExpressionContext)_localctx).l.text;
				            ((ExpressionContext)_localctx).line = ((ExpressionContext)_localctx).l.line;
				            writeIntoLexLogFile("Line "+  std::to_string(((ExpressionContext)_localctx).l.line)+": expression : logic_expression\n\n" + ((ExpressionContext)_localctx).l.text + "\n"); 
				        
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(268);
				variable();
				setState(269);
				((ExpressionContext)_localctx).ASSIGNOP = match(ASSIGNOP);
				setState(270);
				logic_expression();

				            ((ExpressionContext)_localctx).text = ((ExpressionContext)_localctx).ASSIGNOP->getText();
				            ((ExpressionContext)_localctx).line = ((ExpressionContext)_localctx).ASSIGNOP->getLine();   

				       
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
		public Rel_expressionContext r;
		public Token LOGICOP;
		public List<Rel_expressionContext> rel_expression() {
			return getRuleContexts(Rel_expressionContext.class);
		}
		public Rel_expressionContext rel_expression(int i) {
			return getRuleContext(Rel_expressionContext.class,i);
		}
		public TerminalNode LOGICOP() { return getToken(C8086Parser.LOGICOP, 0); }
		public Logic_expressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_logic_expression; }
	}

	public final Logic_expressionContext logic_expression() throws RecognitionException {
		Logic_expressionContext _localctx = new Logic_expressionContext(_ctx, getState());
		enterRule(_localctx, 32, RULE_logic_expression);
		try {
			setState(283);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,18,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(275);
				((Logic_expressionContext)_localctx).r = rel_expression();

				            ((Logic_expressionContext)_localctx).text =  ((Logic_expressionContext)_localctx).r.text;
				            ((Logic_expressionContext)_localctx).line =  ((Logic_expressionContext)_localctx).r.line;
				            writeIntoLexLogFile("Line "+  std::to_string(((Logic_expressionContext)_localctx).r.line)+": logic_expression : rel_expression\n\n" + ((Logic_expressionContext)_localctx).r.text + "\n"); 

				        
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(278);
				rel_expression();
				setState(279);
				((Logic_expressionContext)_localctx).LOGICOP = match(LOGICOP);
				setState(280);
				rel_expression();

				            ((Logic_expressionContext)_localctx).text =  ((Logic_expressionContext)_localctx).LOGICOP->getText();
				            ((Logic_expressionContext)_localctx).line =  ((Logic_expressionContext)_localctx).LOGICOP->getLine();
				        
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
		public Simple_expressionContext s;
		public Token RELOP;
		public List<Simple_expressionContext> simple_expression() {
			return getRuleContexts(Simple_expressionContext.class);
		}
		public Simple_expressionContext simple_expression(int i) {
			return getRuleContext(Simple_expressionContext.class,i);
		}
		public TerminalNode RELOP() { return getToken(C8086Parser.RELOP, 0); }
		public Rel_expressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_rel_expression; }
	}

	public final Rel_expressionContext rel_expression() throws RecognitionException {
		Rel_expressionContext _localctx = new Rel_expressionContext(_ctx, getState());
		enterRule(_localctx, 34, RULE_rel_expression);
		try {
			setState(293);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,19,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(285);
				((Rel_expressionContext)_localctx).s = simple_expression(0);

				            ((Rel_expressionContext)_localctx).text =  ((Rel_expressionContext)_localctx).s.text;
				            ((Rel_expressionContext)_localctx).line =  ((Rel_expressionContext)_localctx).s.line;
				            writeIntoLexLogFile("Line "+  std::to_string(((Rel_expressionContext)_localctx).s.line)+": rel_expression : simple_expression\n\n" + ((Rel_expressionContext)_localctx).s.text + "\n"); 
				            
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(288);
				simple_expression(0);
				setState(289);
				((Rel_expressionContext)_localctx).RELOP = match(RELOP);
				setState(290);
				simple_expression(0);

				            ((Rel_expressionContext)_localctx).text =  ((Rel_expressionContext)_localctx).RELOP->getText();
				            ((Rel_expressionContext)_localctx).line =  ((Rel_expressionContext)_localctx).RELOP->getLine();
				        
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
		public TermContext t;
		public TermContext term() {
			return getRuleContext(TermContext.class,0);
		}
		public Simple_expressionContext simple_expression() {
			return getRuleContext(Simple_expressionContext.class,0);
		}
		public TerminalNode ADDOP() { return getToken(C8086Parser.ADDOP, 0); }
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
			setState(296);
			((Simple_expressionContext)_localctx).t = term(0);

			            ((Simple_expressionContext)_localctx).text =  ((Simple_expressionContext)_localctx).t.text;
			            ((Simple_expressionContext)_localctx).line =  ((Simple_expressionContext)_localctx).t.line;
			            writeIntoLexLogFile("Line "+  std::to_string(((Simple_expressionContext)_localctx).t.line)+": simple_expression : term\n\n" + ((Simple_expressionContext)_localctx).t.text + "\n"); 
			            
			}
			_ctx.stop = _input.LT(-1);
			setState(306);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,20,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					{
					_localctx = new Simple_expressionContext(_parentctx, _parentState);
					pushNewRecursionContext(_localctx, _startState, RULE_simple_expression);
					setState(299);
					if (!(precpred(_ctx, 1))) throw new FailedPredicateException(this, "precpred(_ctx, 1)");
					setState(300);
					match(ADDOP);
					setState(301);
					term(0);

					                      ((Simple_expressionContext)_localctx).text =  ((Simple_expressionContext)_localctx).t.text;
					                      ((Simple_expressionContext)_localctx).line =  ((Simple_expressionContext)_localctx).t.line;
					                    
					}
					} 
				}
				setState(308);
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
		public Unary_expressionContext u;
		public Token MULOP;
		public Unary_expressionContext unary_expression() {
			return getRuleContext(Unary_expressionContext.class,0);
		}
		public TermContext term() {
			return getRuleContext(TermContext.class,0);
		}
		public TerminalNode MULOP() { return getToken(C8086Parser.MULOP, 0); }
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
			setState(310);
			((TermContext)_localctx).u = unary_expression();

			         
			            ((TermContext)_localctx).text =  ((TermContext)_localctx).u.text;
			            ((TermContext)_localctx).line =  ((TermContext)_localctx).u.line;
			            writeIntoLexLogFile("Line "+  std::to_string(((TermContext)_localctx).u.line)+": term : unary_expression\n\n" + ((TermContext)_localctx).u.text + "\n"); 
			            
			}
			_ctx.stop = _input.LT(-1);
			setState(320);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,21,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					{
					_localctx = new TermContext(_parentctx, _parentState);
					pushNewRecursionContext(_localctx, _startState, RULE_term);
					setState(313);
					if (!(precpred(_ctx, 1))) throw new FailedPredicateException(this, "precpred(_ctx, 1)");
					setState(314);
					((TermContext)_localctx).MULOP = match(MULOP);
					setState(315);
					unary_expression();

					                      ((TermContext)_localctx).text =  ((TermContext)_localctx).MULOP->getText();
					                      ((TermContext)_localctx).line =  ((TermContext)_localctx).MULOP->getLine();
					                  
					}
					} 
				}
				setState(322);
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
		public Token ADDOP;
		public Token NOT;
		public FactorContext f;
		public TerminalNode ADDOP() { return getToken(C8086Parser.ADDOP, 0); }
		public Unary_expressionContext unary_expression() {
			return getRuleContext(Unary_expressionContext.class,0);
		}
		public TerminalNode NOT() { return getToken(C8086Parser.NOT, 0); }
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
			setState(334);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case ADDOP:
				enterOuterAlt(_localctx, 1);
				{
				setState(323);
				((Unary_expressionContext)_localctx).ADDOP = match(ADDOP);
				setState(324);
				unary_expression();

				            ((Unary_expressionContext)_localctx).text =  ((Unary_expressionContext)_localctx).ADDOP->getText();
				            ((Unary_expressionContext)_localctx).line =  ((Unary_expressionContext)_localctx).ADDOP->getLine();
				        
				}
				break;
			case NOT:
				enterOuterAlt(_localctx, 2);
				{
				setState(327);
				((Unary_expressionContext)_localctx).NOT = match(NOT);
				setState(328);
				unary_expression();

				            ((Unary_expressionContext)_localctx).text =  ((Unary_expressionContext)_localctx).NOT->getText();
				            ((Unary_expressionContext)_localctx).line =  ((Unary_expressionContext)_localctx).NOT->getLine();
				        
				}
				break;
			case LPAREN:
			case ID:
			case CONST_INT:
			case CONST_FLOAT:
				enterOuterAlt(_localctx, 3);
				{
				setState(331);
				((Unary_expressionContext)_localctx).f = factor();

				            ((Unary_expressionContext)_localctx).text =  ((Unary_expressionContext)_localctx).f.text;
				            ((Unary_expressionContext)_localctx).line =  ((Unary_expressionContext)_localctx).f.line;
				            writeIntoLexLogFile("Line "+  std::to_string(((Unary_expressionContext)_localctx).f.line)+": unary_expression : factor\n\n" + ((Unary_expressionContext)_localctx).f.text + "\n"); 
				            
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
		public VariableContext v;
		public Token ID;
		public Argument_listContext a;
		public ExpressionContext e;
		public Token CONST_INT;
		public Token CONST_FLOAT;
		public Token INCOP;
		public Token DECOP;
		public VariableContext variable() {
			return getRuleContext(VariableContext.class,0);
		}
		public TerminalNode ID() { return getToken(C8086Parser.ID, 0); }
		public TerminalNode LPAREN() { return getToken(C8086Parser.LPAREN, 0); }
		public TerminalNode RPAREN() { return getToken(C8086Parser.RPAREN, 0); }
		public Argument_listContext argument_list() {
			return getRuleContext(Argument_listContext.class,0);
		}
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public TerminalNode CONST_INT() { return getToken(C8086Parser.CONST_INT, 0); }
		public TerminalNode CONST_FLOAT() { return getToken(C8086Parser.CONST_FLOAT, 0); }
		public TerminalNode INCOP() { return getToken(C8086Parser.INCOP, 0); }
		public TerminalNode DECOP() { return getToken(C8086Parser.DECOP, 0); }
		public FactorContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_factor; }
	}

	public final FactorContext factor() throws RecognitionException {
		FactorContext _localctx = new FactorContext(_ctx, getState());
		enterRule(_localctx, 42, RULE_factor);
		try {
			setState(361);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,23,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(336);
				((FactorContext)_localctx).v = variable();

				        ((FactorContext)_localctx).text =  ((FactorContext)_localctx).v.text;
				        ((FactorContext)_localctx).line =  ((FactorContext)_localctx).v.line;
				        writeIntoLexLogFile("Line "+  std::to_string(((FactorContext)_localctx).v.line)+": factor : variable\n\n" + ((FactorContext)_localctx).v.text + "\n");
				        
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(339);
				((FactorContext)_localctx).ID = match(ID);
				setState(340);
				match(LPAREN);
				setState(341);
				((FactorContext)_localctx).a = argument_list();
				setState(342);
				match(RPAREN);

				        ((FactorContext)_localctx).text =  ((FactorContext)_localctx).ID->getText();
				        ((FactorContext)_localctx).line =  ((FactorContext)_localctx).ID->getLine();
				    
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(345);
				match(LPAREN);
				setState(346);
				((FactorContext)_localctx).e = expression();
				setState(347);
				match(RPAREN);
				}
				break;
			case 4:
				enterOuterAlt(_localctx, 4);
				{
				setState(349);
				((FactorContext)_localctx).CONST_INT = match(CONST_INT);

				        ((FactorContext)_localctx).text =  ((FactorContext)_localctx).CONST_INT->getText();
				        ((FactorContext)_localctx).line =  ((FactorContext)_localctx).CONST_INT->getLine();
				    
				}
				break;
			case 5:
				enterOuterAlt(_localctx, 5);
				{
				setState(351);
				((FactorContext)_localctx).CONST_FLOAT = match(CONST_FLOAT);

				        ((FactorContext)_localctx).text =  ((FactorContext)_localctx).CONST_FLOAT->getText();
				        ((FactorContext)_localctx).line =  ((FactorContext)_localctx).CONST_FLOAT->getLine();
				        writeIntoLexLogFile("Line "+  std::to_string(_localctx.line)+": factor : CONST_FLOAT\n\n" + _localctx.text + "\n");

				    
				}
				break;
			case 6:
				enterOuterAlt(_localctx, 6);
				{
				setState(353);
				((FactorContext)_localctx).v = variable();
				setState(354);
				((FactorContext)_localctx).INCOP = match(INCOP);

				        ((FactorContext)_localctx).text =  ((FactorContext)_localctx).INCOP->getText();
				        ((FactorContext)_localctx).line =  ((FactorContext)_localctx).INCOP->getLine();
				    
				}
				break;
			case 7:
				enterOuterAlt(_localctx, 7);
				{
				setState(357);
				((FactorContext)_localctx).v = variable();
				setState(358);
				((FactorContext)_localctx).DECOP = match(DECOP);

				        ((FactorContext)_localctx).text =  ((FactorContext)_localctx).DECOP->getText();
				        ((FactorContext)_localctx).line =  ((FactorContext)_localctx).DECOP->getLine();
				    
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
			setState(365);
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
				setState(363);
				arguments(0);
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
		public Logic_expressionContext logic_expression() {
			return getRuleContext(Logic_expressionContext.class,0);
		}
		public ArgumentsContext arguments() {
			return getRuleContext(ArgumentsContext.class,0);
		}
		public TerminalNode COMMA() { return getToken(C8086Parser.COMMA, 0); }
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
			setState(368);
			logic_expression();
			}
			_ctx.stop = _input.LT(-1);
			setState(375);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,25,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					{
					_localctx = new ArgumentsContext(_parentctx, _parentState);
					pushNewRecursionContext(_localctx, _startState, RULE_arguments);
					setState(370);
					if (!(precpred(_ctx, 2))) throw new FailedPredicateException(this, "precpred(_ctx, 2)");
					setState(371);
					match(COMMA);
					setState(372);
					logic_expression();
					}
					} 
				}
				setState(377);
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
			return precpred(_ctx, 4);
		case 2:
			return precpred(_ctx, 3);
		}
		return true;
	}
	private boolean declaration_list_sempred(Declaration_listContext _localctx, int predIndex) {
		switch (predIndex) {
		case 3:
			return precpred(_ctx, 4);
		case 4:
			return precpred(_ctx, 3);
		}
		return true;
	}
	private boolean statements_sempred(StatementsContext _localctx, int predIndex) {
		switch (predIndex) {
		case 5:
			return precpred(_ctx, 1);
		}
		return true;
	}
	private boolean simple_expression_sempred(Simple_expressionContext _localctx, int predIndex) {
		switch (predIndex) {
		case 6:
			return precpred(_ctx, 1);
		}
		return true;
	}
	private boolean term_sempred(TermContext _localctx, int predIndex) {
		switch (predIndex) {
		case 7:
			return precpred(_ctx, 1);
		}
		return true;
	}
	private boolean arguments_sempred(ArgumentsContext _localctx, int predIndex) {
		switch (predIndex) {
		case 8:
			return precpred(_ctx, 2);
		}
		return true;
	}

	public static final String _serializedATN =
		"\u0004\u0001!\u017b\u0002\u0000\u0007\u0000\u0002\u0001\u0007\u0001\u0002"+
		"\u0002\u0007\u0002\u0002\u0003\u0007\u0003\u0002\u0004\u0007\u0004\u0002"+
		"\u0005\u0007\u0005\u0002\u0006\u0007\u0006\u0002\u0007\u0007\u0007\u0002"+
		"\b\u0007\b\u0002\t\u0007\t\u0002\n\u0007\n\u0002\u000b\u0007\u000b\u0002"+
		"\f\u0007\f\u0002\r\u0007\r\u0002\u000e\u0007\u000e\u0002\u000f\u0007\u000f"+
		"\u0002\u0010\u0007\u0010\u0002\u0011\u0007\u0011\u0002\u0012\u0007\u0012"+
		"\u0002\u0013\u0007\u0013\u0002\u0014\u0007\u0014\u0002\u0015\u0007\u0015"+
		"\u0002\u0016\u0007\u0016\u0002\u0017\u0007\u0017\u0001\u0000\u0001\u0000"+
		"\u0001\u0000\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001"+
		"\u0005\u00019\b\u0001\n\u0001\f\u0001<\t\u0001\u0001\u0002\u0001\u0002"+
		"\u0001\u0002\u0003\u0002A\b\u0002\u0001\u0003\u0001\u0003\u0001\u0003"+
		"\u0001\u0003\u0001\u0003\u0001\u0003\u0001\u0003\u0001\u0003\u0001\u0003"+
		"\u0001\u0003\u0001\u0003\u0001\u0003\u0001\u0003\u0003\u0003P\b\u0003"+
		"\u0001\u0004\u0001\u0004\u0001\u0004\u0001\u0004\u0001\u0004\u0001\u0004"+
		"\u0001\u0004\u0001\u0004\u0001\u0004\u0001\u0004\u0001\u0004\u0001\u0004"+
		"\u0001\u0004\u0003\u0004_\b\u0004\u0001\u0005\u0001\u0005\u0001\u0005"+
		"\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005\u0003\u0005"+
		"i\b\u0005\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005"+
		"\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005"+
		"\u0005\u0005v\b\u0005\n\u0005\f\u0005y\t\u0005\u0001\u0006\u0001\u0006"+
		"\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006"+
		"\u0003\u0006\u0083\b\u0006\u0001\u0007\u0001\u0007\u0001\u0007\u0001\u0007"+
		"\u0001\u0007\u0001\u0007\u0001\u0007\u0001\u0007\u0001\u0007\u0001\u0007"+
		"\u0003\u0007\u008f\b\u0007\u0001\b\u0001\b\u0001\t\u0001\t\u0001\t\u0001"+
		"\t\u0001\t\u0001\t\u0003\t\u0099\b\t\u0001\n\u0001\n\u0001\n\u0001\n\u0001"+
		"\n\u0001\n\u0001\n\u0001\n\u0003\n\u00a3\b\n\u0001\n\u0001\n\u0001\n\u0001"+
		"\n\u0001\n\u0001\n\u0001\n\u0001\n\u0001\n\u0001\n\u0001\n\u0005\n\u00b0"+
		"\b\n\n\n\f\n\u00b3\t\n\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b"+
		"\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0005\u000b\u00bd\b\u000b"+
		"\n\u000b\f\u000b\u00c0\t\u000b\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f"+
		"\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001"+
		"\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001"+
		"\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001"+
		"\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001"+
		"\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001"+
		"\f\u0001\f\u0001\f\u0003\f\u00f6\b\f\u0001\r\u0001\r\u0001\r\u0001\r\u0001"+
		"\r\u0001\r\u0003\r\u00fe\b\r\u0001\u000e\u0001\u000e\u0001\u000e\u0001"+
		"\u000e\u0001\u000e\u0001\u000e\u0001\u000e\u0001\u000e\u0003\u000e\u0108"+
		"\b\u000e\u0001\u000f\u0001\u000f\u0001\u000f\u0001\u000f\u0001\u000f\u0001"+
		"\u000f\u0001\u000f\u0001\u000f\u0003\u000f\u0112\b\u000f\u0001\u0010\u0001"+
		"\u0010\u0001\u0010\u0001\u0010\u0001\u0010\u0001\u0010\u0001\u0010\u0001"+
		"\u0010\u0003\u0010\u011c\b\u0010\u0001\u0011\u0001\u0011\u0001\u0011\u0001"+
		"\u0011\u0001\u0011\u0001\u0011\u0001\u0011\u0001\u0011\u0003\u0011\u0126"+
		"\b\u0011\u0001\u0012\u0001\u0012\u0001\u0012\u0001\u0012\u0001\u0012\u0001"+
		"\u0012\u0001\u0012\u0001\u0012\u0001\u0012\u0005\u0012\u0131\b\u0012\n"+
		"\u0012\f\u0012\u0134\t\u0012\u0001\u0013\u0001\u0013\u0001\u0013\u0001"+
		"\u0013\u0001\u0013\u0001\u0013\u0001\u0013\u0001\u0013\u0001\u0013\u0005"+
		"\u0013\u013f\b\u0013\n\u0013\f\u0013\u0142\t\u0013\u0001\u0014\u0001\u0014"+
		"\u0001\u0014\u0001\u0014\u0001\u0014\u0001\u0014\u0001\u0014\u0001\u0014"+
		"\u0001\u0014\u0001\u0014\u0001\u0014\u0003\u0014\u014f\b\u0014\u0001\u0015"+
		"\u0001\u0015\u0001\u0015\u0001\u0015\u0001\u0015\u0001\u0015\u0001\u0015"+
		"\u0001\u0015\u0001\u0015\u0001\u0015\u0001\u0015\u0001\u0015\u0001\u0015"+
		"\u0001\u0015\u0001\u0015\u0001\u0015\u0001\u0015\u0001\u0015\u0001\u0015"+
		"\u0001\u0015\u0001\u0015\u0001\u0015\u0001\u0015\u0001\u0015\u0001\u0015"+
		"\u0003\u0015\u016a\b\u0015\u0001\u0016\u0001\u0016\u0003\u0016\u016e\b"+
		"\u0016\u0001\u0017\u0001\u0017\u0001\u0017\u0001\u0017\u0001\u0017\u0001"+
		"\u0017\u0005\u0017\u0176\b\u0017\n\u0017\f\u0017\u0179\t\u0017\u0001\u0017"+
		"\u0000\u0007\u0002\n\u0014\u0016$&.\u0018\u0000\u0002\u0004\u0006\b\n"+
		"\f\u000e\u0010\u0012\u0014\u0016\u0018\u001a\u001c\u001e \"$&(*,.\u0000"+
		"\u0000\u018b\u00000\u0001\u0000\u0000\u0000\u00023\u0001\u0000\u0000\u0000"+
		"\u0004@\u0001\u0000\u0000\u0000\u0006O\u0001\u0000\u0000\u0000\b^\u0001"+
		"\u0000\u0000\u0000\nh\u0001\u0000\u0000\u0000\f\u0082\u0001\u0000\u0000"+
		"\u0000\u000e\u008e\u0001\u0000\u0000\u0000\u0010\u0090\u0001\u0000\u0000"+
		"\u0000\u0012\u0098\u0001\u0000\u0000\u0000\u0014\u00a2\u0001\u0000\u0000"+
		"\u0000\u0016\u00b4\u0001\u0000\u0000\u0000\u0018\u00f5\u0001\u0000\u0000"+
		"\u0000\u001a\u00fd\u0001\u0000\u0000\u0000\u001c\u0107\u0001\u0000\u0000"+
		"\u0000\u001e\u0111\u0001\u0000\u0000\u0000 \u011b\u0001\u0000\u0000\u0000"+
		"\"\u0125\u0001\u0000\u0000\u0000$\u0127\u0001\u0000\u0000\u0000&\u0135"+
		"\u0001\u0000\u0000\u0000(\u014e\u0001\u0000\u0000\u0000*\u0169\u0001\u0000"+
		"\u0000\u0000,\u016d\u0001\u0000\u0000\u0000.\u016f\u0001\u0000\u0000\u0000"+
		"01\u0003\u0002\u0001\u000012\u0006\u0000\uffff\uffff\u00002\u0001\u0001"+
		"\u0000\u0000\u000034\u0006\u0001\uffff\uffff\u000045\u0003\u0004\u0002"+
		"\u00005:\u0001\u0000\u0000\u000067\n\u0002\u0000\u000079\u0003\u0004\u0002"+
		"\u000086\u0001\u0000\u0000\u00009<\u0001\u0000\u0000\u0000:8\u0001\u0000"+
		"\u0000\u0000:;\u0001\u0000\u0000\u0000;\u0003\u0001\u0000\u0000\u0000"+
		"<:\u0001\u0000\u0000\u0000=A\u0003\u000e\u0007\u0000>A\u0003\u0006\u0003"+
		"\u0000?A\u0003\b\u0004\u0000@=\u0001\u0000\u0000\u0000@>\u0001\u0000\u0000"+
		"\u0000@?\u0001\u0000\u0000\u0000A\u0005\u0001\u0000\u0000\u0000BC\u0003"+
		"\u0012\t\u0000CD\u0005\u001f\u0000\u0000DE\u0005\u000e\u0000\u0000EF\u0003"+
		"\n\u0005\u0000FG\u0005\u000f\u0000\u0000GH\u0005\u0014\u0000\u0000HP\u0001"+
		"\u0000\u0000\u0000IJ\u0003\u0012\t\u0000JK\u0005\u001f\u0000\u0000KL\u0005"+
		"\u000e\u0000\u0000LM\u0005\u000f\u0000\u0000MN\u0005\u0014\u0000\u0000"+
		"NP\u0001\u0000\u0000\u0000OB\u0001\u0000\u0000\u0000OI\u0001\u0000\u0000"+
		"\u0000P\u0007\u0001\u0000\u0000\u0000QR\u0003\u0012\t\u0000RS\u0005\u001f"+
		"\u0000\u0000ST\u0005\u000e\u0000\u0000TU\u0003\n\u0005\u0000UV\u0005\u000f"+
		"\u0000\u0000VW\u0003\f\u0006\u0000W_\u0001\u0000\u0000\u0000XY\u0003\u0012"+
		"\t\u0000YZ\u0005\u001f\u0000\u0000Z[\u0005\u000e\u0000\u0000[\\\u0005"+
		"\u000f\u0000\u0000\\]\u0003\f\u0006\u0000]_\u0001\u0000\u0000\u0000^Q"+
		"\u0001\u0000\u0000\u0000^X\u0001\u0000\u0000\u0000_\t\u0001\u0000\u0000"+
		"\u0000`a\u0006\u0005\uffff\uffff\u0000ab\u0003\u0012\t\u0000bc\u0005\u001f"+
		"\u0000\u0000cd\u0006\u0005\uffff\uffff\u0000di\u0001\u0000\u0000\u0000"+
		"ef\u0003\u0012\t\u0000fg\u0006\u0005\uffff\uffff\u0000gi\u0001\u0000\u0000"+
		"\u0000h`\u0001\u0000\u0000\u0000he\u0001\u0000\u0000\u0000iw\u0001\u0000"+
		"\u0000\u0000jk\n\u0004\u0000\u0000kl\u0005\u0015\u0000\u0000lm\u0003\u0012"+
		"\t\u0000mn\u0005\u001f\u0000\u0000no\u0006\u0005\uffff\uffff\u0000ov\u0001"+
		"\u0000\u0000\u0000pq\n\u0003\u0000\u0000qr\u0005\u0015\u0000\u0000rs\u0003"+
		"\u0012\t\u0000st\u0006\u0005\uffff\uffff\u0000tv\u0001\u0000\u0000\u0000"+
		"uj\u0001\u0000\u0000\u0000up\u0001\u0000\u0000\u0000vy\u0001\u0000\u0000"+
		"\u0000wu\u0001\u0000\u0000\u0000wx\u0001\u0000\u0000\u0000x\u000b\u0001"+
		"\u0000\u0000\u0000yw\u0001\u0000\u0000\u0000z{\u0005\u0010\u0000\u0000"+
		"{|\u0003\u0016\u000b\u0000|}\u0005\u0011\u0000\u0000}~\u0006\u0006\uffff"+
		"\uffff\u0000~\u0083\u0001\u0000\u0000\u0000\u007f\u0080\u0005\u0010\u0000"+
		"\u0000\u0080\u0081\u0005\u0011\u0000\u0000\u0081\u0083\u0006\u0006\uffff"+
		"\uffff\u0000\u0082z\u0001\u0000\u0000\u0000\u0082\u007f\u0001\u0000\u0000"+
		"\u0000\u0083\r\u0001\u0000\u0000\u0000\u0084\u0085\u0003\u0012\t\u0000"+
		"\u0085\u0086\u0003\u0014\n\u0000\u0086\u0087\u0005\u0014\u0000\u0000\u0087"+
		"\u0088\u0006\u0007\uffff\uffff\u0000\u0088\u008f\u0001\u0000\u0000\u0000"+
		"\u0089\u008a\u0003\u0012\t\u0000\u008a\u008b\u0003\u0010\b\u0000\u008b"+
		"\u008c\u0005\u0014\u0000\u0000\u008c\u008d\u0006\u0007\uffff\uffff\u0000"+
		"\u008d\u008f\u0001\u0000\u0000\u0000\u008e\u0084\u0001\u0000\u0000\u0000"+
		"\u008e\u0089\u0001\u0000\u0000\u0000\u008f\u000f\u0001\u0000\u0000\u0000"+
		"\u0090\u0091\u0006\b\uffff\uffff\u0000\u0091\u0011\u0001\u0000\u0000\u0000"+
		"\u0092\u0093\u0005\u000b\u0000\u0000\u0093\u0099\u0006\t\uffff\uffff\u0000"+
		"\u0094\u0095\u0005\f\u0000\u0000\u0095\u0099\u0006\t\uffff\uffff\u0000"+
		"\u0096\u0097\u0005\r\u0000\u0000\u0097\u0099\u0006\t\uffff\uffff\u0000"+
		"\u0098\u0092\u0001\u0000\u0000\u0000\u0098\u0094\u0001\u0000\u0000\u0000"+
		"\u0098\u0096\u0001\u0000\u0000\u0000\u0099\u0013\u0001\u0000\u0000\u0000"+
		"\u009a\u009b\u0006\n\uffff\uffff\u0000\u009b\u009c\u0005\u001f\u0000\u0000"+
		"\u009c\u00a3\u0006\n\uffff\uffff\u0000\u009d\u009e\u0005\u001f\u0000\u0000"+
		"\u009e\u009f\u0005\u0012\u0000\u0000\u009f\u00a0\u0005 \u0000\u0000\u00a0"+
		"\u00a1\u0005\u0013\u0000\u0000\u00a1\u00a3\u0006\n\uffff\uffff\u0000\u00a2"+
		"\u009a\u0001\u0000\u0000\u0000\u00a2\u009d\u0001\u0000\u0000\u0000\u00a3"+
		"\u00b1\u0001\u0000\u0000\u0000\u00a4\u00a5\n\u0004\u0000\u0000\u00a5\u00a6"+
		"\u0005\u0015\u0000\u0000\u00a6\u00a7\u0005\u001f\u0000\u0000\u00a7\u00b0"+
		"\u0006\n\uffff\uffff\u0000\u00a8\u00a9\n\u0003\u0000\u0000\u00a9\u00aa"+
		"\u0005\u0015\u0000\u0000\u00aa\u00ab\u0005\u001f\u0000\u0000\u00ab\u00ac"+
		"\u0005\u0012\u0000\u0000\u00ac\u00ad\u0005 \u0000\u0000\u00ad\u00ae\u0005"+
		"\u0013\u0000\u0000\u00ae\u00b0\u0006\n\uffff\uffff\u0000\u00af\u00a4\u0001"+
		"\u0000\u0000\u0000\u00af\u00a8\u0001\u0000\u0000\u0000\u00b0\u00b3\u0001"+
		"\u0000\u0000\u0000\u00b1\u00af\u0001\u0000\u0000\u0000\u00b1\u00b2\u0001"+
		"\u0000\u0000\u0000\u00b2\u0015\u0001\u0000\u0000\u0000\u00b3\u00b1\u0001"+
		"\u0000\u0000\u0000\u00b4\u00b5\u0006\u000b\uffff\uffff\u0000\u00b5\u00b6"+
		"\u0003\u0018\f\u0000\u00b6\u00b7\u0006\u000b\uffff\uffff\u0000\u00b7\u00be"+
		"\u0001\u0000\u0000\u0000\u00b8\u00b9\n\u0001\u0000\u0000\u00b9\u00ba\u0003"+
		"\u0018\f\u0000\u00ba\u00bb\u0006\u000b\uffff\uffff\u0000\u00bb\u00bd\u0001"+
		"\u0000\u0000\u0000\u00bc\u00b8\u0001\u0000\u0000\u0000\u00bd\u00c0\u0001"+
		"\u0000\u0000\u0000\u00be\u00bc\u0001\u0000\u0000\u0000\u00be\u00bf\u0001"+
		"\u0000\u0000\u0000\u00bf\u0017\u0001\u0000\u0000\u0000\u00c0\u00be\u0001"+
		"\u0000\u0000\u0000\u00c1\u00c2\u0003\u000e\u0007\u0000\u00c2\u00c3\u0006"+
		"\f\uffff\uffff\u0000\u00c3\u00f6\u0001\u0000\u0000\u0000\u00c4\u00c5\u0003"+
		"\u001a\r\u0000\u00c5\u00c6\u0006\f\uffff\uffff\u0000\u00c6\u00f6\u0001"+
		"\u0000\u0000\u0000\u00c7\u00c8\u0003\f\u0006\u0000\u00c8\u00c9\u0006\f"+
		"\uffff\uffff\u0000\u00c9\u00f6\u0001\u0000\u0000\u0000\u00ca\u00cb\u0005"+
		"\u0007\u0000\u0000\u00cb\u00cc\u0005\u000e\u0000\u0000\u00cc\u00cd\u0003"+
		"\u001a\r\u0000\u00cd\u00ce\u0003\u001a\r\u0000\u00ce\u00cf\u0003\u001e"+
		"\u000f\u0000\u00cf\u00d0\u0005\u000f\u0000\u0000\u00d0\u00d1\u0003\u0018"+
		"\f\u0000\u00d1\u00d2\u0006\f\uffff\uffff\u0000\u00d2\u00f6\u0001\u0000"+
		"\u0000\u0000\u00d3\u00d4\u0005\u0005\u0000\u0000\u00d4\u00d5\u0005\u000e"+
		"\u0000\u0000\u00d5\u00d6\u0003\u001e\u000f\u0000\u00d6\u00d7\u0005\u000f"+
		"\u0000\u0000\u00d7\u00d8\u0003\u0018\f\u0000\u00d8\u00d9\u0006\f\uffff"+
		"\uffff\u0000\u00d9\u00f6\u0001\u0000\u0000\u0000\u00da\u00db\u0005\u0005"+
		"\u0000\u0000\u00db\u00dc\u0005\u000e\u0000\u0000\u00dc\u00dd\u0003\u001e"+
		"\u000f\u0000\u00dd\u00de\u0005\u000f\u0000\u0000\u00de\u00df\u0003\u0018"+
		"\f\u0000\u00df\u00e0\u0005\u0006\u0000\u0000\u00e0\u00e1\u0003\u0018\f"+
		"\u0000\u00e1\u00e2\u0006\f\uffff\uffff\u0000\u00e2\u00f6\u0001\u0000\u0000"+
		"\u0000\u00e3\u00e4\u0005\b\u0000\u0000\u00e4\u00e5\u0005\u000e\u0000\u0000"+
		"\u00e5\u00e6\u0003\u001e\u000f\u0000\u00e6\u00e7\u0005\u000f\u0000\u0000"+
		"\u00e7\u00e8\u0003\u0018\f\u0000\u00e8\u00e9\u0006\f\uffff\uffff\u0000"+
		"\u00e9\u00f6\u0001\u0000\u0000\u0000\u00ea\u00eb\u0005\t\u0000\u0000\u00eb"+
		"\u00ec\u0005\u000e\u0000\u0000\u00ec\u00ed\u0005\u001f\u0000\u0000\u00ed"+
		"\u00ee\u0005\u000f\u0000\u0000\u00ee\u00ef\u0005\u0014\u0000\u0000\u00ef"+
		"\u00f6\u0006\f\uffff\uffff\u0000\u00f0\u00f1\u0005\n\u0000\u0000\u00f1"+
		"\u00f2\u0003\u001e\u000f\u0000\u00f2\u00f3\u0005\u0014\u0000\u0000\u00f3"+
		"\u00f4\u0006\f\uffff\uffff\u0000\u00f4\u00f6\u0001\u0000\u0000\u0000\u00f5"+
		"\u00c1\u0001\u0000\u0000\u0000\u00f5\u00c4\u0001\u0000\u0000\u0000\u00f5"+
		"\u00c7\u0001\u0000\u0000\u0000\u00f5\u00ca\u0001\u0000\u0000\u0000\u00f5"+
		"\u00d3\u0001\u0000\u0000\u0000\u00f5\u00da\u0001\u0000\u0000\u0000\u00f5"+
		"\u00e3\u0001\u0000\u0000\u0000\u00f5\u00ea\u0001\u0000\u0000\u0000\u00f5"+
		"\u00f0\u0001\u0000\u0000\u0000\u00f6\u0019\u0001\u0000\u0000\u0000\u00f7"+
		"\u00f8\u0005\u0014\u0000\u0000\u00f8\u00fe\u0006\r\uffff\uffff\u0000\u00f9"+
		"\u00fa\u0003\u001e\u000f\u0000\u00fa\u00fb\u0005\u0014\u0000\u0000\u00fb"+
		"\u00fc\u0006\r\uffff\uffff\u0000\u00fc\u00fe\u0001\u0000\u0000\u0000\u00fd"+
		"\u00f7\u0001\u0000\u0000\u0000\u00fd\u00f9\u0001\u0000\u0000\u0000\u00fe"+
		"\u001b\u0001\u0000\u0000\u0000\u00ff\u0100\u0005\u001f\u0000\u0000\u0100"+
		"\u0108\u0006\u000e\uffff\uffff\u0000\u0101\u0102\u0005\u001f\u0000\u0000"+
		"\u0102\u0103\u0005\u0012\u0000\u0000\u0103\u0104\u0003\u001e\u000f\u0000"+
		"\u0104\u0105\u0005\u0013\u0000\u0000\u0105\u0106\u0006\u000e\uffff\uffff"+
		"\u0000\u0106\u0108\u0001\u0000\u0000\u0000\u0107\u00ff\u0001\u0000\u0000"+
		"\u0000\u0107\u0101\u0001\u0000\u0000\u0000\u0108\u001d\u0001\u0000\u0000"+
		"\u0000\u0109\u010a\u0003 \u0010\u0000\u010a\u010b\u0006\u000f\uffff\uffff"+
		"\u0000\u010b\u0112\u0001\u0000\u0000\u0000\u010c\u010d\u0003\u001c\u000e"+
		"\u0000\u010d\u010e\u0005\u001e\u0000\u0000\u010e\u010f\u0003 \u0010\u0000"+
		"\u010f\u0110\u0006\u000f\uffff\uffff\u0000\u0110\u0112\u0001\u0000\u0000"+
		"\u0000\u0111\u0109\u0001\u0000\u0000\u0000\u0111\u010c\u0001\u0000\u0000"+
		"\u0000\u0112\u001f\u0001\u0000\u0000\u0000\u0113\u0114\u0003\"\u0011\u0000"+
		"\u0114\u0115\u0006\u0010\uffff\uffff\u0000\u0115\u011c\u0001\u0000\u0000"+
		"\u0000\u0116\u0117\u0003\"\u0011\u0000\u0117\u0118\u0005\u001d\u0000\u0000"+
		"\u0118\u0119\u0003\"\u0011\u0000\u0119\u011a\u0006\u0010\uffff\uffff\u0000"+
		"\u011a\u011c\u0001\u0000\u0000\u0000\u011b\u0113\u0001\u0000\u0000\u0000"+
		"\u011b\u0116\u0001\u0000\u0000\u0000\u011c!\u0001\u0000\u0000\u0000\u011d"+
		"\u011e\u0003$\u0012\u0000\u011e\u011f\u0006\u0011\uffff\uffff\u0000\u011f"+
		"\u0126\u0001\u0000\u0000\u0000\u0120\u0121\u0003$\u0012\u0000\u0121\u0122"+
		"\u0005\u001c\u0000\u0000\u0122\u0123\u0003$\u0012\u0000\u0123\u0124\u0006"+
		"\u0011\uffff\uffff\u0000\u0124\u0126\u0001\u0000\u0000\u0000\u0125\u011d"+
		"\u0001\u0000\u0000\u0000\u0125\u0120\u0001\u0000\u0000\u0000\u0126#\u0001"+
		"\u0000\u0000\u0000\u0127\u0128\u0006\u0012\uffff\uffff\u0000\u0128\u0129"+
		"\u0003&\u0013\u0000\u0129\u012a\u0006\u0012\uffff\uffff\u0000\u012a\u0132"+
		"\u0001\u0000\u0000\u0000\u012b\u012c\n\u0001\u0000\u0000\u012c\u012d\u0005"+
		"\u0016\u0000\u0000\u012d\u012e\u0003&\u0013\u0000\u012e\u012f\u0006\u0012"+
		"\uffff\uffff\u0000\u012f\u0131\u0001\u0000\u0000\u0000\u0130\u012b\u0001"+
		"\u0000\u0000\u0000\u0131\u0134\u0001\u0000\u0000\u0000\u0132\u0130\u0001"+
		"\u0000\u0000\u0000\u0132\u0133\u0001\u0000\u0000\u0000\u0133%\u0001\u0000"+
		"\u0000\u0000\u0134\u0132\u0001\u0000\u0000\u0000\u0135\u0136\u0006\u0013"+
		"\uffff\uffff\u0000\u0136\u0137\u0003(\u0014\u0000\u0137\u0138\u0006\u0013"+
		"\uffff\uffff\u0000\u0138\u0140\u0001\u0000\u0000\u0000\u0139\u013a\n\u0001"+
		"\u0000\u0000\u013a\u013b\u0005\u0018\u0000\u0000\u013b\u013c\u0003(\u0014"+
		"\u0000\u013c\u013d\u0006\u0013\uffff\uffff\u0000\u013d\u013f\u0001\u0000"+
		"\u0000\u0000\u013e\u0139\u0001\u0000\u0000\u0000\u013f\u0142\u0001\u0000"+
		"\u0000\u0000\u0140\u013e\u0001\u0000\u0000\u0000\u0140\u0141\u0001\u0000"+
		"\u0000\u0000\u0141\'\u0001\u0000\u0000\u0000\u0142\u0140\u0001\u0000\u0000"+
		"\u0000\u0143\u0144\u0005\u0016\u0000\u0000\u0144\u0145\u0003(\u0014\u0000"+
		"\u0145\u0146\u0006\u0014\uffff\uffff\u0000\u0146\u014f\u0001\u0000\u0000"+
		"\u0000\u0147\u0148\u0005\u001b\u0000\u0000\u0148\u0149\u0003(\u0014\u0000"+
		"\u0149\u014a\u0006\u0014\uffff\uffff\u0000\u014a\u014f\u0001\u0000\u0000"+
		"\u0000\u014b\u014c\u0003*\u0015\u0000\u014c\u014d\u0006\u0014\uffff\uffff"+
		"\u0000\u014d\u014f\u0001\u0000\u0000\u0000\u014e\u0143\u0001\u0000\u0000"+
		"\u0000\u014e\u0147\u0001\u0000\u0000\u0000\u014e\u014b\u0001\u0000\u0000"+
		"\u0000\u014f)\u0001\u0000\u0000\u0000\u0150\u0151\u0003\u001c\u000e\u0000"+
		"\u0151\u0152\u0006\u0015\uffff\uffff\u0000\u0152\u016a\u0001\u0000\u0000"+
		"\u0000\u0153\u0154\u0005\u001f\u0000\u0000\u0154\u0155\u0005\u000e\u0000"+
		"\u0000\u0155\u0156\u0003,\u0016\u0000\u0156\u0157\u0005\u000f\u0000\u0000"+
		"\u0157\u0158\u0006\u0015\uffff\uffff\u0000\u0158\u016a\u0001\u0000\u0000"+
		"\u0000\u0159\u015a\u0005\u000e\u0000\u0000\u015a\u015b\u0003\u001e\u000f"+
		"\u0000\u015b\u015c\u0005\u000f\u0000\u0000\u015c\u016a\u0001\u0000\u0000"+
		"\u0000\u015d\u015e\u0005 \u0000\u0000\u015e\u016a\u0006\u0015\uffff\uffff"+
		"\u0000\u015f\u0160\u0005!\u0000\u0000\u0160\u016a\u0006\u0015\uffff\uffff"+
		"\u0000\u0161\u0162\u0003\u001c\u000e\u0000\u0162\u0163\u0005\u0019\u0000"+
		"\u0000\u0163\u0164\u0006\u0015\uffff\uffff\u0000\u0164\u016a\u0001\u0000"+
		"\u0000\u0000\u0165\u0166\u0003\u001c\u000e\u0000\u0166\u0167\u0005\u001a"+
		"\u0000\u0000\u0167\u0168\u0006\u0015\uffff\uffff\u0000\u0168\u016a\u0001"+
		"\u0000\u0000\u0000\u0169\u0150\u0001\u0000\u0000\u0000\u0169\u0153\u0001"+
		"\u0000\u0000\u0000\u0169\u0159\u0001\u0000\u0000\u0000\u0169\u015d\u0001"+
		"\u0000\u0000\u0000\u0169\u015f\u0001\u0000\u0000\u0000\u0169\u0161\u0001"+
		"\u0000\u0000\u0000\u0169\u0165\u0001\u0000\u0000\u0000\u016a+\u0001\u0000"+
		"\u0000\u0000\u016b\u016e\u0003.\u0017\u0000\u016c\u016e\u0001\u0000\u0000"+
		"\u0000\u016d\u016b\u0001\u0000\u0000\u0000\u016d\u016c\u0001\u0000\u0000"+
		"\u0000\u016e-\u0001\u0000\u0000\u0000\u016f\u0170\u0006\u0017\uffff\uffff"+
		"\u0000\u0170\u0171\u0003 \u0010\u0000\u0171\u0177\u0001\u0000\u0000\u0000"+
		"\u0172\u0173\n\u0002\u0000\u0000\u0173\u0174\u0005\u0015\u0000\u0000\u0174"+
		"\u0176\u0003 \u0010\u0000\u0175\u0172\u0001\u0000\u0000\u0000\u0176\u0179"+
		"\u0001\u0000\u0000\u0000\u0177\u0175\u0001\u0000\u0000\u0000\u0177\u0178"+
		"\u0001\u0000\u0000\u0000\u0178/\u0001\u0000\u0000\u0000\u0179\u0177\u0001"+
		"\u0000\u0000\u0000\u001a:@O^huw\u0082\u008e\u0098\u00a2\u00af\u00b1\u00be"+
		"\u00f5\u00fd\u0107\u0111\u011b\u0125\u0132\u0140\u014e\u0169\u016d\u0177";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}