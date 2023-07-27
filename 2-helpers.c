#include "main.h"
/**
 * length_of_int - finds the length of an integer.
 * @number: integer.
 * Return: the length of the integer.
*/

int length_of_int(int number)
{
	int length;

	for (length = 0; number != 0; length++)
	{
		number = number / 10;
	}
	return (length);
}

/**
 * reverse_call - reverses an array.
 * @array: is the array to be reversed.
 * @length: length of the array.
 * Return: void.
*/

void reverse_call(char *array, int length)
{
	int a = 0, len;
	char temp;

	len = length - 1;
	while (a < (length / 2))
	{
		temp = array[a];
		array[a] = array[len - a];
		array[len - a] = temp;
		a++;
	}
}

/**
 * print_positive - prints a positive integer.
 * @num: negative number.
 * Return: void.
*/

void print_positive(unsigned int num)
{
	unsigned int holder;

	holder = num;
	if ((holder / 10) > 0)
		print_positive(holder / 10);

	_putchar(holder % 10 + '0');
}

/**
 * print_negative - prints a negative integer.
 * @num: integer
 * Return: void
*/

void print_negative(int num)
{
	unsigned int holder;

	holder = num;
	if (num < 0)
	{
		_putchar('-');
		holder = -holder;
	}
	if ((holder / 10) > 0)
		print_positive(holder / 10);

	_putchar(holder % 10 + '0');
}

/**
 * _atoi - converts a character to an integer.
 * @str: is a pointer to an array of characters.
 * Return: converted integer.
*/
int _atoi(char *str)
{
	int index = 0;
	int num = 0;
	int sign = 1;
	bool digit = false;

	while (str[index] == ' ' || str[index] == '\t')
		index++;

	if (str[index] == '-')
	{
		sign = -1;
		index++;
	}
	else if (str[index] == '+')
		index++;

	while (str[index] >= '0' && str[index] <= '9')
	{
		digit = true;
		if (num > INT_MAX / 10 || (num == INT_MAX / 10 &&
(str[index] - '0') > INT_MAX % 10))
			return (sign == 1 ? INT_MAX : INT_MIN);

		num = num * 10 + (str[index] - '0');
		index++;
	}
	if (!digit)
		return (0);
	return (num * sign);
}
