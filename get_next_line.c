/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kitaoryoma <kitaoryoma@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 23:33:41 by kitaoryoma        #+#    #+#             */
/*   Updated: 2024/04/22 23:55:09 by kitaoryoma       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*result;
	size_t	i;

	if (size != 0 && SIZE_MAX / size < count)
		return (NULL);
	result = malloc(count * size);
	if (!result)
	{
		free(result);
		return (NULL);
	}
	i = 0;
	while (i < count * size)
	{
		result[i] = 0;
		i++;
	}
	return (result);
}

//1字ずつ読んでtmpにつめていく　戻り値は読んだバイト数　readが-1を返したら-1を返す　1文字目がヌル文字なら0を返す
int	ft_read(char *tmp, int fd, size_t bs)
{
	
}


//BUFFER_SIZEがsize_tを超えるとft_callocでエラー処理されるようになっているがこれでいいのか
char	*get_next_line(int fd)
{
	char	*tmp;
	char	*result;
	int		bytes;

	if (BUFFER_SIZE <= 0)
		return (NULL);
	tmp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!tmp)
		return (NULL);
	bytes = ft_read(tmp, fd, BUFFER_SIZE);
	result = (char *)malloc(sizeof(char) * (bytes + 1));
	//ここでft_readでエラーが起きた時のbytes=0, 1も同時に考慮
	//resultがマロックエラーした時もfree(result)は起こられない
	if (!result || bytes == 0 || bytes == -1)
	{
		free(tmp);
		free(result);
		return (NULL);
	}
	//resultにtmpをつめる

	return (result);
}
