#include "../../include/klee/Core/defs.h"

// ------------------------
// variables
// ------------------------

ContractData contract;
std::vector<std::string> contractNames;
std::stringstream writefile;
// std::stringstream writeState;
std::stringstream writeDecl;

std::map<node, std::string> membersQualifiers;    // todo: decide datatype
std::vector<node> publicMembers;                  // todo: decide datatype
std::vector<node> privateMembers;                 // todo: decide datatype

std::vector<FunctionData*> viewFunctions;
std::vector<FunctionData*> payableFunctions;
std::vector<FunctionData*> pureFunctions;

std::vector<std::string> datatypeStr{"int", "float", "long", "string", "bool", "unsigned", "address", "int[]", "string[]",
"long[]", "float[]", "userdef", "unsigned[]", "string[]", "address[]", "short"};

std::vector<std::string> functionBlock;

std::set<std::string> uniqueVars;                 //todo

std::map<std::string, std::string> replaceKeywordsMap = {
    {"msg[ ]*\\.[ ]*sender", "msgSender"},
    {"msg[ ]*\\.[ ]*value", "msgValue"},
    {"msg[ ]*\\.[ ]*data", "msgData"},
    {"tx[ ]*\\.[ ]*origin", "txOrigin"},
    {"tx[ ]*\\.[ ]*gasprice", "txGasprice"},
    {"block[ ]*\\.[ ]*number", "blockNumber"},
    {"block[ ]*\\.[ ]*coinbase", "blockCoinbase"},
    {"block[ ]*\\.[ ]*gaslimit", "blockGaslimit"},
    {"block[ ]*\\.[ ]*timestamp", "blockTimestamp"},
    {"block[ ]*\\.[ ]*difficulty", "blockDifficulty"},
    {"\\.[ ]*length", ".size()"},
    {"block[ ]*\\.[ ]*blockhash", "blockhash"},
    {"\\.[ ]*call[ ]*\\.[ ]*value[ ]*\\([a-zA-Z0-9_\\+\\-\\*\\/\\%\\>\\.\\[\\] ]*\\)", ".call"},
    {"\\.[ ]*call[ ]*\\.[ ]*gas[ ]*\\([a-zA-Z0-9_\\+\\-\\*\\/\\%\\>\\.\\[\\] ]*\\)", ".call"},
    {"\\.[ ]*call[ ]*\\.[ ]*value[ ]*\\([a-zA-Z0-9_\\+\\-\\*\\/\\%\\>\\.\\[\\] ]*\\)[ ]*\\.[ ]*gas[ ]*\\([a-zA-Z0-9_\\+\\-\\*\\/\\%\\>\\.\\[\\] ]*\\)", ".call"},
    {"\\.[ ]*call[ ]*\\.[ ]*gas[ ]*\\([a-zA-Z0-9_\\+\\-\\*\\/\\%\\>\\.\\[\\] ]*\\)[ ]*\\.[ ]*value[ ]*\\([a-zA-Z0-9_\\+\\-\\*\\/\\%\\>\\.\\[\\] ]*\\)", ".call"},
    {"\\.[ ]*value[ ]*\\([a-zA-Z0-9_\\+\\-\\*\\/\\%\\>\\.\\[\\] ]*\\)", ""},
    {"\\.[ ]*gas[ ]*\\([a-zA-Z0-9_\\+\\-\\*\\/\\%\\>\\.\\[\\] ]*\\)", ""},
    {"\\.[ ]*value[ ]*\\([a-zA-Z0-9_\\+\\-\\*\\/\\%\\>\\.\\[\\] ]*\\)[ ]*\\.[ ]*gas[ ]*\\([a-zA-Z0-9_\\+\\-\\*\\/\\%\\>\\.\\[\\] ]*\\)", ""},
    {"\\.[ ]*gas[ ]*\\([a-zA-Z0-9_\\+\\-\\*\\/\\%\\>\\.\\[\\] ]*\\)[ ]*\\.[ ]*value[ ]*\\([a-zA-Z0-9_\\+\\-\\*\\/\\%\\>\\.\\[\\] ]*\\)", ""},
    /*{"\\.[ ]*push", ".push_back"},*/
    // {"[^(a-zA-Z0-9)]+\\_[ ]*\\;", " return true; return false;"},
    {"this[ ]*\\.", "this->"},
    {"this[^\\-]", "*this"}
};

// --------------------------------------
// defining node structure
// --------------------------------------

node* new_node(){
    node* temp = new node;
    return temp;
}
node* new_node(std::string content, int line_no){
    node* temp = new node;
    temp->data = content;
    temp->line_no = line_no;
    temp->hasData = true;
    return temp;
}
node* new_node(std::string content){
    node* temp = new node;
    temp->data = content;
    temp->hasData = true;
    return temp;
}
node* new_node(const char* content, int line_no){
    node* temp = new node;
    std::string str(content);
    temp->data = str;
    temp->line_no = line_no;
    temp->hasData = true;
    return temp;
}
node* new_node(const char* content){
    node* temp = new node;
    std::string str(content);
    temp->data = str;
    temp->hasData = true;
    return temp;
}
node* new_node(std::initializer_list<node*> args){
    node* temp = new node;
    for(auto elem: args){
        temp->children.push_back(elem);
    }
    return temp;
}
void dfs(node* head){
    if(head->hasData == true){
        return;
    }
    int size = head->children.size();
    if(size == 0)
        return;
    for(unsigned i = 0; i < size; ++i){
        dfs(head->children[i]);
    }
}


// ----------------------
// utility
// ----------------------

bool searchPattern(std::string content, std::string ele)
{
    std::smatch match;
    std::regex element(ele, std::regex::extended);

    if(std::regex_search(content, match, element))
        return true;
    else
        return false;
}

void trimSpace(std::string &arg){
    boost::trim(arg);
    // return arg;
}

bool compareStr(std::string arg1, std::string arg2)
{
    // std::string temp = "[ ]+" + target + "[ ]+";
    std::string temp1 = arg1;
    std::string temp2 = arg2;
    temp1.erase(remove(temp1.begin(), temp1.end(), ' '), temp1.end());
    temp2.erase(remove(temp2.begin(), temp2.end(), ' '), temp2.end());

    if(temp1 == temp2)
        return true;
    else
        return false;
}

std::string toString(char* input)
{
    std::string s(input);
    return s;
}

char* toChar(std::string input)
{
    char *cstr = new char[input.length(), 1];
    strcpy(cstr, input.c_str());
    return cstr;
}
char* concatStr(std::initializer_list<char*> args)
{
    std::string result = "";
    for(auto elem : args)
    {
        std::string s(elem);
        result += s;
        // std::cout << elem << std::endl ;
    }
    return toChar(result);
}

// char* concatStr({int n_args, ...)
// {
//     va_list ap;
//     va_start(ap, n_args);
//     std::string result = "";
//     // char* temp = va_arg(ap, char*);
//     for(unsigned i = 0; i < n_args; i,,) {
//         char* temp = va_arg(ap, char*);
//         std::string s(temp);
//         result,= s;
//     }
//     va_end(ap);
//     return concatStr({result);
// }



void writeDfs(std::vector<node*> args)
{
    for(auto head: args)
    {
        if(head->hasData)
        {
            writefile << head->data + " ";
            if(head->data == ";" || head->data == "}" || head->data == "{")
                writefile << std::endl;
        }
        int size = head->children.size();
        if(size > 0){
            writeDfs(head->children);
        }
    }
}

void writeDfs(std::stringstream& writefile, std::vector<node*> args)
{
    for(auto head: args)
    {
        if(head->hasData)
        {
            writefile << head->data + " ";
            if(head->data == ";" || head->data == "}" || head->data == "{")
                writefile << std::endl;
        }
        int size = head->children.size();
        if(size > 0){
            writeDfs(writefile, head->children);
        }
    }
}


std::vector<node*> listToVec(std::initializer_list<node*> args)
{
    std::vector<node*> res;
    for(auto elem: args){
        res.push_back(elem);
    }
    // std::cout << "\nconverted" << std::endl;
    return res;
}

std::string nodeToString(node* head)
{
    std::string result = "";
    if(head->hasData){
        result += head->data;
        return result;
    }
    else{
        int size = head->children.size();
        // if(size == 0)
        //     return;
        for(unsigned i = 0; i < size; ++i)
        {
            result += nodeToString(head->children[i]) + " ";
        }
    }
    return result;
}

void addModifier(std::vector<node*> modifiers, node* block){
    for(unsigned i = 0; i < modifiers.size(); ++i){

        node* mod = new_node({new_node("assert("), modifiers[i], new_node(");")});
        block->children.insert(block->children.begin() + 1, mod);
    }
}

void addRetVariables(node* ret, node* block, bool hasBody){

    if(!hasBody){
        std::string retType = nodeToString(ret);
        node* retStmt;
        if(retType.find("bool") != std::string::npos){
            retStmt = new_node("return true;");
        }
        else if(retType.find("address") != std::string::npos){
            retStmt = new_node("return address();");
        }
        else if(retType.find("string") != std::string::npos){
            retStmt = new_node("return \"\";");
        }
        else{
            retStmt = new_node("return 0;");
        }
        // block->children.insert(block->children.begin() + 1, ret);
        block->children.insert(block->children.end() - 1, retStmt);
    }
    else{
        if(ret->children.size() > 1){
            node* retStmt = new_node({new_node("return "), ret->children[1], new_node(";")});
            block->children.insert(block->children.begin() + 1, ret);
            block->children.insert(block->children.end() - 1, retStmt);
        }
        else{
            static unsigned count = 0;
            node* retStmt = new_node({new_node("return "), new_node("temp" + std::to_string(count)), new_node(";")});
            block->children.insert(block->children.begin() + 1, ret);
            block->children.insert(block->children.end() - 1, retStmt);
            count++;
        }
    }
}

node* getRetType(node* ret)
{
    node* temp;
    if(ret->children.size() >= 1)
    {
        temp = ret->children[0];
        return temp;
        // ret->children.clear();
        // ret->children.push_back(temp);
    }
    return NULL;
}

node* getRetType(std::vector<node*> retList){
    node* temp = new_node();
    if(retList.size() > 1){
        temp->children.push_back(new_node("std::tuple<"));
        // std::cout << retList.size() << '\n';
        for(int i = (retList.size() - 1); i >= 0; --i)
            temp->children.push_back(retList[i]);
        temp->children.push_back(new_node(">"));
        return temp;
    }
    else{
        if(!retList.empty())
            return getRetType(retList[0]);
        else return NULL;
    }
}


// -----------------------------
// FunctionData class
// ----------------------------

FunctionData::FunctionData()
{
    isPure = false;
    isPublic = true;
    isView = false;
    isPayable = false;
    hasTransferFunc = false;
    returnType = "NORETURN_TYPE";
}
FunctionData::FunctionData(std::string name)
{
    this->name = name;
}

FunctionData::FunctionData(std::string name, std::vector<std::pair<std::string, std::string>> arguments, std::string returnType)
{
    this->name = name;
    this->arguments = arguments;
    this->returnType = returnType;
}

void FunctionData::printFunctionData()
{
    std::cout << "Name:" << this->name << std::endl;

    for(unsigned i = 0; i < this->arguments.size(); ++i)
    {
        std::cout << this->arguments[i].first << " " << this->arguments[i].second << std::endl;
    }
    std::cout << "isPure:" << this->isPure << std::endl;
    std::cout << "isPublic:" << this->isPublic << std::endl;
    std::cout << "isView:" << this->isView << std::endl;
    std::cout << "isPayable:" << this->isPayable << std::endl;
    std::cout << "hasTransferFunc:" << this->hasTransferFunc << std::endl;
    std::cout << "block:" << this->block << std::endl;
    std::cout << "retType:" << this->returnType << std::endl;

    // if(readState.size() != 0){
    //     std::cout << "read State:" << std::endl;
    //     for(auto itr = readState.begin(); itr != readState.end(); ++itr)
    //     {
    //         if(itr->second){
    //             std::cout << itr->first.first << std::endl;
    //         }
    //     }
    // }
}

std::string FunctionData::getName()
{
    return this->name;
}

void FunctionData::setRWState(){
    std::vector<Variable*> stateVar = contract.vars;
    std::string block = this->block;
    for(unsigned i = 0; i < stateVar.size(); ++i){
        std::size_t posVar = block.find(stateVar[i]->name);
        if(posVar != std::string::npos){
            this->readState[stateVar[i]] = true;
            std::size_t posSemi = block.find(";", posVar + 1);
            // posSemi = block.find("")
            if(posSemi != std::string::npos){
                std::string stmt = block.substr(posVar, posSemi - posVar);
                if((stmt.find("=") != std::string::npos && stmt.find("==") == std::string::npos
                && stmt.find(">=") == std::string::npos && stmt.find("<=") == std::string::npos && stmt.find("!=") == std::string::npos)
                || stmt.find("++") != std::string::npos || stmt.find("--") != std::string::npos){
                    this->writeState[stateVar[i]] = true;
                    stateVar[i]->canBeSymbolic = true;
                }
            }
            std::string before = block.substr(0, posVar);
            posSemi = before.find_last_of(";");
            if(posSemi != std::string::npos){
                std::string stmt = before.substr(posVar, posVar - posSemi);
                if(stmt.find("++") != std::string::npos || stmt.find("--") != std::string::npos){
                    this->writeState[stateVar[i]] = true;
                    stateVar[i]->canBeSymbolic = true;
                }
            }
        }
    }
}

//--------------------------------------------------------------------------

bool isParentheses(char c){
    if(c =='(' || c == ')')
        return true;
    else return false;
}

std::istream& operator>>(std::istream& inF, FunctionData& function)
{
    // skip leading empty lines, read name from non-empty line 1
    // std::getline(inF, function->name);
    inF >> function.name;

    std::size_t countArgs;
    if(inF >> countArgs)
    {
        function.arguments.resize(countArgs);
        for(unsigned i = 0; i < countArgs; ++i){
            inF >> function.arguments[i].first;
            std::getline(inF, function.arguments[i].second);
        }
    }
    std::string temp;
    inF >> temp;
    if(temp != "NORETURN_TYPE")
        function.returnType = temp;
    function.returnType = temp;
    //
    //
    // // unsigned boolVal;
    inF >> function.isPure;
    inF >> function.isView;
    inF >> function.isPayable;
    inF >> function.isPublic;
    inF >> function.hasTransferFunc;

    std::getline(inF, temp);    //for nextline
    std::getline(inF, function.block);
    std::getline(inF, function.args);
     // input failed; clear everything
    return inF;
}

std::ostream& operator<< ( std::ostream& outF, const FunctionData& function)
{
    outF << function.name << '\n';

    outF << function.arguments.size() << '\n';
    for(unsigned i = 0; i < function.arguments.size(); ++i)
    {
        outF << function.arguments[i].first << " " << function.arguments[i].second;
        outF << '\n';
    }

    // if(function->returnType != "NORETURN_TYPE")
    outF << function.returnType << '\n';

    outF << function.isPure << '\n';
    outF << function.isView << '\n';
    outF << function.isPayable << '\n';
    outF << function.isPublic << '\n';
    outF << function.hasTransferFunc << '\n';

    outF << function.block << '\n';
    outF << function.args << '\n';
    // out << function.readState.size() << '\n';
    // for(auto itr = functions.begin(); itr!= functions.end(); ++itr){
    //     out << *itr;
    // }
    return outF;
}

// void FunctionData::convertArgs()
// {
//     std::string args = this->args;
//     args.erase(std::remove_if(input.begin(), input.end(), &isParentheses), input.end());
//     std::vector<std::string> list = split(args, ",");
//     for(unsigned i = 0; i < list.size(); ++i){
//         std::stringstream ss(list[i]);
//         std::string word;
//         ss >> word
//     }
//
// }


//---------------------------------------
//ContractData class
//---------------------------------------


ContractData::ContractData(){
    hasFallback = false;
    hasDefaultConstructor = false;
    hasParaConstructor = false;
}
ContractData::ContractData(std::string name)
{
    this->name = name;
}
ContractData::ContractData(std::string name, std::vector<std::pair<std::string, std::string>> stateVariables, std::vector<FunctionData*> functions)
{
    this->name = name;
    this->stateVariables = stateVariables;
    this->functions = functions;
}

void ContractData::printContractData()
{
    std::cout << "ContractName:" << this->name << std::endl;
    for(unsigned i = 0; i < this->stateVariables.size(); ++i)
    {
        std::cout << this->stateVariables[i].second << " " << stateVariables[i].first << std::endl;
    }
    std::cout << "fallback:" << this->hasFallback;
    FunctionData* obj;
    for(unsigned i = 0; i < this->functions.size(); ++i)
    {
        // std::cout << stateVariables[i].first << " " << stateVariables[i].second << std::endl;
        obj = this->functions[i];
        obj->printFunctionData();
        std::cout << std::endl;
    }
}

std::vector<FunctionData*> ContractData::getFunctions()
{
    return functions;
}

std::vector<std::pair<std::string, std::string>> ContractData::getStateVariables()
{
    return stateVariables;
}

std::istream& operator>> (std::istream& in, ContractData& contract)
{
    // std::getline(in, contract.name);
    // std::getline(in, contract.objectName);

    in >> contract.name;
    in >> contract.objectName;

    std::size_t countVars;
    if(in >> countVars)
    {
        contract.stateVariables.resize(countVars);
        for(unsigned i = 0; i < countVars; ++i){
            in >> contract.stateVariables[i].first;
            std::getline(in, contract.stateVariables[i].second);
        }
    }

    // std::size_t countFunc;
    // in >> countFunc;
    // contract.functions.resize(countFunc);
    // if(countFunc > 0)
    //     in >> *(contract.functions[0]);

    in >> contract.hasFallback;
    std::size_t countFunc;
    if(in >> countFunc){
        contract.functions.resize(countFunc);
        for(unsigned i = 0; i < countFunc; ++i){
            FunctionData* f = new FunctionData();
            in >> *(f);
            contract.functions[i] = f;
        }
    }

    // std::getline(in, contract.hasFallback);

     // input failed; clear everything
    // if( !in ) contract = {} ; // input failed; clear everything

    return in ;
}

std::ostream& operator<< (std::ostream& out, const ContractData& contract)
{
    out << contract.name << '\n';
    out << contract.objectName << '\n';

    out << contract.stateVariables.size() << '\n';
    for(auto itr = contract.stateVariables.begin(); itr != contract.stateVariables.end(); ++itr)
    {
        out << itr->first << " " << itr->second;
        out << '\n';
    }
    out << contract.hasFallback << '\n';
    out << contract.functions.size() << '\n';

    for(unsigned i = 0; i < contract.functions.size(); ++i){
        out << *(contract.functions[i]);
    }
    return out;
}

void ContractData::writeContract()
{
    // raw_fd_ostream file_obj;
    // std::unique_ptr<llvm::raw_fd_ostream> f = klee_open_output_file("contract.txt", "cant open File");
    std::ofstream file_obj;
    file_obj.open("contract.txt", std::ios::out);
    if(file_obj){
        // file_obj.write((char*)&contract, sizeof(contract));
        file_obj << contract;
        file_obj.close();
    }
}

ContractData ContractData::readContract()
{
    std::ifstream file_obj;
    file_obj.open("contract.txt", std::ios::in);
    ContractData obj;

    //can also read multiple objects using the loop
    // while (!file_obj.eof()) {
    //
    //     file_obj.read((char*)&obj, sizeof(obj));
    // }
    if(file_obj){
        // file_obj.read((char*)&obj, sizeof(obj));
        file_obj >> obj;
        file_obj.close();
    }
    // else
    //     std::cout << "\ncant open file\n";
    return obj;
}


// --------------------------------------
// ContractData class ends
// -------------------------------------

std::vector<std::string> split(std::string input, std::string splitter)
{
    std::regex regEx(splitter);
    // input.erase(std::remove_if(input.begin(), input.end(), &isParentheses), input.end());

    std::vector<std::string> result(
                    std::sregex_token_iterator(input.begin(), input.end(), regEx, -1),
                    std::sregex_token_iterator()
                    );
    return result;
}

void cleanFile(std::ifstream& input, std::ofstream& outputStream)
{
    std::stringstream strStream;
    strStream << input.rdbuf(); //read the entirefile
    std::string allText = strStream.str();

    std::vector<std::string> classSplit = split(allText, "class");
    outputStream.open("temp1.cpp");
    outputStream << "class";

    std::vector<std::string> classDef = split(classSplit[1], "@function");

    // std::cout << temp2.size() << std::endl;
    for(unsigned i = 0; i < classDef.size(); ++i)
    {
        std::vector<std::string> functionDef = split(classDef[i], "\\{[^]*\\}");
        if(functionDef.size() > 1)
        {
            outputStream << functionDef[0] << "{}\n";
            functionBlock.push_back(functionDef[1]);
        }                                                       //writing only function prototype
        else
            outputStream << functionDef[0];                 //writing state vars
    }

    outputStream << "\n}";
}

variabletype getType(std::string type)
{
    trimSpace(type);
    if(type.find("map") != std::string::npos)
        return MAP;
    else if(type.find("vector") != std::string::npos)
        return VECTOR;
    else if(type.find("[") != std::string::npos)
        return ARRAY;
    else if(type.find("string") != std::string::npos)
        return STDSTRING;
    else if(type.find("struct") != std::string::npos)
        return STRUCTURE;
    else if(type.find("array") != std::string::npos)
        return ARRAY;

    for(unsigned i = 0; i < datatypeStr.size(); ++i){
        if(type.find(datatypeStr[i]) != std::string::npos)
            return SIMPLE;
    }
    return USERDEF;
}

void setFunctionDataAttr(FunctionData* function, std::vector<std::pair<node*, node*>> funcArgs)
{
    std::string block = function->block;

    std::string transferFunc[] = {"send", "call", "transfer"};
    int transferFuncSize = 3;

    std::vector<std::string> words;
    boost::split(words, block, boost::is_any_of("\n\t .,!?\"()[]"));

    for(unsigned i = 0; i < transferFuncSize; ++i)
    {
        auto index = std::find(words.begin(), words.end(), transferFunc[i]);
        if(index != words.end())
        {
            function->hasTransferFunc = true;
            break;
        }
    }
    //setting FunctionCallArguments

    for(auto itr = funcArgs.begin(); itr != funcArgs.end(); ++itr)
    {
        std::string name = nodeToString(itr->first);
        std::string type = nodeToString(itr->second);
        function->arguments.push_back(make_pair(name, type));
        variabletype t = getType(type);
        function->vars.push_back(new Variable(name, type, t));
    }

    //todo: check if a local var declaration is same as state var

    // auto stateVars = contract.stateVariables;
    // if(stateVars.size() == 0)
    //     std::cout << "State vars not set" << std::endl;

    // for(unsigned i = 0; i < stateVars.size(); ++i)
    // {
    //     auto var = stateVars[i];
    //     auto index = std::find(words.begin(), words.end(), var.first);
    //     if(index != words.end())
    //     {
    //         function->readState[var] = true;
    //     }
    // }
}

void addClassObject(std::ofstream& outputStream)
{
    contract.objectName = "Object";
    int count = 0;
    while(uniqueVars.find(contract.objectName) != uniqueVars.end())
    {
        contract.objectName = "Object" + count;
        count++;
    }
    outputStream << "\n";
    outputStream << contract.name << " ";
    outputStream << contract.objectName << ";";
    outputStream << "\n";
}

int factorial(int n)
{
    if(n <= 1)
        return 1;
    else return n * factorial(n-1);
}

bool canMakeSymbolic(std::string type){

    // std::vector<std::string> symTypes{"int", "unsigned", "long", "bool", "address", "char"};
    trimSpace(type);
    variabletype t = getType(type);
    if(t == SIMPLE){
        return true;
    }
    return false;
}

bool inWriteState(Variable* var){
    for(unsigned i = 0; i < contract.functions.size(); ++i){
        if(contract.functions[i]->readState.find(var) != contract.functions[i]->readState.end()){
            return true;
        }
    }
    return false;
}

void addSymbolicVar(std::ofstream& outputStream, std::vector<std::pair<std::string, std::string>> vars, bool isStateVar)
{
    // what to do for user defined datatypes, same name but different datatype vars
    unsigned varCount = vars.size();
    for(unsigned i = 0; i < varCount; ++i)
    {
        bool flag = false;
        if(uniqueVars.find(vars[i].first) == uniqueVars.end()){
            std::string name = vars[i].first;
            std::string type = vars[i].second;
            if(isStateVar){
                for(unsigned i = 0; i < contract.vars.size(); ++i){
                    if(contract.vars[i]->name == name && ((contract.vars[i]->isInitialized && !contract.vars[i]->canBeSymbolic) || contract.vars[i]->isConstant)){
                        flag = true;
                        break;
                    }
                }
            }
            if(flag)
                continue;
            if(canMakeSymbolic(type)){
                outputStream << type << " " << name << ";";
                outputStream << std::endl;
                outputStream << "klee_make_symbolic(&" << name << ", sizeof(" << name << "), \"" << name << "\");";
                outputStream << std::endl;
                if(isStateVar)
                    outputStream << contract.objectName << "." << name << " = " << name << ";" << std::endl;
                else{
                }
                uniqueVars.insert(name);
            }
            else /*if(type.find("string") != std::string::npos)*/{
                // outputStream << "char " << name << "_new[10];";
                // outputStream << std::endl;
                // outputStream << "klee_make_symbolic(&" << name << "_new" << ", sizeof(" << name << "_new), \"" << name << "\");";
                // outputStream << std::endl;
                // outputStream << type << " " << name << ";";
                // outputStream << std::endl;
                // outputStream << "for(unsigned i = 0; i < 10; ++i)";
                // outputStream << std::endl;
                // outputStream << name << "[i] = " << name << "_new[i];";
                // outputStream << std::endl;
                if(!isStateVar){
                    outputStream << type << " " << name << ";";
                    outputStream << std::endl;
                    uniqueVars.insert(name);
                }
            }
        }
        // check datatype of matching var, if different then
        // else{
        //     std::string name = vars[i].first;
        //     std::string newName = name + "_new";
        //     std::string type = vars[i].second;
        //
        //     if(canMakeSymbolic(type)){
        //         outputStream << type << " " << newName << ";";
        //         outputStream << std::endl;
        //         outputStream << "klee_make_symbolic(&" << newName << ", sizeof(" << newName << "), \"" << newName << "\");";
        //         outputStream << std::endl;
        //         if(isStateVar)
        //             outputStream << contract.objectName << "." << name << " = " << newName << ";" << std::endl;
        //         else{
        //         }
        //         uniqueVars.insert(newName);
        //     }
        // }
    }
}

void addFunctionPerm(std::ofstream& outputStream, std::vector<FunctionData*> todFunctions, int count)
{
    unsigned i = 0;
    int countTod = todFunctions.size();
    // std::cout << "count tod:" << countTod;
    // std::cout << std::endl << "adding functions" << std::endl;

    // while(i < count)
    // {
        for(int j = 0; j < countTod; ++j){
            FunctionData* currFunc = todFunctions[j];
            //todo: code for return values
            if(currFunc->name != contract.name){
                outputStream << contract.objectName << ".";
                outputStream << currFunc->name << "(" ;
                int size = currFunc->arguments.size();
                if(size > 0){
                    for(int k = 0; k < size - 1; ++k){
                        outputStream << currFunc->arguments[k].first << ", ";
                    }
                    outputStream << currFunc->arguments[size - 1].first;
                }
                outputStream << ");";
                outputStream << std::endl;
            }
        }
        // next_permutation(todFunctions.begin(), todFunctions.end());         //todo
        // i++;
    // }
    // std::cout << std::endl << "funcend" << std::endl;
}

void findTodFunctions(std::vector<FunctionData*>& todFunctions, std::vector<FunctionData*>& restFunctions)
{
    std::vector<FunctionData*> allFunctions = contract.getFunctions();

    int size = allFunctions.size();
    for(unsigned i = 0; i < size; ++i)
    {
        FunctionData* currFunction = allFunctions[i];
        if(currFunction->type == RETURN_TYPE || currFunction->type == NORETURN_TYPE || currFunction->type == FALLBACK_TYPE){
            // if(currFunction->isPure){
            //     restFunctions.push_back(currFunction);
            //     // continue;
            // }
            // else if(currFunction->isView){
            //     restFunctions.push_back(currFunction);
            //     // continue;
            // }
            if(!currFunction->isPublic){
                restFunctions.push_back(currFunction);
                // continue;
            }
            else
                todFunctions.push_back(currFunction);
        }
    }
}

void addMainFunction(std::ofstream& outputStream)
{
    std::vector<FunctionData*> todFunctions;
    std::vector<FunctionData*> restFunctions;

    findTodFunctions(todFunctions, restFunctions);

    outputStream << "\nint main(){ \n";
    addClassObject(outputStream);

    for(unsigned i = 0; i < contract.functions.size(); ++i){
        contract.functions[i]->setRWState();
    }

    addSymbolicVar(outputStream, contract.stateVariables, true);

    int countTod = todFunctions.size();
    for(unsigned i = 0; i < countTod; ++i)
    {
        if(todFunctions[i]->name != contract.name)
            addSymbolicVar(outputStream, todFunctions[i]->arguments, false);
    }
    // std::cout << std::endl << "func" << std::endl;

    if(countTod <= 3){
        addFunctionPerm(outputStream, todFunctions, factorial(countTod));
    }
    else{
        addFunctionPerm(outputStream, todFunctions, 10);
    }
    // std::cout << std::endl << "func" << std::endl;
    outputStream << std::endl << "return 0;\n}" << std::endl;
}

void rewriteContent(std::string filename){
    std::ifstream cppfile(filename, std::ios::in);
    if(cppfile){
        std::string content;
        std::string newContent = "";
        std::stringstream ss;
        ss << cppfile.rdbuf();
        content = ss.str();
        content = rewriteArray(content);
        // content = rewriteDelete(content);
        content = removeDelete(content);
        content = rewriteEnum(content);
        content = removeSuper(content);
        cppfile.close();
        int i = 0;
        int check = 0;
        // int index = 0;
        while(i < content.length()){                          //while loop runs till end of string
            char c = content[i];
            // std::cout << c << ":" ;
            if(c == ' ' && check == 0){           //check spaces
                newContent += content[i];
                check = 1;
            }
            else if(c == ' ' && check == 1){                   //check alphabets and numbers
                // newContent += content[i];
                // check = 0;
            }
            else{
                newContent += content[i];
                check = 0;
            }
            i++;
        }
        std::ofstream cppfile2(filename, std::ios::out);
        if(cppfile2){
            if(checkOverlap(newContent)){
                std::cout << "Memory Overlap possible:Length of array changed"<< '\n';
                // newContent = rewriteSize(newContent);
            }
            std::cout << checkBlockhash(newContent) << '\n';
            cppfile2 << newContent;
            cppfile2.close();
        }
    }
}

void rewriteSize(std::string& content, std::string pattern){

    std::vector<std::string> len{"\\.[ ]*length", "\\.[ ]*size[ ]*\\([ ]*\\)", "\\.[ ]*length[ ]*\\([ ]*\\)"};
    std::vector<std::string> change{"[ ]*\\+[ ]*\\+", "[ ]*\\-[ ]*\\-", "[ ]*\\+[ ]*=", "[ ]*\\-[ ]*=", "[ ]*=[^=]"};

    for(unsigned i = 0; i < len.size(); ++i){
        for(unsigned j = 0; j < change.size(); ++j){
            std::regex sizePattern("[^;}{()]*" + len[i] + change[j] + "[^;]*[ ]*;");
            std::smatch match; // <-- need a match object
            unsigned pos = 0;
            std::string subject = content;
            while (std::regex_search(subject, match, sizePattern)) {
                std::string sizeUse = match.str(0);
                pos += match.position(0);
                content.erase(pos, sizeUse.length());
                subject = match.suffix().str();
            }
        }
    }
}

std::string rewriteEnum(std::string content){

    for(unsigned i = 0; i < contract.enumNames.size(); ++i){
        std::regex enumDot(contract.enumNames[i] + "[ ]*\\.");
        std::smatch match; // <-- need a match object
        // std::string subject = content;
        unsigned pos = 0;
        std::string subject = content;
        while (std::regex_search(subject, match, enumDot)) {
            std::string enumUse = match.str(0);
            pos += match.position(0);
            content.erase(pos, enumUse.length());
            subject = match.suffix().str();
            // pos -= enumUse.length();
        }
    }
    return content;
}

std::string rewriteArray(std::string content){

    std::smatch match; // <-- need a match object
    std::regex arrayDim("[a-zA-Z0-9]+[ ]*\\[[ ]*[a-zA-Z0-9]*[ ]*\\][ ]+[a-zA-Z0-9_]+");

    std::string subject = content;
    unsigned pos = 0;

    while (std::regex_search(subject, match, arrayDim)) {
        std::string arrayDec = match.str(0);
        pos += match.position(0);
        // std::cout << pos << "\n";
        content.erase(pos, arrayDec.length());

        size_t posB1 = arrayDec.find("[");
        size_t posB2 = arrayDec.find("]");
        std::string dim = arrayDec.substr(posB1, posB2 + 1 - posB1);
        arrayDec.erase(posB1, posB2 + 1 - posB1);
        arrayDec += dim;
        content.insert(pos, arrayDec);
        // suffix to find the rest of the string.
        subject = match.suffix().str();
        pos += arrayDec.length();
    }
    return content;
    //std::cout << std::endl << content << std::endl;
}

void replaceKeywords(std::string filename)
{
    std::ifstream cppfile(filename);
    if(cppfile){
        std::string content;
        std::stringstream ss;
        ss << cppfile.rdbuf();
        content = ss.str();
        cppfile.close();

        // std::cout << checkOverlap(content);

        for(auto itr = replaceKeywordsMap.begin(); itr != replaceKeywordsMap.end(); ++itr)
        {
            std::string from = itr->first;
            std::string to = itr->second;
            std::regex fromRegex(from);
            content = std::regex_replace(content, fromRegex, to);
            // size_t start_pos = 0;
            // while((start_pos = content.find(from, start_pos)) != std::string::npos) {
            //     content.replace(start_pos, from.length(), to);
            //     start_posreplaceKey += to.length(); // In case 'to' contains 'from', like replacing 'x' with 'yx'
            // }
        }
        std::ofstream newcppfile(filename);
        newcppfile << content;
        newcppfile.close();
    }
    else{
        std::cerr << "error opening cpp file";
    }
}

FunctionData* createFunction(enum funcType type, std::initializer_list<node*> args, node* funcAttr)
{
    std::vector<node*> newArgs;
    newArgs = listToVec(args);
    int size = args.size();
    FunctionData* function = new FunctionData();
    std::stringstream ss;
    if(funcAttr)
    {
        std::string qualifier = nodeToString(funcAttr);
        std::stringstream ss(qualifier);
        std::string word;

        while(ss >> word){
            if(word == "public"){
                function->isPublic = true;
            }
            else if(word == "pure"){
                function->isPure = true;
                pureFunctions.push_back(function);
            }
            else if(word == "view"){
                function->isView = true;
                viewFunctions.push_back(function);
            }
            else if(word == "payable"){
                function->isPayable = true;
                payableFunctions.push_back(function);
            }
            else if(word == "private"){
                function->isPublic = false;
            }
        }
    }
    switch(type)
    {
        case RETURN_TYPE:{
            if(size == 4){
                function->name = nodeToString(newArgs[1]);
                function->args = nodeToString(newArgs[2]);
                function->block = nodeToString(newArgs[3]);
                function->type = RETURN_TYPE;
                function->returnType = nodeToString(newArgs[0]);
                if(function->isPublic){
                    writefile << "public:" << '\n';
                }
                else{
                    writefile << "public:" << '\n';
                }
                writeDfs(newArgs);
            }
            else{
                std::cout << "Error in func creation" << std::endl;
            }
        }
        break;
        case NORETURN_TYPE:{
            if(size == 3){
                function->name = nodeToString(newArgs[0]);
                function->args = nodeToString(newArgs[1]);
                function->block = nodeToString(newArgs[2]);
                function->type = NORETURN_TYPE;
                function->returnType = "void";
                if(function->isPublic){
                    writefile << "public:" << '\n';
                }
                else{
                    writefile << "private:" << '\n';
                }
                if(function->name != contract.name)
                    writefile << "void ";
                else{
                    function->type = CONSTRUCTOR_TYPE;

                    if(std::any_of(std::begin(function->args), std::end(function->args), ::isalpha)){
                        contract.hasParaConstructor = true;
                        // std::cout << "herelkdl;ad";
                        // There is at least one alphabetic character in the string
                    }
                    else{
                        contract.hasDefaultConstructor = true;
                        // std::cout << "nothere";
                    }
                }
                writeDfs(newArgs);
            }
            else{
                std::cout << "Error in func creation" << std::endl;
            }
        }
        break;
        case CONSTRUCTOR_TYPE:{
            if(size == 2){
                function->name = contract.name;
                function->args = nodeToString(newArgs[0]);
                function->block = nodeToString(newArgs[1]);
                function->type = CONSTRUCTOR_TYPE;

                if(std::any_of(std::begin(function->args), std::end(function->args), ::isalpha)){
                    contract.hasParaConstructor = true;
                    // std::cout << "herelkdl;ad";
                    // There is at least one alphabetic character in the string
                }
                else{
                    contract.hasDefaultConstructor = true;
                    // std::cout << "nothere";
                }

                if(function->isPublic){
                    writefile << "public:" << '\n';
                }
                else{
                    writefile << "private:" << '\n';
                }
                writefile << contract.name;
                writeDfs(newArgs);
            }
            else{
                std::cout << "Error in func creation" << std::endl;
            }
        }
        break;
        case FALLBACK_TYPE:{
            if(size >= 1){
                //writeDfs(newArgs);
                function->name = "fallback";
                function->block = nodeToString(newArgs[1]);
                function->type = FALLBACK_TYPE;
                function->returnType = "void";
                function->args = "()";
                contract.hasFallback = true;
                writefile << "public:" << '\n';
                writeDfs(newArgs);
            }
            else{
                std::cout << "Error in func creation" << std::endl;
            }
        }
        break;
        case MODIFIER_TYPE:{
            if(size >= 3){
                function->name = nodeToString(newArgs[0]);
                function->block = nodeToString(newArgs[2]);
                function->type = MODIFIER_TYPE;
                function->returnType = "bool";
                function->args = nodeToString(newArgs[1]);
                if(function->isPublic){
                    writefile << "public:" << '\n';
                }
                else{
                    writefile << "private:" << '\n';
                }
                writefile << "bool ";
                writeDfs(newArgs);
            }
            // else if(size >= 2)
            // {
            //     function->name = nodeToString(newArgs[0]);
            //     function->block = nodeToString(newArgs[1]);
            //     function->type = MODIFIER_TYPE;
            //     if(function->isPublic){
            //         writefile << '\n' << "public:" << '\n';
            //     }
            //     else{
            //         writefile << '\n' << "private:" << '\n';
            //     }
            //     writefile << "bool ";
            //     writeDfs(newArgs);
            // }
        }
        break;
        default: std::cerr << "Error in function creation";
    }
    writefile << std::endl;
    return function;
}

void createState(std::initializer_list<node*> args, node* varAttr, bool isInitialized)
{
    std::vector<node*> newArgs;
    newArgs = listToVec(args);
    writefile << std::endl;
    int size = newArgs.size();
    if(size >= 2)
    {
        std::string type = nodeToString(newArgs[0]);
        std::string name = nodeToString(newArgs[1]);
        variabletype t = getType(type);
        // if(uniqueVars.find(name) == uniqueVars.end())
        //     uniqueVars.insert(name);
        contract.stateVariables.push_back(make_pair(name, type));
        contract.vars.push_back(new Variable(name, type, t, isInitialized));

        // std::string qualifier = nodeToString(varAttr);
        // std::stringstream ss(qualifier);
        // std::string word;
        //
        // while(ss >> word){
        //     if(word == "public"){
        //         contract.isPublicStateVariable.push_back(true);
        //         writefile << '\n' << "public:" << "\n";
        //     }
        //     else if(word == "internal"){
        //         contract.isPublicStateVariable.push_back(false);
        //         writefile << '\n' << "protected:" << "\n";
        //     }
        //     else if(word == "private"){
        //         contract.isPublicStateVariable.push_back(false);
        //         writefile << '\n' << "private:" << "\n";
        //     }
        //     else if(word == "constant") {
        //         contract.isPublicStateVariable.push_back(true);
        //         writefile << '\n' << "const:" << "\n";
        //     }
        //     else{
        //         contract.isPublicStateVariable.push_back(false);
        //         writefile << '\n' << "protected:" << "\n";
        //     }
        // }
        writefile << "public:" << '\n';
        writeDfs(newArgs);
    }
    else{
        std::cout << "Error creating state" << std::endl;
    }
}

void createContract(std::initializer_list<node*> args)
{
    // writefile << "#include <bits/stdc++.h>" << std::endl;
    writeDecl << "#include <cassert>" << std::endl;
    writeDecl << "#include <klee/klee.h>" << std::endl;
    writeDecl << "#include \"../types.h\"" << std::endl;
    writeDecl << "#include \"../functions.h\"" << std::endl;

    //check if these needed
    writeDecl << "#include <algorithm>" << std::endl;
    writeDecl << "#include <iterator>" << std::endl;
    writeDecl << "#include <map>" << std::endl;
    writeDecl << "#include <string>" << std::endl;

    std::vector<node*> newArgs;
    newArgs = listToVec(args);
    writeDecl << std::endl;
    writeDfs(writeDecl, newArgs);
    // writefile << ";";
}

void addContractName(node* name){
    contractNames.push_back(nodeToString(name));
}

void writeAddrConstructor(std::string name)
{
    writefile << "// Address constructor.\n"; 
    writefile << name << "(const char addr[43]){};\n";
    writefile << name << "(address addr){}\n";
}

void writeConstructor(std::stringstream& writefile, std::string name)
{
    if (find(contractNames.begin(), contractNames.end(), name) != contractNames.end())
    writefile << "// Contructor for Contract " << name << "\n";
    writefile << name << "(){};\n";
}
void writeConstructor(std::stringstream& writefile, std::string structName, std::string members)
{
    trimSpace(members);
    // writefile << members << ":"<< std::endl;
    std::vector<std::string> args = split(members, ";");
    writefile << structName << "(";
    for(unsigned i = 0; i < args.size() - 1; ++i)
        writefile << args[i] << ",";
    writefile << args[args.size() - 1] << "){\n";
    for(unsigned i = 0; i < args.size(); ++i){
        trimSpace(args[i]);
        std::vector<std::string> argName = split(args[i], " ");
        variabletype t = getType(args[i]);
        if(t == SIMPLE || t == VECTOR || t == MAP || t == STRUCTURE){
            writefile << "this->" << argName[argName.size() - 1] << "=" << argName[argName.size() - 1] << ";\n";
        }
        else if(t == ARRAY){
            writefile << "int ARRSIZE = sizeof(" << argName[argName.size() - 1] << ")/sizeof("  << argName[argName.size() - 1] << "[0]);" << '\n';
            writefile << "std::copy(" << argName[argName.size() - 1] << ", " << argName[argName.size() - 1] << "+ ARRSIZE, " << "this->" << argName[argName.size() - 1] << ");\n";
        }
    }
    writefile << "}\n";
}
void createEnum(std::initializer_list<node*> args)
{
    std::vector<node*> newArgs;
    newArgs = listToVec(args);
    writeDecl << std::endl;
    writeDecl << "public:" << '\n';
    writeDfs(writeDecl, newArgs);
    writeDecl << ";";
    if(newArgs.size() > 1){
        contract.enumNames.push_back(nodeToString(newArgs[1]));
    }
}

void createStruct(std::initializer_list<node*> args)
{
    std::vector<node*> newArgs;
    newArgs = listToVec(args);
    writeDecl << std::endl;
    writeDecl << "public:" << '\n';
    writeDfs(writeDecl, newArgs);
    if(newArgs.size() > 1){
        std::string structName = nodeToString(newArgs[1]);
        contract.structNames.push_back(structName);

        if(newArgs.size() > 3){
            std::string members = nodeToString(newArgs[3]);
            writeConstructor(writeDecl, structName);
            writeConstructor(writeDecl, structName, members);
        }
    }
    writeDecl << "};";
}

std::string removeSuper(std::string content){
    std::regex superPattern("super[ ]*\\.");
    std::smatch match; // <-- need a match object
    unsigned pos = 0;
    std::string subject = content;
    while (std::regex_search(subject, match, superPattern)) {
        std::string superUse = match.str(0);
        pos += match.position(0);
        content.erase(pos, superUse.length());
        subject = match.suffix().str();
    }
    return content;
}

std::string removeDelete(std::string content){
    std::regex delPattern("delete [^;]*[ ]*;");
    std::smatch match; // <-- need a match object
    unsigned pos = 0;
    std::string subject = content;
    while (std::regex_search(subject, match, delPattern)) {
        std::string delUse = match.str(0);
        pos += match.position(0);
        content.replace(pos, delUse.length(), ";");
        pos += 1;
        subject = match.suffix().str();
    }
    return content;
}

std::string rewriteDelete(std::string content){
    unsigned pos = 0;
    unsigned prevPos = -1;
    start:
    while(pos != prevPos && content.find("delete ", pos) != std::string::npos){
        prevPos = pos;
        std::cout << pos << " ";
        auto index = content.find("delete ");
        if(index != std::string::npos){
            auto end = content.find(";", index + 1);
            pos = end + 1;
            std::string delStmt = content.substr(index, end - index);
            std::cout << delStmt << "\n";

            // if(index != std::string::npos){
            auto index2 = delStmt.find(" ");
            std::cout << index2 << " ";
            if(index2 != std::string::npos){
                std::string name = delStmt.substr(index2 + 1);
                std::cout << name << '\n';
                for(unsigned j = 0; j < contract.vars.size(); ++j){
                    Variable* var = contract.vars[j];
                    if(name.find(var->name) == 0){
                        variabletype type = getType(var->type);
                        std::string newStmt = getDeleteStmt(type, name);
                        content.erase(index, end - index + 1);
                        content.insert(index, newStmt);
                        pos = newStmt.length() + index;
                        goto start;
                    }
                }
                for(unsigned j = 0; j < contract.functions.size(); ++j){
                    for(unsigned k = 0; k < contract.functions[j]->vars.size() ; ++k){
                        Variable* var = contract.functions[j]->vars[k];
                        if(name.find(var->name) != std::string::npos){
                            variabletype type = getType(var->type);
                            std::string newStmt = getDeleteStmt(type, name);
                            content.erase(index, end - index + 1);
                            content.insert(index, newStmt);
                            pos = newStmt.length() + index;
                            break;
                        }
                    }
                }
            }
        }
    }
    // for(unsigned j = 0; j < contract.vars.size(); ++j){
    //     Variable* var = contract.vars[j];
    //     std::cout << var->type << " " << var->name << '\n';
    // }
    return content;
}

std::string getDeleteStmt(variabletype type, std::string name){

    // std::cout << type << " " << name << "\n";
    static unsigned count = 0;
    std::string stmt = "";
    if(type == VECTOR){
        stmt += name + ".clear();";
    }
    else if(type == MAP){
        unsigned first = name.find('[');
        unsigned last = name.find(']');
        std::string map = name.substr(0, first);
        std::string key = name.substr (first + 1, last - first - 1);
        stmt += "auto it" + std::to_string(count) + " = " + map + ".find(" + key + ");\n";
        stmt += map + ".erase(it" + std::to_string(count) + ");";
        count++;
    }
    return stmt;
}

node* changeQuotes(node* strNode){
    std::string str = nodeToString(strNode);
    auto index1 = str.find("'");
    if(index1 != std::string::npos){
        str[index1] = '\"';
        auto index2 = str.find("'");
        if(index2 != std::string::npos){
            str[index2] = '\"';
        }
    }
    node* temp = new_node(str);
    return temp;
}

void clearContractData(){
    contract.functions.clear();
    contract.stateVariables.clear();
    contract.hasFallback = false;
    contract.hasDefaultConstructor = false;
    contract.hasParaConstructor = false;
    contract.enumNames.clear();
    contract.structNames.clear();
    contract.vars.clear();
    contract.isPublicStateVariable.clear();
}


void writeContractNames(){
    std::ofstream file_obj;
    file_obj.open("names.txt", std::ios::out);
    if(file_obj){
        file_obj << contractNames.size() << '\n';
        for(unsigned i = 0; i < contractNames.size(); ++i){
            file_obj << contractNames[i] << '\n' ;
        }
        file_obj.close();
    }
}

std::vector<std::string> readContractNames(){
    std::ifstream file_obj;
    file_obj.open("names.txt", std::ios::in);
    std::vector<std::string> names;
    std::string temp;

    if(file_obj){
        unsigned count = 0;
        file_obj >> count;
        // std::cout << count;
        for(unsigned i = 0; i < count; ++i) {
            file_obj >> temp;
            names.push_back(temp);
        }
        file_obj.close();
    }
    return names;
}

// property checks

std::string checkTxOrigin(std::string content)
{
    std::string message = "";
    std::string toFind = "tx[ ]*\\.[ ]*origin";
    if(searchPattern(content, toFind))
        message += "tx.Origin should not be used for authorizing.";
    return message;
}

std::string checkBlockhash(std::string content)
{
    std::string message = "";
    std::string toFind = "blockhash[ ]*\\([ ]*block[ ]*\\.[ ]*number[ ]*\\)";
    if(searchPattern(content, toFind))
        message += "blockhash(block.number) used";
    return message;
}

std::string checkTimestamp(std::string content){
    std::string message = "";
    std::string toFind = "blockhash[ ]*\\.[ ]*timestamp";
    if(searchPattern(content, toFind))
        message += "block.timestamp used";
    return message;
}

std::string checkFallback(){
    std::string message = "";
    if(!contract.hasFallback)
    {
        for(unsigned i = 0; i < contract.functions.size(); ++i)
        {
            if(contract.functions[i]->isPayable){
                message += contract.functions[i]->name + "is payable, ";
            }
        }
        message += "Contract dont have fallback, should not be accepting payment";
    }
    else
        return message;
}

bool checkOverlap(std::string& content){
    std::string message = "";
    std::vector<std::string> len{"\\.[ ]*length", "\\.[ ]*size[ ]*\\([ ]*\\)", "\\.[ ]*length[ ]*\\([ ]*\\)"};
    std::vector<std::string> change{"[ ]*\\+[ ]*\\+", "[ ]*\\-[ ]*\\-", "[ ]*\\+[ ]*=", "[ ]*\\-[ ]*=", "[ ]*=[^=]"};

    for(unsigned j = 0; j < len.size(); ++j){
        for(unsigned i = 0; i < change.size(); ++i){
            std::string f = len[j] + change[i];
            if(searchPattern(content, f)){
                // std::cout << f << '\n';
                rewriteSize(content, f);

                // TODO: LOOK HERE IF ISSUE ARISES

                //std::string filename = "/home/namrata/klee/tools/klee/properties.txt";
                std::string filename = "properties.txt";
                std::ofstream failProperty(filename, std::ios::out);
                failProperty << "Memory Overlap\n";
                failProperty.close();
                return true;
                goto end;
            }
        }
    }
    end:
    return false;
}