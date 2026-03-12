# SimpleLang Compiler

A minimal compiler for SimpleLang, a basic high-level language designed for 8-bit CPUs.

## Overview

SimpleLang is an educational programming language that demonstrates basic compiler construction principles. It compiles to assembly code for 8-bit CPU architectures and includes fundamental programming constructs without the complexity of loops or advanced features.

## Language Features

- **Variable Declarations**: `int variable_name;`
- **Assignments**: `variable = expression;`
- **Arithmetic Operations**: `+` (addition), `-` (subtraction)
- **Conditional Statements**: `if (condition) { statement }`
- **Comments**: `// single line comments`

## Installation

### Prerequisites
- GCC compiler
- Make utility
- Git (for cloning)

### Build Instructions

```bash
# Clone the repository
git clone <your-repo-url>
cd simplelang-compiler

# Build the compiler
make

# Clean build artifacts
make clean
```

## Usage

```bash
./simplelang <input_file.sl> <output_file.asm>
```

### Example

Create a SimpleLang program (`example.sl`):
```c
// Variable declarations
int a;
int b;
int result;

// Assignments
a = 15;
b = 25;
result = a + b;

// Conditional logic
if (result == 40) {
    result = result - 5;
}
```

Compile it:
```bash
./simplelang example.sl example.asm
```

## Generated Assembly

The compiler generates assembly code compatible with 8-bit CPU instruction sets:

```asm
.data
temp: .byte 0
a: .byte 0
b: .byte 0
result: .byte 0

.text
start:
    LDI A, 15
    STA a
    LDI A, 25
    STA b
    LDA a
    STA temp
    LDA b
    ADD temp
    STA result
    LDA result
    STA temp
    LDI A, 40
    CMP temp
    JNZ else_0
    LDA result
    STA temp
    LDI A, 5
    SUB temp
    STA result
else_0:
    HLT
```

## Architecture

The compiler follows a traditional three-phase design:

### 1. Lexical Analysis (Lexer)
- **Files**: `lexer.h`, `lexer.c`
- **Purpose**: Tokenizes source code into meaningful symbols
- **Tokens**: Keywords, identifiers, numbers, operators, delimiters

### 2. Syntax Analysis (Parser)
- **Files**: `parser.h`, `parser.c`, `ast.h`, `ast.c`
- **Purpose**: Builds Abstract Syntax Tree (AST) using recursive descent parsing
- **Grammar**: Handles SimpleLang syntax rules and error detection

### 3. Code Generation
- **Files**: `codegen.h`, `codegen.c`
- **Purpose**: Traverses AST to emit 8-bit assembly instructions
- **Output**: Assembly code with proper instruction mapping

## Instruction Set Mapping

| SimpleLang Construct | Assembly Instructions |
|---------------------|----------------------|
| Variable access | `LDA variable` |
| Constants | `LDI A, value` |
| Assignment | `STA variable` |
| Addition | `ADD operand` |
| Subtraction | `SUB operand` |
| Comparison | `CMP operand` |
| Conditional jump | `JNZ label` |
| Program termination | `HLT` |

## Project Structure

```
simplelang-compiler/
├── src/
│   ├── lexer.h          # Lexer interface
│   ├── lexer.c          # Lexer implementation
│   ├── parser.h         # Parser interface
│   ├── parser.c         # Parser implementation
│   ├── ast.h            # AST node definitions
│   ├── ast.c            # AST operations
│   ├── codegen.h        # Code generator interface
│   ├── codegen.c        # Code generator implementation
│   └── main.c           # Main compiler program
├── examples/
│   └── test.sl          # Example SimpleLang program
├── Makefile             # Build configuration
├── README.md            # This file
└── .gitignore          # Git ignore rules
```

## Testing

The repository includes a test program (`test.sl`) that demonstrates all language features:

```bash
# Compile the test program
./simplelang test.sl test_output.asm

# View the generated assembly
cat test_output.asm
```

## Contributing

This is an educational project. Contributions that enhance learning or add educational value are welcome:

1. Fork the repository
2. Create a feature branch
3. Make your changes
4. Add tests if applicable
5. Submit a pull request

## Educational Goals

This compiler demonstrates:
- **Lexical Analysis**: Pattern recognition and tokenization
- **Syntax Analysis**: Grammar parsing and AST construction
- **Code Generation**: Target code emission and optimization
- **Compiler Architecture**: Multi-phase compilation design
- **8-bit Computing**: Understanding resource-constrained environments

## Limitations

Current limitations (by design for educational purposes):
- No loops (while, for)
- No functions or procedures
- No arrays or complex data types
- No floating-point arithmetic
- No string handling
- Limited error reporting

## Future Enhancements

Potential educational extensions:
- Symbol table management
- Type checking
- Better error messages
- Optimization passes
- Additional operators
- More comprehensive testing

## License

This project is created for educational purposes. Feel free to use and modify for learning.

## References

- [8-bit Computer Project](https://github.com/lightcode/8bit-computer)
- Compiler Construction Principles
- Computer Architecture Fundamentals