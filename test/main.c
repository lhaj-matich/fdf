#include <stdio.h>

int     ft_get_width(char *str, char sep)
{
        int i;
        int words_count;

        i = 0;
        words_count = 0;
        if (str[i] != sep)
        {
                words_count += 1;
                i += 1;
        }
        while (str[i] != '\0')
        {
                if (str[i] != sep && str[i - 1] == sep)
                        words_count++;
                i++;
        }
        return (words_count);
}

int main(void)
{
    char *str = "0  0 10 10 10 10 10 10  0  0  0  0 10 10 10 10  0  0  ";
    printf("%d\n", ft_get_width(str, ' '));
    return (0);
}