
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
    extern std::vector<std::string>returnTypes;
    extern std::vector<std::string>fndecreturnTypes;
    extern std::vector<std::string>fndefreturnTypes;



// Generated from C8086Parser.g4 by ANTLR 4.13.2


#include "C8086ParserListener.h"

#include "C8086Parser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct C8086ParserStaticData final {
  C8086ParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  C8086ParserStaticData(const C8086ParserStaticData&) = delete;
  C8086ParserStaticData(C8086ParserStaticData&&) = delete;
  C8086ParserStaticData& operator=(const C8086ParserStaticData&) = delete;
  C8086ParserStaticData& operator=(C8086ParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag c8086parserParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<C8086ParserStaticData> c8086parserParserStaticData = nullptr;

void c8086parserParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (c8086parserParserStaticData != nullptr) {
    return;
  }
#else
  assert(c8086parserParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<C8086ParserStaticData>(
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
  	4,1,34,414,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,1,0,1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,5,
  	1,60,8,1,10,1,12,1,63,9,1,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,3,2,74,
  	8,2,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,3,
  	3,92,8,3,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,
  	1,4,1,4,3,4,111,8,4,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,
  	5,1,5,3,5,127,8,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,
  	1,5,1,5,5,5,144,8,5,10,5,12,5,147,9,5,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,
  	1,6,1,6,3,6,159,8,6,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,3,7,171,8,
  	7,1,8,1,8,1,9,1,9,1,9,1,9,1,9,1,9,3,9,181,8,9,1,10,1,10,1,10,1,10,1,10,
  	1,10,1,10,1,10,3,10,191,8,10,1,10,1,10,1,10,1,10,1,10,1,10,1,10,1,10,
  	1,10,1,10,1,10,5,10,204,8,10,10,10,12,10,207,9,10,1,11,1,11,1,11,1,11,
  	1,11,1,11,1,11,1,11,5,11,217,8,11,10,11,12,11,220,9,11,1,12,1,12,1,12,
  	1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,
  	1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,
  	1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,
  	1,12,1,12,1,12,1,12,1,12,1,12,1,12,3,12,274,8,12,1,13,1,13,1,13,1,13,
  	1,13,1,13,3,13,282,8,13,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,3,14,
  	292,8,14,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,3,15,302,8,15,1,16,1,
  	16,1,16,1,16,1,16,1,16,1,16,1,16,3,16,312,8,16,1,17,1,17,1,17,1,17,1,
  	17,1,17,1,17,1,17,3,17,322,8,17,1,18,1,18,1,18,1,18,1,18,1,18,1,18,1,
  	18,1,18,5,18,333,8,18,10,18,12,18,336,9,18,1,19,1,19,1,19,1,19,1,19,1,
  	19,1,19,1,19,1,19,5,19,347,8,19,10,19,12,19,350,9,19,1,20,1,20,1,20,1,
  	20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,3,20,363,8,20,1,21,1,21,1,21,1,
  	21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,
  	21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,3,21,392,8,21,1,22,1,
  	22,1,22,1,22,3,22,398,8,22,1,23,1,23,1,23,1,23,1,23,1,23,1,23,1,23,1,
  	23,5,23,409,8,23,10,23,12,23,412,9,23,1,23,0,7,2,10,20,22,36,38,46,24,
  	0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,42,44,46,0,
  	0,433,0,48,1,0,0,0,2,51,1,0,0,0,4,73,1,0,0,0,6,91,1,0,0,0,8,110,1,0,0,
  	0,10,126,1,0,0,0,12,158,1,0,0,0,14,170,1,0,0,0,16,172,1,0,0,0,18,180,
  	1,0,0,0,20,190,1,0,0,0,22,208,1,0,0,0,24,273,1,0,0,0,26,281,1,0,0,0,28,
  	291,1,0,0,0,30,301,1,0,0,0,32,311,1,0,0,0,34,321,1,0,0,0,36,323,1,0,0,
  	0,38,337,1,0,0,0,40,362,1,0,0,0,42,391,1,0,0,0,44,397,1,0,0,0,46,399,
  	1,0,0,0,48,49,3,2,1,0,49,50,6,0,-1,0,50,1,1,0,0,0,51,52,6,1,-1,0,52,53,
  	3,4,2,0,53,54,6,1,-1,0,54,61,1,0,0,0,55,56,10,2,0,0,56,57,3,4,2,0,57,
  	58,6,1,-1,0,58,60,1,0,0,0,59,55,1,0,0,0,60,63,1,0,0,0,61,59,1,0,0,0,61,
  	62,1,0,0,0,62,3,1,0,0,0,63,61,1,0,0,0,64,65,3,14,7,0,65,66,6,2,-1,0,66,
  	74,1,0,0,0,67,68,3,6,3,0,68,69,6,2,-1,0,69,74,1,0,0,0,70,71,3,8,4,0,71,
  	72,6,2,-1,0,72,74,1,0,0,0,73,64,1,0,0,0,73,67,1,0,0,0,73,70,1,0,0,0,74,
  	5,1,0,0,0,75,76,3,18,9,0,76,77,5,32,0,0,77,78,6,3,-1,0,78,79,5,14,0,0,
  	79,80,3,10,5,0,80,81,5,15,0,0,81,82,5,20,0,0,82,83,6,3,-1,0,83,92,1,0,
  	0,0,84,85,3,18,9,0,85,86,5,32,0,0,86,87,5,14,0,0,87,88,5,15,0,0,88,89,
  	5,20,0,0,89,90,6,3,-1,0,90,92,1,0,0,0,91,75,1,0,0,0,91,84,1,0,0,0,92,
  	7,1,0,0,0,93,94,3,18,9,0,94,95,5,32,0,0,95,96,5,14,0,0,96,97,3,10,5,0,
  	97,98,6,4,-1,0,98,99,5,15,0,0,99,100,3,12,6,0,100,101,6,4,-1,0,101,111,
  	1,0,0,0,102,103,3,18,9,0,103,104,5,32,0,0,104,105,5,14,0,0,105,106,5,
  	15,0,0,106,107,6,4,-1,0,107,108,3,12,6,0,108,109,6,4,-1,0,109,111,1,0,
  	0,0,110,93,1,0,0,0,110,102,1,0,0,0,111,9,1,0,0,0,112,113,6,5,-1,0,113,
  	114,3,18,9,0,114,115,5,32,0,0,115,116,6,5,-1,0,116,127,1,0,0,0,117,118,
  	3,18,9,0,118,119,5,23,0,0,119,120,6,5,-1,0,120,127,1,0,0,0,121,122,3,
  	18,9,0,122,123,6,5,-1,0,123,127,1,0,0,0,124,125,5,23,0,0,125,127,6,5,
  	-1,0,126,112,1,0,0,0,126,117,1,0,0,0,126,121,1,0,0,0,126,124,1,0,0,0,
  	127,145,1,0,0,0,128,129,10,7,0,0,129,130,5,21,0,0,130,131,3,18,9,0,131,
  	132,5,32,0,0,132,133,6,5,-1,0,133,144,1,0,0,0,134,135,10,6,0,0,135,136,
  	5,21,0,0,136,137,3,18,9,0,137,138,6,5,-1,0,138,144,1,0,0,0,139,140,10,
  	5,0,0,140,141,5,21,0,0,141,142,5,23,0,0,142,144,6,5,-1,0,143,128,1,0,
  	0,0,143,134,1,0,0,0,143,139,1,0,0,0,144,147,1,0,0,0,145,143,1,0,0,0,145,
  	146,1,0,0,0,146,11,1,0,0,0,147,145,1,0,0,0,148,149,5,16,0,0,149,150,6,
  	6,-1,0,150,151,3,22,11,0,151,152,6,6,-1,0,152,153,5,17,0,0,153,154,6,
  	6,-1,0,154,159,1,0,0,0,155,156,5,16,0,0,156,157,5,17,0,0,157,159,6,6,
  	-1,0,158,148,1,0,0,0,158,155,1,0,0,0,159,13,1,0,0,0,160,161,3,18,9,0,
  	161,162,3,20,10,0,162,163,5,20,0,0,163,164,6,7,-1,0,164,171,1,0,0,0,165,
  	166,3,18,9,0,166,167,3,16,8,0,167,168,5,20,0,0,168,169,6,7,-1,0,169,171,
  	1,0,0,0,170,160,1,0,0,0,170,165,1,0,0,0,171,15,1,0,0,0,172,173,6,8,-1,
  	0,173,17,1,0,0,0,174,175,5,11,0,0,175,181,6,9,-1,0,176,177,5,12,0,0,177,
  	181,6,9,-1,0,178,179,5,13,0,0,179,181,6,9,-1,0,180,174,1,0,0,0,180,176,
  	1,0,0,0,180,178,1,0,0,0,181,19,1,0,0,0,182,183,6,10,-1,0,183,184,5,32,
  	0,0,184,191,6,10,-1,0,185,186,5,32,0,0,186,187,5,18,0,0,187,188,5,33,
  	0,0,188,189,5,19,0,0,189,191,6,10,-1,0,190,182,1,0,0,0,190,185,1,0,0,
  	0,191,205,1,0,0,0,192,193,10,4,0,0,193,194,5,21,0,0,194,195,5,32,0,0,
  	195,204,6,10,-1,0,196,197,10,3,0,0,197,198,5,21,0,0,198,199,5,32,0,0,
  	199,200,5,18,0,0,200,201,5,33,0,0,201,202,5,19,0,0,202,204,6,10,-1,0,
  	203,192,1,0,0,0,203,196,1,0,0,0,204,207,1,0,0,0,205,203,1,0,0,0,205,206,
  	1,0,0,0,206,21,1,0,0,0,207,205,1,0,0,0,208,209,6,11,-1,0,209,210,3,24,
  	12,0,210,211,6,11,-1,0,211,218,1,0,0,0,212,213,10,1,0,0,213,214,3,24,
  	12,0,214,215,6,11,-1,0,215,217,1,0,0,0,216,212,1,0,0,0,217,220,1,0,0,
  	0,218,216,1,0,0,0,218,219,1,0,0,0,219,23,1,0,0,0,220,218,1,0,0,0,221,
  	222,3,14,7,0,222,223,6,12,-1,0,223,274,1,0,0,0,224,225,3,26,13,0,225,
  	226,6,12,-1,0,226,274,1,0,0,0,227,228,3,12,6,0,228,229,6,12,-1,0,229,
  	274,1,0,0,0,230,231,5,7,0,0,231,232,5,14,0,0,232,233,3,26,13,0,233,234,
  	3,26,13,0,234,235,3,30,15,0,235,236,5,15,0,0,236,237,3,24,12,0,237,238,
  	6,12,-1,0,238,274,1,0,0,0,239,240,5,5,0,0,240,241,5,14,0,0,241,242,3,
  	30,15,0,242,243,5,15,0,0,243,244,3,24,12,0,244,245,6,12,-1,0,245,274,
  	1,0,0,0,246,247,5,5,0,0,247,248,5,14,0,0,248,249,3,30,15,0,249,250,5,
  	15,0,0,250,251,3,24,12,0,251,252,5,6,0,0,252,253,3,24,12,0,253,254,6,
  	12,-1,0,254,274,1,0,0,0,255,256,5,8,0,0,256,257,5,14,0,0,257,258,3,30,
  	15,0,258,259,5,15,0,0,259,260,3,24,12,0,260,261,6,12,-1,0,261,274,1,0,
  	0,0,262,263,5,9,0,0,263,264,5,14,0,0,264,265,5,32,0,0,265,266,5,15,0,
  	0,266,267,5,20,0,0,267,274,6,12,-1,0,268,269,5,10,0,0,269,270,3,30,15,
  	0,270,271,5,20,0,0,271,272,6,12,-1,0,272,274,1,0,0,0,273,221,1,0,0,0,
  	273,224,1,0,0,0,273,227,1,0,0,0,273,230,1,0,0,0,273,239,1,0,0,0,273,246,
  	1,0,0,0,273,255,1,0,0,0,273,262,1,0,0,0,273,268,1,0,0,0,274,25,1,0,0,
  	0,275,276,5,20,0,0,276,282,6,13,-1,0,277,278,3,30,15,0,278,279,5,20,0,
  	0,279,280,6,13,-1,0,280,282,1,0,0,0,281,275,1,0,0,0,281,277,1,0,0,0,282,
  	27,1,0,0,0,283,284,5,32,0,0,284,292,6,14,-1,0,285,286,5,32,0,0,286,287,
  	5,18,0,0,287,288,3,30,15,0,288,289,5,19,0,0,289,290,6,14,-1,0,290,292,
  	1,0,0,0,291,283,1,0,0,0,291,285,1,0,0,0,292,29,1,0,0,0,293,294,3,32,16,
  	0,294,295,6,15,-1,0,295,302,1,0,0,0,296,297,3,28,14,0,297,298,5,31,0,
  	0,298,299,3,32,16,0,299,300,6,15,-1,0,300,302,1,0,0,0,301,293,1,0,0,0,
  	301,296,1,0,0,0,302,31,1,0,0,0,303,304,3,34,17,0,304,305,6,16,-1,0,305,
  	312,1,0,0,0,306,307,3,34,17,0,307,308,5,30,0,0,308,309,3,34,17,0,309,
  	310,6,16,-1,0,310,312,1,0,0,0,311,303,1,0,0,0,311,306,1,0,0,0,312,33,
  	1,0,0,0,313,314,3,36,18,0,314,315,6,17,-1,0,315,322,1,0,0,0,316,317,3,
  	36,18,0,317,318,5,29,0,0,318,319,3,36,18,0,319,320,6,17,-1,0,320,322,
  	1,0,0,0,321,313,1,0,0,0,321,316,1,0,0,0,322,35,1,0,0,0,323,324,6,18,-1,
  	0,324,325,3,38,19,0,325,326,6,18,-1,0,326,334,1,0,0,0,327,328,10,1,0,
  	0,328,329,5,23,0,0,329,330,3,38,19,0,330,331,6,18,-1,0,331,333,1,0,0,
  	0,332,327,1,0,0,0,333,336,1,0,0,0,334,332,1,0,0,0,334,335,1,0,0,0,335,
  	37,1,0,0,0,336,334,1,0,0,0,337,338,6,19,-1,0,338,339,3,40,20,0,339,340,
  	6,19,-1,0,340,348,1,0,0,0,341,342,10,1,0,0,342,343,5,25,0,0,343,344,3,
  	40,20,0,344,345,6,19,-1,0,345,347,1,0,0,0,346,341,1,0,0,0,347,350,1,0,
  	0,0,348,346,1,0,0,0,348,349,1,0,0,0,349,39,1,0,0,0,350,348,1,0,0,0,351,
  	352,5,23,0,0,352,353,3,40,20,0,353,354,6,20,-1,0,354,363,1,0,0,0,355,
  	356,5,28,0,0,356,357,3,40,20,0,357,358,6,20,-1,0,358,363,1,0,0,0,359,
  	360,3,42,21,0,360,361,6,20,-1,0,361,363,1,0,0,0,362,351,1,0,0,0,362,355,
  	1,0,0,0,362,359,1,0,0,0,363,41,1,0,0,0,364,365,3,28,14,0,365,366,6,21,
  	-1,0,366,392,1,0,0,0,367,368,5,32,0,0,368,369,5,14,0,0,369,370,6,21,-1,
  	0,370,371,3,44,22,0,371,372,5,15,0,0,372,373,6,21,-1,0,373,392,1,0,0,
  	0,374,375,5,14,0,0,375,376,3,30,15,0,376,377,5,15,0,0,377,378,6,21,-1,
  	0,378,392,1,0,0,0,379,380,5,33,0,0,380,392,6,21,-1,0,381,382,5,34,0,0,
  	382,392,6,21,-1,0,383,384,3,28,14,0,384,385,5,26,0,0,385,386,6,21,-1,
  	0,386,392,1,0,0,0,387,388,3,28,14,0,388,389,5,27,0,0,389,390,6,21,-1,
  	0,390,392,1,0,0,0,391,364,1,0,0,0,391,367,1,0,0,0,391,374,1,0,0,0,391,
  	379,1,0,0,0,391,381,1,0,0,0,391,383,1,0,0,0,391,387,1,0,0,0,392,43,1,
  	0,0,0,393,394,3,46,23,0,394,395,6,22,-1,0,395,398,1,0,0,0,396,398,1,0,
  	0,0,397,393,1,0,0,0,397,396,1,0,0,0,398,45,1,0,0,0,399,400,6,23,-1,0,
  	400,401,3,32,16,0,401,402,6,23,-1,0,402,410,1,0,0,0,403,404,10,2,0,0,
  	404,405,5,21,0,0,405,406,3,32,16,0,406,407,6,23,-1,0,407,409,1,0,0,0,
  	408,403,1,0,0,0,409,412,1,0,0,0,410,408,1,0,0,0,410,411,1,0,0,0,411,47,
  	1,0,0,0,412,410,1,0,0,0,26,61,73,91,110,126,143,145,158,170,180,190,203,
  	205,218,273,281,291,301,311,321,334,348,362,391,397,410
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  c8086parserParserStaticData = std::move(staticData);
}

}

C8086Parser::C8086Parser(TokenStream *input) : C8086Parser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

C8086Parser::C8086Parser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  C8086Parser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *c8086parserParserStaticData->atn, c8086parserParserStaticData->decisionToDFA, c8086parserParserStaticData->sharedContextCache, options);
}

C8086Parser::~C8086Parser() {
  delete _interpreter;
}

const atn::ATN& C8086Parser::getATN() const {
  return *c8086parserParserStaticData->atn;
}

std::string C8086Parser::getGrammarFileName() const {
  return "C8086Parser.g4";
}

const std::vector<std::string>& C8086Parser::getRuleNames() const {
  return c8086parserParserStaticData->ruleNames;
}

const dfa::Vocabulary& C8086Parser::getVocabulary() const {
  return c8086parserParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView C8086Parser::getSerializedATN() const {
  return c8086parserParserStaticData->serializedATN;
}


//----------------- StartContext ------------------------------------------------------------------

C8086Parser::StartContext::StartContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C8086Parser::ProgramContext* C8086Parser::StartContext::program() {
  return getRuleContext<C8086Parser::ProgramContext>(0);
}


size_t C8086Parser::StartContext::getRuleIndex() const {
  return C8086Parser::RuleStart;
}

void C8086Parser::StartContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStart(this);
}

void C8086Parser::StartContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStart(this);
}

C8086Parser::StartContext* C8086Parser::start() {
  StartContext *_localctx = _tracker.createInstance<StartContext>(_ctx, getState());
  enterRule(_localctx, 0, C8086Parser::RuleStart);

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
           // writeIntoparserLogFile("Parsing completed successfully with " + std::to_string(syntaxErrorCount) + " syntax errors.");


            writeIntoparserLogFile("Line "+std::to_string(_localctx->line)+": start : program\n");
            symbolTable->print_current_scope_table(parserLogFile);


            writeIntoparserLogFile("\nTotal number of lines: "+std::to_string(_localctx->line));
            writeIntoparserLogFile("Total number of errors: "+std::to_string(errorCount));




    	
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ProgramContext ------------------------------------------------------------------

C8086Parser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C8086Parser::UnitContext* C8086Parser::ProgramContext::unit() {
  return getRuleContext<C8086Parser::UnitContext>(0);
}

C8086Parser::ProgramContext* C8086Parser::ProgramContext::program() {
  return getRuleContext<C8086Parser::ProgramContext>(0);
}


size_t C8086Parser::ProgramContext::getRuleIndex() const {
  return C8086Parser::RuleProgram;
}

void C8086Parser::ProgramContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProgram(this);
}

void C8086Parser::ProgramContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProgram(this);
}


C8086Parser::ProgramContext* C8086Parser::program() {
   return program(0);
}

C8086Parser::ProgramContext* C8086Parser::program(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  C8086Parser::ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, parentState);
  C8086Parser::ProgramContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 2;
  enterRecursionRule(_localctx, 2, C8086Parser::RuleProgram, precedence);

    

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

C8086Parser::UnitContext::UnitContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C8086Parser::Var_declarationContext* C8086Parser::UnitContext::var_declaration() {
  return getRuleContext<C8086Parser::Var_declarationContext>(0);
}

C8086Parser::Func_declarationContext* C8086Parser::UnitContext::func_declaration() {
  return getRuleContext<C8086Parser::Func_declarationContext>(0);
}

C8086Parser::Func_definitionContext* C8086Parser::UnitContext::func_definition() {
  return getRuleContext<C8086Parser::Func_definitionContext>(0);
}


size_t C8086Parser::UnitContext::getRuleIndex() const {
  return C8086Parser::RuleUnit;
}

void C8086Parser::UnitContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnit(this);
}

void C8086Parser::UnitContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnit(this);
}

C8086Parser::UnitContext* C8086Parser::unit() {
  UnitContext *_localctx = _tracker.createInstance<UnitContext>(_ctx, getState());
  enterRule(_localctx, 4, C8086Parser::RuleUnit);

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
              writeIntoparserLogFile("Line "+std::to_string(_localctx->line)+": unit : var_declaration\n\n"+_localctx->text+"\n");

          
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(67);
      antlrcpp::downCast<UnitContext *>(_localctx)->fdec = func_declaration();
        
              antlrcpp::downCast<UnitContext *>(_localctx)->text =  antlrcpp::downCast<UnitContext *>(_localctx)->fdec->text;
              antlrcpp::downCast<UnitContext *>(_localctx)->line =  antlrcpp::downCast<UnitContext *>(_localctx)->fdec->line;
              writeIntoparserLogFile("Line "+std::to_string(_localctx->line)+": unit : func_declaration\n\n"+_localctx->text+"\n");

          
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(70);
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

C8086Parser::Func_declarationContext::Func_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* C8086Parser::Func_declarationContext::ID() {
  return getToken(C8086Parser::ID, 0);
}

tree::TerminalNode* C8086Parser::Func_declarationContext::LPAREN() {
  return getToken(C8086Parser::LPAREN, 0);
}

tree::TerminalNode* C8086Parser::Func_declarationContext::RPAREN() {
  return getToken(C8086Parser::RPAREN, 0);
}

tree::TerminalNode* C8086Parser::Func_declarationContext::SEMICOLON() {
  return getToken(C8086Parser::SEMICOLON, 0);
}

C8086Parser::Type_specifierContext* C8086Parser::Func_declarationContext::type_specifier() {
  return getRuleContext<C8086Parser::Type_specifierContext>(0);
}

C8086Parser::Parameter_listContext* C8086Parser::Func_declarationContext::parameter_list() {
  return getRuleContext<C8086Parser::Parameter_listContext>(0);
}


size_t C8086Parser::Func_declarationContext::getRuleIndex() const {
  return C8086Parser::RuleFunc_declaration;
}

void C8086Parser::Func_declarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunc_declaration(this);
}

void C8086Parser::Func_declarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunc_declaration(this);
}

C8086Parser::Func_declarationContext* C8086Parser::func_declaration() {
  Func_declarationContext *_localctx = _tracker.createInstance<Func_declarationContext>(_ctx, getState());
  enterRule(_localctx, 6, C8086Parser::RuleFunc_declaration);

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
      antlrcpp::downCast<Func_declarationContext *>(_localctx)->idToken = match(C8086Parser::ID);

              paramCount = 0;
          
      setState(78);
      antlrcpp::downCast<Func_declarationContext *>(_localctx)->lparenToken = match(C8086Parser::LPAREN);
      setState(79);
      antlrcpp::downCast<Func_declarationContext *>(_localctx)->pl = parameter_list(0);
      setState(80);
      antlrcpp::downCast<Func_declarationContext *>(_localctx)->rparenToken = match(C8086Parser::RPAREN);
      setState(81);
      antlrcpp::downCast<Func_declarationContext *>(_localctx)->semicolonToken = match(C8086Parser::SEMICOLON);
        

              antlrcpp::downCast<Func_declarationContext *>(_localctx)->text =  antlrcpp::downCast<Func_declarationContext *>(_localctx)->ts->text +" "+ antlrcpp::downCast<Func_declarationContext *>(_localctx)->idToken->getText() + antlrcpp::downCast<Func_declarationContext *>(_localctx)->lparenToken->getText() + antlrcpp::downCast<Func_declarationContext *>(_localctx)->pl->text+ antlrcpp::downCast<Func_declarationContext *>(_localctx)->rparenToken->getText() +  antlrcpp::downCast<Func_declarationContext *>(_localctx)->semicolonToken->getText();
              antlrcpp::downCast<Func_declarationContext *>(_localctx)->line =  antlrcpp::downCast<Func_declarationContext *>(_localctx)->semicolonToken->getLine(); 
              antlrcpp::downCast<Func_declarationContext *>(_localctx)->type =  antlrcpp::downCast<Func_declarationContext *>(_localctx)->ts->text;


              SymbolInfo* funcSymbol = new SymbolInfo(antlrcpp::downCast<Func_declarationContext *>(_localctx)->idToken->getText(), "ID");

              funcSymbol->setIsFunction(true);
              funcSymbol->setIsFunctionDefined(true);
              funcSymbol->setReturnType(antlrcpp::downCast<Func_declarationContext *>(_localctx)->ts->text);
              funcSymbol->setParameterList(antlrcpp::downCast<Func_declarationContext *>(_localctx)->pl->plist);
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
      antlrcpp::downCast<Func_declarationContext *>(_localctx)->idToken = match(C8086Parser::ID);
      setState(86);
      antlrcpp::downCast<Func_declarationContext *>(_localctx)->lparenToken = match(C8086Parser::LPAREN);
      setState(87);
      antlrcpp::downCast<Func_declarationContext *>(_localctx)->rparenToken = match(C8086Parser::RPAREN);
      setState(88);
      antlrcpp::downCast<Func_declarationContext *>(_localctx)->semicolonToken = match(C8086Parser::SEMICOLON);
        
              antlrcpp::downCast<Func_declarationContext *>(_localctx)->text =  antlrcpp::downCast<Func_declarationContext *>(_localctx)->ts->text + " "+antlrcpp::downCast<Func_declarationContext *>(_localctx)->idToken->getText() + antlrcpp::downCast<Func_declarationContext *>(_localctx)->lparenToken->getText() + antlrcpp::downCast<Func_declarationContext *>(_localctx)->rparenToken->getText() +  antlrcpp::downCast<Func_declarationContext *>(_localctx)->semicolonToken->getText();
              antlrcpp::downCast<Func_declarationContext *>(_localctx)->line =  antlrcpp::downCast<Func_declarationContext *>(_localctx)->semicolonToken->getLine(); 
              antlrcpp::downCast<Func_declarationContext *>(_localctx)->type =  antlrcpp::downCast<Func_declarationContext *>(_localctx)->ts->text;


              SymbolInfo* funcSymbol = new SymbolInfo(antlrcpp::downCast<Func_declarationContext *>(_localctx)->idToken->getText(), "ID");
              funcSymbol->setIsFunction(true);
              funcSymbol->setIsFunctionDefined(true);
              funcSymbol->setReturnType(antlrcpp::downCast<Func_declarationContext *>(_localctx)->ts->text);



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

C8086Parser::Func_definitionContext::Func_definitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* C8086Parser::Func_definitionContext::ID() {
  return getToken(C8086Parser::ID, 0);
}

tree::TerminalNode* C8086Parser::Func_definitionContext::LPAREN() {
  return getToken(C8086Parser::LPAREN, 0);
}

tree::TerminalNode* C8086Parser::Func_definitionContext::RPAREN() {
  return getToken(C8086Parser::RPAREN, 0);
}

C8086Parser::Type_specifierContext* C8086Parser::Func_definitionContext::type_specifier() {
  return getRuleContext<C8086Parser::Type_specifierContext>(0);
}

C8086Parser::Parameter_listContext* C8086Parser::Func_definitionContext::parameter_list() {
  return getRuleContext<C8086Parser::Parameter_listContext>(0);
}

C8086Parser::Compound_statementContext* C8086Parser::Func_definitionContext::compound_statement() {
  return getRuleContext<C8086Parser::Compound_statementContext>(0);
}


size_t C8086Parser::Func_definitionContext::getRuleIndex() const {
  return C8086Parser::RuleFunc_definition;
}

void C8086Parser::Func_definitionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunc_definition(this);
}

void C8086Parser::Func_definitionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunc_definition(this);
}

C8086Parser::Func_definitionContext* C8086Parser::func_definition() {
  Func_definitionContext *_localctx = _tracker.createInstance<Func_definitionContext>(_ctx, getState());
  enterRule(_localctx, 8, C8086Parser::RuleFunc_definition);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(110);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(93);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->ts = type_specifier();
      setState(94);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken = match(C8086Parser::ID);
      setState(95);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->lparenToken = match(C8086Parser::LPAREN);
      setState(96);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->pl = parameter_list(0);

              
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


              



           
      setState(98);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->rparenToken = match(C8086Parser::RPAREN);
      setState(99);
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

              //symbolTable->print_current_scope_table(parserLogFile);

              writeIntoparserLogFile("\nLine "+std::to_string(_localctx->line)+": func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement\n\n"+_localctx->text+"\n");
       

          
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(102);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->ts = type_specifier();
      setState(103);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken = match(C8086Parser::ID);
      setState(104);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->lparenToken = match(C8086Parser::LPAREN);
      setState(105);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->rparenToken = match(C8086Parser::RPAREN);
       

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

              
      setState(107);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->cs = compound_statement();
       

              antlrcpp::downCast<Func_definitionContext *>(_localctx)->text =  antlrcpp::downCast<Func_definitionContext *>(_localctx)->ts->text +" " + antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getText() +  antlrcpp::downCast<Func_definitionContext *>(_localctx)->lparenToken->getText() + antlrcpp::downCast<Func_definitionContext *>(_localctx)->rparenToken->getText() + antlrcpp::downCast<Func_definitionContext *>(_localctx)->cs->text;
              antlrcpp::downCast<Func_definitionContext *>(_localctx)->line =  antlrcpp::downCast<Func_definitionContext *>(_localctx)->cs->line;


           //   symbolTable->print_current_scope_table(parserLogFile);


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

C8086Parser::Parameter_listContext::Parameter_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* C8086Parser::Parameter_listContext::ID() {
  return getToken(C8086Parser::ID, 0);
}

C8086Parser::Type_specifierContext* C8086Parser::Parameter_listContext::type_specifier() {
  return getRuleContext<C8086Parser::Type_specifierContext>(0);
}

tree::TerminalNode* C8086Parser::Parameter_listContext::ADDOP() {
  return getToken(C8086Parser::ADDOP, 0);
}

tree::TerminalNode* C8086Parser::Parameter_listContext::COMMA() {
  return getToken(C8086Parser::COMMA, 0);
}

C8086Parser::Parameter_listContext* C8086Parser::Parameter_listContext::parameter_list() {
  return getRuleContext<C8086Parser::Parameter_listContext>(0);
}


size_t C8086Parser::Parameter_listContext::getRuleIndex() const {
  return C8086Parser::RuleParameter_list;
}

void C8086Parser::Parameter_listContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParameter_list(this);
}

void C8086Parser::Parameter_listContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParameter_list(this);
}


C8086Parser::Parameter_listContext* C8086Parser::parameter_list() {
   return parameter_list(0);
}

C8086Parser::Parameter_listContext* C8086Parser::parameter_list(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  C8086Parser::Parameter_listContext *_localctx = _tracker.createInstance<Parameter_listContext>(_ctx, parentState);
  C8086Parser::Parameter_listContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 10;
  enterRecursionRule(_localctx, 10, C8086Parser::RuleParameter_list, precedence);

    

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
    setState(126);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
    case 1: {
      setState(113);
      antlrcpp::downCast<Parameter_listContext *>(_localctx)->ts = type_specifier();
      setState(114);
      antlrcpp::downCast<Parameter_listContext *>(_localctx)->idToken = match(C8086Parser::ID);

              antlrcpp::downCast<Parameter_listContext *>(_localctx)->text =  antlrcpp::downCast<Parameter_listContext *>(_localctx)->ts->text + " " + antlrcpp::downCast<Parameter_listContext *>(_localctx)->idToken->getText()   ;
              antlrcpp::downCast<Parameter_listContext *>(_localctx)->line =  antlrcpp::downCast<Parameter_listContext *>(_localctx)->idToken->getLine();
              _localctx->plist.push_back(std::make_pair(antlrcpp::downCast<Parameter_listContext *>(_localctx)->ts->text, antlrcpp::downCast<Parameter_listContext *>(_localctx)->idToken->getText()));

              SymbolInfo* paramSymbol = new SymbolInfo(antlrcpp::downCast<Parameter_listContext *>(_localctx)->idToken->getText(), "ID");
              paramSymbol->setIsArray(false);
              paramSymbol->setType(antlrcpp::downCast<Parameter_listContext *>(_localctx)->ts->text);
              // if(!symbolTable->Insert(paramSymbol)){
              //     writeIntoparserLogFile("Error at line "+std::to_string(_localctx->line)+": Multiple declaration of "+antlrcpp::downCast<Parameter_listContext *>(_localctx)->idToken->getText()+" in parameter\n");
              //     writeIntoErrorFile("Error at line "+std::to_string(_localctx->line)+": Multiple declaration of "+antlrcpp::downCast<Parameter_listContext *>(_localctx)->idToken->getText()+" in parameter\n");
              // }
              writeIntoparserLogFile("Line " + std::to_string(_localctx->line) +": parameter_list : type_specifier ID\n\n" + _localctx->text + "\n");
      		
      break;
    }

    case 2: {
      setState(117);
      antlrcpp::downCast<Parameter_listContext *>(_localctx)->ts = type_specifier();
      setState(118);
      antlrcpp::downCast<Parameter_listContext *>(_localctx)->addopToken = match(C8086Parser::ADDOP);

              antlrcpp::downCast<Parameter_listContext *>(_localctx)->line =  antlrcpp::downCast<Parameter_listContext *>(_localctx)->addopToken->getLine();
              writeIntoErrorFile("Error at line " + std::to_string(_localctx->line) + ": syntax error, unexpected ADDOP, expecting RPAREN or COMMA\n");
              writeIntoparserLogFile("Error at line " + std::to_string(_localctx->line) + ": syntax error, unexpected ADDOP, expecting RPAREN or COMMA\n");
              
      break;
    }

    case 3: {
      setState(121);
      antlrcpp::downCast<Parameter_listContext *>(_localctx)->ts = type_specifier();


              antlrcpp::downCast<Parameter_listContext *>(_localctx)->text =  antlrcpp::downCast<Parameter_listContext *>(_localctx)->ts->text ;
              antlrcpp::downCast<Parameter_listContext *>(_localctx)->line =  antlrcpp::downCast<Parameter_listContext *>(_localctx)->ts->line;
              _localctx->plist.push_back(std::make_pair(antlrcpp::downCast<Parameter_listContext *>(_localctx)->ts->text, ""));
              writeIntoparserLogFile("Line " + std::to_string(_localctx->line) + ": parameter_list : type_specifier \n" +antlrcpp::downCast<Parameter_listContext *>(_localctx)->ts->text+ "\n");
      		
      break;
    }

    case 4: {
      setState(124);
      antlrcpp::downCast<Parameter_listContext *>(_localctx)->addopToken = match(C8086Parser::ADDOP);

              antlrcpp::downCast<Parameter_listContext *>(_localctx)->line =  antlrcpp::downCast<Parameter_listContext *>(_localctx)->addopToken->getLine();
              writeIntoErrorFile("Error at line " + std::to_string(_localctx->line) + ": syntax error, unexpected ADDOP, expecting RPAREN or COMMA\n");
              writeIntoparserLogFile("Error at line " + std::to_string(_localctx->line) + ": syntax error, unexpected ADDOP, expecting RPAREN or COMMA\n");
              
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(145);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(143);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<Parameter_listContext>(parentContext, parentState);
          _localctx->pl = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleParameter_list);
          setState(128);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(129);
          antlrcpp::downCast<Parameter_listContext *>(_localctx)->commaToken = match(C8086Parser::COMMA);
          setState(130);
          antlrcpp::downCast<Parameter_listContext *>(_localctx)->ts = type_specifier();
          setState(131);
          antlrcpp::downCast<Parameter_listContext *>(_localctx)->idToken = match(C8086Parser::ID);

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
          setState(134);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(135);
          antlrcpp::downCast<Parameter_listContext *>(_localctx)->commaToken = match(C8086Parser::COMMA);
          setState(136);
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
          setState(139);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(140);
          antlrcpp::downCast<Parameter_listContext *>(_localctx)->commaToken = match(C8086Parser::COMMA);
          setState(141);
          antlrcpp::downCast<Parameter_listContext *>(_localctx)->addopToken = match(C8086Parser::ADDOP);

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
      setState(147);
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

C8086Parser::Compound_statementContext::Compound_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* C8086Parser::Compound_statementContext::LCURL() {
  return getToken(C8086Parser::LCURL, 0);
}

tree::TerminalNode* C8086Parser::Compound_statementContext::RCURL() {
  return getToken(C8086Parser::RCURL, 0);
}

C8086Parser::StatementsContext* C8086Parser::Compound_statementContext::statements() {
  return getRuleContext<C8086Parser::StatementsContext>(0);
}


size_t C8086Parser::Compound_statementContext::getRuleIndex() const {
  return C8086Parser::RuleCompound_statement;
}

void C8086Parser::Compound_statementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCompound_statement(this);
}

void C8086Parser::Compound_statementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCompound_statement(this);
}

C8086Parser::Compound_statementContext* C8086Parser::compound_statement() {
  Compound_statementContext *_localctx = _tracker.createInstance<Compound_statementContext>(_ctx, getState());
  enterRule(_localctx, 12, C8086Parser::RuleCompound_statement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(158);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(148);
      antlrcpp::downCast<Compound_statementContext *>(_localctx)->lcurlToken = match(C8086Parser::LCURL);
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
              
               
      setState(150);
      antlrcpp::downCast<Compound_statementContext *>(_localctx)->ss = statements(0);
       
              // std::cout << "ss  type"<<antlrcpp::downCast<Compound_statementContext *>(_localctx)->ss->type <<std::endl;
              antlrcpp::downCast<Compound_statementContext *>(_localctx)->type =  antlrcpp::downCast<Compound_statementContext *>(_localctx)->ss->type;
          
      setState(152);
      antlrcpp::downCast<Compound_statementContext *>(_localctx)->rcurlToken = match(C8086Parser::RCURL);

              antlrcpp::downCast<Compound_statementContext *>(_localctx)->text =  antlrcpp::downCast<Compound_statementContext *>(_localctx)->lcurlToken->getText()+"\n" + antlrcpp::downCast<Compound_statementContext *>(_localctx)->ss->text +"\n" + antlrcpp::downCast<Compound_statementContext *>(_localctx)->rcurlToken->getText();
              antlrcpp::downCast<Compound_statementContext *>(_localctx)->line =  (antlrcpp::downCast<Compound_statementContext *>(_localctx)->rcurlToken != nullptr ? antlrcpp::downCast<Compound_statementContext *>(_localctx)->rcurlToken->getLine() : 0);
              writeIntoparserLogFile("Line "+std::to_string(_localctx->line)+": compound_statement : LCURL statements RCURL\n\n"+_localctx->text+"\n");
              symbolTable->print_all_scope_table2(parserLogFile);
              symbolTable->ExitScope();


          
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(155);
      antlrcpp::downCast<Compound_statementContext *>(_localctx)->lcurlToken = match(C8086Parser::LCURL);
      setState(156);
      match(C8086Parser::RCURL);


              antlrcpp::downCast<Compound_statementContext *>(_localctx)->text =  antlrcpp::downCast<Compound_statementContext *>(_localctx)->lcurlToken->getText();
              antlrcpp::downCast<Compound_statementContext *>(_localctx)->line =  antlrcpp::downCast<Compound_statementContext *>(_localctx)->lcurlToken->getLine();
              antlrcpp::downCast<Compound_statementContext *>(_localctx)->type =  "void"; 
          //    symbolTable->print_current_scope_table(parserLogFile);


          
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

C8086Parser::Var_declarationContext::Var_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C8086Parser::Type_specifierContext* C8086Parser::Var_declarationContext::type_specifier() {
  return getRuleContext<C8086Parser::Type_specifierContext>(0);
}

C8086Parser::Declaration_listContext* C8086Parser::Var_declarationContext::declaration_list() {
  return getRuleContext<C8086Parser::Declaration_listContext>(0);
}

tree::TerminalNode* C8086Parser::Var_declarationContext::SEMICOLON() {
  return getToken(C8086Parser::SEMICOLON, 0);
}

C8086Parser::Declaration_list_errContext* C8086Parser::Var_declarationContext::declaration_list_err() {
  return getRuleContext<C8086Parser::Declaration_list_errContext>(0);
}


size_t C8086Parser::Var_declarationContext::getRuleIndex() const {
  return C8086Parser::RuleVar_declaration;
}

void C8086Parser::Var_declarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVar_declaration(this);
}

void C8086Parser::Var_declarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVar_declaration(this);
}

C8086Parser::Var_declarationContext* C8086Parser::var_declaration() {
  Var_declarationContext *_localctx = _tracker.createInstance<Var_declarationContext>(_ctx, getState());
  enterRule(_localctx, 14, C8086Parser::RuleVar_declaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(170);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(160);
      antlrcpp::downCast<Var_declarationContext *>(_localctx)->t = type_specifier();
      setState(161);
      antlrcpp::downCast<Var_declarationContext *>(_localctx)->dl = declaration_list(0);
      setState(162);
      antlrcpp::downCast<Var_declarationContext *>(_localctx)->sm = match(C8086Parser::SEMICOLON);

              antlrcpp::downCast<Var_declarationContext *>(_localctx)->text =  antlrcpp::downCast<Var_declarationContext *>(_localctx)->t->text +" "+ antlrcpp::downCast<Var_declarationContext *>(_localctx)->dl->text + antlrcpp::downCast<Var_declarationContext *>(_localctx)->sm->getText() ;
              antlrcpp::downCast<Var_declarationContext *>(_localctx)->line =  antlrcpp::downCast<Var_declarationContext *>(_localctx)->t->line;
              writeIntoparserLogFile("Line "+std::to_string(_localctx->line)+": var_declaration : type_specifier declaration_list SEMICOLON\n\n"+_localctx->text+"\n");

              // writeIntoparserLogFile(
              //     std::string("Variable Declaration: type_specifier declaration_list ") +
              //     std::to_string(antlrcpp::downCast<Var_declarationContext *>(_localctx)->sm->getType()) +
              //     " at line " + std::to_string(antlrcpp::downCast<Var_declarationContext *>(_localctx)->sm->getLine())
              // );

              // writeIntoparserLogFile("type_specifier name_line: " + antlrcpp::downCast<Var_declarationContext *>(_localctx)->t->text);

              // std::stringstream ss(antlrcpp::downCast<Var_declarationContext *>(_localctx)->dl->text);

              // std::string name;

              // while(std::getline(ss,name,',')){ 
              //     name.erase(0, name.find_first_not_of(" \t"));
              //     name.erase(name.find_last_not_of(" \t") + 1);

              //     if(!symbolTable->Insert(name,"ID")){   
              //         writeIntoparserLogFile("Error at line "+std::to_string(_localctx->line)+": Multiple declaration of "+name+"\n");
              //         writeIntoErrorFile("Error at line "+std::to_string(_localctx->line)+":  Multiple declaration of "+name+"\n");
              //     }
              //  }

              for(const auto& var : antlrcpp::downCast<Var_declarationContext *>(_localctx)->dl->varList) {
                  SymbolInfo* varSymbol = new SymbolInfo(var.first, "ID");
                  varSymbol->setIsArray(var.second);
                 // std::cout<<"is array true nakke"<<varSymbol->getIsArray()<<var.second << std::endl;
                  varSymbol->setSymbolDataType(antlrcpp::downCast<Var_declarationContext *>(_localctx)->t->type);
                 // std::cout<<"vartype ki set hocche check"<<varSymbol->getSymbolDataType() << std::endl;
                  if(!symbolTable->Insert(varSymbol)){
                      writeIntoparserLogFile("Error at line "+std::to_string(_localctx->line)+":  Multiple declaration of "+var.first+"\n");
                      writeIntoErrorFile("Error at line "+std::to_string(_localctx->line)+": Multiple declaration of "+var.first+"\n");
                                      errorCount++;

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
      setState(165);
      antlrcpp::downCast<Var_declarationContext *>(_localctx)->t = type_specifier();
      setState(166);
      antlrcpp::downCast<Var_declarationContext *>(_localctx)->de = declaration_list_err();
      setState(167);
      antlrcpp::downCast<Var_declarationContext *>(_localctx)->sm = match(C8086Parser::SEMICOLON);

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

C8086Parser::Declaration_list_errContext::Declaration_list_errContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t C8086Parser::Declaration_list_errContext::getRuleIndex() const {
  return C8086Parser::RuleDeclaration_list_err;
}

void C8086Parser::Declaration_list_errContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDeclaration_list_err(this);
}

void C8086Parser::Declaration_list_errContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDeclaration_list_err(this);
}

C8086Parser::Declaration_list_errContext* C8086Parser::declaration_list_err() {
  Declaration_list_errContext *_localctx = _tracker.createInstance<Declaration_list_errContext>(_ctx, getState());
  enterRule(_localctx, 16, C8086Parser::RuleDeclaration_list_err);

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

C8086Parser::Type_specifierContext::Type_specifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* C8086Parser::Type_specifierContext::INT() {
  return getToken(C8086Parser::INT, 0);
}

tree::TerminalNode* C8086Parser::Type_specifierContext::FLOAT() {
  return getToken(C8086Parser::FLOAT, 0);
}

tree::TerminalNode* C8086Parser::Type_specifierContext::VOID() {
  return getToken(C8086Parser::VOID, 0);
}


size_t C8086Parser::Type_specifierContext::getRuleIndex() const {
  return C8086Parser::RuleType_specifier;
}

void C8086Parser::Type_specifierContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterType_specifier(this);
}

void C8086Parser::Type_specifierContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitType_specifier(this);
}

C8086Parser::Type_specifierContext* C8086Parser::type_specifier() {
  Type_specifierContext *_localctx = _tracker.createInstance<Type_specifierContext>(_ctx, getState());
  enterRule(_localctx, 18, C8086Parser::RuleType_specifier);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(180);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case C8086Parser::INT: {
        enterOuterAlt(_localctx, 1);
        setState(174);
        antlrcpp::downCast<Type_specifierContext *>(_localctx)->intToken = match(C8086Parser::INT);

                    antlrcpp::downCast<Type_specifierContext *>(_localctx)->text =  antlrcpp::downCast<Type_specifierContext *>(_localctx)->intToken->getText();
                    antlrcpp::downCast<Type_specifierContext *>(_localctx)->line =  antlrcpp::downCast<Type_specifierContext *>(_localctx)->intToken->getLine();
                    antlrcpp::downCast<Type_specifierContext *>(_localctx)->type =  "int";
        			writeIntoparserLogFile("Line " + std::to_string(antlrcpp::downCast<Type_specifierContext *>(_localctx)->intToken->getLine()) + ": type_specifier : INT\n\n" + antlrcpp::downCast<Type_specifierContext *>(_localctx)->intToken->getText() + "\n");
                    if(multipleDeclaration){

                    }
                
        break;
      }

      case C8086Parser::FLOAT: {
        enterOuterAlt(_localctx, 2);
        setState(176);
        antlrcpp::downCast<Type_specifierContext *>(_localctx)->floatToken = match(C8086Parser::FLOAT);

                    antlrcpp::downCast<Type_specifierContext *>(_localctx)->text =  antlrcpp::downCast<Type_specifierContext *>(_localctx)->floatToken->getText();
                    antlrcpp::downCast<Type_specifierContext *>(_localctx)->line =  antlrcpp::downCast<Type_specifierContext *>(_localctx)->floatToken->getLine();
                    antlrcpp::downCast<Type_specifierContext *>(_localctx)->type =  "float";
        			writeIntoparserLogFile("Line " + std::to_string(antlrcpp::downCast<Type_specifierContext *>(_localctx)->floatToken->getLine()) + ": type_specifier : FLOAT\n\n" +antlrcpp::downCast<Type_specifierContext *>(_localctx)->floatToken->getText() + "\n");        
        		
        break;
      }

      case C8086Parser::VOID: {
        enterOuterAlt(_localctx, 3);
        setState(178);
        antlrcpp::downCast<Type_specifierContext *>(_localctx)->voidToken = match(C8086Parser::VOID);

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

C8086Parser::Declaration_listContext::Declaration_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* C8086Parser::Declaration_listContext::ID() {
  return getToken(C8086Parser::ID, 0);
}

tree::TerminalNode* C8086Parser::Declaration_listContext::LTHIRD() {
  return getToken(C8086Parser::LTHIRD, 0);
}

tree::TerminalNode* C8086Parser::Declaration_listContext::CONST_INT() {
  return getToken(C8086Parser::CONST_INT, 0);
}

tree::TerminalNode* C8086Parser::Declaration_listContext::RTHIRD() {
  return getToken(C8086Parser::RTHIRD, 0);
}

tree::TerminalNode* C8086Parser::Declaration_listContext::COMMA() {
  return getToken(C8086Parser::COMMA, 0);
}

C8086Parser::Declaration_listContext* C8086Parser::Declaration_listContext::declaration_list() {
  return getRuleContext<C8086Parser::Declaration_listContext>(0);
}


size_t C8086Parser::Declaration_listContext::getRuleIndex() const {
  return C8086Parser::RuleDeclaration_list;
}

void C8086Parser::Declaration_listContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDeclaration_list(this);
}

void C8086Parser::Declaration_listContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDeclaration_list(this);
}


C8086Parser::Declaration_listContext* C8086Parser::declaration_list() {
   return declaration_list(0);
}

C8086Parser::Declaration_listContext* C8086Parser::declaration_list(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  C8086Parser::Declaration_listContext *_localctx = _tracker.createInstance<Declaration_listContext>(_ctx, parentState);
  C8086Parser::Declaration_listContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 20;
  enterRecursionRule(_localctx, 20, C8086Parser::RuleDeclaration_list, precedence);

    

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
    setState(190);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx)) {
    case 1: {
      setState(183);
      antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken = match(C8086Parser::ID);
       
              antlrcpp::downCast<Declaration_listContext *>(_localctx)->text =  antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken->getText();
              antlrcpp::downCast<Declaration_listContext *>(_localctx)->line =  antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken->getLine();
              _localctx->varList.push_back(std::make_pair(antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken->getText(), false));
              writeIntoparserLogFile("Line " + std::to_string(_localctx->line) + ": declaration_list : ID\n\n" +_localctx->text + "\n");        

          
      break;
    }

    case 2: {
      setState(185);
      antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken = match(C8086Parser::ID);
      setState(186);
      antlrcpp::downCast<Declaration_listContext *>(_localctx)->lthirdToken = match(C8086Parser::LTHIRD);
      setState(187);
      antlrcpp::downCast<Declaration_listContext *>(_localctx)->const_intToken = match(C8086Parser::CONST_INT);
      setState(188);
      antlrcpp::downCast<Declaration_listContext *>(_localctx)->rthirdToken = match(C8086Parser::RTHIRD);
       
              antlrcpp::downCast<Declaration_listContext *>(_localctx)->text =  antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken->getText() + antlrcpp::downCast<Declaration_listContext *>(_localctx)->lthirdToken->getText() + antlrcpp::downCast<Declaration_listContext *>(_localctx)->const_intToken->getText() + antlrcpp::downCast<Declaration_listContext *>(_localctx)->rthirdToken->getText();
              antlrcpp::downCast<Declaration_listContext *>(_localctx)->line =  antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken->getLine();

              antlrcpp::downCast<Declaration_listContext *>(_localctx)->type =  "array";
              _localctx->varList.push_back(std::make_pair(antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken->getText(), true));

              
              writeIntoparserLogFile("Line " + std::to_string(_localctx->line) + ": declaration_list : ID LTHIRD CONST_INT RTHIRD\n\n" +_localctx->text + "\n");        

          
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(205);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(203);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<Declaration_listContext>(parentContext, parentState);
          _localctx->dl = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleDeclaration_list);
          setState(192);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(193);
          antlrcpp::downCast<Declaration_listContext *>(_localctx)->commaToken = match(C8086Parser::COMMA);
          setState(194);
          antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken = match(C8086Parser::ID);
           

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
          setState(196);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(197);
          antlrcpp::downCast<Declaration_listContext *>(_localctx)->commaToken = match(C8086Parser::COMMA);
          setState(198);
          antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken = match(C8086Parser::ID);
          setState(199);
          antlrcpp::downCast<Declaration_listContext *>(_localctx)->lthirdToken = match(C8086Parser::LTHIRD);
          setState(200);
          antlrcpp::downCast<Declaration_listContext *>(_localctx)->const_intToken = match(C8086Parser::CONST_INT);
          setState(201);
          antlrcpp::downCast<Declaration_listContext *>(_localctx)->rthirdToken = match(C8086Parser::RTHIRD);
           
                            antlrcpp::downCast<Declaration_listContext *>(_localctx)->text =  antlrcpp::downCast<Declaration_listContext *>(_localctx)->dl->text + antlrcpp::downCast<Declaration_listContext *>(_localctx)->commaToken->getText() + antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken->getText() + antlrcpp::downCast<Declaration_listContext *>(_localctx)->lthirdToken->getText() + antlrcpp::downCast<Declaration_listContext *>(_localctx)->const_intToken->getText() + antlrcpp::downCast<Declaration_listContext *>(_localctx)->rthirdToken->getText();
                            antlrcpp::downCast<Declaration_listContext *>(_localctx)->line =  antlrcpp::downCast<Declaration_listContext *>(_localctx)->rthirdToken->getLine();
                            antlrcpp::downCast<Declaration_listContext *>(_localctx)->varList =  antlrcpp::downCast<Declaration_listContext *>(_localctx)->dl->varList;
                    		_localctx->varList.push_back(std::make_pair(antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken->getText(), true));
                            
                            writeIntoparserLogFile("Line " + std::to_string(_localctx->line) + ": declaration_list : declaration_list COMMA ID LTHIRD CONST_INT RTHIRD\n\n" +_localctx->text + "\n");        

                        
          break;
        }

        default:
          break;
        } 
      }
      setState(207);
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

C8086Parser::StatementsContext::StatementsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C8086Parser::StatementContext* C8086Parser::StatementsContext::statement() {
  return getRuleContext<C8086Parser::StatementContext>(0);
}

C8086Parser::StatementsContext* C8086Parser::StatementsContext::statements() {
  return getRuleContext<C8086Parser::StatementsContext>(0);
}


size_t C8086Parser::StatementsContext::getRuleIndex() const {
  return C8086Parser::RuleStatements;
}

void C8086Parser::StatementsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatements(this);
}

void C8086Parser::StatementsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatements(this);
}


C8086Parser::StatementsContext* C8086Parser::statements() {
   return statements(0);
}

C8086Parser::StatementsContext* C8086Parser::statements(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  C8086Parser::StatementsContext *_localctx = _tracker.createInstance<StatementsContext>(_ctx, parentState);
  C8086Parser::StatementsContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 22;
  enterRecursionRule(_localctx, 22, C8086Parser::RuleStatements, precedence);

    

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
    setState(209);
    antlrcpp::downCast<StatementsContext *>(_localctx)->s = statement();

            antlrcpp::downCast<StatementsContext *>(_localctx)->text =  antlrcpp::downCast<StatementsContext *>(_localctx)->s->text;
            antlrcpp::downCast<StatementsContext *>(_localctx)->line =  antlrcpp::downCast<StatementsContext *>(_localctx)->s->line;
            antlrcpp::downCast<StatementsContext *>(_localctx)->type =  antlrcpp::downCast<StatementsContext *>(_localctx)->s->type;
                    // std::cout << "s  type"<<antlrcpp::downCast<StatementsContext *>(_localctx)->s->type <<std::endl;

            writeIntoparserLogFile("Line " + std::to_string(_localctx->line) + ": statements : statement\n\n" + _localctx->text+"\n"); 
        
    _ctx->stop = _input->LT(-1);
    setState(218);
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
        setState(212);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(213);
        antlrcpp::downCast<StatementsContext *>(_localctx)->s = statement();

                          antlrcpp::downCast<StatementsContext *>(_localctx)->text =  antlrcpp::downCast<StatementsContext *>(_localctx)->ss->text +"\n" + antlrcpp::downCast<StatementsContext *>(_localctx)->s->text;
                          antlrcpp::downCast<StatementsContext *>(_localctx)->line =  antlrcpp::downCast<StatementsContext *>(_localctx)->s->line;
                          antlrcpp::downCast<StatementsContext *>(_localctx)->type =  antlrcpp::downCast<StatementsContext *>(_localctx)->s->type;
                                  // std::cout << "s  type"<<antlrcpp::downCast<StatementsContext *>(_localctx)->s->type <<std::endl;

                          writeIntoparserLogFile("Line " + std::to_string(_localctx->line) + ": statements : statements statement\n\n" +_localctx->text+"\n"); 

                       
      }
      setState(220);
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

C8086Parser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C8086Parser::Var_declarationContext* C8086Parser::StatementContext::var_declaration() {
  return getRuleContext<C8086Parser::Var_declarationContext>(0);
}

std::vector<C8086Parser::Expression_statementContext *> C8086Parser::StatementContext::expression_statement() {
  return getRuleContexts<C8086Parser::Expression_statementContext>();
}

C8086Parser::Expression_statementContext* C8086Parser::StatementContext::expression_statement(size_t i) {
  return getRuleContext<C8086Parser::Expression_statementContext>(i);
}

C8086Parser::Compound_statementContext* C8086Parser::StatementContext::compound_statement() {
  return getRuleContext<C8086Parser::Compound_statementContext>(0);
}

tree::TerminalNode* C8086Parser::StatementContext::FOR() {
  return getToken(C8086Parser::FOR, 0);
}

tree::TerminalNode* C8086Parser::StatementContext::LPAREN() {
  return getToken(C8086Parser::LPAREN, 0);
}

tree::TerminalNode* C8086Parser::StatementContext::RPAREN() {
  return getToken(C8086Parser::RPAREN, 0);
}

C8086Parser::ExpressionContext* C8086Parser::StatementContext::expression() {
  return getRuleContext<C8086Parser::ExpressionContext>(0);
}

std::vector<C8086Parser::StatementContext *> C8086Parser::StatementContext::statement() {
  return getRuleContexts<C8086Parser::StatementContext>();
}

C8086Parser::StatementContext* C8086Parser::StatementContext::statement(size_t i) {
  return getRuleContext<C8086Parser::StatementContext>(i);
}

tree::TerminalNode* C8086Parser::StatementContext::IF() {
  return getToken(C8086Parser::IF, 0);
}

tree::TerminalNode* C8086Parser::StatementContext::ELSE() {
  return getToken(C8086Parser::ELSE, 0);
}

tree::TerminalNode* C8086Parser::StatementContext::WHILE() {
  return getToken(C8086Parser::WHILE, 0);
}

tree::TerminalNode* C8086Parser::StatementContext::PRINTLN() {
  return getToken(C8086Parser::PRINTLN, 0);
}

tree::TerminalNode* C8086Parser::StatementContext::ID() {
  return getToken(C8086Parser::ID, 0);
}

tree::TerminalNode* C8086Parser::StatementContext::SEMICOLON() {
  return getToken(C8086Parser::SEMICOLON, 0);
}

tree::TerminalNode* C8086Parser::StatementContext::RETURN() {
  return getToken(C8086Parser::RETURN, 0);
}


size_t C8086Parser::StatementContext::getRuleIndex() const {
  return C8086Parser::RuleStatement;
}

void C8086Parser::StatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatement(this);
}

void C8086Parser::StatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatement(this);
}

C8086Parser::StatementContext* C8086Parser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 24, C8086Parser::RuleStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(273);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(221);
      antlrcpp::downCast<StatementContext *>(_localctx)->v = var_declaration();

              antlrcpp::downCast<StatementContext *>(_localctx)->text =  antlrcpp::downCast<StatementContext *>(_localctx)->v->text;
              antlrcpp::downCast<StatementContext *>(_localctx)->line =  antlrcpp::downCast<StatementContext *>(_localctx)->v->line;
              antlrcpp::downCast<StatementContext *>(_localctx)->type =  "void";
              writeIntoparserLogFile("Line "+  std::to_string(_localctx->line) +": statement : var_declaration\n\n"+_localctx->text + "\n" );
          
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(224);
      antlrcpp::downCast<StatementContext *>(_localctx)->es = expression_statement();

              antlrcpp::downCast<StatementContext *>(_localctx)->text =  antlrcpp::downCast<StatementContext *>(_localctx)->es->text;
              antlrcpp::downCast<StatementContext *>(_localctx)->line =  antlrcpp::downCast<StatementContext *>(_localctx)->es->line;
              antlrcpp::downCast<StatementContext *>(_localctx)->type =  "void";

              writeIntoparserLogFile("Line "+  std::to_string(_localctx->line) +": statement : expression_statement\n\n"+_localctx->text + "\n" );

          
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(227);
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
      setState(230);
      antlrcpp::downCast<StatementContext *>(_localctx)->forToken = match(C8086Parser::FOR);
      setState(231);
      antlrcpp::downCast<StatementContext *>(_localctx)->lparenToken = match(C8086Parser::LPAREN);
      setState(232);
      antlrcpp::downCast<StatementContext *>(_localctx)->es1 = expression_statement();
      setState(233);
      antlrcpp::downCast<StatementContext *>(_localctx)->es2 = expression_statement();
      setState(234);
      antlrcpp::downCast<StatementContext *>(_localctx)->e = expression();
      setState(235);
      antlrcpp::downCast<StatementContext *>(_localctx)->rparenToken = match(C8086Parser::RPAREN);
      setState(236);
      antlrcpp::downCast<StatementContext *>(_localctx)->s = statement();

              antlrcpp::downCast<StatementContext *>(_localctx)->text =  (antlrcpp::downCast<StatementContext *>(_localctx)->forToken != nullptr ? antlrcpp::downCast<StatementContext *>(_localctx)->forToken->getText() : "") +  antlrcpp::downCast<StatementContext *>(_localctx)->lparenToken->getText() +  antlrcpp::downCast<StatementContext *>(_localctx)->es1->text + antlrcpp::downCast<StatementContext *>(_localctx)->es2->text + antlrcpp::downCast<StatementContext *>(_localctx)->e->text   + antlrcpp::downCast<StatementContext *>(_localctx)->rparenToken->getText() + antlrcpp::downCast<StatementContext *>(_localctx)->s->text;
              antlrcpp::downCast<StatementContext *>(_localctx)->line =  antlrcpp::downCast<StatementContext *>(_localctx)->s->line;
              antlrcpp::downCast<StatementContext *>(_localctx)->type =  "void";

              writeIntoparserLogFile("Line " + std::to_string(antlrcpp::downCast<StatementContext *>(_localctx)->s->line) + ": statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement\n\n" + _localctx->text +"\n"); 

          
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(239);
      antlrcpp::downCast<StatementContext *>(_localctx)->ifToken = match(C8086Parser::IF);
      setState(240);
      antlrcpp::downCast<StatementContext *>(_localctx)->lparenToken = match(C8086Parser::LPAREN);
      setState(241);
      antlrcpp::downCast<StatementContext *>(_localctx)->e = expression();
      setState(242);
      antlrcpp::downCast<StatementContext *>(_localctx)->rparenToken = match(C8086Parser::RPAREN);
      setState(243);
      antlrcpp::downCast<StatementContext *>(_localctx)->s = statement();


              antlrcpp::downCast<StatementContext *>(_localctx)->text =  antlrcpp::downCast<StatementContext *>(_localctx)->ifToken->getText()+ antlrcpp::downCast<StatementContext *>(_localctx)->lparenToken->getText()+ antlrcpp::downCast<StatementContext *>(_localctx)->e->text  + antlrcpp::downCast<StatementContext *>(_localctx)->rparenToken->getText() +antlrcpp::downCast<StatementContext *>(_localctx)->s->text;
              antlrcpp::downCast<StatementContext *>(_localctx)->line =  antlrcpp::downCast<StatementContext *>(_localctx)->ifToken->getLine();
              antlrcpp::downCast<StatementContext *>(_localctx)->type =  "void";

              writeIntoparserLogFile("Line " + std::to_string(_localctx->line) + ": statement : IF LPAREN expression RPAREN statement\n\n" + _localctx->text +"\n"); 

          
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(246);
      antlrcpp::downCast<StatementContext *>(_localctx)->ifToken = match(C8086Parser::IF);
      setState(247);
      antlrcpp::downCast<StatementContext *>(_localctx)->lparenToken = match(C8086Parser::LPAREN);
      setState(248);
      antlrcpp::downCast<StatementContext *>(_localctx)->e = expression();
      setState(249);
      antlrcpp::downCast<StatementContext *>(_localctx)->rparenToken = match(C8086Parser::RPAREN);
      setState(250);
      antlrcpp::downCast<StatementContext *>(_localctx)->s1 = statement();
      setState(251);
      antlrcpp::downCast<StatementContext *>(_localctx)->elseToken = match(C8086Parser::ELSE);
      setState(252);
      antlrcpp::downCast<StatementContext *>(_localctx)->s2 = statement();

              antlrcpp::downCast<StatementContext *>(_localctx)->text =  antlrcpp::downCast<StatementContext *>(_localctx)->ifToken->getText() + antlrcpp::downCast<StatementContext *>(_localctx)->lparenToken->getText() + antlrcpp::downCast<StatementContext *>(_localctx)->e->text  + antlrcpp::downCast<StatementContext *>(_localctx)->rparenToken->getText() + antlrcpp::downCast<StatementContext *>(_localctx)->s1->text+ antlrcpp::downCast<StatementContext *>(_localctx)->elseToken->getText() +" "+  antlrcpp::downCast<StatementContext *>(_localctx)->s2->text ;
             antlrcpp::downCast<StatementContext *>(_localctx)->line =  antlrcpp::downCast<StatementContext *>(_localctx)->ifToken->getLine();
              antlrcpp::downCast<StatementContext *>(_localctx)->type =  "void";

              writeIntoparserLogFile("Line " + std::to_string(_localctx->line) + ": statement : IF LPAREN expression RPAREN statement ELSE statement\n\n" + _localctx->text +"\n"); 

          
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(255);
      antlrcpp::downCast<StatementContext *>(_localctx)->whileToken = match(C8086Parser::WHILE);
      setState(256);
      antlrcpp::downCast<StatementContext *>(_localctx)->lparenToken = match(C8086Parser::LPAREN);
      setState(257);
      antlrcpp::downCast<StatementContext *>(_localctx)->e = expression();
      setState(258);
      antlrcpp::downCast<StatementContext *>(_localctx)->rparenToken = match(C8086Parser::RPAREN);
      setState(259);
      antlrcpp::downCast<StatementContext *>(_localctx)->s = statement();

              antlrcpp::downCast<StatementContext *>(_localctx)->text =  antlrcpp::downCast<StatementContext *>(_localctx)->whileToken->getText() + antlrcpp::downCast<StatementContext *>(_localctx)->lparenToken->getText() + antlrcpp::downCast<StatementContext *>(_localctx)->e->text  + antlrcpp::downCast<StatementContext *>(_localctx)->rparenToken->getText() + antlrcpp::downCast<StatementContext *>(_localctx)->s->text;
              antlrcpp::downCast<StatementContext *>(_localctx)->line =  antlrcpp::downCast<StatementContext *>(_localctx)->s->line;
              antlrcpp::downCast<StatementContext *>(_localctx)->type =  "void";

              writeIntoparserLogFile("Line " + std::to_string(_localctx->line) + ": statement : WHILE LPAREN expression RPAREN statement\n\n" + _localctx->text +"\n"); 

          
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(262);
      antlrcpp::downCast<StatementContext *>(_localctx)->printlnToken = match(C8086Parser::PRINTLN);
      setState(263);
      antlrcpp::downCast<StatementContext *>(_localctx)->lparenToken = match(C8086Parser::LPAREN);
      setState(264);
      antlrcpp::downCast<StatementContext *>(_localctx)->idToken = match(C8086Parser::ID);
      setState(265);
      antlrcpp::downCast<StatementContext *>(_localctx)->rparenToken = match(C8086Parser::RPAREN);
      setState(266);
      antlrcpp::downCast<StatementContext *>(_localctx)->semicolonToken = match(C8086Parser::SEMICOLON);

              antlrcpp::downCast<StatementContext *>(_localctx)->text =  antlrcpp::downCast<StatementContext *>(_localctx)->printlnToken->getText() + antlrcpp::downCast<StatementContext *>(_localctx)->lparenToken->getText() +  antlrcpp::downCast<StatementContext *>(_localctx)->idToken->getText() +  antlrcpp::downCast<StatementContext *>(_localctx)->rparenToken->getText() +  antlrcpp::downCast<StatementContext *>(_localctx)->semicolonToken->getText();
              antlrcpp::downCast<StatementContext *>(_localctx)->line =  antlrcpp::downCast<StatementContext *>(_localctx)->semicolonToken->getLine();

              antlrcpp::downCast<StatementContext *>(_localctx)->type =  "void";

              writeIntoparserLogFile("Line " + std::to_string(_localctx->line) + ": statement : PRINTLN LPAREN ID RPAREN SEMICOLON\n\n" + _localctx->text +"\n"); 

          
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(268);
      antlrcpp::downCast<StatementContext *>(_localctx)->returnToken = match(C8086Parser::RETURN);
      setState(269);
      antlrcpp::downCast<StatementContext *>(_localctx)->e = expression();
      setState(270);
      antlrcpp::downCast<StatementContext *>(_localctx)->semicolonToken = match(C8086Parser::SEMICOLON);

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

C8086Parser::Expression_statementContext::Expression_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* C8086Parser::Expression_statementContext::SEMICOLON() {
  return getToken(C8086Parser::SEMICOLON, 0);
}

C8086Parser::ExpressionContext* C8086Parser::Expression_statementContext::expression() {
  return getRuleContext<C8086Parser::ExpressionContext>(0);
}


size_t C8086Parser::Expression_statementContext::getRuleIndex() const {
  return C8086Parser::RuleExpression_statement;
}

void C8086Parser::Expression_statementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpression_statement(this);
}

void C8086Parser::Expression_statementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpression_statement(this);
}

C8086Parser::Expression_statementContext* C8086Parser::expression_statement() {
  Expression_statementContext *_localctx = _tracker.createInstance<Expression_statementContext>(_ctx, getState());
  enterRule(_localctx, 26, C8086Parser::RuleExpression_statement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(281);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case C8086Parser::SEMICOLON: {
        enterOuterAlt(_localctx, 1);
        setState(275);
        antlrcpp::downCast<Expression_statementContext *>(_localctx)->semicolonToken = match(C8086Parser::SEMICOLON);

                antlrcpp::downCast<Expression_statementContext *>(_localctx)->text =  antlrcpp::downCast<Expression_statementContext *>(_localctx)->semicolonToken->getText();
                antlrcpp::downCast<Expression_statementContext *>(_localctx)->line =  antlrcpp::downCast<Expression_statementContext *>(_localctx)->semicolonToken->getLine();

                writeIntoparserLogFile("Line " + std::to_string(antlrcpp::downCast<Expression_statementContext *>(_localctx)->semicolonToken->getLine()) + ": expression_statement : SEMICOLON\n\n" + _localctx->text +"\n"); 

            
        break;
      }

      case C8086Parser::LPAREN:
      case C8086Parser::ADDOP:
      case C8086Parser::NOT:
      case C8086Parser::ID:
      case C8086Parser::CONST_INT:
      case C8086Parser::CONST_FLOAT: {
        enterOuterAlt(_localctx, 2);
        setState(277);
        antlrcpp::downCast<Expression_statementContext *>(_localctx)->e = expression();
        setState(278);
        antlrcpp::downCast<Expression_statementContext *>(_localctx)->semicolonToken = match(C8086Parser::SEMICOLON);

                antlrcpp::downCast<Expression_statementContext *>(_localctx)->text =  antlrcpp::downCast<Expression_statementContext *>(_localctx)->e->text + antlrcpp::downCast<Expression_statementContext *>(_localctx)->semicolonToken->getText();
                antlrcpp::downCast<Expression_statementContext *>(_localctx)->line =  antlrcpp::downCast<Expression_statementContext *>(_localctx)->semicolonToken->getLine();
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

C8086Parser::VariableContext::VariableContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* C8086Parser::VariableContext::ID() {
  return getToken(C8086Parser::ID, 0);
}

tree::TerminalNode* C8086Parser::VariableContext::LTHIRD() {
  return getToken(C8086Parser::LTHIRD, 0);
}

tree::TerminalNode* C8086Parser::VariableContext::RTHIRD() {
  return getToken(C8086Parser::RTHIRD, 0);
}

C8086Parser::ExpressionContext* C8086Parser::VariableContext::expression() {
  return getRuleContext<C8086Parser::ExpressionContext>(0);
}


size_t C8086Parser::VariableContext::getRuleIndex() const {
  return C8086Parser::RuleVariable;
}

void C8086Parser::VariableContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVariable(this);
}

void C8086Parser::VariableContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVariable(this);
}

C8086Parser::VariableContext* C8086Parser::variable() {
  VariableContext *_localctx = _tracker.createInstance<VariableContext>(_ctx, getState());
  enterRule(_localctx, 28, C8086Parser::RuleVariable);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(291);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(283);
      antlrcpp::downCast<VariableContext *>(_localctx)->idToken = match(C8086Parser::ID);

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
      setState(285);
      antlrcpp::downCast<VariableContext *>(_localctx)->idToken = match(C8086Parser::ID);
      setState(286);
      antlrcpp::downCast<VariableContext *>(_localctx)->lthirdToken = match(C8086Parser::LTHIRD);
      setState(287);
      antlrcpp::downCast<VariableContext *>(_localctx)->e = expression();
      setState(288);
      antlrcpp::downCast<VariableContext *>(_localctx)->rthirdToken = match(C8086Parser::RTHIRD);
       
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

C8086Parser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C8086Parser::Logic_expressionContext* C8086Parser::ExpressionContext::logic_expression() {
  return getRuleContext<C8086Parser::Logic_expressionContext>(0);
}

tree::TerminalNode* C8086Parser::ExpressionContext::ASSIGNOP() {
  return getToken(C8086Parser::ASSIGNOP, 0);
}

C8086Parser::VariableContext* C8086Parser::ExpressionContext::variable() {
  return getRuleContext<C8086Parser::VariableContext>(0);
}


size_t C8086Parser::ExpressionContext::getRuleIndex() const {
  return C8086Parser::RuleExpression;
}

void C8086Parser::ExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpression(this);
}

void C8086Parser::ExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpression(this);
}

C8086Parser::ExpressionContext* C8086Parser::expression() {
  ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, getState());
  enterRule(_localctx, 30, C8086Parser::RuleExpression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(301);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(293);
      antlrcpp::downCast<ExpressionContext *>(_localctx)->l = logic_expression();

                  antlrcpp::downCast<ExpressionContext *>(_localctx)->text = antlrcpp::downCast<ExpressionContext *>(_localctx)->l->text;
                  antlrcpp::downCast<ExpressionContext *>(_localctx)->line = antlrcpp::downCast<ExpressionContext *>(_localctx)->l->line;
                  antlrcpp::downCast<ExpressionContext *>(_localctx)->type =  antlrcpp::downCast<ExpressionContext *>(_localctx)->l->type;
                     antlrcpp::downCast<ExpressionContext *>(_localctx)->argIsArray =  false;
                  // std::cout << "l type"<<antlrcpp::downCast<ExpressionContext *>(_localctx)->l->type <<std::endl;

                  writeIntoparserLogFile("Line "+  std::to_string(antlrcpp::downCast<ExpressionContext *>(_localctx)->l->line)+": expression : logic_expression\n\n" + antlrcpp::downCast<ExpressionContext *>(_localctx)->l->text + "\n"); 
              
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(296);
      antlrcpp::downCast<ExpressionContext *>(_localctx)->v = variable();
      setState(297);
      antlrcpp::downCast<ExpressionContext *>(_localctx)->assignopToken = match(C8086Parser::ASSIGNOP);
      setState(298);
      antlrcpp::downCast<ExpressionContext *>(_localctx)->le = logic_expression();

                  antlrcpp::downCast<ExpressionContext *>(_localctx)->text =  antlrcpp::downCast<ExpressionContext *>(_localctx)->v->text + antlrcpp::downCast<ExpressionContext *>(_localctx)->assignopToken->getText() + antlrcpp::downCast<ExpressionContext *>(_localctx)->le->text;
                  antlrcpp::downCast<ExpressionContext *>(_localctx)->line = antlrcpp::downCast<ExpressionContext *>(_localctx)->le->line;  
                  antlrcpp::downCast<ExpressionContext *>(_localctx)->type =  antlrcpp::downCast<ExpressionContext *>(_localctx)->le->type;
                   antlrcpp::downCast<ExpressionContext *>(_localctx)->argIsArray =  false;
                  SymbolInfo* lookup = symbolTable->LookUP(antlrcpp::downCast<ExpressionContext *>(_localctx)->v->text);



                  if (lookup && antlrcpp::downCast<ExpressionContext *>(_localctx)->v->type != _localctx->type) {
                  
                 // std::cout<<std::to_string(_localctx->line)<<" v=le er bhitor type check v"<<lookup->getSymbolDataType() << " le" << _localctx->type << std::endl;
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

C8086Parser::Logic_expressionContext::Logic_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<C8086Parser::Rel_expressionContext *> C8086Parser::Logic_expressionContext::rel_expression() {
  return getRuleContexts<C8086Parser::Rel_expressionContext>();
}

C8086Parser::Rel_expressionContext* C8086Parser::Logic_expressionContext::rel_expression(size_t i) {
  return getRuleContext<C8086Parser::Rel_expressionContext>(i);
}

tree::TerminalNode* C8086Parser::Logic_expressionContext::LOGICOP() {
  return getToken(C8086Parser::LOGICOP, 0);
}


size_t C8086Parser::Logic_expressionContext::getRuleIndex() const {
  return C8086Parser::RuleLogic_expression;
}

void C8086Parser::Logic_expressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLogic_expression(this);
}

void C8086Parser::Logic_expressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLogic_expression(this);
}

C8086Parser::Logic_expressionContext* C8086Parser::logic_expression() {
  Logic_expressionContext *_localctx = _tracker.createInstance<Logic_expressionContext>(_ctx, getState());
  enterRule(_localctx, 32, C8086Parser::RuleLogic_expression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(311);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(303);
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
      setState(306);
      antlrcpp::downCast<Logic_expressionContext *>(_localctx)->re1 = rel_expression();
      setState(307);
      antlrcpp::downCast<Logic_expressionContext *>(_localctx)->logicopToken = match(C8086Parser::LOGICOP);
      setState(308);
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

C8086Parser::Rel_expressionContext::Rel_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<C8086Parser::Simple_expressionContext *> C8086Parser::Rel_expressionContext::simple_expression() {
  return getRuleContexts<C8086Parser::Simple_expressionContext>();
}

C8086Parser::Simple_expressionContext* C8086Parser::Rel_expressionContext::simple_expression(size_t i) {
  return getRuleContext<C8086Parser::Simple_expressionContext>(i);
}

tree::TerminalNode* C8086Parser::Rel_expressionContext::RELOP() {
  return getToken(C8086Parser::RELOP, 0);
}


size_t C8086Parser::Rel_expressionContext::getRuleIndex() const {
  return C8086Parser::RuleRel_expression;
}

void C8086Parser::Rel_expressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRel_expression(this);
}

void C8086Parser::Rel_expressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRel_expression(this);
}

C8086Parser::Rel_expressionContext* C8086Parser::rel_expression() {
  Rel_expressionContext *_localctx = _tracker.createInstance<Rel_expressionContext>(_ctx, getState());
  enterRule(_localctx, 34, C8086Parser::RuleRel_expression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(321);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(313);
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
      setState(316);
      antlrcpp::downCast<Rel_expressionContext *>(_localctx)->s1 = simple_expression(0);
      setState(317);
      antlrcpp::downCast<Rel_expressionContext *>(_localctx)->relopToken = match(C8086Parser::RELOP);
      setState(318);
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

C8086Parser::Simple_expressionContext::Simple_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C8086Parser::TermContext* C8086Parser::Simple_expressionContext::term() {
  return getRuleContext<C8086Parser::TermContext>(0);
}

tree::TerminalNode* C8086Parser::Simple_expressionContext::ADDOP() {
  return getToken(C8086Parser::ADDOP, 0);
}

C8086Parser::Simple_expressionContext* C8086Parser::Simple_expressionContext::simple_expression() {
  return getRuleContext<C8086Parser::Simple_expressionContext>(0);
}


size_t C8086Parser::Simple_expressionContext::getRuleIndex() const {
  return C8086Parser::RuleSimple_expression;
}

void C8086Parser::Simple_expressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSimple_expression(this);
}

void C8086Parser::Simple_expressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSimple_expression(this);
}


C8086Parser::Simple_expressionContext* C8086Parser::simple_expression() {
   return simple_expression(0);
}

C8086Parser::Simple_expressionContext* C8086Parser::simple_expression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  C8086Parser::Simple_expressionContext *_localctx = _tracker.createInstance<Simple_expressionContext>(_ctx, parentState);
  C8086Parser::Simple_expressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 36;
  enterRecursionRule(_localctx, 36, C8086Parser::RuleSimple_expression, precedence);

    

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
    setState(324);
    antlrcpp::downCast<Simple_expressionContext *>(_localctx)->t = term(0);

                antlrcpp::downCast<Simple_expressionContext *>(_localctx)->text =  antlrcpp::downCast<Simple_expressionContext *>(_localctx)->t->text;
                antlrcpp::downCast<Simple_expressionContext *>(_localctx)->line =  antlrcpp::downCast<Simple_expressionContext *>(_localctx)->t->line;
                antlrcpp::downCast<Simple_expressionContext *>(_localctx)->type =  antlrcpp::downCast<Simple_expressionContext *>(_localctx)->t->type;
                antlrcpp::downCast<Simple_expressionContext *>(_localctx)->argIsArray =  antlrcpp::downCast<Simple_expressionContext *>(_localctx)->t->argIsArray;
                writeIntoparserLogFile("Line "+  std::to_string(antlrcpp::downCast<Simple_expressionContext *>(_localctx)->t->line)+": simple_expression : term\n\n" + antlrcpp::downCast<Simple_expressionContext *>(_localctx)->t->text + "\n"); 
                
    _ctx->stop = _input->LT(-1);
    setState(334);
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
        setState(327);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(328);
        antlrcpp::downCast<Simple_expressionContext *>(_localctx)->addopToken = match(C8086Parser::ADDOP);
        setState(329);
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
      setState(336);
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

C8086Parser::TermContext::TermContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C8086Parser::Unary_expressionContext* C8086Parser::TermContext::unary_expression() {
  return getRuleContext<C8086Parser::Unary_expressionContext>(0);
}

tree::TerminalNode* C8086Parser::TermContext::MULOP() {
  return getToken(C8086Parser::MULOP, 0);
}

C8086Parser::TermContext* C8086Parser::TermContext::term() {
  return getRuleContext<C8086Parser::TermContext>(0);
}


size_t C8086Parser::TermContext::getRuleIndex() const {
  return C8086Parser::RuleTerm;
}

void C8086Parser::TermContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTerm(this);
}

void C8086Parser::TermContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTerm(this);
}


C8086Parser::TermContext* C8086Parser::term() {
   return term(0);
}

C8086Parser::TermContext* C8086Parser::term(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  C8086Parser::TermContext *_localctx = _tracker.createInstance<TermContext>(_ctx, parentState);
  C8086Parser::TermContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 38;
  enterRecursionRule(_localctx, 38, C8086Parser::RuleTerm, precedence);

    

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
    setState(338);
    antlrcpp::downCast<TermContext *>(_localctx)->u = unary_expression();

             
                antlrcpp::downCast<TermContext *>(_localctx)->text =  antlrcpp::downCast<TermContext *>(_localctx)->u->text;
                antlrcpp::downCast<TermContext *>(_localctx)->line =  antlrcpp::downCast<TermContext *>(_localctx)->u->line;
                antlrcpp::downCast<TermContext *>(_localctx)->type =  antlrcpp::downCast<TermContext *>(_localctx)->u->type;
               antlrcpp::downCast<TermContext *>(_localctx)->argIsArray =  antlrcpp::downCast<TermContext *>(_localctx)->u->argIsArray; ;
                writeIntoparserLogFile("Line "+  std::to_string(antlrcpp::downCast<TermContext *>(_localctx)->u->line)+": term : unary_expression\n\n" + antlrcpp::downCast<TermContext *>(_localctx)->u->text + "\n");
                
    _ctx->stop = _input->LT(-1);
    setState(348);
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
        setState(341);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(342);
        antlrcpp::downCast<TermContext *>(_localctx)->mulopToken = match(C8086Parser::MULOP);
        setState(343);
        antlrcpp::downCast<TermContext *>(_localctx)->ue = unary_expression();

                      antlrcpp::downCast<TermContext *>(_localctx)->text =  antlrcpp::downCast<TermContext *>(_localctx)->t->text + antlrcpp::downCast<TermContext *>(_localctx)->mulopToken->getText() + antlrcpp::downCast<TermContext *>(_localctx)->ue->text;
                      antlrcpp::downCast<TermContext *>(_localctx)->line =  antlrcpp::downCast<TermContext *>(_localctx)->ue->line;
                      bool print = true;
                      
                      if (antlrcpp::downCast<TermContext *>(_localctx)->mulopToken->getText() == "%") {
                          if (antlrcpp::downCast<TermContext *>(_localctx)->t->type != "int" || antlrcpp::downCast<TermContext *>(_localctx)->ue->type != "int") {
                              writeIntoErrorFile("Error at line " + std::to_string(_localctx->line) + ": Non-Integer operand on modulus operator\n");
                              writeIntoparserLogFile("Line " + std::to_string(_localctx->line) + ": term : term MULOP unary_expression\n");
                              writeIntoparserLogFile("Error at line " + std::to_string(_localctx->line) + ": Non-Integer operand on modulus operator\n\n" + _localctx->text + "\n");
                                              errorCount++;
                              print = false;
                          }
                          else if(antlrcpp::downCast<TermContext *>(_localctx)->ue->text == "0"){
                                          writeIntoErrorFile("Error at line " + std::to_string(_localctx->line) + ": Modulus by Zero\n");

                              writeIntoparserLogFile("Error at line " + std::to_string(_localctx->line) + ": Modulus by Zero\n\n" + _localctx->text + "\n");
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
                      if(print){
                      writeIntoparserLogFile("Line " + std::to_string(_localctx->line) + ": term : term MULOP unary_expression\n\n" + _localctx->text + "\n");
                      }  



                   
      }
      setState(350);
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

C8086Parser::Unary_expressionContext::Unary_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* C8086Parser::Unary_expressionContext::ADDOP() {
  return getToken(C8086Parser::ADDOP, 0);
}

C8086Parser::Unary_expressionContext* C8086Parser::Unary_expressionContext::unary_expression() {
  return getRuleContext<C8086Parser::Unary_expressionContext>(0);
}

tree::TerminalNode* C8086Parser::Unary_expressionContext::NOT() {
  return getToken(C8086Parser::NOT, 0);
}

C8086Parser::FactorContext* C8086Parser::Unary_expressionContext::factor() {
  return getRuleContext<C8086Parser::FactorContext>(0);
}


size_t C8086Parser::Unary_expressionContext::getRuleIndex() const {
  return C8086Parser::RuleUnary_expression;
}

void C8086Parser::Unary_expressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnary_expression(this);
}

void C8086Parser::Unary_expressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnary_expression(this);
}

C8086Parser::Unary_expressionContext* C8086Parser::unary_expression() {
  Unary_expressionContext *_localctx = _tracker.createInstance<Unary_expressionContext>(_ctx, getState());
  enterRule(_localctx, 40, C8086Parser::RuleUnary_expression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(362);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case C8086Parser::ADDOP: {
        enterOuterAlt(_localctx, 1);
        setState(351);
        antlrcpp::downCast<Unary_expressionContext *>(_localctx)->addopToken = match(C8086Parser::ADDOP);
        setState(352);
        antlrcpp::downCast<Unary_expressionContext *>(_localctx)->ue = unary_expression();

                    antlrcpp::downCast<Unary_expressionContext *>(_localctx)->text =  antlrcpp::downCast<Unary_expressionContext *>(_localctx)->addopToken->getText() + antlrcpp::downCast<Unary_expressionContext *>(_localctx)->ue->text;
                    antlrcpp::downCast<Unary_expressionContext *>(_localctx)->line =  antlrcpp::downCast<Unary_expressionContext *>(_localctx)->addopToken->getLine();
                    antlrcpp::downCast<Unary_expressionContext *>(_localctx)->type =  antlrcpp::downCast<Unary_expressionContext *>(_localctx)->ue->type;
                
        break;
      }

      case C8086Parser::NOT: {
        enterOuterAlt(_localctx, 2);
        setState(355);
        antlrcpp::downCast<Unary_expressionContext *>(_localctx)->notToken = match(C8086Parser::NOT);
        setState(356);
        antlrcpp::downCast<Unary_expressionContext *>(_localctx)->ue = unary_expression();

                    antlrcpp::downCast<Unary_expressionContext *>(_localctx)->text =  antlrcpp::downCast<Unary_expressionContext *>(_localctx)->notToken->getText() + antlrcpp::downCast<Unary_expressionContext *>(_localctx)->ue->text;
                    antlrcpp::downCast<Unary_expressionContext *>(_localctx)->line =  antlrcpp::downCast<Unary_expressionContext *>(_localctx)->ue->line;
                    antlrcpp::downCast<Unary_expressionContext *>(_localctx)->type =  antlrcpp::downCast<Unary_expressionContext *>(_localctx)->ue->type;
                    writeIntoparserLogFile("Line "+  std::to_string(_localctx->line)+": unary_expression : NOT unary_expression\n\n" + _localctx->text + "\n");

                
        break;
      }

      case C8086Parser::LPAREN:
      case C8086Parser::ID:
      case C8086Parser::CONST_INT:
      case C8086Parser::CONST_FLOAT: {
        enterOuterAlt(_localctx, 3);
        setState(359);
        antlrcpp::downCast<Unary_expressionContext *>(_localctx)->f = factor();

                    antlrcpp::downCast<Unary_expressionContext *>(_localctx)->text =  antlrcpp::downCast<Unary_expressionContext *>(_localctx)->f->text;
                    antlrcpp::downCast<Unary_expressionContext *>(_localctx)->line =  antlrcpp::downCast<Unary_expressionContext *>(_localctx)->f->line;
                    antlrcpp::downCast<Unary_expressionContext *>(_localctx)->type =  antlrcpp::downCast<Unary_expressionContext *>(_localctx)->f->type;
                    antlrcpp::downCast<Unary_expressionContext *>(_localctx)->argIsArray =  antlrcpp::downCast<Unary_expressionContext *>(_localctx)->f->argIsArray;
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

C8086Parser::FactorContext::FactorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C8086Parser::VariableContext* C8086Parser::FactorContext::variable() {
  return getRuleContext<C8086Parser::VariableContext>(0);
}

tree::TerminalNode* C8086Parser::FactorContext::ID() {
  return getToken(C8086Parser::ID, 0);
}

tree::TerminalNode* C8086Parser::FactorContext::LPAREN() {
  return getToken(C8086Parser::LPAREN, 0);
}

tree::TerminalNode* C8086Parser::FactorContext::RPAREN() {
  return getToken(C8086Parser::RPAREN, 0);
}

C8086Parser::Argument_listContext* C8086Parser::FactorContext::argument_list() {
  return getRuleContext<C8086Parser::Argument_listContext>(0);
}

C8086Parser::ExpressionContext* C8086Parser::FactorContext::expression() {
  return getRuleContext<C8086Parser::ExpressionContext>(0);
}

tree::TerminalNode* C8086Parser::FactorContext::CONST_INT() {
  return getToken(C8086Parser::CONST_INT, 0);
}

tree::TerminalNode* C8086Parser::FactorContext::CONST_FLOAT() {
  return getToken(C8086Parser::CONST_FLOAT, 0);
}

tree::TerminalNode* C8086Parser::FactorContext::INCOP() {
  return getToken(C8086Parser::INCOP, 0);
}

tree::TerminalNode* C8086Parser::FactorContext::DECOP() {
  return getToken(C8086Parser::DECOP, 0);
}


size_t C8086Parser::FactorContext::getRuleIndex() const {
  return C8086Parser::RuleFactor;
}

void C8086Parser::FactorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFactor(this);
}

void C8086Parser::FactorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFactor(this);
}

C8086Parser::FactorContext* C8086Parser::factor() {
  FactorContext *_localctx = _tracker.createInstance<FactorContext>(_ctx, getState());
  enterRule(_localctx, 42, C8086Parser::RuleFactor);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(391);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(364);
      antlrcpp::downCast<FactorContext *>(_localctx)->v = variable();

              antlrcpp::downCast<FactorContext *>(_localctx)->text =  antlrcpp::downCast<FactorContext *>(_localctx)->v->text;
              antlrcpp::downCast<FactorContext *>(_localctx)->line =  antlrcpp::downCast<FactorContext *>(_localctx)->v->line;
              antlrcpp::downCast<FactorContext *>(_localctx)->type =  antlrcpp::downCast<FactorContext *>(_localctx)->v->type;
              antlrcpp::downCast<FactorContext *>(_localctx)->argIsArray =  antlrcpp::downCast<FactorContext *>(_localctx)->v->isArray;
              // std::cout << "v type"<<antlrcpp::downCast<FactorContext *>(_localctx)->v->type <<std::endl;
              writeIntoparserLogFile("Line "+  std::to_string(antlrcpp::downCast<FactorContext *>(_localctx)->v->line)+": factor : variable\n\n" + antlrcpp::downCast<FactorContext *>(_localctx)->v->text + "\n");
              
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(367);
      antlrcpp::downCast<FactorContext *>(_localctx)->idToken = match(C8086Parser::ID);
      setState(368);
      antlrcpp::downCast<FactorContext *>(_localctx)->lparenToken = match(C8086Parser::LPAREN);

              argumentCount = 0;
              argumentTypes.clear();
              argumentIsArray.clear();
          
      setState(370);
      antlrcpp::downCast<FactorContext *>(_localctx)->a = argument_list();
      setState(371);
      antlrcpp::downCast<FactorContext *>(_localctx)->rparenToken = match(C8086Parser::RPAREN);

          antlrcpp::downCast<FactorContext *>(_localctx)->text =  antlrcpp::downCast<FactorContext *>(_localctx)->idToken->getText() + antlrcpp::downCast<FactorContext *>(_localctx)->lparenToken->getText() + antlrcpp::downCast<FactorContext *>(_localctx)->a->text + antlrcpp::downCast<FactorContext *>(_localctx)->rparenToken->getText();
          antlrcpp::downCast<FactorContext *>(_localctx)->line =  antlrcpp::downCast<FactorContext *>(_localctx)->idToken->getLine();
          antlrcpp::downCast<FactorContext *>(_localctx)->type =  antlrcpp::downCast<FactorContext *>(_localctx)->idToken->getType();

          SymbolInfo* func = symbolTable->LookUP(antlrcpp::downCast<FactorContext *>(_localctx)->idToken->getText());
          
          if (func == nullptr) {
              writeIntoErrorFile("Error at line " + std::to_string(_localctx->line) + ": Undefined function " + antlrcpp::downCast<FactorContext *>(_localctx)->idToken->getText() + "\n");
              errorCount++;
          } 
          else if (func->getIsFunction() && func->getIsFunctionDefined()) {
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
      setState(374);
      antlrcpp::downCast<FactorContext *>(_localctx)->lparenToken = match(C8086Parser::LPAREN);
      setState(375);
      antlrcpp::downCast<FactorContext *>(_localctx)->e = expression();
      setState(376);
      antlrcpp::downCast<FactorContext *>(_localctx)->rparenToken = match(C8086Parser::RPAREN);
       
              antlrcpp::downCast<FactorContext *>(_localctx)->text =  antlrcpp::downCast<FactorContext *>(_localctx)->lparenToken->getText() + antlrcpp::downCast<FactorContext *>(_localctx)->e->text + antlrcpp::downCast<FactorContext *>(_localctx)->rparenToken->getText();
              antlrcpp::downCast<FactorContext *>(_localctx)->line =  antlrcpp::downCast<FactorContext *>(_localctx)->rparenToken->getLine();
              antlrcpp::downCast<FactorContext *>(_localctx)->type =  antlrcpp::downCast<FactorContext *>(_localctx)->e->type;
               antlrcpp::downCast<FactorContext *>(_localctx)->argIsArray =  false;
              writeIntoparserLogFile("Line "+  std::to_string(_localctx->line)+": factor : LPAREN expression RPAREN\n\n" + _localctx->text + "\n");

           
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(379);
      antlrcpp::downCast<FactorContext *>(_localctx)->const_intToken = match(C8086Parser::CONST_INT);

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
      setState(381);
      antlrcpp::downCast<FactorContext *>(_localctx)->const_floatToken = match(C8086Parser::CONST_FLOAT);

              antlrcpp::downCast<FactorContext *>(_localctx)->text =  antlrcpp::downCast<FactorContext *>(_localctx)->const_floatToken->getText();
              antlrcpp::downCast<FactorContext *>(_localctx)->line =  antlrcpp::downCast<FactorContext *>(_localctx)->const_floatToken->getLine();
              antlrcpp::downCast<FactorContext *>(_localctx)->type =  "float";
               antlrcpp::downCast<FactorContext *>(_localctx)->argIsArray =  false;
              writeIntoparserLogFile("Line "+  std::to_string(_localctx->line)+": factor : CONST_FLOAT\n\n" + _localctx->text + "\n");

          
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(383);
      antlrcpp::downCast<FactorContext *>(_localctx)->v = variable();
      setState(384);
      antlrcpp::downCast<FactorContext *>(_localctx)->incopToken = match(C8086Parser::INCOP);

              antlrcpp::downCast<FactorContext *>(_localctx)->text =  antlrcpp::downCast<FactorContext *>(_localctx)->v->text+antlrcpp::downCast<FactorContext *>(_localctx)->incopToken->getText();
              antlrcpp::downCast<FactorContext *>(_localctx)->line =  antlrcpp::downCast<FactorContext *>(_localctx)->incopToken->getLine();
              antlrcpp::downCast<FactorContext *>(_localctx)->type =  antlrcpp::downCast<FactorContext *>(_localctx)->v->type;
              writeIntoparserLogFile("Line "+  std::to_string(_localctx->line)+": factor : variable INCOP\n\n" + _localctx->text + "\n");

          
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(387);
      antlrcpp::downCast<FactorContext *>(_localctx)->v = variable();
      setState(388);
      antlrcpp::downCast<FactorContext *>(_localctx)->decopToken = match(C8086Parser::DECOP);

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

C8086Parser::Argument_listContext::Argument_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C8086Parser::ArgumentsContext* C8086Parser::Argument_listContext::arguments() {
  return getRuleContext<C8086Parser::ArgumentsContext>(0);
}


size_t C8086Parser::Argument_listContext::getRuleIndex() const {
  return C8086Parser::RuleArgument_list;
}

void C8086Parser::Argument_listContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArgument_list(this);
}

void C8086Parser::Argument_listContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArgument_list(this);
}

C8086Parser::Argument_listContext* C8086Parser::argument_list() {
  Argument_listContext *_localctx = _tracker.createInstance<Argument_listContext>(_ctx, getState());
  enterRule(_localctx, 44, C8086Parser::RuleArgument_list);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(397);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case C8086Parser::LPAREN:
      case C8086Parser::ADDOP:
      case C8086Parser::NOT:
      case C8086Parser::ID:
      case C8086Parser::CONST_INT:
      case C8086Parser::CONST_FLOAT: {
        enterOuterAlt(_localctx, 1);
        setState(393);
        antlrcpp::downCast<Argument_listContext *>(_localctx)->a = arguments(0);
           
                    antlrcpp::downCast<Argument_listContext *>(_localctx)->text =  antlrcpp::downCast<Argument_listContext *>(_localctx)->a->text;
                    antlrcpp::downCast<Argument_listContext *>(_localctx)->line =  antlrcpp::downCast<Argument_listContext *>(_localctx)->a->line;
                    antlrcpp::downCast<Argument_listContext *>(_localctx)->type =  antlrcpp::downCast<Argument_listContext *>(_localctx)->a->type;
                    
                    writeIntoparserLogFile("Line "+ std::to_string(_localctx->line)+": argument_list : arguments\n\n"+_localctx->text+"\n");
                  
        break;
      }

      case C8086Parser::RPAREN: {
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

C8086Parser::ArgumentsContext::ArgumentsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C8086Parser::Logic_expressionContext* C8086Parser::ArgumentsContext::logic_expression() {
  return getRuleContext<C8086Parser::Logic_expressionContext>(0);
}

tree::TerminalNode* C8086Parser::ArgumentsContext::COMMA() {
  return getToken(C8086Parser::COMMA, 0);
}

C8086Parser::ArgumentsContext* C8086Parser::ArgumentsContext::arguments() {
  return getRuleContext<C8086Parser::ArgumentsContext>(0);
}


size_t C8086Parser::ArgumentsContext::getRuleIndex() const {
  return C8086Parser::RuleArguments;
}

void C8086Parser::ArgumentsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArguments(this);
}

void C8086Parser::ArgumentsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArguments(this);
}


C8086Parser::ArgumentsContext* C8086Parser::arguments() {
   return arguments(0);
}

C8086Parser::ArgumentsContext* C8086Parser::arguments(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  C8086Parser::ArgumentsContext *_localctx = _tracker.createInstance<ArgumentsContext>(_ctx, parentState);
  C8086Parser::ArgumentsContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 46;
  enterRecursionRule(_localctx, 46, C8086Parser::RuleArguments, precedence);

    

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
    setState(400);
    antlrcpp::downCast<ArgumentsContext *>(_localctx)->le = logic_expression();


                antlrcpp::downCast<ArgumentsContext *>(_localctx)->text = antlrcpp::downCast<ArgumentsContext *>(_localctx)->le->text;
                antlrcpp::downCast<ArgumentsContext *>(_localctx)->line = antlrcpp::downCast<ArgumentsContext *>(_localctx)->le->line;
                antlrcpp::downCast<ArgumentsContext *>(_localctx)->type =  antlrcpp::downCast<ArgumentsContext *>(_localctx)->le->type; 
                argumentCount++;  
                argumentTypes.push_back(antlrcpp::downCast<ArgumentsContext *>(_localctx)->le->type);
                argumentIsArray.push_back(antlrcpp::downCast<ArgumentsContext *>(_localctx)->le->argIsArr);
                writeIntoparserLogFile("Line "+ std::to_string(_localctx->line)+": arguments : logic_expression\n\n"+_localctx->text+"\n");


            
    _ctx->stop = _input->LT(-1);
    setState(410);
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
        setState(403);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(404);
        antlrcpp::downCast<ArgumentsContext *>(_localctx)->commaToken = match(C8086Parser::COMMA);
        setState(405);
        antlrcpp::downCast<ArgumentsContext *>(_localctx)->le = logic_expression();
            
                              antlrcpp::downCast<ArgumentsContext *>(_localctx)->text = antlrcpp::downCast<ArgumentsContext *>(_localctx)->a->text +  antlrcpp::downCast<ArgumentsContext *>(_localctx)->commaToken->getText()+  antlrcpp::downCast<ArgumentsContext *>(_localctx)->le->text;
                              antlrcpp::downCast<ArgumentsContext *>(_localctx)->line = antlrcpp::downCast<ArgumentsContext *>(_localctx)->le->line;
                              antlrcpp::downCast<ArgumentsContext *>(_localctx)->type =  antlrcpp::downCast<ArgumentsContext *>(_localctx)->le->type;
                              argumentCount++;
                              argumentTypes.push_back(antlrcpp::downCast<ArgumentsContext *>(_localctx)->le->type);
                              argumentIsArray.push_back(antlrcpp::downCast<ArgumentsContext *>(_localctx)->le->argIsArr);
                              writeIntoparserLogFile("Line "+ std::to_string(_localctx->line)+": arguments : arguments COMMA logic_expression\n\n"+_localctx->text+"\n");

                            
      }
      setState(412);
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

bool C8086Parser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
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

bool C8086Parser::programSempred(ProgramContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

bool C8086Parser::parameter_listSempred(Parameter_listContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 1: return precpred(_ctx, 7);
    case 2: return precpred(_ctx, 6);
    case 3: return precpred(_ctx, 5);

  default:
    break;
  }
  return true;
}

bool C8086Parser::declaration_listSempred(Declaration_listContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 4: return precpred(_ctx, 4);
    case 5: return precpred(_ctx, 3);

  default:
    break;
  }
  return true;
}

bool C8086Parser::statementsSempred(StatementsContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 6: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool C8086Parser::simple_expressionSempred(Simple_expressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 7: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool C8086Parser::termSempred(TermContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 8: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool C8086Parser::argumentsSempred(ArgumentsContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 9: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

void C8086Parser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  c8086parserParserInitialize();
#else
  ::antlr4::internal::call_once(c8086parserParserOnceFlag, c8086parserParserInitialize);
#endif
}
