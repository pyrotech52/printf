#include "main.h"

/**
 * get_flags - checks for active flags
 * @format: Formatted string
 * @x: parameter
 * Return: flags
 */
int get_flags(const char *format, int *x)
{
	int i, j;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {NEGATIVE, POSITIVE, ZERO, HASH, SPACE, 0};

	for (j = *x + 1; format[j] != '\0'; j++)
	{
		for (i = 0; FLAGS_CH[i] != '\0'; i++)
			if (format[j] == FLAGS_CH[i])
			{
				flags |= FLAGS_ARR[i];
				break;
			}

		if (FLAGS_CH[i] == 0)
			break;
	}

	*x = j - 1;

	return (flags);
}
