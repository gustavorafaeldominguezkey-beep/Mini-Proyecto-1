#include <stdio.h>
#include <string.h>
#include "symbol_table.h"
void symbol_table_init(SymbolTable*t){t->count=0;}int symbol_find(const SymbolTable*t,const char*n){for(int i=0;i<t->count;i++)if(!strcmp(t->symbols[i].name,n))return i;return -1;}
int symbol_add(SymbolTable*t,const char*n,const char*ty,const char*v,int init){if(t->count>=MAX_SYMBOLS||symbol_find(t,n)>=0)return 0;Symbol*s=&t->symbols[t->count++];strncpy(s->name,n,SYMBOL_SIZE-1);strncpy(s->type,ty,SYMBOL_SIZE-1);strncpy(s->value,v?v:"",SYMBOL_SIZE-1);s->initialized=init;return 1;}
int symbol_set_value(SymbolTable*t,const char*n,const char*v){int i=symbol_find(t,n);if(i<0)return 0;strncpy(t->symbols[i].value,v,SYMBOL_SIZE-1);t->symbols[i].initialized=1;return 1;}
void symbol_table_print(const SymbolTable*t){printf("\n===== TABLA DE SIMBOLOS =====\n%-16s %-12s %-18s %-10s\n","Nombre","Tipo","Valor","Inicializada");printf("------------------------------------------------------------\n");for(int i=0;i<t->count;i++)printf("%-16s %-12s %-18s %-10s\n",t->symbols[i].name,t->symbols[i].type,t->symbols[i].initialized?t->symbols[i].value:"(sin valor)",t->symbols[i].initialized?"SI":"NO");}
