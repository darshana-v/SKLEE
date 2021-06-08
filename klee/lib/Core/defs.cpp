#include "/home/namrata/klee/include/klee/Core/defs.h"

// #include <boost/algorithm/std::string.hpp>

// using namespace std;

// ------------------------
// variables
// ------------------------

ContractData contract;
std::stringstream writefile;

std::map<node, std::string> membersQualifiers;    // todo: decide datatype
std::vector<node> publicMembers;                  // todo: decide datatype
std::vector<node> privateMembers;                 // todo: decide datatype

std::vector<FunctionData*> viewFunctions;
std::vector<FunctionData*> payableFunctions;
std::vector<FunctionData*> pureFunctions;

std::vector<std::string> datatypeStr{"int", "float", "long", "string", "bool", "unsigned", "address", "int[]", "string[]", "long[]", "float[]", "userdef", "unsigned[]", "string[]", "address[]", "short"};

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
    /*{"\\.[ ]*push", ".push_back"},*/
    {"[^(a-zA-Z0-9)]+\\_[ ]*\\;", " return true; return false;"},
    {"this[ ]*\\.", "this->"}
};

// --------------------------------------
// defining node structure
// --------------------------------------

node* new_node(){
    node* temp = new node;
    // temp->children = new std::vector<node*>();
    // temp->hasData = false;
    return temp;
}

node* new_node(std::string content){
    node* temp = new node;
    temp->data = content;
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

node* new_node(std::initializer_list<node*> args)
{
    node* temp = new node;
    for(auto elem: args)
    {
        temp->children.push_back(elem);
    }
    return temp;
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

void trimSpace(std::string &arg)
{
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


void dfs(node* head)
{
    if(head->hasData == true)
    {
        // std::cout << head->data << " ";
        return;
    }
    int size = head->children.size();
    if(size == 0)
        return;
    for(unsigned i = 0; i < size; ++i)
    {
        dfs(head->children[i]);
    }
}

void writeDfs(std::vector<node*> args)
{
    for(auto head: args)
    {
        if(head->hasData)
        {
            writefile << head->data + " ";
            if(head->data == ";")
                writefile << std::endl;
        }
        int size = head->children.size();
        if(size > 0){
            writeDfs(head->children);
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

void addModifier(node* modifier, node* block){
    node* mod = new_node({new_node("assert("), modifier, new_node(");\n")});
    block->children.insert(block->children.begin() + 1, mod);
}

void addRetVariables(node* ret, node* block){
    // node* newBlock = block;
    node* retStmt = new_node({new_node("return "), ret->children[1], new_node(";")});
    block->children.insert(block->children.begin() + 1, ret);
    block->children.insert(block->children.end() - 1, retStmt);
    // return block;
}

node* getRetType(node* ret)
{
    node* temp;
    if(ret->children.size() > 1)
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

    if(readState.size() != 0){

        std::cout << "read State:" << std::endl;
        for(auto itr = readState.begin(); itr != readState.end(); ++itr)
        {
            if(itr->second){
                std::cout << itr->first.first << std::endl;
            }
        }
    }
}

std::string FunctionData::getName()
{
    return this->name;
}

bool isParentheses(char c)
{
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
    file_obj.open("/home/namrata/klee/tools/klee/contract.txt", std::ios::in);
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
        std::string name =  nodeToString(itr->first);
        std::string type = nodeToString(itr->second);
        function->arguments.push_back(make_pair(name, type));
        variabletype t = getType(type);
        function->vars.push_back(new Variable(name, type, t));
    }

    //todo: check if a local var declaration is same as state var

    auto stateVars = contract.stateVariables;
    // if(stateVars.size() == 0)
    //     std::cout << "State vars not set" << std::endl;

    for(unsigned i = 0; i < stateVars.size(); ++i)
    {
        auto var = stateVars[i];
        auto index = std::find(words.begin(), words.end(), var.first);
        if(index != words.end())
        {
            function->readState[var] = true;
        }
    }
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
    if(t == SIMPLE || t == ARRAY){
        return true;
    }
    return false;
}

void addSymbolicVar(std::ofstream& outputStream, std::vector<std::pair<std::string, std::string>> vars, bool isStateVar)
{
    // what to do for user defined datatypes, same name but different datatype vars
    int varCount = vars.size();
    for(unsigned i = 0; i < varCount; ++i)
    {
        if(uniqueVars.find(vars[i].first) == uniqueVars.end()){
            std::string name = vars[i].first;
            std::string type = vars[i].second;
            // std::cout << type << ":\n";

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
            else if(type.find("string") != std::string::npos){
                outputStream << "char " << name << "_new[10];";
                outputStream << std::endl;
                outputStream << "klee_make_symbolic(&" << name << "_new" << ", sizeof(" << name << "_new), \"" << name << "\");";
                outputStream << std::endl;
                outputStream << "std::" << type << " " << name << ";";
                outputStream << std::endl;
                outputStream << "for(unsigned i = 0; i < 10; ++i)";
                outputStream << std::endl;
                outputStream << name << "[i] = " << name << "_new[i];";
                outputStream << std::endl;

                if(isStateVar)
                outputStream << contract.objectName << "." << name << " = " << name << ";" << std::endl;
                else{
                }
            }
            else{

            }
        }
        // check datatype of matching var, if different then
        else{
            std::string name = vars[i].first;
            std::string newName = name + "_new";
            std::string type = vars[i].second;

            if(canMakeSymbolic(type)){
                outputStream << type << " " << newName << ";";
                outputStream << std::endl;
                outputStream << "klee_make_symbolic(&" << newName << ", sizeof(" << newName << "), \"" << newName << "\");";
                outputStream << std::endl;
                if(isStateVar)
                    outputStream << contract.objectName << "." << name << " = " << newName << ";" << std::endl;
                else{
                }
                uniqueVars.insert(newName);
            }
        }
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
        if(currFunction->type == RETURN_TYPE || currFunction->type == NORETURN_TYPE){
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

    // std::cout << std::endl << "rewriting" << std::endl;
    std::ifstream cppfile(filename, std::ios::in);
    if(cppfile){
        std::string content;
        std::string newContent = "";
        std::stringstream ss;
        ss << cppfile.rdbuf();
        content = ss.str();
        content = rewriteArray(content);
        content = rewriteDelete(content);
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
            // std::cout << "her";
            cppfile2 << newContent;
            cppfile2.close();
            std::cout << checkOverlap(newContent) << '\n';
        }
    }
    // std::cout << std::endl << "rewriting" << std::endl;
}

std::string rewriteArray(std::string content){

    std::smatch match; // <-- need a match object
    std::regex arrayDim("[a-zA-Z0-9]+[ ]*\\[[ ]*[a-zA-Z0-9]*[ ]*\\][ ]+[a-zA-Z0-9]+");

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
        // pos += content.length() - subject.length();
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
                    writefile << '\n' << "public:" << '\n';
                }
                else{
                    writefile << '\n' << "public:" << '\n';
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
                    writefile << '\n' << "public:" << '\n';
                }
                else{
                    writefile << '\n' << "private:" << '\n';
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
                    std::cout << "herelkdl;ad";
                    // There is at least one alphabetic character in the string
                }
                else{
                    contract.hasDefaultConstructor = true;
                    std::cout << "nothere";
                }

                if(function->isPublic){
                    writefile << '\n' << "public:" << '\n';
                }
                else{
                    writefile << '\n' << "private:" << '\n';
                }
                writefile << contract.name;
                // std::cout << "\nbefore" << std::endl;
                writeDfs(newArgs);
            }
            else{
                std::cout << "Error in func creation" << std::endl;
            }
        }
        break;
        case FALLBACK_TYPE:{
            if(size == 1){
                //writeDfs(newArgs);
                function->name = "fallback";
                function->block = nodeToString(newArgs[0]);
                function->type = FALLBACK_TYPE;
                // writefile << '\n' << "public:" << '\n';
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
                if(function->isPublic){
                    writefile << '\n' << "public:" << '\n';
                }
                else{
                    writefile << '\n' << "private:" << '\n';
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
    writefile << std::endl << std::endl;
    return function;
}

void createState(std::initializer_list<node*> args)
{
    std::vector<node*> newArgs;
    newArgs = listToVec(args);
    writefile << std::endl;
    int size = newArgs.size();
    if(size >= 3)
    {
        std::string type = nodeToString(newArgs[0]);
        std::string name = nodeToString(newArgs[1]);
        variabletype t = getType(type);
        if(uniqueVars.find(name) == uniqueVars.end())
            uniqueVars.insert(name);
        contract.stateVariables.push_back(make_pair(name, type));
        contract.vars.push_back(new Variable(name, type, t));
        std::string qualifier = nodeToString(newArgs[size - 1]);
        newArgs.pop_back();
        // std::cout << newArgs.size() << std::endl;

        std::stringstream ss(qualifier);
        std::string word;

        while(ss >> word){
            if(word == "public"){
                contract.isPublicStateVariable.push_back(true);
                writefile << '\n' << "public:" << "\n";
            }
            else if(word == "internal"){
                contract.isPublicStateVariable.push_back(false);
                writefile << '\n' << "private:" << "\n";
            }
            else if(word == "external"){
                contract.isPublicStateVariable.push_back(true);
                writefile << '\n' << "public:" << "\n";
            }
            else if(word == "private"){
                contract.isPublicStateVariable.push_back(false);
                writefile << '\n' << "private:" << "\n";
            }
            else if(word == "constant") {
                contract.isPublicStateVariable.push_back(true);
                writefile << '\n' << "public:" << "\n";
            }
            else{
                contract.isPublicStateVariable.push_back(true);
                writefile << '\n' << "public:" << "\n";
            }
        }
        writeDfs(newArgs);
    }
    else{
        std::cout << "Error creating state" << std::endl;
    }
}

void createContract(std::initializer_list<node*> args)
{
    // writefile << "#include <bits/stdc++.h>" << std::endl;
    writefile << "#include <cassert>" << std::endl;
    writefile << "#include <klee/klee.h>" << std::endl;
    writefile << "#include \"/home/namrata/types.h\"" << std::endl;
    writefile << "#include \"/home/namrata/functions.h\"" << std::endl;

    //check if these needed
    writefile << "#include <algorithm>" << std::endl;
    writefile << "#include <iterator>" << std::endl;
    writefile << "#include <map>" << std::endl;
    writefile << "#include <string>" << std::endl;


    std::vector<node*> newArgs;
    newArgs = listToVec(args);
    writefile << std::endl;
    writeDfs(newArgs);
    // writefile << ";";
}

void writeConstructor(std::string name)
{
    writefile << name << "(){};\n";
}
void writeConstructor(std::string structName, std::string members)
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
void createStruct(std::initializer_list<node*> args)
{
    std::vector<node*> newArgs;
    newArgs = listToVec(args);
    writefile << std::endl;
    writefile << "public:" << '\n';
    writeDfs(newArgs);
    std::string structName = nodeToString(newArgs[1]);
    std::string members = nodeToString(newArgs[3]);
    writeConstructor(structName);
    writeConstructor(structName, members);
    writefile << "};";
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
    std::string toFind = "blockhash[ ]*([ ]*block[ ]*\\.[ ]*number[ ]*)";
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

std::string checkOverlap(std::string content){
    // content += ".length + +"; //to check

    // content = ".size() += 1 ;";
    std::string message = "";
    std::vector<std::string> len{"\\.[ ]*length", "\\.[ ]*size[ ]*\\([ ]*\\)", "\\.[ ]*length[ ]*\\([ ]*\\)"};

    std::vector<std::string> change{"[ ]*\\+[ ]*\\+", "[ ]*\\-[ ]*\\-", "[ ]*\\+[ ]*=", "[ ]*\\-[ ]*=", "[ ]*="};

    for(unsigned j = 0; j < len.size(); ++j){
        for(unsigned i = 0; i < change.size(); ++i){
            std::string f = len[j] + change[i];
            // std::cout << f << '\n';
            if(searchPattern(content, f)){
                message += "Memory Overlap possible:Length of array changed";
                // std::cout << message << '\n' << f;
                // std::cout << message << '\n';
                goto end;
            }
        }
    }
    end:
    return message;
}

std::string rewriteDelete(std::string content){
    int pos = 0;
    while(content.find("delete", pos) != std::string::npos){

        std::cout << pos << " ";
        auto index = content.find("delete");
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
                            break;
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
            // }
            // pos = end + 1;
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
    std::string stmt = "";
    if(type == VECTOR){
        stmt += name + ".clear();";
    }
    else if(type == MAP){
        unsigned first = name.find('[');
        unsigned last = name.find(']');
        std::string map = name.substr(0, first);
        std::string key = name.substr (first + 1, last-first + 1);
        stmt += "auto it = " + map + ".find(" + key + ");\n";
        stmt += map + ".erase(it);";
    }

    // std::cout << stmt << std::endl;
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
