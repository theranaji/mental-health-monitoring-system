#ifndef PARSER_H
#define PARSER_H

#include "lexer.h"
#include "ast.h"

typedef struct {
    FILE *file;
    Token currentToken;
} Parser;

Parser* createParser(FILE *file);
void destroyParser(Parser *parser);
ASTNode* parseProgram(Parser *parser);

#endif