#include "main.h"
#include <stdlib.h>
#include <stdio.h>
#define ERR_MSG "Error"
/**
 * digit - checks if a string contains a non-digit char
 * @s: string to be evaluated
 * Return: 0 if a non-digit is found, 1 otherwise
 */
int digit(char *s)
{
	int x = 0;

	while (s[x])
	{
		if (s[x] < '0' || s[x] > '9')
			return (0);
		x++;
	}
	return (1);
}
/**
 * _strlen - returns the length of a string
 * @s: string to evaluate
 * Return: the length of the string
 */
int _strlen(char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}
/**
 * errors - handles errors for main
 */
void errors(void)
{
	printf("Error\n");
	exit(98);
}
/**
 * main - multiplies two positive numbers
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: always 0 (Success)
 */
int main(int argc, char *argv[])
{
	char *s1, *s2;
	int ll1, ll2, ll, i, carry, dd1, dd2, *reslt, j = 0;

	s1 = argv[1], s2 = argv[2];
	if (argc != 3 || !digit(s1) || !digit(s2))
		errors();
	ll1 = _strlen(s1);
	ll2 = _strlen(s2);
	ll = ll1 + ll2 + 1;
	reslt = malloc(sizeof(int) * ll);
	if (!reslt)
		return (1);
	for (i = 0; i <= ll1 + ll2; i++)
		reslt[i] = 0;
	for (ll1 = ll1 - 1; ll1 >= 0; ll1--)
	{
		dd1 = s1[ll1] - '0';
		carry = 0;
		for (ll2 = _strlen(s2) - 1; ll2 >= 0; ll2--)
		{
			dd2 = s2[ll2] - '0';
			carry += reslt[ll1 + ll2 + 1] + (dd1 * dd2);
			reslt[ll1 + ll2 + 1] = carry % 10;
			carry /= 10;
		}
		if (carry > 0)
			reslt[ll1 + ll2 + 1] += carry;
	}
	for (i = 0; i < ll - 1; i++)
	{
		if (reslt[i])
			j = 1;
		if (j)
			_putchar(reslt[i] + '0');
	}
	if (!j)
		_putchar('0');
	_putchar('\n');
	free(reslt);
	return (0);
}
