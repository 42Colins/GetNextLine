#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main()
{
	int fd;
	fd = open("42.txt", O_RDONLY);
	//get_next_line(fd);
	int i = 0;
	// while (i < 10)
	// {
	// 	printf("%s", get_next_line(fd));
	// 	i++;
	// }
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
}
