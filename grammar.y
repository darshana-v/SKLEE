//Reference: (github.com/ethereum/solidity/pull/732)
//%expect 220
%{

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
#include "/home/namrata/klee/include/klee/Core/defs.h"

void yyerror(const char *);
int yylex(void);
void writeContractContent();

std::string filename = "convertedFile.cpp";
std::ofstream file(filename, std::ios::out);

node* headNode;
std::vector<node*> modifiers;
bool isReturnIden = false;
bool hasFallback = false;
bool isArray = false;
bool hasModifier = false;
bool hasBody = true;
std::vector<std::pair<node*, node*>> funcArgs;
std::vector<node*> retList;
node* baseClass;

%}

%error-verbose
%union
{
    char* s;
    int i;
    struct node* var;
}

%start SourceUnit

%token ENUM STRUCT WHILE DO FOR IF CONTINUE BREAK RETURN SWITCH IMPORT CONTRACT AS PUBLIC PRIVATE FUNCTION INTERNAL CONSTANT DEFAULT CASE
%token BEG_TAB END_TAB L_CURLY_B R_CURLY_B PRAGMA LIBRARY INTERFACE MODIFIER IS MEMORY STORAGE CALLDATA SEND CALL TRANSFER ADDRESS DOT BOOL
%token OPT_L OPT_R SPACE BYTE HEX PURE VIEW PAYABLE MAPPING IMPLIES HEX_NUMBER STRING_LITERAL PLUS MULTIPLY EQUAL EQUAL2 PLUS2 MINUS2 L_PAREN
%token DOLLAR AMP CARET MOD NUMBER_LITERAL IDENTIFIER DECIMAL_NUMBER REL_OP LOG_OP QUES_MARK COLON EMIT UINT SOLIDITY VERSION EVENT INDEXED
%token FINNEY ETHER SECONDS MINUTES HOURS DAYS WEEKS YEARS UNDERSCORE ANONYMOUS USING NOT FIXED UFIXED R_PAREN COMMA STAR TRUE FALSE TEXT
%token CONSTRUCTOR DELETE REQUIRE ASSERT AUTO ELSE THROW EXTERNAL RETURNS COMMENT STRING INT NEW FROM MINUS DIVIDE WEI SZABO TILDE SEMICOLON

%type <var> ENUM STRUCT WHILE DO FOR IF CONTINUE BREAK RETURN SWITCH IMPORT CONTRACT AS PUBLIC PRIVATE FUNCTION INTERNAL CONSTANT DEFAULT
BEG_TAB END_TAB L_CURLY_B R_CURLY_B PRAGMA LIBRARY INTERFACE MODIFIER IS MEMORY STORAGE CALLDATA SEND CALL TRANSFER ADDRESS DOT BOOL STRING
OPT_L OPT_R SPACE BYTE HEX PURE VIEW PAYABLE MAPPING IMPLIES HEX_NUMBER STRING_LITERAL PLUS IDENTIFIER REQUIRE ASSERT EQUAL2 PLUS2 MINUS2
DOLLAR AMP CARET MOD NUMBER_LITERAL DECIMAL_NUMBER REL_OP LOG_OP QUES_MARK COLON EMIT UINT SOLIDITY VERSION EVENT INDEXED WEI SZABO TILDE
FINNEY ETHER SECONDS MINUTES HOURS DAYS WEEKS YEARS UNDERSCORE ANONYMOUS USING FIXED UFIXED CONSTRUCTOR NOT DELETE AUTO FALSE TEXT
CASE ELSE THROW EXTERNAL RETURNS COMMENT  INT NEW FROM MINUS DIVIDE MULTIPLY EQUAL SEMICOLON L_PAREN R_PAREN COMMA STAR TRUE

%type <var> NumberLiteral BooleanLiteral NumberUnit SourceUnit
%type <var> Operator ContractDefinition ContractPart UsingForDeclaration StructDefinition Vars StorageLocation ModifierDefinition
ModifierInvocation EventParameter EventDefinition EventParameterList EnumValue EnumValues EnumDefinition StateVariableDeclaration
StateMutability IfStatement ForStatement WhileStatement ReturnList Parameter Parameter2 ParameterList SimpleStatement
FunctionCall FunctionTypeName FunctionAttribute FunctionDefinition FunctionCallArguments VariableAttribute AssertStatement
VariableDefinition VariableDeclaration VarDec2 TypeName ArrayTypeName Mapping ElementaryTypeName Unary1 Unary2
Expression NewExpression MemberAccess IndexAccess IndexAccess2 Qualifier UserDefinedTypeName PrimaryExpression
ExpressionList NameValue NameValueList EmitStatement DoWhileStatement Statement ExpressionStatement Block BaseClass

// Version: VERSION | VERSION Version
// Anytext: TEXT;


%%

SourceUnit: ContractDefinition
{   clearContractData(); writeContractContent();
    writefile.str(std::string()); writeDecl.str(std::string());}
    SourceUnit {$$ = new_node({$1, $3}); headNode = $$;}

| ContractDefinition
{$$ = $1; headNode = $$;}

| PragmaDirective SourceUnit
{$$ = $2; headNode = $$;};

PragmaDirective: PRAGMA SOLIDITY SEMICOLON;

ContractDefinition: CONTRACT IDENTIFIER L_CURLY_B
{	createContract({$1, $2, new_node(": virtual public address"), $3}); contract.name = $2->data;}
ContractPart R_CURLY_B
{
	addContractName($2);
	writefile << "public:\n";
	writeAddrConstructor(contract.name);
	if(!contract.hasDefaultConstructor /*&& contract.hasParaConstructor*/){
        writefile << "public:\n";
        writeConstructor(writefile, contract.name);
        writefile << '\n';
    }
	writefile << "};\n"; $$ = new_node({$1, $2, new_node(": virtual public address"), $3, $5, $6});
}

| CONTRACT IDENTIFIER IS BaseClass L_CURLY_B
{	createContract({$1, $2, new_node(": virtual public address, "), $4, $5}); contract.name = $2->data; baseClass = $4;}
ContractPart R_CURLY_B
{
	addContractName($2);
	writefile << "public:\n";
	writeAddrConstructor(contract.name);
	if(!contract.hasDefaultConstructor /*&& contract.hasParaConstructor*/){
        writefile << "public:\n";
        writeConstructor(writefile, contract.name);
        writefile << '\n';
    }
	writefile << "};\n"; $$ = new_node({$1, $2, new_node(": virtual public address, "), $4, $5, $7, $8});
}
;

BaseClass : IDENTIFIER {$$ = new_node({new_node("public "), $1});}
| IDENTIFIER COMMA BaseClass {$$ = new_node({new_node("public "), $1, $2, $3});}
;


ContractPart: StateVariableDeclaration ContractPart
{$$ = new_node({$1, $2});}

|  FunctionDefinition ContractPart
{$$ = new_node({$1, $2});}

|  UsingForDeclaration ContractPart
{$$ = new_node({$1, $2});}

|  StructDefinition ContractPart
{$$ = new_node({$1, $2});}

|  ModifierDefinition ContractPart
{$$ = new_node({$1, $2});}

|  EventDefinition ContractPart
{$$ = new_node({$1, $2});}

|  EnumDefinition ContractPart
{$$ = new_node({$1, $2});}

|  { $$ = new_node(); } ;
;

UsingForDeclaration: USING IDENTIFIER FOR STAR SEMICOLON
{$$ = new_node({$1, $2, $3, $4, $5});}

| USING IDENTIFIER FOR TypeName SEMICOLON
{$$ = new_node({$1, $2, $3, $4, $5});}
;

StructDefinition: STRUCT IDENTIFIER L_CURLY_B Vars R_CURLY_B
{$$ = new_node({$1, $2, $3, $4, $5}); createStruct({$1, $2, $3, $4});}
;

Vars: VariableDeclaration SEMICOLON Vars
{$$ = new_node({$1, $2, $3});}

| VariableDeclaration SEMICOLON {$$ = new_node({$1, $2});}
;

StorageLocation: MEMORY {$$ = $1;}
| STORAGE {$$ = $1;}
| CALLDATA {$$ = $1;}
;

ModifierDefinition: MODIFIER IDENTIFIER ParameterList Block
{$$ = new_node({$1, $2, $3, $4}); FunctionData* f = createFunction(MODIFIER_TYPE, {$2, $3, $4}, new_node("public")); contract.functions.push_back(f); funcArgs.clear();}

| MODIFIER IDENTIFIER Block
{$$ = new_node({$1, $2, $3}); FunctionData* f = createFunction(MODIFIER_TYPE, {$2, new_node("()"), $3}, new_node("public")); contract.functions.push_back(f);}    /*considering only this for now*/
;

ModifierInvocation: IDENTIFIER {$$ = $1; hasModifier = true; modifiers.push_back(new_node({$1, new_node("()")}));}

| IDENTIFIER L_PAREN ExpressionList R_PAREN
{$$ = new_node({$1, $2, $3, $4}); hasModifier = true; modifiers.push_back($$);}

| IDENTIFIER L_PAREN R_PAREN
{$$ = new_node({$1, $2, $3}); hasModifier = true; modifiers.push_back($$);}
;


EventDefinition: EVENT IDENTIFIER EventParameterList ANONYMOUS SEMICOLON
{$$ = new_node({$1, $2, $3, $5}); createFunction(NORETURN_TYPE, {$2, $3, new_node("{}")}, new_node("public")); funcArgs.clear();}

| EVENT IDENTIFIER EventParameterList SEMICOLON
{$$ = new_node({$1, $2, $3, $4}); createFunction(NORETURN_TYPE, {$2, $3, new_node("{}")}, new_node("public")); funcArgs.clear();}
;

EventParameterList: L_PAREN EventParameter R_PAREN {$$ = new_node({$1, $2, $3});}

| L_PAREN R_PAREN {$$ = new_node({$1, $2});}
;

EventParameter: TypeName INDEXED IDENTIFIER COMMA EventParameter
{$$ = new_node({$1, $3, $4, $5});}

| TypeName INDEXED IDENTIFIER {$$ = new_node({$1, $3});}

| TypeName IDENTIFIER COMMA EventParameter {$$ = new_node({$1, $2, $3, $4});}

| TypeName IDENTIFIER {$$ = new_node({$1, $2});}

| TypeName {$$ = $1;}
;

EnumValue: IDENTIFIER {$$ = $1;};

EnumDefinition: ENUM IDENTIFIER L_CURLY_B R_CURLY_B
{$$ = new_node({$1, $2, $3, $4}); createEnum({$1, $2, $3, $4});}

| ENUM IDENTIFIER L_CURLY_B EnumValue EnumValues R_CURLY_B
{$$ = new_node({$1, $2, $3, $4, $5, $6}); createEnum({$1, $2, $3, $4, $5, $6});}
;

EnumValues: COMMA EnumValue EnumValues
{$$ = new_node({$1, $2, $3});}

|{ $$ = new_node(); } ;
;

StateVariableDeclaration: TypeName VariableAttribute IDENTIFIER SEMICOLON
{$$ = new_node({$1, $2, $3, $4}); createState({$1, $3, $4}, $2, false);}

| TypeName VariableAttribute IDENTIFIER EQUAL Expression SEMICOLON
{$$ = new_node({$1, $2, $3, $4, $5, $6}); createState({$1, $3, $4, $5, $6}, $2, true);}
;

StateMutability: PURE {$$ = $1;}
| VIEW {$$ = $1;}
| PAYABLE {$$ = $1;}
;

Qualifier: PUBLIC {$$ = $1;}
| PRIVATE {$$ = $1;}
| CONSTANT {$$ = $1;}
| INTERNAL  {$$ = $1;}
| EXTERNAL {$$ = $1;}
;

VariableAttribute: Qualifier VariableAttribute
{$$ = new_node({$1, $2});}

| StateMutability VariableAttribute
{$$ = new_node({$1, $2});}

| { $$ = new_node(); }
;

FunctionAttribute: Qualifier FunctionAttribute
{$$ = new_node({$1, $2});}

| StateMutability FunctionAttribute
{$$ = new_node({$1, $2});}

| ModifierInvocation FunctionAttribute
{$$ = new_node({$1, $2});}

| { $$ = new_node(); } ;


FunctionDefinition: FUNCTION IDENTIFIER ParameterList FunctionAttribute RETURNS ReturnList Block
{	$$ = new_node({$1, $2, $3, $4, $5, $6, $7});
	node* ret = $6;
	if(!hasBody && isReturnIden){
		addRetVariables($6, $7, hasBody);
		ret = getRetType($6);
		hasBody = true;
		isReturnIden = false;
	}
	if(!hasBody){
		addRetVariables($6, $7, hasBody);
		// ret = getRetType($6);
		hasBody = true;
	}

	if(isReturnIden){
		addRetVariables($6, $7, hasBody);
		ret = getRetType($6/*retList*/);
		isReturnIden = false;
	}

	if(hasModifier){
		addModifier(modifiers, $7);
		hasModifier = false;
	}

	FunctionData* f = createFunction(RETURN_TYPE, {ret, $2, $3, $7}, $4);
	setFunctionDataAttr(f, funcArgs);
	contract.functions.push_back(f);
	funcArgs.clear();
	// if(!retList.empty())
	retList.clear();
	modifiers.clear();
}

| FUNCTION IDENTIFIER ParameterList FunctionAttribute Block
{	$$ = new_node({$1, $2, $3, $4, $5});
	if(hasModifier){
		addModifier(modifiers, $5);
	}
	hasModifier = false;

	FunctionData* f = createFunction(NORETURN_TYPE, {$2, $3, $5}, $4);
	setFunctionDataAttr(f, funcArgs);
	contract.functions.push_back(f);
	funcArgs.clear();
	modifiers.clear();
}

| CONSTRUCTOR ParameterList FunctionAttribute Block
{$$ = new_node({$1, $2, $3, $4}); FunctionData* f = createFunction(CONSTRUCTOR_TYPE, {$2, $4}, $3);
setFunctionDataAttr(f, funcArgs); contract.functions.push_back(f); funcArgs.clear(); hasModifier = false;}

| FUNCTION L_PAREN R_PAREN FunctionAttribute Block
{$$ = new_node({$1, $2, $3, $4, $5}); FunctionData* f = createFunction(FALLBACK_TYPE, {new_node("void fallback()"), $5}, $4);
setFunctionDataAttr(f, funcArgs); contract.functions.push_back(f); funcArgs.clear(); hasFallback = true; hasModifier = false;}
;

ParameterList: L_PAREN Parameter R_PAREN {$$ = new_node({$1, $2, $3});}
;

Parameter: TypeName IDENTIFIER COMMA {funcArgs.push_back(std::make_pair($2, $1));} Parameter {$$ = new_node({$1, $2, $3, $5});}
| TypeName StorageLocation IDENTIFIER {$$ = new_node({$1, $3}); funcArgs.push_back(std::make_pair($3, $1));}
| TypeName IDENTIFIER {$$ = new_node({$1, $2}); funcArgs.push_back(std::make_pair($2, $1));}
| TypeName {$$ = $1;}         /*added for function prototyypes*/
| { $$ = new_node();}
;

ReturnList: L_PAREN Parameter2 R_PAREN {$$ = $2;}   /*todo: removed () considering only one return type*/
;

Parameter2: TypeName {$$ = $1; retList.push_back($1);}
| TypeName IDENTIFIER {$$ = new_node({$1, $2, new_node(";")}); retList.push_back($1); isReturnIden = true; }
| TypeName COMMA Parameter2 { $$ = new_node({$1, $2, $3}); retList.push_back($2); retList.push_back($1); isReturnIden = true;}     /*todo: returning only one type*/
| TypeName IDENTIFIER COMMA Parameter2 {$$ = new_node({$1, $2, new_node(";"), $4}); retList.push_back($3); retList.push_back($1); isReturnIden = true; }
;

VariableDeclaration: TypeName StorageLocation IDENTIFIER EQUAL Expression {$$ = new_node({$1, $3, $4, $5});}
| TypeName StorageLocation IDENTIFIER {$$ = new_node({$1, $3});}
| TypeName IDENTIFIER {$$ = new_node({$1, $2});}
| TypeName IDENTIFIER EQUAL Expression {$$ = new_node({$1, $2, $3, $4});}
;

TypeName: ElementaryTypeName {$$ = $1;}
| Mapping {$$ = $1;}
| UserDefinedTypeName {$$ = $1;}
| ArrayTypeName {$$ = $1;}
| FunctionTypeName {$$ = $1;}
| ADDRESS PAYABLE {$$ = new_node({$1, $2});}
;

UserDefinedTypeName: IDENTIFIER {$$ = $1;};  /*incomplete*/

/*Udtn: DOT IDENTIFIER Udtn  //causes problem with function call with dot
| DOT IDENTIFIER  ;*/

Mapping: MAPPING L_PAREN ElementaryTypeName IMPLIES TypeName R_PAREN
{
	node* temp1 = new_node("std::map");
	node* temp2 = new_node("<");
	node* temp3 = new_node(">");
	node* temp4 = new_node(",");
	$$ = new_node({temp1, temp2, $3, temp4, $5, temp3});
};

ArrayTypeName: TypeName OPT_L OPT_R {$$ = new_node({new_node("struct Vector"), new_node("<"), $1, new_node(">")}); isArray = true;}
| TypeName OPT_L Expression OPT_R  {$$ = new_node({$1, $2, $3, $4}); isArray = true;}
;

FunctionTypeName: FUNCTION ParameterList RETURNS ParameterList {$$ = new_node({$1, $2, $3, $4});}
; /*incomplete*/

Block: L_CURLY_B Statement R_CURLY_B {$$ = new_node({$1, $2, $3});}
| SEMICOLON {$$ = new_node({new_node("{"), new_node("}")}); hasBody = false;}
;

Statement:  Statement IfStatement {$$ = new_node({$1, $2});}
| Statement WhileStatement {$$ = new_node({$1, $2});}
| Statement ForStatement {$$ = new_node({$1, $2});}
| L_CURLY_B Statement R_CURLY_B {$$ = new_node({$1, $2, $3});}
| Statement SimpleStatement SEMICOLON {$$ = new_node({$1, $2, $3});}
| Statement DoWhileStatement SEMICOLON {$$ = new_node({$1, $2, $3});}
| Statement CONTINUE SEMICOLON {$$ = new_node({$1, $2, $3});}
| Statement BREAK SEMICOLON {$$ = new_node({$1, $2, $3});}
| Statement RETURN L_PAREN ExpressionList R_PAREN SEMICOLON {$$ = new_node({$1, $2, new_node("std::make_tuple"), $3, $4, $5, $6});}
| Statement RETURN Expression SEMICOLON {$$ = new_node({$1, $2, $3, $4});}
| Statement RETURN SEMICOLON {$$ = new_node({$1, $2, $3});}
| Statement THROW SEMICOLON {$$ = new_node({$1, $2, $3});}
| Statement EmitStatement SEMICOLON {$$ = new_node({$1, $2, $3});}
| Statement UNDERSCORE {$$ = new_node({$1, new_node("return true; return false;")});}
| Statement UNDERSCORE SEMICOLON {$$ = new_node({$1, new_node("return true; return false"), $3});}
| Statement AssertStatement SEMICOLON {$$ = new_node({$1, $2, $3});}

| { $$ = new_node(); }

;

AssertStatement : REQUIRE L_PAREN Expression R_PAREN {$$ = new_node({$1, $2, $3, $4});};
| ASSERT L_PAREN Expression R_PAREN {$$ = new_node({$1, $2, $3, $4});};
| REQUIRE L_PAREN Expression COMMA STRING_LITERAL R_PAREN {node* temp = new_node("&&"); $$ = new_node({$1, $2, $3, temp, $5, $6});};
| ASSERT L_PAREN Expression COMMA STRING_LITERAL R_PAREN {node* temp = new_node("&&"); $$ = new_node({$1, $2, $3, temp, $5, $6});};


ExpressionStatement: Expression {$$ = $1;};

IfStatement: IF L_PAREN Expression R_PAREN Statement {$$ = new_node({$1, $2, $3, $4, $5});}
| IF L_PAREN  Expression R_PAREN Statement ELSE Statement {$$ = new_node({$1, $2, $3, $4, $5, $6, $7});};


WhileStatement: WHILE L_PAREN Expression R_PAREN Statement  {$$ = new_node({$1, $2, $3, $4, $5});}
;

SimpleStatement: Expression {$$ = $1;}
| VariableDefinition {$$ = $1;}
;

ForStatement: FOR L_PAREN SimpleStatement SEMICOLON Expression SEMICOLON ExpressionStatement R_PAREN Statement
{$$ = new_node({$1, $2, $3, $4, $5, $6, $7, $8, $9});}
;

DoWhileStatement: DO Statement WHILE L_PAREN Expression R_PAREN  {$$ = new_node({$1, $2, $3, $4, $5, $6});}
;

EmitStatement: EMIT FunctionCall {$$ = $2;}; //emit removed

VariableDefinition: VariableDeclaration {$$ = $1;}
| L_PAREN VariableDeclaration VarDec2 R_PAREN EQUAL Expression {$$ = new_node({$1, $2, $3, $4, $5, $6});}
| L_PAREN VarDec2 R_PAREN  {$$ = new_node({$1, $2, $3});}
;

VarDec2: COMMA VariableDeclaration {$$ = new_node({$1, $2});}
| { $$ = new_node(); }
;

// Precedence by order (github.com/ethereum/solidity/pull/732)
Expression: Expression Unary1 {$$ = new_node({$1, $2});}
| NewExpression {$$ = $1;}
| IndexAccess {$$ = $1;}
| FunctionCall {$$ = $1;}
| MemberAccess {$$ = $1;}
| OPT_L ExpressionList OPT_R {$$ = new_node({new_node("{"), $2, new_node("}")});}
| L_PAREN Expression R_PAREN {$$ = new_node({$1, $2, $3});}
| Unary2 Expression {$$ = new_node({$1, $2});}
| Expression LOG_OP Expression {$$ = new_node({$1, $2, $3});}
| Expression QUES_MARK Expression COLON Expression {$$ = new_node({$1, $2, $3, $4, $5});}
| Expression Operator Expression {$$ = new_node({$1, $2, $3});}
| Expression REL_OP Expression {$$ = new_node({$1, $2, $3});}
| PrimaryExpression {$$ = $1;}
;

Operator: EQUAL {$$ = $1;}
| PLUS {$$ = $1;}
| MINUS {$$ = $1;}
| DIVIDE {$$ = $1;}
| STAR {$$ = $1;}
| MOD {$$ = $1;}
| EQUAL2 {$$ = $1;}
| CARET {$$ = $1;}
;

Unary1: PLUS2 {$$ = $1;}
| MINUS2 {$$ = $1;}
;

Unary2: PLUS2 {$$ = $1;}
| PLUS {$$ = $1;}
| MINUS {$$ = $1;}
| TILDE {$$ = $1;}
| DELETE {$$ = $1;}
| MINUS2 {$$ = $1;}
| NOT {$$ = $1;}
;

PrimaryExpression: BooleanLiteral {$$ = $1;}
| NumberLiteral {$$ = $1;}
| STRING_LITERAL {node* temp = changeQuotes($1); $$ = temp;}
| IDENTIFIER {$$ = $1;}
| ElementaryTypeName {$$ = $1;}
;

ExpressionList: Expression {$$ = $1;}
| Expression COMMA ExpressionList {$$ = new_node({$1, $2, $3});}
;

/*edited: 2, 3 removed */
NameValue: COMMA IDENTIFIER COLON Expression NameValue {$$ = new_node({$1, $4, $5});}
| { $$ = new_node(); }
;

/*edited: 2, 3 removed */
NameValueList: IDENTIFIER COLON Expression NameValue {$$ = new_node({$3, $4});}
;

/*edited: 1, 3 removed */
FunctionCallArguments: L_CURLY_B NameValueList R_CURLY_B {$$ = new_node({$2});}
| L_CURLY_B R_CURLY_B {$$ = new_node();}   /*1, 2 removed*/
| ExpressionList {$$ = $1;}
;

FunctionCall: Expression L_PAREN FunctionCallArguments R_PAREN {$$ = new_node({$1, $2, $3, $4});}
| Expression L_PAREN R_PAREN  {$$ = new_node({$1, $2, $3});}
;

NewExpression: NEW TypeName {$$ = new_node({$1, $2});}
;

MemberAccess: Expression DOT IDENTIFIER  {$$ = new_node({$1, $2, $3});}
| IDENTIFIER DOT IDENTIFIER {$$ = new_node({$1, $2, $3});}
| IDENTIFIER DOT IndexAccess {$$ = new_node({$1, $2, $3});}
| Expression DOT IndexAccess  {$$ = new_node({$1, $2, $3});}
;

IndexAccess: IDENTIFIER OPT_L Expression OPT_R IndexAccess2  {$$ = new_node({$1, $2, $3, $4, $5});}  /*{$$ = concatStr({$1, $2  $3, $4, $5});}*/
| IDENTIFIER OPT_L OPT_R  {$$ = new_node({$1, $2, $3});};  /*Expression instead of first Identifier, indexAccess2 added*/

IndexAccess2: OPT_L Expression OPT_R {$$ = new_node({$1, $2, $3});}
| OPT_L OPT_R {$$ = new_node({$1, $2});}
| { $$ = new_node();};
;

BooleanLiteral: TRUE {$$ = $1;}
| FALSE {$$ = $1;}
;

NumberLiteral: HEX_NUMBER {$$ = $1;}
| DECIMAL_NUMBER {$$ = $1;}
| HEX_NUMBER NumberUnit {$$ = new_node({$1, $2});}
| DECIMAL_NUMBER NumberUnit  {$$ = new_node({$1, $2});}
;

NumberUnit: WEI {$$ = $1;}
| SZABO {$$ = $1;}
| FINNEY {$$ = $1;}
| ETHER {$$ = $1;}
| SECONDS {$$ = $1;}
| MINUTES {$$ = $1;}
| HOURS {$$ = $1;}
| DAYS {$$ = $1;}
| WEEKS {$$ = $1;}
| YEARS {$$ = $1;}
;


ElementaryTypeName: ADDRESS {$$ = $1;}
| BOOL {$$ = $1;}
| STRING {$$ = $1;}
| INT {$$ = $1;}
| UINT {$$ = $1;}
| BYTE {$$ = $1;}
| AUTO {$$ = $1;}
;

//Fixed: FIXED | FIXED DECIMAL_NUMBER "x" DECIMAL_NUMBER;

//Ufixed: UFIXED | UFIXED DECIMAL_NUMBER "x" DECIMAL_NUMBER;


%%

void writeContractContent(){
	std::string content = writeDecl.str() + writefile.str();
    file << content;
}

void yyerror(const char *msg)
{
    printf("\nError:\n");
    fprintf(stderr,"%s\n",msg);
}

int main(int argc, char* argv[])
{
    int x = yyparse();
    dfs(headNode);

    std::string content = writeDecl.str() + writefile.str();
    file << content;
    file.close();

    replaceKeywords(filename);

    file.open(filename, std::ios::app);
    addMainFunction(file);
    file.close();

    rewriteContent(filename);

    contract.writeContract();
    writeContractNames();
    
    return x;
}
