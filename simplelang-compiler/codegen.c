#include "codegen.h"
#include <string.h>

static int labelCounter = 0;

static void generateExpression(ASTNode *node, FILE *output) {
    if (!node) return;
    
    switch (node->type) {
        case AST_NUMBER:
            fprintf(output, "    LDI A, %s\n", node->value);
            break;
        case AST_IDENTIFIER:
            fprintf(output, "    LDA %s\n", node->value);
            break;
        case AST_BINARY_OP:
            generateExpression(node->left, output);
            fprintf(output, "    STA temp\n");
            generateExpression(node->right, output);
            if (strcmp(node->value, "+") == 0) {
                fprintf(output, "    ADD temp\n");
            } else if (strcmp(node->value, "-") == 0) {
                fprintf(output, "    SUB temp\n");
            } else if (strcmp(node->value, "==") == 0) {
                fprintf(output, "    CMP temp\n");
            }
            break;
        default:
            break;
    }
}

static void generateStatement(ASTNode *node, FILE *output) {
    if (!node) return;
    
    switch (node->type) {
        case AST_DECLARATION:
            fprintf(output, "%s: .byte 0\n", node->value);
            break;
        case AST_ASSIGNMENT:
            generateExpression(node->right, output);
            fprintf(output, "    STA %s\n", node->value);
            break;
        case AST_IF_STMT:
            {
                int label = labelCounter++;
                generateExpression(node->left, output);
                fprintf(output, "    JNZ else_%d\n", label);
                generateStatement(node->right, output);
                fprintf(output, "else_%d:\n", label);
            }
            break;
        default:
            break;
    }
    
    if (node->next) {
        generateStatement(node->next, output);
    }
}

void generateCode(ASTNode *ast, FILE *output) {
    if (!ast || ast->type != AST_PROGRAM) return;
    
    fprintf(output, ".data\n");
    fprintf(output, "temp: .byte 0\n");
    
    ASTNode *stmt = ast->left;
    while (stmt) {
        if (stmt->type == AST_DECLARATION) {
            fprintf(output, "%s: .byte 0\n", stmt->value);
        }
        stmt = stmt->next;
    }
    
    fprintf(output, "\n.text\n");
    fprintf(output, "start:\n");
    
    generateStatement(ast->left, output);
    
    fprintf(output, "    HLT\n");
}