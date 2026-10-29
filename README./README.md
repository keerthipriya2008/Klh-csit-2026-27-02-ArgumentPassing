# Argument Passing

## Project Title

Argument Passing

## Subject

Operating Systems and Systems Programming

## Project Description

This project demonstrates how command-line arguments are passed from
the Linux shell to a C program.

The project uses argc and argv to receive and process command-line
arguments.

It also demonstrates process-related Linux/POSIX mechanisms such as
fork(), exec(), and wait().

## Technologies Used

- Linux / Ubuntu
- C Programming
- GCC Compiler
- Linux Terminal
- POSIX APIs
- Make / Makefile
- Git / GitHub
- VS Code

## Project Structure

ArgumentPassing/
├── src/
│   ├── argument_demo.c
│   └── process_argument.c
├── tests/
│   └── test_cases.txt
├── docs/
│   └── screenshots/
├── results/
├── reports/
├── Makefile
└── README.md

## How to Compile

Run:

make

## How to Run Basic Argument Passing

Run:

./argument_demo Jhansi 18 CSIT

## How to Run Process Argument Passing

Run:

./process_argument Jhansi 18 CSIT

## Concepts Demonstrated

1. Command-line arguments
2. argc
3. argv
4. Process creation using fork()
5. Program execution using exec()
6. Parent-child synchronization using wait()
7. Process IDs
8. Linux terminal
9. POSIX system programming

## Testing

The project is tested with:

- No arguments
- One argument
- Multiple arguments
- Process-based argument passing

## Expected Outcome

The project demonstrates how Linux command-line arguments are passed
to a C program and how process-related system calls can be used to
execute a program with specified arguments.
