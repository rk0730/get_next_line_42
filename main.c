#include <fcntl.h>
#include <stdio.h>

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
int	main(void)
{
	int		fd; 
	char	*tmp;

	fd = open("test.txt", O_RDONLY);
	tmp = get_next_line(fd);
	printf("%s", tmp);
	close(fd);
	return (0);
}
