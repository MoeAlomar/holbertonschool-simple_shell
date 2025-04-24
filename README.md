# C-Simple Shell Project
![IMG_18207](https://github.com/user-attachments/assets/51d09e05-68e2-4cdb-b7ab-bb27ce5cf1e0)
# Project Description:

The `c-simple_shell` project is about building a simple program that mimics the command-line interface `(Shell)` of Unix-based systems using the `C programming language` , It is designed to help understand how a shell works internally and to closely observe the flow of processes, `input, processing, output`, The project was developed by a student team as a final project in the C programming course

# Project Objectives:

- Deep understanding of how the Shell works: Enables understanding how commands are executed and how Unix system processes are managed.
- Enhancing skills in the C language: Through working with pointers, memory management , functions , variables , and dealing with the system library.
- Handling memory leaks: By using the Valgrind tool to ensure memory efficiency and smooth performance .
- Learning and gaining teamwork skills , By dividing tasks among the team , dealing with files , exchanging experiences ,and using Git
 
# Files

| File Name            | Description |
|----------------------|-------------|
| `main.c`             | Entry point of the shell program; contains the loop that reads and executes user commands |
| `input_reader.c`     | Contains functions to read user input from the terminal |
| `exec_command.c`     | Handles the logic for executing user-entered commands |
| `parser.c`           | Parses and tokenizes user commands into executable components |
| `builtin_env.c`      | Implements built-in commands like `env` to print environment variables |
| `memory_utils.c`     | Provides helper functions for memory management, such as string allocation and deallocation |
| `path_utils.c`       | Handles searching executable paths using environment variables like `$PATH` |
| `sh_helper.c`        | Miscellaneous helper functions used across various parts of the shell |
| `shell.h`            | Main header file containing function prototypes and data structure definitions for the project |
| `man_1_simple_shell` | Manual (man) page file that explains how to use the program, supported commands, usage examples, and author information |

## How to Run the Program

### 1. Compilation

To compile all `.c` source files into a single executable named `simple_shell`, use:

```bash
gcc -Wall -Werror -Wextra -pedantic *.c -o simple_shell
```

### 2. Interactive Mode

To run the shell in interactive mode where it waits for user input:

```bash
./simple_shell
```

Here are some example commands that you can test in your `simple_shell`:

```bash
 ls
```
### `$ exit`

```bash
$ exit
```
## Authors

- **Khaled Almimoni**  
- **Mohammed Alomar**
