#include "main.h"

/**
 * gettingSize - Calculates the size to cast the argument
 * @formed_string: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 *
 * Return: percentage.
 */
int gettingSize(const char *formed_string, int *i)
{
	int currentI = *i + 1;
	int size = 0;

	if (formed_string[currentI] == 'l')
		size = S_LONG;
	else if (formed_string[currentI] == 'h')
		size = S_SHORT;

	if (size == 0)
		*i = currentI - 1;
	else
		*i = currentI;

	return (size);
}
