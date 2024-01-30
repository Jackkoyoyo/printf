#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* FLAGS */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* SIZES */
#define S_LONG 2
#define S_SHORT 1



#ifndef _MAIN_H_
#define _MAIN_H_

/* begin standard C header files */
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>
#include <stdio.h>

/* macros */

#define BUFSIZE 1024
#define TRUE (1 == 1)
#define FALSE !TRUE
#define LOWHEXA 0
#define UPHEXA 1

/* structs */
/**
 * struct commonvar_s - common variables needed
 * @format: the input format string
 * @in: index to traverse the format string
 * @args: the variadic arguments list of input arguments
 * @buffer: buffer to be written to before writing to stdout
 * @buf_index: index to traverse the buffer, also total chars written
 * @flag: notifies if there was a modifier flag
 * @space: notifies if space was printed
 * @ch0: character to be written to buffer
 * @ch1: character checking after % character
 * @ch2: character to check 2 spaces after % symbol
 * @ch3: unused for now, but may become a third specifier
 * @error: indicates error or not (0 no error, 1 error)
 */
typedef struct commonvar_s
{
	const char *format;
	int in;
	va_list *args;
	char *buffer;
	int buf_index;
	int flag;
	int space;
	char ch0;
	char ch1;
	char ch2;
	char ch3;
	int error;
} commonvar_t;

/**
 * struct paired_s - printf specifiers and paired function
 * @car: the specifier
 * @funct: pointer to the conversion specifier function
 */
typedef struct paired_s
{
	char car;
	void (*funct)(commonvar_t *comm);
} paired_t;

/* initializing and ending functions */
int _printf(const char *format, ...);
commonvar_t *creat_commonvar(va_list *args_list, const char *format);
int end_funct(commonvar_t *arg_comm);

/* custom memory allocation and buffer */
void *_calloc(unsigned int nmemb, unsigned int size);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void write_buffer(commonvar_t *comm);
void puts_buffer(commonvar_t *comm, char *str);

/* string functions */
void rev_string(char *s);
int _strlen(char *s);
int _strlenconst(const char *s);
int _putchar(char c);
void puts_mod(char *str, unsigned int l);

/* parse and pair functions */
void (*paired_specifier(commonvar_t *comm))(commonvar_t *comm);
void parse_specifiers(commonvar_t *comm);

/* hexadecimal */
void print_hexa(commonvar_t *comm, unsigned long int n, int hexcase, int size);
void p_longlowhexa(commonvar_t *comm);
void p_longuphexa(commonvar_t *comm);
void p_lowhexa(commonvar_t *comm);
void p_uphexa(commonvar_t *comm);

/* integers */
void print_integers(commonvar_t *comm, long int n);
void p_int(commonvar_t *comm);
void p_longint(commonvar_t *comm);
void print_unsign(commonvar_t *comm, unsigned long int n);
void p_uint(commonvar_t *comm);
void p_ulongint(commonvar_t *comm);

/* octals */
void print_oct(commonvar_t *comm, unsigned long int n, int size);
void p_oct(commonvar_t *comm);
void p_longoct(commonvar_t *comm);

/* handles specifier functions */
void p_char(commonvar_t *comm);
void p_string(commonvar_t *comm);
void p_string_hexa(commonvar_t *comm);
void p_pointer(commonvar_t *comm);
void p_rev_string(commonvar_t *comm);
void p_rot13(commonvar_t *comm);
void p_percent(commonvar_t *comm);
void p_binary(commonvar_t *comm);

#endif /* MAIN_H */
