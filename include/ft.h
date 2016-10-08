/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 17:05:20 by qloubier          #+#    #+#             */
/*   Updated: 2016/10/08 02:55:46 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# define FT_DIGIT "0123456789ABCDEF"
# define FT_DIGIT_L "0123456789abcdef"

typedef unsigned int	t_idx;
typedef unsigned int	t_ui;

typedef struct			s_char_map
{
	t_ui				base;
	const char			*cmap;
}						t_cmap;

static const char		*g_digitupmap = FT_DIGIT;
static const char		*g_digitlowmap = FT_DIGIT_L;
static const t_cmap		g_cmapup[] = {
	(t_cmap){2, FT_DIGIT},
	(t_cmap){3, FT_DIGIT},
	(t_cmap){4, FT_DIGIT},
	(t_cmap){5, FT_DIGIT},
	(t_cmap){6, FT_DIGIT},
	(t_cmap){7, FT_DIGIT},
	(t_cmap){8, FT_DIGIT},
	(t_cmap){9, FT_DIGIT},
	(t_cmap){10, FT_DIGIT},
	(t_cmap){11, FT_DIGIT},
	(t_cmap){12, FT_DIGIT},
	(t_cmap){13, FT_DIGIT},
	(t_cmap){14, FT_DIGIT},
	(t_cmap){15, FT_DIGIT},
	(t_cmap){16, FT_DIGIT},
	};
static const t_cmap		g_cmaplow[] = {
	(t_cmap){2, FT_DIGIT_L},
	(t_cmap){3, FT_DIGIT_L},
	(t_cmap){4, FT_DIGIT_L},
	(t_cmap){5, FT_DIGIT_L},
	(t_cmap){6, FT_DIGIT_L},
	(t_cmap){7, FT_DIGIT_L},
	(t_cmap){8, FT_DIGIT_L},
	(t_cmap){9, FT_DIGIT_L},
	(t_cmap){10, FT_DIGIT_L},
	(t_cmap){11, FT_DIGIT_L},
	(t_cmap){12, FT_DIGIT_L},
	(t_cmap){13, FT_DIGIT_L},
	(t_cmap){14, FT_DIGIT_L},
	(t_cmap){15, FT_DIGIT_L},
	(t_cmap){16, FT_DIGIT_L},
	};
#endif
