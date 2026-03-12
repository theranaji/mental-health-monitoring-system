#ifndef AST_H
#define AST_H

typedef enum {
    AST_PROGRAM, AST_DECLARATION, AST_ASSIGNMENT, AST_IF_STMT,
    AST_BINARY_OP, AST_IDENTIFIER, AST_NUMBER
} ASTNodeType;

typedef struct ASTNode {
    ASTNodeType type;
    char *value;
    struct ASTNode *left;
    struct ASTNode *right;
    struct ASTNode *next;
} ASTNode;

ASTNode* createNode(ASTNodeType type, char *value);
void freeAST(ASTNode *node);

#endif