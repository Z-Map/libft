/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 17:05:20 by qloubier          #+#    #+#             */
/*   Updated: 2016/05/22 05:59:07 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <inttypes.h>
# include <stdarg.h>

# include "ft.h"
# include "libft_memory.h"
# include "libft_string.h"
# include "libft_list.h"
# include "libft_format.h"

# ifndef BUFF_SIZE
#  define BUFF_SIZE 80
# endif

# if BUFF_SIZE < 64
#  define GROW_SIZE 64
# else
#  define GROW_SIZE BUFF_SIZE
# endif
# if BUFF_SIZE > 128
#  define START_SIZE BUFF_SIZE
# else
#  define START_SIZE 128
# endif

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
