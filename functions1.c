#include "main.h"

/*printUnsignedNumber*/
/**
 * print_unsigned - Function to print an unsigned number
 * @types: This is a list of arguments
 * @buffer: Buffer array to handle print
 * @flags: This calculates active flags
 * @width: This gets the width
 * @precision: Precision specifier
 * @size: Size specifier
 * Return: The number of characters printed
 */
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/*printUnsignedNumberInOctal*/
/**
 * print_octal - Function to print an unsigned number in base 8
 * @types: This is a list of arguments
 * @buffer: Buffer array to handle print
 * @flags: This calculates the active flags
 * @width: This gets the width
 * @precision: Specifies the Precision
 * @size: Size specifier
 * Return: Number of characters printed
 */
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{

	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[i--] = '0';

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/*printUnsignedNumberInHexadecimal*/
/**
 * print_hexadecimal - Function to print an unsigned number in base 10
 * @types: This is a list of arguments
 * @buffer: Buffer array to handle print
 * @flags: This calculates the active flags
 * @width: This gets the width
 * @precision: Specifies precision
 * @size: Specifies the size
 * Return: Number of characters printed
 */
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/*printUnsignedNumberInUpperHexadecimal*/
/**
 * print_hexa_upper - Prints an unsigned number in upper hexadecimal notation
 * @types: A list of arguments
 * @buffer: A Buffer array to handle print
 * @flags:  This calculates active flags
 * @width: This gets the width
 * @precision: Precision specification
 * @size: Specifies the size
 * Return: Number of chars printed
 */
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/*printHexxNumInLowerOrUpper*/
/**
 * print_hexa - Function that prints a hexadecimal number either in lower or upper
 * @types: A List of arguments
 * @map_to: An array of values to map the number to
 * @buffer: A buffer array to handle print
 * @flags: This calculates active flags
 * @flag_ch: This calculates active flags
 * @width: Gets the width
 * @precision: Precision specification
 * @size: This specifies the size
 * Return: The number of characters printed
 */
int print_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
