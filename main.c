#include "get_next_line.h"
#include <stdio.h>

int main()
{
	int fd;
	fd = open("42.txt", O_RDONLY);
	int i = 0;
	char *str;
	while (i < 10)
	{
		str = get_next_line(fd);
		printf("%s", str);
		free(str);
		i++;
	}
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
}
