#include "main.h"

/**
 * getPercentage - Calculates the precision for printing
 * @formed_string: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 * @listArges: list of arguments.
 *
 * Return: percentage.
 */
int getPercentage(const char *formed_string, int *i, va_list listArges)
{
	int currentI = *i + 1;
	int percentage = -1;

	if (formed_string[currentI] != '.')
		return (percentage);

	percentage = 0;

	for (currentI += 1; formed_string[currentI] != '\0'; currentI++)
	{
		if (is_digit(formed_string[currentI]))
		{
			percentage *= 10;
			percentage += formed_string[currentI] - '0';
		}
		else if (formed_string[currentI] == '*')
		{
			currentI++;
			percentage = va_arg(listArges, int);
			break;
		}
		else
			break;
	}

	*i = currentI - 1;

	return (percentage);
}
