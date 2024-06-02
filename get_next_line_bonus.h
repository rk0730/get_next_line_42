/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkitao <rkitao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 11:39:07 by kitaoryoma        #+#    #+#             */
/*   Updated: 2024/05/11 11:49:26 by rkitao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif

# if BUFFER_SIZE == INT_MAX || BUFFER_SIZE < 0
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 0
# endif

char	*get_next_line(int fd);
char	*ft_gen_ansb(int fd, char *box[OPEN_MAX + 1]);
void	ft_free_nullb(char *box[OPEN_MAX + 1]);
size_t	ft_strlenb(const char *str);
int		ft_find_nlb(char *str);
int		ft_gen_helpb(char *buf, char **ans_p, size_t *start_end);
char	*ft_gen_ans_hb(char *box[OPEN_MAX + 1], int fd, char **ap, size_t *se);
char	*ft_join_ansb(char **old_ans_p, char *buf, size_t *start_end);
void	ft_join_ans_hb(char *new_ans, char *buf, size_t len, size_t *start_end);

#endif
