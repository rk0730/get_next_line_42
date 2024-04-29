/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkitao <rkitao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 23:33:41 by kitaoryoma        #+#    #+#             */
/*   Updated: 2024/04/29 21:42:38 by rkitao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>

void	ft_count_word(char *str, size_t *start_p, size_t *end_p)
{
	*start_p = 0;
	while (*start_p < BUFFER_SIZE && str[*start_p] == '\0')
		*start_p = *start_p + 1;
	*end_p = *start_p;
	while (*end_p < BUFFER_SIZE && str[*end_p] != '\0' && str[*end_p] != '\n')
		*end_p = *end_p + 1;
	if (str[*end_p] == '\n')
		*end_p = *end_p + 1;
}

char	*ft_join_ans(char **old_ans_p, char *buf, size_t start, size_t end)
{
	char	*new_ans;
	size_t	i;
	size_t	len;

	len = ft_strlen(*old_ans_p);
	if (end - start == 0)
		return (*old_ans_p);
	new_ans = (char *)malloc(len + (end - start) + 1);
	//printf("malloc1\n");
	if (!new_ans)
	{
		free(*old_ans_p);
		//printf("free1\n");
		*old_ans_p = NULL;
		return (NULL);
	}
	i = 0;
	while (i < len)
	{
		new_ans[i] = (*old_ans_p)[i];
		i++;
	}
	while (i < len + (end - start))
	{
		new_ans[i] = buf[start + (i - len)];
		i++;
	}
	new_ans[len + (end - start)] = '\0';
	free(*old_ans_p);
	//printf("free2\n");
	return (new_ans);
}

int	ft_gen_help(char *buf, char **ans_p, size_t *start_p, size_t *end_p)
{
	ft_count_word(buf, start_p, end_p);
	*ans_p = ft_join_ans(ans_p, buf, *start_p, *end_p);
	if (!(*ans_p))
		return (1);
	while (*start_p < *end_p)
	{
		if (buf)
			buf[*start_p] = '\0';
		*start_p = *start_p + 1;
	}
	return (0);
}

char	*ft_gen_ans(int fd, char *box[OPEN_MAX])
{
	size_t	start;
	size_t	end;
	char	*ans;
	int		result;
	int		read_r;

	ans = (char *)malloc(sizeof(char));
	//printf("malloc2\n");
	if (!ans)
		return (NULL);
	*ans = '\0';
	result = ft_gen_help(box[fd], &ans, &start, &end);
	if (result == 1)
	{
		free(ans);
		//printf("free3\n");
		return (NULL);
	}
	while (end == BUFFER_SIZE && ft_find_nl(ans) == 0)
	{
		read_r = read(fd, box[fd], BUFFER_SIZE);
		//printf("read result %d\n", read_r);
		if (read_r == -1)
		{
			free(ans);
			//printf("free4\n");
			return (NULL);
		}
		if (read_r == 0)
		{
			free(box[fd]);
			//printf("free5\n");
			//printf("address %s\n", box[fd]);
			box[fd] = NULL;
			return (ans);
		}
		result = ft_gen_help(box[fd], &ans, &start, &end);
		if (result == 1)
		{
			free(ans);
			//printf("free6\n");
			return (NULL);
		}
	}
	return (ans);
}

//BUFFER_SIZEがsize_tを超えるとft_callocでエラー処理されるようになっているがこれでいいのか
//BUFFER_SIZEにsizemaxが入るとBUFFER_SIZE + 1のcallocで失敗する
char	*get_next_line(int fd)
{
	static char	*box[OPEN_MAX + 1];
	char		*ans;
	size_t		i;

	if (fd < 0 || (size_t)BUFFER_SIZE == 0)
		return (NULL);
	if (box[fd] == NULL)
	{
		box[fd] = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		//printf("malloc3\n");
		if (!(box[fd]))
		{
			ft_free_null(box);
			return (NULL);
		}
		i = 0;
		while (i < BUFFER_SIZE + 1)
			box[fd][i++] = '\0';
		// //printf("fd %d\n", fd);
	}
	ans = ft_gen_ans(fd, box);
	// //printf("ans address %p\n", ans);
	if (!ans)
		ft_free_null(box);
	if (!ans || ft_strlen(ans) == 0)
	{
		free(ans);
		//printf("free7\n");
		return (NULL);
	}
	return (ans);
}
