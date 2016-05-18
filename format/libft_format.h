/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_format.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 10:32:33 by qloubier          #+#    #+#             */
/*   Updated: 2016/05/18 19:55:30 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_FORMAT_H
# define LIBFT_FORMAT_H
# include "../lst/libft_list.h"

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

enum					e_pf_type
{
	PFT_INT = 1,
	PFT_OCTALE = 1 << 1,
	PFT_UINT = 1 << 2,
	PFT_HEXA = 1 << 3,
	PFT_CHAR = 1 << 4,
	PFT_PTR = 1 << 5,
	PFT_SPECHAR = 1 << 6,
	PFT_STR = 1 << 7,
	PFT_WSTR = 1 << 8
};

typedef struct			s_printf_convert
{
	enum e_pf_flag		flag;
	enum e_pf_type		type;
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

void					ft_parse_nbr(va_list ap, t_ptfc *arg);
void					ft_parse_oct(va_list ap, t_ptfc *arg);
void					ft_parse_char(va_list ap, t_ptfc *arg);
void					ft_parse_str(va_list ap, t_ptfc *arg);
void					ft_parse_wstr(va_list ap, t_ptfc *arg);
void					ft_parse_float(va_list ap, t_ptfc *arg);
void					ft_parse_ptr(va_list ap, t_ptfc *arg);
void					ft_parse_spc(va_list ap, t_ptfc *arg);

int						ft_printf(const char *fstr, ...);
int						ft_printf_fd(int fd, const char *fstr, ...);
int						ft_preform_count(const char *fstr, va_list ap,
							t_list **args);
int						ft_print_buff(const char *fstr, int len, t_list **args);

void					**ft_gettypetab(int i);


#endif
