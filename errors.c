#include "libft.h"
#include "settings.h"

void    ft_app_error(int error_code)
{
    if (error_code == 1)
        ft_putstr_fd("Invalid Map: Empty Map\n", 2);
    else if (error_code == 2)
        ft_putstr_fd("Invalid Map: The map is not valid\n", 2);
    exit(ERROR_STATUS);
}