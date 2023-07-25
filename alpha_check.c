#include "main.h"

/**
 * alpha_check - checks if a integer is a character.
 * @ch: integer.
 * Return: returns -1 if successful and 0 if not.
*/
int alpha_check(int ch)
{
	if (((ch >= 65) && (ch <= 90)) || ((ch >= 97) && (ch <= 122)))
		return (-1);
	else
		return (0);
}
