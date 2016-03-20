/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 17:05:20 by qloubier          #+#    #+#             */
/*   Updated: 2016/03/19 17:55:56 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include "mem/libft_memory.h"
# include "str/libft_string.h"
# include "lst/libft_list.h"
# define BUFF_SIZE 32
# if BUFF_SIZE < 32
#  define GROW_SIZE 32
# else
#  define GROW_SIZE BUFF_SIZE
# endif
# define START_SIZE 64
# if START_SIZE < BUFF_SIZE
#  define START_SIZE BUFF_SIZE
# endif

typedef unsigned int	t_idx;

typedef struct			s_gnl_buffer
{
	int					fd;
	t_idx				buf_size;
	t_idx				cursor;
	char				*strb;
}						t_gnlb;

int						ft_get_line(int const fd, char **line);
int						ft_atoi (const char *str);
char					*ft_itoa(int n);
void					ft_putchar (char c);
void					ft_putstr (char const *s);
void					ft_putendl(char const *s);
void					ft_putnbr(int n);
void					ft_putchar_fd(char c, int fd);
void					ft_putstr_fd(char const *s, int fd);
void					ft_putendl_fd(char const *s, int fd);
void					ft_putnbr_fd(int n, int fd);

#endif
