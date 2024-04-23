#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//標準入力のテスト
// int	main(void)
// {
// 	int		fd; 
// 	char	*tmp;

// 	fd = 0;
// 	tmp = get_next_line(fd);
// 	printf("%s", tmp);
// 	return (0);
// }

//ファイルのテスト
// int	main(void)
// {
// 	int		fd; 
// 	char	*tmp;

// 	fd = open("test.txt", O_RDONLY);
// 	tmp = get_next_line(fd);
// 	printf("%s", tmp);
// 	close(fd);
// 	return (0);
// }

# define TEST_BF 5
# define MAX 1000000

void	getnext(int fd)
{
	//2098803000
	static char	box[MAX / 50][TEST_BF + 1];
	if (!(box[0][0]))
		printf("null\n");
	else
		printf("notnull\n");
	printf("boxの最初 %d\n", box[fd][0]);
	// printf("box[5] %d\n", box[]);
	int	result = read(fd, &box[fd][0], TEST_BF);
	printf("result %d\n", result);
	printf("result %s\n", &box[fd][0]);
}


int	main(void)
{
	int	fd1 = open("alpha.txt", O_RDONLY);
	int	fd2 = open("alpha2.txt", O_RDONLY);
	int	fd3 = open("num.txt", O_RDONLY);

	printf("fd1\n");
	getnext(fd1);
	printf("fd1\n");
	getnext(fd1);
	printf("fd2\n");
	getnext(fd2);
	printf("fd1\n");
	getnext(fd1);
	printf("fd3\n");
	getnext(fd3);
	return (0);
}
