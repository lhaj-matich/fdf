#include "get_next_line.h"
#include <sys/stat.h>
#include <fcntl.h>

char	**read_data(fd)
{
	char *line;
	char **data;
	int j;

	j = 0;
	while (line != '\0')
	{
		line = get_next_line(fd);
		data[j] = line;
		j++;
	}
	return (data);
}

int main(void)
{
	int fd = read("test_maps/42.fdf",O_RDONLY);
	char **data;
   	if (fd < 0)
   	{
   		printf("Error Encountered while opening the file!\n");
   	}
	data = read_data(fd);
   	return (0);
}
