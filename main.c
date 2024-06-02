// cc -Wall -Wextra -Werror -D BUFFER_SIZE=5 get_next_line.c get_next_line_utils.c main.c -include get_next_line.h
// ./a.out

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

#include <libc.h>

__attribute__((destructor))
static void destructor() {
	system("leaks -q a.out");
}

#include <errno.h>

int count = 0;

void *malloc(size_t size)
{
	static int i = 0;
	while (i++ < count)
		return (calloc(size, 1));
	errno = ENOMEM;
	return (NULL);
}

int	main(void)
{
	char	*line;
	int		fd;

	fd = open("get_next_line.h", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}
