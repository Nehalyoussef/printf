#include "main.h"
/**
 * printingHandles - Prints an argument based on its type
 * @formed_string: Formatted string in which to print the arguments.
 * @listArges: List of arguments to be printed.
 * @cnt: cnt.
 * @buff: buff array to handle print.
 * @flagActive: Calculates active flags
 * @width: get width.
 * @percentage: Precision specification
 * @size: Size
 * Return: 1 or 2;
 */
int printingHandles(const char *formed_string, int *cnt, va_list listArges, char buff[],
	int flagActive, int width, int percentage, int size)
{
	int i, invisibleLen = 0, final_chars = -1;
	fmt_t fmt_types[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'i', print_int}, {'d', print_int}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
		{'X', print_hexa_upper}, {'p', print_pointer}, {'S', print_non_printable},
		{'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
	};
	for (i = 0; fmt_types[i].formed_string != '\0'; i++)
		if (formed_string[*cnt] == fmt_types[i].formed_string)
			return (fmt_types[i].fn(listArges, buff, flagActive, width, percentage, size));

	if (fmt_types[i].formed_string == '\0')
	{
		if (formed_string[*cnt] == '\0')
			return (-1);
		invisibleLen += write(1, "%%", 1);
		if (formed_string[*cnt - 1] == ' ')
			invisibleLen += write(1, " ", 1);
		else if (width)
		{
			--(*cnt);
			while (formed_string[*cnt] != ' ' && formed_string[*cnt] != '%')
				--(*cnt);
			if (formed_string[*cnt] == ' ')
				--(*cnt);
			return (1);
		}
		invisibleLen += write(1, &formed_string[*cnt], 1);
		return (invisibleLen);
	}
	return (final_chars);
}