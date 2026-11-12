# Compiler Design Course Repository

A structured collection of course logistics, lecture notes, weekly laboratory programs, tutorials, previous-year questions, and reference material for Compiler Design (NCSC302).

## Repository structure

```text
.
├── Book/
│   └── Modern Compiler Implementation in C - Book by Andrew Appel.pdf
├── Labs/
│   ├── Lab_01/ … Lab_11/       # Weekly practical sheets and implementations
├── Notes/
│   ├── 1_Lexical_Analysis/     # Lex and scanner construction
│   ├── 2_Syntax Analysis/      # Parsing, Yacc, and bottom-up parsing
│   ├── 3_Semantic_Analysis/    # Semantic analysis and intermediate code
│   ├── 4_Imtermediate_Code/    # Intermediate-code generation
│   ├── 5_Code_Optimization/    # Code optimisation techniques
│   ├── Combined_pdfs/           # Consolidated study-note PDFs
│   └── Lecture 1 - compiling your code.pdf
├── PYQs/                       # Previous-year papers and solutions
├── Tutorials/                  # Tutorial sheets for Weeks 1–11
├── Compiler-Design-Course-Logistics.pdf
├── Lecture Plan - NCSC302.pdf
└── README.md
```

The repository is organised by the way the course is studied: consult the lecture plan and logistics first, use `Notes/` for concepts, practise with `Tutorials/`, implement algorithms in `Labs/`, and revise with `PYQs/`. The directory name `4_Imtermediate_Code` follows the spelling used in the supplied course material.

## Weekly labs

Each lab folder contains its practical sheet (`Practical_weekN.pdf`) and the corresponding C, Lex, or Yacc source files.

| Lab                                                                                  | Contents                                                   | Main concepts                                                          |
| ------------------------------------------------------------------------------------ | ---------------------------------------------------------- | ---------------------------------------------------------------------- |
| [`Lab_01`](/home/gaurav/Desktop/Class/Clg/Compiler%20Design/Public-Repo/Labs/Lab_01) | `count.c`, `count_multiple.c`, `Sample.txt`, `Sample2.txt` | Character, word, and line counting; processing one or more input files |
| [`Lab_02`](/home/gaurav/Desktop/Class/Clg/Compiler%20Design/Public-Repo/Labs/Lab_02) | `calculator.l`, `tokens.l`                                 | Flex rules, token recognition, and a lexical calculator                |
| [`Lab_03`](/home/gaurav/Desktop/Class/Clg/Compiler%20Design/Public-Repo/Labs/Lab_03) | `function_analyzer.l`, `wordcount.l`                       | C-function pattern analysis and multi-file word counting with Flex     |
| [`Lab_04`](/home/gaurav/Desktop/Class/Clg/Compiler%20Design/Public-Repo/Labs/Lab_04) | `left_recursion.c`, `indirect_left_recursion.c`            | Removing immediate and indirect left recursion from grammars           |
| [`Lab_05`](/home/gaurav/Desktop/Class/Clg/Compiler%20Design/Public-Repo/Labs/Lab_05) | `first_follow.c`, `ll1_parser.c`                           | FIRST/FOLLOW sets and table-driven LL(1) parsing                       |
| [`Lab_06`](/home/gaurav/Desktop/Class/Clg/Compiler%20Design/Public-Repo/Labs/Lab_06) | `ll1_panic_recovery.c`, `operator_precedence.c`            | LL(1) panic-mode error recovery and operator-precedence parsing        |
| [`Lab_07`](/home/gaurav/Desktop/Class/Clg/Compiler%20Design/Public-Repo/Labs/Lab_07) | `lr0_items.c`                                              | Canonical LR(0) item sets and closure/goto construction                |
| [`Lab_08`](/home/gaurav/Desktop/Class/Clg/Compiler%20Design/Public-Repo/Labs/Lab_08) | `lexer.l`, `parser.y`                                      | Integrating Lex and Yacc for arithmetic-expression parsing             |
| [`Lab_09`](/home/gaurav/Desktop/Class/Clg/Compiler%20Design/Public-Repo/Labs/Lab_09) | `tree_dag.c`                                               | Syntax trees, DAGs, and common-subexpression sharing                   |
| [`Lab_10`](/home/gaurav/Desktop/Class/Clg/Compiler%20Design/Public-Repo/Labs/Lab_10) | `three_address_code.c`                                     | Three-address code generation for expressions                          |
| [`Lab_11`](/home/gaurav/Desktop/Class/Clg/Compiler%20Design/Public-Repo/Labs/Lab_11) | `cfg_dot.c`                                                | Control-flow graphs and Graphviz DOT output                            |

## Notes and study material

The `Notes/` directory is grouped by compiler phase. Several topics have multiple versions because the collection preserves successive lecture-note revisions.

| Notes folder                                                                                                    | What it covers                                     | Included material                                                                                                                       |
| --------------------------------------------------------------------------------------------------------------- | -------------------------------------------------- | --------------------------------------------------------------------------------------------------------------------------------------- |
| [`1_Lexical_Analysis`](/home/gaurav/Desktop/Class/Clg/Compiler%20Design/Public-Repo/Notes/1_Lexical_Analysis)   | Lexical analysis and scanner construction          | `Lex.pdf` plus four versions of the lexical-analysis notes                                                                              |
| [`2_Syntax Analysis`](/home/gaurav/Desktop/Class/Clg/Compiler%20Design/Public-Repo/Notes/2_Syntax%20Analysis)   | Syntax analysis and parsing                        | Five versions of syntax-analysis notes, `yacc.pdf`, and a `Bottom Up Parsing/` collection                                               |
| [`3_Semantic_Analysis`](/home/gaurav/Desktop/Class/Clg/Compiler%20Design/Public-Repo/Notes/3_Semantic_Analysis) | Semantic analysis and intermediate representations | Notes on semantic analysis, including the “Semantic Analysis and intermediate code” lecture and several revisions                       |
| [`4_Imtermediate_Code`](/home/gaurav/Desktop/Class/Clg/Compiler%20Design/Public-Repo/Notes/4_Imtermediate_Code) | Intermediate-code generation                       | Four revisions of intermediate-code-generation notes                                                                                    |
| [`5_Code_Optimization`](/home/gaurav/Desktop/Class/Clg/Compiler%20Design/Public-Repo/Notes/5_Code_Optimization) | Code optimisation                                  | Three revisions covering code-optimisation techniques                                                                                   |
| [`Combined_pdfs`](/home/gaurav/Desktop/Class/Clg/Compiler%20Design/Public-Repo/Notes/Combined_pdfs)             | Quick revision                                     | Consolidated PDFs for lexical analysis, syntax analysis, bottom-up parsing, semantic analysis, intermediate code, and code optimisation |

`Notes/Lecture 1 - compiling your code.pdf` provides an introductory overview of the compilation process. The individual note files are the detailed, versioned material; the PDFs in `Combined_pdfs/` are convenient topic-wise compilations for revision.

## Other course resources

- **`Compiler-Design-Course-Logistics.pdf`** — course organisation, practical information, and requirements.
- **`Lecture Plan - NCSC302.pdf`** — lecture sequence and planned coverage.
- **`Tutorials/`** — tutorial sheets for Weeks 1 through 11.
- **`PYQs/`** — mid-semester and end-semester question papers, solutions, and scanned question images.
- **`Book/`** — _Modern Compiler Implementation in C_ by Andrew Appel, a reference for compiler construction and implementation.

## Topics covered

The collection follows the major stages of a compiler:

1. Lexical analysis, regular expressions, finite automata, and Flex.
2. Context-free grammars, syntax analysis, LL(1), operator-precedence, and LR(0) parsing.
3. Semantic analysis and syntax-directed compiler concepts.
4. Intermediate representations and three-address code.
5. Code optimisation.
6. Control-flow graphs and supporting compiler tools.

## Building selected programs

The C examples require GCC. For example:

```bash
gcc Labs/Lab_01/count.c -o lab1_single
./lab1_single Labs/Lab_01/Sample.txt
```

The multi-file counter accepts one or more input paths:

```bash
cd Labs/Lab_01
gcc count_multiple.c -o count_multiple
./count_multiple Sample.txt Sample2.txt
```

Flex examples require Flex, GCC, and (for scanners using `yywrap`) `libfl`:

```bash
cd Labs/Lab_03
flex wordcount.l
gcc lex.yy.c -o wordcount -lfl
./wordcount ../Lab_01/Sample.txt
```

The Lex/Yacc example in Lab 08 can be built with:

```bash
cd Labs/Lab_08
bison -d parser.y
flex lexer.l
gcc parser.tab.c lex.yy.c -o expression_parser -lfl
./expression_parser
```

Generated files such as `lex.yy.c`, `parser.tab.c`, and `parser.tab.h` are build outputs and do not need to be committed.

## Faculty credit

This repository was prepared for the Compiler Design course taught by [Prof. Anjan Chowdhury](https://www.iitism.ac.in/faculty-details?faculty=anjanchowdhury), Assistant Professor in the Department of Computer Science and Engineering at IIT (ISM) Dhanbad. See also the [Google Scholar profile](https://scholar.google.com/citations?user=e1D23CoAAAAJ&hl=en).

## Notes on use

- This is an educational course repository, not a standalone compiler implementation.
- Practical PDFs are retained alongside their implementations so that each program can be read in context.
- File names and note revisions preserve the original course material and may contain inconsistent capitalisation or spelling.
- No separate licence has been provided; the contents are intended for personal and academic use in the course.
