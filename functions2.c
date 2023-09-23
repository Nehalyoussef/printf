#include "main.h"

/**
 * print pointer
 */
/**
 * printPointers - Prints the value of a pointer variable
 * @type_list: List a of arguments
 * @buff: buff array to handle print
 * @active_flags:  Calculates active flags
 * @width: get width
 * @percentage: Precision specification
 * @size: Size
 * Return: Number of characters printed.
 */
int printPointers(va_list type_list, char buff[],
	int active_flags, int width, int percentage, int size)
{
	char extra_c = 0, padd = ' ';
	int ind = BUFF_SIZE - 2, length = 2, padd_start = 1; /** length=2, for '0x' */
	unsigned long num_addrs;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(type_list, void *);

	UNUSED(width);
	UNUSED(size);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));

	buff[BUFF_SIZE - 1] = '\0';
	UNUSED(percentage);

	num_addrs = (unsigned long)addrs;

	while (num_addrs > 0)
	{
		buff[ind--] = map_to[num_addrs % 16];
		num_addrs /= 16;
		length++;
	}

	if ((active_flags & F_ZERO) && !(active_flags & F_MINUS))
		padd = '0';
	if (active_flags & F_PLUS)
		extra_c = '+', length++;
	else if (active_flags & F_SPACE)
		extra_c = ' ', length++;

	ind++;

	/**return (write(1, &buff[i], BUFF_SIZE - i - 1));*/
	return (write_pointer(buff, ind, length,
		width, active_flags, padd, extra_c, padd_start));
}

/**
 * print unprintable
 */
/**
 * printUnPrintable - Prints ascii codes in hexa of non printable chars
 * @type_list: Lista of arguments
 * @buff: buff array to handle print
 * @active_flags:  Calculates active flags
 * @width: get width
 * @percentage: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int printUnPrintable(va_list type_list, char buff[],
	int active_flags, int width, int percentage, int size)
{
	int i = 0, offset = 0;
	char *str = va_arg(type_list, char *);

	UNUSED(active_flags);
	UNUSED(width);
	UNUSED(percentage);
	UNUSED(size);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[i] != '\0')
	{
		if (is_printable(str[i]))
			buff[i + offset] = str[i];
		else
			offset += append_hexa_code(str[i], buff, i + offset);

		i++;
	}

	buff[i + offset] = '\0';

	return (write(1, buff, i + offset));
}

/**
 * print in reverse
*/
/**
 * printInReverse - Prints reverse string.
 * @type_list: Lista of arguments
 * @buff: buff array to handle print
 * @active_flags:  Calculates active flags
 * @width: get width
 * @percentage: Precision specification
 * @size: Size specifier
 * Return: Numbers of chars printed
 */

int printInReverse(va_list type_list, char buff[],
	int active_flags, int width, int percentage, int size)
{
	char *str;
	int i, count = 0;

	UNUSED(buff);
	UNUSED(active_flags);
	UNUSED(width);
	UNUSED(size);

	str = va_arg(type_list, char *);

	if (str == NULL)
	{
		UNUSED(percentage);

		str = ")Null(";
	}
	for (i = 0; str[i]; i++)
		;

	for (i = i - 1; i >= 0; i--)
	{
		char z = str[i];

		write(1, &z, 1);
		count++;
	}
	return (count);
}
/**
 * print a string in rotation
 */
/**
 * printRotationStr - Print a string in rot13.
 * @type_list: Lista of arguments
 * @buff: buff array to handle print
 * @active_flags:  Calculates active flags
 * @width: get width
 * @percentage: Precision specification
 * @size: Size specifier
 * Return: Numbers of chars printed
 */
int printRotationStr(va_list type_list, char buff[],
	int active_flags, int width, int percentage, int size)
{
	char x;
	char *str;
	unsigned int i, j;
	int count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(type_list, char *);
	UNUSED(buff);
	UNUSED(active_flags);
	UNUSED(width);
	UNUSED(percentage);
	UNUSED(size);

	if (str == NULL)
		str = "(AHYY)";
	for (i = 0; str[i]; i++)
	{
		for (j = 0; in[j]; j++)
		{
			if (in[j] == str[i])
			{
				x = out[j];
				write(1, &x, 1);
				count++;
				break;
			}
		}
		if (!in[j])
		{
			x = str[i];
			write(1, &x, 1);
			count++;
		}
	}
	return (count);
}