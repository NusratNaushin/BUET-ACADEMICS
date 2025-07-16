
    #pragma once
    #include <iostream>
    #include <fstream>
    #include <string>
    extern std::ofstream lexLogFile;


// Generated from C2105168Lexer.g4 by ANTLR 4.13.2


#include "C2105168Lexer.h"


using namespace antlr4;



using namespace antlr4;

namespace {

struct C2105168LexerStaticData final {
  C2105168LexerStaticData(std::vector<std::string> ruleNames,
                          std::vector<std::string> channelNames,
                          std::vector<std::string> modeNames,
                          std::vector<std::string> literalNames,
                          std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), channelNames(std::move(channelNames)),
        modeNames(std::move(modeNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  C2105168LexerStaticData(const C2105168LexerStaticData&) = delete;
  C2105168LexerStaticData(C2105168LexerStaticData&&) = delete;
  C2105168LexerStaticData& operator=(const C2105168LexerStaticData&) = delete;
  C2105168LexerStaticData& operator=(C2105168LexerStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> channelNames;
  const std::vector<std::string> modeNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag c2105168lexerLexerOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<C2105168LexerStaticData> c2105168lexerLexerStaticData = nullptr;

void c2105168lexerLexerInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (c2105168lexerLexerStaticData != nullptr) {
    return;
  }
#else
  assert(c2105168lexerLexerStaticData == nullptr);
#endif
  auto staticData = std::make_unique<C2105168LexerStaticData>(
    std::vector<std::string>{
      "LINE_COMMENT", "BLOCK_COMMENT", "STRING", "WS", "IF", "ELSE", "FOR", 
      "WHILE", "PRINTLN", "RETURN", "INT", "FLOAT", "VOID", "LPAREN", "RPAREN", 
      "LCURL", "RCURL", "LTHIRD", "RTHIRD", "SEMICOLON", "COMMA", "HASH", 
      "ADDOP", "SUBOP", "MULOP", "INCOP", "DECOP", "NOT", "RELOP", "LOGICOP", 
      "ASSIGNOP", "ID", "CONST_INT", "CONST_FLOAT"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
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
  	4,0,34,271,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,
  	7,14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,
  	7,21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,
  	7,28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,1,0,1,0,1,0,1,
  	0,5,0,74,8,0,10,0,12,0,77,9,0,1,0,1,0,1,0,1,0,1,1,1,1,1,1,1,1,1,1,5,1,
  	88,8,1,10,1,12,1,91,9,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,2,1,2,1,2,5,
  	2,104,8,2,10,2,12,2,107,9,2,1,2,1,2,1,2,1,2,1,2,1,3,4,3,115,8,3,11,3,
  	12,3,116,1,3,1,3,1,4,1,4,1,4,1,5,1,5,1,5,1,5,1,5,1,6,1,6,1,6,1,6,1,7,
  	1,7,1,7,1,7,1,7,1,7,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,9,1,9,1,9,1,9,1,9,1,
  	9,1,9,1,10,1,10,1,10,1,10,1,11,1,11,1,11,1,11,1,11,1,11,1,12,1,12,1,12,
  	1,12,1,12,1,13,1,13,1,14,1,14,1,15,1,15,1,16,1,16,1,17,1,17,1,18,1,18,
  	1,19,1,19,1,20,1,20,1,21,1,21,1,21,1,21,1,22,1,22,1,23,1,23,1,24,1,24,
  	1,25,1,25,1,25,1,26,1,26,1,26,1,27,1,27,1,28,1,28,1,28,1,28,1,28,1,28,
  	1,28,1,28,1,28,3,28,211,8,28,1,29,1,29,1,29,1,29,3,29,217,8,29,1,30,1,
  	30,1,31,1,31,5,31,223,8,31,10,31,12,31,226,9,31,1,32,4,32,229,8,32,11,
  	32,12,32,230,1,33,4,33,234,8,33,11,33,12,33,235,1,33,1,33,5,33,240,8,
  	33,10,33,12,33,243,9,33,3,33,245,8,33,1,33,1,33,3,33,249,8,33,1,33,4,
  	33,252,8,33,11,33,12,33,253,3,33,256,8,33,1,33,1,33,4,33,260,8,33,11,
  	33,12,33,261,1,33,4,33,265,8,33,11,33,12,33,266,1,33,3,33,270,8,33,1,
  	89,0,34,1,1,3,2,5,3,7,4,9,5,11,6,13,7,15,8,17,9,19,10,21,11,23,12,25,
  	13,27,14,29,15,31,16,33,17,35,18,37,19,39,20,41,21,43,22,45,23,47,24,
  	49,25,51,26,53,27,55,28,57,29,59,30,61,31,63,32,65,33,67,34,1,0,10,2,
  	0,10,10,13,13,4,0,10,10,13,13,34,34,92,92,3,0,9,10,12,13,32,32,2,0,43,
  	43,45,45,3,0,37,37,42,42,47,47,2,0,60,60,62,62,3,0,65,90,95,95,97,122,
  	4,0,48,57,65,90,95,95,97,122,1,0,48,57,2,0,69,69,101,101,293,0,1,1,0,
  	0,0,0,3,1,0,0,0,0,5,1,0,0,0,0,7,1,0,0,0,0,9,1,0,0,0,0,11,1,0,0,0,0,13,
  	1,0,0,0,0,15,1,0,0,0,0,17,1,0,0,0,0,19,1,0,0,0,0,21,1,0,0,0,0,23,1,0,
  	0,0,0,25,1,0,0,0,0,27,1,0,0,0,0,29,1,0,0,0,0,31,1,0,0,0,0,33,1,0,0,0,
  	0,35,1,0,0,0,0,37,1,0,0,0,0,39,1,0,0,0,0,41,1,0,0,0,0,43,1,0,0,0,0,45,
  	1,0,0,0,0,47,1,0,0,0,0,49,1,0,0,0,0,51,1,0,0,0,0,53,1,0,0,0,0,55,1,0,
  	0,0,0,57,1,0,0,0,0,59,1,0,0,0,0,61,1,0,0,0,0,63,1,0,0,0,0,65,1,0,0,0,
  	0,67,1,0,0,0,1,69,1,0,0,0,3,82,1,0,0,0,5,99,1,0,0,0,7,114,1,0,0,0,9,120,
  	1,0,0,0,11,123,1,0,0,0,13,128,1,0,0,0,15,132,1,0,0,0,17,138,1,0,0,0,19,
  	145,1,0,0,0,21,152,1,0,0,0,23,156,1,0,0,0,25,162,1,0,0,0,27,167,1,0,0,
  	0,29,169,1,0,0,0,31,171,1,0,0,0,33,173,1,0,0,0,35,175,1,0,0,0,37,177,
  	1,0,0,0,39,179,1,0,0,0,41,181,1,0,0,0,43,183,1,0,0,0,45,187,1,0,0,0,47,
  	189,1,0,0,0,49,191,1,0,0,0,51,193,1,0,0,0,53,196,1,0,0,0,55,199,1,0,0,
  	0,57,210,1,0,0,0,59,216,1,0,0,0,61,218,1,0,0,0,63,220,1,0,0,0,65,228,
  	1,0,0,0,67,269,1,0,0,0,69,70,5,47,0,0,70,71,5,47,0,0,71,75,1,0,0,0,72,
  	74,8,0,0,0,73,72,1,0,0,0,74,77,1,0,0,0,75,73,1,0,0,0,75,76,1,0,0,0,76,
  	78,1,0,0,0,77,75,1,0,0,0,78,79,6,0,0,0,79,80,1,0,0,0,80,81,6,0,1,0,81,
  	2,1,0,0,0,82,83,5,47,0,0,83,84,5,42,0,0,84,89,1,0,0,0,85,88,9,0,0,0,86,
  	88,7,0,0,0,87,85,1,0,0,0,87,86,1,0,0,0,88,91,1,0,0,0,89,90,1,0,0,0,89,
  	87,1,0,0,0,90,92,1,0,0,0,91,89,1,0,0,0,92,93,5,42,0,0,93,94,5,47,0,0,
  	94,95,1,0,0,0,95,96,6,1,2,0,96,97,1,0,0,0,97,98,6,1,1,0,98,4,1,0,0,0,
  	99,105,5,34,0,0,100,101,5,92,0,0,101,104,9,0,0,0,102,104,8,1,0,0,103,
  	100,1,0,0,0,103,102,1,0,0,0,104,107,1,0,0,0,105,103,1,0,0,0,105,106,1,
  	0,0,0,106,108,1,0,0,0,107,105,1,0,0,0,108,109,5,34,0,0,109,110,6,2,3,
  	0,110,111,1,0,0,0,111,112,6,2,1,0,112,6,1,0,0,0,113,115,7,2,0,0,114,113,
  	1,0,0,0,115,116,1,0,0,0,116,114,1,0,0,0,116,117,1,0,0,0,117,118,1,0,0,
  	0,118,119,6,3,1,0,119,8,1,0,0,0,120,121,5,105,0,0,121,122,5,102,0,0,122,
  	10,1,0,0,0,123,124,5,101,0,0,124,125,5,108,0,0,125,126,5,115,0,0,126,
  	127,5,101,0,0,127,12,1,0,0,0,128,129,5,102,0,0,129,130,5,111,0,0,130,
  	131,5,114,0,0,131,14,1,0,0,0,132,133,5,119,0,0,133,134,5,104,0,0,134,
  	135,5,105,0,0,135,136,5,108,0,0,136,137,5,101,0,0,137,16,1,0,0,0,138,
  	139,5,112,0,0,139,140,5,114,0,0,140,141,5,105,0,0,141,142,5,110,0,0,142,
  	143,5,116,0,0,143,144,5,102,0,0,144,18,1,0,0,0,145,146,5,114,0,0,146,
  	147,5,101,0,0,147,148,5,116,0,0,148,149,5,117,0,0,149,150,5,114,0,0,150,
  	151,5,110,0,0,151,20,1,0,0,0,152,153,5,105,0,0,153,154,5,110,0,0,154,
  	155,5,116,0,0,155,22,1,0,0,0,156,157,5,102,0,0,157,158,5,108,0,0,158,
  	159,5,111,0,0,159,160,5,97,0,0,160,161,5,116,0,0,161,24,1,0,0,0,162,163,
  	5,118,0,0,163,164,5,111,0,0,164,165,5,105,0,0,165,166,5,100,0,0,166,26,
  	1,0,0,0,167,168,5,40,0,0,168,28,1,0,0,0,169,170,5,41,0,0,170,30,1,0,0,
  	0,171,172,5,123,0,0,172,32,1,0,0,0,173,174,5,125,0,0,174,34,1,0,0,0,175,
  	176,5,91,0,0,176,36,1,0,0,0,177,178,5,93,0,0,178,38,1,0,0,0,179,180,5,
  	59,0,0,180,40,1,0,0,0,181,182,5,44,0,0,182,42,1,0,0,0,183,184,5,35,0,
  	0,184,185,1,0,0,0,185,186,6,21,1,0,186,44,1,0,0,0,187,188,7,3,0,0,188,
  	46,1,0,0,0,189,190,7,3,0,0,190,48,1,0,0,0,191,192,7,4,0,0,192,50,1,0,
  	0,0,193,194,5,43,0,0,194,195,5,43,0,0,195,52,1,0,0,0,196,197,5,45,0,0,
  	197,198,5,45,0,0,198,54,1,0,0,0,199,200,5,33,0,0,200,56,1,0,0,0,201,202,
  	5,60,0,0,202,211,5,61,0,0,203,204,5,61,0,0,204,211,5,61,0,0,205,206,5,
  	62,0,0,206,211,5,61,0,0,207,211,7,5,0,0,208,209,5,33,0,0,209,211,5,61,
  	0,0,210,201,1,0,0,0,210,203,1,0,0,0,210,205,1,0,0,0,210,207,1,0,0,0,210,
  	208,1,0,0,0,211,58,1,0,0,0,212,213,5,38,0,0,213,217,5,38,0,0,214,215,
  	5,124,0,0,215,217,5,124,0,0,216,212,1,0,0,0,216,214,1,0,0,0,217,60,1,
  	0,0,0,218,219,5,61,0,0,219,62,1,0,0,0,220,224,7,6,0,0,221,223,7,7,0,0,
  	222,221,1,0,0,0,223,226,1,0,0,0,224,222,1,0,0,0,224,225,1,0,0,0,225,64,
  	1,0,0,0,226,224,1,0,0,0,227,229,7,8,0,0,228,227,1,0,0,0,229,230,1,0,0,
  	0,230,228,1,0,0,0,230,231,1,0,0,0,231,66,1,0,0,0,232,234,7,8,0,0,233,
  	232,1,0,0,0,234,235,1,0,0,0,235,233,1,0,0,0,235,236,1,0,0,0,236,244,1,
  	0,0,0,237,241,5,46,0,0,238,240,7,8,0,0,239,238,1,0,0,0,240,243,1,0,0,
  	0,241,239,1,0,0,0,241,242,1,0,0,0,242,245,1,0,0,0,243,241,1,0,0,0,244,
  	237,1,0,0,0,244,245,1,0,0,0,245,255,1,0,0,0,246,248,7,9,0,0,247,249,7,
  	3,0,0,248,247,1,0,0,0,248,249,1,0,0,0,249,251,1,0,0,0,250,252,7,8,0,0,
  	251,250,1,0,0,0,252,253,1,0,0,0,253,251,1,0,0,0,253,254,1,0,0,0,254,256,
  	1,0,0,0,255,246,1,0,0,0,255,256,1,0,0,0,256,270,1,0,0,0,257,259,5,46,
  	0,0,258,260,7,8,0,0,259,258,1,0,0,0,260,261,1,0,0,0,261,259,1,0,0,0,261,
  	262,1,0,0,0,262,270,1,0,0,0,263,265,7,8,0,0,264,263,1,0,0,0,265,266,1,
  	0,0,0,266,264,1,0,0,0,266,267,1,0,0,0,267,268,1,0,0,0,268,270,5,46,0,
  	0,269,233,1,0,0,0,269,257,1,0,0,0,269,264,1,0,0,0,270,68,1,0,0,0,20,0,
  	75,87,89,103,105,116,210,216,224,230,235,241,244,248,253,255,261,266,
  	269,4,1,0,0,6,0,0,1,1,1,1,2,2
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  c2105168lexerLexerStaticData = std::move(staticData);
}

}

C2105168Lexer::C2105168Lexer(CharStream *input) : Lexer(input) {
  C2105168Lexer::initialize();
  _interpreter = new atn::LexerATNSimulator(this, *c2105168lexerLexerStaticData->atn, c2105168lexerLexerStaticData->decisionToDFA, c2105168lexerLexerStaticData->sharedContextCache);
}

C2105168Lexer::~C2105168Lexer() {
  delete _interpreter;
}

std::string C2105168Lexer::getGrammarFileName() const {
  return "C2105168Lexer.g4";
}

const std::vector<std::string>& C2105168Lexer::getRuleNames() const {
  return c2105168lexerLexerStaticData->ruleNames;
}

const std::vector<std::string>& C2105168Lexer::getChannelNames() const {
  return c2105168lexerLexerStaticData->channelNames;
}

const std::vector<std::string>& C2105168Lexer::getModeNames() const {
  return c2105168lexerLexerStaticData->modeNames;
}

const dfa::Vocabulary& C2105168Lexer::getVocabulary() const {
  return c2105168lexerLexerStaticData->vocabulary;
}

antlr4::atn::SerializedATNView C2105168Lexer::getSerializedATN() const {
  return c2105168lexerLexerStaticData->serializedATN;
}

const atn::ATN& C2105168Lexer::getATN() const {
  return *c2105168lexerLexerStaticData->atn;
}


void C2105168Lexer::action(RuleContext *context, size_t ruleIndex, size_t actionIndex) {
  switch (ruleIndex) {
    case 0: LINE_COMMENTAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 1: BLOCK_COMMENTAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 2: STRINGAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;

  default:
    break;
  }
}

void C2105168Lexer::LINE_COMMENTAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 0: 
            writeIntoLexLogFile(
              "Line# " + std::to_string(getLine())
              + ": Token <SINGLE LINE COMMENT> Lexeme "
              + getText()
            );
         break;

  default:
    break;
  }
}

void C2105168Lexer::BLOCK_COMMENTAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 1: 
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
         break;

  default:
    break;
  }
}

void C2105168Lexer::STRINGAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 2: 
            writeIntoLexLogFile(
              "Line# " + std::to_string(getLine())
              + ": Token <STRING> Lexeme " + getText()
            );
         break;

  default:
    break;
  }
}



void C2105168Lexer::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  c2105168lexerLexerInitialize();
#else
  ::antlr4::internal::call_once(c2105168lexerLexerOnceFlag, c2105168lexerLexerInitialize);
#endif
}
