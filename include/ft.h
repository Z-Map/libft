/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 17:05:20 by qloubier          #+#    #+#             */
/*   Updated: 2017/01/28 16:50:25 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# define FT_DIGIT "0123456789ABCDEF"
# define FT_DIGIT_L "0123456789abcdef"

# define FT_MX_FLOATLEN 310

typedef unsigned int	t_idx;
typedef unsigned int	t_ui;
typedef unsigned long	t_ul;

typedef struct			s_char_map
{
	t_ui				base;
	int					padding;
	const char			*cmap;
}						t_cmap;

static const char		*g_digitupmap = FT_DIGIT;
static const char		*g_digitlowmap = FT_DIGIT_L;
static const t_cmap		g_cmapup[] = {
	(t_cmap){2, 0, FT_DIGIT},
	(t_cmap){3, 0, FT_DIGIT},
	(t_cmap){4, 0, FT_DIGIT},
	(t_cmap){5, 0, FT_DIGIT},
	(t_cmap){6, 0, FT_DIGIT},
	(t_cmap){7, 0, FT_DIGIT},
	(t_cmap){8, 0, FT_DIGIT},
	(t_cmap){9, 0, FT_DIGIT},
	(t_cmap){10, 0, FT_DIGIT},
	(t_cmap){11, 0, FT_DIGIT},
	(t_cmap){12, 0, FT_DIGIT},
	(t_cmap){13, 0, FT_DIGIT},
	(t_cmap){14, 0, FT_DIGIT},
	(t_cmap){15, 0, FT_DIGIT},
	(t_cmap){16, 0, FT_DIGIT},
};
static const t_cmap		g_cmaplow[] = {
	(t_cmap){2, 0, FT_DIGIT_L},
	(t_cmap){3, 0, FT_DIGIT_L},
	(t_cmap){4, 0, FT_DIGIT_L},
	(t_cmap){5, 0, FT_DIGIT_L},
	(t_cmap){6, 0, FT_DIGIT_L},
	(t_cmap){7, 0, FT_DIGIT_L},
	(t_cmap){8, 0, FT_DIGIT_L},
	(t_cmap){9, 0, FT_DIGIT_L},
	(t_cmap){10, 0, FT_DIGIT_L},
	(t_cmap){11, 0, FT_DIGIT_L},
	(t_cmap){12, 0, FT_DIGIT_L},
	(t_cmap){13, 0, FT_DIGIT_L},
	(t_cmap){14, 0, FT_DIGIT_L},
	(t_cmap){15, 0, FT_DIGIT_L},
	(t_cmap){16, 0, FT_DIGIT_L},
};
#endif
