#include "main.h"

/**
 * canBPrinted - Evaluates if a char is printable
 * @ch: Char to be evaluated.
 *
 * Return: 1 if c is printable, 0 otherwise
 */
int canBPrinted(char ch)
{
	if (ch >= 32 && ch < 127)
		return (1);

	return (0);
}

/**
 * enterHexaCodes - Append ascci in hexadecimal code to buff
 * @buff: Array of chars.
 * @i: Index at which to start appending.
 * @code_asc: ASSCI CODE.
 * Return: Always 3
 */
int enterHexaCodes(char code_asc, char buff[], int i)
{
	char map_to[] = "0123456789ABCDEF";
	if (code_asc < 0)
		code_asc *= -1;

	buff[i++] = '\\';
	buff[i++] = 'x';

	buff[i++] = map_to[code_asc / 16];
	buff[i] = map_to[code_asc % 16];

	return (3);
}

/**
 * itsDigit - Verifies if a char is a digit
 * @c: Char to be evaluated
 *
 * Return: 1 if c is a digit, 0 otherwise
 */
int itsDigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * sizeToNumberConv - Casts a number to the specified size
 * @numero: Number to be casted.
 * @size: Number indicating the type to be casted.
 *
 * Return: Casted value of numero
 */
long int sizeToNumberConv(long int numero, int size)
{
	if (size == S_LONG)
		return (numero);
	else if (size == S_SHORT)
		return ((short)numero);

	return ((int)numero);
}

/**
 * sizeToUnsignedConc - Casts a number to the specified size
 * @numero: Number to be casted
 * @size: Number indicating the type to be casted
 *
 * Return: Casted value of numero
 */
long int sizeToUnsignedConc(unsigned long int numero, int size)
{
	if (size == S_LONG)
		return (numero);
	else if (size == S_SHORT)
		return ((unsigned short)numero);

	return ((unsigned int)numero);
}