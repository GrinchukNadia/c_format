*This activity has been created as part of the 42 curriculum by ngrinchu.*
# Printf
A C project exploring variadic functions and formatted output.

## Description
Printf is a project developed as part of the 42 Common Core curriculum. Its main goal is to recreate the standard C printf function by implementing formatted output using variadic arguments.

The function supports multiple conversion specifiers, including characters, strings, pointers, integers, unsigned integers, and hexadecimal values.

This project helps develop a deeper understanding of variadic functions, argument handling, format string parsing, and output formatting in C.
## Instructions
### Compilation
To compile the library, run the following command:
```bash
make
```
This command compiles the source files together with the required functions from **Libft** and creates the static library `libftprintf.a`.

Other available commands:
- `make clean` - removes object files (`.o`).
- `make fclean` - removes object files and `libft.a`.
- `make re` - rebuilds the library from scratch.
- `help` - displays all available commands.

### Usage
To use this library in your own project, copy the entire repository into your project's directory.

Compile the library using make and link the generated `libftprintf.a` file with your project.

Since `libftprintf.a` includes both `ft_printf` and `Libft`, you can use all functions from both libraries in your project.

### Resources
The following resource were used during the development of this project:
- 42 subject - to follow the project requirements and constraints.
- Manual pages (man) - to study function behavior, parameters, and return values.
- [cppreference](https://cppreference.com/c) - to study function specifications and edge cases.
- [GNU Make Manual](https://www.gnu.org/software/make/manual/html_node/index.html#SEC_Contents) - to learn build rules, dependencies, and automatic variables.

AI Usage  
AI tools were used to clarify C programming concepts encountered in technical articles, explore edge cases, and discuss and improve testing strategies.

## Algorithm and Data Structures
The implementation processes the format string sequentially, writing regular characters directly to standard output and handling conversion specifiers through separate functions.

Numeric conversions use recursion to separate a number into individual digits and print them in the correct order. This eliminates the need to store and reverse the digits before printing.

The project uses va_list to access variadic arguments and the call stack to handle recursive function calls. No additional complex data structures or dynamic memory allocation are required.

The algorithm follows the natural order of processing formatted output, keeping the implementation straightforward and easy to follow.