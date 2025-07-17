
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
      "", "", "", "", "", "'if'", "'else'", "'for'", "'while'", "'println'", 
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
  	4,1,34,429,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,1,0,1,0,1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
  	1,5,1,61,8,1,10,1,12,1,64,9,1,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,3,2,
  	75,8,2,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,
  	3,3,3,93,8,3,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,
  	1,4,1,4,1,4,1,4,1,4,1,4,3,4,115,8,4,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,
  	5,1,5,1,5,1,5,1,5,1,5,3,5,131,8,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,
  	1,5,1,5,1,5,1,5,1,5,1,5,5,5,148,8,5,10,5,12,5,151,9,5,1,6,1,6,1,6,1,6,
  	1,6,1,6,1,6,1,6,1,6,1,6,1,6,3,6,164,8,6,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,
  	7,1,7,1,7,3,7,176,8,7,1,8,1,8,1,9,1,9,1,9,1,9,1,9,1,9,3,9,186,8,9,1,10,
  	1,10,1,10,1,10,1,10,1,10,1,10,1,10,1,10,1,10,1,10,1,10,1,10,3,10,201,
  	8,10,1,10,1,10,1,10,1,10,1,10,1,10,1,10,1,10,1,10,1,10,1,10,1,10,1,10,
  	1,10,1,10,1,10,5,10,219,8,10,10,10,12,10,222,9,10,1,11,1,11,1,11,1,11,
  	1,11,1,11,1,11,1,11,5,11,232,8,11,10,11,12,11,235,9,11,1,12,1,12,1,12,
  	1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,
  	1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,
  	1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,
  	1,12,1,12,1,12,1,12,1,12,1,12,1,12,3,12,289,8,12,1,13,1,13,1,13,1,13,
  	1,13,1,13,3,13,297,8,13,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,3,14,
  	307,8,14,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,3,15,317,8,15,1,16,1,
  	16,1,16,1,16,1,16,1,16,1,16,1,16,3,16,327,8,16,1,17,1,17,1,17,1,17,1,
  	17,1,17,1,17,1,17,3,17,337,8,17,1,18,1,18,1,18,1,18,1,18,1,18,1,18,1,
  	18,1,18,5,18,348,8,18,10,18,12,18,351,9,18,1,19,1,19,1,19,1,19,1,19,1,
  	19,1,19,1,19,1,19,5,19,362,8,19,10,19,12,19,365,9,19,1,20,1,20,1,20,1,
  	20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,3,20,378,8,20,1,21,1,21,1,21,1,
  	21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,
  	21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,3,21,407,8,21,1,22,1,
  	22,1,22,1,22,3,22,413,8,22,1,23,1,23,1,23,1,23,1,23,1,23,1,23,1,23,1,
  	23,5,23,424,8,23,10,23,12,23,427,9,23,1,23,0,7,2,10,20,22,36,38,46,24,
  	0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,42,44,46,0,
  	0,450,0,48,1,0,0,0,2,52,1,0,0,0,4,74,1,0,0,0,6,92,1,0,0,0,8,114,1,0,0,
  	0,10,130,1,0,0,0,12,163,1,0,0,0,14,175,1,0,0,0,16,177,1,0,0,0,18,185,
  	1,0,0,0,20,200,1,0,0,0,22,223,1,0,0,0,24,288,1,0,0,0,26,296,1,0,0,0,28,
  	306,1,0,0,0,30,316,1,0,0,0,32,326,1,0,0,0,34,336,1,0,0,0,36,338,1,0,0,
  	0,38,352,1,0,0,0,40,377,1,0,0,0,42,406,1,0,0,0,44,412,1,0,0,0,46,414,
  	1,0,0,0,48,49,6,0,-1,0,49,50,3,2,1,0,50,51,6,0,-1,0,51,1,1,0,0,0,52,53,
  	6,1,-1,0,53,54,3,4,2,0,54,55,6,1,-1,0,55,62,1,0,0,0,56,57,10,2,0,0,57,
  	58,3,4,2,0,58,59,6,1,-1,0,59,61,1,0,0,0,60,56,1,0,0,0,61,64,1,0,0,0,62,
  	60,1,0,0,0,62,63,1,0,0,0,63,3,1,0,0,0,64,62,1,0,0,0,65,66,3,14,7,0,66,
  	67,6,2,-1,0,67,75,1,0,0,0,68,69,3,6,3,0,69,70,6,2,-1,0,70,75,1,0,0,0,
  	71,72,3,8,4,0,72,73,6,2,-1,0,73,75,1,0,0,0,74,65,1,0,0,0,74,68,1,0,0,
  	0,74,71,1,0,0,0,75,5,1,0,0,0,76,77,3,18,9,0,77,78,5,32,0,0,78,79,6,3,
  	-1,0,79,80,5,14,0,0,80,81,3,10,5,0,81,82,5,15,0,0,82,83,5,20,0,0,83,84,
  	6,3,-1,0,84,93,1,0,0,0,85,86,3,18,9,0,86,87,5,32,0,0,87,88,5,14,0,0,88,
  	89,5,15,0,0,89,90,5,20,0,0,90,91,6,3,-1,0,91,93,1,0,0,0,92,76,1,0,0,0,
  	92,85,1,0,0,0,93,7,1,0,0,0,94,95,3,18,9,0,95,96,5,32,0,0,96,97,5,14,0,
  	0,97,98,6,4,-1,0,98,99,3,10,5,0,99,100,6,4,-1,0,100,101,5,15,0,0,101,
  	102,6,4,-1,0,102,103,3,12,6,0,103,104,6,4,-1,0,104,115,1,0,0,0,105,106,
  	3,18,9,0,106,107,5,32,0,0,107,108,5,14,0,0,108,109,5,15,0,0,109,110,6,
  	4,-1,0,110,111,6,4,-1,0,111,112,3,12,6,0,112,113,6,4,-1,0,113,115,1,0,
  	0,0,114,94,1,0,0,0,114,105,1,0,0,0,115,9,1,0,0,0,116,117,6,5,-1,0,117,
  	118,3,18,9,0,118,119,5,32,0,0,119,120,6,5,-1,0,120,131,1,0,0,0,121,122,
  	3,18,9,0,122,123,5,23,0,0,123,124,6,5,-1,0,124,131,1,0,0,0,125,126,3,
  	18,9,0,126,127,6,5,-1,0,127,131,1,0,0,0,128,129,5,23,0,0,129,131,6,5,
  	-1,0,130,116,1,0,0,0,130,121,1,0,0,0,130,125,1,0,0,0,130,128,1,0,0,0,
  	131,149,1,0,0,0,132,133,10,7,0,0,133,134,5,21,0,0,134,135,3,18,9,0,135,
  	136,5,32,0,0,136,137,6,5,-1,0,137,148,1,0,0,0,138,139,10,6,0,0,139,140,
  	5,21,0,0,140,141,3,18,9,0,141,142,6,5,-1,0,142,148,1,0,0,0,143,144,10,
  	5,0,0,144,145,5,21,0,0,145,146,5,23,0,0,146,148,6,5,-1,0,147,132,1,0,
  	0,0,147,138,1,0,0,0,147,143,1,0,0,0,148,151,1,0,0,0,149,147,1,0,0,0,149,
  	150,1,0,0,0,150,11,1,0,0,0,151,149,1,0,0,0,152,153,5,16,0,0,153,154,6,
  	6,-1,0,154,155,3,22,11,0,155,156,6,6,-1,0,156,157,5,17,0,0,157,158,6,
  	6,-1,0,158,164,1,0,0,0,159,160,5,16,0,0,160,161,6,6,-1,0,161,162,5,17,
  	0,0,162,164,6,6,-1,0,163,152,1,0,0,0,163,159,1,0,0,0,164,13,1,0,0,0,165,
  	166,3,18,9,0,166,167,3,20,10,0,167,168,5,20,0,0,168,169,6,7,-1,0,169,
  	176,1,0,0,0,170,171,3,18,9,0,171,172,3,16,8,0,172,173,5,20,0,0,173,174,
  	6,7,-1,0,174,176,1,0,0,0,175,165,1,0,0,0,175,170,1,0,0,0,176,15,1,0,0,
  	0,177,178,6,8,-1,0,178,17,1,0,0,0,179,180,5,11,0,0,180,186,6,9,-1,0,181,
  	182,5,12,0,0,182,186,6,9,-1,0,183,184,5,13,0,0,184,186,6,9,-1,0,185,179,
  	1,0,0,0,185,181,1,0,0,0,185,183,1,0,0,0,186,19,1,0,0,0,187,188,6,10,-1,
  	0,188,189,5,32,0,0,189,201,6,10,-1,0,190,191,5,32,0,0,191,192,5,18,0,
  	0,192,193,5,33,0,0,193,194,5,19,0,0,194,201,6,10,-1,0,195,196,5,32,0,
  	0,196,197,5,23,0,0,197,198,3,20,10,1,198,199,6,10,-1,0,199,201,1,0,0,
  	0,200,187,1,0,0,0,200,190,1,0,0,0,200,195,1,0,0,0,201,220,1,0,0,0,202,
  	203,10,6,0,0,203,204,5,21,0,0,204,205,5,32,0,0,205,219,6,10,-1,0,206,
  	207,10,5,0,0,207,208,5,21,0,0,208,209,5,32,0,0,209,210,5,18,0,0,210,211,
  	5,33,0,0,211,212,5,19,0,0,212,219,6,10,-1,0,213,214,10,4,0,0,214,215,
  	5,21,0,0,215,216,5,32,0,0,216,217,5,23,0,0,217,219,6,10,-1,0,218,202,
  	1,0,0,0,218,206,1,0,0,0,218,213,1,0,0,0,219,222,1,0,0,0,220,218,1,0,0,
  	0,220,221,1,0,0,0,221,21,1,0,0,0,222,220,1,0,0,0,223,224,6,11,-1,0,224,
  	225,3,24,12,0,225,226,6,11,-1,0,226,233,1,0,0,0,227,228,10,1,0,0,228,
  	229,3,24,12,0,229,230,6,11,-1,0,230,232,1,0,0,0,231,227,1,0,0,0,232,235,
  	1,0,0,0,233,231,1,0,0,0,233,234,1,0,0,0,234,23,1,0,0,0,235,233,1,0,0,
  	0,236,237,3,14,7,0,237,238,6,12,-1,0,238,289,1,0,0,0,239,240,3,26,13,
  	0,240,241,6,12,-1,0,241,289,1,0,0,0,242,243,3,12,6,0,243,244,6,12,-1,
  	0,244,289,1,0,0,0,245,246,5,7,0,0,246,247,5,14,0,0,247,248,3,26,13,0,
  	248,249,3,26,13,0,249,250,3,30,15,0,250,251,5,15,0,0,251,252,3,24,12,
  	0,252,253,6,12,-1,0,253,289,1,0,0,0,254,255,5,5,0,0,255,256,5,14,0,0,
  	256,257,3,30,15,0,257,258,5,15,0,0,258,259,3,24,12,0,259,260,6,12,-1,
  	0,260,289,1,0,0,0,261,262,5,5,0,0,262,263,5,14,0,0,263,264,3,30,15,0,
  	264,265,5,15,0,0,265,266,3,24,12,0,266,267,5,6,0,0,267,268,3,24,12,0,
  	268,269,6,12,-1,0,269,289,1,0,0,0,270,271,5,8,0,0,271,272,5,14,0,0,272,
  	273,3,30,15,0,273,274,5,15,0,0,274,275,3,24,12,0,275,276,6,12,-1,0,276,
  	289,1,0,0,0,277,278,5,9,0,0,278,279,5,14,0,0,279,280,5,32,0,0,280,281,
  	5,15,0,0,281,282,5,20,0,0,282,289,6,12,-1,0,283,284,5,10,0,0,284,285,
  	3,30,15,0,285,286,5,20,0,0,286,287,6,12,-1,0,287,289,1,0,0,0,288,236,
  	1,0,0,0,288,239,1,0,0,0,288,242,1,0,0,0,288,245,1,0,0,0,288,254,1,0,0,
  	0,288,261,1,0,0,0,288,270,1,0,0,0,288,277,1,0,0,0,288,283,1,0,0,0,289,
  	25,1,0,0,0,290,291,5,20,0,0,291,297,6,13,-1,0,292,293,3,30,15,0,293,294,
  	5,20,0,0,294,295,6,13,-1,0,295,297,1,0,0,0,296,290,1,0,0,0,296,292,1,
  	0,0,0,297,27,1,0,0,0,298,299,5,32,0,0,299,307,6,14,-1,0,300,301,5,32,
  	0,0,301,302,5,18,0,0,302,303,3,30,15,0,303,304,5,19,0,0,304,305,6,14,
  	-1,0,305,307,1,0,0,0,306,298,1,0,0,0,306,300,1,0,0,0,307,29,1,0,0,0,308,
  	309,3,32,16,0,309,310,6,15,-1,0,310,317,1,0,0,0,311,312,3,28,14,0,312,
  	313,5,31,0,0,313,314,3,32,16,0,314,315,6,15,-1,0,315,317,1,0,0,0,316,
  	308,1,0,0,0,316,311,1,0,0,0,317,31,1,0,0,0,318,319,3,34,17,0,319,320,
  	6,16,-1,0,320,327,1,0,0,0,321,322,3,34,17,0,322,323,5,30,0,0,323,324,
  	3,34,17,0,324,325,6,16,-1,0,325,327,1,0,0,0,326,318,1,0,0,0,326,321,1,
  	0,0,0,327,33,1,0,0,0,328,329,3,36,18,0,329,330,6,17,-1,0,330,337,1,0,
  	0,0,331,332,3,36,18,0,332,333,5,29,0,0,333,334,3,36,18,0,334,335,6,17,
  	-1,0,335,337,1,0,0,0,336,328,1,0,0,0,336,331,1,0,0,0,337,35,1,0,0,0,338,
  	339,6,18,-1,0,339,340,3,38,19,0,340,341,6,18,-1,0,341,349,1,0,0,0,342,
  	343,10,1,0,0,343,344,5,23,0,0,344,345,3,38,19,0,345,346,6,18,-1,0,346,
  	348,1,0,0,0,347,342,1,0,0,0,348,351,1,0,0,0,349,347,1,0,0,0,349,350,1,
  	0,0,0,350,37,1,0,0,0,351,349,1,0,0,0,352,353,6,19,-1,0,353,354,3,40,20,
  	0,354,355,6,19,-1,0,355,363,1,0,0,0,356,357,10,1,0,0,357,358,5,25,0,0,
  	358,359,3,40,20,0,359,360,6,19,-1,0,360,362,1,0,0,0,361,356,1,0,0,0,362,
  	365,1,0,0,0,363,361,1,0,0,0,363,364,1,0,0,0,364,39,1,0,0,0,365,363,1,
  	0,0,0,366,367,5,23,0,0,367,368,3,40,20,0,368,369,6,20,-1,0,369,378,1,
  	0,0,0,370,371,5,28,0,0,371,372,3,40,20,0,372,373,6,20,-1,0,373,378,1,
  	0,0,0,374,375,3,42,21,0,375,376,6,20,-1,0,376,378,1,0,0,0,377,366,1,0,
  	0,0,377,370,1,0,0,0,377,374,1,0,0,0,378,41,1,0,0,0,379,380,3,28,14,0,
  	380,381,6,21,-1,0,381,407,1,0,0,0,382,383,5,32,0,0,383,384,5,14,0,0,384,
  	385,6,21,-1,0,385,386,3,44,22,0,386,387,5,15,0,0,387,388,6,21,-1,0,388,
  	407,1,0,0,0,389,390,5,14,0,0,390,391,3,30,15,0,391,392,5,15,0,0,392,393,
  	6,21,-1,0,393,407,1,0,0,0,394,395,5,33,0,0,395,407,6,21,-1,0,396,397,
  	5,34,0,0,397,407,6,21,-1,0,398,399,3,28,14,0,399,400,5,26,0,0,400,401,
  	6,21,-1,0,401,407,1,0,0,0,402,403,3,28,14,0,403,404,5,27,0,0,404,405,
  	6,21,-1,0,405,407,1,0,0,0,406,379,1,0,0,0,406,382,1,0,0,0,406,389,1,0,
  	0,0,406,394,1,0,0,0,406,396,1,0,0,0,406,398,1,0,0,0,406,402,1,0,0,0,407,
  	43,1,0,0,0,408,409,3,46,23,0,409,410,6,22,-1,0,410,413,1,0,0,0,411,413,
  	1,0,0,0,412,408,1,0,0,0,412,411,1,0,0,0,413,45,1,0,0,0,414,415,6,23,-1,
  	0,415,416,3,32,16,0,416,417,6,23,-1,0,417,425,1,0,0,0,418,419,10,2,0,
  	0,419,420,5,21,0,0,420,421,3,32,16,0,421,422,6,23,-1,0,422,424,1,0,0,
  	0,423,418,1,0,0,0,424,427,1,0,0,0,425,423,1,0,0,0,425,426,1,0,0,0,426,
  	47,1,0,0,0,427,425,1,0,0,0,26,62,74,92,114,130,147,149,163,175,185,200,
  	218,220,233,288,296,306,316,326,336,349,363,377,406,412,425
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
     writeIntoAsmFile(".MODEL SMALL\n.STACK 1000H\n.Data\n\tnumber DB \"00000$\"");
    setState(49);
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

            writeIntoAsmFile(Print_assembly);
            writeIntoAsmFile("END main");
            std::cout << "here" <<std::endl;


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
    setState(53);
    antlrcpp::downCast<ProgramContext *>(_localctx)->u = unit();
     
            antlrcpp::downCast<ProgramContext *>(_localctx)->text =  antlrcpp::downCast<ProgramContext *>(_localctx)->u->text;
            antlrcpp::downCast<ProgramContext *>(_localctx)->line =  antlrcpp::downCast<ProgramContext *>(_localctx)->u->line;
            writeIntoparserLogFile("Line "+std::to_string(_localctx->line)+": program : unit\n\n"+_localctx->text+"\n");

             
    _ctx->stop = _input->LT(-1);
    setState(62);
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
        setState(56);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(57);
        antlrcpp::downCast<ProgramContext *>(_localctx)->u = unit();
          
                          antlrcpp::downCast<ProgramContext *>(_localctx)->text =  antlrcpp::downCast<ProgramContext *>(_localctx)->pu->text +"\n"+antlrcpp::downCast<ProgramContext *>(_localctx)->u->text;
                          antlrcpp::downCast<ProgramContext *>(_localctx)->line =  antlrcpp::downCast<ProgramContext *>(_localctx)->u->line;
                          antlrcpp::downCast<ProgramContext *>(_localctx)->data_section_code =  antlrcpp::downCast<ProgramContext *>(_localctx)->pu->data_section_code +antlrcpp::downCast<ProgramContext *>(_localctx)->u->data_section_code;
                          antlrcpp::downCast<ProgramContext *>(_localctx)->code_section =  antlrcpp::downCast<ProgramContext *>(_localctx)->pu->code_section + antlrcpp::downCast<ProgramContext *>(_localctx)->u->code_section;
                          writeIntoparserLogFile("Line "+std::to_string(_localctx->line)+": program : program unit\n\n"+_localctx->text+"\n");
                           
      }
      setState(64);
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
    setState(74);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(65);
      antlrcpp::downCast<UnitContext *>(_localctx)->vd = var_declaration();
        
              antlrcpp::downCast<UnitContext *>(_localctx)->text =  antlrcpp::downCast<UnitContext *>(_localctx)->vd->text;
              antlrcpp::downCast<UnitContext *>(_localctx)->line =  antlrcpp::downCast<UnitContext *>(_localctx)->vd->line;


              std::cout << "DEBUG: unit var_declaration code_section = '" << _localctx->code_section << "'" << std::endl;
              writeIntoparserLogFile("Line "+std::to_string(_localctx->line)+": unit : var_declaration\n\n"+_localctx->text+"\n");

          
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(68);
      antlrcpp::downCast<UnitContext *>(_localctx)->fdec = func_declaration();
        

              antlrcpp::downCast<UnitContext *>(_localctx)->text =  antlrcpp::downCast<UnitContext *>(_localctx)->fdec->text;  
              antlrcpp::downCast<UnitContext *>(_localctx)->line =  antlrcpp::downCast<UnitContext *>(_localctx)->fdec->line;
              writeIntoparserLogFile("Line "+std::to_string(_localctx->line)+": unit : func_declaration\n\n"+_localctx->text+"\n");

          
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(71);
      antlrcpp::downCast<UnitContext *>(_localctx)->fdef = func_definition();
        
              antlrcpp::downCast<UnitContext *>(_localctx)->text =  antlrcpp::downCast<UnitContext *>(_localctx)->fdef->text;
              antlrcpp::downCast<UnitContext *>(_localctx)->line =  antlrcpp::downCast<UnitContext *>(_localctx)->fdef->line;
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
    setState(92);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(76);
      antlrcpp::downCast<Func_declarationContext *>(_localctx)->ts = type_specifier();
      setState(77);
      antlrcpp::downCast<Func_declarationContext *>(_localctx)->idToken = match(C2105168Parser::ID);

              paramCount = 0;
          
      setState(79);
      antlrcpp::downCast<Func_declarationContext *>(_localctx)->lparenToken = match(C2105168Parser::LPAREN);
      setState(80);
      antlrcpp::downCast<Func_declarationContext *>(_localctx)->pl = parameter_list(0);
      setState(81);
      antlrcpp::downCast<Func_declarationContext *>(_localctx)->rparenToken = match(C2105168Parser::RPAREN);
      setState(82);
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



              writeIntoparserLogFile("Line "+std::to_string(_localctx->line)+": func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON\n\n"+_localctx->text+"\n");


          
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(85);
      antlrcpp::downCast<Func_declarationContext *>(_localctx)->ts = type_specifier();
      setState(86);
      antlrcpp::downCast<Func_declarationContext *>(_localctx)->idToken = match(C2105168Parser::ID);
      setState(87);
      antlrcpp::downCast<Func_declarationContext *>(_localctx)->lparenToken = match(C2105168Parser::LPAREN);
      setState(88);
      antlrcpp::downCast<Func_declarationContext *>(_localctx)->rparenToken = match(C2105168Parser::RPAREN);
      setState(89);
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
    setState(114);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(94);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->ts = type_specifier();
      setState(95);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken = match(C2105168Parser::ID);
      setState(96);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->lparenToken = match(C2105168Parser::LPAREN);
          std::cout << "DEBUG: About to parse parameter_list" << std::endl;
      setState(98);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->pl = parameter_list(0);

                  std::cout << "DEBUG: Successfully parsed parameter_list, pl.text = '" << antlrcpp::downCast<Func_definitionContext *>(_localctx)->pl->text << "'" << std::endl;
              SymbolInfo* funcSymbol = new SymbolInfo(antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getText(), "ID");
              funcSymbol->setIsFunction(true);
              funcSymbol->setIsFunctionDefined(true);
              funcSymbol->setReturnType(antlrcpp::downCast<Func_definitionContext *>(_localctx)->ts->text);


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


           
      setState(100);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->rparenToken = match(C2105168Parser::RPAREN);
          
              writeIntoAsmFile(antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getText() + " PROC");
              writeIntoAsmFile("\tMOV AX, @DATA\n\tMOV DS, AX\n\tPUSH BP\n\tMOV BP, SP");

          
      setState(102);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->cs = compound_statement();
        


              antlrcpp::downCast<Func_definitionContext *>(_localctx)->text =  antlrcpp::downCast<Func_definitionContext *>(_localctx)->ts->text+" "  + antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getText() +  antlrcpp::downCast<Func_definitionContext *>(_localctx)->lparenToken->getText()+ antlrcpp::downCast<Func_definitionContext *>(_localctx)->pl->text + antlrcpp::downCast<Func_definitionContext *>(_localctx)->rparenToken->getText() + antlrcpp::downCast<Func_definitionContext *>(_localctx)->cs->text;
              antlrcpp::downCast<Func_definitionContext *>(_localctx)->line =  antlrcpp::downCast<Func_definitionContext *>(_localctx)->cs->line;
              antlrcpp::downCast<Func_definitionContext *>(_localctx)->type =  antlrcpp::downCast<Func_definitionContext *>(_localctx)->ts->text;
              antlrcpp::downCast<Func_definitionContext *>(_localctx)->returnType =  antlrcpp::downCast<Func_definitionContext *>(_localctx)->cs->type;

              if (antlrcpp::downCast<Func_definitionContext *>(_localctx)->ts->text == "void" && _localctx->returnType != "void") {
                  writeIntoErrorFile("Error at line " + std::to_string(_localctx->line) + ": Cannot return value from function "+  antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getText() + " with void return type\n");
                   writeIntoparserLogFile("Error at line " + std::to_string(_localctx->line) + ": Cannot return value from function "+  antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getText() + " with void return type\n");
                  errorCount++;
              } 

              writeIntoAsmFile("\tMOV AX, 4CH\n\tINT 21H");
              writeIntoAsmFile(antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getText()+ " ENDP");
              
              writeIntoparserLogFile("\nLine "+std::to_string(_localctx->line)+": func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement\n\n"+_localctx->text+"\n");
       

          
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(105);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->ts = type_specifier();
      setState(106);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken = match(C2105168Parser::ID);
      setState(107);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->lparenToken = match(C2105168Parser::LPAREN);
      setState(108);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->rparenToken = match(C2105168Parser::RPAREN);
          
              writeIntoAsmFile(antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getText() + " PROC");
               writeIntoAsmFile("\tMOV AX, @DATA\n\tMOV DS, AX\n\tPUSH BP\n\tMOV BP, SP");

          
       

              SymbolInfo* funcSymbol = new SymbolInfo(antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getText(), "ID");
              funcSymbol->setIsFunction(true);
              funcSymbol->setReturnType(antlrcpp::downCast<Func_definitionContext *>(_localctx)->ts->text);

              SymbolInfo* existing = symbolTable->LookUP(antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getText());
              if (existing && existing->getIsFunction() && existing->getIsFunctionDefined()) {
                 // writeIntoparserLogFile("Error at line " + std::to_string(_localctx->line) + ": Multiple definition of function " + antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getText());
              } else {
                  symbolTable->Insert(funcSymbol);
                  funcSymbol->setIsFunctionDefined(true);

              }

              
      setState(111);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->cs = compound_statement();
       

              antlrcpp::downCast<Func_definitionContext *>(_localctx)->text =  antlrcpp::downCast<Func_definitionContext *>(_localctx)->ts->text +" " + antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getText() +  antlrcpp::downCast<Func_definitionContext *>(_localctx)->lparenToken->getText() + antlrcpp::downCast<Func_definitionContext *>(_localctx)->rparenToken->getText() + antlrcpp::downCast<Func_definitionContext *>(_localctx)->cs->text;
              antlrcpp::downCast<Func_definitionContext *>(_localctx)->line =  antlrcpp::downCast<Func_definitionContext *>(_localctx)->cs->line;
              std::cout << "DEBUG: func_declaration code_section = '" << _localctx->code_section << "'" << std::endl;

              writeIntoAsmFile("\tMOV AX, 4CH\n\tINT 21H");

              writeIntoAsmFile(antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getText()+ " ENDP");

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
    setState(130);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
    case 1: {
      setState(117);
      antlrcpp::downCast<Parameter_listContext *>(_localctx)->ts = type_specifier();
      setState(118);
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
      setState(121);
      antlrcpp::downCast<Parameter_listContext *>(_localctx)->ts = type_specifier();
      setState(122);
      antlrcpp::downCast<Parameter_listContext *>(_localctx)->addopToken = match(C2105168Parser::ADDOP);

              antlrcpp::downCast<Parameter_listContext *>(_localctx)->text =  antlrcpp::downCast<Parameter_listContext *>(_localctx)->ts->text;
              antlrcpp::downCast<Parameter_listContext *>(_localctx)->line =  antlrcpp::downCast<Parameter_listContext *>(_localctx)->addopToken->getLine();
              writeIntoErrorFile("Error at line " + std::to_string(_localctx->line) + ": syntax error, unexpected ADDOP, expecting RPAREN or COMMA\n");
              writeIntoparserLogFile("Error at line " + std::to_string(_localctx->line) + ": syntax error, unexpected ADDOP, expecting RPAREN or COMMA\n");
              
      break;
    }

    case 3: {
      setState(125);
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
      setState(128);
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
    setState(149);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(147);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<Parameter_listContext>(parentContext, parentState);
          _localctx->pl = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleParameter_list);
          setState(132);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(133);
          antlrcpp::downCast<Parameter_listContext *>(_localctx)->commaToken = match(C2105168Parser::COMMA);
          setState(134);
          antlrcpp::downCast<Parameter_listContext *>(_localctx)->ts = type_specifier();
          setState(135);
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
          setState(138);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(139);
          antlrcpp::downCast<Parameter_listContext *>(_localctx)->commaToken = match(C2105168Parser::COMMA);
          setState(140);
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
          setState(143);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(144);
          antlrcpp::downCast<Parameter_listContext *>(_localctx)->commaToken = match(C2105168Parser::COMMA);
          setState(145);
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
      setState(151);
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
    setState(163);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(152);
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
              
               
      setState(154);
      antlrcpp::downCast<Compound_statementContext *>(_localctx)->ss = statements(0);
       
              // std::cout << "ss  type"<<antlrcpp::downCast<Compound_statementContext *>(_localctx)->ss->type <<std::endl;
              antlrcpp::downCast<Compound_statementContext *>(_localctx)->type =  antlrcpp::downCast<Compound_statementContext *>(_localctx)->ss->type;
          
      setState(156);
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
      setState(159);
      antlrcpp::downCast<Compound_statementContext *>(_localctx)->lcurlToken = match(C2105168Parser::LCURL);
      symbolTable->EnterScope();
      setState(161);
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
    setState(175);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(165);
      antlrcpp::downCast<Var_declarationContext *>(_localctx)->t = type_specifier();
      setState(166);
      antlrcpp::downCast<Var_declarationContext *>(_localctx)->dl = declaration_list(0);
      setState(167);
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


                  std::string currentScopeId = symbolTable->getCurrentScopeID();

                  if(currentScopeId == "1"){

                      isDATAEmpty = false;
                      
                      stack_offset_global += 2;
                      varSymbol->setStackOffset(stack_offset_global);
                      varSymbol->setIsGlobal(true);
                      _localctx->data_section_code+="\t"+varSymbol->getSymbolName()+" DW 1 DUP (0000H)\n";

                      std::cout << "data_section_code: " << _localctx->data_section_code << std::endl;
                  }


                  else if(currentScopeId !="1" ){
                      if(!pushbpprint){
                          pushbpprint = true;
                      }
                      stack_offset_local += 2;
                      varSymbol->setStackOffset(stack_offset_local);
                      _localctx->code_section += "\tSUB SP, 2\n";

                  }

              }
                          std::string currentScopeId = symbolTable->getCurrentScopeID();

              if(currentScopeId == "1"){
                      writeIntoAsmFile(_localctx->data_section_code+".CODE");
              }
               writeIntoAsmFile(_localctx->code_section);




              if(antlrcpp::downCast<Var_declarationContext *>(_localctx)->t->text == "void"){
                  writeIntoparserLogFile("Error at line "+std::to_string(_localctx->line)+":  Variable type cannot be void\n");
                  writeIntoErrorFile("Error at line "+std::to_string(_localctx->line)+": Variable type cannot be void\n");
                                  errorCount++;
              }

              

              
            
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(170);
      antlrcpp::downCast<Var_declarationContext *>(_localctx)->t = type_specifier();
      setState(171);
      antlrcpp::downCast<Var_declarationContext *>(_localctx)->de = declaration_list_err();
      setState(172);
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
    setState(185);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case C2105168Parser::INT: {
        enterOuterAlt(_localctx, 1);
        setState(179);
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
        setState(181);
        antlrcpp::downCast<Type_specifierContext *>(_localctx)->floatToken = match(C2105168Parser::FLOAT);

                    antlrcpp::downCast<Type_specifierContext *>(_localctx)->text =  antlrcpp::downCast<Type_specifierContext *>(_localctx)->floatToken->getText();
                    antlrcpp::downCast<Type_specifierContext *>(_localctx)->line =  antlrcpp::downCast<Type_specifierContext *>(_localctx)->floatToken->getLine();
                    antlrcpp::downCast<Type_specifierContext *>(_localctx)->type =  "float";
        			writeIntoparserLogFile("Line " + std::to_string(antlrcpp::downCast<Type_specifierContext *>(_localctx)->floatToken->getLine()) + ": type_specifier : FLOAT\n\n" +antlrcpp::downCast<Type_specifierContext *>(_localctx)->floatToken->getText() + "\n");        
        		
        break;
      }

      case C2105168Parser::VOID: {
        enterOuterAlt(_localctx, 3);
        setState(183);
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
    setState(200);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx)) {
    case 1: {
      setState(188);
      antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken = match(C2105168Parser::ID);
       
              antlrcpp::downCast<Declaration_listContext *>(_localctx)->text =  antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken->getText();
              antlrcpp::downCast<Declaration_listContext *>(_localctx)->line =  antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken->getLine();
              _localctx->varList.push_back(std::make_pair(antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken->getText(), false));
              writeIntoparserLogFile("Line " + std::to_string(_localctx->line) + ": declaration_list : ID\n\n" +_localctx->text + "\n");        

          
      break;
    }

    case 2: {
      setState(190);
      antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken = match(C2105168Parser::ID);
      setState(191);
      antlrcpp::downCast<Declaration_listContext *>(_localctx)->lthirdToken = match(C2105168Parser::LTHIRD);
      setState(192);
      antlrcpp::downCast<Declaration_listContext *>(_localctx)->const_intToken = match(C2105168Parser::CONST_INT);
      setState(193);
      antlrcpp::downCast<Declaration_listContext *>(_localctx)->rthirdToken = match(C2105168Parser::RTHIRD);
       
              antlrcpp::downCast<Declaration_listContext *>(_localctx)->text =  antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken->getText() + antlrcpp::downCast<Declaration_listContext *>(_localctx)->lthirdToken->getText() + antlrcpp::downCast<Declaration_listContext *>(_localctx)->const_intToken->getText() + antlrcpp::downCast<Declaration_listContext *>(_localctx)->rthirdToken->getText();
              antlrcpp::downCast<Declaration_listContext *>(_localctx)->line =  antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken->getLine();

              antlrcpp::downCast<Declaration_listContext *>(_localctx)->type =  "array";
              _localctx->varList.push_back(std::make_pair(antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken->getText(), true));

              
              writeIntoparserLogFile("Line " + std::to_string(_localctx->line) + ": declaration_list : ID LTHIRD CONST_INT RTHIRD\n\n" +_localctx->text + "\n");        

          
      break;
    }

    case 3: {
      setState(195);
      antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken = match(C2105168Parser::ID);
      setState(196);
      antlrcpp::downCast<Declaration_listContext *>(_localctx)->addopToken = match(C2105168Parser::ADDOP);
      setState(197);
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
    setState(220);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(218);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<Declaration_listContext>(parentContext, parentState);
          _localctx->dl = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleDeclaration_list);
          setState(202);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(203);
          antlrcpp::downCast<Declaration_listContext *>(_localctx)->commaToken = match(C2105168Parser::COMMA);
          setState(204);
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
          setState(206);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(207);
          antlrcpp::downCast<Declaration_listContext *>(_localctx)->commaToken = match(C2105168Parser::COMMA);
          setState(208);
          antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken = match(C2105168Parser::ID);
          setState(209);
          antlrcpp::downCast<Declaration_listContext *>(_localctx)->lthirdToken = match(C2105168Parser::LTHIRD);
          setState(210);
          antlrcpp::downCast<Declaration_listContext *>(_localctx)->const_intToken = match(C2105168Parser::CONST_INT);
          setState(211);
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
          setState(213);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(214);
          antlrcpp::downCast<Declaration_listContext *>(_localctx)->commaToken = match(C2105168Parser::COMMA);
          setState(215);
          antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken = match(C2105168Parser::ID);
          setState(216);
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
      setState(222);
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
    setState(224);
    antlrcpp::downCast<StatementsContext *>(_localctx)->s = statement();

            antlrcpp::downCast<StatementsContext *>(_localctx)->text =  antlrcpp::downCast<StatementsContext *>(_localctx)->s->text;
            antlrcpp::downCast<StatementsContext *>(_localctx)->line =  antlrcpp::downCast<StatementsContext *>(_localctx)->s->line;
            antlrcpp::downCast<StatementsContext *>(_localctx)->type =  antlrcpp::downCast<StatementsContext *>(_localctx)->s->type;
            antlrcpp::downCast<StatementsContext *>(_localctx)->code_section =  antlrcpp::downCast<StatementsContext *>(_localctx)->s->code_section;
                    // std::cout << "s  type"<<antlrcpp::downCast<StatementsContext *>(_localctx)->s->type <<std::endl;

            writeIntoparserLogFile("Line " + std::to_string(_localctx->line) + ": statements : statement\n\n" + _localctx->text+"\n"); 
        
    _ctx->stop = _input->LT(-1);
    setState(233);
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
        setState(227);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(228);
        antlrcpp::downCast<StatementsContext *>(_localctx)->s = statement();

                          antlrcpp::downCast<StatementsContext *>(_localctx)->text =  antlrcpp::downCast<StatementsContext *>(_localctx)->ss->text +"\n" + antlrcpp::downCast<StatementsContext *>(_localctx)->s->text;
                          antlrcpp::downCast<StatementsContext *>(_localctx)->line =  antlrcpp::downCast<StatementsContext *>(_localctx)->s->line;
                          antlrcpp::downCast<StatementsContext *>(_localctx)->type =  antlrcpp::downCast<StatementsContext *>(_localctx)->s->type;
                          antlrcpp::downCast<StatementsContext *>(_localctx)->code_section =  antlrcpp::downCast<StatementsContext *>(_localctx)->ss->code_section +  antlrcpp::downCast<StatementsContext *>(_localctx)->s->code_section;  
                                  // std::cout << "s  type"<<antlrcpp::downCast<StatementsContext *>(_localctx)->s->type <<std::endl;

                          writeIntoparserLogFile("Line " + std::to_string(_localctx->line) + ": statements : statements statement\n\n" +_localctx->text+"\n"); 

                       
      }
      setState(235);
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
    setState(288);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(236);
      antlrcpp::downCast<StatementContext *>(_localctx)->v = var_declaration();

              antlrcpp::downCast<StatementContext *>(_localctx)->text =  antlrcpp::downCast<StatementContext *>(_localctx)->v->text;
              antlrcpp::downCast<StatementContext *>(_localctx)->line =  antlrcpp::downCast<StatementContext *>(_localctx)->v->line;
              std::cout << "DEBUG: unit var_declaration code_section = '" << _localctx->code_section << "'" << std::endl;
              antlrcpp::downCast<StatementContext *>(_localctx)->type =  "void";
              writeIntoparserLogFile("Line "+  std::to_string(_localctx->line) +": statement : var_declaration\n\n"+_localctx->text + "\n" );
          
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(239);
      antlrcpp::downCast<StatementContext *>(_localctx)->es = expression_statement();

              antlrcpp::downCast<StatementContext *>(_localctx)->text =  antlrcpp::downCast<StatementContext *>(_localctx)->es->text;
              antlrcpp::downCast<StatementContext *>(_localctx)->line =  antlrcpp::downCast<StatementContext *>(_localctx)->es->line;
              antlrcpp::downCast<StatementContext *>(_localctx)->type =  "void";
              writeIntoparserLogFile("Line "+  std::to_string(_localctx->line) +": statement : expression_statement\n\n"+_localctx->text + "\n" );

          
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(242);
      antlrcpp::downCast<StatementContext *>(_localctx)->cs = compound_statement();

              antlrcpp::downCast<StatementContext *>(_localctx)->text =  antlrcpp::downCast<StatementContext *>(_localctx)->cs->text;
              antlrcpp::downCast<StatementContext *>(_localctx)->line =  antlrcpp::downCast<StatementContext *>(_localctx)->cs->line;
              antlrcpp::downCast<StatementContext *>(_localctx)->type =  antlrcpp::downCast<StatementContext *>(_localctx)->cs->type;
              antlrcpp::downCast<StatementContext *>(_localctx)->type =  "void";

              writeIntoparserLogFile("Line "+  std::to_string(_localctx->line) +": statement : compound_statement\n\n"+_localctx->text + "\n" );

          
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(245);
      antlrcpp::downCast<StatementContext *>(_localctx)->forToken = match(C2105168Parser::FOR);
      setState(246);
      antlrcpp::downCast<StatementContext *>(_localctx)->lparenToken = match(C2105168Parser::LPAREN);
      setState(247);
      antlrcpp::downCast<StatementContext *>(_localctx)->es1 = expression_statement();
      setState(248);
      antlrcpp::downCast<StatementContext *>(_localctx)->es2 = expression_statement();
      setState(249);
      antlrcpp::downCast<StatementContext *>(_localctx)->e = expression();
      setState(250);
      antlrcpp::downCast<StatementContext *>(_localctx)->rparenToken = match(C2105168Parser::RPAREN);
      setState(251);
      antlrcpp::downCast<StatementContext *>(_localctx)->s = statement();

              antlrcpp::downCast<StatementContext *>(_localctx)->text =  (antlrcpp::downCast<StatementContext *>(_localctx)->forToken != nullptr ? antlrcpp::downCast<StatementContext *>(_localctx)->forToken->getText() : "") +  antlrcpp::downCast<StatementContext *>(_localctx)->lparenToken->getText() +  antlrcpp::downCast<StatementContext *>(_localctx)->es1->text + antlrcpp::downCast<StatementContext *>(_localctx)->es2->text + antlrcpp::downCast<StatementContext *>(_localctx)->e->text   + antlrcpp::downCast<StatementContext *>(_localctx)->rparenToken->getText() + antlrcpp::downCast<StatementContext *>(_localctx)->s->text;
              antlrcpp::downCast<StatementContext *>(_localctx)->line =  antlrcpp::downCast<StatementContext *>(_localctx)->s->line;
              antlrcpp::downCast<StatementContext *>(_localctx)->type =  "void";

              writeIntoparserLogFile("Line " + std::to_string(antlrcpp::downCast<StatementContext *>(_localctx)->s->line) + ": statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement\n\n" + _localctx->text +"\n"); 

          
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(254);
      antlrcpp::downCast<StatementContext *>(_localctx)->ifToken = match(C2105168Parser::IF);
      setState(255);
      antlrcpp::downCast<StatementContext *>(_localctx)->lparenToken = match(C2105168Parser::LPAREN);
      setState(256);
      antlrcpp::downCast<StatementContext *>(_localctx)->e = expression();
      setState(257);
      antlrcpp::downCast<StatementContext *>(_localctx)->rparenToken = match(C2105168Parser::RPAREN);
      setState(258);
      antlrcpp::downCast<StatementContext *>(_localctx)->s = statement();


              antlrcpp::downCast<StatementContext *>(_localctx)->text =  antlrcpp::downCast<StatementContext *>(_localctx)->ifToken->getText()+ antlrcpp::downCast<StatementContext *>(_localctx)->lparenToken->getText()+ antlrcpp::downCast<StatementContext *>(_localctx)->e->text  + antlrcpp::downCast<StatementContext *>(_localctx)->rparenToken->getText() +antlrcpp::downCast<StatementContext *>(_localctx)->s->text;
              antlrcpp::downCast<StatementContext *>(_localctx)->line =  antlrcpp::downCast<StatementContext *>(_localctx)->ifToken->getLine();
              antlrcpp::downCast<StatementContext *>(_localctx)->type =  "void";

              writeIntoparserLogFile("Line " + std::to_string(_localctx->line) + ": statement : IF LPAREN expression RPAREN statement\n\n" + _localctx->text +"\n"); 

          
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(261);
      antlrcpp::downCast<StatementContext *>(_localctx)->ifToken = match(C2105168Parser::IF);
      setState(262);
      antlrcpp::downCast<StatementContext *>(_localctx)->lparenToken = match(C2105168Parser::LPAREN);
      setState(263);
      antlrcpp::downCast<StatementContext *>(_localctx)->e = expression();
      setState(264);
      antlrcpp::downCast<StatementContext *>(_localctx)->rparenToken = match(C2105168Parser::RPAREN);
      setState(265);
      antlrcpp::downCast<StatementContext *>(_localctx)->s1 = statement();
      setState(266);
      antlrcpp::downCast<StatementContext *>(_localctx)->elseToken = match(C2105168Parser::ELSE);
      setState(267);
      antlrcpp::downCast<StatementContext *>(_localctx)->s2 = statement();

              antlrcpp::downCast<StatementContext *>(_localctx)->text =  antlrcpp::downCast<StatementContext *>(_localctx)->ifToken->getText() + antlrcpp::downCast<StatementContext *>(_localctx)->lparenToken->getText() + antlrcpp::downCast<StatementContext *>(_localctx)->e->text  + antlrcpp::downCast<StatementContext *>(_localctx)->rparenToken->getText() + antlrcpp::downCast<StatementContext *>(_localctx)->s1->text+ antlrcpp::downCast<StatementContext *>(_localctx)->elseToken->getText() +" "+  antlrcpp::downCast<StatementContext *>(_localctx)->s2->text ;
             antlrcpp::downCast<StatementContext *>(_localctx)->line =  antlrcpp::downCast<StatementContext *>(_localctx)->ifToken->getLine();
              antlrcpp::downCast<StatementContext *>(_localctx)->type =  "void";

              writeIntoparserLogFile("Line " + std::to_string(_localctx->line) + ": statement : IF LPAREN expression RPAREN statement ELSE statement\n\n" + _localctx->text +"\n"); 

          
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(270);
      antlrcpp::downCast<StatementContext *>(_localctx)->whileToken = match(C2105168Parser::WHILE);
      setState(271);
      antlrcpp::downCast<StatementContext *>(_localctx)->lparenToken = match(C2105168Parser::LPAREN);
      setState(272);
      antlrcpp::downCast<StatementContext *>(_localctx)->e = expression();
      setState(273);
      antlrcpp::downCast<StatementContext *>(_localctx)->rparenToken = match(C2105168Parser::RPAREN);
      setState(274);
      antlrcpp::downCast<StatementContext *>(_localctx)->s = statement();

              antlrcpp::downCast<StatementContext *>(_localctx)->text =  antlrcpp::downCast<StatementContext *>(_localctx)->whileToken->getText() + antlrcpp::downCast<StatementContext *>(_localctx)->lparenToken->getText() + antlrcpp::downCast<StatementContext *>(_localctx)->e->text  + antlrcpp::downCast<StatementContext *>(_localctx)->rparenToken->getText() + antlrcpp::downCast<StatementContext *>(_localctx)->s->text;
              antlrcpp::downCast<StatementContext *>(_localctx)->line =  antlrcpp::downCast<StatementContext *>(_localctx)->s->line;
              antlrcpp::downCast<StatementContext *>(_localctx)->type =  "void";

              writeIntoparserLogFile("Line " + std::to_string(_localctx->line) + ": statement : WHILE LPAREN expression RPAREN statement\n\n" + _localctx->text +"\n"); 

          
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(277);
      antlrcpp::downCast<StatementContext *>(_localctx)->printlnToken = match(C2105168Parser::PRINTLN);
      setState(278);
      antlrcpp::downCast<StatementContext *>(_localctx)->lparenToken = match(C2105168Parser::LPAREN);
      setState(279);
      antlrcpp::downCast<StatementContext *>(_localctx)->idToken = match(C2105168Parser::ID);
      setState(280);
      antlrcpp::downCast<StatementContext *>(_localctx)->rparenToken = match(C2105168Parser::RPAREN);
      setState(281);
      antlrcpp::downCast<StatementContext *>(_localctx)->semicolonToken = match(C2105168Parser::SEMICOLON);


              antlrcpp::downCast<StatementContext *>(_localctx)->text =  antlrcpp::downCast<StatementContext *>(_localctx)->printlnToken->getText() + antlrcpp::downCast<StatementContext *>(_localctx)->lparenToken->getText() +  antlrcpp::downCast<StatementContext *>(_localctx)->idToken->getText() +  antlrcpp::downCast<StatementContext *>(_localctx)->rparenToken->getText() +  antlrcpp::downCast<StatementContext *>(_localctx)->semicolonToken->getText();
              antlrcpp::downCast<StatementContext *>(_localctx)->line =  antlrcpp::downCast<StatementContext *>(_localctx)->semicolonToken->getLine();

              antlrcpp::downCast<StatementContext *>(_localctx)->type =  "void";

              SymbolInfo* lookup = symbolTable->LookUP(antlrcpp::downCast<StatementContext *>(_localctx)->idToken->getText());
              SymbolInfo* existing = symbolTable->LookUP(antlrcpp::downCast<StatementContext *>(_localctx)->idToken->getText());
                  std::string currentScopeId = symbolTable->getCurrentScopeID();
                  if(existing->getIsGlobal()){
                      antlrcpp::downCast<StatementContext *>(_localctx)->code_section =  "\tMOV AX, "+ antlrcpp::downCast<StatementContext *>(_localctx)->idToken->getText();
                  } else {
                      antlrcpp::downCast<StatementContext *>(_localctx)->code_section =  "\tMOV AX, [BP-" + std::to_string(existing->getStackOffset()) + "]";
                  }

              writeIntoAsmFile("L" + std::to_string(label_count++)+":");
              writeIntoAsmFile(_localctx->code_section+"       ; Line "+std::to_string(_localctx->line));
              writeIntoAsmFile("\tCALL print_output");
              writeIntoAsmFile("\tCALL new_line");

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
      setState(283);
      antlrcpp::downCast<StatementContext *>(_localctx)->returnToken = match(C2105168Parser::RETURN);
      setState(284);
      antlrcpp::downCast<StatementContext *>(_localctx)->e = expression();
      setState(285);
      antlrcpp::downCast<StatementContext *>(_localctx)->semicolonToken = match(C2105168Parser::SEMICOLON);

              antlrcpp::downCast<StatementContext *>(_localctx)->text =  antlrcpp::downCast<StatementContext *>(_localctx)->returnToken->getText() + " " + antlrcpp::downCast<StatementContext *>(_localctx)->e->text + antlrcpp::downCast<StatementContext *>(_localctx)->semicolonToken->getText();
              antlrcpp::downCast<StatementContext *>(_localctx)->line =  antlrcpp::downCast<StatementContext *>(_localctx)->returnToken->getLine();
              
              antlrcpp::downCast<StatementContext *>(_localctx)->type =  antlrcpp::downCast<StatementContext *>(_localctx)->e->type;




              SymbolInfo* lookup = symbolTable->LookUP(antlrcpp::downCast<StatementContext *>(_localctx)->e->text);


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
    setState(296);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case C2105168Parser::SEMICOLON: {
        enterOuterAlt(_localctx, 1);
        setState(290);
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
        setState(292);
        antlrcpp::downCast<Expression_statementContext *>(_localctx)->e = expression();
        setState(293);
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
    setState(306);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(298);
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
      setState(300);
      antlrcpp::downCast<VariableContext *>(_localctx)->idToken = match(C2105168Parser::ID);
      setState(301);
      antlrcpp::downCast<VariableContext *>(_localctx)->lthirdToken = match(C2105168Parser::LTHIRD);
      setState(302);
      antlrcpp::downCast<VariableContext *>(_localctx)->e = expression();
      setState(303);
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
    setState(316);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(308);
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
      setState(311);
      antlrcpp::downCast<ExpressionContext *>(_localctx)->v = variable();
      setState(312);
      antlrcpp::downCast<ExpressionContext *>(_localctx)->assignopToken = match(C2105168Parser::ASSIGNOP);
      setState(313);
      antlrcpp::downCast<ExpressionContext *>(_localctx)->le = logic_expression();

                  antlrcpp::downCast<ExpressionContext *>(_localctx)->text =  antlrcpp::downCast<ExpressionContext *>(_localctx)->v->text + antlrcpp::downCast<ExpressionContext *>(_localctx)->assignopToken->getText() + antlrcpp::downCast<ExpressionContext *>(_localctx)->le->text;
                  antlrcpp::downCast<ExpressionContext *>(_localctx)->line = antlrcpp::downCast<ExpressionContext *>(_localctx)->le->line;  
                  antlrcpp::downCast<ExpressionContext *>(_localctx)->type =  antlrcpp::downCast<ExpressionContext *>(_localctx)->le->type;
                  antlrcpp::downCast<ExpressionContext *>(_localctx)->argIsArray =  false;

                  SymbolInfo* existing = symbolTable->LookUP(antlrcpp::downCast<ExpressionContext *>(_localctx)->v->text);
                  std::string currentScopeId = symbolTable->getCurrentScopeID();
                  if(existing->getIsGlobal()){
                      antlrcpp::downCast<ExpressionContext *>(_localctx)->code_section =  "\tMOV " + antlrcpp::downCast<ExpressionContext *>(_localctx)->v->text + ", AX";
                  } else {
                      antlrcpp::downCast<ExpressionContext *>(_localctx)->code_section =  "\tMOV [BP-" + std::to_string(existing->getStackOffset()) + "], AX";
                  }

                              writeIntoAsmFile("\tPOP AX");

                  writeIntoAsmFile(_localctx->code_section);


                  
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
    setState(326);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(318);
      antlrcpp::downCast<Logic_expressionContext *>(_localctx)->r = rel_expression();

                  antlrcpp::downCast<Logic_expressionContext *>(_localctx)->text =  antlrcpp::downCast<Logic_expressionContext *>(_localctx)->r->text;
                  antlrcpp::downCast<Logic_expressionContext *>(_localctx)->line =  antlrcpp::downCast<Logic_expressionContext *>(_localctx)->r->line;
                  antlrcpp::downCast<Logic_expressionContext *>(_localctx)->type =  antlrcpp::downCast<Logic_expressionContext *>(_localctx)->r->type;
                  antlrcpp::downCast<Logic_expressionContext *>(_localctx)->argIsArr =  antlrcpp::downCast<Logic_expressionContext *>(_localctx)->r->argIsArray;
                  // std::cout << "r  type"<<antlrcpp::downCast<Logic_expressionContext *>(_localctx)->r->type <<std::endl;

                  writeIntoparserLogFile("Line "+  std::to_string(antlrcpp::downCast<Logic_expressionContext *>(_localctx)->r->line)+": logic_expression : rel_expression\n\n" + antlrcpp::downCast<Logic_expressionContext *>(_localctx)->r->text + "\n"); 

              
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(321);
      antlrcpp::downCast<Logic_expressionContext *>(_localctx)->re1 = rel_expression();
      setState(322);
      antlrcpp::downCast<Logic_expressionContext *>(_localctx)->logicopToken = match(C2105168Parser::LOGICOP);
      setState(323);
      antlrcpp::downCast<Logic_expressionContext *>(_localctx)->re2 = rel_expression();

                  antlrcpp::downCast<Logic_expressionContext *>(_localctx)->text =  antlrcpp::downCast<Logic_expressionContext *>(_localctx)->re1->text+antlrcpp::downCast<Logic_expressionContext *>(_localctx)->logicopToken->getText() + antlrcpp::downCast<Logic_expressionContext *>(_localctx)->re2->text;
                  antlrcpp::downCast<Logic_expressionContext *>(_localctx)->line =  antlrcpp::downCast<Logic_expressionContext *>(_localctx)->re2->line;
                  antlrcpp::downCast<Logic_expressionContext *>(_localctx)->type =  antlrcpp::downCast<Logic_expressionContext *>(_localctx)->re2->type;
                  antlrcpp::downCast<Logic_expressionContext *>(_localctx)->argIsArr =  false;
                  int labelEnd = 0;

               writeIntoAsmFile("\tPOP DX");  
                writeIntoAsmFile("\tPOP AX");  
          
          if (antlrcpp::downCast<Logic_expressionContext *>(_localctx)->logicopToken->getText() == "&&") {
              int labelFalse = label_count++;
              labelEnd = label_count++;
              
              writeIntoAsmFile("\tCMP AX, 0\n\tJE L" + std::to_string(labelFalse));  
              writeIntoAsmFile("\tCMP DX, 0\n\tJE L" + std::to_string(labelFalse));  
              
              writeIntoAsmFile("\tMOV AX, 1\n\tJMP L" + std::to_string(labelEnd));
              
              writeIntoAsmFile("L" + std::to_string(labelFalse) + ":");
              writeIntoAsmFile("\tMOV AX, 0");
              
          } else if (antlrcpp::downCast<Logic_expressionContext *>(_localctx)->logicopToken->getText() == "||") {
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
    setState(336);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(328);
      antlrcpp::downCast<Rel_expressionContext *>(_localctx)->s = simple_expression(0);

                  antlrcpp::downCast<Rel_expressionContext *>(_localctx)->text =  antlrcpp::downCast<Rel_expressionContext *>(_localctx)->s->text;
                  antlrcpp::downCast<Rel_expressionContext *>(_localctx)->line =  antlrcpp::downCast<Rel_expressionContext *>(_localctx)->s->line;
                  antlrcpp::downCast<Rel_expressionContext *>(_localctx)->type =  antlrcpp::downCast<Rel_expressionContext *>(_localctx)->s->type;
                  antlrcpp::downCast<Rel_expressionContext *>(_localctx)->argIsArray =  antlrcpp::downCast<Rel_expressionContext *>(_localctx)->s->argIsArray;
                  // std::cout << "s type"<<antlrcpp::downCast<Rel_expressionContext *>(_localctx)->s->type <<std::endl;
                  writeIntoparserLogFile("Line "+  std::to_string(antlrcpp::downCast<Rel_expressionContext *>(_localctx)->s->line)+": rel_expression : simple_expression\n\n" + antlrcpp::downCast<Rel_expressionContext *>(_localctx)->s->text + "\n"); 
                  
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(331);
      antlrcpp::downCast<Rel_expressionContext *>(_localctx)->s1 = simple_expression(0);
      setState(332);
      antlrcpp::downCast<Rel_expressionContext *>(_localctx)->relopToken = match(C2105168Parser::RELOP);
      setState(333);
      antlrcpp::downCast<Rel_expressionContext *>(_localctx)->s2 = simple_expression(0);

                  antlrcpp::downCast<Rel_expressionContext *>(_localctx)->text =  antlrcpp::downCast<Rel_expressionContext *>(_localctx)->s1->text + antlrcpp::downCast<Rel_expressionContext *>(_localctx)->relopToken->getText() + antlrcpp::downCast<Rel_expressionContext *>(_localctx)->s2->text;
                  antlrcpp::downCast<Rel_expressionContext *>(_localctx)->line =  antlrcpp::downCast<Rel_expressionContext *>(_localctx)->relopToken->getLine();
                  antlrcpp::downCast<Rel_expressionContext *>(_localctx)->type =  antlrcpp::downCast<Rel_expressionContext *>(_localctx)->s2->type;
                  antlrcpp::downCast<Rel_expressionContext *>(_localctx)->argIsArray =  false;
                  int labelEnd = 0;

                  writeIntoAsmFile("\tPOP DX");
                  writeIntoAsmFile("\tPOP AX");
                  if (antlrcpp::downCast<Rel_expressionContext *>(_localctx)->relopToken->getText() == "==") {
                      int labelTrue = label_count++;
                      int labelFalse = label_count++;
                      labelEnd = label_count++;
                      writeIntoAsmFile("\tCMP AX, DX\n\tJE L" + std::to_string(labelTrue));
                      writeIntoAsmFile("\tJMP L" + std::to_string(labelFalse));
                      writeIntoAsmFile("L" + std::to_string(labelTrue) + ":");
                      writeIntoAsmFile("\tMOV AX, 1\n\tJMP L" + std::to_string(labelEnd));
                      writeIntoAsmFile("L" + std::to_string(labelFalse) + ":");
                      writeIntoAsmFile("\tMOV AX, 0");

                  } else if (antlrcpp::downCast<Rel_expressionContext *>(_localctx)->relopToken->getText() == "!=") {
                      int labelTrue = label_count++;
                      int labelFalse = label_count++;
                      labelEnd = label_count++;
                      writeIntoAsmFile("\tCMP AX, DX\n\tJNE L" + std::to_string(labelTrue));
                      writeIntoAsmFile("\tJMP L" + std::to_string(labelFalse));
                      writeIntoAsmFile("L" + std::to_string(labelTrue) + ":");
                      writeIntoAsmFile("\tMOV AX, 1\n\tJMP L" + std::to_string(labelEnd));
                      writeIntoAsmFile("L" + std::to_string(labelFalse) + ":");
                      writeIntoAsmFile("\tMOV AX, 0");
                    } else if (antlrcpp::downCast<Rel_expressionContext *>(_localctx)->relopToken->getText() == "<") {
                      int labelTrue = label_count++;
                      int labelFalse = label_count++;
                      labelEnd = label_count++;
                      writeIntoAsmFile("\tCMP AX, DX\n\tJL L" + std::to_string(labelTrue));
                      writeIntoAsmFile("\tJMP L" + std::to_string(labelFalse));
                      writeIntoAsmFile("L" + std::to_string(labelTrue) + ":");
                      writeIntoAsmFile("\tMOV AX, 1\n\tJMP L" + std::to_string(labelEnd));
                      writeIntoAsmFile("L" + std::to_string(labelFalse) + ":");
                      writeIntoAsmFile("\tMOV AX, 0");
                  } else if (antlrcpp::downCast<Rel_expressionContext *>(_localctx)->relopToken->getText() == ">") {
                      int labelTrue = label_count++;
                      int labelFalse = label_count++;
                      labelEnd = label_count++;
                      writeIntoAsmFile("\tCMP AX, DX\n\tJG L" + std::to_string(labelTrue));
                      writeIntoAsmFile("\tJMP L" + std::to_string(labelFalse));
                      writeIntoAsmFile("L" + std::to_string(labelTrue) + ":");
                      writeIntoAsmFile("\tMOV AX, 1\n\tJMP L" + std::to_string(labelEnd));
                      writeIntoAsmFile("L" + std::to_string(labelFalse) + ":");
                      writeIntoAsmFile("\tMOV AX, 0");
                  } else if (antlrcpp::downCast<Rel_expressionContext *>(_localctx)->relopToken->getText() == "<=") {
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
                  else if (antlrcpp::downCast<Rel_expressionContext *>(_localctx)->relopToken->getText() == ">=") {
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
    setState(339);
    antlrcpp::downCast<Simple_expressionContext *>(_localctx)->t = term(0);

                antlrcpp::downCast<Simple_expressionContext *>(_localctx)->text =  antlrcpp::downCast<Simple_expressionContext *>(_localctx)->t->text;
                antlrcpp::downCast<Simple_expressionContext *>(_localctx)->line =  antlrcpp::downCast<Simple_expressionContext *>(_localctx)->t->line;
                antlrcpp::downCast<Simple_expressionContext *>(_localctx)->type =  antlrcpp::downCast<Simple_expressionContext *>(_localctx)->t->type;
                antlrcpp::downCast<Simple_expressionContext *>(_localctx)->argIsArray =  antlrcpp::downCast<Simple_expressionContext *>(_localctx)->t->argIsArray;



                writeIntoparserLogFile("Line "+  std::to_string(antlrcpp::downCast<Simple_expressionContext *>(_localctx)->t->line)+": simple_expression : term\n\n" + antlrcpp::downCast<Simple_expressionContext *>(_localctx)->t->text + "\n"); 
                
    _ctx->stop = _input->LT(-1);
    setState(349);
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
        setState(342);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(343);
        antlrcpp::downCast<Simple_expressionContext *>(_localctx)->addopToken = match(C2105168Parser::ADDOP);
        setState(344);
        antlrcpp::downCast<Simple_expressionContext *>(_localctx)->t = term(0);

                              antlrcpp::downCast<Simple_expressionContext *>(_localctx)->text =  antlrcpp::downCast<Simple_expressionContext *>(_localctx)->s->text+antlrcpp::downCast<Simple_expressionContext *>(_localctx)->addopToken->getText()+antlrcpp::downCast<Simple_expressionContext *>(_localctx)->t->text;
                              antlrcpp::downCast<Simple_expressionContext *>(_localctx)->line =  antlrcpp::downCast<Simple_expressionContext *>(_localctx)->t->line;
                              antlrcpp::downCast<Simple_expressionContext *>(_localctx)->argIsArray =  false;
                              if (antlrcpp::downCast<Simple_expressionContext *>(_localctx)->s->type == "float" || antlrcpp::downCast<Simple_expressionContext *>(_localctx)->t->type == "float") {
                                  antlrcpp::downCast<Simple_expressionContext *>(_localctx)->type =  "float";
                              } else {
                                   antlrcpp::downCast<Simple_expressionContext *>(_localctx)->type =  "int";
                              }

                              writeIntoAsmFile("\tPOP DX");
                              writeIntoAsmFile("\tPOP AX");

                              if (antlrcpp::downCast<Simple_expressionContext *>(_localctx)->addopToken->getText() == "+") {

                                  antlrcpp::downCast<Simple_expressionContext *>(_localctx)->code_section =  "\tADD AX, DX\n\tPUSH AX"    ;
                              } else if (antlrcpp::downCast<Simple_expressionContext *>(_localctx)->addopToken->getText() == "-") {
                                  antlrcpp::downCast<Simple_expressionContext *>(_localctx)->code_section =  "\tSUB AX, DX\n\tPUSH AX\n";
                              }

                              writeIntoAsmFile(_localctx->code_section);
                              writeIntoparserLogFile("Line "+  std::to_string(_localctx->line)+": simple_expression : simple_expression ADDOP term\n\n" + _localctx->text + "\n"); 

                             
      }
      setState(351);
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
    setState(353);
    antlrcpp::downCast<TermContext *>(_localctx)->u = unary_expression();

             
                antlrcpp::downCast<TermContext *>(_localctx)->text =  antlrcpp::downCast<TermContext *>(_localctx)->u->text;
                antlrcpp::downCast<TermContext *>(_localctx)->line =  antlrcpp::downCast<TermContext *>(_localctx)->u->line;
                antlrcpp::downCast<TermContext *>(_localctx)->type =  antlrcpp::downCast<TermContext *>(_localctx)->u->type;
               antlrcpp::downCast<TermContext *>(_localctx)->argIsArray =  antlrcpp::downCast<TermContext *>(_localctx)->u->argIsArray; 
                writeIntoparserLogFile("Line "+  std::to_string(antlrcpp::downCast<TermContext *>(_localctx)->u->line)+": term : unary_expression\n\n" + antlrcpp::downCast<TermContext *>(_localctx)->u->text + "\n");
                
    _ctx->stop = _input->LT(-1);
    setState(363);
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
        setState(356);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(357);
        antlrcpp::downCast<TermContext *>(_localctx)->mulopToken = match(C2105168Parser::MULOP);
        setState(358);
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

                      

                    

                      if (antlrcpp::downCast<TermContext *>(_localctx)->mulopToken->getText() == "*") {
                          writeIntoAsmFile("\tPOP DX");
                          writeIntoAsmFile("\tPOP AX"); 
                          antlrcpp::downCast<TermContext *>(_localctx)->code_section =  "\tMUL DX\n\tPUSH AX";
                      } else if (antlrcpp::downCast<TermContext *>(_localctx)->mulopToken->getText() == "/") {
                          antlrcpp::downCast<TermContext *>(_localctx)->code_section =  "\tXCHG AX, DX\n\tDIV DX\n\tPUSH AX";
                      } else if (antlrcpp::downCast<TermContext *>(_localctx)->mulopToken->getText() == "%") {
                          writeIntoAsmFile("\tPOP CX");
                          writeIntoAsmFile("\tPOP AX");
                          antlrcpp::downCast<TermContext *>(_localctx)->code_section =  "\tCWD\n\tDIV CX\n\tPUSH DX";
                      }
                      writeIntoAsmFile(_localctx->code_section);
                   
      }
      setState(365);
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
    setState(377);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case C2105168Parser::ADDOP: {
        enterOuterAlt(_localctx, 1);
        setState(366);
        antlrcpp::downCast<Unary_expressionContext *>(_localctx)->addopToken = match(C2105168Parser::ADDOP);
        setState(367);
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
        setState(370);
        antlrcpp::downCast<Unary_expressionContext *>(_localctx)->notToken = match(C2105168Parser::NOT);
        setState(371);
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
        setState(374);
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
    setState(406);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(379);
      antlrcpp::downCast<FactorContext *>(_localctx)->v = variable();

              antlrcpp::downCast<FactorContext *>(_localctx)->text =  antlrcpp::downCast<FactorContext *>(_localctx)->v->text;
              antlrcpp::downCast<FactorContext *>(_localctx)->line =  antlrcpp::downCast<FactorContext *>(_localctx)->v->line;
              antlrcpp::downCast<FactorContext *>(_localctx)->type =  antlrcpp::downCast<FactorContext *>(_localctx)->v->type;
              antlrcpp::downCast<FactorContext *>(_localctx)->argIsArray =  antlrcpp::downCast<FactorContext *>(_localctx)->v->isArray;

              SymbolInfo* lookup = symbolTable->LookUP(antlrcpp::downCast<FactorContext *>(_localctx)->v->text);

              if(lookup->getIsGlobal()){
                  writeIntoAsmFile("\tMOV AX, "+antlrcpp::downCast<FactorContext *>(_localctx)->v->text+"       ; Line "+std::to_string(_localctx->line));
                  writeIntoAsmFile("\tPUSH AX");
                }

                else {   
                  writeIntoAsmFile("L" + std::to_string(label_count++)+":");

                  writeIntoAsmFile("\tMOV AX, [BP-" + std::to_string(lookup->getStackOffset()) + "]"+"       ; Line "+std::to_string(_localctx->line));
                  writeIntoAsmFile("\tPUSH AX");
                }

              // std::cout << "v type"<<antlrcpp::downCast<FactorContext *>(_localctx)->v->type <<std::endl;
              writeIntoparserLogFile("Line "+  std::to_string(antlrcpp::downCast<FactorContext *>(_localctx)->v->line)+": factor : variable\n\n" + antlrcpp::downCast<FactorContext *>(_localctx)->v->text + "\n");
              
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(382);
      antlrcpp::downCast<FactorContext *>(_localctx)->idToken = match(C2105168Parser::ID);
      setState(383);
      antlrcpp::downCast<FactorContext *>(_localctx)->lparenToken = match(C2105168Parser::LPAREN);

              argumentCount = 0;
              argumentTypes.clear();
              argumentIsArray.clear();
          
      setState(385);
      antlrcpp::downCast<FactorContext *>(_localctx)->a = argument_list();
      setState(386);
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
      setState(389);
      antlrcpp::downCast<FactorContext *>(_localctx)->lparenToken = match(C2105168Parser::LPAREN);
      setState(390);
      antlrcpp::downCast<FactorContext *>(_localctx)->e = expression();
      setState(391);
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
      setState(394);
      antlrcpp::downCast<FactorContext *>(_localctx)->const_intToken = match(C2105168Parser::CONST_INT);

              antlrcpp::downCast<FactorContext *>(_localctx)->text =  antlrcpp::downCast<FactorContext *>(_localctx)->const_intToken->getText();
              antlrcpp::downCast<FactorContext *>(_localctx)->line =  antlrcpp::downCast<FactorContext *>(_localctx)->const_intToken->getLine();
              antlrcpp::downCast<FactorContext *>(_localctx)->type =  "int";
              antlrcpp::downCast<FactorContext *>(_localctx)->argIsArray =  false;
              writeIntoAsmFile("L" + std::to_string(label_count++) + ":\n" + "\tMOV AX, "+_localctx->text +"       ; Line "+std::to_string(_localctx->line));
              writeIntoAsmFile("\tPUSH AX");
              

              

              writeIntoparserLogFile("Line "+  std::to_string(_localctx->line)+": factor : CONST_INT\n\n" + _localctx->text + "\n");

          
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(396);
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
      setState(398);
      antlrcpp::downCast<FactorContext *>(_localctx)->v = variable();
      setState(399);
      antlrcpp::downCast<FactorContext *>(_localctx)->incopToken = match(C2105168Parser::INCOP);

              antlrcpp::downCast<FactorContext *>(_localctx)->text =  antlrcpp::downCast<FactorContext *>(_localctx)->v->text+antlrcpp::downCast<FactorContext *>(_localctx)->incopToken->getText();
              antlrcpp::downCast<FactorContext *>(_localctx)->line =  antlrcpp::downCast<FactorContext *>(_localctx)->incopToken->getLine();
              antlrcpp::downCast<FactorContext *>(_localctx)->type =  antlrcpp::downCast<FactorContext *>(_localctx)->v->type;

              SymbolInfo* lookup = symbolTable->LookUP(antlrcpp::downCast<FactorContext *>(_localctx)->v->text);
              writeIntoAsmFile("\tMOV AX, [BP-" + std::to_string(lookup->getStackOffset()) + "]"+"       ; Line "+std::to_string(_localctx->line));
              writeIntoAsmFile("\tPUSH AX");
              writeIntoAsmFile("\tINC AX");
              writeIntoparserLogFile("Line "+  std::to_string(_localctx->line)+": factor : variable INCOP\n\n" + _localctx->text + "\n");

          
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(402);
      antlrcpp::downCast<FactorContext *>(_localctx)->v = variable();
      setState(403);
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
    setState(412);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case C2105168Parser::LPAREN:
      case C2105168Parser::ADDOP:
      case C2105168Parser::NOT:
      case C2105168Parser::ID:
      case C2105168Parser::CONST_INT:
      case C2105168Parser::CONST_FLOAT: {
        enterOuterAlt(_localctx, 1);
        setState(408);
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
    setState(415);
    antlrcpp::downCast<ArgumentsContext *>(_localctx)->le = logic_expression();


                antlrcpp::downCast<ArgumentsContext *>(_localctx)->text = antlrcpp::downCast<ArgumentsContext *>(_localctx)->le->text;
                antlrcpp::downCast<ArgumentsContext *>(_localctx)->line = antlrcpp::downCast<ArgumentsContext *>(_localctx)->le->line;
                antlrcpp::downCast<ArgumentsContext *>(_localctx)->type =  antlrcpp::downCast<ArgumentsContext *>(_localctx)->le->type; 
                argumentCount++;  
                argumentTypes.push_back(antlrcpp::downCast<ArgumentsContext *>(_localctx)->le->type);
                argumentIsArray.push_back(antlrcpp::downCast<ArgumentsContext *>(_localctx)->le->argIsArr);
                writeIntoparserLogFile("Line "+ std::to_string(_localctx->line)+": arguments : logic_expression\n\n"+_localctx->text+"\n");


            
    _ctx->stop = _input->LT(-1);
    setState(425);
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
        setState(418);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(419);
        antlrcpp::downCast<ArgumentsContext *>(_localctx)->commaToken = match(C2105168Parser::COMMA);
        setState(420);
        antlrcpp::downCast<ArgumentsContext *>(_localctx)->le = logic_expression();
            
                              antlrcpp::downCast<ArgumentsContext *>(_localctx)->text = antlrcpp::downCast<ArgumentsContext *>(_localctx)->a->text +  antlrcpp::downCast<ArgumentsContext *>(_localctx)->commaToken->getText()+  antlrcpp::downCast<ArgumentsContext *>(_localctx)->le->text;
                              antlrcpp::downCast<ArgumentsContext *>(_localctx)->line = antlrcpp::downCast<ArgumentsContext *>(_localctx)->le->line;
                              antlrcpp::downCast<ArgumentsContext *>(_localctx)->type =  antlrcpp::downCast<ArgumentsContext *>(_localctx)->le->type;
                              argumentCount++;
                              argumentTypes.push_back(antlrcpp::downCast<ArgumentsContext *>(_localctx)->le->type);
                              argumentIsArray.push_back(antlrcpp::downCast<ArgumentsContext *>(_localctx)->le->argIsArr);
                              writeIntoparserLogFile("Line "+ std::to_string(_localctx->line)+": arguments : arguments COMMA logic_expression\n\n"+_localctx->text+"\n");

                            
      }
      setState(427);
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
