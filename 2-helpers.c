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
	int index1, index2, neg, num;

	index1 = 0;
	num = 0;
	neg = 0;

	while ((str[index1] < '0' || str[index1] > '9') && str[index1] != '\0')
	{
		if (str[index1] == '-')
		neg = neg * (-1);
		index1++;
	}
	index2 = index1;
	while ((str[index2] >= '0') && (str[index2] <= '9'))
	{
		num = (num * 10) + neg * ((str[index2] - '0'));
		index2++;
	}
	return (num);
}