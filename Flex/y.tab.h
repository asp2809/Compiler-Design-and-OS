
#ifndef _Y_TAB_H
#define _Y_TAB_H
#define IF 1025
#define ELSE 1026
#define FOR 1027
#define ID 1028
#define STR 1029
#define BIN_OP 1030
#define IC 1031
#define DO 1032
#define NOP 1033
#define PRINT 1034
#define READ 1035
#define THEN 1036
#define RELATIONAL_OP 1037
#define LOGICAL_OP 1038
#define COMMENT 1039

int yylex(void);
typedef union {
  char *string;
  int integer;
} yylType;
#endif