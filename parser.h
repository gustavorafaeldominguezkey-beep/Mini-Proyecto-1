#ifndef PARSER_H
#define PARSER_H
#include "lexer.h"
#include "ast.h"
typedef struct{Lexer lexer;Token current;int errors;}Parser;void parser_init(Parser*,const char*);ASTNode*parser_parse(Parser*);int parser_error_count(const Parser*);
#endif
