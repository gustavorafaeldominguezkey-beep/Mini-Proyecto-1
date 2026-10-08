#include <stdio.h>
#include <stdlib.h>
#include "parser.h"
#include "semantic.h"
#include "symbol_table.h"
#include "ast.h"
static char*read_file(const char*f){FILE*x=fopen(f,"rb");if(!x)return NULL;fseek(x,0,SEEK_END);long n=ftell(x);rewind(x);char*b=malloc(n+1);if(!b){fclose(x);return NULL;}size_t r=fread(b,1,n,x);b[r]=0;fclose(x);return b;}
int main(int argc,char**argv){printf("========================================\n  RAFCODE - MINI COMPILADOR    \n========================================\n");if(argc!=2){printf("Uso: rafcode.exe <archivo.raf>\nEjemplo: rafcode.exe examples\\programa.raf\n");return 1;}char*s=read_file(argv[1]);if(!s){fprintf(stderr,"No se pudo abrir '%s'.\n",argv[1]);return 1;}Parser p;parser_init(&p,s);ASTNode*ast=parser_parse(&p);if(parser_error_count(&p)){printf("\n[SINTACTICO] %d error(es).\n",parser_error_count(&p));ast_free(ast);free(s);return 1;}printf("\n[SINTACTICO] Analisis correcto.\n");SymbolTable t;int e=semantic_analyze(ast,&t);if(e){printf("\n[SEMANTICO] %d error(es).\n",e);symbol_table_print(&t);ast_print(ast);ast_free(ast);free(s);return 1;}printf("[SEMANTICO] Analisis correcto.\n");symbol_table_print(&t);ast_print(ast);printf("\n========================================\nCompilacion finalizada correctamente.\n========================================\n");ast_free(ast);free(s);return 0;}
