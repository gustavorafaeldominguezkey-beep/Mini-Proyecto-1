#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H
#define MAX_SYMBOLS 100
#define SYMBOL_SIZE 128
typedef struct{char name[SYMBOL_SIZE];char type[SYMBOL_SIZE];char value[SYMBOL_SIZE];int initialized;}Symbol;
typedef struct{Symbol symbols[MAX_SYMBOLS];int count;}SymbolTable;
void symbol_table_init(SymbolTable*);int symbol_find(const SymbolTable*,const char*);int symbol_add(SymbolTable*,const char*,const char*,const char*,int);int symbol_set_value(SymbolTable*,const char*,const char*);void symbol_table_print(const SymbolTable*);
#endif
