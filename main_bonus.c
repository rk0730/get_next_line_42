//cc -Wall -Wextra -Werror -D BUFFER_SIZE=5 get_next_line_bonus.c get_next_line_utils_bonus.c main_bonus.c -include get_next_line_bonus.h; ./a.out;

#include "get_next_line_bonus.h"
#include <stdio.h>
#include <fcntl.h>

#include <libc.h>

__attribute__((destructor))
static void destructor() {
	system("leaks -q a.out");
}

int	main()
{
	char	*line1;
	char	*line2;
	int fd1 = open("get_next_line.h", O_RDONLY);
	int	fd2 = open("get_next_line_bonus.h", O_RDONLY);
	while (1)
	{
		line1 = get_next_line(fd1);
		line2 = get_next_line(fd2);

		if (!line2)
			break;
		printf("%s", line1);
		printf("%s", line2);
		free(line1);
		free(line2);
	}
	close(fd1);
	close(fd2);
	return (0);
}
