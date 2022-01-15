#include <stdio.h>
#include <math.h>
#include <string.h>

int	ft_convert_hex(char *hex)
{
	int i;
	int value;
	int length;
	long long decimal;
	long long base;

	decimal = 0;
	base = 1;
	i = 0;

	length = strlen(hex);
	i = length - 1;
	while (i >= 0)
	{
		if (hex[i] >= '0' && hex[i] <= '9')
		{
			decimal += (hex[i] - 48) * base;
			base *= 16;
		}
		else if (hex[i] >= 'A' && hex[i] <= 'F')
		{
			decimal += (hex[i] - 55) * base;
			base *= 16;
		}
		else if (hex[i] >= 'a' && hex[i] <= 'f')
		{
			decimal += (hex[i] - 55) * base;
			base *= 16;
		}
		i--;
	}
	return (decimal);
}