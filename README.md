# PRINTF FUNCTION IMPLEMENTATION

## Requirement and Compilation
Use the following compilation flags;\
    $gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o my_printf

## Description of '_printf' function
### Prototype
    int _printf(const char *format, ...);

## Description
The _printf function works te same way as the standard library 'printf'.It processes the format string and prints the formatted output.

## Conversion Specifiers
THe _printf will handle conversion specifiers like;\
    %c - for printing characters\
    %s - for printing strings\
    %% - for printing rot13'ed string

## Custom Conversion Specifiers
The _printf will print custom conversion specifiers like\
    %b - unsignedint in binary format\
    %r - printing reversed string\
    %R - printing rot13'ed string

## Usage
clone the repository

    $ git clone https://github.com/reeclerv/printf.git
compile the code \
     $gcc -Wall -Werror -Wextra -pedantic -std=gnu89 main.c _printf.c -o test

test the code\
    ./test

## Documentation
For more detailed description of the codes and functions, please refer to the comments within the files.

## Authors
Collins Abutes\
Evalyne Wambui