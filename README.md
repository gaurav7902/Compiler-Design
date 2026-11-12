# Compiler Design Course Repository

Course material, practical exercises, tutorials, previous-year questions, and reference material for the Compiler Design course.

## Repository contents

```text
.
├── Book/
│   └── Modern Compiler Implementation in C.pdf
├── Labs/
│   ├── Lab_01/                # Week 1 code, samples, and practical PDF
│   ├── Lab_02/ ... Lab_11/    # Remaining weekly lab solutions and PDFs
├── Notes/
├── PYQs/
├── Tutorials/
├── Compiler-Design-Course-Logistics.pdf
└── Lecture Plan - NCSC302.pdf
```

The `Labs/` directory contains the practical sheets and source files. `Lab_01` through `Lab_11` provide one folder per practical week with implementations, input samples where needed, and the corresponding practical PDF. `Notes/` is reserved for lecture notes. `Tutorials/` contains tutorial sheets, and `PYQs/` contains previous-year question papers and solutions. The `Book/` directory contains a recommended compiler implementation reference.

## Topics covered

The material in this repository supports the main stages of compiler design, including:

- Lexical analysis and tokenization
- Regular expressions and finite automata
- Flex-based scanner construction
- Syntax analysis and parsing
- Context-free grammars
- Intermediate code and compiler implementation concepts
- Practical C and Flex programming exercises

The exact topics and schedule are documented in `Lecture Plan - NCSC302.pdf` and `Compiler-Design-Course-Logistics.pdf`.

## Faculty credit

This repository was prepared for the Compiler Design course taught by [Prof. Anjan Chowdhury](https://www.iitism.ac.in/faculty-details?faculty=anjanchowdhury), Assistant Professor in the Department of Computer Science and Engineering at IIT (ISM) Dhanbad. See also the [Google Scholar profile](https://scholar.google.com/citations?user=e1D23CoAAAAJ&hl=en).

## Running the C examples

A C compiler such as GCC is required. From the repository root:

```bash
gcc Labs/Lab_01/count.c -o lab1_single
./lab1_single Labs/Lab_01/Sample.txt
```

`count.c` accepts an input path as its command-line argument. The sample files are stored with the Week 1 programs:

```bash
cd Labs/Lab_01
gcc count.c -o count
./count Sample.txt
```

The multiple-file version accepts one or more input paths:

```bash
gcc count_multiple.c -o count_multiple
./count_multiple Sample.txt Sample2.txt
```

## Weekly lab solutions

The weekly folders contain the following implementations:

| Folder   | Programs                                                           |
| -------- | ------------------------------------------------------------------ |
| `Lab_01` | Single-file and multiple-file character, word, and line counters   |
| `Lab_02` | Flex C-token analyzer and arithmetic calculator                    |
| `Lab_03` | Flex multi-file word counter and C function analyzer               |
| `Lab_04` | Immediate and indirect left-recursion elimination                  |
| `Lab_05` | FIRST/FOLLOW computation and table-driven LL(1) parser             |
| `Lab_06` | LL(1) panic-mode recovery and operator-precedence trace            |
| `Lab_07` | Canonical LR(0) item-set construction                              |
| `Lab_08` | Lex/Yacc arithmetic expression evaluator                           |
| `Lab_09` | Syntax-tree and DAG construction with common-subexpression sharing |
| `Lab_10` | Three-address code generation                                      |
| `Lab_11` | Three-address-code overview and Graphviz CFG generation            |

For Flex programs, install Flex and GCC. For the Week 03 word counter:

```bash
cd Labs/Lab_03
flex wordcount.l
gcc lex.yy.c -o wordcount -lfl
./wordcount ../Lab_01/Sample.txt
```

For the Week 08 Lex/Yacc evaluator:

```bash
cd Labs/Lab_08
bison -d parser.y
flex lexer.l
gcc parser.tab.c lex.yy.c -o expression_parser -lfl
./expression_parser
```

The generated scanner/parser files are build outputs and do not need to be committed.

## Notes on the repository

- This is an educational course repository, not a standalone compiler implementation.
- File names and practical sheets follow the course material and may not be numbered consecutively in every directory.
- Build artifacts such as `a.out` are included only as existing local artifacts; they are not required to compile the examples.

## License

No separate license has been provided. The contents are intended for personal and academic use in the course.
