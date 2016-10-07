/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 17:05:20 by qloubier          #+#    #+#             */
/*   Updated: 2016/10/07 20:01:25 by map              ###   ########.fr       */
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
	const char			*cmap;
	t_ui				base;
}						t_cmap;

static const char		*g_digitupmap = FT_DIGIT;
static const char		*g_digitlowmap = FT_DIGIT_L;
static const t_cmap		g_cmapup[] = {
	(t_cmap){FT_DIGIT, 2},
	(t_cmap){FT_DIGIT, 3},
	(t_cmap){FT_DIGIT, 4},
	(t_cmap){FT_DIGIT, 5},
	(t_cmap){FT_DIGIT, 6},
	(t_cmap){FT_DIGIT, 7},
	(t_cmap){FT_DIGIT, 8},
	(t_cmap){FT_DIGIT, 9},
	(t_cmap){FT_DIGIT, 10},
	(t_cmap){FT_DIGIT, 11},
	(t_cmap){FT_DIGIT, 12},
	(t_cmap){FT_DIGIT, 13},
	(t_cmap){FT_DIGIT, 14},
	(t_cmap){FT_DIGIT, 15},
	(t_cmap){FT_DIGIT, 16},
	};
static const t_cmap		g_cmaplow[] = {
	(t_cmap){FT_DIGIT_L, 2},
	(t_cmap){FT_DIGIT_L, 3},
	(t_cmap){FT_DIGIT_L, 4},
	(t_cmap){FT_DIGIT_L, 5},
	(t_cmap){FT_DIGIT_L, 6},
	(t_cmap){FT_DIGIT_L, 7},
	(t_cmap){FT_DIGIT_L, 8},
	(t_cmap){FT_DIGIT_L, 9},
	(t_cmap){FT_DIGIT_L, 10},
	(t_cmap){FT_DIGIT_L, 11},
	(t_cmap){FT_DIGIT_L, 12},
	(t_cmap){FT_DIGIT_L, 13},
	(t_cmap){FT_DIGIT_L, 14},
	(t_cmap){FT_DIGIT_L, 15},
	(t_cmap){FT_DIGIT_L, 16},
	};
#endif
