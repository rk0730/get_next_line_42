/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkitao <rkitao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 23:34:14 by kitaoryoma        #+#    #+#             */
/*   Updated: 2024/04/29 21:51:59 by rkitao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

//消す
#include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);
char	*ft_gen_ans(int fd, char *box[OPEN_MAX]);
char	*ft_join_ans(char **old_ans_p, char *buf, size_t start, size_t end);
void	ft_free_null(char *box[OPEN_MAX]);
size_t	ft_strlen(const char *str);
int		ft_gen_help(char *buf, char **ans_p, size_t *start_p, size_t *end_p);
int		ft_find_nl(char *str);

#endif
