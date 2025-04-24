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

| File Name        | Description |
|------------------|-------------|
| `main.c`         | Entry point of the program; manages the main loop for receiving and handling commands. |
| `builtin_env.c`  | Implements the built-in `env` command to display environment variables. |
| `exec_command.c` | Contains functions to execute commands using `fork()` to create a process and `execve()` to run the program. |
| `parser.c`       | Responsible for parsing the user's input line into command and arguments (tokens). |
| `path_utils.c`   | Works with the `PATH` environment variable to resolve the correct path of executables. |
| `memory_utils.c` | Contains helper functions for memory allocation and deallocation to prevent memory leaks. |

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

## Authors

- **Khaled Almimoni**  
- **Mohammed Alomar**
