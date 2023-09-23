#include "main.h"

/**
 * printing charecters 
 */

/**
 * printing_charecters - Prints a char
 * @type_list: List a of arguments
 * @buff: buff array to handle print
 * @active_flags:  Calculates active flags
 * @width: Width
 * @percentage: Precision specification
 * @size: Size
 * Return: Number of charecters
 */
int printing_charecters(va_list type_list, char buff[],
	int active_flags, int width, int percentage, int size)
{
	char c = va_arg(type_list, int);

	return (handle_write_char(c, buff, active_flags, width, percentage, size));
}

/**
 * printing a string
 */
/**
 * printing_strings - Prints a string
 * @type_list: List a of arguments
 * @buff: buff array to handle print
 * @active_flags:  Calculates active flags
 * @width: get width.
 * @percentage: Precision specification
 * @size: Size
 * Return: Number of charecters
 */
int printing_strings(va_list type_list, char buff[],
	int active_flags, int width, int percentage, int size)
{
	int length = 0, i;
	char *str = va_arg(type_list, char *);

	UNUSED(buff);
	UNUSED(active_flags);
	UNUSED(width);
	UNUSED(percentage);
	UNUSED(size);
	if (str == NULL)
	{
		str = "(null)";
		if (percentage >= 6)
			str = "      ";
	}

	while (str[length] != '\0')
		length++;

	if (percentage >= 0 && percentage < length)
		length = percentage;

	if (width > length)
	{
		if (active_flags & F_MINUS)
		{
			write(1, &str[0], length);
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (width);
		}
	}

	return (write(1, str, length));
}
/**
 *PRINT PERCENT SIGN 
 */
/**
 * print_percent - Prints a percent sign
 * @type_list: Lista of arguments
 * @buff: buff array to handle print
 * @active_flags:  Calculates active flags
 * @width: get width.
 * @percentage: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_percent(va_list type_list, char buff[],
	int active_flags, int width, int percentage, int size)
{
	UNUSED(type_list);
	UNUSED(buff);
	UNUSED(active_flags);
	UNUSED(width);
	UNUSED(percentage);
	UNUSED(size);
	return (write(1, "%%", 1));
}

/**
 * printing integers 
 */
/**
 * print_int - Print int
 * @type_list: Lista of arguments
 * @buff: buff array to handle print
 * @active_flag:  Calculates active flags
 * @width: get width.
 * @percentage: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_int(va_list type_list, char buff[],
	int active_flags, int width, int percentage, int size)
{
	int i = BUFF_SIZE - 2;
	int is_negative = 0;
	long int n = va_arg(type_list, long int);
	unsigned long int num;

	n = convert_size_number(n, size);

	if (n == 0)
		buff[i--] = '0';

	buff[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_negative = 1;
	}

	while (num > 0)
	{
		buff[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_number(is_negative, i, buff, active_flags, width, percentage, size));
}

/**
 * printing binaries 
 */
/**
 * print_binary - Prints an unsigned number
 * @type_list: Lista of arguments
 * @buff: buff array to handle print
 * @active_flags:  Calculates active flags
 * @width: get width.
 * @percentage: Precision specification
 * @size: Size specifier
 * Return: Numbers of char printed.
 */
int print_binary(va_list type_list, char buff[],
	int active_flags, int width, int percentage, int size)
{
	unsigned int n, m, i, sum;
	unsigned int a[32];
	int count;

	UNUSED(buff);
	UNUSED(active_flags);
	UNUSED(width);
	UNUSED(percentage);
	UNUSED(size);

	n = va_arg(type_list, unsigned int);
	m = 2147483648; /* (2 ^ 31) */
	a[0] = n / m;
	for (i = 1; i < 32; i++)
	{
		m /= 2;
		a[i] = (n / m) % 2;
	}
	for (i = 0, sum = 0, count = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			char z = '0' + a[i];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}