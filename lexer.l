%option noyywrap

%{

#include <stdio.h>
#include <string.h>
#include "grammar.h"
#include <string>
#include "/home/namrata/klee/include/klee/Core/defs.h"

%}


int8  "int8"
int16 "int16"
int24 "int24"
int32 "int32"
int64 ("int40"|"int48"|"int56"|"int64")
int128 ("int72"|"int80"|"int88"|"int96"|"int104"|"int112"|"int120"|"int128")
int256 ("int"|"int136"|"int144"|"int152"|"int160"|"int168"|"int176"|"int184"|"int192"|"int200"|"int208"|"int216"|"int224"|"int232"|"int240"|"int248"|"int256")
uint8  "uint8"
uint16 "uint16"
uint24 "uint24"
uint32 "uint32"
uint64 ("uint40"|"uint48"|"uint56"|"uint64")
uint128 ("uint72"|"uint80"|"uint88"|"uint96"|"uint104"|"uint112"|"uint120"|"uint128")
uint256 ("uint"|"uint136"|"uint144"|"uint152"|"uint160"|"uint168"|"uint176"|"uint184"|"uint192"|"uint200"|"uint208"|"uint216"|"uint224"|"uint232"|"uint240"|"uint248"|"uint256")

symbol (\.|\,|\;|\\|\:|\"|\?|\!|\~|\(|\)|\`|\|)
special ("{"|"}"|"["|"]"|"-"|"^"|"~"|"#"|"@"|"%")
rel_op ("+"|"-"|"="|"*"|"/")
rel_op2 (">"|"<"|"<="|">="|"^")
identifier [a-zA-Z_$0-9]+
space [ \t]+
newline \n
dot "\."
hexNumber  [0][x|X][0-9a-fA-F]+
decimalNumber  [0-9]+[\\.]?[0-9]*([eE][0-9]+)?
stringLiteral [\\"][^"\r\n]*[\\"]
stringLiteral2 [\\'][^'\r\n]*[\\']
text ({symbol}|{rel_op}|{int}|{special}|{space}|{identifier}|{newline})+
version ({rel_op2}*[0-9]+[\\.][0-9]+[\\.][0-9]+)

%%

[/][*][^*]*[*]+([^*/][^*]*[*]+)*[/]                   { /*printf("%s", yytext);*/}
"//".* 		                                          { /*printf("%s", yytext);*/}
"msg\.sender"         	{ printf("%s", yytext); yylval.var = new_node("msgSender"); return IDENTIFIER;}
"msg\.value"          	{ printf("%s", yytext); yylval.var = new_node("msgValue"); return IDENTIFIER;}
"msg\.data"           	{ printf("%s", yytext); yylval.var = new_node("msgData"); return IDENTIFIER;}
"msg\.gas"           	{ printf("%s", yytext); yylval.var = new_node("msgGas"); return IDENTIFIER;}
"block\.coinbase"     	{ printf("%s", yytext); yylval.var = new_node("blockCoinbase"); return IDENTIFIER;}
"block\.difficulty"   	{ printf("%s", yytext); yylval.var = new_node("blockDifficulty"); return IDENTIFIER;}
"block\.gaslimit"     	{ printf("%s", yytext); yylval.var = new_node("blockGaslimit"); return IDENTIFIER;}
"block\.number"       	{ printf("%s", yytext); yylval.var = new_node("blockNumber"); return IDENTIFIER;}
"block\.timestamp"    	{ printf("%s", yytext); yylval.var = new_node("blockTimestamp"); return IDENTIFIER;}
"now"                 	{ printf("%s", yytext); yylval.var = new_node("blockTimestamp"); return IDENTIFIER;}
"tx\.gasprice"        	{ printf("%s", yytext); yylval.var = new_node("txGasprice"); return IDENTIFIER;}
"tx\.origin"          	{ printf("%s", yytext); yylval.var = new_node("txOrigin"); return IDENTIFIER;}
"sha3"          		{ printf("%s", yytext); yylval.var = new_node("keccak256"); return IDENTIFIER;}
"contract"      		{ printf("%s", yytext); yylval.var = new_node("class "); return CONTRACT;}
"library"       		{ printf("%s", yytext); yylval.var = new_node(toString(yytext)); return LIBRARY;}
"pragma"        		{ printf("%s", yytext); yylval.var = new_node(toString(yytext)); return PRAGMA;}
"if"            		{ printf("%s", yytext); yylval.var = new_node(toString(yytext)); return IF;}
"else"          		{ printf("%s", yytext); yylval.var = new_node(toString(yytext)); return ELSE;}
"while"         		{ printf("%s", yytext); yylval.var = new_node(toString(yytext)); return WHILE;}
"do"            		{ printf("%s", yytext); yylval.var = new_node(toString(yytext)); return DO;}
"for"           		{ printf("%s", yytext); yylval.var = new_node(toString(yytext)); return FOR;}
"emit"          		{ printf("%s", yytext); yylval.var = new_node(toString(yytext)); return EMIT;}
"view"          		{ printf("%s", yytext); yylval.var = new_node(toString(yytext)); return VIEW;}
"internal"      		{ printf("%s", yytext); yylval.var = new_node(toString(yytext)); return INTERNAL;}
"external"      		{ printf("%s", yytext); yylval.var = new_node(toString(yytext)); return EXTERNAL;}
"solidity"      		{ printf("%s", yytext); yylval.var = new_node(toString(yytext)); return SOLIDITY;}
"case"          		{ printf("%s", yytext); yylval.var = new_node(toString(yytext)); return CASE;}
"switch"        		{ printf("%s", yytext); yylval.var = new_node(toString(yytext)); return SWITCH;}
"break"         		{ printf("%s", yytext); yylval.var = new_node(toString(yytext)); return BREAK;}
"continue"      		{ printf("%s", yytext); yylval.var = new_node(toString(yytext)); return CONTINUE;}
"pure"          		{ printf("%s", yytext); yylval.var = new_node(toString(yytext)); return PURE;}
"payable"       		{ printf("%s", yytext); yylval.var = new_node(toString(yytext)); return PAYABLE;}
"enum"          		{ printf("%s", yytext); yylval.var = new_node(toString(yytext)); return ENUM;}
"import"        		{ printf("%s", yytext); yylval.var = new_node(toString(yytext)); return IMPORT;}
"function"      		{ printf("%s", yytext); yylval.var = new_node(toString(yytext)); return FUNCTION;}
"constructor"   		{ printf("%s", yytext); yylval.var = new_node(toString(yytext)); return CONSTRUCTOR;}
"public"        		{ printf("%s", yytext); yylval.var = new_node(toString(yytext)); return PUBLIC;}
"private"       		{ printf("%s", yytext); yylval.var = new_node(toString(yytext)); return PRIVATE;}
"constant"      		{ printf("%s", yytext); yylval.var = new_node(toString(yytext)); return CONSTANT;}
"throw"         		{ printf("%s", yytext); yylval.var = new_node("exit(0)"); return THROW;}
"calldata"	    		{ printf("%s", yytext); yylval.var = new_node(toString(yytext)); return CALLDATA;}
"returns"       		{ printf("%s", yytext); yylval.var = new_node(toString(yytext)); return RETURNS;}
"return"        		{ printf("%s", yytext); yylval.var = new_node(toString(yytext)); return RETURN;}
"mapping"       		{ printf("%s", yytext); yylval.var = new_node(toString(yytext)); return MAPPING;}
"event"         		{ printf("%s", yytext); yylval.var = new_node(toString(yytext)); return EVENT;}
"indexed"       		{ printf("%s", yytext); yylval.var = new_node(toString(yytext)); return INDEXED;}
"modifier"      		{ printf("%s", yytext); yylval.var = new_node(toString(yytext)); return MODIFIER;}
"anonymous"     		{ printf("%s", yytext); yylval.var = new_node(toString(yytext)); return ANONYMOUS;}
"wei"           		{ printf("%s", yytext); yylval.var = new_node(toString(yytext)); return WEI;}
"days"          		{ printf("%s", yytext); yylval.var = new_node(toString(yytext)); return DAYS;}
"minutes"       		{ printf("%s", yytext); yylval.var = new_node(toString(yytext)); return MINUTES;}
"seconds"       		{ printf("%s", yytext); yylval.var = new_node(toString(yytext)); return SECONDS;}
"finney"        		{ printf("%s", yytext); yylval.var = new_node(toString(yytext)); return FINNEY;}
"weeks"         		{ printf("%s", yytext); yylval.var = new_node(toString(yytext)); return WEEKS;}
"years"         		{ printf("%s", yytext); yylval.var = new_node(toString(yytext)); return YEARS;}
"szabo"         		{ printf("%s", yytext); yylval.var = new_node(toString(yytext)); return SZABO;}
"hours"         		{ printf("%s", yytext); yylval.var = new_node(toString(yytext)); return HOURS;}
"ether"         		{ printf("%s", yytext); yylval.var = new_node(toString(yytext)); return ETHER;}
"using"         		{ printf("%s", yytext); yylval.var = new_node(toString(yytext)); return USING;}
"fixed"         		{ printf("%s", yytext); yylval.var = new_node(toString(yytext)); return FIXED;}
"ufixed"        		{ printf("%s", yytext); yylval.var = new_node(toString(yytext)); return UFIXED;}
"storage"	    		{ printf("%s", yytext); yylval.var = new_node(toString(yytext)); return STORAGE;}
"memory"	    		{ printf("%s", yytext); yylval.var = new_node(toString(yytext)); return MEMORY;}
"delete"        		{ printf("%s", yytext); yylval.var = new_node(toString(yytext)); return DELETE;}
"require"       		{ printf("%s", yytext); yylval.var = new_node("assert"); return REQUIRE;}
"assert"        		{ printf("%s", yytext); yylval.var = new_node(toString(yytext)); return ASSERT;}
"var"					{ printf("%s", yytext); yylval.var = new_node("auto "); return AUTO;}
"push"					{ printf("%s", yytext); yylval.var = new_node("push_back"); return IDENTIFIER;}
"pop"					{ printf("%s", yytext); yylval.var = new_node("pop_back"); return IDENTIFIER;}


"is"     				{ printf("%s", yytext); yylval.var = new_node(toString(yytext)); return IS;}
{version}       		{ printf("%s", yytext); yylval.var = new_node(toString(yytext));}
{dot}           		{ printf("%s", yytext); yylval.var = new_node(toString(yytext)); return DOT;}
{int8}           		{ printf("%s", yytext); yylval.var = new_node("int "); return INT;}
{int16}           		{ printf("%s", yytext); yylval.var = new_node("int "); return INT;}
{int24}           		{ printf("%s", yytext); yylval.var = new_node("int "); return INT;}
{int32}           		{ printf("%s", yytext); yylval.var = new_node("int "); return INT;}
{int64}           		{ printf("%s", yytext); yylval.var = new_node("int64 "); return INT;}
{int128}           		{ printf("%s", yytext); yylval.var = new_node("int64 "); return INT;}
{int256}           		{ printf("%s", yytext); yylval.var = new_node("int64 "); return INT;}
{uint8}           		{ printf("%s", yytext); yylval.var = new_node("unsigned "); return UINT;}
{uint16}           		{ printf("%s", yytext); yylval.var = new_node("unsigned "); return UINT;}
{uint24}           		{ printf("%s", yytext); yylval.var = new_node("unsigned "); return UINT;}
{uint32}           		{ printf("%s", yytext); yylval.var = new_node("unsigned "); return UINT;}
{uint64}           		{ printf("%s", yytext); yylval.var = new_node("uint64 "); return UINT;}
{uint128}           	{ printf("%s", yytext); yylval.var = new_node("uint64 "); return UINT;}
{uint256}           	{ printf("%s", yytext); yylval.var = new_node("uint64 "); return UINT;}
"byte"          		{ printf("%s", yytext); yylval.var = new_node("char "); return BYTE;}
"bytes1"          		{ printf("%s", yytext); yylval.var = new_node("char "); return BYTE;}
"bytes2"          		{ printf("%s", yytext); yylval.var = new_node("bytes "); return BYTE;}
"bytes3"          		{ printf("%s", yytext); yylval.var = new_node("bytes "); return BYTE;}
"bytes4"          		{ printf("%s", yytext); yylval.var = new_node("bytes "); return BYTE;}
"bytes5"          		{ printf("%s", yytext); yylval.var = new_node("bytes "); return BYTE;}
"bytes6"          		{ printf("%s", yytext); yylval.var = new_node("bytes "); return BYTE;}
"bytes7"          		{ printf("%s", yytext); yylval.var = new_node("bytes "); return BYTE;}
"bytes8"          		{ printf("%s", yytext); yylval.var = new_node("bytes "); return BYTE;}
"bytes9"          		{ printf("%s", yytext); yylval.var = new_node("bytes "); return BYTE;}
"bytes10"          		{ printf("%s", yytext); yylval.var = new_node("bytes "); return BYTE;}
"bytes11"          		{ printf("%s", yytext); yylval.var = new_node("bytes "); return BYTE;}
"bytes12"          		{ printf("%s", yytext); yylval.var = new_node("bytes "); return BYTE;}
"bytes13"          		{ printf("%s", yytext); yylval.var = new_node("bytes "); return BYTE;}
"bytes14"          		{ printf("%s", yytext); yylval.var = new_node("bytes "); return BYTE;}
"bytes15"          		{ printf("%s", yytext); yylval.var = new_node("bytes "); return BYTE;}
"bytes16"          		{ printf("%s", yytext); yylval.var = new_node("bytes "); return BYTE;}
"bytes17"          		{ printf("%s", yytext); yylval.var = new_node("bytes "); return BYTE;}
"bytes18"          		{ printf("%s", yytext); yylval.var = new_node("bytes "); return BYTE;}
"bytes19"          		{ printf("%s", yytext); yylval.var = new_node("bytes "); return BYTE;}
"bytes20"          		{ printf("%s", yytext); yylval.var = new_node("bytes "); return BYTE;}
"bytes21"          		{ printf("%s", yytext); yylval.var = new_node("bytes "); return BYTE;}
"bytes22"          		{ printf("%s", yytext); yylval.var = new_node("bytes "); return BYTE;}
"bytes23"          		{ printf("%s", yytext); yylval.var = new_node("bytes "); return BYTE;}
"bytes24"          		{ printf("%s", yytext); yylval.var = new_node("bytes "); return BYTE;}
"bytes25"          		{ printf("%s", yytext); yylval.var = new_node("bytes "); return BYTE;}
"bytes26"          		{ printf("%s", yytext); yylval.var = new_node("bytes "); return BYTE;}
"bytes27"          		{ printf("%s", yytext); yylval.var = new_node("bytes "); return BYTE;}
"bytes28"          		{ printf("%s", yytext); yylval.var = new_node("bytes "); return BYTE;}
"bytes29"          		{ printf("%s", yytext); yylval.var = new_node("bytes "); return BYTE;}
"bytes30"          		{ printf("%s", yytext); yylval.var = new_node("bytes "); return BYTE;}
"bytes31"          		{ printf("%s", yytext); yylval.var = new_node("bytes "); return BYTE;}
"bytes32"          		{ printf("%s", yytext); yylval.var = new_node("bytes "); return BYTE;}
"bytes"            		{ printf("%s", yytext); yylval.var = new_node("std::string "); return BYTE;}

"address"       		{ printf("%s", yytext); yylval.var = new_node(toString(yytext) + " "); return ADDRESS;}
"string"        		{ printf("%s", yytext); yylval.var = new_node("std::" + toString(yytext) + " "); return STRING;}
"bool"          		{ printf("%s", yytext); yylval.var = new_node(toString(yytext) + " "); return BOOL;}
"new"           		{ printf("%s", yytext); yylval.var = new_node(""); return NEW;}
"struct"        		{ printf("%s", yytext); yylval.var = new_node(toString(yytext) + " "); return STRUCT;}
"_"           			{ printf("%s", yytext); yylval.var = new_node(toString(yytext)); return UNDERSCORE;}

{decimalNumber} 		{ printf("%s", yytext); yylval.var = new_node(toString(yytext)); return DECIMAL_NUMBER;}
{hexNumber}     		{ printf("%s", yytext); yylval.var = new_node("\"" + toString(yytext) + "\""); return HEX_NUMBER;}
{identifier}    		{ printf("%s", yytext); yylval.var = new_node(toString(yytext)); return IDENTIFIER;}
{space}         		{ printf("%s", yytext);}

"=="            		{ printf("%s", yytext); yylval.var = new_node(toString(yytext)); return EQUAL2;}
">="            		{ printf("%s", yytext); yylval.var = new_node(toString(yytext)); return REL_OP;}
"&&"            		{ printf("%s", yytext); yylval.var = new_node(toString(yytext)); return LOG_OP;}
"<="            		{ printf("%s", yytext); yylval.var = new_node(toString(yytext)); return REL_OP;}
"||"            		{ printf("%s", yytext); yylval.var = new_node(toString(yytext)); return LOG_OP;}
"!"             		{ printf("%s", yytext); yylval.var = new_node(toString(yytext)); return NOT;}
"=>"            		{ printf("%s", yytext); yylval.var = new_node(toString(yytext)); return IMPLIES;}
"+="            		{ printf("%s", yytext); yylval.var = new_node(toString(yytext)); return REL_OP;}
"*="            		{ printf("%s", yytext); yylval.var = new_node(toString(yytext)); return REL_OP;}
"-="            		{ printf("%s", yytext); yylval.var = new_node(toString(yytext)); return REL_OP;}
"/="            		{ printf("%s", yytext); yylval.var = new_node(toString(yytext)); return REL_OP;}
"<<"            		{ printf("%s", yytext); yylval.var = new_node(toString(yytext)); return REL_OP;}
">>"            		{ printf("%s", yytext); yylval.var = new_node(toString(yytext)); return REL_OP;}
"<<="           		{ printf("%s", yytext); yylval.var = new_node(toString(yytext)); return REL_OP;}
">>="           		{ printf("%s", yytext); yylval.var = new_node(toString(yytext)); return REL_OP;}
"%="            		{ printf("%s", yytext); yylval.var = new_node(toString(yytext)); return REL_OP;}
"**"            		{ printf("%s", yytext); yylval.var = new_node("^"); return REL_OP;}
"!="            		{ printf("%s", yytext); yylval.var = new_node(toString(yytext)); return REL_OP;}
"++"            		{ printf("%s", yytext); yylval.var = new_node(toString(yytext)); return PLUS2;}
"--"            		{ printf("%s", yytext); yylval.var = new_node(toString(yytext)); return MINUS2;}
"="             		{ printf("%s", yytext); yylval.var = new_node(toString(yytext)); return EQUAL;}
"+"             		{ printf("%s", yytext); yylval.var = new_node(toString(yytext)); return PLUS;}
"-"             		{ printf("%s", yytext); yylval.var = new_node(toString(yytext)); return MINUS;}
"*"             		{ printf("%s", yytext); yylval.var = new_node(toString(yytext)); return STAR;}
","             		{ printf("%s", yytext); yylval.var = new_node(toString(yytext)); return COMMA;}
"/"             		{ printf("%s", yytext); yylval.var = new_node(toString(yytext)); return DIVIDE;}
"%"             		{ printf("%s", yytext); yylval.var = new_node(toString(yytext)); return MOD;}
"("             		{ printf("%s", yytext); yylval.var = new_node(toString(yytext)); return L_PAREN;}
")"             		{ printf("%s", yytext); yylval.var = new_node(toString(yytext)); return R_PAREN;}
";"             		{ printf("%s", yytext); yylval.var = new_node(toString(yytext)); return SEMICOLON;}
":"             		{ printf("%s", yytext); yylval.var = new_node(toString(yytext)); return COLON;}
"{"             		{ printf("%s", yytext); yylval.var = new_node(toString(yytext)); return L_CURLY_B;}
"}"             		{ printf("%s", yytext); yylval.var = new_node(toString(yytext)); return R_CURLY_B;}
"["             		{ printf("%s", yytext); yylval.var = new_node(toString(yytext)); return OPT_L;}
"]"             		{ printf("%s", yytext); yylval.var = new_node(toString(yytext)); return OPT_R;}
"\\$"           		{ printf("%s", yytext); yylval.var = new_node(toString(yytext)); return DOLLAR;}
"&"             		{ printf("%s", yytext); yylval.var = new_node(toString(yytext)); return REL_OP;}
"\\^"           		{ printf("%s", yytext); yylval.var = new_node(toString(yytext)); return CARET;}
"\\~"           		{ printf("%s", yytext); yylval.var = new_node(toString(yytext)); return TILDE;}
">"             		{ printf("%s", yytext); yylval.var = new_node(toString(yytext)); return LOG_OP;}
"<"             		{ printf("%s", yytext); yylval.var = new_node(toString(yytext)); return LOG_OP;}
"?"             		{ printf("%s", yytext); yylval.var = new_node(toString(yytext)); return QUES_MARK;}
{stringLiteral}      	{ printf("%s", yytext); yylval.var = new_node(toString(yytext)); return STRING_LITERAL;}
{stringLiteral2}     	{ printf("%s", yytext); yylval.var = new_node(toString(yytext)); return STRING_LITERAL;}

.                    	{ printf("%s", yytext);}

%%
