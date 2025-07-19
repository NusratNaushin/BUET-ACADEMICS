#ifndef SYMBOLINFO_H
#define SYMBOLINFO_H
#include <string>
#include <iostream>


// using namespace std;
class SymbolInfo
{
private:
    /* data */
    std::string symbol_name;
    std::string symbol_type;
    std::string symbol_data_type;
    SymbolInfo *next;
    std::string func_name;

    int stack_offset = 0; 

    bool isGlobal = false; 


    
public:

    SymbolInfo(std::string symbol_name , std::string symbol_type){
        this->symbol_name = symbol_name;
        this->symbol_type = symbol_type;
        this->next = NULL;

      //  cout << "Constructor called in symbolinfo class" << endl;


    }
    
    
    std::string getSymbolName(){
        return symbol_name;
    }


    std::string getSymbolType(){
        return symbol_type;
    }

    void setSymbolName(std::string symbol_name){
        this->symbol_name = symbol_name;
    }

    void setSymbolType(std::string symbol_type){
        this->symbol_type = symbol_type;
    }

    void setSymbolDataType(std::string symbol_data_type){
        this->symbol_data_type = symbol_data_type;
    }
    std::string getSymbolDataType(){
        return symbol_data_type;
    }

    SymbolInfo *getNext(){
        return next;
    }

    void setNext(SymbolInfo *next){
        this->next = next;
    }


    bool isFunction = false;
    bool isFunctiondefined = false;
    bool isDeclared = false;
    bool isParameter = false;
    std::string index = "-1"; 
    std::string returnType;
    std::vector<std::pair<std::string, std::string>> parameterList;

    void setReturnType(std::string returnType){
        this->returnType = returnType;
    }
    std::string getReturnType(){
        return returnType;
    }

    void setIsFunction(bool isFunction){
        this->isFunction = isFunction;
    }
    bool getIsFunction(){
        return isFunction;
    }   
    void setIsFunctionDefined(bool isFunctiondefined){
        this->isFunctiondefined = isFunctiondefined;
    }
    bool getIsFunctionDefined(){
        return isFunctiondefined;
    }
    void setIsDeclared(bool isFunctiondefined){
        this->isFunctiondefined = isFunctiondefined;
    }
    bool getIsDeclared(){
        return isFunctiondefined;
    }
    void addParameter(std::string paramName, std::string paramType){
        parameterList.push_back(std::make_pair(paramName, paramType));
    }
    void setParameterList(std::vector<std::pair<std::string, std::string>> plist) {
    parameterList = plist;
    }
    std::vector<std::pair<std::string, std::string>> getParameterList(){
        return parameterList;
    }
    void clearParameterList(){
        parameterList.clear();
    }
    
    bool isArray=false;
    std::string arraysize="-1";

    void setIsArray(bool isArray){
        this->isArray = isArray;
    }
    bool getIsArray(){
        return isArray;
    }
    void setType(std::string type){
        this->symbol_type = type;
    }
    std::string getType(){
        return symbol_type;
    }


    void setStackOffset(int offset) {
        this->stack_offset = offset;
    }

    int getStackOffset() const {
        return stack_offset;
    }

    void setIsGlobal(bool isGlobal) {
        this->isGlobal = isGlobal;
    }

    bool getIsGlobal() const {
        return isGlobal;
    }

    void setIsParameter(bool isParamsymbol) {
        this->isParameter = isParamsymbol;
    }

    bool getIsParameter() const {
        return isParameter;
    }

    void setFunctionName(std::string functionName) {
        this->func_name = functionName;
    }
    std::string getFunctionName() const {
        return func_name;
    }

    std::string getArraySize() const {
        return arraysize;
    }
    void setArraySize(std::string size) {
        this->arraysize = size;
    }

    void setIndex(std::string index) {
        this->index = index;
    }

    std::string getIndex() const {
        return index;
    }

};

// SymbolInfo::~SymbolInfo()
// {
//     //cout << "Destructor called in symbolinfo class" << endl;
// }


// int main(){
//     SymbolInfo *symbol = new SymbolInfo("x" , "int");
// }

#endif //SYMBOLINFO_H