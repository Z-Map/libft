/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_parse.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/09 19:48:04 by qloubier          #+#    #+#             */
/*   Updated: 2017/05/18 13:01:10 by qloubier         ###   ########.fr       */
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
	VM_TYPE			= 0xFF,
	VS_SHORTSHORT	= 0x00100,
	VS_SHORT		= 0x00200,
	VS_LONGLONG		= 0x00400,
	VS_LONG			= 0x00800,
	VF_UNSIGNED		= 0x01000,
	VF_VEC2			= 0x02000,
	VF_VEC3			= 0x04000,
	VF_VEC4			= 0x08000,
	VF_PTR			= 0x10000,
	VF_ELEMENT		= 0x20000,
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

typedef struct			s_ft_generic_separator
{
	const char			*separator;
	const char			*end;
	int					slen;
	int					elen;
}						t_gsep;

typedef struct			s_ft_generic_parser
{
	const char			*stopset;
	t_gsep				*seplst;
	size_t				seplen;
	const char			*end;
	const char			*cursor;
	size_t				c_len;
	const char			*buffer;
	size_t				b_len;
	const char			*key;
	size_t				k_len;
	const char			*value;
	size_t				v_len;
	void				*arg;
	void				*mem;
	char				*cfgbits;
}						t_gparse;

struct					s_ft_value
{
	t_ui				basetype;
	t_ui				offset;
	int					idx;
	t_ui				flags;
	const char			*name;
	t_elm				*descriptor;
};

struct					s_ft_element
{
	const char			*name;
	size_t				size;
	int					max_idx;
	t_ui				vlen;
	t_val				*values;
	void				(*getter)(t_val*, void*, void*);
	void				(*setter)(t_val*, void*, void*);
	int					(*parser)(t_val*, void*, t_gparse parser);
	t_elm				*next;
};

/*
** Thx to Chr0nos
*/
int						ft_prssetcfgbit(t_gparse parser, int idx);
int						ft_prsgetcfgbit(t_gparse parser, int idx);

/*
** Element parser tools
*/
int						ft_prsgetsep(t_gparse *p, const char *c, size_t len);
int						ft_prsgetgsep(t_gparse *p, const char *c, size_t len);
size_t					ft_prstrim(FT_CC **c, size_t *l, FT_CC *s);
size_t					ft_prsskp(FT_CC **c, size_t *l, FT_CC *s, FT_CC **b);
size_t					ft_prsbrk(FT_CC **c, size_t *l, FT_CC *s, FT_CC **b);
size_t					ft_prsgskp(t_gparse *p, t_gsep *group, FT_CC *e);
int						ft_enext(t_gparse *parser);
int						ft_eparse(t_gparse parser, t_elm *elm, void *mem);
int						ft_evparse(t_gparse p, t_elm *elm, void *mem, int *i);
void					ft_set_numval(t_val *val, void *mem, t_numv num, int s);
void					ft_int_setter(t_val *val, void *mem, void *v);
void					ft_uint_setter(t_val *val, void *mem, void *v);
void					ft_float_setter(t_val *val, void *mem, void *v);
void					ft_str_setter(t_val *val, void *mem, void *v);
int						ft_vparse_int(t_val *val, void *mem, t_gparse parser);
int						ft_vparse_uint(t_val *val, void *mem, t_gparse parser);
int						ft_vparse_float(t_val *val, void *mem, t_gparse parser);
int						ft_vparse_vec(t_val *val, void *mem, t_gparse parser);
int						ft_vparse_col(t_val *val, void *mem, t_gparse parser);
int						ft_vparse_str(t_val *val, void *mem, t_gparse parser);
int						ft_vparse_vstr(t_val *val, void *mem, t_gparse parser);
int						ft_vparse_elm(t_val *val, void *mem, t_gparse parser);
int						ft_vparse_null(t_val *val, void *mem, t_gparse parser);

static const t_elm		g_el_int = {"int", sizeof(int), 0, 0, NULL,
							NULL, ft_int_setter, ft_vparse_int, NULL};
static const t_elm		g_el_uint = {"uint", sizeof(unsigned int), 0, 0, NULL,
							NULL, ft_uint_setter, ft_vparse_uint,
							(t_elm *)(t_ul)&g_el_int};
static const t_elm		g_el_long = {"long", sizeof(long), 0, 0, NULL,
							NULL, ft_int_setter, ft_vparse_int,
							(t_elm *)(t_ul)&g_el_uint};
static const t_elm		g_el_ulong = {"ulong", sizeof(unsigned long),
							0, 0, NULL,
							NULL, ft_uint_setter, ft_vparse_uint,
							(t_elm *)(t_ul)&g_el_long};
static const t_elm		g_el_float = {"float", sizeof(float), 0, 0, NULL,
							NULL, ft_float_setter, ft_vparse_float,
							(t_elm *)(t_ul)&g_el_ulong};
static const t_elm		g_el_double = {"double", sizeof(double), 0, 0, NULL,
							NULL, ft_float_setter, ft_vparse_float,
							(t_elm *)(t_ul)&g_el_float};
static const t_elm		g_el_longdouble = {"longdouble", sizeof(long double),
							0, 0, NULL,
							NULL, ft_float_setter, ft_vparse_float,
							(t_elm *)(t_ul)&g_el_double};
static const t_val		g_el_vecd_valtab[8] = {
							{VT_DOUBLE, 0, 0, 0, "x",
								(t_elm *)(t_ul)&g_el_float},
							{VT_DOUBLE, 0, 0, 0, "r",
								(t_elm *)(t_ul)&g_el_float},
							{VT_DOUBLE, sizeof(double), 1, 0, "y",
								(t_elm *)(t_ul)&g_el_float},
							{VT_DOUBLE, sizeof(double), 1, 0, "g",
								(t_elm *)(t_ul)&g_el_float},
							{VT_DOUBLE, sizeof(double) * 2, 2, 0, "z",
								(t_elm *)(t_ul)&g_el_float},
							{VT_DOUBLE, sizeof(double) * 2, 2, 0, "b",
								(t_elm *)(t_ul)&g_el_float},
							{VT_DOUBLE, sizeof(double) * 3, 3, 0, "w",
								(t_elm *)(t_ul)&g_el_float},
							{VT_DOUBLE, sizeof(double) * 3, 3, 0, "a",
								(t_elm *)(t_ul)&g_el_float}};
static const t_val		g_el_vecf_valtab[8] = {
							{VT_FLOAT, 0, 0, 0, "x",
								(t_elm *)(t_ul)&g_el_float},
							{VT_FLOAT, 0, 0, 0, "r",
								(t_elm *)(t_ul)&g_el_float},
							{VT_FLOAT, sizeof(float), 1, 0, "y",
								(t_elm *)(t_ul)&g_el_float},
							{VT_FLOAT, sizeof(float), 1, 0, "g",
								(t_elm *)(t_ul)&g_el_float},
							{VT_FLOAT, sizeof(float) * 2, 2, 0, "z",
								(t_elm *)(t_ul)&g_el_float},
							{VT_FLOAT, sizeof(float) * 2, 2, 0, "b",
								(t_elm *)(t_ul)&g_el_float},
							{VT_FLOAT, sizeof(float) * 3, 3, 0, "w",
								(t_elm *)(t_ul)&g_el_float},
							{VT_FLOAT, sizeof(float) * 3, 3, 0, "a",
								(t_elm *)(t_ul)&g_el_float}};
static const t_val		g_el_veci_valtab[8] = {
							{VT_INT, 0, 0, 0, "x", (t_elm *)(t_ul)&g_el_int},
							{VT_INT, 0, 0, 0, "r", (t_elm *)(t_ul)&g_el_int},
							{VT_INT, sizeof(int), 1, 0, "y",
								(t_elm *)(t_ul)&g_el_int},
							{VT_INT, sizeof(int), 1, 0, "g",
								(t_elm *)(t_ul)&g_el_int},
							{VT_INT, sizeof(int) * 2, 2, 0, "z",
								(t_elm *)(t_ul)&g_el_int},
							{VT_INT, sizeof(int) * 2, 2, 0, "b",
								(t_elm *)(t_ul)&g_el_int},
							{VT_INT, sizeof(int) * 3, 3, 0, "w",
								(t_elm *)(t_ul)&g_el_int},
							{VT_INT, sizeof(int) * 3, 3, 0, "a",
								(t_elm *)(t_ul)&g_el_int}};
static const t_val		g_el_vecui_valtab[8] = {
							{VT_UINT, 0, 0, 0, "x", (t_elm *)(t_ul)&g_el_uint},
							{VT_UINT, 0, 0, 0, "r", (t_elm *)(t_ul)&g_el_uint},
							{VT_UINT, sizeof(t_ui), 1, 0, "y",
								(t_elm *)(t_ul)&g_el_uint},
							{VT_UINT, sizeof(t_ui), 1, 0, "g",
								(t_elm *)(t_ul)&g_el_uint},
							{VT_UINT, sizeof(t_ui) * 2, 2, 0, "z",
								(t_elm *)(t_ul)&g_el_uint},
							{VT_UINT, sizeof(t_ui) * 2, 2, 0, "b",
								(t_elm *)(t_ul)&g_el_uint},
							{VT_UINT, sizeof(t_ui) * 3, 3, 0, "w",
								(t_elm *)(t_ul)&g_el_uint},
							{VT_UINT, sizeof(t_ui) * 3, 3, 0, "a",
								(t_elm *)(t_ul)&g_el_uint}};
static const t_val		g_el_vecl_valtab[8] = {
							{VT_LONG, 0, 0, 0, "x", (t_elm *)(t_ul)&g_el_long},
							{VT_LONG, 0, 0, 0, "r", (t_elm *)(t_ul)&g_el_long},
							{VT_LONG, sizeof(long), 1, 0, "y",
								(t_elm *)(t_ul)&g_el_long},
							{VT_LONG, sizeof(long), 1, 0, "g",
								(t_elm *)(t_ul)&g_el_long},
							{VT_LONG, sizeof(long) * 2, 2, 0, "z",
								(t_elm *)(t_ul)&g_el_long},
							{VT_LONG, sizeof(long) * 2, 2, 0, "b",
								(t_elm *)(t_ul)&g_el_long},
							{VT_LONG, sizeof(long) * 3, 3, 0, "w",
								(t_elm *)(t_ul)&g_el_long},
							{VT_LONG, sizeof(long) * 3, 3, 0, "a",
								(t_elm *)(t_ul)&g_el_long}};
static const t_elm		g_el_vec = {"vec", sizeof(double) * 4, 3, 8,
							(t_val *)(t_ul)g_el_vecd_valtab,
							NULL, NULL, ft_vparse_vec, NULL};
static const t_elm		g_el_vec2f = {"vec2f", sizeof(float) * 2, 1, 4,
							(t_val *)(t_ul)g_el_vecf_valtab,
							NULL, NULL, ft_vparse_vec,
							(t_elm *)(t_ul)&g_el_vec};
static const t_elm		g_el_vec3f = {"vec3f", sizeof(float) * 3, 2, 6,
							(t_val *)(t_ul)g_el_vecf_valtab,
							NULL, NULL, ft_vparse_vec,
							(t_elm *)(t_ul)&g_el_vec2f};
static const t_elm		g_el_vec4f = {"vec4f", sizeof(float) * 4, 3, 8,
							(t_val *)(t_ul)g_el_vecf_valtab,
							NULL, NULL, ft_vparse_vec,
							(t_elm *)(t_ul)&g_el_vec3f};
static const t_elm		g_el_vec2d = {"vec2f", sizeof(double) * 2, 1, 4,
							(t_val *)(t_ul)g_el_vecd_valtab,
							NULL, NULL, ft_vparse_vec,
							(t_elm *)(t_ul)&g_el_vec4f};
static const t_elm		g_el_vec3d = {"vec3f", sizeof(double) * 3, 2, 6,
							(t_val *)(t_ul)g_el_vecd_valtab,
							NULL, NULL, ft_vparse_vec,
							(t_elm *)(t_ul)&g_el_vec2d};
static const t_elm		g_el_vec4d = {"vec4f", sizeof(double) * 4, 3, 8,
							(t_val *)(t_ul)g_el_vecd_valtab,
							NULL, NULL, ft_vparse_vec,
							(t_elm *)(t_ul)&g_el_vec3d};
static const t_elm		g_el_vec2i = {"vec2i", sizeof(int) * 2, 1, 4,
							(t_val *)(t_ul)g_el_veci_valtab,
							NULL, NULL, ft_vparse_vec,
							(t_elm *)(t_ul)&g_el_vec4d};
static const t_elm		g_el_vec3i = {"vec3i", sizeof(int) * 3, 2, 6,
							(t_val *)(t_ul)g_el_veci_valtab,
							NULL, NULL, ft_vparse_vec,
							(t_elm *)(t_ul)&g_el_vec2i};
static const t_elm		g_el_vec4i = {"vec4i", sizeof(int) * 4, 3, 8,
							(t_val *)(t_ul)g_el_veci_valtab,
							NULL, NULL, ft_vparse_vec,
							(t_elm *)(t_ul)&g_el_vec3i};
static const t_elm		g_el_vec2ui = {"vec2ui", sizeof(int) * 2, 1, 4,
							(t_val *)(t_ul)g_el_vecui_valtab,
							NULL, NULL, ft_vparse_vec,
							(t_elm *)(t_ul)&g_el_vec4i};
static const t_elm		g_el_vec3ui = {"vec3ui", sizeof(int) * 3, 2, 6,
							(t_val *)(t_ul)g_el_vecui_valtab,
							NULL, NULL, ft_vparse_vec,
							(t_elm *)(t_ul)&g_el_vec2ui};
static const t_elm		g_el_vec4ui = {"vec4ui", sizeof(int) * 4, 3, 8,
							(t_val *)(t_ul)g_el_vecui_valtab,
							NULL, NULL, ft_vparse_vec,
							(t_elm *)(t_ul)&g_el_vec3ui};
static const t_elm		g_el_col = {"rgba", sizeof(int), 0, 0, NULL,
							NULL, NULL, ft_vparse_col,
							(t_elm *)(t_ul)&g_el_vec4ui};
static const t_elm		g_el_str = {"str", sizeof(char *), 0, 0, NULL,
							NULL, ft_str_setter, ft_vparse_str,
							(t_elm *)(t_ul)&g_el_col};
static const t_elm		g_el_vstr = {"vstr", sizeof(char *), 0, 0, NULL,
							NULL, ft_str_setter, ft_vparse_vstr,
							(t_elm *)(t_ul)&g_el_str};


#endif
