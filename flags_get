#include "main.h"

/**
 * getInFlags - determines the active flags
 * @formed_string: formatted string into which the arguments will be printed
 * @i: take a parameter.
 * Return: Flags:
 */
int getInFlags(const char *formed_string, int *i)
{
	int j, another_i;
	int active_flags = 0;
	const char flag_char[] = {'-', '+', '0', '#', ' ', '\0'};
	const int flag_op[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (another_i = *i + 1; formed_string[another_i] != '\0'; another_i++)
	{
		for (j = 0; flag_char[j] != '\0'; j++)
			if (formed_string[another_i] == flag_char[j])
			{
				active_flags |= flag_op[j];
				break;
			}

		if (flag_char[j] == 0)
			break;
	}

	*i = another_i - 1;

	return (active_flags);
}
