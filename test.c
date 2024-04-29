#include "get_next_line.h"

#include <stdio.h>
#include <fcntl.h>

__attribute__((destructor))
static void destructor() {
    system("leaks -q a.out");
}

int	main()
{
	int fd = open("test100", O_RDONLY);

	char *str = get_next_line(fd);
	printf("result %s\n", str);
	while (str != NULL)
	{
		str = get_next_line(fd);
		printf("result %s\n", str);
	}

	close(fd);
	return (0);
}
