%option yylineno

%{
  #include <iostream>
  #include <string.h>
  #include <stdlib.h>
  #include "reg.tab.hpp"
  using namespace std;
  extern int yylex();
%}
DELIM ([ \t])
WHITESPACES ({DELIM}+)
POSI_DECI ([1-9])
DECI (0|{POSI_DECI})
DECIMAL (0|{POSI_DECI}{DECI}*)
LOWER ([a-z])
LETTER ({LOWER}|[:upper:]|_)
IDENTIFIER ({LETTER}({LETTER}|{DECI})*)
STR (\".*\")
RELATIONAL_OP (==|<|>)
COMMENT \/\/(.*)(\n)*
NEW_LINE (\n)
FC [\-\+]?[0-9]*(\.[0-9]+)?

%%
{WHITESPACES} { ; }
{COMMENT} { ; }
{NEW_LINE} { ; }

if {return IF;}
else {return ELSE; }
print { return PRINT; }
for { return FOR; }
do { return DO; }
nop { return NOP; }
read {return READ; }
then { return THEN; }
int { return INT; }
real { return REAL; }


\( { return (int)'('; }
\) { return (int)')'; }
\{ { return (int)'{'; }
\} { return (int)'}'; }
; { return (int)';'; }
= { return (int)'='; }
, { return (int)','; }


"+" {
  yylval.integer = (int)'+';
  return (int)'+';
}
"-" {
  yylval.integer = (int)'-';
  return (int)'-';
}
"*" {
  yylval.integer = (int)'*';
  return (int)'*';
}
"/" {
  yylval.integer = (int)'/';
  return (int)'/';
}

{RELATIONAL_OP} {
  yylval.string=(char *)malloc((yyleng+1)*(sizeof(char)));
  strncpy(yylval.string, yytext, yyleng + 1);
  return RELATIONAL_OP;
}

"|" {
  yylval.string=(char *)malloc((yyleng+1)*(sizeof(char)));
  strncpy(yylval.string, yytext, yyleng + 1);
  return (int)'|';
}

"&" {
  yylval.string=(char *)malloc((yyleng+1)*(sizeof(char)));
  strncpy(yylval.string, yytext, yyleng + 1);
  return (int)'&';
}

"~" {
  yylval.string=(char *)malloc((yyleng+1)*(sizeof(char)));
  strncpy(yylval.string, yytext, yyleng + 1);
  return (int)'~';
}


{IDENTIFIER} {
  yylval.string=(char *)malloc((yyleng+1)*(sizeof(char)));
  strncpy(yylval.string, yytext, yyleng + 1);
  return ID;
}

{DECIMAL} {
  yylval.integer = atoi(yytext);
  return IC;
}

{FC} {
  yylval.fc = atof(yytext);
  return FC;
}

{STR} {
  yylval.string=(char *)malloc((yyleng+1)*(sizeof(char)));
  strncpy(yylval.string, yytext, yyleng + 1);
  return STR;
}

%%


int yywrap(void)
{
    return 1;
}
