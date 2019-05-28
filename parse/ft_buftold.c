/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buftold.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 13:00:11 by map               #+#    #+#             */
/*   Updated: 2019/05/28 14:51:06 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_parse.h"

static int		is_special(long double *ld, const char **str)
{
	double	d;
	t_ul	*dr;

	dr = (t_ul *)&d;
	if (!FT_SNCMP(*str, "inf", 3))
		*dr = FT_D_EXP;
	else if (!FT_SNCMP(*str, "nan", 3))
		*dr = FT_D_EXP + 1ul;
	else
		return (0);
	*ld = (long double)d;
	return (1);
}

long double		ft_buftold(const char **str, int len, t_cmap cm)
{
	long double	d;
	char		sig;

	sig = (**str == '-') ? 0 : 1;
	if (**str == '+' || **str == '-')
	{
		(*str)++;
		len--;
	}
	d = (long double)0.0;
	if ((len >= 3) && is_special(&d, str))
		*str += 3;
	else
		*str = ft_parseld(*str, &d, cm, len);
	return (sig ? d : -d);
}
