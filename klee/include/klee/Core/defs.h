#ifndef DEFS
#define DEFS

#include <string.h>
#include <ctype.h>
#include <boost/algorithm/string.hpp>
#include <regex>
#include <string>
#include <set>
#include <vector>
#include <map>
#include <iostream>
#include <fstream>
#include <sstream>

// #include <llvm/Support/raw_ostream.h>

// ---------------------
// node
// --------------------

typedef struct node{
    std::string data;
    bool hasData = false;
    std::vector<node*> children;
}node;

node* new_node();
node* new_node(std::string data);
node* new_node(const char* data);
node* new_node(std::initializer_list<node*> args);
void dfs(node* head);

// -----------------------
// varaiables
// -----------------------


enum qualifier{PUBLIC_Q, PRIVATE_Q, PURE_Q, VIEW_Q, PAYABLE_Q};
enum datatype{INT_TYPE, FLOAT_TYPE, UNSIGNED_TYPE, LONG_TYPE, STRING_TYPE, BOOL_TYPE, INT_ARR, BOOL_ARR, STRING_ARR, LONG_ARR, FLOAT_ARR, UNSIGNED_ARR, USERDEF_TYPE, MAP_TYPE, VECTOR_TYPE, STRUCT_TYPE};
enum funcType{RETURN_TYPE = 1, NORETURN_TYPE = 2, CONSTRUCTOR_TYPE = 3, FALLBACK_TYPE = 4, MODIFIER_TYPE = 5};
enum variabletype{SIMPLE, ARRAY, VECTOR, MAP, STRUCTURE, USERDEF, STDSTRING};

//node corresponds to function and variable nodes, std::string corresponds to qualifier
extern std::map<node, std::string> membersQualifiers;

extern std::vector<node> publicMembers;
extern std::vector<node> privateMembers;

extern std::vector<std::string> datatypeStr;
extern std::vector<std::string> functionBlock;
extern std::set<std::string> uniqueVars;

extern std::stringstream writefile;
extern std::stringstream writeDecl;
extern bool ifFallback;
extern bool isReturnIden;


// ---------------------
// class definition
// ---------------------

class Variable{
public:
    std::string name;
    std::string type;
    bool isInitialized;
    bool isConstant;
    variabletype vartype;
    bool canBeSymbolic = false;
    Variable(std::string name, std::string type, variabletype vartype, bool isInitialized = false, bool isConstant = false, bool canBeSymbolic = false){
        this->name = name;
        this->type = type;
        this->vartype = vartype;
        this->isInitialized = isInitialized;
        this->isConstant = isConstant;
    }
};

class FunctionData
{
public:
    std::string name;
    std::vector<std::pair<std::string, std::string>> arguments;
    std::string returnType;
    bool isPure;
    bool isView;
    bool isPayable;
    bool isPublic;
    bool hasTransferFunc;
    std::string block;
    std::string args;

    //which state variables are read/write by this function
    std::vector<Variable*> vars;
    std::map<Variable*, bool> readState;
    std::map<Variable*, bool> writeState;
    funcType type;

    FunctionData();
    FunctionData(std::string name);
    FunctionData(std::string name, std::vector<std::pair<std::string, std::string>> arguments, std::string returnType);

    bool operator<(const FunctionData& obj)
    {
        return this->name < obj.name;
    }
    void printFunctionData();
    void setRWState();
    void convertArgs();
    std::string getName();

    friend std::ostream& operator<< ( std::ostream& outF, const FunctionData& function);
    friend std::istream& operator>> ( std::istream& inF, FunctionData& function);

};

class ContractData
{
public:
    std::string name;
    std::string objectName;
    std::vector<std::pair<std::string, std::string>> stateVariables;
    std::vector<FunctionData*> functions;
    bool hasFallback;
    std::vector<Variable*> vars;
    std::vector<bool> isPublicStateVariable;
    // bool hasConstructor;
    bool hasDefaultConstructor;
    bool hasParaConstructor;
    std::vector<std::string> enumNames;
    std::vector<std::string> structNames;

    ContractData();
    ContractData(std::string name);
    ContractData(std::string name, std::vector<std::pair<std::string, std::string>> stateVariables, std::vector<FunctionData*> functions);

    void printContractData();
    void writeContract();
    ContractData readContract();
    std::vector<FunctionData*> getFunctions();
    std::vector<std::pair<std::string, std::string>> getStateVariables();

    friend std::ostream& operator<< ( std::ostream& out, const ContractData& contract);
    friend std::istream& operator>> ( std::istream& in, ContractData& contract);

};

// -----------------------------
// varaiables
// ------------------------------

extern ContractData contract;
extern std::vector<std::string> contractNames;
extern std::vector<FunctionData*> viewFunctions;
extern std::vector<FunctionData*> payableFunctions;
extern std::vector<FunctionData*> pureFunctions;

// ----------------------------
// function
// ----------------------------

std::string toString(char* input);
char* toChar(std::string input);
char* concatStr(std::initializer_list<char*> args);
std::vector<std::string> split(std::string input, std::string splitter);
void cleanFile(std::ifstream& input, std::ofstream& output);
void setFunctionDataAttr(FunctionData* function, std::vector<std::pair<node*, node*>> funcArgs);
void addClassObject(std::ofstream& output);
int factorial(int n);
void addSymbolicVar(std::ofstream& output, std::vector<std::pair<std::string, std::string>> vars, bool isStateVar);
void addFunctionPerm(std::ofstream& output, std::vector<FunctionData*> todFunctions, int count);
void addMainFunction(std::ofstream& output);
FunctionData* createFunction(enum funcType type, std::initializer_list<node*> args, node* funcAttr);
void createState(std::initializer_list<node*> args, node* varAttr, bool isInitialized);
void createContract(std::initializer_list<node*> args);
void createStruct(std::initializer_list<node*> args);
void createEnum(std::initializer_list<node*> args);
std::vector<node*> listToVec(std::initializer_list<node*>);
void writeDfs(std::vector<node*> args);
void replaceKeywords(std::string filename);
std::string nodeToString(node* head);
void addRetVariables(node* ret, node* block, bool);
node* getRetType(node* ret);
void trimSpace(std::string&);
bool searchPattern(std::string content, std::string ele);
void findTodFunctions(std::vector<FunctionData*>& todFunctions, std::vector<FunctionData*>& restFunctions);

bool checkOverlap(std::string& content);
std::string checkBlockhash(std::string content);
bool canMakeSymbolic(std::string type);
variabletype getType(std::string type);
void rewriteContent(std::string filename);
std::string rewriteArray(std::string content);
std::string rewriteDelete(std::string content);
std::string removeDelete(std::string content);
std::string removeSuper(std::string content);
std::string getDeleteStmt(variabletype type, std::string name);
void writeConstructor(std::stringstream& writefile, std::string name);
void writeConstructor(std::stringstream& writefile, std::string name, std::string member);
node* changeQuotes(node* strNode);
void addModifier(std::vector<node*> modifier, node* block);
node* getRetType(std::vector<node*> retList);
std::string rewriteEnum(std::string content);
void writeAddrConstructor(std::string name);
void clearContractData();
bool inWriteState(Variable* var);
void rewriteSize(std::string& content, std::string pattern);
void addContractName(node* name);
void writeContractNames();
std::vector<std::string> readContractNames();
void writeDfs(std::stringstream& writefile, std::vector<node*> args);

#endif