#include <stdlib.h>
#include <stdio.h>

#include "palindrome.h"

/**
 * is_palindrome - function that checks integer is a palindrome.
 * @n: number to be checked
 * Return: 1 if n is a palindrome, 0 otherwise
 */

int is_palindrome(unsigned long n)
{
	unsigned long reversed = 0;
	unsigned long original = n;

	while (n > 0)
	{
		reversed = reversed * 10 + (n % 10);
		n /= 10;
	}

	if (reversed == original)
	{
		return (1);
	}

	else
	{
		return (0);
	}
}
