
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



// Generated from C2105168Parser.g4 by ANTLR 4.13.2


#include "C2105168ParserListener.h"

#include "C2105168Parser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct C2105168ParserStaticData final {
  C2105168ParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  C2105168ParserStaticData(const C2105168ParserStaticData&) = delete;
  C2105168ParserStaticData(C2105168ParserStaticData&&) = delete;
  C2105168ParserStaticData& operator=(const C2105168ParserStaticData&) = delete;
  C2105168ParserStaticData& operator=(C2105168ParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag c2105168parserParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<C2105168ParserStaticData> c2105168parserParserStaticData = nullptr;

void c2105168parserParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (c2105168parserParserStaticData != nullptr) {
    return;
  }
#else
  assert(c2105168parserParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<C2105168ParserStaticData>(
    std::vector<std::string>{
      "start", "program", "unit", "func_declaration", "func_definition", 
      "parameter_list", "compound_statement", "var_declaration", "declaration_list_err", 
      "type_specifier", "declaration_list", "statements", "statement", "expression_statement", 
      "variable", "expression", "logic_expression", "rel_expression", "simple_expression", 
      "term", "unary_expression", "factor", "argument_list", "arguments"
    },
    std::vector<std::string>{
      "", "", "", "", "", "'if'", "'else'", "'for'", "'while'", "'printf'", 
      "'return'", "'int'", "'float'", "'void'", "'('", "')'", "'{'", "'}'", 
      "'['", "']'", "';'", "','", "'#'", "", "", "", "'++'", "'--'", "'!'", 
      "", "", "'='"
    },
    std::vector<std::string>{
      "", "LINE_COMMENT", "BLOCK_COMMENT", "STRING", "WS", "IF", "ELSE", 
      "FOR", "WHILE", "PRINTLN", "RETURN", "INT", "FLOAT", "VOID", "LPAREN", 
      "RPAREN", "LCURL", "RCURL", "LTHIRD", "RTHIRD", "SEMICOLON", "COMMA", 
      "HASH", "ADDOP", "SUBOP", "MULOP", "INCOP", "DECOP", "NOT", "RELOP", 
      "LOGICOP", "ASSIGNOP", "ID", "CONST_INT", "CONST_FLOAT"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,34,426,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,1,0,1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,5,
  	1,60,8,1,10,1,12,1,63,9,1,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,3,2,74,
  	8,2,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,3,
  	3,92,8,3,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,
  	1,4,1,4,1,4,3,4,112,8,4,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,
  	5,1,5,1,5,3,5,128,8,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,
  	1,5,1,5,1,5,5,5,145,8,5,10,5,12,5,148,9,5,1,6,1,6,1,6,1,6,1,6,1,6,1,6,
  	1,6,1,6,1,6,1,6,3,6,161,8,6,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,3,
  	7,173,8,7,1,8,1,8,1,9,1,9,1,9,1,9,1,9,1,9,3,9,183,8,9,1,10,1,10,1,10,
  	1,10,1,10,1,10,1,10,1,10,1,10,1,10,1,10,1,10,1,10,3,10,198,8,10,1,10,
  	1,10,1,10,1,10,1,10,1,10,1,10,1,10,1,10,1,10,1,10,1,10,1,10,1,10,1,10,
  	1,10,5,10,216,8,10,10,10,12,10,219,9,10,1,11,1,11,1,11,1,11,1,11,1,11,
  	1,11,1,11,5,11,229,8,11,10,11,12,11,232,9,11,1,12,1,12,1,12,1,12,1,12,
  	1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,
  	1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,
  	1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,
  	1,12,1,12,1,12,1,12,1,12,3,12,286,8,12,1,13,1,13,1,13,1,13,1,13,1,13,
  	3,13,294,8,13,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,3,14,304,8,14,1,
  	15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,3,15,314,8,15,1,16,1,16,1,16,1,
  	16,1,16,1,16,1,16,1,16,3,16,324,8,16,1,17,1,17,1,17,1,17,1,17,1,17,1,
  	17,1,17,3,17,334,8,17,1,18,1,18,1,18,1,18,1,18,1,18,1,18,1,18,1,18,5,
  	18,345,8,18,10,18,12,18,348,9,18,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,
  	19,1,19,5,19,359,8,19,10,19,12,19,362,9,19,1,20,1,20,1,20,1,20,1,20,1,
  	20,1,20,1,20,1,20,1,20,1,20,3,20,375,8,20,1,21,1,21,1,21,1,21,1,21,1,
  	21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,
  	21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,3,21,404,8,21,1,22,1,22,1,22,1,
  	22,3,22,410,8,22,1,23,1,23,1,23,1,23,1,23,1,23,1,23,1,23,1,23,5,23,421,
  	8,23,10,23,12,23,424,9,23,1,23,0,7,2,10,20,22,36,38,46,24,0,2,4,6,8,10,
  	12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,42,44,46,0,0,447,0,48,1,
  	0,0,0,2,51,1,0,0,0,4,73,1,0,0,0,6,91,1,0,0,0,8,111,1,0,0,0,10,127,1,0,
  	0,0,12,160,1,0,0,0,14,172,1,0,0,0,16,174,1,0,0,0,18,182,1,0,0,0,20,197,
  	1,0,0,0,22,220,1,0,0,0,24,285,1,0,0,0,26,293,1,0,0,0,28,303,1,0,0,0,30,
  	313,1,0,0,0,32,323,1,0,0,0,34,333,1,0,0,0,36,335,1,0,0,0,38,349,1,0,0,
  	0,40,374,1,0,0,0,42,403,1,0,0,0,44,409,1,0,0,0,46,411,1,0,0,0,48,49,3,
  	2,1,0,49,50,6,0,-1,0,50,1,1,0,0,0,51,52,6,1,-1,0,52,53,3,4,2,0,53,54,
  	6,1,-1,0,54,61,1,0,0,0,55,56,10,2,0,0,56,57,3,4,2,0,57,58,6,1,-1,0,58,
  	60,1,0,0,0,59,55,1,0,0,0,60,63,1,0,0,0,61,59,1,0,0,0,61,62,1,0,0,0,62,
  	3,1,0,0,0,63,61,1,0,0,0,64,65,3,14,7,0,65,66,6,2,-1,0,66,74,1,0,0,0,67,
  	68,3,6,3,0,68,69,6,2,-1,0,69,74,1,0,0,0,70,71,3,8,4,0,71,72,6,2,-1,0,
  	72,74,1,0,0,0,73,64,1,0,0,0,73,67,1,0,0,0,73,70,1,0,0,0,74,5,1,0,0,0,
  	75,76,3,18,9,0,76,77,5,32,0,0,77,78,6,3,-1,0,78,79,5,14,0,0,79,80,3,10,
  	5,0,80,81,5,15,0,0,81,82,5,20,0,0,82,83,6,3,-1,0,83,92,1,0,0,0,84,85,
  	3,18,9,0,85,86,5,32,0,0,86,87,5,14,0,0,87,88,5,15,0,0,88,89,5,20,0,0,
  	89,90,6,3,-1,0,90,92,1,0,0,0,91,75,1,0,0,0,91,84,1,0,0,0,92,7,1,0,0,0,
  	93,94,3,18,9,0,94,95,5,32,0,0,95,96,5,14,0,0,96,97,6,4,-1,0,97,98,3,10,
  	5,0,98,99,6,4,-1,0,99,100,5,15,0,0,100,101,3,12,6,0,101,102,6,4,-1,0,
  	102,112,1,0,0,0,103,104,3,18,9,0,104,105,5,32,0,0,105,106,5,14,0,0,106,
  	107,5,15,0,0,107,108,6,4,-1,0,108,109,3,12,6,0,109,110,6,4,-1,0,110,112,
  	1,0,0,0,111,93,1,0,0,0,111,103,1,0,0,0,112,9,1,0,0,0,113,114,6,5,-1,0,
  	114,115,3,18,9,0,115,116,5,32,0,0,116,117,6,5,-1,0,117,128,1,0,0,0,118,
  	119,3,18,9,0,119,120,5,23,0,0,120,121,6,5,-1,0,121,128,1,0,0,0,122,123,
  	3,18,9,0,123,124,6,5,-1,0,124,128,1,0,0,0,125,126,5,23,0,0,126,128,6,
  	5,-1,0,127,113,1,0,0,0,127,118,1,0,0,0,127,122,1,0,0,0,127,125,1,0,0,
  	0,128,146,1,0,0,0,129,130,10,7,0,0,130,131,5,21,0,0,131,132,3,18,9,0,
  	132,133,5,32,0,0,133,134,6,5,-1,0,134,145,1,0,0,0,135,136,10,6,0,0,136,
  	137,5,21,0,0,137,138,3,18,9,0,138,139,6,5,-1,0,139,145,1,0,0,0,140,141,
  	10,5,0,0,141,142,5,21,0,0,142,143,5,23,0,0,143,145,6,5,-1,0,144,129,1,
  	0,0,0,144,135,1,0,0,0,144,140,1,0,0,0,145,148,1,0,0,0,146,144,1,0,0,0,
  	146,147,1,0,0,0,147,11,1,0,0,0,148,146,1,0,0,0,149,150,5,16,0,0,150,151,
  	6,6,-1,0,151,152,3,22,11,0,152,153,6,6,-1,0,153,154,5,17,0,0,154,155,
  	6,6,-1,0,155,161,1,0,0,0,156,157,5,16,0,0,157,158,6,6,-1,0,158,159,5,
  	17,0,0,159,161,6,6,-1,0,160,149,1,0,0,0,160,156,1,0,0,0,161,13,1,0,0,
  	0,162,163,3,18,9,0,163,164,3,20,10,0,164,165,5,20,0,0,165,166,6,7,-1,
  	0,166,173,1,0,0,0,167,168,3,18,9,0,168,169,3,16,8,0,169,170,5,20,0,0,
  	170,171,6,7,-1,0,171,173,1,0,0,0,172,162,1,0,0,0,172,167,1,0,0,0,173,
  	15,1,0,0,0,174,175,6,8,-1,0,175,17,1,0,0,0,176,177,5,11,0,0,177,183,6,
  	9,-1,0,178,179,5,12,0,0,179,183,6,9,-1,0,180,181,5,13,0,0,181,183,6,9,
  	-1,0,182,176,1,0,0,0,182,178,1,0,0,0,182,180,1,0,0,0,183,19,1,0,0,0,184,
  	185,6,10,-1,0,185,186,5,32,0,0,186,198,6,10,-1,0,187,188,5,32,0,0,188,
  	189,5,18,0,0,189,190,5,33,0,0,190,191,5,19,0,0,191,198,6,10,-1,0,192,
  	193,5,32,0,0,193,194,5,23,0,0,194,195,3,20,10,1,195,196,6,10,-1,0,196,
  	198,1,0,0,0,197,184,1,0,0,0,197,187,1,0,0,0,197,192,1,0,0,0,198,217,1,
  	0,0,0,199,200,10,6,0,0,200,201,5,21,0,0,201,202,5,32,0,0,202,216,6,10,
  	-1,0,203,204,10,5,0,0,204,205,5,21,0,0,205,206,5,32,0,0,206,207,5,18,
  	0,0,207,208,5,33,0,0,208,209,5,19,0,0,209,216,6,10,-1,0,210,211,10,4,
  	0,0,211,212,5,21,0,0,212,213,5,32,0,0,213,214,5,23,0,0,214,216,6,10,-1,
  	0,215,199,1,0,0,0,215,203,1,0,0,0,215,210,1,0,0,0,216,219,1,0,0,0,217,
  	215,1,0,0,0,217,218,1,0,0,0,218,21,1,0,0,0,219,217,1,0,0,0,220,221,6,
  	11,-1,0,221,222,3,24,12,0,222,223,6,11,-1,0,223,230,1,0,0,0,224,225,10,
  	1,0,0,225,226,3,24,12,0,226,227,6,11,-1,0,227,229,1,0,0,0,228,224,1,0,
  	0,0,229,232,1,0,0,0,230,228,1,0,0,0,230,231,1,0,0,0,231,23,1,0,0,0,232,
  	230,1,0,0,0,233,234,3,14,7,0,234,235,6,12,-1,0,235,286,1,0,0,0,236,237,
  	3,26,13,0,237,238,6,12,-1,0,238,286,1,0,0,0,239,240,3,12,6,0,240,241,
  	6,12,-1,0,241,286,1,0,0,0,242,243,5,7,0,0,243,244,5,14,0,0,244,245,3,
  	26,13,0,245,246,3,26,13,0,246,247,3,30,15,0,247,248,5,15,0,0,248,249,
  	3,24,12,0,249,250,6,12,-1,0,250,286,1,0,0,0,251,252,5,5,0,0,252,253,5,
  	14,0,0,253,254,3,30,15,0,254,255,5,15,0,0,255,256,3,24,12,0,256,257,6,
  	12,-1,0,257,286,1,0,0,0,258,259,5,5,0,0,259,260,5,14,0,0,260,261,3,30,
  	15,0,261,262,5,15,0,0,262,263,3,24,12,0,263,264,5,6,0,0,264,265,3,24,
  	12,0,265,266,6,12,-1,0,266,286,1,0,0,0,267,268,5,8,0,0,268,269,5,14,0,
  	0,269,270,3,30,15,0,270,271,5,15,0,0,271,272,3,24,12,0,272,273,6,12,-1,
  	0,273,286,1,0,0,0,274,275,5,9,0,0,275,276,5,14,0,0,276,277,5,32,0,0,277,
  	278,5,15,0,0,278,279,5,20,0,0,279,286,6,12,-1,0,280,281,5,10,0,0,281,
  	282,3,30,15,0,282,283,5,20,0,0,283,284,6,12,-1,0,284,286,1,0,0,0,285,
  	233,1,0,0,0,285,236,1,0,0,0,285,239,1,0,0,0,285,242,1,0,0,0,285,251,1,
  	0,0,0,285,258,1,0,0,0,285,267,1,0,0,0,285,274,1,0,0,0,285,280,1,0,0,0,
  	286,25,1,0,0,0,287,288,5,20,0,0,288,294,6,13,-1,0,289,290,3,30,15,0,290,
  	291,5,20,0,0,291,292,6,13,-1,0,292,294,1,0,0,0,293,287,1,0,0,0,293,289,
  	1,0,0,0,294,27,1,0,0,0,295,296,5,32,0,0,296,304,6,14,-1,0,297,298,5,32,
  	0,0,298,299,5,18,0,0,299,300,3,30,15,0,300,301,5,19,0,0,301,302,6,14,
  	-1,0,302,304,1,0,0,0,303,295,1,0,0,0,303,297,1,0,0,0,304,29,1,0,0,0,305,
  	306,3,32,16,0,306,307,6,15,-1,0,307,314,1,0,0,0,308,309,3,28,14,0,309,
  	310,5,31,0,0,310,311,3,32,16,0,311,312,6,15,-1,0,312,314,1,0,0,0,313,
  	305,1,0,0,0,313,308,1,0,0,0,314,31,1,0,0,0,315,316,3,34,17,0,316,317,
  	6,16,-1,0,317,324,1,0,0,0,318,319,3,34,17,0,319,320,5,30,0,0,320,321,
  	3,34,17,0,321,322,6,16,-1,0,322,324,1,0,0,0,323,315,1,0,0,0,323,318,1,
  	0,0,0,324,33,1,0,0,0,325,326,3,36,18,0,326,327,6,17,-1,0,327,334,1,0,
  	0,0,328,329,3,36,18,0,329,330,5,29,0,0,330,331,3,36,18,0,331,332,6,17,
  	-1,0,332,334,1,0,0,0,333,325,1,0,0,0,333,328,1,0,0,0,334,35,1,0,0,0,335,
  	336,6,18,-1,0,336,337,3,38,19,0,337,338,6,18,-1,0,338,346,1,0,0,0,339,
  	340,10,1,0,0,340,341,5,23,0,0,341,342,3,38,19,0,342,343,6,18,-1,0,343,
  	345,1,0,0,0,344,339,1,0,0,0,345,348,1,0,0,0,346,344,1,0,0,0,346,347,1,
  	0,0,0,347,37,1,0,0,0,348,346,1,0,0,0,349,350,6,19,-1,0,350,351,3,40,20,
  	0,351,352,6,19,-1,0,352,360,1,0,0,0,353,354,10,1,0,0,354,355,5,25,0,0,
  	355,356,3,40,20,0,356,357,6,19,-1,0,357,359,1,0,0,0,358,353,1,0,0,0,359,
  	362,1,0,0,0,360,358,1,0,0,0,360,361,1,0,0,0,361,39,1,0,0,0,362,360,1,
  	0,0,0,363,364,5,23,0,0,364,365,3,40,20,0,365,366,6,20,-1,0,366,375,1,
  	0,0,0,367,368,5,28,0,0,368,369,3,40,20,0,369,370,6,20,-1,0,370,375,1,
  	0,0,0,371,372,3,42,21,0,372,373,6,20,-1,0,373,375,1,0,0,0,374,363,1,0,
  	0,0,374,367,1,0,0,0,374,371,1,0,0,0,375,41,1,0,0,0,376,377,3,28,14,0,
  	377,378,6,21,-1,0,378,404,1,0,0,0,379,380,5,32,0,0,380,381,5,14,0,0,381,
  	382,6,21,-1,0,382,383,3,44,22,0,383,384,5,15,0,0,384,385,6,21,-1,0,385,
  	404,1,0,0,0,386,387,5,14,0,0,387,388,3,30,15,0,388,389,5,15,0,0,389,390,
  	6,21,-1,0,390,404,1,0,0,0,391,392,5,33,0,0,392,404,6,21,-1,0,393,394,
  	5,34,0,0,394,404,6,21,-1,0,395,396,3,28,14,0,396,397,5,26,0,0,397,398,
  	6,21,-1,0,398,404,1,0,0,0,399,400,3,28,14,0,400,401,5,27,0,0,401,402,
  	6,21,-1,0,402,404,1,0,0,0,403,376,1,0,0,0,403,379,1,0,0,0,403,386,1,0,
  	0,0,403,391,1,0,0,0,403,393,1,0,0,0,403,395,1,0,0,0,403,399,1,0,0,0,404,
  	43,1,0,0,0,405,406,3,46,23,0,406,407,6,22,-1,0,407,410,1,0,0,0,408,410,
  	1,0,0,0,409,405,1,0,0,0,409,408,1,0,0,0,410,45,1,0,0,0,411,412,6,23,-1,
  	0,412,413,3,32,16,0,413,414,6,23,-1,0,414,422,1,0,0,0,415,416,10,2,0,
  	0,416,417,5,21,0,0,417,418,3,32,16,0,418,419,6,23,-1,0,419,421,1,0,0,
  	0,420,415,1,0,0,0,421,424,1,0,0,0,422,420,1,0,0,0,422,423,1,0,0,0,423,
  	47,1,0,0,0,424,422,1,0,0,0,26,61,73,91,111,127,144,146,160,172,182,197,
  	215,217,230,285,293,303,313,323,333,346,360,374,403,409,422
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  c2105168parserParserStaticData = std::move(staticData);
}

}

C2105168Parser::C2105168Parser(TokenStream *input) : C2105168Parser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

C2105168Parser::C2105168Parser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  C2105168Parser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *c2105168parserParserStaticData->atn, c2105168parserParserStaticData->decisionToDFA, c2105168parserParserStaticData->sharedContextCache, options);
}

C2105168Parser::~C2105168Parser() {
  delete _interpreter;
}

const atn::ATN& C2105168Parser::getATN() const {
  return *c2105168parserParserStaticData->atn;
}

std::string C2105168Parser::getGrammarFileName() const {
  return "C2105168Parser.g4";
}

const std::vector<std::string>& C2105168Parser::getRuleNames() const {
  return c2105168parserParserStaticData->ruleNames;
}

const dfa::Vocabulary& C2105168Parser::getVocabulary() const {
  return c2105168parserParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView C2105168Parser::getSerializedATN() const {
  return c2105168parserParserStaticData->serializedATN;
}


//----------------- StartContext ------------------------------------------------------------------

C2105168Parser::StartContext::StartContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C2105168Parser::ProgramContext* C2105168Parser::StartContext::program() {
  return getRuleContext<C2105168Parser::ProgramContext>(0);
}


size_t C2105168Parser::StartContext::getRuleIndex() const {
  return C2105168Parser::RuleStart;
}

void C2105168Parser::StartContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105168ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStart(this);
}

void C2105168Parser::StartContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105168ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStart(this);
}

C2105168Parser::StartContext* C2105168Parser::start() {
  StartContext *_localctx = _tracker.createInstance<StartContext>(_ctx, getState());
  enterRule(_localctx, 0, C2105168Parser::RuleStart);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(48);
    antlrcpp::downCast<StartContext *>(_localctx)->p = program(0);

            
            antlrcpp::downCast<StartContext *>(_localctx)->text =  antlrcpp::downCast<StartContext *>(_localctx)->p->text;
            antlrcpp::downCast<StartContext *>(_localctx)->line =  antlrcpp::downCast<StartContext *>(_localctx)->p->line;
            antlrcpp::downCast<StartContext *>(_localctx)->data_section =  antlrcpp::downCast<StartContext *>(_localctx)->p->data_section_code;
            antlrcpp::downCast<StartContext *>(_localctx)->code_section =  (antlrcpp::downCast<StartContext *>(_localctx)->p->code_section);
            std::cout << "DEBUG: start code_section = '" << _localctx->code_section << "'" << std::endl;
           // writeIntoparserLogFile("Parsing completed successfully with " + std::to_string(syntaxErrorCount) + " syntax errors.");


            writeIntoparserLogFile("Line "+std::to_string(_localctx->line)+": start : program\n");
            symbolTable->print_current_scope_table(parserLogFile);


            writeIntoparserLogFile("\nTotal number of lines: "+std::to_string(_localctx->line));
            writeIntoparserLogFile("Total number of errors: "+std::to_string(errorCount));


            antlrcpp::downCast<StartContext *>(_localctx)->asm_header = ".MODEL SMALL\n.STACK 1000H";
            std::cout << "here" <<std::endl;
            writeIntoAsmFile(_localctx->asm_header+"\n.Data\nnumber DB \"00000$\"\n"+_localctx->data_section+".CODE\n"+_localctx->code_section);
            std::cout << _localctx->code_section <<std::endl;
    	
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ProgramContext ------------------------------------------------------------------

C2105168Parser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C2105168Parser::UnitContext* C2105168Parser::ProgramContext::unit() {
  return getRuleContext<C2105168Parser::UnitContext>(0);
}

C2105168Parser::ProgramContext* C2105168Parser::ProgramContext::program() {
  return getRuleContext<C2105168Parser::ProgramContext>(0);
}


size_t C2105168Parser::ProgramContext::getRuleIndex() const {
  return C2105168Parser::RuleProgram;
}

void C2105168Parser::ProgramContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105168ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProgram(this);
}

void C2105168Parser::ProgramContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105168ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProgram(this);
}


C2105168Parser::ProgramContext* C2105168Parser::program() {
   return program(0);
}

C2105168Parser::ProgramContext* C2105168Parser::program(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  C2105168Parser::ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, parentState);
  C2105168Parser::ProgramContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 2;
  enterRecursionRule(_localctx, 2, C2105168Parser::RuleProgram, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(52);
    antlrcpp::downCast<ProgramContext *>(_localctx)->u = unit();
     
            antlrcpp::downCast<ProgramContext *>(_localctx)->text =  antlrcpp::downCast<ProgramContext *>(_localctx)->u->text;
            antlrcpp::downCast<ProgramContext *>(_localctx)->line =  antlrcpp::downCast<ProgramContext *>(_localctx)->u->line;
            writeIntoparserLogFile("Line "+std::to_string(_localctx->line)+": program : unit\n\n"+_localctx->text+"\n");
            antlrcpp::downCast<ProgramContext *>(_localctx)->data_section_code =  antlrcpp::downCast<ProgramContext *>(_localctx)->u->data_section_code;
            antlrcpp::downCast<ProgramContext *>(_localctx)->code_section =  antlrcpp::downCast<ProgramContext *>(_localctx)->u->code_section;
             
    _ctx->stop = _input->LT(-1);
    setState(61);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<ProgramContext>(parentContext, parentState);
        _localctx->pu = previousContext;
        pushNewRecursionContext(_localctx, startState, RuleProgram);
        setState(55);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(56);
        antlrcpp::downCast<ProgramContext *>(_localctx)->u = unit();
          
                          antlrcpp::downCast<ProgramContext *>(_localctx)->text =  antlrcpp::downCast<ProgramContext *>(_localctx)->pu->text +"\n"+antlrcpp::downCast<ProgramContext *>(_localctx)->u->text;
                          antlrcpp::downCast<ProgramContext *>(_localctx)->line =  antlrcpp::downCast<ProgramContext *>(_localctx)->u->line;
                          antlrcpp::downCast<ProgramContext *>(_localctx)->data_section_code =  antlrcpp::downCast<ProgramContext *>(_localctx)->pu->data_section_code + "\n" + antlrcpp::downCast<ProgramContext *>(_localctx)->u->data_section_code;
                          antlrcpp::downCast<ProgramContext *>(_localctx)->code_section =  antlrcpp::downCast<ProgramContext *>(_localctx)->pu->code_section + antlrcpp::downCast<ProgramContext *>(_localctx)->u->code_section;
                          writeIntoparserLogFile("Line "+std::to_string(_localctx->line)+": program : program unit\n\n"+_localctx->text+"\n");
                           
      }
      setState(63);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- UnitContext ------------------------------------------------------------------

C2105168Parser::UnitContext::UnitContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C2105168Parser::Var_declarationContext* C2105168Parser::UnitContext::var_declaration() {
  return getRuleContext<C2105168Parser::Var_declarationContext>(0);
}

C2105168Parser::Func_declarationContext* C2105168Parser::UnitContext::func_declaration() {
  return getRuleContext<C2105168Parser::Func_declarationContext>(0);
}

C2105168Parser::Func_definitionContext* C2105168Parser::UnitContext::func_definition() {
  return getRuleContext<C2105168Parser::Func_definitionContext>(0);
}


size_t C2105168Parser::UnitContext::getRuleIndex() const {
  return C2105168Parser::RuleUnit;
}

void C2105168Parser::UnitContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105168ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnit(this);
}

void C2105168Parser::UnitContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105168ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnit(this);
}

C2105168Parser::UnitContext* C2105168Parser::unit() {
  UnitContext *_localctx = _tracker.createInstance<UnitContext>(_ctx, getState());
  enterRule(_localctx, 4, C2105168Parser::RuleUnit);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(73);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(64);
      antlrcpp::downCast<UnitContext *>(_localctx)->vd = var_declaration();
        
              antlrcpp::downCast<UnitContext *>(_localctx)->text =  antlrcpp::downCast<UnitContext *>(_localctx)->vd->text;
              antlrcpp::downCast<UnitContext *>(_localctx)->line =  antlrcpp::downCast<UnitContext *>(_localctx)->vd->line;
              antlrcpp::downCast<UnitContext *>(_localctx)->data_section_code =  antlrcpp::downCast<UnitContext *>(_localctx)->vd->data_section_code;
              antlrcpp::downCast<UnitContext *>(_localctx)->code_section =  antlrcpp::downCast<UnitContext *>(_localctx)->vd->code_section;
              std::cout << "DEBUG: unit var_declaration code_section = '" << _localctx->code_section << "'" << std::endl;
              writeIntoparserLogFile("Line "+std::to_string(_localctx->line)+": unit : var_declaration\n\n"+_localctx->text+"\n");

          
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(67);
      antlrcpp::downCast<UnitContext *>(_localctx)->fdec = func_declaration();
        

              antlrcpp::downCast<UnitContext *>(_localctx)->text =  antlrcpp::downCast<UnitContext *>(_localctx)->fdec->text;  
              antlrcpp::downCast<UnitContext *>(_localctx)->line =  antlrcpp::downCast<UnitContext *>(_localctx)->fdec->line;
              antlrcpp::downCast<UnitContext *>(_localctx)->data_section_code =  "";
              antlrcpp::downCast<UnitContext *>(_localctx)->code_section =  antlrcpp::downCast<UnitContext *>(_localctx)->fdec->code_section;
              writeIntoparserLogFile("Line "+std::to_string(_localctx->line)+": unit : func_declaration\n\n"+_localctx->text+"\n");

          
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(70);
      antlrcpp::downCast<UnitContext *>(_localctx)->fdef = func_definition();
        
              antlrcpp::downCast<UnitContext *>(_localctx)->text =  antlrcpp::downCast<UnitContext *>(_localctx)->fdef->text;
              antlrcpp::downCast<UnitContext *>(_localctx)->line =  antlrcpp::downCast<UnitContext *>(_localctx)->fdef->line;
              antlrcpp::downCast<UnitContext *>(_localctx)->data_section_code =  "";
              antlrcpp::downCast<UnitContext *>(_localctx)->code_section =  antlrcpp::downCast<UnitContext *>(_localctx)->fdef->code_section;
              writeIntoparserLogFile("Line "+std::to_string(_localctx->line)+": unit : func_definition\n\n"+_localctx->text+"\n");
              
          
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Func_declarationContext ------------------------------------------------------------------

C2105168Parser::Func_declarationContext::Func_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* C2105168Parser::Func_declarationContext::ID() {
  return getToken(C2105168Parser::ID, 0);
}

tree::TerminalNode* C2105168Parser::Func_declarationContext::LPAREN() {
  return getToken(C2105168Parser::LPAREN, 0);
}

tree::TerminalNode* C2105168Parser::Func_declarationContext::RPAREN() {
  return getToken(C2105168Parser::RPAREN, 0);
}

tree::TerminalNode* C2105168Parser::Func_declarationContext::SEMICOLON() {
  return getToken(C2105168Parser::SEMICOLON, 0);
}

C2105168Parser::Type_specifierContext* C2105168Parser::Func_declarationContext::type_specifier() {
  return getRuleContext<C2105168Parser::Type_specifierContext>(0);
}

C2105168Parser::Parameter_listContext* C2105168Parser::Func_declarationContext::parameter_list() {
  return getRuleContext<C2105168Parser::Parameter_listContext>(0);
}


size_t C2105168Parser::Func_declarationContext::getRuleIndex() const {
  return C2105168Parser::RuleFunc_declaration;
}

void C2105168Parser::Func_declarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105168ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunc_declaration(this);
}

void C2105168Parser::Func_declarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105168ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunc_declaration(this);
}

C2105168Parser::Func_declarationContext* C2105168Parser::func_declaration() {
  Func_declarationContext *_localctx = _tracker.createInstance<Func_declarationContext>(_ctx, getState());
  enterRule(_localctx, 6, C2105168Parser::RuleFunc_declaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(91);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(75);
      antlrcpp::downCast<Func_declarationContext *>(_localctx)->ts = type_specifier();
      setState(76);
      antlrcpp::downCast<Func_declarationContext *>(_localctx)->idToken = match(C2105168Parser::ID);

              paramCount = 0;
          
      setState(78);
      antlrcpp::downCast<Func_declarationContext *>(_localctx)->lparenToken = match(C2105168Parser::LPAREN);
      setState(79);
      antlrcpp::downCast<Func_declarationContext *>(_localctx)->pl = parameter_list(0);
      setState(80);
      antlrcpp::downCast<Func_declarationContext *>(_localctx)->rparenToken = match(C2105168Parser::RPAREN);
      setState(81);
      antlrcpp::downCast<Func_declarationContext *>(_localctx)->semicolonToken = match(C2105168Parser::SEMICOLON);
        

              antlrcpp::downCast<Func_declarationContext *>(_localctx)->text =  antlrcpp::downCast<Func_declarationContext *>(_localctx)->ts->text +" "+ antlrcpp::downCast<Func_declarationContext *>(_localctx)->idToken->getText() + antlrcpp::downCast<Func_declarationContext *>(_localctx)->lparenToken->getText() + antlrcpp::downCast<Func_declarationContext *>(_localctx)->pl->text+ antlrcpp::downCast<Func_declarationContext *>(_localctx)->rparenToken->getText() +  antlrcpp::downCast<Func_declarationContext *>(_localctx)->semicolonToken->getText();
              antlrcpp::downCast<Func_declarationContext *>(_localctx)->line =  antlrcpp::downCast<Func_declarationContext *>(_localctx)->semicolonToken->getLine(); 
              antlrcpp::downCast<Func_declarationContext *>(_localctx)->type =  antlrcpp::downCast<Func_declarationContext *>(_localctx)->ts->text;

              SymbolInfo* funcSymbol = new SymbolInfo(antlrcpp::downCast<Func_declarationContext *>(_localctx)->idToken->getText(), "ID");

              funcSymbol->setIsFunction(true);
              funcSymbol->setIsFunctionDefined(true);
              funcSymbol->setReturnType(antlrcpp::downCast<Func_declarationContext *>(_localctx)->ts->text);
              funcSymbol->setParameterList(antlrcpp::downCast<Func_declarationContext *>(_localctx)->pl->plist);
              funcSymbol->setIsDeclared(true);
              plist = antlrcpp::downCast<Func_declarationContext *>(_localctx)->pl->plist;  

              fndecreturnTypes.push_back(antlrcpp::downCast<Func_declarationContext *>(_localctx)->ts->text);


              SymbolInfo* existing = symbolTable->LookUP(antlrcpp::downCast<Func_declarationContext *>(_localctx)->idToken->getText());
              if (existing && existing->getIsFunction() && existing->getIsFunctionDefined()) {
                  // writeIntoparserLogFile("Error at line " + std::to_string(_localctx->line) + ": Multiple definition of function " + antlrcpp::downCast<Func_declarationContext *>(_localctx)->idToken->getText());
              } else {
                  if(symbolTable->Insert(funcSymbol)){ 
                     // std::cout << funcSymbol->getSymbolName() << antlrcpp::downCast<Func_declarationContext *>(_localctx)->idToken->getText() << std::endl;

                    //  writeIntoErrorFile("Error at line "+std::to_string(_localctx->line)+": Multiple declaration of "+antlrcpp::downCast<Func_declarationContext *>(_localctx)->idToken->getText()+"\n");

                  }


              }

          // for (auto& param : antlrcpp::downCast<Func_declarationContext *>(_localctx)->pl->plist) {
          //     symbolTable->Insert(param.second, "ID");
          // }


              writeIntoparserLogFile("Line "+std::to_string(_localctx->line)+": func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON\n\n"+_localctx->text+"\n");


          
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(84);
      antlrcpp::downCast<Func_declarationContext *>(_localctx)->ts = type_specifier();
      setState(85);
      antlrcpp::downCast<Func_declarationContext *>(_localctx)->idToken = match(C2105168Parser::ID);
      setState(86);
      antlrcpp::downCast<Func_declarationContext *>(_localctx)->lparenToken = match(C2105168Parser::LPAREN);
      setState(87);
      antlrcpp::downCast<Func_declarationContext *>(_localctx)->rparenToken = match(C2105168Parser::RPAREN);
      setState(88);
      antlrcpp::downCast<Func_declarationContext *>(_localctx)->semicolonToken = match(C2105168Parser::SEMICOLON);
        
              antlrcpp::downCast<Func_declarationContext *>(_localctx)->text =  antlrcpp::downCast<Func_declarationContext *>(_localctx)->ts->text + " "+antlrcpp::downCast<Func_declarationContext *>(_localctx)->idToken->getText() + antlrcpp::downCast<Func_declarationContext *>(_localctx)->lparenToken->getText() + antlrcpp::downCast<Func_declarationContext *>(_localctx)->rparenToken->getText() +  antlrcpp::downCast<Func_declarationContext *>(_localctx)->semicolonToken->getText();
              antlrcpp::downCast<Func_declarationContext *>(_localctx)->line =  antlrcpp::downCast<Func_declarationContext *>(_localctx)->semicolonToken->getLine(); 
              antlrcpp::downCast<Func_declarationContext *>(_localctx)->type =  antlrcpp::downCast<Func_declarationContext *>(_localctx)->ts->text;

              

              SymbolInfo* funcSymbol = new SymbolInfo(antlrcpp::downCast<Func_declarationContext *>(_localctx)->idToken->getText(), "ID");
              funcSymbol->setIsFunction(true);
              funcSymbol->setIsFunctionDefined(true);
              funcSymbol->setReturnType(antlrcpp::downCast<Func_declarationContext *>(_localctx)->ts->text);
              funcSymbol->setIsDeclared(true);



              SymbolInfo* existing = symbolTable->LookUP(antlrcpp::downCast<Func_declarationContext *>(_localctx)->idToken->getText());
              if (existing && existing->getIsFunction() && existing->getIsFunctionDefined()) {
                  writeIntoparserLogFile("Error at line " + std::to_string(_localctx->line) + ": Redeclaration of function " + antlrcpp::downCast<Func_declarationContext *>(_localctx)->idToken->getText());
              } else {
                  if(symbolTable->Insert(funcSymbol)){ 
                         // std::cout << funcSymbol->getSymbolName() << antlrcpp::downCast<Func_declarationContext *>(_localctx)->idToken->getText() << std::endl;
                               //       writeIntoErrorFile("Error at line "+std::to_string(_localctx->line)+":  Multiple declaration of "+antlrcpp::downCast<Func_declarationContext *>(_localctx)->idToken->getText()+"\n");

                  }        }

           

              writeIntoparserLogFile("Line "+std::to_string(_localctx->line)+": func_declaration : type_specifier ID LPAREN RPAREN SEMICOLON\n\n"+_localctx->text+"\n");

              
          
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Func_definitionContext ------------------------------------------------------------------

C2105168Parser::Func_definitionContext::Func_definitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* C2105168Parser::Func_definitionContext::ID() {
  return getToken(C2105168Parser::ID, 0);
}

tree::TerminalNode* C2105168Parser::Func_definitionContext::LPAREN() {
  return getToken(C2105168Parser::LPAREN, 0);
}

tree::TerminalNode* C2105168Parser::Func_definitionContext::RPAREN() {
  return getToken(C2105168Parser::RPAREN, 0);
}

C2105168Parser::Type_specifierContext* C2105168Parser::Func_definitionContext::type_specifier() {
  return getRuleContext<C2105168Parser::Type_specifierContext>(0);
}

C2105168Parser::Parameter_listContext* C2105168Parser::Func_definitionContext::parameter_list() {
  return getRuleContext<C2105168Parser::Parameter_listContext>(0);
}

C2105168Parser::Compound_statementContext* C2105168Parser::Func_definitionContext::compound_statement() {
  return getRuleContext<C2105168Parser::Compound_statementContext>(0);
}


size_t C2105168Parser::Func_definitionContext::getRuleIndex() const {
  return C2105168Parser::RuleFunc_definition;
}

void C2105168Parser::Func_definitionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105168ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunc_definition(this);
}

void C2105168Parser::Func_definitionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105168ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunc_definition(this);
}

C2105168Parser::Func_definitionContext* C2105168Parser::func_definition() {
  Func_definitionContext *_localctx = _tracker.createInstance<Func_definitionContext>(_ctx, getState());
  enterRule(_localctx, 8, C2105168Parser::RuleFunc_definition);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(111);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(93);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->ts = type_specifier();
      setState(94);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken = match(C2105168Parser::ID);
      setState(95);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->lparenToken = match(C2105168Parser::LPAREN);
          std::cout << "DEBUG: About to parse parameter_list" << std::endl;
      setState(97);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->pl = parameter_list(0);

                  std::cout << "DEBUG: Successfully parsed parameter_list, pl.text = '" << antlrcpp::downCast<Func_definitionContext *>(_localctx)->pl->text << "'" << std::endl;
              SymbolInfo* funcSymbol = new SymbolInfo(antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getText(), "ID");
              funcSymbol->setIsFunction(true);
              funcSymbol->setIsFunctionDefined(true);
              funcSymbol->setReturnType(antlrcpp::downCast<Func_definitionContext *>(_localctx)->ts->text);


             // std::cout<< "return type "<< funcSymbol->getSymbolName() << funcSymbol->getReturnType() << std::endl;
              funcSymbol->setParameterList(antlrcpp::downCast<Func_definitionContext *>(_localctx)->pl->plist);
              plist = antlrcpp::downCast<Func_definitionContext *>(_localctx)->pl->plist;
              fndefreturnTypes.push_back(antlrcpp::downCast<Func_definitionContext *>(_localctx)->ts->text);

              SymbolInfo* existing = symbolTable->LookUP(antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getText());

              if (existing && existing->getIsFunction() && existing->getIsFunctionDefined()) {
                 // writeIntoparserLogFile("Error at line " + std::to_string(_localctx->line) + ": Multiple definition of function " + antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getText());
              } else {
                  symbolTable->Insert(funcSymbol);
              }


              SymbolInfo* lookup = symbolTable->LookUP(antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getText());       
              if(antlrcpp::downCast<Func_definitionContext *>(_localctx)->ts->text != lookup->getReturnType() ){

              writeIntoparserLogFile("Error at line "+std::to_string(antlrcpp::downCast<Func_definitionContext *>(_localctx)->ts->line)+": Return type mismatch of "+lookup->getSymbolName()+"\n");
              writeIntoErrorFile("Error at line "+std::to_string(antlrcpp::downCast<Func_definitionContext *>(_localctx)->ts->line)+": Return type mismatch of "+lookup->getSymbolName()+"\n");

                      errorCount++;
              }


           
      setState(99);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->rparenToken = match(C2105168Parser::RPAREN);
      setState(100);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->cs = compound_statement();
        


              antlrcpp::downCast<Func_definitionContext *>(_localctx)->text =  antlrcpp::downCast<Func_definitionContext *>(_localctx)->ts->text+" "  + antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getText() +  antlrcpp::downCast<Func_definitionContext *>(_localctx)->lparenToken->getText()+ antlrcpp::downCast<Func_definitionContext *>(_localctx)->pl->text + antlrcpp::downCast<Func_definitionContext *>(_localctx)->rparenToken->getText() + antlrcpp::downCast<Func_definitionContext *>(_localctx)->cs->text;
              antlrcpp::downCast<Func_definitionContext *>(_localctx)->line =  antlrcpp::downCast<Func_definitionContext *>(_localctx)->cs->line;
              antlrcpp::downCast<Func_definitionContext *>(_localctx)->type =  antlrcpp::downCast<Func_definitionContext *>(_localctx)->ts->text;
              antlrcpp::downCast<Func_definitionContext *>(_localctx)->code_section =  antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getText() + " PROC\n";
              antlrcpp::downCast<Func_definitionContext *>(_localctx)->returnType =  antlrcpp::downCast<Func_definitionContext *>(_localctx)->cs->type;

              if (antlrcpp::downCast<Func_definitionContext *>(_localctx)->ts->text == "void" && _localctx->returnType != "void") {
                  writeIntoErrorFile("Error at line " + std::to_string(_localctx->line) + ": Cannot return value from function "+  antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getText() + " with void return type\n");
                   writeIntoparserLogFile("Error at line " + std::to_string(_localctx->line) + ": Cannot return value from function "+  antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getText() + " with void return type\n");
                  errorCount++;
              } 
              

              //symbolTable->print_current_scope_table(parserLogFile);

              writeIntoparserLogFile("\nLine "+std::to_string(_localctx->line)+": func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement\n\n"+_localctx->text+"\n");
       

          
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(103);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->ts = type_specifier();
      setState(104);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken = match(C2105168Parser::ID);
      setState(105);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->lparenToken = match(C2105168Parser::LPAREN);
      setState(106);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->rparenToken = match(C2105168Parser::RPAREN);
       

              SymbolInfo* funcSymbol = new SymbolInfo(antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getText(), "ID");
              funcSymbol->setIsFunction(true);
              funcSymbol->setReturnType(antlrcpp::downCast<Func_definitionContext *>(_localctx)->ts->text);

              // if(antlrcpp::downCast<Func_definitionContext *>(_localctx)->cs->type != antlrcpp::downCast<Func_definitionContext *>(_localctx)->ts->text){ 
              //     writeIntoErrorFile("Error at line "+std::to_string(_localctx->line)+": Return Type mismatch of "+funcSymbol->getSymbolName()+"\n");
              // }
              
              SymbolInfo* existing = symbolTable->LookUP(antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getText());
              if (existing && existing->getIsFunction() && existing->getIsFunctionDefined()) {
                 // writeIntoparserLogFile("Error at line " + std::to_string(_localctx->line) + ": Multiple definition of function " + antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getText());
              } else {
                  symbolTable->Insert(funcSymbol);
                  funcSymbol->setIsFunctionDefined(true);

              }

              
      setState(108);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->cs = compound_statement();
       

              antlrcpp::downCast<Func_definitionContext *>(_localctx)->text =  antlrcpp::downCast<Func_definitionContext *>(_localctx)->ts->text +" " + antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getText() +  antlrcpp::downCast<Func_definitionContext *>(_localctx)->lparenToken->getText() + antlrcpp::downCast<Func_definitionContext *>(_localctx)->rparenToken->getText() + antlrcpp::downCast<Func_definitionContext *>(_localctx)->cs->text;
              antlrcpp::downCast<Func_definitionContext *>(_localctx)->line =  antlrcpp::downCast<Func_definitionContext *>(_localctx)->cs->line;
              antlrcpp::downCast<Func_definitionContext *>(_localctx)->code_section =  antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getText() + " PROC\n" +antlrcpp::downCast<Func_definitionContext *>(_localctx)->cs->code_section;
              std::cout << "DEBUG: func_declaration code_section = '" << _localctx->code_section << "'" << std::endl;



              writeIntoparserLogFile("\nLine "+std::to_string(_localctx->line)+": func_definition : type_specifier ID LPAREN RPAREN compound_statement\n\n"+_localctx->text+"\n");


          
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Parameter_listContext ------------------------------------------------------------------

C2105168Parser::Parameter_listContext::Parameter_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* C2105168Parser::Parameter_listContext::ID() {
  return getToken(C2105168Parser::ID, 0);
}

C2105168Parser::Type_specifierContext* C2105168Parser::Parameter_listContext::type_specifier() {
  return getRuleContext<C2105168Parser::Type_specifierContext>(0);
}

tree::TerminalNode* C2105168Parser::Parameter_listContext::ADDOP() {
  return getToken(C2105168Parser::ADDOP, 0);
}

tree::TerminalNode* C2105168Parser::Parameter_listContext::COMMA() {
  return getToken(C2105168Parser::COMMA, 0);
}

C2105168Parser::Parameter_listContext* C2105168Parser::Parameter_listContext::parameter_list() {
  return getRuleContext<C2105168Parser::Parameter_listContext>(0);
}


size_t C2105168Parser::Parameter_listContext::getRuleIndex() const {
  return C2105168Parser::RuleParameter_list;
}

void C2105168Parser::Parameter_listContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105168ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParameter_list(this);
}

void C2105168Parser::Parameter_listContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105168ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParameter_list(this);
}


C2105168Parser::Parameter_listContext* C2105168Parser::parameter_list() {
   return parameter_list(0);
}

C2105168Parser::Parameter_listContext* C2105168Parser::parameter_list(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  C2105168Parser::Parameter_listContext *_localctx = _tracker.createInstance<Parameter_listContext>(_ctx, parentState);
  C2105168Parser::Parameter_listContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 10;
  enterRecursionRule(_localctx, 10, C2105168Parser::RuleParameter_list, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(127);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
    case 1: {
      setState(114);
      antlrcpp::downCast<Parameter_listContext *>(_localctx)->ts = type_specifier();
      setState(115);
      antlrcpp::downCast<Parameter_listContext *>(_localctx)->idToken = match(C2105168Parser::ID);

              antlrcpp::downCast<Parameter_listContext *>(_localctx)->text =  antlrcpp::downCast<Parameter_listContext *>(_localctx)->ts->text + " " + antlrcpp::downCast<Parameter_listContext *>(_localctx)->idToken->getText()   ;
              antlrcpp::downCast<Parameter_listContext *>(_localctx)->line =  antlrcpp::downCast<Parameter_listContext *>(_localctx)->idToken->getLine();
              _localctx->plist.push_back(std::make_pair(antlrcpp::downCast<Parameter_listContext *>(_localctx)->ts->text, antlrcpp::downCast<Parameter_listContext *>(_localctx)->idToken->getText()));

              SymbolInfo* paramSymbol = new SymbolInfo(antlrcpp::downCast<Parameter_listContext *>(_localctx)->idToken->getText(), "ID");
              paramSymbol->setIsArray(false);
              paramSymbol->setType(antlrcpp::downCast<Parameter_listContext *>(_localctx)->ts->text);

              writeIntoparserLogFile("Line " + std::to_string(_localctx->line) +": parameter_list : type_specifier ID\n\n" + _localctx->text + "\n");
      		
      break;
    }

    case 2: {
      setState(118);
      antlrcpp::downCast<Parameter_listContext *>(_localctx)->ts = type_specifier();
      setState(119);
      antlrcpp::downCast<Parameter_listContext *>(_localctx)->addopToken = match(C2105168Parser::ADDOP);

              antlrcpp::downCast<Parameter_listContext *>(_localctx)->text =  antlrcpp::downCast<Parameter_listContext *>(_localctx)->ts->text;
              antlrcpp::downCast<Parameter_listContext *>(_localctx)->line =  antlrcpp::downCast<Parameter_listContext *>(_localctx)->addopToken->getLine();
              writeIntoErrorFile("Error at line " + std::to_string(_localctx->line) + ": syntax error, unexpected ADDOP, expecting RPAREN or COMMA\n");
              writeIntoparserLogFile("Error at line " + std::to_string(_localctx->line) + ": syntax error, unexpected ADDOP, expecting RPAREN or COMMA\n");
              
      break;
    }

    case 3: {
      setState(122);
      antlrcpp::downCast<Parameter_listContext *>(_localctx)->ts = type_specifier();


              antlrcpp::downCast<Parameter_listContext *>(_localctx)->text =  antlrcpp::downCast<Parameter_listContext *>(_localctx)->ts->text ;
              antlrcpp::downCast<Parameter_listContext *>(_localctx)->line =  antlrcpp::downCast<Parameter_listContext *>(_localctx)->ts->line;
                  std::cout << "DEBUG: ts.text = '" << antlrcpp::downCast<Parameter_listContext *>(_localctx)->ts->text << "'" << std::endl;
          std::cout << "DEBUG: ts.line = " << antlrcpp::downCast<Parameter_listContext *>(_localctx)->ts->line << std::endl;
              _localctx->plist.push_back(std::make_pair(antlrcpp::downCast<Parameter_listContext *>(_localctx)->ts->text, ""));
              writeIntoparserLogFile("Line " + std::to_string(_localctx->line) + ": parameter_list : type_specifier \n" +antlrcpp::downCast<Parameter_listContext *>(_localctx)->ts->text+ "\n");
      		
      break;
    }

    case 4: {
      setState(125);
      antlrcpp::downCast<Parameter_listContext *>(_localctx)->addopToken = match(C2105168Parser::ADDOP);

              antlrcpp::downCast<Parameter_listContext *>(_localctx)->line =  antlrcpp::downCast<Parameter_listContext *>(_localctx)->addopToken->getLine();
              writeIntoErrorFile("Error at line " + std::to_string(_localctx->line) + ": syntax error, unexpected ADDOP, expecting RPAREN or COMMA\n");
              writeIntoparserLogFile("Error at line " + std::to_string(_localctx->line) + ": syntax error, unexpected ADDOP, expecting RPAREN or COMMA\n");
              
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(146);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(144);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<Parameter_listContext>(parentContext, parentState);
          _localctx->pl = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleParameter_list);
          setState(129);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(130);
          antlrcpp::downCast<Parameter_listContext *>(_localctx)->commaToken = match(C2105168Parser::COMMA);
          setState(131);
          antlrcpp::downCast<Parameter_listContext *>(_localctx)->ts = type_specifier();
          setState(132);
          antlrcpp::downCast<Parameter_listContext *>(_localctx)->idToken = match(C2105168Parser::ID);

                            antlrcpp::downCast<Parameter_listContext *>(_localctx)->text = antlrcpp::downCast<Parameter_listContext *>(_localctx)->pl->text+antlrcpp::downCast<Parameter_listContext *>(_localctx)->commaToken->getText()+ antlrcpp::downCast<Parameter_listContext *>(_localctx)->ts->text +" " + antlrcpp::downCast<Parameter_listContext *>(_localctx)->idToken->getText();
                            antlrcpp::downCast<Parameter_listContext *>(_localctx)->line =  antlrcpp::downCast<Parameter_listContext *>(_localctx)->idToken->getLine();
                            antlrcpp::downCast<Parameter_listContext *>(_localctx)->plist =  antlrcpp::downCast<Parameter_listContext *>(_localctx)->pl->plist;
                                    paramCount++;

                            _localctx->plist.push_back(std::make_pair(antlrcpp::downCast<Parameter_listContext *>(_localctx)->ts->text, antlrcpp::downCast<Parameter_listContext *>(_localctx)->idToken->getText()));
                            
                             writeIntoparserLogFile("Line " + std::to_string(_localctx->line) + ": parameter_list : parameter_list COMMA type_specifier ID\n\n"+_localctx->text+"\n");
                        
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<Parameter_listContext>(parentContext, parentState);
          _localctx->pl = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleParameter_list);
          setState(135);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(136);
          antlrcpp::downCast<Parameter_listContext *>(_localctx)->commaToken = match(C2105168Parser::COMMA);
          setState(137);
          antlrcpp::downCast<Parameter_listContext *>(_localctx)->ts = type_specifier();

                            antlrcpp::downCast<Parameter_listContext *>(_localctx)->text = antlrcpp::downCast<Parameter_listContext *>(_localctx)->pl->text + antlrcpp::downCast<Parameter_listContext *>(_localctx)->commaToken->getText() +  antlrcpp::downCast<Parameter_listContext *>(_localctx)->ts->text ;
                            antlrcpp::downCast<Parameter_listContext *>(_localctx)->line =  antlrcpp::downCast<Parameter_listContext *>(_localctx)->ts->line;
                            antlrcpp::downCast<Parameter_listContext *>(_localctx)->plist =  antlrcpp::downCast<Parameter_listContext *>(_localctx)->pl->plist;
                            _localctx->plist.push_back(std::make_pair(antlrcpp::downCast<Parameter_listContext *>(_localctx)->ts->text, ""));
                            writeIntoparserLogFile("Line " + std::to_string(_localctx->line) + ": parameter_list : parameter_list COMMA type_specifier \n" +_localctx->text + "\n");
                    		
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<Parameter_listContext>(parentContext, parentState);
          _localctx->pl = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleParameter_list);
          setState(140);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(141);
          antlrcpp::downCast<Parameter_listContext *>(_localctx)->commaToken = match(C2105168Parser::COMMA);
          setState(142);
          antlrcpp::downCast<Parameter_listContext *>(_localctx)->addopToken = match(C2105168Parser::ADDOP);

                            antlrcpp::downCast<Parameter_listContext *>(_localctx)->text =  antlrcpp::downCast<Parameter_listContext *>(_localctx)->pl->text;
                            antlrcpp::downCast<Parameter_listContext *>(_localctx)->line =  antlrcpp::downCast<Parameter_listContext *>(_localctx)->addopToken->getLine();
                            writeIntoparserLogFile("Error at line " + std::to_string(_localctx->line) + 
                                ": syntax error, unexpected ADDOP, expecting type_specifier\n");
                            writeIntoErrorFile("Error at line " + std::to_string(_localctx->line) + 
                                ": syntax error, unexpected ADDOP, expecting type_specifier\n");
                        
          break;
        }

        default:
          break;
        } 
      }
      setState(148);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- Compound_statementContext ------------------------------------------------------------------

C2105168Parser::Compound_statementContext::Compound_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* C2105168Parser::Compound_statementContext::LCURL() {
  return getToken(C2105168Parser::LCURL, 0);
}

tree::TerminalNode* C2105168Parser::Compound_statementContext::RCURL() {
  return getToken(C2105168Parser::RCURL, 0);
}

C2105168Parser::StatementsContext* C2105168Parser::Compound_statementContext::statements() {
  return getRuleContext<C2105168Parser::StatementsContext>(0);
}


size_t C2105168Parser::Compound_statementContext::getRuleIndex() const {
  return C2105168Parser::RuleCompound_statement;
}

void C2105168Parser::Compound_statementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105168ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCompound_statement(this);
}

void C2105168Parser::Compound_statementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105168ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCompound_statement(this);
}

C2105168Parser::Compound_statementContext* C2105168Parser::compound_statement() {
  Compound_statementContext *_localctx = _tracker.createInstance<Compound_statementContext>(_ctx, getState());
  enterRule(_localctx, 12, C2105168Parser::RuleCompound_statement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(160);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(149);
      antlrcpp::downCast<Compound_statementContext *>(_localctx)->lcurlToken = match(C2105168Parser::LCURL);
       symbolTable->EnterScope();  

              for(const auto& param : plist) {

                  antlrcpp::downCast<Compound_statementContext *>(_localctx)->line =  antlrcpp::downCast<Compound_statementContext *>(_localctx)->lcurlToken->getLine();
                  SymbolInfo* paramSymbol = new SymbolInfo(param.second, "ID");
                  paramSymbol->setIsArray(false);
                  paramSymbol->setSymbolDataType(param.first);
                  if(!symbolTable->Insert(param.second, "ID")){
                      writeIntoparserLogFile("Error at line " + std::to_string(_localctx->line) + ": Multiple declaration of " + param.second + " in parameter\n");
                      writeIntoErrorFile("Error at line " + std::to_string(_localctx->line) + ": Multiple declaration of " + param.second + " in parameter\n");

                      errorCount++;
                  }
              }
              plist.clear();
              
               
      setState(151);
      antlrcpp::downCast<Compound_statementContext *>(_localctx)->ss = statements(0);
       
              // std::cout << "ss  type"<<antlrcpp::downCast<Compound_statementContext *>(_localctx)->ss->type <<std::endl;
              antlrcpp::downCast<Compound_statementContext *>(_localctx)->type =  antlrcpp::downCast<Compound_statementContext *>(_localctx)->ss->type;
          
      setState(153);
      antlrcpp::downCast<Compound_statementContext *>(_localctx)->rcurlToken = match(C2105168Parser::RCURL);

              antlrcpp::downCast<Compound_statementContext *>(_localctx)->text =  antlrcpp::downCast<Compound_statementContext *>(_localctx)->lcurlToken->getText()+"\n" + antlrcpp::downCast<Compound_statementContext *>(_localctx)->ss->text +"\n" + antlrcpp::downCast<Compound_statementContext *>(_localctx)->rcurlToken->getText();
              antlrcpp::downCast<Compound_statementContext *>(_localctx)->line =  (antlrcpp::downCast<Compound_statementContext *>(_localctx)->rcurlToken != nullptr ? antlrcpp::downCast<Compound_statementContext *>(_localctx)->rcurlToken->getLine() : 0);
              antlrcpp::downCast<Compound_statementContext *>(_localctx)->code_section =  antlrcpp::downCast<Compound_statementContext *>(_localctx)->ss->code_section;
              writeIntoparserLogFile("Line "+std::to_string(_localctx->line)+": compound_statement : LCURL statements RCURL\n\n"+_localctx->text+"\n");
              symbolTable->print_all_scope_table2(parserLogFile);
              symbolTable->ExitScope();


          
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(156);
      antlrcpp::downCast<Compound_statementContext *>(_localctx)->lcurlToken = match(C2105168Parser::LCURL);
      symbolTable->EnterScope();
      setState(158);
      antlrcpp::downCast<Compound_statementContext *>(_localctx)->rcurlToken = match(C2105168Parser::RCURL);


              antlrcpp::downCast<Compound_statementContext *>(_localctx)->text =  antlrcpp::downCast<Compound_statementContext *>(_localctx)->lcurlToken->getText()+antlrcpp::downCast<Compound_statementContext *>(_localctx)->rcurlToken->getText();
              antlrcpp::downCast<Compound_statementContext *>(_localctx)->line =  antlrcpp::downCast<Compound_statementContext *>(_localctx)->rcurlToken->getLine();
              antlrcpp::downCast<Compound_statementContext *>(_localctx)->type =  "void"; 
              writeIntoparserLogFile("Line "+std::to_string(_localctx->line)+": compound_statement : LCURL RCURL\n\n"+_localctx->text+"\n");

              symbolTable->print_all_scope_table2(parserLogFile);
              symbolTable->ExitScope();

          
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Var_declarationContext ------------------------------------------------------------------

C2105168Parser::Var_declarationContext::Var_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C2105168Parser::Type_specifierContext* C2105168Parser::Var_declarationContext::type_specifier() {
  return getRuleContext<C2105168Parser::Type_specifierContext>(0);
}

C2105168Parser::Declaration_listContext* C2105168Parser::Var_declarationContext::declaration_list() {
  return getRuleContext<C2105168Parser::Declaration_listContext>(0);
}

tree::TerminalNode* C2105168Parser::Var_declarationContext::SEMICOLON() {
  return getToken(C2105168Parser::SEMICOLON, 0);
}

C2105168Parser::Declaration_list_errContext* C2105168Parser::Var_declarationContext::declaration_list_err() {
  return getRuleContext<C2105168Parser::Declaration_list_errContext>(0);
}


size_t C2105168Parser::Var_declarationContext::getRuleIndex() const {
  return C2105168Parser::RuleVar_declaration;
}

void C2105168Parser::Var_declarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105168ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVar_declaration(this);
}

void C2105168Parser::Var_declarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105168ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVar_declaration(this);
}

C2105168Parser::Var_declarationContext* C2105168Parser::var_declaration() {
  Var_declarationContext *_localctx = _tracker.createInstance<Var_declarationContext>(_ctx, getState());
  enterRule(_localctx, 14, C2105168Parser::RuleVar_declaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(172);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(162);
      antlrcpp::downCast<Var_declarationContext *>(_localctx)->t = type_specifier();
      setState(163);
      antlrcpp::downCast<Var_declarationContext *>(_localctx)->dl = declaration_list(0);
      setState(164);
      antlrcpp::downCast<Var_declarationContext *>(_localctx)->sm = match(C2105168Parser::SEMICOLON);

              antlrcpp::downCast<Var_declarationContext *>(_localctx)->text =  antlrcpp::downCast<Var_declarationContext *>(_localctx)->t->text +" "+ antlrcpp::downCast<Var_declarationContext *>(_localctx)->dl->text + antlrcpp::downCast<Var_declarationContext *>(_localctx)->sm->getText() ;
              antlrcpp::downCast<Var_declarationContext *>(_localctx)->line =  antlrcpp::downCast<Var_declarationContext *>(_localctx)->t->line;
              antlrcpp::downCast<Var_declarationContext *>(_localctx)->data_section_code =  "";
              antlrcpp::downCast<Var_declarationContext *>(_localctx)->code_section =  "";
              bool pushbpprint = false;
              writeIntoparserLogFile("Line "+std::to_string(_localctx->line)+": var_declaration : type_specifier declaration_list SEMICOLON\n\n"+_localctx->text+"\n");


              for(const auto& var : antlrcpp::downCast<Var_declarationContext *>(_localctx)->dl->varList) {
                  SymbolInfo* varSymbol = new SymbolInfo(var.first, "ID");
                  varSymbol->setIsArray(var.second);
                  varSymbol->setSymbolDataType(antlrcpp::downCast<Var_declarationContext *>(_localctx)->t->type);
                  if(!symbolTable->Insert(varSymbol)){
                      writeIntoparserLogFile("Error at line "+std::to_string(_localctx->line)+":  Multiple declaration of "+var.first+"\n");
                      writeIntoErrorFile("Error at line "+std::to_string(_localctx->line)+": Multiple declaration of "+var.first+"\n");
                                      errorCount++;
                  }

                  //I want to know the current scope id of the inserted variable

                  std::string currentScopeId = symbolTable->getCurrentScopeID();

                  if(currentScopeId == "1"){
                      isDATAEmpty = false;
                      stack_offset_global += 2;
                      varSymbol->setStackOffset(stack_offset_global);
                      std::cout << "got " << varSymbol->getSymbolName() << " with stack offset " << varSymbol->getStackOffset() << std::endl;                _localctx->data_section_code += varSymbol->getSymbolName() + " DW 1 DUP (0000H)\n";

                      std::cout << "data_section_code: " << _localctx->data_section_code << std::endl;
                  }


                  else if(currentScopeId != "1"){
                      if(!isDATAEmpty){
                          _localctx->code_section += "\tMOV AX, @DATA\n\tMOV DS, AX\n\tPUSH BP\n\tMOV BP, SP\n";
                          isDATAEmpty = true;
                          pushbpprint = true;
                      }
                      else if(isDATAEmpty && !pushbpprint){
                          _localctx->code_section += "\tPUSH BP\n\tMOV BP, SP\n";
                          pushbpprint = true;
                      }
                      stack_offset_local += 2;
                      varSymbol->setStackOffset(stack_offset_local);
                      std::cout << "got " << varSymbol->getSymbolName() << " with stack offset " << varSymbol->getStackOffset() << std::endl;
                      _localctx->code_section += "\tSUB SP, 2\n";

                  }



              }

              if(antlrcpp::downCast<Var_declarationContext *>(_localctx)->t->text == "void"){
                  writeIntoparserLogFile("Error at line "+std::to_string(_localctx->line)+":  Variable type cannot be void\n");
                  writeIntoErrorFile("Error at line "+std::to_string(_localctx->line)+": Variable type cannot be void\n");
                                  errorCount++;
              }

              

              
            
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(167);
      antlrcpp::downCast<Var_declarationContext *>(_localctx)->t = type_specifier();
      setState(168);
      antlrcpp::downCast<Var_declarationContext *>(_localctx)->de = declaration_list_err();
      setState(169);
      antlrcpp::downCast<Var_declarationContext *>(_localctx)->sm = match(C2105168Parser::SEMICOLON);

              antlrcpp::downCast<Var_declarationContext *>(_localctx)->text =  antlrcpp::downCast<Var_declarationContext *>(_localctx)->t->text;
              antlrcpp::downCast<Var_declarationContext *>(_localctx)->line =  antlrcpp::downCast<Var_declarationContext *>(_localctx)->t->line;
              writeIntoErrorFile(
                  std::string("Line# ") + std::to_string(antlrcpp::downCast<Var_declarationContext *>(_localctx)->sm->getLine()) +
                  " with error name: " + antlrcpp::downCast<Var_declarationContext *>(_localctx)->de->error_name +
                  " - Syntax error at declaration list of variable declaration"
              );


              syntaxErrorCount++;
            
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Declaration_list_errContext ------------------------------------------------------------------

C2105168Parser::Declaration_list_errContext::Declaration_list_errContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t C2105168Parser::Declaration_list_errContext::getRuleIndex() const {
  return C2105168Parser::RuleDeclaration_list_err;
}

void C2105168Parser::Declaration_list_errContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105168ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDeclaration_list_err(this);
}

void C2105168Parser::Declaration_list_errContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105168ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDeclaration_list_err(this);
}

C2105168Parser::Declaration_list_errContext* C2105168Parser::declaration_list_err() {
  Declaration_list_errContext *_localctx = _tracker.createInstance<Declaration_list_errContext>(_ctx, getState());
  enterRule(_localctx, 16, C2105168Parser::RuleDeclaration_list_err);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);

            antlrcpp::downCast<Declaration_list_errContext *>(_localctx)->error_name =  "Error in declaration list";
        
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Type_specifierContext ------------------------------------------------------------------

C2105168Parser::Type_specifierContext::Type_specifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* C2105168Parser::Type_specifierContext::INT() {
  return getToken(C2105168Parser::INT, 0);
}

tree::TerminalNode* C2105168Parser::Type_specifierContext::FLOAT() {
  return getToken(C2105168Parser::FLOAT, 0);
}

tree::TerminalNode* C2105168Parser::Type_specifierContext::VOID() {
  return getToken(C2105168Parser::VOID, 0);
}


size_t C2105168Parser::Type_specifierContext::getRuleIndex() const {
  return C2105168Parser::RuleType_specifier;
}

void C2105168Parser::Type_specifierContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105168ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterType_specifier(this);
}

void C2105168Parser::Type_specifierContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105168ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitType_specifier(this);
}

C2105168Parser::Type_specifierContext* C2105168Parser::type_specifier() {
  Type_specifierContext *_localctx = _tracker.createInstance<Type_specifierContext>(_ctx, getState());
  enterRule(_localctx, 18, C2105168Parser::RuleType_specifier);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(182);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case C2105168Parser::INT: {
        enterOuterAlt(_localctx, 1);
        setState(176);
        antlrcpp::downCast<Type_specifierContext *>(_localctx)->intToken = match(C2105168Parser::INT);

                    antlrcpp::downCast<Type_specifierContext *>(_localctx)->text =  antlrcpp::downCast<Type_specifierContext *>(_localctx)->intToken->getText();
                    antlrcpp::downCast<Type_specifierContext *>(_localctx)->line =  antlrcpp::downCast<Type_specifierContext *>(_localctx)->intToken->getLine();
                    antlrcpp::downCast<Type_specifierContext *>(_localctx)->type =  "int";
        			writeIntoparserLogFile("Line " + std::to_string(antlrcpp::downCast<Type_specifierContext *>(_localctx)->intToken->getLine()) + ": type_specifier : INT\n\n" + antlrcpp::downCast<Type_specifierContext *>(_localctx)->intToken->getText() + "\n");
                    if(multipleDeclaration){

                    }
                
        break;
      }

      case C2105168Parser::FLOAT: {
        enterOuterAlt(_localctx, 2);
        setState(178);
        antlrcpp::downCast<Type_specifierContext *>(_localctx)->floatToken = match(C2105168Parser::FLOAT);

                    antlrcpp::downCast<Type_specifierContext *>(_localctx)->text =  antlrcpp::downCast<Type_specifierContext *>(_localctx)->floatToken->getText();
                    antlrcpp::downCast<Type_specifierContext *>(_localctx)->line =  antlrcpp::downCast<Type_specifierContext *>(_localctx)->floatToken->getLine();
                    antlrcpp::downCast<Type_specifierContext *>(_localctx)->type =  "float";
        			writeIntoparserLogFile("Line " + std::to_string(antlrcpp::downCast<Type_specifierContext *>(_localctx)->floatToken->getLine()) + ": type_specifier : FLOAT\n\n" +antlrcpp::downCast<Type_specifierContext *>(_localctx)->floatToken->getText() + "\n");        
        		
        break;
      }

      case C2105168Parser::VOID: {
        enterOuterAlt(_localctx, 3);
        setState(180);
        antlrcpp::downCast<Type_specifierContext *>(_localctx)->voidToken = match(C2105168Parser::VOID);

                    antlrcpp::downCast<Type_specifierContext *>(_localctx)->text =  antlrcpp::downCast<Type_specifierContext *>(_localctx)->voidToken->getText();
                    antlrcpp::downCast<Type_specifierContext *>(_localctx)->line =  antlrcpp::downCast<Type_specifierContext *>(_localctx)->voidToken->getLine();
                    antlrcpp::downCast<Type_specifierContext *>(_localctx)->type =  "void";
                    writeIntoparserLogFile("Line " + std::to_string(antlrcpp::downCast<Type_specifierContext *>(_localctx)->voidToken->getLine()) + ": type_specifier : VOID\n\n" +antlrcpp::downCast<Type_specifierContext *>(_localctx)->voidToken->getText() + "\n");        
                
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Declaration_listContext ------------------------------------------------------------------

C2105168Parser::Declaration_listContext::Declaration_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* C2105168Parser::Declaration_listContext::ID() {
  return getToken(C2105168Parser::ID, 0);
}

tree::TerminalNode* C2105168Parser::Declaration_listContext::LTHIRD() {
  return getToken(C2105168Parser::LTHIRD, 0);
}

tree::TerminalNode* C2105168Parser::Declaration_listContext::CONST_INT() {
  return getToken(C2105168Parser::CONST_INT, 0);
}

tree::TerminalNode* C2105168Parser::Declaration_listContext::RTHIRD() {
  return getToken(C2105168Parser::RTHIRD, 0);
}

tree::TerminalNode* C2105168Parser::Declaration_listContext::ADDOP() {
  return getToken(C2105168Parser::ADDOP, 0);
}

C2105168Parser::Declaration_listContext* C2105168Parser::Declaration_listContext::declaration_list() {
  return getRuleContext<C2105168Parser::Declaration_listContext>(0);
}

tree::TerminalNode* C2105168Parser::Declaration_listContext::COMMA() {
  return getToken(C2105168Parser::COMMA, 0);
}


size_t C2105168Parser::Declaration_listContext::getRuleIndex() const {
  return C2105168Parser::RuleDeclaration_list;
}

void C2105168Parser::Declaration_listContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105168ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDeclaration_list(this);
}

void C2105168Parser::Declaration_listContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105168ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDeclaration_list(this);
}


C2105168Parser::Declaration_listContext* C2105168Parser::declaration_list() {
   return declaration_list(0);
}

C2105168Parser::Declaration_listContext* C2105168Parser::declaration_list(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  C2105168Parser::Declaration_listContext *_localctx = _tracker.createInstance<Declaration_listContext>(_ctx, parentState);
  C2105168Parser::Declaration_listContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 20;
  enterRecursionRule(_localctx, 20, C2105168Parser::RuleDeclaration_list, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(197);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx)) {
    case 1: {
      setState(185);
      antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken = match(C2105168Parser::ID);
       
              antlrcpp::downCast<Declaration_listContext *>(_localctx)->text =  antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken->getText();
              antlrcpp::downCast<Declaration_listContext *>(_localctx)->line =  antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken->getLine();
              _localctx->varList.push_back(std::make_pair(antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken->getText(), false));
              writeIntoparserLogFile("Line " + std::to_string(_localctx->line) + ": declaration_list : ID\n\n" +_localctx->text + "\n");        

          
      break;
    }

    case 2: {
      setState(187);
      antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken = match(C2105168Parser::ID);
      setState(188);
      antlrcpp::downCast<Declaration_listContext *>(_localctx)->lthirdToken = match(C2105168Parser::LTHIRD);
      setState(189);
      antlrcpp::downCast<Declaration_listContext *>(_localctx)->const_intToken = match(C2105168Parser::CONST_INT);
      setState(190);
      antlrcpp::downCast<Declaration_listContext *>(_localctx)->rthirdToken = match(C2105168Parser::RTHIRD);
       
              antlrcpp::downCast<Declaration_listContext *>(_localctx)->text =  antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken->getText() + antlrcpp::downCast<Declaration_listContext *>(_localctx)->lthirdToken->getText() + antlrcpp::downCast<Declaration_listContext *>(_localctx)->const_intToken->getText() + antlrcpp::downCast<Declaration_listContext *>(_localctx)->rthirdToken->getText();
              antlrcpp::downCast<Declaration_listContext *>(_localctx)->line =  antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken->getLine();

              antlrcpp::downCast<Declaration_listContext *>(_localctx)->type =  "array";
              _localctx->varList.push_back(std::make_pair(antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken->getText(), true));

              
              writeIntoparserLogFile("Line " + std::to_string(_localctx->line) + ": declaration_list : ID LTHIRD CONST_INT RTHIRD\n\n" +_localctx->text + "\n");        

          
      break;
    }

    case 3: {
      setState(192);
      antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken = match(C2105168Parser::ID);
      setState(193);
      antlrcpp::downCast<Declaration_listContext *>(_localctx)->addopToken = match(C2105168Parser::ADDOP);
      setState(194);
      antlrcpp::downCast<Declaration_listContext *>(_localctx)->declaration_listContext = declaration_list(1);

              antlrcpp::downCast<Declaration_listContext *>(_localctx)->text =  antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken->getText() + "," + antlrcpp::downCast<Declaration_listContext *>(_localctx)->declaration_listContext->text;
              antlrcpp::downCast<Declaration_listContext *>(_localctx)->line =  antlrcpp::downCast<Declaration_listContext *>(_localctx)->addopToken->getLine();
              _localctx->varList.push_back(std::make_pair(antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken->getText(), false));
              for(auto var : antlrcpp::downCast<Declaration_listContext *>(_localctx)->declaration_listContext->varList) {
                  _localctx->varList.push_back(var);
              }
              writeIntoparserLogFile("Line " + std::to_string(_localctx->line) + ": declaration_list : ID\n\n" + antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken->getText() + "\n");
              writeIntoErrorFile("Error at line " + std::to_string(_localctx->line) + ": syntax error, unexpected ADDOP, expecting COMMA or SEMICOLON\n");
              writeIntoparserLogFile("Error at line " + std::to_string(_localctx->line) + ": syntax error, unexpected ADDOP, expecting COMMA or SEMICOLON\n");
              writeIntoparserLogFile("Line " + std::to_string(antlrcpp::downCast<Declaration_listContext *>(_localctx)->declaration_listContext->line) + ": declaration_list : declaration_list COMMA ID\n\n" + _localctx->text + "\n");
              
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(217);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(215);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<Declaration_listContext>(parentContext, parentState);
          _localctx->dl = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleDeclaration_list);
          setState(199);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(200);
          antlrcpp::downCast<Declaration_listContext *>(_localctx)->commaToken = match(C2105168Parser::COMMA);
          setState(201);
          antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken = match(C2105168Parser::ID);
           

                            antlrcpp::downCast<Declaration_listContext *>(_localctx)->text =  antlrcpp::downCast<Declaration_listContext *>(_localctx)->dl->text + antlrcpp::downCast<Declaration_listContext *>(_localctx)->commaToken->getText() + antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken->getText();
                            antlrcpp::downCast<Declaration_listContext *>(_localctx)->line =  antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken->getLine();

                            antlrcpp::downCast<Declaration_listContext *>(_localctx)->varList =  antlrcpp::downCast<Declaration_listContext *>(_localctx)->dl->varList;
                    		_localctx->varList.push_back(std::make_pair(antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken->getText(), false));
                            
                            writeIntoparserLogFile("Line " + std::to_string(_localctx->line) + ": declaration_list : declaration_list COMMA ID\n\n" +_localctx->text + "\n");        

                        
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<Declaration_listContext>(parentContext, parentState);
          _localctx->dl = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleDeclaration_list);
          setState(203);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(204);
          antlrcpp::downCast<Declaration_listContext *>(_localctx)->commaToken = match(C2105168Parser::COMMA);
          setState(205);
          antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken = match(C2105168Parser::ID);
          setState(206);
          antlrcpp::downCast<Declaration_listContext *>(_localctx)->lthirdToken = match(C2105168Parser::LTHIRD);
          setState(207);
          antlrcpp::downCast<Declaration_listContext *>(_localctx)->const_intToken = match(C2105168Parser::CONST_INT);
          setState(208);
          antlrcpp::downCast<Declaration_listContext *>(_localctx)->rthirdToken = match(C2105168Parser::RTHIRD);
           
                            antlrcpp::downCast<Declaration_listContext *>(_localctx)->text =  antlrcpp::downCast<Declaration_listContext *>(_localctx)->dl->text + antlrcpp::downCast<Declaration_listContext *>(_localctx)->commaToken->getText() + antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken->getText() + antlrcpp::downCast<Declaration_listContext *>(_localctx)->lthirdToken->getText() + antlrcpp::downCast<Declaration_listContext *>(_localctx)->const_intToken->getText() + antlrcpp::downCast<Declaration_listContext *>(_localctx)->rthirdToken->getText();
                            antlrcpp::downCast<Declaration_listContext *>(_localctx)->line =  antlrcpp::downCast<Declaration_listContext *>(_localctx)->rthirdToken->getLine();
                            antlrcpp::downCast<Declaration_listContext *>(_localctx)->varList =  antlrcpp::downCast<Declaration_listContext *>(_localctx)->dl->varList;
                    		_localctx->varList.push_back(std::make_pair(antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken->getText(), true));
                            
                            writeIntoparserLogFile("Line " + std::to_string(_localctx->line) + ": declaration_list : declaration_list COMMA ID LTHIRD CONST_INT RTHIRD\n\n" +_localctx->text + "\n");        

                        
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<Declaration_listContext>(parentContext, parentState);
          _localctx->dl = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleDeclaration_list);
          setState(210);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(211);
          antlrcpp::downCast<Declaration_listContext *>(_localctx)->commaToken = match(C2105168Parser::COMMA);
          setState(212);
          antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken = match(C2105168Parser::ID);
          setState(213);
          antlrcpp::downCast<Declaration_listContext *>(_localctx)->addopToken = match(C2105168Parser::ADDOP);

                            antlrcpp::downCast<Declaration_listContext *>(_localctx)->text =  antlrcpp::downCast<Declaration_listContext *>(_localctx)->dl->text + antlrcpp::downCast<Declaration_listContext *>(_localctx)->commaToken->getText() + antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken->getText();
                            antlrcpp::downCast<Declaration_listContext *>(_localctx)->line =  antlrcpp::downCast<Declaration_listContext *>(_localctx)->addopToken->getLine();
                            antlrcpp::downCast<Declaration_listContext *>(_localctx)->varList =  antlrcpp::downCast<Declaration_listContext *>(_localctx)->dl->varList;
                            _localctx->varList.push_back(std::make_pair(antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken->getText(), false));
                                    std::cout<<"help"<<std::endl;

                            writeIntoparserLogFile("Line " + std::to_string(_localctx->line) + ": declaration_list : declaration_list COMMA ID\n\n" +antlrcpp::downCast<Declaration_listContext *>(_localctx)->dl->text + "\n");        

                            writeIntoErrorFile("Error at line " + std::to_string(_localctx->line) + ": syntax error, unexpected ADDOP, expecting COMMA or SEMICOLON\n");
                            writeIntoparserLogFile("Error at line " + std::to_string(_localctx->line) + ": syntax error, unexpected ADDOP, expecting COMMA or SEMICOLON\n");
                            
          break;
        }

        default:
          break;
        } 
      }
      setState(219);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- StatementsContext ------------------------------------------------------------------

C2105168Parser::StatementsContext::StatementsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C2105168Parser::StatementContext* C2105168Parser::StatementsContext::statement() {
  return getRuleContext<C2105168Parser::StatementContext>(0);
}

C2105168Parser::StatementsContext* C2105168Parser::StatementsContext::statements() {
  return getRuleContext<C2105168Parser::StatementsContext>(0);
}


size_t C2105168Parser::StatementsContext::getRuleIndex() const {
  return C2105168Parser::RuleStatements;
}

void C2105168Parser::StatementsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105168ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatements(this);
}

void C2105168Parser::StatementsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105168ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatements(this);
}


C2105168Parser::StatementsContext* C2105168Parser::statements() {
   return statements(0);
}

C2105168Parser::StatementsContext* C2105168Parser::statements(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  C2105168Parser::StatementsContext *_localctx = _tracker.createInstance<StatementsContext>(_ctx, parentState);
  C2105168Parser::StatementsContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 22;
  enterRecursionRule(_localctx, 22, C2105168Parser::RuleStatements, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(221);
    antlrcpp::downCast<StatementsContext *>(_localctx)->s = statement();

            antlrcpp::downCast<StatementsContext *>(_localctx)->text =  antlrcpp::downCast<StatementsContext *>(_localctx)->s->text;
            antlrcpp::downCast<StatementsContext *>(_localctx)->line =  antlrcpp::downCast<StatementsContext *>(_localctx)->s->line;
            antlrcpp::downCast<StatementsContext *>(_localctx)->type =  antlrcpp::downCast<StatementsContext *>(_localctx)->s->type;
            antlrcpp::downCast<StatementsContext *>(_localctx)->code_section =  antlrcpp::downCast<StatementsContext *>(_localctx)->s->code_section;
                    // std::cout << "s  type"<<antlrcpp::downCast<StatementsContext *>(_localctx)->s->type <<std::endl;

            writeIntoparserLogFile("Line " + std::to_string(_localctx->line) + ": statements : statement\n\n" + _localctx->text+"\n"); 
        
    _ctx->stop = _input->LT(-1);
    setState(230);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<StatementsContext>(parentContext, parentState);
        _localctx->ss = previousContext;
        pushNewRecursionContext(_localctx, startState, RuleStatements);
        setState(224);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(225);
        antlrcpp::downCast<StatementsContext *>(_localctx)->s = statement();

                          antlrcpp::downCast<StatementsContext *>(_localctx)->text =  antlrcpp::downCast<StatementsContext *>(_localctx)->ss->text +"\n" + antlrcpp::downCast<StatementsContext *>(_localctx)->s->text;
                          antlrcpp::downCast<StatementsContext *>(_localctx)->line =  antlrcpp::downCast<StatementsContext *>(_localctx)->s->line;
                          antlrcpp::downCast<StatementsContext *>(_localctx)->type =  antlrcpp::downCast<StatementsContext *>(_localctx)->s->type;
                          antlrcpp::downCast<StatementsContext *>(_localctx)->code_section =  antlrcpp::downCast<StatementsContext *>(_localctx)->ss->code_section +  antlrcpp::downCast<StatementsContext *>(_localctx)->s->code_section;  
                                  // std::cout << "s  type"<<antlrcpp::downCast<StatementsContext *>(_localctx)->s->type <<std::endl;

                          writeIntoparserLogFile("Line " + std::to_string(_localctx->line) + ": statements : statements statement\n\n" +_localctx->text+"\n"); 

                       
      }
      setState(232);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

C2105168Parser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C2105168Parser::Var_declarationContext* C2105168Parser::StatementContext::var_declaration() {
  return getRuleContext<C2105168Parser::Var_declarationContext>(0);
}

std::vector<C2105168Parser::Expression_statementContext *> C2105168Parser::StatementContext::expression_statement() {
  return getRuleContexts<C2105168Parser::Expression_statementContext>();
}

C2105168Parser::Expression_statementContext* C2105168Parser::StatementContext::expression_statement(size_t i) {
  return getRuleContext<C2105168Parser::Expression_statementContext>(i);
}

C2105168Parser::Compound_statementContext* C2105168Parser::StatementContext::compound_statement() {
  return getRuleContext<C2105168Parser::Compound_statementContext>(0);
}

tree::TerminalNode* C2105168Parser::StatementContext::FOR() {
  return getToken(C2105168Parser::FOR, 0);
}

tree::TerminalNode* C2105168Parser::StatementContext::LPAREN() {
  return getToken(C2105168Parser::LPAREN, 0);
}

tree::TerminalNode* C2105168Parser::StatementContext::RPAREN() {
  return getToken(C2105168Parser::RPAREN, 0);
}

C2105168Parser::ExpressionContext* C2105168Parser::StatementContext::expression() {
  return getRuleContext<C2105168Parser::ExpressionContext>(0);
}

std::vector<C2105168Parser::StatementContext *> C2105168Parser::StatementContext::statement() {
  return getRuleContexts<C2105168Parser::StatementContext>();
}

C2105168Parser::StatementContext* C2105168Parser::StatementContext::statement(size_t i) {
  return getRuleContext<C2105168Parser::StatementContext>(i);
}

tree::TerminalNode* C2105168Parser::StatementContext::IF() {
  return getToken(C2105168Parser::IF, 0);
}

tree::TerminalNode* C2105168Parser::StatementContext::ELSE() {
  return getToken(C2105168Parser::ELSE, 0);
}

tree::TerminalNode* C2105168Parser::StatementContext::WHILE() {
  return getToken(C2105168Parser::WHILE, 0);
}

tree::TerminalNode* C2105168Parser::StatementContext::PRINTLN() {
  return getToken(C2105168Parser::PRINTLN, 0);
}

tree::TerminalNode* C2105168Parser::StatementContext::ID() {
  return getToken(C2105168Parser::ID, 0);
}

tree::TerminalNode* C2105168Parser::StatementContext::SEMICOLON() {
  return getToken(C2105168Parser::SEMICOLON, 0);
}

tree::TerminalNode* C2105168Parser::StatementContext::RETURN() {
  return getToken(C2105168Parser::RETURN, 0);
}


size_t C2105168Parser::StatementContext::getRuleIndex() const {
  return C2105168Parser::RuleStatement;
}

void C2105168Parser::StatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105168ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatement(this);
}

void C2105168Parser::StatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105168ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatement(this);
}

C2105168Parser::StatementContext* C2105168Parser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 24, C2105168Parser::RuleStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(285);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(233);
      antlrcpp::downCast<StatementContext *>(_localctx)->v = var_declaration();

              antlrcpp::downCast<StatementContext *>(_localctx)->text =  antlrcpp::downCast<StatementContext *>(_localctx)->v->text;
              antlrcpp::downCast<StatementContext *>(_localctx)->line =  antlrcpp::downCast<StatementContext *>(_localctx)->v->line;
              antlrcpp::downCast<StatementContext *>(_localctx)->code_section =  antlrcpp::downCast<StatementContext *>(_localctx)->v->code_section;
              std::cout << "DEBUG: unit var_declaration code_section = '" << _localctx->code_section << "'" << std::endl;
              antlrcpp::downCast<StatementContext *>(_localctx)->type =  "void";
              writeIntoparserLogFile("Line "+  std::to_string(_localctx->line) +": statement : var_declaration\n\n"+_localctx->text + "\n" );
          
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(236);
      antlrcpp::downCast<StatementContext *>(_localctx)->es = expression_statement();

              antlrcpp::downCast<StatementContext *>(_localctx)->text =  antlrcpp::downCast<StatementContext *>(_localctx)->es->text;
              antlrcpp::downCast<StatementContext *>(_localctx)->line =  antlrcpp::downCast<StatementContext *>(_localctx)->es->line;
              antlrcpp::downCast<StatementContext *>(_localctx)->type =  "void";
              antlrcpp::downCast<StatementContext *>(_localctx)->code_section =  antlrcpp::downCast<StatementContext *>(_localctx)->es->code_section;
              writeIntoparserLogFile("Line "+  std::to_string(_localctx->line) +": statement : expression_statement\n\n"+_localctx->text + "\n" );

          
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(239);
      antlrcpp::downCast<StatementContext *>(_localctx)->cs = compound_statement();

              antlrcpp::downCast<StatementContext *>(_localctx)->text =  antlrcpp::downCast<StatementContext *>(_localctx)->cs->text;
              antlrcpp::downCast<StatementContext *>(_localctx)->line =  antlrcpp::downCast<StatementContext *>(_localctx)->cs->line;
              antlrcpp::downCast<StatementContext *>(_localctx)->type =  antlrcpp::downCast<StatementContext *>(_localctx)->cs->type;
              antlrcpp::downCast<StatementContext *>(_localctx)->code_section =  antlrcpp::downCast<StatementContext *>(_localctx)->cs->code_section;
              antlrcpp::downCast<StatementContext *>(_localctx)->type =  "void";

              writeIntoparserLogFile("Line "+  std::to_string(_localctx->line) +": statement : compound_statement\n\n"+_localctx->text + "\n" );

          
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(242);
      antlrcpp::downCast<StatementContext *>(_localctx)->forToken = match(C2105168Parser::FOR);
      setState(243);
      antlrcpp::downCast<StatementContext *>(_localctx)->lparenToken = match(C2105168Parser::LPAREN);
      setState(244);
      antlrcpp::downCast<StatementContext *>(_localctx)->es1 = expression_statement();
      setState(245);
      antlrcpp::downCast<StatementContext *>(_localctx)->es2 = expression_statement();
      setState(246);
      antlrcpp::downCast<StatementContext *>(_localctx)->e = expression();
      setState(247);
      antlrcpp::downCast<StatementContext *>(_localctx)->rparenToken = match(C2105168Parser::RPAREN);
      setState(248);
      antlrcpp::downCast<StatementContext *>(_localctx)->s = statement();

              antlrcpp::downCast<StatementContext *>(_localctx)->text =  (antlrcpp::downCast<StatementContext *>(_localctx)->forToken != nullptr ? antlrcpp::downCast<StatementContext *>(_localctx)->forToken->getText() : "") +  antlrcpp::downCast<StatementContext *>(_localctx)->lparenToken->getText() +  antlrcpp::downCast<StatementContext *>(_localctx)->es1->text + antlrcpp::downCast<StatementContext *>(_localctx)->es2->text + antlrcpp::downCast<StatementContext *>(_localctx)->e->text   + antlrcpp::downCast<StatementContext *>(_localctx)->rparenToken->getText() + antlrcpp::downCast<StatementContext *>(_localctx)->s->text;
              antlrcpp::downCast<StatementContext *>(_localctx)->line =  antlrcpp::downCast<StatementContext *>(_localctx)->s->line;
              antlrcpp::downCast<StatementContext *>(_localctx)->type =  "void";
              antlrcpp::downCast<StatementContext *>(_localctx)->code_section =  antlrcpp::downCast<StatementContext *>(_localctx)->s->code_section;

              writeIntoparserLogFile("Line " + std::to_string(antlrcpp::downCast<StatementContext *>(_localctx)->s->line) + ": statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement\n\n" + _localctx->text +"\n"); 

          
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(251);
      antlrcpp::downCast<StatementContext *>(_localctx)->ifToken = match(C2105168Parser::IF);
      setState(252);
      antlrcpp::downCast<StatementContext *>(_localctx)->lparenToken = match(C2105168Parser::LPAREN);
      setState(253);
      antlrcpp::downCast<StatementContext *>(_localctx)->e = expression();
      setState(254);
      antlrcpp::downCast<StatementContext *>(_localctx)->rparenToken = match(C2105168Parser::RPAREN);
      setState(255);
      antlrcpp::downCast<StatementContext *>(_localctx)->s = statement();


              antlrcpp::downCast<StatementContext *>(_localctx)->text =  antlrcpp::downCast<StatementContext *>(_localctx)->ifToken->getText()+ antlrcpp::downCast<StatementContext *>(_localctx)->lparenToken->getText()+ antlrcpp::downCast<StatementContext *>(_localctx)->e->text  + antlrcpp::downCast<StatementContext *>(_localctx)->rparenToken->getText() +antlrcpp::downCast<StatementContext *>(_localctx)->s->text;
              antlrcpp::downCast<StatementContext *>(_localctx)->line =  antlrcpp::downCast<StatementContext *>(_localctx)->ifToken->getLine();
              antlrcpp::downCast<StatementContext *>(_localctx)->type =  "void";

              writeIntoparserLogFile("Line " + std::to_string(_localctx->line) + ": statement : IF LPAREN expression RPAREN statement\n\n" + _localctx->text +"\n"); 

          
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(258);
      antlrcpp::downCast<StatementContext *>(_localctx)->ifToken = match(C2105168Parser::IF);
      setState(259);
      antlrcpp::downCast<StatementContext *>(_localctx)->lparenToken = match(C2105168Parser::LPAREN);
      setState(260);
      antlrcpp::downCast<StatementContext *>(_localctx)->e = expression();
      setState(261);
      antlrcpp::downCast<StatementContext *>(_localctx)->rparenToken = match(C2105168Parser::RPAREN);
      setState(262);
      antlrcpp::downCast<StatementContext *>(_localctx)->s1 = statement();
      setState(263);
      antlrcpp::downCast<StatementContext *>(_localctx)->elseToken = match(C2105168Parser::ELSE);
      setState(264);
      antlrcpp::downCast<StatementContext *>(_localctx)->s2 = statement();

              antlrcpp::downCast<StatementContext *>(_localctx)->text =  antlrcpp::downCast<StatementContext *>(_localctx)->ifToken->getText() + antlrcpp::downCast<StatementContext *>(_localctx)->lparenToken->getText() + antlrcpp::downCast<StatementContext *>(_localctx)->e->text  + antlrcpp::downCast<StatementContext *>(_localctx)->rparenToken->getText() + antlrcpp::downCast<StatementContext *>(_localctx)->s1->text+ antlrcpp::downCast<StatementContext *>(_localctx)->elseToken->getText() +" "+  antlrcpp::downCast<StatementContext *>(_localctx)->s2->text ;
             antlrcpp::downCast<StatementContext *>(_localctx)->line =  antlrcpp::downCast<StatementContext *>(_localctx)->ifToken->getLine();
              antlrcpp::downCast<StatementContext *>(_localctx)->type =  "void";

              writeIntoparserLogFile("Line " + std::to_string(_localctx->line) + ": statement : IF LPAREN expression RPAREN statement ELSE statement\n\n" + _localctx->text +"\n"); 

          
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(267);
      antlrcpp::downCast<StatementContext *>(_localctx)->whileToken = match(C2105168Parser::WHILE);
      setState(268);
      antlrcpp::downCast<StatementContext *>(_localctx)->lparenToken = match(C2105168Parser::LPAREN);
      setState(269);
      antlrcpp::downCast<StatementContext *>(_localctx)->e = expression();
      setState(270);
      antlrcpp::downCast<StatementContext *>(_localctx)->rparenToken = match(C2105168Parser::RPAREN);
      setState(271);
      antlrcpp::downCast<StatementContext *>(_localctx)->s = statement();

              antlrcpp::downCast<StatementContext *>(_localctx)->text =  antlrcpp::downCast<StatementContext *>(_localctx)->whileToken->getText() + antlrcpp::downCast<StatementContext *>(_localctx)->lparenToken->getText() + antlrcpp::downCast<StatementContext *>(_localctx)->e->text  + antlrcpp::downCast<StatementContext *>(_localctx)->rparenToken->getText() + antlrcpp::downCast<StatementContext *>(_localctx)->s->text;
              antlrcpp::downCast<StatementContext *>(_localctx)->line =  antlrcpp::downCast<StatementContext *>(_localctx)->s->line;
              antlrcpp::downCast<StatementContext *>(_localctx)->type =  "void";

              writeIntoparserLogFile("Line " + std::to_string(_localctx->line) + ": statement : WHILE LPAREN expression RPAREN statement\n\n" + _localctx->text +"\n"); 

          
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(274);
      antlrcpp::downCast<StatementContext *>(_localctx)->printlnToken = match(C2105168Parser::PRINTLN);
      setState(275);
      antlrcpp::downCast<StatementContext *>(_localctx)->lparenToken = match(C2105168Parser::LPAREN);
      setState(276);
      antlrcpp::downCast<StatementContext *>(_localctx)->idToken = match(C2105168Parser::ID);
      setState(277);
      antlrcpp::downCast<StatementContext *>(_localctx)->rparenToken = match(C2105168Parser::RPAREN);
      setState(278);
      antlrcpp::downCast<StatementContext *>(_localctx)->semicolonToken = match(C2105168Parser::SEMICOLON);

              antlrcpp::downCast<StatementContext *>(_localctx)->text =  antlrcpp::downCast<StatementContext *>(_localctx)->printlnToken->getText() + antlrcpp::downCast<StatementContext *>(_localctx)->lparenToken->getText() +  antlrcpp::downCast<StatementContext *>(_localctx)->idToken->getText() +  antlrcpp::downCast<StatementContext *>(_localctx)->rparenToken->getText() +  antlrcpp::downCast<StatementContext *>(_localctx)->semicolonToken->getText();
              antlrcpp::downCast<StatementContext *>(_localctx)->line =  antlrcpp::downCast<StatementContext *>(_localctx)->semicolonToken->getLine();

              antlrcpp::downCast<StatementContext *>(_localctx)->type =  "void";

              SymbolInfo* lookup = symbolTable->LookUP(antlrcpp::downCast<StatementContext *>(_localctx)->idToken->getText());



              writeIntoparserLogFile("Line " + std::to_string(_localctx->line) + ": statement : PRINTLN LPAREN ID RPAREN SEMICOLON\n"); 
              if(lookup == nullptr){
                      writeIntoErrorFile("Error at line " + std::to_string(_localctx->line) + ": Undeclared variable " +antlrcpp::downCast<StatementContext *>(_localctx)->idToken->getText() + "\n");  
                      writeIntoparserLogFile("Error at line " + std::to_string(_localctx->line) + ": Undeclared variable " + antlrcpp::downCast<StatementContext *>(_localctx)->idToken->getText() + "\n\n" +_localctx->text+"\n");
                                      errorCount++;
              }

          
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(280);
      antlrcpp::downCast<StatementContext *>(_localctx)->returnToken = match(C2105168Parser::RETURN);
      setState(281);
      antlrcpp::downCast<StatementContext *>(_localctx)->e = expression();
      setState(282);
      antlrcpp::downCast<StatementContext *>(_localctx)->semicolonToken = match(C2105168Parser::SEMICOLON);

              antlrcpp::downCast<StatementContext *>(_localctx)->text =  antlrcpp::downCast<StatementContext *>(_localctx)->returnToken->getText() + " " + antlrcpp::downCast<StatementContext *>(_localctx)->e->text + antlrcpp::downCast<StatementContext *>(_localctx)->semicolonToken->getText();
              antlrcpp::downCast<StatementContext *>(_localctx)->line =  antlrcpp::downCast<StatementContext *>(_localctx)->returnToken->getLine();
              
              antlrcpp::downCast<StatementContext *>(_localctx)->type =  antlrcpp::downCast<StatementContext *>(_localctx)->e->type;


             // std::cout << std::to_string(_localctx->line)<<"return type"<<antlrcpp::downCast<StatementContext *>(_localctx)->e->type<<"return " <<antlrcpp::downCast<StatementContext *>(_localctx)->e->text <<std::endl;

              SymbolInfo* lookup = symbolTable->LookUP(antlrcpp::downCast<StatementContext *>(_localctx)->e->text);

              if(lookup){
                 // std::cout << lookup->getSymbolName() << " has return type " << lookup->getReturnType() <<"and e.type "<< antlrcpp::downCast<StatementContext *>(_localctx)->e->type << std::endl;
              }
              // SymbolInfo* paramSymbol = new SymbolInfo(antlrcpp::downCast<StatementContext *>(_localctx)->e->text, "ID");
              // if(antlrcpp::downCast<StatementContext *>(_localctx)->e->text != "0"){
              // if(!symbolTable->Insert(antlrcpp::downCast<StatementContext *>(_localctx)->e->text, "ID")){ 
              //     writeIntoErrorFile("Error at line "+ std::to_string(_localctx->line) +": Multiple declaration of "+antlrcpp::downCast<StatementContext *>(_localctx)->e->text+" in parameter\n");
              // }    
              // else{   
              //     std::cout << "inserted return : "<< antlrcpp::downCast<StatementContext *>(_localctx)->e->text <<std::endl;
              // }
              // }
              writeIntoparserLogFile("Line " + std::to_string(antlrcpp::downCast<StatementContext *>(_localctx)->semicolonToken->getLine()) + ": statement : RETURN expression SEMICOLON\n\n" + antlrcpp::downCast<StatementContext *>(_localctx)->returnToken->getText() +" "+ antlrcpp::downCast<StatementContext *>(_localctx)->e->text+ antlrcpp::downCast<StatementContext *>(_localctx)->semicolonToken->getText() +"\n"); 

            
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Expression_statementContext ------------------------------------------------------------------

C2105168Parser::Expression_statementContext::Expression_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* C2105168Parser::Expression_statementContext::SEMICOLON() {
  return getToken(C2105168Parser::SEMICOLON, 0);
}

C2105168Parser::ExpressionContext* C2105168Parser::Expression_statementContext::expression() {
  return getRuleContext<C2105168Parser::ExpressionContext>(0);
}


size_t C2105168Parser::Expression_statementContext::getRuleIndex() const {
  return C2105168Parser::RuleExpression_statement;
}

void C2105168Parser::Expression_statementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105168ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpression_statement(this);
}

void C2105168Parser::Expression_statementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105168ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpression_statement(this);
}

C2105168Parser::Expression_statementContext* C2105168Parser::expression_statement() {
  Expression_statementContext *_localctx = _tracker.createInstance<Expression_statementContext>(_ctx, getState());
  enterRule(_localctx, 26, C2105168Parser::RuleExpression_statement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(293);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case C2105168Parser::SEMICOLON: {
        enterOuterAlt(_localctx, 1);
        setState(287);
        antlrcpp::downCast<Expression_statementContext *>(_localctx)->semicolonToken = match(C2105168Parser::SEMICOLON);

                antlrcpp::downCast<Expression_statementContext *>(_localctx)->text =  antlrcpp::downCast<Expression_statementContext *>(_localctx)->semicolonToken->getText();
                antlrcpp::downCast<Expression_statementContext *>(_localctx)->line =  antlrcpp::downCast<Expression_statementContext *>(_localctx)->semicolonToken->getLine();
                antlrcpp::downCast<Expression_statementContext *>(_localctx)->code_section =  "";
                writeIntoparserLogFile("Line " + std::to_string(antlrcpp::downCast<Expression_statementContext *>(_localctx)->semicolonToken->getLine()) + ": expression_statement : SEMICOLON\n\n" + _localctx->text +"\n"); 

            
        break;
      }

      case C2105168Parser::LPAREN:
      case C2105168Parser::ADDOP:
      case C2105168Parser::NOT:
      case C2105168Parser::ID:
      case C2105168Parser::CONST_INT:
      case C2105168Parser::CONST_FLOAT: {
        enterOuterAlt(_localctx, 2);
        setState(289);
        antlrcpp::downCast<Expression_statementContext *>(_localctx)->e = expression();
        setState(290);
        antlrcpp::downCast<Expression_statementContext *>(_localctx)->semicolonToken = match(C2105168Parser::SEMICOLON);

                antlrcpp::downCast<Expression_statementContext *>(_localctx)->text =  antlrcpp::downCast<Expression_statementContext *>(_localctx)->e->text + antlrcpp::downCast<Expression_statementContext *>(_localctx)->semicolonToken->getText();
                antlrcpp::downCast<Expression_statementContext *>(_localctx)->line =  antlrcpp::downCast<Expression_statementContext *>(_localctx)->semicolonToken->getLine();
                antlrcpp::downCast<Expression_statementContext *>(_localctx)->code_section =  antlrcpp::downCast<Expression_statementContext *>(_localctx)->e->code_section;
                writeIntoparserLogFile("Line " + std::to_string(antlrcpp::downCast<Expression_statementContext *>(_localctx)->semicolonToken->getLine()) + ": expression_statement : expression SEMICOLON\n\n" + _localctx->text +"\n"); 

            
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VariableContext ------------------------------------------------------------------

C2105168Parser::VariableContext::VariableContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* C2105168Parser::VariableContext::ID() {
  return getToken(C2105168Parser::ID, 0);
}

tree::TerminalNode* C2105168Parser::VariableContext::LTHIRD() {
  return getToken(C2105168Parser::LTHIRD, 0);
}

tree::TerminalNode* C2105168Parser::VariableContext::RTHIRD() {
  return getToken(C2105168Parser::RTHIRD, 0);
}

C2105168Parser::ExpressionContext* C2105168Parser::VariableContext::expression() {
  return getRuleContext<C2105168Parser::ExpressionContext>(0);
}


size_t C2105168Parser::VariableContext::getRuleIndex() const {
  return C2105168Parser::RuleVariable;
}

void C2105168Parser::VariableContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105168ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVariable(this);
}

void C2105168Parser::VariableContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105168ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVariable(this);
}

C2105168Parser::VariableContext* C2105168Parser::variable() {
  VariableContext *_localctx = _tracker.createInstance<VariableContext>(_ctx, getState());
  enterRule(_localctx, 28, C2105168Parser::RuleVariable);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(303);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(295);
      antlrcpp::downCast<VariableContext *>(_localctx)->idToken = match(C2105168Parser::ID);

              antlrcpp::downCast<VariableContext *>(_localctx)->text =  antlrcpp::downCast<VariableContext *>(_localctx)->idToken->getText();
              antlrcpp::downCast<VariableContext *>(_localctx)->line =  antlrcpp::downCast<VariableContext *>(_localctx)->idToken->getLine();
              antlrcpp::downCast<VariableContext *>(_localctx)->type =  "int";
              SymbolInfo* lookup = symbolTable->LookUP(antlrcpp::downCast<VariableContext *>(_localctx)->idToken->getText());

                  if(lookup && lookup->getIsArray()){
                      antlrcpp::downCast<VariableContext *>(_localctx)->type =  "array";
                      antlrcpp::downCast<VariableContext *>(_localctx)->isArray =  true;
                  }
                  else if (lookup){
                      antlrcpp::downCast<VariableContext *>(_localctx)->type =  lookup->getSymbolDataType();

                  }
                  if (lookup == nullptr) {
                              writeIntoparserLogFile("Line " + std::to_string(antlrcpp::downCast<VariableContext *>(_localctx)->idToken->getLine()) + ": variable : ID\n"); 

                      writeIntoErrorFile("Error at line " + std::to_string(_localctx->line) + ": Undeclared variable " +antlrcpp::downCast<VariableContext *>(_localctx)->idToken->getText() + "\n");  
                      writeIntoparserLogFile("Error at line " + std::to_string(_localctx->line) + ": Undeclared variable " + antlrcpp::downCast<VariableContext *>(_localctx)->idToken->getText() + "\n\n" +antlrcpp::downCast<VariableContext *>(_localctx)->idToken->getText()+"\n");
                                      errorCount++;

                  }

                  else{  
                  writeIntoparserLogFile("Line " + std::to_string(antlrcpp::downCast<VariableContext *>(_localctx)->idToken->getLine()) + ": variable : ID\n\n"+antlrcpp::downCast<VariableContext *>(_localctx)->idToken->getText()+"\n"); 

                  }
                      // std::cout << "ID type: " << _localctx->type <<"for "<< antlrcpp::downCast<VariableContext *>(_localctx)->idToken->getText() << std::endl;
                      // if (lookup)
                      // std::cout << "DEBUG: " << lookup->getSymbolName() << " has type: " << lookup->getType() << std::endl;
                      //                 std::cout << "DEBUG: " << lookup->getSymbolName() << " has type: " << lookup->getSymbolDataType() << std::endl;


              
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(297);
      antlrcpp::downCast<VariableContext *>(_localctx)->idToken = match(C2105168Parser::ID);
      setState(298);
      antlrcpp::downCast<VariableContext *>(_localctx)->lthirdToken = match(C2105168Parser::LTHIRD);
      setState(299);
      antlrcpp::downCast<VariableContext *>(_localctx)->e = expression();
      setState(300);
      antlrcpp::downCast<VariableContext *>(_localctx)->rthirdToken = match(C2105168Parser::RTHIRD);
       
              antlrcpp::downCast<VariableContext *>(_localctx)->text =  antlrcpp::downCast<VariableContext *>(_localctx)->idToken->getText() + antlrcpp::downCast<VariableContext *>(_localctx)->lthirdToken->getText() + antlrcpp::downCast<VariableContext *>(_localctx)->e->text + antlrcpp::downCast<VariableContext *>(_localctx)->rthirdToken->getText();
              antlrcpp::downCast<VariableContext *>(_localctx)->line =  antlrcpp::downCast<VariableContext *>(_localctx)->rthirdToken->getLine();
              antlrcpp::downCast<VariableContext *>(_localctx)->type =  antlrcpp::downCast<VariableContext *>(_localctx)->e->type;
              if (_localctx->type != "int"){  
                  writeIntoErrorFile("Error at line "+std::to_string(_localctx->line)+": Expression inside third brackets not an integer\n");

                  writeIntoparserLogFile("Line " + std::to_string(_localctx->line) + ": variable : ID LTHIRD expression RTHIRD" +"\n"); 

                  writeIntoparserLogFile("Error at line "+std::to_string(_localctx->line)+": Expression inside third brackets not an integer\n\n"+_localctx->text +"\n");
                                  errorCount++;



              }
              else{
              writeIntoparserLogFile("Line " + std::to_string(_localctx->line) + ": variable : ID LTHIRD expression RTHIRD\n\n"+_localctx->text+"\n"); 

              }

          
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

C2105168Parser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C2105168Parser::Logic_expressionContext* C2105168Parser::ExpressionContext::logic_expression() {
  return getRuleContext<C2105168Parser::Logic_expressionContext>(0);
}

tree::TerminalNode* C2105168Parser::ExpressionContext::ASSIGNOP() {
  return getToken(C2105168Parser::ASSIGNOP, 0);
}

C2105168Parser::VariableContext* C2105168Parser::ExpressionContext::variable() {
  return getRuleContext<C2105168Parser::VariableContext>(0);
}


size_t C2105168Parser::ExpressionContext::getRuleIndex() const {
  return C2105168Parser::RuleExpression;
}

void C2105168Parser::ExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105168ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpression(this);
}

void C2105168Parser::ExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105168ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpression(this);
}

C2105168Parser::ExpressionContext* C2105168Parser::expression() {
  ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, getState());
  enterRule(_localctx, 30, C2105168Parser::RuleExpression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(313);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(305);
      antlrcpp::downCast<ExpressionContext *>(_localctx)->l = logic_expression();

                  antlrcpp::downCast<ExpressionContext *>(_localctx)->text = antlrcpp::downCast<ExpressionContext *>(_localctx)->l->text;
                  antlrcpp::downCast<ExpressionContext *>(_localctx)->line = antlrcpp::downCast<ExpressionContext *>(_localctx)->l->line;
                  antlrcpp::downCast<ExpressionContext *>(_localctx)->type =  antlrcpp::downCast<ExpressionContext *>(_localctx)->l->type;
                     antlrcpp::downCast<ExpressionContext *>(_localctx)->argIsArray =  false;
                  antlrcpp::downCast<ExpressionContext *>(_localctx)->code_section =  antlrcpp::downCast<ExpressionContext *>(_localctx)->l->code_section;
                  // std::cout << "l type"<<antlrcpp::downCast<ExpressionContext *>(_localctx)->l->type <<std::endl;

                  writeIntoparserLogFile("Line "+  std::to_string(antlrcpp::downCast<ExpressionContext *>(_localctx)->l->line)+": expression : logic_expression\n\n" + antlrcpp::downCast<ExpressionContext *>(_localctx)->l->text + "\n"); 
              
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(308);
      antlrcpp::downCast<ExpressionContext *>(_localctx)->v = variable();
      setState(309);
      antlrcpp::downCast<ExpressionContext *>(_localctx)->assignopToken = match(C2105168Parser::ASSIGNOP);
      setState(310);
      antlrcpp::downCast<ExpressionContext *>(_localctx)->le = logic_expression();

                  antlrcpp::downCast<ExpressionContext *>(_localctx)->text =  antlrcpp::downCast<ExpressionContext *>(_localctx)->v->text + antlrcpp::downCast<ExpressionContext *>(_localctx)->assignopToken->getText() + antlrcpp::downCast<ExpressionContext *>(_localctx)->le->text;
                  antlrcpp::downCast<ExpressionContext *>(_localctx)->line = antlrcpp::downCast<ExpressionContext *>(_localctx)->le->line;  
                  antlrcpp::downCast<ExpressionContext *>(_localctx)->type =  antlrcpp::downCast<ExpressionContext *>(_localctx)->le->type;
                   antlrcpp::downCast<ExpressionContext *>(_localctx)->argIsArray =  false;

                  antlrcpp::downCast<ExpressionContext *>(_localctx)->code_section =  antlrcpp::downCast<ExpressionContext *>(_localctx)->le->code_section;
                  antlrcpp::downCast<ExpressionContext *>(_localctx)->code_section =  "\tMOV AX, "+ antlrcpp::downCast<ExpressionContext *>(_localctx)->le->text + "       ; Line " + std::to_string(_localctx->line) + "\n";
                  _localctx->code_section += "\tMOV " + antlrcpp::downCast<ExpressionContext *>(_localctx)->v->text + ", AX" +"\n";
                  _localctx->code_section += "\tPUSH AX\n\tPOP AX\n";

                  antlrcpp::downCast<ExpressionContext *>(_localctx)->code_section =  "L" + std::to_string(label_count++) + ":\n" + _localctx->code_section;


                  std::cout << "DEBUG: expression code_section = '" << _localctx->code_section << "'" << std::endl;
                  SymbolInfo* lookup = symbolTable->LookUP(antlrcpp::downCast<ExpressionContext *>(_localctx)->v->text);



                  if (lookup && antlrcpp::downCast<ExpressionContext *>(_localctx)->v->type != _localctx->type) {
                  
                  writeIntoparserLogFile("Line "+  std::to_string(_localctx->line)+": expression : variable ASSIGNOP logic_expression\n"); 

                  if(lookup->getIsArray()){
                      writeIntoErrorFile("Error at line " + std::to_string(_localctx->line) + ": Type mismatch, "+antlrcpp::downCast<ExpressionContext *>(_localctx)->v->text+" is an array\n");
                      writeIntoparserLogFile("Error at line " + std::to_string(_localctx->line) + ": Type Mismatch, "+antlrcpp::downCast<ExpressionContext *>(_localctx)->v->text+"  is an array\n");
                                      errorCount++;


                  } else {

                      writeIntoErrorFile("Error at line " + std::to_string(_localctx->line) + ": Type Mismatch\n");  

                  writeIntoparserLogFile("Error at line " + std::to_string(_localctx->line) + ": Type Mismatch\n\n"+_localctx->text+"\n");
                                  errorCount++;

                   }


                  }

                  else{            
                      writeIntoparserLogFile("Line "+  std::to_string(_localctx->line)+": expression : variable ASSIGNOP logic_expression\n\n"+_localctx->text+"\n"); 
                  }

                  

             
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Logic_expressionContext ------------------------------------------------------------------

C2105168Parser::Logic_expressionContext::Logic_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<C2105168Parser::Rel_expressionContext *> C2105168Parser::Logic_expressionContext::rel_expression() {
  return getRuleContexts<C2105168Parser::Rel_expressionContext>();
}

C2105168Parser::Rel_expressionContext* C2105168Parser::Logic_expressionContext::rel_expression(size_t i) {
  return getRuleContext<C2105168Parser::Rel_expressionContext>(i);
}

tree::TerminalNode* C2105168Parser::Logic_expressionContext::LOGICOP() {
  return getToken(C2105168Parser::LOGICOP, 0);
}


size_t C2105168Parser::Logic_expressionContext::getRuleIndex() const {
  return C2105168Parser::RuleLogic_expression;
}

void C2105168Parser::Logic_expressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105168ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLogic_expression(this);
}

void C2105168Parser::Logic_expressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105168ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLogic_expression(this);
}

C2105168Parser::Logic_expressionContext* C2105168Parser::logic_expression() {
  Logic_expressionContext *_localctx = _tracker.createInstance<Logic_expressionContext>(_ctx, getState());
  enterRule(_localctx, 32, C2105168Parser::RuleLogic_expression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(323);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(315);
      antlrcpp::downCast<Logic_expressionContext *>(_localctx)->r = rel_expression();

                  antlrcpp::downCast<Logic_expressionContext *>(_localctx)->text =  antlrcpp::downCast<Logic_expressionContext *>(_localctx)->r->text;
                  antlrcpp::downCast<Logic_expressionContext *>(_localctx)->line =  antlrcpp::downCast<Logic_expressionContext *>(_localctx)->r->line;
                  antlrcpp::downCast<Logic_expressionContext *>(_localctx)->type =  antlrcpp::downCast<Logic_expressionContext *>(_localctx)->r->type;
                  antlrcpp::downCast<Logic_expressionContext *>(_localctx)->argIsArr =  antlrcpp::downCast<Logic_expressionContext *>(_localctx)->r->argIsArray;
                  antlrcpp::downCast<Logic_expressionContext *>(_localctx)->code_section =  antlrcpp::downCast<Logic_expressionContext *>(_localctx)->r->code_section;
                  // std::cout << "r  type"<<antlrcpp::downCast<Logic_expressionContext *>(_localctx)->r->type <<std::endl;

                  writeIntoparserLogFile("Line "+  std::to_string(antlrcpp::downCast<Logic_expressionContext *>(_localctx)->r->line)+": logic_expression : rel_expression\n\n" + antlrcpp::downCast<Logic_expressionContext *>(_localctx)->r->text + "\n"); 

              
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(318);
      antlrcpp::downCast<Logic_expressionContext *>(_localctx)->re1 = rel_expression();
      setState(319);
      antlrcpp::downCast<Logic_expressionContext *>(_localctx)->logicopToken = match(C2105168Parser::LOGICOP);
      setState(320);
      antlrcpp::downCast<Logic_expressionContext *>(_localctx)->re2 = rel_expression();

                  antlrcpp::downCast<Logic_expressionContext *>(_localctx)->text =  antlrcpp::downCast<Logic_expressionContext *>(_localctx)->re1->text+antlrcpp::downCast<Logic_expressionContext *>(_localctx)->logicopToken->getText() + antlrcpp::downCast<Logic_expressionContext *>(_localctx)->re2->text;
                  antlrcpp::downCast<Logic_expressionContext *>(_localctx)->line =  antlrcpp::downCast<Logic_expressionContext *>(_localctx)->re2->line;
                  antlrcpp::downCast<Logic_expressionContext *>(_localctx)->type =  antlrcpp::downCast<Logic_expressionContext *>(_localctx)->re2->type;
                  antlrcpp::downCast<Logic_expressionContext *>(_localctx)->argIsArr =  false;

                  // std::cout << "re2 type"<<antlrcpp::downCast<Logic_expressionContext *>(_localctx)->re2->type <<std::endl;
                  writeIntoparserLogFile("Line "+  std::to_string(_localctx->line)+": logic_expression : rel_expression LOGICOP rel_expression\n\n" + _localctx->text + "\n"); 

              
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Rel_expressionContext ------------------------------------------------------------------

C2105168Parser::Rel_expressionContext::Rel_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<C2105168Parser::Simple_expressionContext *> C2105168Parser::Rel_expressionContext::simple_expression() {
  return getRuleContexts<C2105168Parser::Simple_expressionContext>();
}

C2105168Parser::Simple_expressionContext* C2105168Parser::Rel_expressionContext::simple_expression(size_t i) {
  return getRuleContext<C2105168Parser::Simple_expressionContext>(i);
}

tree::TerminalNode* C2105168Parser::Rel_expressionContext::RELOP() {
  return getToken(C2105168Parser::RELOP, 0);
}


size_t C2105168Parser::Rel_expressionContext::getRuleIndex() const {
  return C2105168Parser::RuleRel_expression;
}

void C2105168Parser::Rel_expressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105168ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRel_expression(this);
}

void C2105168Parser::Rel_expressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105168ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRel_expression(this);
}

C2105168Parser::Rel_expressionContext* C2105168Parser::rel_expression() {
  Rel_expressionContext *_localctx = _tracker.createInstance<Rel_expressionContext>(_ctx, getState());
  enterRule(_localctx, 34, C2105168Parser::RuleRel_expression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(333);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(325);
      antlrcpp::downCast<Rel_expressionContext *>(_localctx)->s = simple_expression(0);

                  antlrcpp::downCast<Rel_expressionContext *>(_localctx)->text =  antlrcpp::downCast<Rel_expressionContext *>(_localctx)->s->text;
                  antlrcpp::downCast<Rel_expressionContext *>(_localctx)->line =  antlrcpp::downCast<Rel_expressionContext *>(_localctx)->s->line;
                  antlrcpp::downCast<Rel_expressionContext *>(_localctx)->type =  antlrcpp::downCast<Rel_expressionContext *>(_localctx)->s->type;
                  antlrcpp::downCast<Rel_expressionContext *>(_localctx)->argIsArray =  antlrcpp::downCast<Rel_expressionContext *>(_localctx)->s->argIsArray;
                  antlrcpp::downCast<Rel_expressionContext *>(_localctx)->code_section =  antlrcpp::downCast<Rel_expressionContext *>(_localctx)->s->code_section;
                  // std::cout << "s type"<<antlrcpp::downCast<Rel_expressionContext *>(_localctx)->s->type <<std::endl;
                  writeIntoparserLogFile("Line "+  std::to_string(antlrcpp::downCast<Rel_expressionContext *>(_localctx)->s->line)+": rel_expression : simple_expression\n\n" + antlrcpp::downCast<Rel_expressionContext *>(_localctx)->s->text + "\n"); 
                  
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(328);
      antlrcpp::downCast<Rel_expressionContext *>(_localctx)->s1 = simple_expression(0);
      setState(329);
      antlrcpp::downCast<Rel_expressionContext *>(_localctx)->relopToken = match(C2105168Parser::RELOP);
      setState(330);
      antlrcpp::downCast<Rel_expressionContext *>(_localctx)->s2 = simple_expression(0);

                  antlrcpp::downCast<Rel_expressionContext *>(_localctx)->text =  antlrcpp::downCast<Rel_expressionContext *>(_localctx)->s1->text + antlrcpp::downCast<Rel_expressionContext *>(_localctx)->relopToken->getText() + antlrcpp::downCast<Rel_expressionContext *>(_localctx)->s2->text;
                  antlrcpp::downCast<Rel_expressionContext *>(_localctx)->line =  antlrcpp::downCast<Rel_expressionContext *>(_localctx)->relopToken->getLine();
                  antlrcpp::downCast<Rel_expressionContext *>(_localctx)->type =  antlrcpp::downCast<Rel_expressionContext *>(_localctx)->s2->type;
                  antlrcpp::downCast<Rel_expressionContext *>(_localctx)->argIsArray =  false;
                  // std::cout << "s2 type"<<antlrcpp::downCast<Rel_expressionContext *>(_localctx)->s2->type <<std::endl;
                  writeIntoparserLogFile("Line "+  std::to_string(_localctx->line)+": rel_expression : simple_expression RELOP simple_expression\n\n" + _localctx->text + "\n"); 

              
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Simple_expressionContext ------------------------------------------------------------------

C2105168Parser::Simple_expressionContext::Simple_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C2105168Parser::TermContext* C2105168Parser::Simple_expressionContext::term() {
  return getRuleContext<C2105168Parser::TermContext>(0);
}

tree::TerminalNode* C2105168Parser::Simple_expressionContext::ADDOP() {
  return getToken(C2105168Parser::ADDOP, 0);
}

C2105168Parser::Simple_expressionContext* C2105168Parser::Simple_expressionContext::simple_expression() {
  return getRuleContext<C2105168Parser::Simple_expressionContext>(0);
}


size_t C2105168Parser::Simple_expressionContext::getRuleIndex() const {
  return C2105168Parser::RuleSimple_expression;
}

void C2105168Parser::Simple_expressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105168ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSimple_expression(this);
}

void C2105168Parser::Simple_expressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105168ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSimple_expression(this);
}


C2105168Parser::Simple_expressionContext* C2105168Parser::simple_expression() {
   return simple_expression(0);
}

C2105168Parser::Simple_expressionContext* C2105168Parser::simple_expression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  C2105168Parser::Simple_expressionContext *_localctx = _tracker.createInstance<Simple_expressionContext>(_ctx, parentState);
  C2105168Parser::Simple_expressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 36;
  enterRecursionRule(_localctx, 36, C2105168Parser::RuleSimple_expression, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(336);
    antlrcpp::downCast<Simple_expressionContext *>(_localctx)->t = term(0);

                antlrcpp::downCast<Simple_expressionContext *>(_localctx)->text =  antlrcpp::downCast<Simple_expressionContext *>(_localctx)->t->text;
                antlrcpp::downCast<Simple_expressionContext *>(_localctx)->line =  antlrcpp::downCast<Simple_expressionContext *>(_localctx)->t->line;
                antlrcpp::downCast<Simple_expressionContext *>(_localctx)->type =  antlrcpp::downCast<Simple_expressionContext *>(_localctx)->t->type;
                antlrcpp::downCast<Simple_expressionContext *>(_localctx)->argIsArray =  antlrcpp::downCast<Simple_expressionContext *>(_localctx)->t->argIsArray;
                antlrcpp::downCast<Simple_expressionContext *>(_localctx)->code_section =  antlrcpp::downCast<Simple_expressionContext *>(_localctx)->t->code_section;
                writeIntoparserLogFile("Line "+  std::to_string(antlrcpp::downCast<Simple_expressionContext *>(_localctx)->t->line)+": simple_expression : term\n\n" + antlrcpp::downCast<Simple_expressionContext *>(_localctx)->t->text + "\n"); 
                
    _ctx->stop = _input->LT(-1);
    setState(346);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<Simple_expressionContext>(parentContext, parentState);
        _localctx->s = previousContext;
        pushNewRecursionContext(_localctx, startState, RuleSimple_expression);
        setState(339);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(340);
        antlrcpp::downCast<Simple_expressionContext *>(_localctx)->addopToken = match(C2105168Parser::ADDOP);
        setState(341);
        antlrcpp::downCast<Simple_expressionContext *>(_localctx)->t = term(0);

                              antlrcpp::downCast<Simple_expressionContext *>(_localctx)->text =  antlrcpp::downCast<Simple_expressionContext *>(_localctx)->s->text+antlrcpp::downCast<Simple_expressionContext *>(_localctx)->addopToken->getText()+antlrcpp::downCast<Simple_expressionContext *>(_localctx)->t->text;
                              antlrcpp::downCast<Simple_expressionContext *>(_localctx)->line =  antlrcpp::downCast<Simple_expressionContext *>(_localctx)->t->line;
                              antlrcpp::downCast<Simple_expressionContext *>(_localctx)->argIsArray =  false;
                              if (antlrcpp::downCast<Simple_expressionContext *>(_localctx)->s->type == "float" || antlrcpp::downCast<Simple_expressionContext *>(_localctx)->t->type == "float") {
                                  antlrcpp::downCast<Simple_expressionContext *>(_localctx)->type =  "float";
                              } else {
                                   antlrcpp::downCast<Simple_expressionContext *>(_localctx)->type =  "int";
                              }
                              writeIntoparserLogFile("Line "+  std::to_string(_localctx->line)+": simple_expression : simple_expression ADDOP term\n\n" + _localctx->text + "\n"); 

                             
      }
      setState(348);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- TermContext ------------------------------------------------------------------

C2105168Parser::TermContext::TermContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C2105168Parser::Unary_expressionContext* C2105168Parser::TermContext::unary_expression() {
  return getRuleContext<C2105168Parser::Unary_expressionContext>(0);
}

tree::TerminalNode* C2105168Parser::TermContext::MULOP() {
  return getToken(C2105168Parser::MULOP, 0);
}

C2105168Parser::TermContext* C2105168Parser::TermContext::term() {
  return getRuleContext<C2105168Parser::TermContext>(0);
}


size_t C2105168Parser::TermContext::getRuleIndex() const {
  return C2105168Parser::RuleTerm;
}

void C2105168Parser::TermContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105168ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTerm(this);
}

void C2105168Parser::TermContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105168ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTerm(this);
}


C2105168Parser::TermContext* C2105168Parser::term() {
   return term(0);
}

C2105168Parser::TermContext* C2105168Parser::term(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  C2105168Parser::TermContext *_localctx = _tracker.createInstance<TermContext>(_ctx, parentState);
  C2105168Parser::TermContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 38;
  enterRecursionRule(_localctx, 38, C2105168Parser::RuleTerm, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(350);
    antlrcpp::downCast<TermContext *>(_localctx)->u = unary_expression();

             
                antlrcpp::downCast<TermContext *>(_localctx)->text =  antlrcpp::downCast<TermContext *>(_localctx)->u->text;
                antlrcpp::downCast<TermContext *>(_localctx)->line =  antlrcpp::downCast<TermContext *>(_localctx)->u->line;
                antlrcpp::downCast<TermContext *>(_localctx)->type =  antlrcpp::downCast<TermContext *>(_localctx)->u->type;
               antlrcpp::downCast<TermContext *>(_localctx)->argIsArray =  antlrcpp::downCast<TermContext *>(_localctx)->u->argIsArray; 
                antlrcpp::downCast<TermContext *>(_localctx)->code_section =  antlrcpp::downCast<TermContext *>(_localctx)->u->code_section;
                writeIntoparserLogFile("Line "+  std::to_string(antlrcpp::downCast<TermContext *>(_localctx)->u->line)+": term : unary_expression\n\n" + antlrcpp::downCast<TermContext *>(_localctx)->u->text + "\n");
                
    _ctx->stop = _input->LT(-1);
    setState(360);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<TermContext>(parentContext, parentState);
        _localctx->t = previousContext;
        pushNewRecursionContext(_localctx, startState, RuleTerm);
        setState(353);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(354);
        antlrcpp::downCast<TermContext *>(_localctx)->mulopToken = match(C2105168Parser::MULOP);
        setState(355);
        antlrcpp::downCast<TermContext *>(_localctx)->ue = unary_expression();

                      antlrcpp::downCast<TermContext *>(_localctx)->text =  antlrcpp::downCast<TermContext *>(_localctx)->t->text + antlrcpp::downCast<TermContext *>(_localctx)->mulopToken->getText() + antlrcpp::downCast<TermContext *>(_localctx)->ue->text;
                      antlrcpp::downCast<TermContext *>(_localctx)->line =  antlrcpp::downCast<TermContext *>(_localctx)->ue->line;
                      bool print = true;
                      bool zeroprint = false;
                      if (antlrcpp::downCast<TermContext *>(_localctx)->mulopToken->getText() == "%") {
                          if (antlrcpp::downCast<TermContext *>(_localctx)->t->type != "int" || antlrcpp::downCast<TermContext *>(_localctx)->ue->type != "int") {
                              writeIntoErrorFile("Error at line " + std::to_string(_localctx->line) + ": Non-Integer operand on modulus operator\n");
                              writeIntoparserLogFile("Line " + std::to_string(_localctx->line) + ": term : term MULOP unary_expression\n");
                              writeIntoparserLogFile("Error at line " + std::to_string(_localctx->line) + ": Non-Integer operand on modulus operator\n\n" + _localctx->text + "\n");
                                              errorCount++;
                              print = false;
                          }
                          else if(antlrcpp::downCast<TermContext *>(_localctx)->ue->text == "0"){
                              zeroprint = true;
                              errorCount++;
                          }
                       
                          antlrcpp::downCast<TermContext *>(_localctx)->type =  "int"; 
                      } else {
                          if (antlrcpp::downCast<TermContext *>(_localctx)->t->type == "float" || antlrcpp::downCast<TermContext *>(_localctx)->ue->type == "float") {
                              antlrcpp::downCast<TermContext *>(_localctx)->type =  "float";
                          } else {
                              antlrcpp::downCast<TermContext *>(_localctx)->type =  "int";
                          }
                      }
                      if(print && zeroprint == false){
                      writeIntoparserLogFile("Line " + std::to_string(_localctx->line) + ": term : term MULOP unary_expression\n\n" + _localctx->text + "\n");
                      }  

                      if(zeroprint){
                               writeIntoErrorFile("Error at line " + std::to_string(_localctx->line) + ": Modulus by Zero\n");
                      writeIntoparserLogFile("Line " + std::to_string(_localctx->line) + ": term : term MULOP unary_expression\n");

                              writeIntoparserLogFile("Error at line " + std::to_string(_localctx->line) + ": Modulus by Zero\n\n" + _localctx->text + "\n");
                      }



                   
      }
      setState(362);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- Unary_expressionContext ------------------------------------------------------------------

C2105168Parser::Unary_expressionContext::Unary_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* C2105168Parser::Unary_expressionContext::ADDOP() {
  return getToken(C2105168Parser::ADDOP, 0);
}

C2105168Parser::Unary_expressionContext* C2105168Parser::Unary_expressionContext::unary_expression() {
  return getRuleContext<C2105168Parser::Unary_expressionContext>(0);
}

tree::TerminalNode* C2105168Parser::Unary_expressionContext::NOT() {
  return getToken(C2105168Parser::NOT, 0);
}

C2105168Parser::FactorContext* C2105168Parser::Unary_expressionContext::factor() {
  return getRuleContext<C2105168Parser::FactorContext>(0);
}


size_t C2105168Parser::Unary_expressionContext::getRuleIndex() const {
  return C2105168Parser::RuleUnary_expression;
}

void C2105168Parser::Unary_expressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105168ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnary_expression(this);
}

void C2105168Parser::Unary_expressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105168ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnary_expression(this);
}

C2105168Parser::Unary_expressionContext* C2105168Parser::unary_expression() {
  Unary_expressionContext *_localctx = _tracker.createInstance<Unary_expressionContext>(_ctx, getState());
  enterRule(_localctx, 40, C2105168Parser::RuleUnary_expression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(374);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case C2105168Parser::ADDOP: {
        enterOuterAlt(_localctx, 1);
        setState(363);
        antlrcpp::downCast<Unary_expressionContext *>(_localctx)->addopToken = match(C2105168Parser::ADDOP);
        setState(364);
        antlrcpp::downCast<Unary_expressionContext *>(_localctx)->ue = unary_expression();

                    antlrcpp::downCast<Unary_expressionContext *>(_localctx)->text =  antlrcpp::downCast<Unary_expressionContext *>(_localctx)->addopToken->getText() + antlrcpp::downCast<Unary_expressionContext *>(_localctx)->ue->text;
                    antlrcpp::downCast<Unary_expressionContext *>(_localctx)->line =  antlrcpp::downCast<Unary_expressionContext *>(_localctx)->addopToken->getLine();
                    antlrcpp::downCast<Unary_expressionContext *>(_localctx)->type =  antlrcpp::downCast<Unary_expressionContext *>(_localctx)->ue->type;
                    antlrcpp::downCast<Unary_expressionContext *>(_localctx)->code_section =  antlrcpp::downCast<Unary_expressionContext *>(_localctx)->ue->code_section;
                    writeIntoparserLogFile("Line "+  std::to_string(_localctx->line)+": unary_expression : ADDOP unary_expression\n\n" + _localctx->text + "\n");

                
        break;
      }

      case C2105168Parser::NOT: {
        enterOuterAlt(_localctx, 2);
        setState(367);
        antlrcpp::downCast<Unary_expressionContext *>(_localctx)->notToken = match(C2105168Parser::NOT);
        setState(368);
        antlrcpp::downCast<Unary_expressionContext *>(_localctx)->ue = unary_expression();

                    antlrcpp::downCast<Unary_expressionContext *>(_localctx)->text =  antlrcpp::downCast<Unary_expressionContext *>(_localctx)->notToken->getText() + antlrcpp::downCast<Unary_expressionContext *>(_localctx)->ue->text;
                    antlrcpp::downCast<Unary_expressionContext *>(_localctx)->line =  antlrcpp::downCast<Unary_expressionContext *>(_localctx)->ue->line;
                    antlrcpp::downCast<Unary_expressionContext *>(_localctx)->type =  antlrcpp::downCast<Unary_expressionContext *>(_localctx)->ue->type;
                    writeIntoparserLogFile("Line "+  std::to_string(_localctx->line)+": unary_expression : NOT unary_expression\n\n" + _localctx->text + "\n");

                
        break;
      }

      case C2105168Parser::LPAREN:
      case C2105168Parser::ID:
      case C2105168Parser::CONST_INT:
      case C2105168Parser::CONST_FLOAT: {
        enterOuterAlt(_localctx, 3);
        setState(371);
        antlrcpp::downCast<Unary_expressionContext *>(_localctx)->f = factor();

                    antlrcpp::downCast<Unary_expressionContext *>(_localctx)->text =  antlrcpp::downCast<Unary_expressionContext *>(_localctx)->f->text;
                    antlrcpp::downCast<Unary_expressionContext *>(_localctx)->line =  antlrcpp::downCast<Unary_expressionContext *>(_localctx)->f->line;
                    antlrcpp::downCast<Unary_expressionContext *>(_localctx)->type =  antlrcpp::downCast<Unary_expressionContext *>(_localctx)->f->type;
                    antlrcpp::downCast<Unary_expressionContext *>(_localctx)->argIsArray =  antlrcpp::downCast<Unary_expressionContext *>(_localctx)->f->argIsArray;
                    antlrcpp::downCast<Unary_expressionContext *>(_localctx)->code_section =  antlrcpp::downCast<Unary_expressionContext *>(_localctx)->f->code_section;
                    writeIntoparserLogFile("Line "+  std::to_string(antlrcpp::downCast<Unary_expressionContext *>(_localctx)->f->line)+": unary_expression : factor\n\n" + antlrcpp::downCast<Unary_expressionContext *>(_localctx)->f->text + "\n"); 
                    
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FactorContext ------------------------------------------------------------------

C2105168Parser::FactorContext::FactorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C2105168Parser::VariableContext* C2105168Parser::FactorContext::variable() {
  return getRuleContext<C2105168Parser::VariableContext>(0);
}

tree::TerminalNode* C2105168Parser::FactorContext::ID() {
  return getToken(C2105168Parser::ID, 0);
}

tree::TerminalNode* C2105168Parser::FactorContext::LPAREN() {
  return getToken(C2105168Parser::LPAREN, 0);
}

tree::TerminalNode* C2105168Parser::FactorContext::RPAREN() {
  return getToken(C2105168Parser::RPAREN, 0);
}

C2105168Parser::Argument_listContext* C2105168Parser::FactorContext::argument_list() {
  return getRuleContext<C2105168Parser::Argument_listContext>(0);
}

C2105168Parser::ExpressionContext* C2105168Parser::FactorContext::expression() {
  return getRuleContext<C2105168Parser::ExpressionContext>(0);
}

tree::TerminalNode* C2105168Parser::FactorContext::CONST_INT() {
  return getToken(C2105168Parser::CONST_INT, 0);
}

tree::TerminalNode* C2105168Parser::FactorContext::CONST_FLOAT() {
  return getToken(C2105168Parser::CONST_FLOAT, 0);
}

tree::TerminalNode* C2105168Parser::FactorContext::INCOP() {
  return getToken(C2105168Parser::INCOP, 0);
}

tree::TerminalNode* C2105168Parser::FactorContext::DECOP() {
  return getToken(C2105168Parser::DECOP, 0);
}


size_t C2105168Parser::FactorContext::getRuleIndex() const {
  return C2105168Parser::RuleFactor;
}

void C2105168Parser::FactorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105168ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFactor(this);
}

void C2105168Parser::FactorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105168ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFactor(this);
}

C2105168Parser::FactorContext* C2105168Parser::factor() {
  FactorContext *_localctx = _tracker.createInstance<FactorContext>(_ctx, getState());
  enterRule(_localctx, 42, C2105168Parser::RuleFactor);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(403);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(376);
      antlrcpp::downCast<FactorContext *>(_localctx)->v = variable();

              antlrcpp::downCast<FactorContext *>(_localctx)->text =  antlrcpp::downCast<FactorContext *>(_localctx)->v->text;
              antlrcpp::downCast<FactorContext *>(_localctx)->line =  antlrcpp::downCast<FactorContext *>(_localctx)->v->line;
              antlrcpp::downCast<FactorContext *>(_localctx)->type =  antlrcpp::downCast<FactorContext *>(_localctx)->v->type;
              antlrcpp::downCast<FactorContext *>(_localctx)->argIsArray =  antlrcpp::downCast<FactorContext *>(_localctx)->v->isArray;
              antlrcpp::downCast<FactorContext *>(_localctx)->code_section =  antlrcpp::downCast<FactorContext *>(_localctx)->v->code_section;
              // std::cout << "v type"<<antlrcpp::downCast<FactorContext *>(_localctx)->v->type <<std::endl;
              writeIntoparserLogFile("Line "+  std::to_string(antlrcpp::downCast<FactorContext *>(_localctx)->v->line)+": factor : variable\n\n" + antlrcpp::downCast<FactorContext *>(_localctx)->v->text + "\n");
              
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(379);
      antlrcpp::downCast<FactorContext *>(_localctx)->idToken = match(C2105168Parser::ID);
      setState(380);
      antlrcpp::downCast<FactorContext *>(_localctx)->lparenToken = match(C2105168Parser::LPAREN);

              argumentCount = 0;
              argumentTypes.clear();
              argumentIsArray.clear();
          
      setState(382);
      antlrcpp::downCast<FactorContext *>(_localctx)->a = argument_list();
      setState(383);
      antlrcpp::downCast<FactorContext *>(_localctx)->rparenToken = match(C2105168Parser::RPAREN);

          antlrcpp::downCast<FactorContext *>(_localctx)->text =  antlrcpp::downCast<FactorContext *>(_localctx)->idToken->getText() + antlrcpp::downCast<FactorContext *>(_localctx)->lparenToken->getText() + antlrcpp::downCast<FactorContext *>(_localctx)->a->text + antlrcpp::downCast<FactorContext *>(_localctx)->rparenToken->getText();
          antlrcpp::downCast<FactorContext *>(_localctx)->line =  antlrcpp::downCast<FactorContext *>(_localctx)->idToken->getLine();
          antlrcpp::downCast<FactorContext *>(_localctx)->type =  antlrcpp::downCast<FactorContext *>(_localctx)->idToken->getType();

          SymbolInfo* func = symbolTable->LookUP(antlrcpp::downCast<FactorContext *>(_localctx)->idToken->getText());

          if (func == nullptr) {
              writeIntoErrorFile("Error at line " + std::to_string(_localctx->line) + ": Undefined function " + antlrcpp::downCast<FactorContext *>(_localctx)->idToken->getText() + "\n");
              errorCount++;
          } 
          else if (func->getIsFunction() && func->getIsFunctionDefined()) {
                      //            std::cout<<std::to_string(_localctx->line)<<func->getSymbolName()<<(int)func->parameterList.size()<< argumentCount<<std::endl;

              if ((int)func->parameterList.size()!= argumentCount) {

                  writeIntoErrorFile("Error at line " + std::to_string(_localctx->line) + ": Total number of arguments mismatch with declaration in function " + antlrcpp::downCast<FactorContext *>(_localctx)->idToken->getText() + "\n");
                  writeIntoparserLogFile("Error at line " + std::to_string(_localctx->line) + ": Total number of arguments mismatch with declaration in function " + antlrcpp::downCast<FactorContext *>(_localctx)->idToken->getText() + "\n");

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
                          writeIntoErrorFile("Error at line " + std::to_string(_localctx->line) + ": Type mismatch, " + func->parameterList[i].second + " is an array\n");
                          writeIntoparserLogFile("Error at line " + std::to_string(_localctx->line) + ": Type mismatch " + func->parameterList[i].second + " is an array\n");
                          errorCount++;
                      } 
                      else if (!argIsArray && expectedType != argType) {
                          writeIntoErrorFile("Error at line " + std::to_string(_localctx->line) + ": " + std::to_string(i + 1) + "th argument mismatch in function " + antlrcpp::downCast<FactorContext *>(_localctx)->idToken->getText() + "\n");
                          writeIntoparserLogFile("Error at line " + std::to_string(_localctx->line) + ": " + std::to_string(i + 1) + "th argument mismatch in function " + antlrcpp::downCast<FactorContext *>(_localctx)->idToken->getText() + "\n");
                          errorCount++;
                          break;
                      }
                  }

                  std::cout << "argumentCount: " << argumentCount << std::endl;

              }
          } 
          else {
              writeIntoErrorFile("Error at line " + std::to_string(_localctx->line) + ": Undefined function " + antlrcpp::downCast<FactorContext *>(_localctx)->idToken->getText() + "\n");
              errorCount++;
          }

          writeIntoparserLogFile("Line " + std::to_string(_localctx->line) + ": factor : ID LPAREN argument_list RPAREN\n\n" + _localctx->text + "\n");

      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(386);
      antlrcpp::downCast<FactorContext *>(_localctx)->lparenToken = match(C2105168Parser::LPAREN);
      setState(387);
      antlrcpp::downCast<FactorContext *>(_localctx)->e = expression();
      setState(388);
      antlrcpp::downCast<FactorContext *>(_localctx)->rparenToken = match(C2105168Parser::RPAREN);
       
              antlrcpp::downCast<FactorContext *>(_localctx)->text =  antlrcpp::downCast<FactorContext *>(_localctx)->lparenToken->getText() + antlrcpp::downCast<FactorContext *>(_localctx)->e->text + antlrcpp::downCast<FactorContext *>(_localctx)->rparenToken->getText();
              antlrcpp::downCast<FactorContext *>(_localctx)->line =  antlrcpp::downCast<FactorContext *>(_localctx)->rparenToken->getLine();
              antlrcpp::downCast<FactorContext *>(_localctx)->type =  antlrcpp::downCast<FactorContext *>(_localctx)->e->type;
               antlrcpp::downCast<FactorContext *>(_localctx)->argIsArray =  false;
              writeIntoparserLogFile("Line "+  std::to_string(_localctx->line)+": factor : LPAREN expression RPAREN\n\n" + _localctx->text + "\n");

           
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(391);
      antlrcpp::downCast<FactorContext *>(_localctx)->const_intToken = match(C2105168Parser::CONST_INT);

              antlrcpp::downCast<FactorContext *>(_localctx)->text =  antlrcpp::downCast<FactorContext *>(_localctx)->const_intToken->getText();
              antlrcpp::downCast<FactorContext *>(_localctx)->line =  antlrcpp::downCast<FactorContext *>(_localctx)->const_intToken->getLine();
              antlrcpp::downCast<FactorContext *>(_localctx)->type =  "int";
               antlrcpp::downCast<FactorContext *>(_localctx)->argIsArray =  false;
             // std::cout << "CONST_INT type"<<_localctx->type <<std::endl;
              writeIntoparserLogFile("Line "+  std::to_string(_localctx->line)+": factor : CONST_INT\n\n" + _localctx->text + "\n");

          
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(393);
      antlrcpp::downCast<FactorContext *>(_localctx)->const_floatToken = match(C2105168Parser::CONST_FLOAT);

              antlrcpp::downCast<FactorContext *>(_localctx)->text =  antlrcpp::downCast<FactorContext *>(_localctx)->const_floatToken->getText();
              antlrcpp::downCast<FactorContext *>(_localctx)->line =  antlrcpp::downCast<FactorContext *>(_localctx)->const_floatToken->getLine();
              antlrcpp::downCast<FactorContext *>(_localctx)->type =  "float";
               antlrcpp::downCast<FactorContext *>(_localctx)->argIsArray =  false;
              writeIntoparserLogFile("Line "+  std::to_string(_localctx->line)+": factor : CONST_FLOAT\n\n" + _localctx->text + "\n");

          
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(395);
      antlrcpp::downCast<FactorContext *>(_localctx)->v = variable();
      setState(396);
      antlrcpp::downCast<FactorContext *>(_localctx)->incopToken = match(C2105168Parser::INCOP);

              antlrcpp::downCast<FactorContext *>(_localctx)->text =  antlrcpp::downCast<FactorContext *>(_localctx)->v->text+antlrcpp::downCast<FactorContext *>(_localctx)->incopToken->getText();
              antlrcpp::downCast<FactorContext *>(_localctx)->line =  antlrcpp::downCast<FactorContext *>(_localctx)->incopToken->getLine();
              antlrcpp::downCast<FactorContext *>(_localctx)->type =  antlrcpp::downCast<FactorContext *>(_localctx)->v->type;
              writeIntoparserLogFile("Line "+  std::to_string(_localctx->line)+": factor : variable INCOP\n\n" + _localctx->text + "\n");

          
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(399);
      antlrcpp::downCast<FactorContext *>(_localctx)->v = variable();
      setState(400);
      antlrcpp::downCast<FactorContext *>(_localctx)->decopToken = match(C2105168Parser::DECOP);

              antlrcpp::downCast<FactorContext *>(_localctx)->text =  antlrcpp::downCast<FactorContext *>(_localctx)->v->text+antlrcpp::downCast<FactorContext *>(_localctx)->decopToken->getText();
              antlrcpp::downCast<FactorContext *>(_localctx)->line =  antlrcpp::downCast<FactorContext *>(_localctx)->decopToken->getLine();
              antlrcpp::downCast<FactorContext *>(_localctx)->type =  antlrcpp::downCast<FactorContext *>(_localctx)->v->type;
              writeIntoparserLogFile("Line "+  std::to_string(_localctx->line)+": factor : variable DECOP\n\n" + _localctx->text + "\n");

          
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Argument_listContext ------------------------------------------------------------------

C2105168Parser::Argument_listContext::Argument_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C2105168Parser::ArgumentsContext* C2105168Parser::Argument_listContext::arguments() {
  return getRuleContext<C2105168Parser::ArgumentsContext>(0);
}


size_t C2105168Parser::Argument_listContext::getRuleIndex() const {
  return C2105168Parser::RuleArgument_list;
}

void C2105168Parser::Argument_listContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105168ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArgument_list(this);
}

void C2105168Parser::Argument_listContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105168ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArgument_list(this);
}

C2105168Parser::Argument_listContext* C2105168Parser::argument_list() {
  Argument_listContext *_localctx = _tracker.createInstance<Argument_listContext>(_ctx, getState());
  enterRule(_localctx, 44, C2105168Parser::RuleArgument_list);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(409);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case C2105168Parser::LPAREN:
      case C2105168Parser::ADDOP:
      case C2105168Parser::NOT:
      case C2105168Parser::ID:
      case C2105168Parser::CONST_INT:
      case C2105168Parser::CONST_FLOAT: {
        enterOuterAlt(_localctx, 1);
        setState(405);
        antlrcpp::downCast<Argument_listContext *>(_localctx)->a = arguments(0);
           
                    antlrcpp::downCast<Argument_listContext *>(_localctx)->text =  antlrcpp::downCast<Argument_listContext *>(_localctx)->a->text;
                    antlrcpp::downCast<Argument_listContext *>(_localctx)->line =  antlrcpp::downCast<Argument_listContext *>(_localctx)->a->line;
                    antlrcpp::downCast<Argument_listContext *>(_localctx)->type =  antlrcpp::downCast<Argument_listContext *>(_localctx)->a->type;
                    
                    writeIntoparserLogFile("Line "+ std::to_string(_localctx->line)+": argument_list : arguments\n\n"+_localctx->text+"\n");
                  
        break;
      }

      case C2105168Parser::RPAREN: {
        enterOuterAlt(_localctx, 2);

        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArgumentsContext ------------------------------------------------------------------

C2105168Parser::ArgumentsContext::ArgumentsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C2105168Parser::Logic_expressionContext* C2105168Parser::ArgumentsContext::logic_expression() {
  return getRuleContext<C2105168Parser::Logic_expressionContext>(0);
}

tree::TerminalNode* C2105168Parser::ArgumentsContext::COMMA() {
  return getToken(C2105168Parser::COMMA, 0);
}

C2105168Parser::ArgumentsContext* C2105168Parser::ArgumentsContext::arguments() {
  return getRuleContext<C2105168Parser::ArgumentsContext>(0);
}


size_t C2105168Parser::ArgumentsContext::getRuleIndex() const {
  return C2105168Parser::RuleArguments;
}

void C2105168Parser::ArgumentsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105168ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArguments(this);
}

void C2105168Parser::ArgumentsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105168ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArguments(this);
}


C2105168Parser::ArgumentsContext* C2105168Parser::arguments() {
   return arguments(0);
}

C2105168Parser::ArgumentsContext* C2105168Parser::arguments(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  C2105168Parser::ArgumentsContext *_localctx = _tracker.createInstance<ArgumentsContext>(_ctx, parentState);
  C2105168Parser::ArgumentsContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 46;
  enterRecursionRule(_localctx, 46, C2105168Parser::RuleArguments, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(412);
    antlrcpp::downCast<ArgumentsContext *>(_localctx)->le = logic_expression();


                antlrcpp::downCast<ArgumentsContext *>(_localctx)->text = antlrcpp::downCast<ArgumentsContext *>(_localctx)->le->text;
                antlrcpp::downCast<ArgumentsContext *>(_localctx)->line = antlrcpp::downCast<ArgumentsContext *>(_localctx)->le->line;
                antlrcpp::downCast<ArgumentsContext *>(_localctx)->type =  antlrcpp::downCast<ArgumentsContext *>(_localctx)->le->type; 
                argumentCount++;  
                argumentTypes.push_back(antlrcpp::downCast<ArgumentsContext *>(_localctx)->le->type);
                argumentIsArray.push_back(antlrcpp::downCast<ArgumentsContext *>(_localctx)->le->argIsArr);
                writeIntoparserLogFile("Line "+ std::to_string(_localctx->line)+": arguments : logic_expression\n\n"+_localctx->text+"\n");


            
    _ctx->stop = _input->LT(-1);
    setState(422);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<ArgumentsContext>(parentContext, parentState);
        _localctx->a = previousContext;
        pushNewRecursionContext(_localctx, startState, RuleArguments);
        setState(415);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(416);
        antlrcpp::downCast<ArgumentsContext *>(_localctx)->commaToken = match(C2105168Parser::COMMA);
        setState(417);
        antlrcpp::downCast<ArgumentsContext *>(_localctx)->le = logic_expression();
            
                              antlrcpp::downCast<ArgumentsContext *>(_localctx)->text = antlrcpp::downCast<ArgumentsContext *>(_localctx)->a->text +  antlrcpp::downCast<ArgumentsContext *>(_localctx)->commaToken->getText()+  antlrcpp::downCast<ArgumentsContext *>(_localctx)->le->text;
                              antlrcpp::downCast<ArgumentsContext *>(_localctx)->line = antlrcpp::downCast<ArgumentsContext *>(_localctx)->le->line;
                              antlrcpp::downCast<ArgumentsContext *>(_localctx)->type =  antlrcpp::downCast<ArgumentsContext *>(_localctx)->le->type;
                              argumentCount++;
                              argumentTypes.push_back(antlrcpp::downCast<ArgumentsContext *>(_localctx)->le->type);
                              argumentIsArray.push_back(antlrcpp::downCast<ArgumentsContext *>(_localctx)->le->argIsArr);
                              writeIntoparserLogFile("Line "+ std::to_string(_localctx->line)+": arguments : arguments COMMA logic_expression\n\n"+_localctx->text+"\n");

                            
      }
      setState(424);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

bool C2105168Parser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 1: return programSempred(antlrcpp::downCast<ProgramContext *>(context), predicateIndex);
    case 5: return parameter_listSempred(antlrcpp::downCast<Parameter_listContext *>(context), predicateIndex);
    case 10: return declaration_listSempred(antlrcpp::downCast<Declaration_listContext *>(context), predicateIndex);
    case 11: return statementsSempred(antlrcpp::downCast<StatementsContext *>(context), predicateIndex);
    case 18: return simple_expressionSempred(antlrcpp::downCast<Simple_expressionContext *>(context), predicateIndex);
    case 19: return termSempred(antlrcpp::downCast<TermContext *>(context), predicateIndex);
    case 23: return argumentsSempred(antlrcpp::downCast<ArgumentsContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool C2105168Parser::programSempred(ProgramContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

bool C2105168Parser::parameter_listSempred(Parameter_listContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 1: return precpred(_ctx, 7);
    case 2: return precpred(_ctx, 6);
    case 3: return precpred(_ctx, 5);

  default:
    break;
  }
  return true;
}

bool C2105168Parser::declaration_listSempred(Declaration_listContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 4: return precpred(_ctx, 6);
    case 5: return precpred(_ctx, 5);
    case 6: return precpred(_ctx, 4);

  default:
    break;
  }
  return true;
}

bool C2105168Parser::statementsSempred(StatementsContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 7: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool C2105168Parser::simple_expressionSempred(Simple_expressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 8: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool C2105168Parser::termSempred(TermContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 9: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool C2105168Parser::argumentsSempred(ArgumentsContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 10: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

void C2105168Parser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  c2105168parserParserInitialize();
#else
  ::antlr4::internal::call_once(c2105168parserParserOnceFlag, c2105168parserParserInitialize);
#endif
}
