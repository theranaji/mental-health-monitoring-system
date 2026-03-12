# Repository Projects

This repository contains two distinct projects:

## 1. Mental Health Monitoring System
A comprehensive web application for mental health monitoring and sentiment analysis.

### Features
- User authentication and management
- Sentiment analysis of user inputs
- Mental health tracking dashboard
- React frontend with Python backend

### Structure
- `backend/` - Python Flask backend
- `react-frontend/` - React.js frontend application

## 2. SimpleLang Compiler
A minimal compiler for SimpleLang, a basic high-level language designed for 8-bit CPUs.

### Features
- Variable declarations, assignments, arithmetic operations
- Conditional statements (if-then)
- Generates assembly code for 8-bit CPU architectures
- Educational compiler construction project

### Structure
- `simplelang-compiler/` - Complete compiler implementation
  - Lexer, Parser, AST, Code Generator
  - Example programs and documentation
  - Build system with Makefile

## Getting Started

### Mental Health Monitoring System
```bash
# Backend setup
cd backend
pip install -r requirements.txt
python app.py

# Frontend setup
cd react-frontend
npm install
npm start
```

### SimpleLang Compiler
```bash
cd simplelang-compiler
make
./simplelang example.sl output.asm
```

## Contributing
Both projects are open for contributions and educational use.