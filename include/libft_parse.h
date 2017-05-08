/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_parse.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/09 19:48:04 by qloubier          #+#    #+#             */
/*   Updated: 2017/05/07 22:03:06 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_PARSE_H
# define LIBFT_PARSE_H

# include <inttypes.h>
# include <string.h>
# include <stdarg.h>
# include "ft.h"
# include "libft_string.h"
# include "libft_memory.h"
# include "libft_math.h"
# include "libft_list.h"

# define SF_TYPE_STR "idfxXusc%onN"
# define SF_FLAG_STR "*hljz_"

enum					e_sf_flag
{
	SFF_NONE = 0,
	SFF_IGNORE = 1,
	SFF_OPTIONAL = 1 << 2,
	SFF_SHORT_SHORT = 1 << 10,
	SFF_SHORT = 1 << 11,
	SFF_LONG = 1 << 12,
	SFF_LONG_LONG = 1 << 13,
	SFF_INTMAX = 1 << 14,
	SFF_SIZE_T = 1 << 15,
	SFF_CAPITAL = 1 << 16,
	SFF_MXW_SET = 1 << 18,
	SFF_END = (int)(1u << 30)
};

typedef struct			s_scanf_convert
{
	int					flag;
	int					maxwidth;
	void				*arg;
}						t_sfc;

typedef struct			s_scanf_buffer
{
	int					arglen;
	int					padding;
	const char			*src;
	const char			*c;
	const char			*ref;
	va_list				ap;
	t_sfc				arg;
}						t_sfb;

typedef struct			s_scanf_cftab
{
	const char			*(*flag)(const char *, t_sfb *);
	int					(*convert)(const char **, t_sfb*, t_sfc*);
}						t_sftab;

typedef struct			s_key_func
{
	const char			*key;
	int					(*func)(const char *, const char *, void *);
}						t_kf;

int						ft_parse_assign(const t_kf *a_table, const char *str,
							void *arg);

const char				*ft_parse_digit(const char *str, unsigned int *num);
const char				*ft_parse_cmap(const char *str, unsigned long *num,
							t_cmap cm, int len);
const char				*ft_parse_cmlow(const char *str, unsigned long *num,
							t_cmap cm, int len);
const char				*ft_parsej_cmap(const char *str, uintmax_t *num,
							t_cmap cm, int len);
const char				*ft_parsef(const char *str, double *num,
							t_cmap cm, int len);
const char				*ft_parseld(const char *str, long double *num,
							t_cmap cm, int len);
void					ft_bufskip(const char **str, int len, t_cmap cm);
void					ft_bufskipf(const char **str, int len, t_cmap cm);
int						ft_atoi(const char *str);
long					ft_atol(const char *str);
unsigned int			ft_atoui(const char *str);
unsigned long			ft_atoul(const char *str);
float					ft_atof(const char *str);
double					ft_atod(const char *str);
int						ft_buftoi(const char **str, int len, t_cmap cm);
long					ft_buftol(const char **str, int len, t_cmap cm);
intmax_t				ft_buftoj(const char **str, int len, t_cmap cm);
unsigned int			ft_buftoui(const char **str, int len, t_cmap cm);
unsigned long			ft_buftoul(const char **str, int len, t_cmap cm);
uintmax_t				ft_buftouj(const char **str, int len, t_cmap cm);
float					ft_buftof(const char **str, int len, t_cmap cm);
double					ft_buftod(const char **str, int len, t_cmap cm);
long double				ft_buftold(const char **str, int len, t_cmap cm);
const char				*ft_forf(const char *c, const char *s, size_t *len);

const char				*ft_sfflag_j(const char *c, t_sfb *b);
const char				*ft_sfflag_h(const char *c, t_sfb *b);
const char				*ft_sfflag_l(const char *c, t_sfb *b);
const char				*ft_sfflag_z(const char *c, t_sfb *b);
const char				*ft_sfflag_width(const char *c, t_sfb *b);
const char				*ft_sfflag_nc(const char *c, t_sfb *b);
const char				*ft_sfflag_opt(const char *c, t_sfb *b);

int						ft_sfconv_d(const char **c, t_sfb *b, t_sfc *arg);
int						ft_sfconv_i(const char **c, t_sfb *b, t_sfc *arg);
int						ft_sfconv_u(const char **c, t_sfb *b, t_sfc *arg);
int						ft_sfconv_f(const char **c, t_sfb *b, t_sfc *arg);
int						ft_sfconv_s(const char **c, t_sfb *b, t_sfc *arg);
int						ft_sfconv_c(const char **c, t_sfb *b, t_sfc *arg);
int						ft_sfconv_n(const char **c, t_sfb *b, t_sfc *arg);

int						ft_sfbuftoarg(t_sfb *b, t_sfc *arg, t_cmap cm);
int						ft_sfbuftouarg(t_sfb *b, t_sfc *arg, t_cmap cm);
int						ft_sfbuftofarg(t_sfb *b, t_sfc *arg, t_cmap cm);
int						ft_scanf_loop(const char *fstr, t_sfb *sfb);
const char				*ft_scanf_parse(const char *fstr, t_sfb *sfb);
const char				*ft_scanf_convert(const char *fstr, int i, t_sfb *sfb);

int						ft_sscanf(const char *str, const char *fstr, ...);

static const t_sftab	g_sf_flag_tab[] = {
	(t_sftab){&ft_sfflag_nc, &ft_sfconv_i},
	(t_sftab){&ft_sfflag_h, &ft_sfconv_d},
	(t_sftab){&ft_sfflag_l, &ft_sfconv_f},
	(t_sftab){&ft_sfflag_j, &ft_sfconv_u},
	(t_sftab){&ft_sfflag_z, &ft_sfconv_u},
	(t_sftab){&ft_sfflag_opt, &ft_sfconv_u},
	(t_sftab){NULL, &ft_sfconv_s},
	(t_sftab){NULL, &ft_sfconv_c},
	(t_sftab){NULL, &ft_sfconv_n},
	(t_sftab){NULL, &ft_sfconv_u},
	(t_sftab){NULL, &ft_sfconv_n},
	(t_sftab){NULL, &ft_sfconv_n},
	(t_sftab){NULL, NULL}
};

/*
** Arg parser
** !!! NEED TESTING !!!
*/

# define FT_EQUAL_VALUE	0x01

typedef struct			s_argopt
{
	char				letter;
	char				buf[3];
	int					flag;
	char				*argword;
	int					(*cb)(FT_CC *, void *, FT_CC **, int);
	struct s_argopt		*next;
}						t_arg;

typedef struct			s_argret
{
	int					argp;
	int					ac;
	char				**av;
}						t_argret;


t_arg					*ft_setarg(t_arg **arglst, char c, FT_CC *str,
							int (*cb)(FT_CC *, void *, FT_CC **, int));
t_argret				*ft_parsearg(t_arg *arglst, int argc, char **argv,
							void *arg);
int						ft_freearg(t_arg **arglst, t_argret *argp);

/*
** TO DO
*/

/*
** Element system
*/

typedef enum			e_ft_valuetype
{
	VT_NONE			= 0,
	VS_SHORTSHORT	= 0x0010,
	VS_SHORT		= 0x0020,
	VS_LONGLONG		= 0x0040,
	VS_LONG			= 0x0080,
	VF_UNSIGNED		= 0x0100,
	VF_VEC2			= 0x0200,
	VF_VEC3			= 0x0400,
	VF_VEC4			= 0x0800,
	VF_PTR			= 0x1000,
	VF_ELEMENT		= 0x2000,
	VT_INT			= 0x1,
	VT_UINT			= VF_UNSIGNED | VT_INT,
	VT_LONG			= VS_LONG | VT_INT,
	VT_ULONG		= VF_UNSIGNED | VS_LONG | VT_INT,
	VT_FLOAT		= 0x2,
	VT_DOUBLE		= VS_LONG | VT_FLOAT,
	VT_COLOR		= VF_VEC4 | VF_UNSIGNED | VS_SHORTSHORT | VT_INT,
	VT_VEC2I		= VF_VEC2 | VT_INT,
	VT_VEC3I		= VF_VEC3 | VT_INT,
	VT_VEC4I		= VF_VEC4 | VT_INT,
	VT_VEC2UI		= VF_VEC2 | VF_UNSIGNED | VT_INT,
	VT_VEC3UI		= VF_VEC3 | VF_UNSIGNED | VT_INT,
	VT_VEC4UI		= VF_VEC4 | VF_UNSIGNED | VT_INT,
	VT_VEC2L		= VF_VEC2 | VT_LONG,
	VT_VEC3L		= VF_VEC3 | VT_LONG,
	VT_VEC4L		= VF_VEC4 | VT_LONG,
	VT_VEC2F		= VF_VEC2 | VT_FLOAT,
	VT_VEC3F		= VF_VEC3 | VT_FLOAT,
	VT_VEC4F		= VF_VEC4 | VT_FLOAT,
	VT_VEC2D		= VF_VEC2 | VT_DOUBLE,
	VT_VEC3D		= VF_VEC3 | VT_DOUBLE,
	VT_VEC4D		= VF_VEC4 | VT_DOUBLE,
	VT_CHAR			= 0x3,
	VT_STR			= VF_PTR | VT_CHAR
}						t_vt;

struct					s_ft_value
{
	t_ui				basetype;
	t_ui				offset;
	char				*name;
	t_elm				*descriptor;
};

struct					s_ft_element
{
	char				*name;
	t_ui				size;
	t_ui				vlen;
	t_val				*value;
	void				(*getter)(t_val*, void*, void*);
	void				(*setter)(t_val*, void*, void*);
	int					(*parser)(t_val*, void*, const char *);
	t_elm				*next;
};

typedef struct			s_ft_generic_parser
{
	const char			*separator;
	const char			*end;
	const char			*cursor;
	const char			*buffer;
}						t_gparse;

int						ft_eparse(t_gparse parser, t_elm *elm, void *mem);
int						ft_vparse_int(t_val *val, void *mem, const char *str);
int						ft_vparse_uint(t_val *val, void *mem, const char *str);
int						ft_vparse_vec(t_val *val, void *mem, const char *str);
int						ft_vparse_col(t_val *val, void *mem, const char *str);
int						ft_vparse_str(t_val *val, void *mem, const char *str);
int						ft_vparse_vstr(t_val *val, void *mem, const char *str);

#endif
