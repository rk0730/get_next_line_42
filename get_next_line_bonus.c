/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kitaoryoma <kitaoryoma@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 11:43:47 by kitaoryoma        #+#    #+#             */
/*   Updated: 2024/05/04 11:43:49 by kitaoryoma       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	ft_count_wordb(char *str, size_t *start_p, size_t *end_p)
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

//うまくいったらans 失敗したらnullを返す
char	*ft_gen_ans_hb(char *box[OPEN_MAX + 1], int fd, char **ap, size_t *se)
{
	int	read_r;

	while (se[1] == BUFFER_SIZE && ft_find_nlb(*ap) == 0)
	{
		read_r = read(fd, box[fd], BUFFER_SIZE);
		if (read_r == -1)
		{
			free(*ap);
			// ft_free_nullb(box);
			free(box[fd]);
			box[fd] = NULL;			
			return (NULL);
		}
		if (read_r == 0)
		{
			free(box[fd]);
			box[fd] = NULL;
			return (*ap);
		}
		if (ft_gen_helpb(box[fd], ap, se) == 1)
		{
			ft_free_nullb(box);
			return (NULL);
		}
	}
	return (*ap);
}

//buf,ans_pがnullであることはない
//ansを伸ばしたあとbufのstartからendまでを\0で埋めるmallocミスがあれば1を返し、うまくいけば0を返す
int	ft_gen_helpb(char *buf, char **ans_p, size_t *start_end)
{
	ft_count_wordb(buf, &(start_end[0]), &(start_end[1]));
	*ans_p = ft_join_ansb(ans_p, buf, start_end);
	if (!(*ans_p))
		return (1);
	while (start_end[0] < start_end[1])
	{
		if (buf)
			buf[start_end[0]] = '\0';
		start_end[0] = start_end[0] + 1;
	}
	return (0);
}

//box[fd]がnullであることはない。ansを作ってそれを返す
//どこかでmallocミスがあった場合はnullを返す。
char	*ft_gen_ansb(int fd, char *box[OPEN_MAX + 1])
{
	size_t	start_end[2];
	char	*ans;
	int		result;

	ans = (char *)malloc(sizeof(char));
	if (!ans)
	{
		ft_free_nullb(box);
		return (NULL);
	}
	*ans = '\0';
	result = ft_gen_helpb(box[fd], &ans, start_end);
	if (result == 1)
	{
		ft_free_nullb(box);
		return (NULL);
	}
	return (ft_gen_ans_hb(box, fd, &ans, start_end));
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
		if (!(box[fd]))
		{
			ft_free_nullb(box);
			return (NULL);
		}
		i = 0;
		while (i < BUFFER_SIZE + 1)
			box[fd][i++] = '\0';
	}
	ans = ft_gen_ansb(fd, box);
	if (!ans || ft_strlenb(ans) == 0)
	{
		free(ans);
		return (NULL);
	}
	return (ans);
}
