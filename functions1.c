#include "main.h"

/**
 * PRINT UNSIGNED NUMBER 
 */
/**
 * printUnsignedNumbers - Prints an unsigned number
 * @type_list: List a of arguments
 * @buff: buff array to handle print
 * @active_flags:  Calculates active flags
 * @width: get width
 * @percentage: Precision specification
 * @size: Size
 * Return: Number of characters
 */
int printUnsignedNumbers(va_list type_list, char buff[],
	int active_flags, int width, int percentage, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(type_list, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buff[i--] = '0';

	buff[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buff[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_unsgnd(0, i, buff, active_flags, width, percentage, size));
}

/**
 * print unsigned in octal
 */
/**
 * printOctalNumbers - Prints an unsigned number in octal
 * @type_list: List of arguments
 * @buff: buff array to handle print
 * @active_flags:  Calculates active flags
 * @width: get width
 * @percentage: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int printOctalNumbers(va_list type_list, char buff[],
	int active_flags, int width, int percentage, int size)
{

	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(type_list, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buff[i--] = '0';

	buff[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buff[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (active_flags & F_HASH && init_num != 0)
		buff[i--] = '0';

	i++;

	return (write_unsgnd(0, i, buff, active_flags, width, percentage, size));
}

/**
 * print unsigned in hexadecimal 
 */
/**
 * printHexadecimalNumbers - Prints an unsigned number in hexadecimal notation
 * @type_list: List of arguments
 * @buff: buff array to handle print
 * @active_flags:  Calculates active flags
 * @width: get width
 * @percentage: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int printHexadecimalNumbers(va_list type_list, char buff[],
	int active_flags, int width, int percentage, int size)
{
	return (upperOrLowerHexaNumbers(type_list, "0123456789abcdef", buff,
		active_flags, 'x', width, percentage, size));
}

/**
 * print unsigned in upper hexadecimal 
 */
/**
 * upperHexadecimalNumbers - Prints an unsigned number in upper hexadecimal notation
 * @type_list: Lista of arguments
 * @buff: buff array to handle print
 * @active_flags:  Calculates active flags
 * @width: get width
 * @percentage: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int upperHexadecimalNumbers(va_list type_list, char buff[],
	int active_flags, int width, int percentage, int size)
{
	return (upperOrLowerHexaNumbers(type_list, "0123456789ABCDEF", buff,
		active_flags, 'X', width, percentage, size));
}

/**
 * print hexadecimal in lower or uppercase
 */
/**
 * upperOrLowerHexaNumbers - Prints a hexadecimal number in lower or upper
 * @type_list: List of arguments
 * @map_num_to: Array of values to map the number to
 * @buff: buff array to handle print
 * @active_flags:  Calculates active flags
 * @flag_activision: Calculates active flags
 * @width: get width
 * @percentage: Precision specification
 * @size: Size
 * @size: Size
 * Return: Number of characters printed
 */
int upperOrLowerHexaNumbers(va_list type_list, char map_num_to[], char buff[],
	int active_flags, char flag_activision, int width, int percentage, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(type_list, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buff[i--] = '0';

	buff[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buff[i--] = map_num_to[num % 16];
		num /= 16;
	}

	if (active_flags & F_HASH && init_num != 0)
	{
		buff[i--] = flag_activision;
		buff[i--] = '0';
	}

	i++;

	return (write_unsgnd(0, i, buff, active_flags, width, percentage, size));
}