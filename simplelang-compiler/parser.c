#include "parser.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static void nextToken(Parser *parser) {
    getNextToken(parser->file, &parser->currentToken);
}

static ASTNode* parseExpression(Parser *parser);
static ASTNode* parseStatement(Parser *parser);

Parser* createParser(FILE *file) {
    Parser *parser = malloc(sizeof(Parser));
    parser->file = file;
    nextToken(parser);
    return parser;
}

void destroyParser(Parser *parser) {
    free(parser);
}

static ASTNode* parseExpression(Parser *parser) {
    ASTNode *left = NULL;
    
    if (parser->currentToken.type == TOKEN_IDENTIFIER) {
        left = createNode(AST_IDENTIFIER, parser->currentToken.text);
        nextToken(parser);
    } else if (parser->currentToken.type == TOKEN_NUMBER) {
        left = createNode(AST_NUMBER, parser->currentToken.text);
        nextToken(parser);
    }
    
    if (parser->currentToken.type == TOKEN_PLUS || parser->currentToken.type == TOKEN_MINUS) {
        ASTNode *op = createNode(AST_BINARY_OP, parser->currentToken.text);
        nextToken(parser);
        op->left = left;
        op->right = parseExpression(parser);
        return op;
    }
    
    return left;
}

static ASTNode* parseStatement(Parser *parser) {
    if (parser->currentToken.type == TOKEN_INT) {
        nextToken(parser);
        if (parser->currentToken.type == TOKEN_IDENTIFIER) {
            ASTNode *decl = createNode(AST_DECLARATION, parser->currentToken.text);
            nextToken(parser);
            if (parser->currentToken.type == TOKEN_SEMICOLON) nextToken(parser);
            return decl;
        }
    } else if (parser->currentToken.type == TOKEN_IDENTIFIER) {
        char *varName = malloc(strlen(parser->currentToken.text) + 1);
        strcpy(varName, parser->currentToken.text);
        nextToken(parser);
        if (parser->currentToken.type == TOKEN_ASSIGN) {
            nextToken(parser);
            ASTNode *assign = createNode(AST_ASSIGNMENT, varName);
            assign->right = parseExpression(parser);
            if (parser->currentToken.type == TOKEN_SEMICOLON) nextToken(parser);
            free(varName);
            return assign;
        }
        free(varName);
    } else if (parser->currentToken.type == TOKEN_IF) {
        nextToken(parser);
        if (parser->currentToken.type == TOKEN_LPAREN) {
            nextToken(parser);
            ASTNode *ifStmt = createNode(AST_IF_STMT, NULL);
            ifStmt->left = parseExpression(parser);
            if (parser->currentToken.type == TOKEN_EQUAL) {
                ASTNode *cmp = createNode(AST_BINARY_OP, "==");
                cmp->left = ifStmt->left;
                nextToken(parser);
                cmp->right = parseExpression(parser);
                ifStmt->left = cmp;
            }
            if (parser->currentToken.type == TOKEN_RPAREN) nextToken(parser);
            if (parser->currentToken.type == TOKEN_LBRACE) {
                nextToken(parser);
                ifStmt->right = parseStatement(parser);
                if (parser->currentToken.type == TOKEN_RBRACE) nextToken(parser);
            }
            return ifStmt;
        }
    }
    return NULL;
}

ASTNode* parseProgram(Parser *parser) {
    ASTNode *program = createNode(AST_PROGRAM, NULL);
    ASTNode *current = NULL;
    
    while (parser->currentToken.type != TOKEN_EOF) {
        ASTNode *stmt = parseStatement(parser);
        if (stmt) {
            if (!program->left) {
                program->left = stmt;
                current = stmt;
            } else {
                current->next = stmt;
                current = stmt;
            }
        }
    }
    
    return program;
}