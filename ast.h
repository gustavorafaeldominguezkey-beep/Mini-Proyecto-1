#ifndef AST_H
#define AST_H
#define AST_SIZE 128
typedef enum { AST_DECLARACION, AST_ASIGNACION } ASTType;
typedef struct ASTNode{ASTType type;char name[AST_SIZE];char data_type[AST_SIZE];char value[AST_SIZE];struct ASTNode*next;}ASTNode;
ASTNode*ast_create(ASTType,const char*,const char*,const char*);void ast_append(ASTNode**,ASTNode*);void ast_print(const ASTNode*);void ast_free(ASTNode*);
#endif
