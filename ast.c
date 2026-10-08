#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"
ASTNode*ast_create(ASTType t,const char*n,const char*d,const char*v){ASTNode*x=calloc(1,sizeof(ASTNode));if(!x)return NULL;x->type=t;if(n)strncpy(x->name,n,AST_SIZE-1);if(d)strncpy(x->data_type,d,AST_SIZE-1);if(v)strncpy(x->value,v,AST_SIZE-1);return x;}
void ast_append(ASTNode**r,ASTNode*x){if(!*r){*r=x;return;}ASTNode*p=*r;while(p->next)p=p->next;p->next=x;}
void ast_print(const ASTNode*r){printf("\n===== AST =====\n");int i=0;for(;r;r=r->next){if(r->type==AST_DECLARACION){printf("%d. DECLARACION\n   |-- nombre: %s\n   |-- tipo: %s\n   `-- valor: %s\n",++i,r->name,r->data_type,r->value[0]?r->value:"(sin valor)");}else printf("%d. ASIGNACION\n   |-- variable: %s\n   `-- valor: %s\n",++i,r->name,r->value);}}
void ast_free(ASTNode*r){while(r){ASTNode*n=r->next;free(r);r=n;}}
