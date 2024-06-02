/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kitaoryoma <kitaoryoma@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 11:39:12 by kitaoryoma        #+#    #+#             */
/*   Updated: 2024/05/05 22:46:54 by kitaoryoma       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	ft_free_nullb(char *box[OPEN_MAX + 1])
{
	size_t	count;

	count = 0;
	while (count < OPEN_MAX + 1)
	{
		free(box[count]);
		box[count] = NULL;
		count++;
	}
}

size_t	ft_strlenb(const char *str)
{
	size_t	count;

	count = 0;
	while (str[count])
	{
		count++;
	}
	return (count);
}

int	ft_find_nlb(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

void	ft_join_ans_hb(char *new_ans, char *buf, size_t len, size_t *start_end)
{
	size_t	i;

	i = len;
	while (i < len + (start_end[1] - start_end[0]))
	{
		new_ans[i] = buf[start_end[0] + (i - len)];
		i++;
	}
	new_ans[len + (start_end[1] - start_end[0])] = '\0';
}

char	*ft_join_ansb(char **old_ans_p, char *buf, size_t *start_end)
{
	char	*new_ans;
	size_t	i;
	size_t	len;

	len = ft_strlenb(*old_ans_p);
	if (start_end[1] - start_end[0] == 0)
		return (*old_ans_p);
	new_ans = (char *)malloc(len + (start_end[1] - start_end[0]) + 1);
	if (!new_ans)
	{
		free(*old_ans_p);
		*old_ans_p = NULL;
		return (NULL);
	}
	i = 0;
	while (i < len)
	{
		new_ans[i] = (*old_ans_p)[i];
		i++;
	}
	ft_join_ans_hb(new_ans, buf, len, start_end);
	free(*old_ans_p);
	return (new_ans);
}
