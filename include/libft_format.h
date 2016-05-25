/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_format.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 10:32:33 by qloubier          #+#    #+#             */
/*   Updated: 2016/05/22 06:57:05 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_FORMAT_H
# define LIBFT_FORMAT_H
# include <string.h>
# include <stdarg.h>
# include <inttypes.h>
# include "ft.h"
# include "libft_list.h"
# include "libft_string.h"

# define PF_TYPE_STR "diocsSfpxu%"
# define PF_FLAG_STR "#+0- "

/*
**	Declare public format function
*/

enum					e_pf_flag
{
	ALTERNTE = 1,
	FORCE_SIGN = 1 << 1,
	ZERO_FILL = 1 << 2,
	LEFT_ALIGN = 1 << 3,
	SPACE = 1 << 4,
	SHORT_SHORT = 1 << 10,
	SHORT = 1 << 11,
	LONG = 1 << 12,
	LONG_LONG = 1 << 13,
	INTMAX = 1 << 14,
	SIZE_T = 1 << 15,
	CAPITAL = 1 << 16,
	END = (int)(1u << 31)
};

enum					e_pf_type
{
	PFT_INT = 1,
	PFT_OCT = 1 << 1,
	PFT_UINT = 1 << 2,
	PFT_HEXA = 1 << 3,
	PFT_CHAR = 1 << 4,
	PFT_PTR = 1 << 5,
	PFT_SPECHAR = 1 << 6,
	PFT_STR = 1 << 7,
	PFT_WSTR = 1 << 8,
	PFT_FLOAT = 1 << 9
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

void					ft_pfarg_nbr(va_list ap, t_ptfc *arg);
void					ft_pfarg_unbr(va_list ap, t_ptfc *arg);
void					ft_pfarg_oct(va_list ap, t_ptfc *arg);
void					ft_pfarg_hexa(va_list ap, t_ptfc *arg);
void					ft_pfarg_char(va_list ap, t_ptfc *arg);
void					ft_pfarg_str(va_list ap, t_ptfc *arg);
void					ft_pfarg_wstr(va_list ap, t_ptfc *arg);
void					ft_pfarg_float(va_list ap, t_ptfc *arg);
void					ft_pfarg_ptr(va_list ap, t_ptfc *arg);
void					ft_pfarg_spc(va_list ap, t_ptfc *arg);

int						ft_printf(const char *fstr, ...);
int						ft_printf_fd(int fd, const char *fstr, ...);
int						ft_preform_count(const char *fstr, va_list ap,
							t_list **args);
int						ft_print_buff(const char *fstr, int len, t_list **args);

void					**ft_gettypetab(int i);

#endif
