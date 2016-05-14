/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 17:05:20 by qloubier          #+#    #+#             */
/*   Updated: 2016/05/13 18:15:09 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <inttypes.h>
# include <stdarg.h>
# include "mem/libft_memory.h"
# include "str/libft_string.h"
# include "lst/libft_list.h"

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

typedef unsigned int	t_idx;
typedef unsigned int	t_ui;

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

/*
**	Declare public format function
*/

enum					e_pf_flag
{
	END = 1,
	FORCE_SIGN = 1 << 1,
	ZERO_FILL = 1 << 2,
	ALTERNTE = 1 << 3,
	SHORT_SHORT = 1 << 4,
	SHORT = 1 << 5,
	LONG = 1 << 6,
	LONG_LONG = 1 << 7,
	INTMAX = 1 << 8,
	SIZE_T = 1 << 9,
	CAPITAL = 1 << 10,
	LEFT_ALIGN = 1 << 11
};

typedef struct			s_printf_convert
{
	enum e_pf_flag		flag;
	t_ui				precision;
	int					minwidth;
	int					b_len;
	uintmax_t			arg;
}						t_ptfc;

size_t					ft_snbrlen(short nbr);
size_t					ft_nbrlen(int nbr);
size_t					ft_lnbrlen(long nbr);
size_t					ft_jnbrlen(intmax_t nbr);
size_t					ft_nbrlen_base(register long i, char base);

size_t					ft_floatlen(double i, t_ui pre);

int						ft_printf(const char *fstr, ...);
int						ft_printf_fd(int fd, const char *fstr, ...);

#endif
