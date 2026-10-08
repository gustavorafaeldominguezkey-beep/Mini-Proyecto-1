#ifndef TOKEN_H
#define TOKEN_H
#define MAX_LEXEME 128
typedef enum { TOK_EOF, TOK_CREAR, TOK_COMO, TOK_ENTERO, TOK_DECIMAL, TOK_TEXTO, TOK_BOOLEANO, TOK_CARACTER, TOK_VERDADERO, TOK_FALSO, TOK_IDENTIFICADOR, TOK_NUM_ENTERO, TOK_NUM_DECIMAL, TOK_TEXTO_LITERAL, TOK_CARACTER_LITERAL, TOK_IGUAL, TOK_PUNTO_COMA, TOK_ERROR } TokenType;
typedef struct { TokenType type; char lexeme[MAX_LEXEME]; int line; int column; } Token;
const char *token_type_name(TokenType type);
#endif
