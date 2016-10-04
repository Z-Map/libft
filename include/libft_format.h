/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_format.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 10:32:33 by qloubier          #+#    #+#             */
/*   Updated: 2016/10/04 13:05:43 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_FORMAT_H
# define LIBFT_FORMAT_H
# include <string.h>
# include <stdarg.h>
# include <inttypes.h>
# include <unistd.h>
# include "ft.h"
# include "libft_list.h"
# include "libft_string.h"
# include "libft_parse.h"

# ifndef FT_PF_BUFSIZE
#  define FT_PF_BUFSIZE 4096
# endif

# define FT_MX_FLOATLEN 310

# define PF_TYPE_STR "dDioOcCsSfFpxXuUn%"
# define PF_FLAG_STR "#+0- .lhjz*"

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
	PREC_SET = 1 << 17,
	MNW_SET = 1 << 18,
	END = (int)(1u << 31)
};

enum					e_pf_type
{
	PFT_INT = 1,
	PFT_OCT = 8,
	PFT_UINT = 10,
	PFT_HEXA = 16,
	PFT_CHAR = 2,
	PFT_PTR = 3,
	PFT_SPECHAR = 4,
	PFT_STR = 5,
	PFT_WSTR = 6,
	PFT_FLOAT = 7,
	PFT_N = 9
};

typedef struct			s_printf_convert
{
	enum e_pf_flag		flag;
	enum e_pf_type		type;
	t_ui				precision;
	t_ui				minwidth;
	int					b_len;
	uintmax_t			arg;
}						t_pfc;

typedef struct			s_printf_buffer
{
	ssize_t				len;
	int					blen;
	int					fd;
	char				buffer[FT_PF_BUFSIZE + 1];
	char				*c;
	va_list				ap;
	t_pfc				arg;
}						t_pfb;

typedef struct			s_printf_cftab
{
	const char			*(*flag)(const char *, t_pfb *);
	void				(*getarg)(va_list, t_pfc*);
}						t_pftab;

int						ft_printf_bwrite(t_pfb *b, const char *c, size_t len);
int						ft_printf_bflush(t_pfb *b);

int						ft_printf_loop(const char *fstr, t_pfb *pfb);
const char				*ft_printf_parse(const char *fstr, t_pfb *pfb);
int						ft_printf_convert(int tid, t_pfc *arg, t_pfb *pfb);
const char				*ft_forf(const char *c, const char *s, size_t *len);

size_t					ft_snbrlen(short nbr);
size_t					ft_nbrlen(int nbr);
size_t					ft_lnbrlen(long nbr);
size_t					ft_jnbrlen(intmax_t nbr);
size_t					ft_jdigitlen(intmax_t i);
size_t					ft_nbrlen_base(register long i, char base);
size_t					ft_ujnbrlen(uintmax_t nbr, unsigned int base);
size_t					ft_ujdigitlen(uintmax_t i, unsigned int base);
size_t					ft_floatlen(double i, t_ui pre);

char					*ft_itoa(int n);

const char				*ft_pfflag_alt(const char *c, t_pfb *b);
const char				*ft_pfflag_zero(const char *c, t_pfb *b);
const char				*ft_pfflag_dot(const char *c, t_pfb *b);
const char				*ft_pfflag_l(const char *c, t_pfb *b);
const char				*ft_pfflag_h(const char *c, t_pfb *b);
const char				*ft_pfflag_j(const char *c, t_pfb *b);
const char				*ft_pfflag_z(const char *c, t_pfb *b);
const char				*ft_pfflag_width(const char *c, t_pfb *b);
const char				*ft_pfflag_more(const char *c, t_pfb *b);
const char				*ft_pfflag_less(const char *c, t_pfb *b);
const char				*ft_pfflag_space(const char *c, t_pfb *b);

void					ft_pfarg_nbr(va_list ap, t_pfc *arg);
void					ft_pfarg_unbr(va_list ap, t_pfc *arg);
void					ft_pfarg_oct(va_list ap, t_pfc *arg);
void					ft_pfarg_hexa(va_list ap, t_pfc *arg);
void					ft_pfarg_char(va_list ap, t_pfc *arg);
void					ft_pfarg_str(va_list ap, t_pfc *arg);
void					ft_pfarg_wstr(va_list ap, t_pfc *arg);
void					ft_pfarg_float(va_list ap, t_pfc *arg);
void					ft_pfarg_ptr(va_list ap, t_pfc *arg);
void					ft_pfarg_spc(va_list ap, t_pfc *arg);
void					ft_pfarg_n(va_list ap, t_pfc *arg);

int						ft_printf(const char *fstr,
	...) __attribute__((format(printf,1,2)));
int						ft_printf_fd(int fd, const char *fstr, ...);
int						ft_preform_count(const char *fstr, va_list ap,
							t_list **args);
int						ft_print_buff(const char *fstr, int len, t_list **args);

void					**ft_gettypetab(int i);

const static t_pftab	g_pf_flag_tab[] = {
	(t_pftab){&ft_pfflag_alt, &ft_pfarg_nbr},
	(t_pftab){&ft_pfflag_zero, &ft_pfarg_nbr},
	(t_pftab){&ft_pfflag_dot, &ft_pfarg_nbr},
	(t_pftab){&ft_pfflag_l, &ft_pfarg_oct},
	(t_pftab){&ft_pfflag_h, &ft_pfarg_oct},
	(t_pftab){&ft_pfflag_j, &ft_pfarg_char},
	(t_pftab){&ft_pfflag_z, &ft_pfarg_char},
	(t_pftab){&ft_pfflag_width, &ft_pfarg_str},
	(t_pftab){&ft_pfflag_more, &ft_pfarg_str},
	(t_pftab){&ft_pfflag_less, &ft_pfarg_float},
	(t_pftab){&ft_pfflag_space, &ft_pfarg_float},
	(t_pftab){NULL, &ft_pfarg_ptr},
	(t_pftab){NULL, &ft_pfarg_hexa},
	(t_pftab){NULL, &ft_pfarg_hexa},
	(t_pftab){NULL, &ft_pfarg_unbr},
	(t_pftab){NULL, &ft_pfarg_unbr},
	(t_pftab){NULL, &ft_pfarg_n},
	(t_pftab){NULL, &ft_pfarg_spc}
};

/*
**	TO DO
*/

char					*ft_dtoa(double n, t_ui prec);
char					*ft_ftoa(float n, t_ui prec);

#endif
