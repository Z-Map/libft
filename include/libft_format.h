/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_format.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 10:32:33 by qloubier          #+#    #+#             */
/*   Updated: 2016/10/06 03:05:42 by map              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_FORMAT_H
# define LIBFT_FORMAT_H
# include <string.h>
# include <stdarg.h>
# include <inttypes.h>
# include <wchar.h>
# include <unistd.h>
# include "ft.h"
# include "libft_list.h"
# include "libft_string.h"
# include "libft_wstring.h"
# include "libft_unicode.h"
# include "libft_parse.h"
# include "libft_io.h"

# ifndef FT_PF_BUFSIZE
#  define FT_PF_BUFSIZE 4096
# endif

# define FT_MX_FLOATLEN 310

# define PF_TYPE_STR "dDioOcCsSfFpxXuUn%"
# define PF_FLAG_STR "#+0- .hljz*"

# define PF_UCHAR 0xFF
# define PF_USHORT 0xFFFF

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
	PFF_PTR = 1 << 19,
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
	int					(*getarg)(int, va_list, t_pfc*);
	int					(*getlen)(t_pfc*);
	void				(*convert)(t_pfb*, t_pfc*, size_t);
}						t_pftab;

int						ft_printf_bwrite(t_pfb *b, const char *c, size_t len);
int						ft_printf_bwritew(t_pfb *b, const wchar_t *c,
							size_t len);
int						ft_printf_bwritec(t_pfb *b, char c, size_t len);
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
char					*ft_ujtobuf(char *b, uintmax_t n);

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

int						ft_pfarg_nbr(int cc, va_list ap, t_pfc *arg);
int						ft_pfarg_unbr(int cc, va_list ap, t_pfc *arg);
int						ft_pfarg_oct(int cc, va_list ap, t_pfc *arg);
int						ft_pfarg_hexa(int cc, va_list ap, t_pfc *arg);
int						ft_pfarg_char(int cc, va_list ap, t_pfc *arg);
int						ft_pfarg_str(int cc, va_list ap, t_pfc *arg);
int						ft_pfarg_wstr(int cc, va_list ap, t_pfc *arg);
int						ft_pfarg_float(int cc, va_list ap, t_pfc *arg);
int						ft_pfarg_ptr(int cc, va_list ap, t_pfc *arg);
int						ft_pfarg_spc(int cc, va_list ap, t_pfc *arg);
int						ft_pfarg_n(int cc, va_list ap, t_pfc *arg);

int						ft_pflen_nbr(t_pfc *arg);
int						ft_pflen_unbr(t_pfc *arg);
int						ft_pflen_str(t_pfc *arg);
int						ft_pflen_char(t_pfc *arg);
int						ft_pflen_float(t_pfc *arg);
int						ft_pflen_n(t_pfc *arg);

void					ft_pfconv_nbr(t_pfb *b, t_pfc *arg, size_t len);
void					ft_pfconv_unbr(t_pfb *b, t_pfc *arg, size_t len);
void					ft_pfconv_str(t_pfb *b, t_pfc *arg, size_t len);
void					ft_pfconv_char(t_pfb *b, t_pfc *arg, size_t len);
void					ft_pfconv_float(t_pfb *b, t_pfc *arg, size_t len);
void					ft_pfconv_n(t_pfb *b, t_pfc *arg, size_t len);

int						ft_printf(const char *fstr,
	...) __attribute__((format(printf,1,2)));
int						ft_printf_fd(int fd, const char *fstr, ...);
int						ft_preform_count(const char *fstr, va_list ap,
							t_list **args);
int						ft_print_buff(const char *fstr, int len, t_list **args);

void					**ft_gettypetab(int i);

const static char		*g_pf_nullstr = "(null)";
const static t_pftab	g_pf_flag_tab[] = {
	(t_pftab){&ft_pfflag_alt, &ft_pfarg_nbr, &ft_pflen_nbr, &ft_pfconv_nbr},
	(t_pftab){&ft_pfflag_more, &ft_pfarg_nbr, &ft_pflen_nbr, &ft_pfconv_nbr},
	(t_pftab){&ft_pfflag_zero, &ft_pfarg_nbr, &ft_pflen_nbr, &ft_pfconv_nbr},
	(t_pftab){&ft_pfflag_less, &ft_pfarg_oct, &ft_pflen_unbr, &ft_pfconv_unbr},
	(t_pftab){&ft_pfflag_space, &ft_pfarg_oct, &ft_pflen_unbr, &ft_pfconv_unbr},
	(t_pftab){&ft_pfflag_dot, &ft_pfarg_char, &ft_pflen_char, &ft_pfconv_char},
	(t_pftab){&ft_pfflag_h, &ft_pfarg_char, &ft_pflen_char, &ft_pfconv_char},
	(t_pftab){&ft_pfflag_l, &ft_pfarg_str, &ft_pflen_str, &ft_pfconv_str},
	(t_pftab){&ft_pfflag_j, &ft_pfarg_str, &ft_pflen_str, &ft_pfconv_str},
	(t_pftab){&ft_pfflag_z, &ft_pfarg_float, &ft_pflen_float,
		&ft_pfconv_float},
	(t_pftab){&ft_pfflag_width, &ft_pfarg_float, &ft_pflen_float,
		&ft_pfconv_float},
	(t_pftab){NULL, &ft_pfarg_ptr, &ft_pflen_unbr, &ft_pfconv_unbr},
	(t_pftab){NULL, &ft_pfarg_hexa, &ft_pflen_unbr, &ft_pfconv_unbr},
	(t_pftab){NULL, &ft_pfarg_hexa, &ft_pflen_unbr, &ft_pfconv_unbr},
	(t_pftab){NULL, &ft_pfarg_unbr, &ft_pflen_unbr, &ft_pfconv_unbr},
	(t_pftab){NULL, &ft_pfarg_unbr, &ft_pflen_unbr, &ft_pfconv_unbr},
	(t_pftab){NULL, &ft_pfarg_n, &ft_pflen_n, &ft_pfconv_n},
	(t_pftab){NULL, &ft_pfarg_spc, &ft_pflen_char, &ft_pfconv_char}
};

/*
**	TO DO
*/

char					*ft_dtoa(double n, t_ui prec);
char					*ft_ftoa(float n, t_ui prec);

#endif
