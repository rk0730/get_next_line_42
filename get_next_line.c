/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kitaoryoma <kitaoryoma@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 23:33:41 by kitaoryoma        #+#    #+#             */
/*   Updated: 2024/04/23 11:21:55 by kitaoryoma       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//基本的に構造体を使って進める　使えないなら二次元配列？
//BUFFER_SIZEの大きさの文字列をmallocなしでつくれるのかどうか試す
//構造体はfd 文字列 nextからなる

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

//1字ずつ読んでtmpにつめていく　戻り値は読んだバイト数　readが-1を返したら0を返す　1文字目がヌル文字なら0を返す
size_t	ft_read(char *tmp, int fd, size_t bs)
{
	//readの戻り値が-1なら即return
	//今まで読んだ文字数をcountする
	//while (count < bs)
	//readする
	//readの戻り値が-1でないかどうか確認する
	//今入れた文字tmp[count]を確認し、\0ならreturn(count)、\nならインクリメントしてreturn(count)
	//whileを抜けたらreturn (count)（return (bs)と同じ）
}


//BUFFER_SIZEがsize_tを超えるとft_callocでエラー処理されるようになっているがこれでいいのか
//BUFFER_SIZEにsizemaxが入るとBUFFER_SIZE + 1のcallocで失敗する
char	*get_next_line(int fd)
{
	char		*tmp;
	char		*result;
	size_t		bytes;

	if (BUFFER_SIZE <= 0)
		return (NULL);
	tmp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!tmp)
		return (NULL);
	bytes = ft_read(tmp, fd, BUFFER_SIZE);
	result = (char *)malloc(sizeof(char) * (bytes + 1));
	//ここでft_readでエラーが起きた時のbytes=0も同時に考慮
	//resultがマロックエラーした時もfree(result)は起こられない
	if (!result || bytes == 0)
	{
		free(tmp);
		free(result);
		return (NULL);
	}
	//resultにtmpをつめる

	return (result);
}
