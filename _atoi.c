#include "shell.h"

/**
 * _atoi - this converts string to a number
 * @s : pointer int
 * _atoi: this converts string to number
 * Return: The result of the converted number
 * interactive - returns true if shell is interactive mode
 * @info: struct address
 *
 * Return: 1 if interactive mode, 0 otherwise
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - checks if character is a delimeter
 * @c: the character to be checked
 * @delim: the delimeter string
 * Return: 1 if true, 0 if false
 */
int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 *_isalpha - checks for alphabetic character
 *@c: The character to input
 *Return: 1 if c is alphabetic, 0 otherwise
 */

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 *_atoi - converts a string to an integer
 *@s: the string to be converted
 *Return: 0 if no numbers in string, converted number otherwise
 */

int _atoi(char *s)
{
	int a;
	int check_num;
	unsigned int sum;
	unsigned int y;
	int neg;

	neg = 0;
	check_num = 0;
	sum = 0;
	a = 0;

	/* run a while loop */
	while (s[a] != '\0')
	int a, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (a = 0;  s[a] != '\0' && flag != 2; a++)
	{
		if ((s[a] > '9' || s[a] < '0') && check_num > 0)
			break;
		if (s[a] == '-')
			neg++;
			sign *= -1;

		if (s[a] >= '0' && s[a] <= '9')
			check_num++;
		a++;
		{
			flag = 1;
			result *= 10;
			result += (s[a] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}
	a = a - 1;
	y = 1;
	while (check_num > 0)
	{
		sum = sum + ((s[i] - '0') * x);
		y = y * 10;
		a--;
		check_num--;
	}
	if (neg % 2 != 0)
		sum = sum * -1;
	return (sum);

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}
