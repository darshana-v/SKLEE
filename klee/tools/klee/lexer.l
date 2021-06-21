%option noyywrap

%{

#include <stdio.h>
#include <string.h>
#include "grammar.h"
#include <string>
#include "../../include/klee/Core/defs.h"

int lineNo = 1;
int char_pos = 1;
void show_error(int lineNo, int char_pos, std::string yytext);
int count_width(std::string text_area);
int getLen(std::string yytext);
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
newline (\n|\r|\r\n)
dot "\."
hexNumber  [0][x|X][0-9a-fA-F]+
decimalNumber  [0-9]+[\\.]?[0-9]*([eE][0-9]+)?
stringLiteral [\\"][^"\r\n]*[\\"]
stringLiteral2 [\\'][^'\r\n]*[\\']
text ({symbol}|{rel_op}|{int}|{special}|{space}|{identifier}|{newline})+
version ({rel_op2}*[0-9]+[\\.][0-9]+[\\.][0-9]+)

%%

[/][*][^*]*[*]+([^*/][^*]*[*]+)*[/]                   { lineNo += count_width(toString(yytext)); /*printf("%s", yytext);*/}
"//".* 		                                          { /*printf("%s", yytext);*/}
{newline}               { printf("%s", yytext); char_pos = 1;lineNo++; char_pos = 1;}
"msg\.sender"         	{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node("msgSender", lineNo); return IDENTIFIER;}
"msg\.value"          	{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node("msgValue", lineNo); return IDENTIFIER;}
"msg\.data"           	{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node("msgData", lineNo); return IDENTIFIER;}
"msg\.gas"           	{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node("mssgGas", lineNo); return IDENTIFIER;}
"block\.coinbase"     	{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node("blockCoinbase", lineNo); return IDENTIFIER;}
"block\.difficulty"   	{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node("blockDifficulty", lineNo); return IDENTIFIER;}
"block\.gaslimit"     	{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node("blockGaslimit", lineNo); return IDENTIFIER;}
"block\.number"       	{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node("blockNumber", lineNo); return IDENTIFIER;}
"block\.timestamp"    	{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node("blockTimestamp", lineNo); return IDENTIFIER;}
"now"                 	{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node("blockTimestamp", lineNo); return IDENTIFIER;}
"tx\.gasprice"        	{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node("txGasprice", lineNo); return IDENTIFIER;}
"tx\.origin"          	{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node("txOrigin", lineNo); return IDENTIFIER;}
"sha3"          		{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node("keccak256", lineNo); return IDENTIFIER;}
"contract"      		{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node("class ", lineNo); return CONTRACT;}
"library"       		{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node(toString(yytext), lineNo); return LIBRARY;}
"pragma"        		{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node(toString(yytext), lineNo); return PRAGMA;}
"if"            		{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node(toString(yytext), lineNo); return IF;}
"else"          		{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node(toString(yytext), lineNo); return ELSE;}
"while"         		{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node(toString(yytext), lineNo); return WHILE;}
"do"            		{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node(toString(yytext), lineNo); return DO;}
"for"           		{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node(toString(yytext), lineNo); return FOR;}
"emit"          		{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node(toString(yytext), lineNo); return EMIT;}
"view"          		{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node(toString(yytext), lineNo); return VIEW;}
"internal"      		{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node(toString(yytext), lineNo); return INTERNAL;}
"external"      		{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node(toString(yytext), lineNo); return EXTERNAL;}
"solidity"      		{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node(toString(yytext), lineNo); return SOLIDITY;}
"case"          		{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node(toString(yytext), lineNo); return CASE;}
"switch"        		{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node(toString(yytext), lineNo); return SWITCH;}
"break"         		{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node(toString(yytext), lineNo); return BREAK;}
"continue"      		{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node(toString(yytext), lineNo); return CONTINUE;}
"pure"          		{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node(toString(yytext), lineNo); return PURE;}
"payable"       		{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node(toString(yytext), lineNo); return PAYABLE;}
"enum"          		{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node(toString(yytext), lineNo); return ENUM;}
"import"        		{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node(toString(yytext), lineNo); return IMPORT;}
"function"      		{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node(toString(yytext), lineNo); return FUNCTION;}
"constructor"   		{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node(toString(yytext), lineNo); return CONSTRUCTOR;}
"public"        		{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node(toString(yytext), lineNo); return PUBLIC;}
"private"       		{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node(toString(yytext), lineNo); return PRIVATE;}
"constant"      		{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node(toString(yytext), lineNo); return CONSTANT;}
"throw"         		{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node("exit(0)", lineNo); return THROW;}
"calldata"	    		{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node(toString(yytext), lineNo); return CALLDATA;}
"returns"       		{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node(toString(yytext), lineNo); return RETURNS;}
"return"        		{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node(toString(yytext), lineNo); return RETURN;}
"mapping"       		{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node(toString(yytext), lineNo); return MAPPING;}
"event"         		{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node(toString(yytext), lineNo); return EVENT;}
"indexed"       		{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node(toString(yytext), lineNo); return INDEXED;}
"modifier"      		{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node(toString(yytext), lineNo); return MODIFIER;}
"anonymous"     		{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node(toString(yytext), lineNo); return ANONYMOUS;}
"wei"           		{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node(toString(yytext), lineNo); return WEI;}
"days"          		{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node(toString(yytext), lineNo); return DAYS;}
"minutes"       		{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node(toString(yytext), lineNo); return MINUTES;}
"seconds"       		{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node(toString(yytext), lineNo); return SECONDS;}
"finney"        		{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node(toString(yytext), lineNo); return FINNEY;}
"weeks"         		{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node(toString(yytext), lineNo); return WEEKS;}
"years"         		{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node(toString(yytext), lineNo); return YEARS;}
"szabo"         		{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node(toString(yytext), lineNo); return SZABO;}
"hours"         		{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node(toString(yytext), lineNo); return HOURS;}
"ether"         		{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node(toString(yytext), lineNo); return ETHER;}
"using"         		{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node(toString(yytext), lineNo); return USING;}
"fixed"         		{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node(toString(yytext), lineNo); return FIXED;}
"ufixed"        		{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node(toString(yytext), lineNo); return UFIXED;}
"storage"	    		{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node(toString(yytext), lineNo); return STORAGE;}
"memory"	    		{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node(toString(yytext), lineNo); return MEMORY;}
"delete"        		{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node(toString(yytext), lineNo); return DELETE;}
"require"       		{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node("assert", lineNo); return REQUIRE;}
"assert"        		{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node(toString(yytext), lineNo); return ASSERT;}
"var"					{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node("auto ", lineNo); return AUTO;}
"push"					{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node("push_back", lineNo); return IDENTIFIER;}
"pop"					{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node("pop_back", lineNo); return IDENTIFIER;}


"is"     				{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node(toString(yytext), lineNo); return IS;}
{version}       		{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node(toString(yytext), lineNo);}
{dot}           		{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node(toString(yytext), lineNo); return DOT;}
{int8}           		{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node("int ", lineNo); return INT;}
{int16}           		{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node("int ", lineNo); return INT;}
{int24}           		{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node("int ", lineNo); return INT;}
{int32}           		{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node("int ", lineNo); return INT;}
{int64}           		{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node("int64 ", lineNo); return INT;}
{int128}           		{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node("int64 ", lineNo); return INT;}
{int256}           		{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node("int64 ", lineNo); return INT;}
{uint8}           		{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node("unsigned ", lineNo); return UINT;}
{uint16}           		{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node("unsigned ", lineNo); return UINT;}
{uint24}           		{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node("unsigned ", lineNo); return UINT;}
{uint32}           		{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node("unsigned ", lineNo); return UINT;}
{uint64}           		{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node("uint64 ", lineNo); return UINT;}
{uint128}           	{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node("uint64 ", lineNo); return UINT;}
{uint256}           	{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node("uint64 ", lineNo); return UINT;}
"byte"          		{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node("char ", lineNo); return BYTE;}
"bytes1"          		{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node("char ", lineNo); return BYTE;}
"bytes2"          		{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node("bytes ", lineNo); return BYTE;}
"bytes3"          		{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node("bytes ", lineNo); return BYTE;}
"bytes4"          		{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node("bytes ", lineNo); return BYTE;}
"bytes5"          		{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node("bytes ", lineNo); return BYTE;}
"bytes6"          		{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node("bytes ", lineNo); return BYTE;}
"bytes7"          		{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node("bytes ", lineNo); return BYTE;}
"bytes8"          		{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node("bytes ", lineNo); return BYTE;}
"bytes9"          		{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node("bytes ", lineNo); return BYTE;}
"bytes10"          		{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node("bytes ", lineNo); return BYTE;}
"bytes11"          		{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node("bytes ", lineNo); return BYTE;}
"bytes12"          		{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node("bytes ", lineNo); return BYTE;}
"bytes13"          		{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node("bytes ", lineNo); return BYTE;}
"bytes14"          		{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node("bytes ", lineNo); return BYTE;}
"bytes15"          		{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node("bytes ", lineNo); return BYTE;}
"bytes16"          		{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node("bytes ", lineNo); return BYTE;}
"bytes17"          		{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node("bytes ", lineNo); return BYTE;}
"bytes18"          		{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node("bytes ", lineNo); return BYTE;}
"bytes19"          		{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node("bytes ", lineNo); return BYTE;}
"bytes20"          		{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node("bytes ", lineNo); return BYTE;}
"bytes21"          		{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node("bytes ", lineNo); return BYTE;}
"bytes22"          		{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node("bytes ", lineNo); return BYTE;}
"bytes23"          		{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node("bytes ", lineNo); return BYTE;}
"bytes24"          		{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node("bytes ", lineNo); return BYTE;}
"bytes25"          		{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node("bytes ", lineNo); return BYTE;}
"bytes26"          		{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node("bytes ", lineNo); return BYTE;}
"bytes27"          		{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node("bytes ", lineNo); return BYTE;}
"bytes28"          		{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node("bytes ", lineNo); return BYTE;}
"bytes29"          		{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node("bytes ", lineNo); return BYTE;}
"bytes30"          		{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node("bytes ", lineNo); return BYTE;}
"bytes31"          		{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node("bytes ", lineNo); return BYTE;}
"bytes32"          		{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node("bytes ", lineNo); return BYTE;}
"bytes"            		{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node("std::string ", lineNo); return BYTE;}

"address"       		{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node(toString(yytext) + " ", lineNo); return ADDRESS;}
"string"        		{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node("std::" + toString(yytext) + " ", lineNo); return STRING;}
"bool"          		{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node(toString(yytext) + " ", lineNo); return BOOL;}
"new"           		{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node("", lineNo); return NEW;}
"struct"        		{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node(toString(yytext) + " ", lineNo); return STRUCT;}
"_"           			{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node(toString(yytext), lineNo); return UNDERSCORE;}

{decimalNumber} 		{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node(toString(yytext), lineNo); return DECIMAL_NUMBER;}
{hexNumber}     		{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node("\"" + toString(yytext) + "\"", lineNo); return HEX_NUMBER;}
{identifier}    		{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node(toString(yytext), lineNo); return IDENTIFIER;}
{space}         		{ printf("%s", yytext); char_pos+= getLen(toString(yytext));}

"=="            		{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node(toString(yytext), lineNo); return EQUAL2;}
">="            		{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node(toString(yytext), lineNo); return REL_OP;}
"&&"            		{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node(toString(yytext), lineNo); return LOG_OP;}
"<="            		{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node(toString(yytext), lineNo); return REL_OP;}
"||"            		{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node(toString(yytext), lineNo); return LOG_OP;}
"!"             		{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node(toString(yytext), lineNo); return NOT;}
"=>"            		{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node(toString(yytext), lineNo); return IMPLIES;}
"+="            		{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node(toString(yytext), lineNo); return REL_OP;}
"*="            		{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node(toString(yytext), lineNo); return REL_OP;}
"-="            		{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node(toString(yytext), lineNo); return REL_OP;}
"/="            		{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node(toString(yytext), lineNo); return REL_OP;}
"<<"            		{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node(toString(yytext), lineNo); return REL_OP;}
">>"            		{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node(toString(yytext), lineNo); return REL_OP;}
"<<="           		{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node(toString(yytext), lineNo); return REL_OP;}
">>="           		{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node(toString(yytext), lineNo); return REL_OP;}
"%="            		{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node(toString(yytext), lineNo); return REL_OP;}
"**"            		{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node("^", lineNo); return REL_OP;}
"!="            		{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node(toString(yytext), lineNo); return REL_OP;}
"++"            		{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node(toString(yytext), lineNo); return PLUS2;}
"--"            		{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node(toString(yytext), lineNo); return MINUS2;}
"="             		{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node(toString(yytext), lineNo); return EQUAL;}
"+"             		{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node(toString(yytext), lineNo); return PLUS;}
"-"             		{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node(toString(yytext), lineNo); return MINUS;}
"*"             		{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node(toString(yytext), lineNo); return STAR;}
","             		{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node(toString(yytext), lineNo); return COMMA;}
"/"             		{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node(toString(yytext), lineNo); return DIVIDE;}
"%"             		{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node(toString(yytext), lineNo); return MOD;}
"("             		{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node(toString(yytext), lineNo); return L_PAREN;}
")"             		{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node(toString(yytext), lineNo); return R_PAREN;}
";"             		{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node(toString(yytext), lineNo); return SEMICOLON;}
":"             		{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node(toString(yytext), lineNo); return COLON;}
"{"             		{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node(toString(yytext), lineNo); return L_CURLY_B;}
"}"             		{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node(toString(yytext), lineNo); return R_CURLY_B;}
"["             		{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node(toString(yytext), lineNo); return OPT_L;}
"]"             		{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node(toString(yytext), lineNo); return OPT_R;}
"\\$"           		{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node(toString(yytext), lineNo); return DOLLAR;}
"&"             		{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node(toString(yytext), lineNo); return REL_OP;}
"\\^"           		{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node(toString(yytext), lineNo); return CARET;}
"\\~"           		{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node(toString(yytext), lineNo); return TILDE;}
">"             		{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node(toString(yytext), lineNo); return LOG_OP;}
"<"             		{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node(toString(yytext), lineNo); return LOG_OP;}
"?"             		{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node(toString(yytext), lineNo); return QUES_MARK;}
{stringLiteral}      	{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node(toString(yytext), lineNo); return STRING_LITERAL;}
{stringLiteral2}     	{ printf("%s", yytext); char_pos+= getLen(toString(yytext));yylval.var = new_node(toString(yytext), lineNo); return STRING_LITERAL;}
.                    	{ show_error(lineNo, char_pos, toString(yytext)); char_pos+= getLen(toString(yytext));/*printf("%s", yytext);*/}

%%

void show_error(int lineNo, int char_pos, std::string yytext)
{
    printf("Unknown token :%s at position %i on line : %i.\n", yytext.c_str(), char_pos, lineNo);
}

int count_width(std::string text_area)
{
    return std::max(
        std::count(text_area.begin(), text_area.end(), '\r'),
        std::max(std::count(text_area.begin(), text_area.end(), '\n'),
        std::count(text_area.begin(), text_area.end(), '\r\n'))
    );
}
int getLen(std::string yytext)
{
    return std::strlen(yytext.c_str());
}