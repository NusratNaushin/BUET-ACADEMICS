#include <iostream>
#include <fstream>
#include <string>
#include "antlr4-runtime.h"
#include "C2105168Lexer.h"
#include "C2105168Parser.h"

using namespace antlr4;
using namespace std;

ofstream parserLogFile; // global output stream
ofstream errorFile; // global error stream
ofstream lexLogFile; // global lexer log stream
ofstream asmfile;

int syntaxErrorCount;
bool isArray;
std::string currentFunctionReturnType = "";
int argumentCount = 0;
int paramCount = 0;
int errorCount = 0;
bool multipleDeclaration=false;
bool isDATAEmpty = true; 
int label_count = 1; 
int stack_offset_local = 0;
int stack_offset_global = 0;
int param_offset = 2;
bool isInsideFunctionDefinition = false;
bool isParamsymbol = false;
int paramsize = 0;
std::vector<std::string>argumentTypes;
std::vector<std::string>parameterTypes;
std::vector<bool>argumentIsArray;
std::vector<std::string>fndecreturnTypes;
std::vector<std::string>fndefreturnTypes;
std::vector<std::string>elseStatements;
std::vector<std::string>exitLabels;
std::vector<std::string>loopStartLabels;
std::vector<std::string>loopEndLabels;
std::vector<std::string>loopUpdateLabels;
std::vector<std::string> whileStartLabels;
std::vector<std::string> whileEndLabels;

std::vector<std::pair<std::string, std::string>> plist;

int main(int argc, const char* argv[]) {
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " <input_file>" << endl;
        return 1;
    }

    // ---- Input File ----
    ifstream inputFile(argv[1]);
    if (!inputFile.is_open()) {
        cerr << "Error opening input file: " << argv[1] << endl;
        return 1;
    }

    string outputDirectory = "output/";
    string parserLogFileName = outputDirectory + "parserLog.txt";
    string errorFileName = outputDirectory + "errorLog.txt";
    string lexLogFileName = outputDirectory + "lexerLog.txt";
    string asmFileName = outputDirectory + "mycode.asm";
    // create output directory if it doesn't exist
    system(("mkdir -p " + outputDirectory).c_str());

    // ---- Output Files ----
    parserLogFile.open(parserLogFileName);
    if (!parserLogFile.is_open()) {
        cerr << "Error opening parser log file: " << parserLogFileName << endl;
        return 1;
    }

    errorFile.open(errorFileName);
    if (!errorFile.is_open()) {
        cerr << "Error opening error log file: " << errorFileName << endl;
        return 1;
    }

    lexLogFile.open(lexLogFileName);
    if (!lexLogFile.is_open()) {
        cerr << "Error opening lexer log file: " << lexLogFileName << endl;
        return 1;
    }
   
    asmfile.open(asmFileName);
    if (!asmfile.is_open()) {
        cerr << "Error opening assembly file: " << asmFileName << endl;
        return 1;
    }
    // ---- Parsing Flow ----
    ANTLRInputStream input(inputFile);
    C2105168Lexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    C2105168Parser parser(&tokens);

    // this is necessary to avoid the default error listener and use our custom error handling
    parser.removeErrorListeners();

    // start parsing at the 'start' rule
    parser.start();

    // clean up
    inputFile.close();
    parserLogFile.close();
    errorFile.close();
    lexLogFile.close();
    cout << "Parsing completed. Check the output files for details." << endl;
    return 0;
}
