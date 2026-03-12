#include <stdio.h>
#include <stdlib.h>
#include "lexer.h"
#include "parser.h"
#include "codegen.h"

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <input.sl> <output.asm>\n", argv[0]);
        return 1;
    }
    
    FILE *input = fopen(argv[1], "r");
    if (!input) {
        perror("Error opening input file");
        return 1;
    }
    
    FILE *output = fopen(argv[2], "w");
    if (!output) {
        perror("Error opening output file");
        fclose(input);
        return 1;
    }
    
    Parser *parser = createParser(input);
    ASTNode *ast = parseProgram(parser);
    
    generateCode(ast, output);
    
    freeAST(ast);
    destroyParser(parser);
    fclose(input);
    fclose(output);
    
    printf("Compilation successful: %s -> %s\n", argv[1], argv[2]);
    return 0;
}