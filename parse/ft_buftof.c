/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buftof.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: map <map@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 13:00:11 by map               #+#    #+#             */
/*   Updated: 2016/11/09 15:40:24 by map              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_parse.h"

float		ft_buftof(const char **str, int len, t_cmap cm)
{
	double	d;
	t_ul	*dr;
	char	sig;

	dr = (t_ul *)&d;
	sig = (**str == '-') ? 0 : 1;
	if (**str == '+' || **str == '-')
	{
		(*str)++;
		len--;
	}
	d = 0.0;
	if ((len >= 3))
	{
		if (!FT_SNCMP(*str, "inf", 3))
			*dr = FT_D_EXP;
		else if (!FT_SNCMP(*str, "nan", 3))
			*dr = FT_D_EXP + 1ul;
	}
	if (*dr)
		*str += 3;
	else
		*str = ft_parsef(*str, &d, cm, len);
	return ((float)(sig ? d : -d));
}
