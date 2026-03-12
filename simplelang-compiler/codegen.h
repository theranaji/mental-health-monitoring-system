#ifndef CODEGEN_H
#define CODEGEN_H

#include "ast.h"
#include <stdio.h>

void generateCode(ASTNode *ast, FILE *output);

#endif