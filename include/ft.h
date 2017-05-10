/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 17:05:20 by qloubier          #+#    #+#             */
/*   Updated: 2017/05/09 21:22:11 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# ifdef FT_NATIVE_LIBC
#pragma GCC diagnostic ignored "-Wdisabled-macro-expansion"

#  define FT_MSET	memset
#  define FT_BZERO	bzero
#  define FT_MCPY	memcpy
#  define FT_MCCPY	memccpy
#  define FT_MMOVE	memmove
#  define FT_MCHR	memchr
#  define FT_MCMP	memcmp

#  define FT_SLEN	strlen
#  define FT_SCPY	strcpy
#  define FT_SNCPY	strncpy
#  define FT_SCAT	strcat
#  define FT_SNCAT	strncat
#  define FT_SCHR	strchr
#  define FT_SRCHR	strrchr
#  define FT_SCMP	strcmp
#  define FT_SNCMP	strncmp

# else
#  define FT_MSET	ft_memset
#  define FT_BZERO	ft_bzero
#  define FT_MCPY	ft_memcpy
#  define FT_MCCPY	ft_memccpy
#  define FT_MMOVE	ft_memmove
#  define FT_MCHR	ft_memchr
#  define FT_MCMP	ft_memcmp

#  define FT_SLEN	ft_strlen
#  define FT_SCPY	ft_strcpy
#  define FT_SNCPY	ft_strncpy
#  define FT_SCAT	ft_strcat
#  define FT_SNCAT	ft_strncat
#  define FT_SCHR	ft_strchr
#  define FT_SRCHR	ft_strrchr
#  define FT_SCMP	ft_strcmp
#  define FT_SNCMP	ft_strncmp

# endif

# define FT_DIGIT		"0123456789ABCDEF"
# define FT_DIGIT_L		"0123456789abcdef"
# define FT_DECIMAL_DIGIT "0123456789"
# define FT_DECIMAL_C	"+-0123456789"
# define FT_OCTAL_C		"01234567"
# define FT_HEXA_C		"+-0123456789ABCDEF"
# define FT_HEXA_C_L	"+-0123456789abcdef"

# define FT_WHITESPACE	" \t\n\r\v\f"

# define FT_MX_FLOATLEN	310

# define FT_CC			const char

typedef unsigned int			t_idx;
typedef unsigned char			t_uc;
typedef unsigned short			t_us;
typedef unsigned int			t_ui;
typedef unsigned long			t_ul;
typedef unsigned long			t_np;

typedef struct s_virtual_memory	t_vmem;
typedef struct s_ft_value		t_val;
typedef struct s_ft_element		t_elm;

typedef union					u_num_value
{
	char						c;
	unsigned char				uc;
	short						s;
	unsigned short				us;
	int							i;
	unsigned int				ui;
	long						l;
	unsigned long				ul;
	float						f;
	double						d;
	long double					ld;
}								t_numv;

typedef const struct			s_char_map
{
	t_ui						base;
	int							padding;
	const char					*cmap;
}								t_cmap;

static const char				g_digitupmap[] = FT_DIGIT;
static const char				g_digitlowmap[] = FT_DIGIT_L;
static const t_cmap				g_cmapup[] = {
	(t_cmap){2, 0, g_digitupmap},
	(t_cmap){3, 0, g_digitupmap},
	(t_cmap){4, 0, g_digitupmap},
	(t_cmap){5, 0, g_digitupmap},
	(t_cmap){6, 0, g_digitupmap},
	(t_cmap){7, 0, g_digitupmap},
	(t_cmap){8, 0, g_digitupmap},
	(t_cmap){9, 0, g_digitupmap},
	(t_cmap){10, 0, g_digitupmap},
	(t_cmap){11, 0, g_digitupmap},
	(t_cmap){12, 0, g_digitupmap},
	(t_cmap){13, 0, g_digitupmap},
	(t_cmap){14, 0, g_digitupmap},
	(t_cmap){15, 0, g_digitupmap},
	(t_cmap){16, 0, g_digitupmap},
};

static const  t_cmap			g_cmaplow[] = {
	(t_cmap){2, 0, g_digitlowmap},
	(t_cmap){3, 0, g_digitlowmap},
	(t_cmap){4, 0, g_digitlowmap},
	(t_cmap){5, 0, g_digitlowmap},
	(t_cmap){6, 0, g_digitlowmap},
	(t_cmap){7, 0, g_digitlowmap},
	(t_cmap){8, 0, g_digitlowmap},
	(t_cmap){9, 0, g_digitlowmap},
	(t_cmap){10, 0, g_digitlowmap},
	(t_cmap){11, 0, g_digitlowmap},
	(t_cmap){12, 0, g_digitlowmap},
	(t_cmap){13, 0, g_digitlowmap},
	(t_cmap){14, 0, g_digitlowmap},
	(t_cmap){15, 0, g_digitlowmap},
	(t_cmap){16, 0, g_digitlowmap},
};

#endif
