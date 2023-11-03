#include "command.h"

/**
 * integerParser - Format an integer and update the buffer.
 * @buffer: The destination buffer for the formatted string.
 * @value: The integer value to format.
 *
 * Return: The number of characters written to the buffer.
 */
static int integerParser(char *buffer, int value)
{
	int written = 0;
	int divisor = 1;

	if (value < 0)
	{
		buffer[written] = '-';
		written++;
		value = -value;
	}

	while (value / divisor > 9)
		divisor *= 10;

	while (divisor > 0)
	{
		buffer[written] = '0' + (value / divisor);
		value %= divisor;
		divisor /= 10;
		written++;
	}

	return (written);
}

/**
 * inputParser - Format a string based on format and arguments.
 * @buffer: The destination buffer for the formatted string.
 * @formatSpecifier: The format string containing format specifiers.
 * @args: A va_list of arguments for the format specifiers.
 *
 * Return: The number of characters written to the buffer.
 */
static int inputParser(char *buffer, const char *formatSpecifier, va_list args)
{
	int written = 0;

	while (*formatSpecifier)
		{
		if (*formatSpecifier == '%' && formatSpecifier[1] == 'd')
		{
			int value = va_arg(args, int);

			written += integerParser(buffer + written, value);
			formatSpecifier += 2;
		}
		else if (*formatSpecifier == '%' && formatSpecifier[1] == 's')
		{
			const char *value = va_arg(args, const char *);

			while (*value)
			{
				buffer[written] = *value;
				value++;
				written++;
			}
			formatSpecifier += 2;
		}
		else
		{
			buffer[written] = *formatSpecifier;
			formatSpecifier++;
			written++;
		}
	}

	return (written);
}

/**
 * udemPrint - Write a formatted string to stdout.
 * @format: The format string containing format specifiers.
 * @...: The arguments for the format specifiers.
 *
 * Return: The number of characters written to stdout.
 */
int udemPrint(const char *format, ...)
{
	va_list args;
	char buffer[MAX_INPUT_SIZE];
	int writtenInput;

	va_start(args, format);
	writtenInput = inputParser(buffer, format, args);
	va_end(args);

	write(STDOUT_FILENO, buffer, writtenInput);

	return (writtenInput);
}
int fchymezyPrint(const char *format, ...)
{
	va_list args;
	char buffer [MAX_INPUT_SIZE];
	int writtenInput;

	va_start(args, format);
	writtenInput = inputParser(buffer, format, args);
	va_end(args);

	write(STDERR_FILENO, buffer, writtenInput);

	return (writtenInput);
}

