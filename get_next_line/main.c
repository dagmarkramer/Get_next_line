// #include <unistd.h>
// #include <stdlib.h>
#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

// int		main(int ac, char *av[])
// {
// 	char	*line;
// 	int		fd;

// 	if (ac < 2)
// 	{
// 		printf("usage: a.out file");
// 		return (-1);
// 	}
// 	line = 0;
// 	fd = open(av[1], O_RDONLY);
// 	printf("%s\n", line);
// 	free(line);
// 	while (get_next_line(fd, &line) != 0)
// 	{
// 		printf("%s\n", line);
// 		free(line);
// 	}
// 	close(fd);
// 	return (0);
// }

int main(int ac, char *av[])
{
	//gcc -Wall -Wextra -Werror -D BUFFER_SIZE=32 get_next_line.c get_next_line_utils.c
	// Line is allocated by GNL and freed outside of the function.
	char *line;
	int fd;

	if (ac < 2)
	{
		printf("usage: a.out file");
		return (-1);
	}
	line = 0;
	fd = open(av[1], O_RDONLY);
	get_next_line(fd, &line);
	printf("%s\n", line);
	free (line);

	get_next_line(fd, &line);
	printf("%s\n", line);
	free (line);

	get_next_line(fd, &line);
	printf("%s\n", line);
	free (line);

	get_next_line(fd, &line);
	printf("%s\n", line);
	free (line);

	get_next_line(fd, &line);
	printf("%s\n", line);
	free (line);

	get_next_line(fd, &line);
	printf("%s\n", line);
	free (line);

	get_next_line(fd, &line);
	printf("%s\n", line);
	free (line);

	get_next_line(fd, &line);
	printf("%s\n", line);
	free (line);

	close(fd);
	return (0);
}