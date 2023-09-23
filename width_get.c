#include "main.h"

/**
 * gettingWidth - determines the printing width
 * @formed_string:formatted string into which the arguments should be printed.
 * @i: List of arguments to be printed.
 * @listArges: list of arguments.
 *
 * Return: width.
 */
int gettingWidth(const char *formed_string, int *i, va_list listArges)
{
	int currentI;
	int width = 0;

	for (currentI = *i + 1; formed_string[currentI] != '\0'; currentI++)
	{
		if (is_digit(formed_string[currentI]))
		{
			width *= 10;
			width += formed_string[currentI] - '0';
		}
		else if (formed_string[currentI] == '*')
		{
			currentI++;
			width = va_arg(listArges, int);
			break;
		}
		else
			break;
	}

	*i = currentI - 1;

	return (width);
}
