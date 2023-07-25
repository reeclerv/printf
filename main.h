#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* FLAGS */
#define F_NEG 1
#define F_POS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* SIZES */
#define S_LONG 2
#define S_SHORT 1

/**
 * struct fmt - Struct op
 *
 */
struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};


/**
 * typedef struct fmt fmt_t - Struct op
 *
 */
typedef struct fmt fmt_t;

int _printf(const char *format, ...);
int handle_printing(const char *fmt, int *index,
va_list arglist, char buffer[], int flags, int width, int precision, int size);

/******Functions***************************/

/* Funtions to print chars and strings */
int handle_char(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int handle_string(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int handle_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Functions to print numbers */
int handle_int(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int handle_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int print_hexa(va_list types, char map_to[],
char buffer[], int flags, char flag_ch, int width, int precision, int size);

/* Function to print non printable characters */
int print_non_printable(va_list arglist, char buffer[],
	int flags, int width, int precision, int size);

/* Funcion to print memory address */
int print_pointer(va_list arglist, char buffer[],
	int flags, int width, int precision, int size);

/* Functions to handle other specifiers */
int get_flags(const char *format, int *i);
int get_width(const char *format, int *i, va_list list);
int get_precision(const char *format, int *i, va_list list);
int get_size(const char *format, int *i);

/*Function to print string in reverse*/
int print_reverse(va_list arglist, char buffer[],
	int flags, int width, int precision, int size);

/*Function to print a string in rot 13*/
int handle_rot13string(va_list arglist, char buffer[],
	int flags, int width, int precision, int size);

/* width handler */
int handle_display_char(char c, char buffer[],
	int flags, int width, int precision, int size);
int display_number(int is_positive, int ind, char buffer[],
	int flags, int width, int precision, int size);
int display_num(int ind, char bff[], int flags, int width, int precision,
	int length, char padd, char extra_c);
int display_pointer(char buffer[], int ind, int length,
	int width, int flags, char padd, char extra_c, int padd_start);

int display_unsgnd(int is_negative, int ind,
char buffer[],
	int flags, int width, int precision, int size);
/*******UTILS**********************************************/

int is_printable(char);
int append_hexa_ascii(char ascii_val, char buffer[], int index);
int is_digit(char);

long int convert_size_number(long int num, int size);
long int convert_size_unsgnd(unsigned long int num, int size);

#endif /* MAIN_H */
