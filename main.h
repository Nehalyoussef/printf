#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/** flag */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/** size */
#define S_LONG 2
#define S_SHORT 1

/**
 * struct format - Struct op
 *
 * @formAt: The format.
 * @fun: The function associated.
 */
struct formAt
{
	char formAt;
	int (*fun)(va_list, char[], int, int, int, int);
};


/**
 * typedef struct formt fun_t - Struct op
 *
 * @formt: The format.
 * @fun_t: The function associated.
 */
typedef struct formt fun_t;

int _printf(const char *format, ...);
int printingHandles(const char *formt, int *i,
va_list list, char buff[], int active_flags, int width, int percentage, int size);

/** functions ******************/

/** Funtions to print chars and strings */
int printing_charecters(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int printing_strings(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/** Functions to print numbers */
int print_int(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int printUnsignedNumbers(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int printOctalNumbers(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int printHexadecimalNumbers(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int upperHexadecimalNumbers(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int upperOrLowerHexaNumbers(va_list types, char map_to[],
char buffer[], int flags, char flag_ch, int width, int precision, int size);

/** Function to print non printable characters */
int printUnPrintable(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/** Funcion to print memory address */
int printPointers(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/** Funciotns to handle other specifiers */
int getInFlags(const char *format, int *i);
int gettingWidth(const char *format, int *i, va_list list);
int getPercentage(const char *format, int *i, va_list list);
int gettingSize(const char *format, int *i);

/**Function to print string in reverse*/
int printInReverse(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/**Function to print a string in rot 13*/
int printRotationStr(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/** width handler */
int writeCharHandeling(char c, char buffer[],
	int flags, int width, int precision, int size);
int writingNum(int is_positive, int ind, char buffer[],
	int flags, int width, int precision, int size);
int writeNumBuff(int ind, char bff[], int flags, int width, int precision,
	int length, char padd, char extra_c);
int writeAdrPtr(char buffer[], int ind, int length,
	int width, int flags, char padd, char extra_c, int padd_start);

int writeUnsignedNum(int is_negative, int ind,
char buffer[],
	int flags, int width, int precision, int size);

/** utils ******************/
int canBPrinted(char);
int enterHexaCodes(char, char[], int);
int itsDigit(char);

long int sizeToNumberConv(long int num, int size);
long int sizeToUnsignedConc(unsigned long int num, int size);

#endif /* MAIN_H */
