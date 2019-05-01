
%{
  #include <iostream>
  #include <string.h>
  #include <stdlib.h>
  #include "y.tab.h"
  using namespace std;
  extern int yylex();
  yylType yylval;
%}

%option noyywrap
DELIM ([ \t])
WHITESPACES ({DELIM}+)
POSI_DECI ([1-9])
DECI (0|{POSI_DECI})
DECIMAL (0|{POSI_DECI}{DECI}*)
LOWER ([a-z])
IDENTIFIER ({LETTER}({LETTER}|{DECI})*)
STR (\".*\")
RELATIONAL_OP (==|<|>)
LOGICAL_OP [&\\|~]
COMMENT \/\/(.*)(\n)*

%%
{WHITESPACES} { ; }
{COMMENT} { return COMMENT; }

if {return IF;}
else {return ELSE; }
print { return PRINT; }
for { return FOR; }
do { return DO; }
nop { return NOP; }
read {return READ; }
then { return THEN; }


\( { return (int)'('; }
\) { return (int)')'; }
\{ { return (int)'{'; }
\} { return (int)'}'; }
; { return (int)';'; }
= { return (int)'='; }


"+" {
  yylval.integer = (int)'+';
  return BIN_OP;
}
"-" {
  yylval.integer = (int)'-';
  return BIN_OP;
}
"*" {
  yylval.integer = (int)'*';
  return BIN_OP;
}
"/" {
  yylval.integer = (int)'/';
  return BIN_OP;
}

{RELATIONAL_OP} {
  yylval.string=(char *)malloc((yyleng+1)*(sizeof(char)));
  strncpy(yylval.string, yytext, yyleng + 1);
  return RELATIONAL_OP;
}

{LOGICAL_OP} {
  yylval.string=(char *)malloc((yyleng+1)*(sizeof(char)));
  strncpy(yylval.string, yytext, yyleng + 1);
  return LOGICAL_OP;
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

{STR} {
  yylval.string=(char *)malloc((yyleng+1)*(sizeof(char)));
  strncpy(yylval.string, yytext, yyleng + 1);
  return STR;
}

%%
int main(int argc, char **argv) {
  if (argc < 2) {
    cout << "Please provide the input file name." << endl;
    return -1;
  }

  FILE *myfile = fopen(argv[1], "r");


  yyin = myfile;

  int s;
  while ((s = yylex())) {
    switch (s)
    {
      case '(' :
        cout << "<(> ";
        break;
      case ')' :
        cout << "<)> ";
        break;
      case '{' :
        cout << "<{> ";
        break;
      case '}' :
        cout << "<}> ";
        break;
      case ';' :
        cout << "<;> ";
        break;
      case ',' :
        cout << "<,> ";
        break;
      case '=' :
        cout << "<=> ";
        break;
      case BIN_OP:
        cout << "<BIN_OP," << (char)yylval.integer << "> ";
        break;
      case RELATIONAL_OP:
        cout << "<RELATIONAL_OP," << yylval.string << "> ";
        free(yylval.string);
        break;
      case LOGICAL_OP:
        cout << "<LOGICAL_OP," << yylval.string << "> ";
        free(yylval.string);
        break;
      case IF:
        cout << "<if> ";
        break;
      case ELSE:
        cout << "<else> ";
        break;
      case THEN:
        cout << "<then> ";
        break;
      case PRINT:
        cout << "<print> ";
        break;
      case NOP:
        cout << "<nop> ";
        break;
      case READ:
        cout << "<read> ";
        break;
      case FOR:
        cout << "<for> ";
        break;
      case DO:
        cout << "<do> ";
        break;
      case ID:
        cout << "<ID," << yylval.string << "> ";
        free(yylval.string);
        break;
      case IC:
        cout << "<IC," << yylval.integer << "> ";
        break;
      case STR:
        cout << "<str," << yylval.string << "> ";
        free(yylval.string);
        break;
      case COMMENT:
        break;
      default:;
    }
  }
}
