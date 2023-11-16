# Monty Bytecode Interpreter

## Usage

To use the Monty bytecode interpreter, run the following command:

```bash
monty file
```

Here, "file" is the path to the file containing Monty bytecode.

## Error Handling

- If the user doesn't provide any file or provides more than one argument, the program will print the error message:

  ```bash
  USAGE: monty file
  ```

  ...followed by a new line, and exit with the status EXIT_FAILURE.

- If it's not possible to open the specified file, the program will print the error message:

  ```bash
  Error: Can't open file <file>
  ```

  ...followed by a new line, and exit with the status EXIT_FAILURE, where `<file>` is the name of the file.

- If the file contains an invalid instruction, the program will print the error message:

  ```bash
  L<line_number>: unknown instruction <opcode>
  ```

  ...followed by a new line, and exit with the status EXIT_FAILURE, where `<line_number>` is the line number where the invalid instruction appears.

## Program Execution

The Monty program runs the bytecodes line by line and stops if:

- It executed properly every line of the file.
- It finds an error in the file.
- An error occurred.

## Memory Management

If the program can't allocate more memory using malloc, it will print the error message:

```bash
Error: malloc failed
```

...followed by a new line, and exit with status EXIT_FAILURE. The program is required to use malloc and free and is not allowed to use any other function from `man malloc` (realloc, calloc, …).
