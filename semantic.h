#ifndef SEMANTIC_H
#define SEMANTIC_H
#include "ast.h"
#include "symbol_table.h"
int semantic_analyze(const ASTNode*,SymbolTable*);
#endif
