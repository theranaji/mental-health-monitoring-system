#include "ast.h"
#include <stdlib.h>
#include <string.h>

ASTNode* createNode(ASTNodeType type, char *value) {
    ASTNode *node = malloc(sizeof(ASTNode));
    node->type = type;
    node->value = value ? strdup(value) : NULL;
    node->left = NULL;
    node->right = NULL;
    node->next = NULL;
    return node;
}

void freeAST(ASTNode *node) {
    if (!node) return;
    freeAST(node->left);
    freeAST(node->right);
    freeAST(node->next);
    free(node->value);
    free(node);
}