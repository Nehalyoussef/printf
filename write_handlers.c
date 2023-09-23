#include "main.h"

/**
 * write handle
 */
/**
 * writeCharHandeling - Prints a string
 * @c: char types.
 * @buff: buff array to handle print
 * @active_flags:  Calculates active flags.
 * @width: get width.
 * @percentage: precision specifier
 * @size: Size specifier
 *
 * Return: Number of chars printed.
 */
int writeCharHandeling(char c, char buff[],
	int active_flags, int width, int percentage, int size)
	int i = 0;
	char padding = ' ';

	UNUSED(percentage);
	UNUSED(size);

	if (active_flags & F_ZERO)
		padding = '0';

	buff[i++] = c;
	buff[i] = '\0';

	if (width > 1)
	{
		buff[BUFF_SIZE - 1] = '\0';
		for (i = 0; i < width - 1; i++)
			buff[BUFF_SIZE - i - 2] = padding;

		if (active_flags & F_MINUS)
			return (write(1, &buff[0], 1) +
					write(1, &buff[BUFF_SIZE - i - 1], width - 1));
		else
			return (write(1, &buff[BUFF_SIZE - i - 1], width - 1) +
					write(1, &buff[0], 1));
	}

	return (write(1, &buff[0], 1));
}

/************************* WRITE NUMBER *************************/
/**
 * writingNum - Prints a string
 * @is_nega: List of arguments
 * @indicate: char types.
 * @buff: buff array to handle print
 * @active_flags:  Calculates active flags
 * @width: get width.
 * @percentage: precision specifier
 * @size: Size specifier
 *
 * Return: Number of chars printed.
 */
int writingNum(int is_nega, int indicate, char buff[],
	int active_flags, int width, int percentage, int size)
{
	int length = BUFF_SIZE - indicate - 1;
	char padding = ' ', extra_ch = 0;

	UNUSED(size);

	if ((active_flags & F_ZERO) && !(active_flags & F_MINUS))
		padding = '0';
	if (is_nega)
		extra_ch = '-';
	else if (active_flags & F_PLUS)
		extra_ch = '+';
	else if (active_flags & F_SPACE)
		extra_ch = ' ';

	return (writeNumBuff(indicate, buff, active_flags, width, percentage,
		length, padding, extra_ch));
}

/**
 * writeNumBuff - Write a number using a bufffer
 * @indicate: indicateex at which the number starts on the buff
 * @buff: buff
 * @active_flags: active_flags
 * @width: width
 * @percentage: Precision specifier
 * @length: Number length
 * @padding: Pading char
 * @another_char: Extra char
 *
 * Return: Number of printed chars.
 */
int writeNumBuff(int indicate, char buff[],
	int active_flags, int width, int percentage,
	int length, char padding, char another_char)
{
	int i, paddingStart = 1;

	if (percentage == 0 && indicate == BUFF_SIZE - 2 && buff[indicate] == '0' && width == 0)
		return (0); /* printf(".0d", 0)  no char is printed */
	if (percentage == 0 && indicate == BUFF_SIZE - 2 && buff[indicate] == '0')
		buff[indicate] = padding = ' '; /* width is displayed with padding ' ' */
	if (percentage > 0 && percentage < length)
		padding = ' ';
	while (percentage > length)
		buff[--indicate] = '0', length++;
	if (another_char != 0)
		length++;
	if (width > length)
	{
		for (i = 1; i < width - length + 1; i++)
			buff[i] = padding;
		buff[i] = '\0';
		if (active_flags & F_MINUS && padding == ' ')/* Asign extra char to left of buff */
		{
			if (another_char)
				buff[--indicate] = another_char;
			return (write(1, &buff[indicate], length) + write(1, &buff[1], i - 1));
		}
		else if (!(active_flags & F_MINUS) && padding == ' ')/* extra char to left of buff */
		{
			if (another_char)
				buff[--indicate] = another_char;
			return (write(1, &buff[1], i - 1) + write(1, &buff[indicate], length));
		}
		else if (!(active_flags & F_MINUS) && padding == '0')/* extra char to left of padd */
		{
			if (another_char)
				buff[--paddingStart] = another_char;
			return (write(1, &buff[paddingStart], i - paddingStart) +
				write(1, &buff[indicate], length - (1 - paddingStart)));
		}
	}
	if (another_char)
		buff[--indicate] = another_char;
	return (write(1, &buff[indicate], length));
}

/**
 * writeUnsignedNum - Writes an unsigned number
 * @is_nega: Number indicating if the num is negative
 * @indicate: Index at which the number starts in the buff
 * @buff: Array of chars
 * @active_flags: active_flags specifiers
 * @width: Width specifier
 * @percentage: Precision specifier
 * @size: Size specifier
 *
 * Return: Number of written chars.
 */
int writeUnsignedNum(int is_nega, int indicate,
	char buff[],
	int active_flags, int width, int percentage, int size)
{
	/* The number is stored at the bufer's right and starts at position i */
	int length = BUFF_SIZE - indicate - 1, i = 0;
	char padding = ' ';

	UNUSED(is_nega);
	UNUSED(size);

	if (percentage == 0 && indicate == BUFF_SIZE - 2 && buff[indicate] == '0')
		return (0); /* printf(".0d", 0)  no char is printed */

	if (percentage > 0 && percentage < length)
		padding = ' ';

	while (percentage > length)
	{
		buff[--indicate] = '0';
		length++;
	}

	if ((active_flags & F_ZERO) && !(active_flags & F_MINUS))
		padding = '0';

	if (width > length)
	{
		for (i = 0; i < width - length; i++)
			buff[i] = padding;

		buff[i] = '\0';

		if (active_flags & F_MINUS) /* Asign extra char to left of buff [buff>padd]*/
		{
			return (write(1, &buff[indicate], length) + write(1, &buff[0], i));
		}
		else /* Asign extra char to left of padding [padd>buff]*/
		{
			return (write(1, &buff[0], i) + write(1, &buff[indicate], length));
		}
	}

	return (write(1, &buff[indicate], length));
}

/**
 * writeAdrPtr - Write a memory address
 * @buff: Arrays of chars
 * @indicate: Index at which the number starts in the buff
 * @length: Length of number
 * @width: Width specifier
 * @active_flags: active_flags specifier
 * @padding: Char representing the padding
 * @another_char: Char representing extra char
 * @paddingStart: Index at which padding should start
 *
 * Return: Number of written chars.
 */
int writeAdrPtr(char buff[], int indicate, int length,
	int width, int active_flags, char padding, char another_char, int paddingStart)
{
	int i;

	if (width > length)
	{
		for (i = 3; i < width - length + 3; i++)
			buff[i] = padding;
		buff[i] = '\0';
		if (active_flags & F_MINUS && padding == ' ')/* Asign extra char to left of buff */
		{
			buff[--indicate] = 'x';
			buff[--indicate] = '0';
			if (another_char)
				buff[--indicate] = another_char;
			return (write(1, &buff[indicate], length) + write(1, &buff[3], i - 3));
		}
		else if (!(active_flags & F_MINUS) && padding == ' ')/* extra char to left of buff */
		{
			buff[--indicate] = 'x';
			buff[--indicate] = '0';
			if (another_char)
				buff[--indicate] = another_char;
			return (write(1, &buff[3], i - 3) + write(1, &buff[indicate], length));
		}
		else if (!(active_flags & F_MINUS) && padding == '0')/* extra char to left of padding */
		{
			if (another_char)
				buff[--paddingStart] = another_char;
			buff[1] = '0';
			buff[2] = 'x';
			return (write(1, &buff[paddingStart], i - paddingStart) +
				write(1, &buff[indicate], length - (1 - paddingStart) - 2));
		}
	}
	buff[--indicate] = 'x';
	buff[--indicate] = '0';
	if (another_char)
		buff[--indicate] = another_char;
	return (write(1, &buff[indicate], BUFF_SIZE - indicate - 1));
}