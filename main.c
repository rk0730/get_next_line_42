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

int	main(void)
{
	// int	fd1 = open("alpha.txt", O_RDONLY);
	// int	fd2 = open("alpha2.txt", O_RDONLY);
	// int	fd3 = open("num.txt", O_RDONLY);
	// char	*str = calloc(10, 1);

	// ssize_t result = read(fd1, str, 8);
	// printf("%s\n", str);
	// printf("each\n");
	// for (size_t i = 0; i < 8; i++)
	// {
	// 	printf("%d\n", str[i]);
	// }
	
	// printf("result %zd\n", result);
	// // read(fd1, str, 3);
	// // printf("%s\n", str);
	// // read(fd2, str, 3);
	// // printf("%s\n", str);
	// // read(fd1, str, 3);
	// // printf("%s\n", str);
	// // read(fd2, str, 3);
	// // printf("%s\n", str);
	// // read(0, str, 5);
	// // printf("%s\n", str);
	// // read(fd1, str, 3);
	// // printf("%s\n", str);
	// // read(0, str, 5);
	// // printf("%s\n", str);

	// free(str);
	// close(fd1);
	// close(fd2);
	// close(fd3);
	char *str = (char *)malloc(0);
	printf("%p\n", str);
	return (0);
}
