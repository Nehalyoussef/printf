#include "main.h"

void printing_buff(char buff[], int *buff1);

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
	int i, print = 0, print_charecters = 0;
	int flag, width, percentage, size, buff1 = 0;
	va_list list;
	char buff[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buff[buff1++] = format[i];
			if (buff1 == BUFF_SIZE)
				printing_buff(buff, &buff1);
			/* write(1, &format[i], 1);*/
			print_charecters++;
		}
		else
		{
			printing_buff(buff, &buff1);
			flag = get_flags(format, &i);
			width = get_width(format, &i, list);
			percentage = get_precision(format, &i, list);
			size = get_size(format, &i);
			++i;
			print = handle_print(format, &i, list, buff,
				flag, width, precision, size);
			if (print == -1)
				return (-1);
			print_charecters += print;
		}
	}

	printing_buff(buff, &buff1);

	va_end(list);

	return (print_charecters);
}

/**
 * printing_buff - Prints the contents of the buff if it exist
 * @buff: Array of chars
 * @buff1: Index at which to add next char, represents the length.
 */
void printing_buff(char buff[], int *buff1)
{
	if (*buff1 > 0)
		write(1, &buff[0], *buff1);

	*buff1 = 0;
}
