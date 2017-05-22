/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsef.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: map <map@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 13:19:18 by map               #+#    #+#             */
/*   Updated: 2017/05/22 03:46:56 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_parse.h"

const char	*ft_parsef(const char *str, double *num, t_cmap cm, int len)
{
	register int	i;
	double			d;
	double			n;

	n = 0.0;
	i = 0;
	while ((*str) && (len-- > 0) &&
		((i = ft_strnidx(cm.cmap, (int)(*str), (size_t)cm.base)) >= 0))
	{
		n = (n * (double)cm.base) + (double)(i);
		str++;
	}
	if ((*str == '.') && (len > 0))
	{
		str++;
		d = (double)cm.base;
		while ((*str) && (len-- > 0) &&
			((i = ft_strnidx(cm.cmap, (int)(*str), (size_t)cm.base)) >= 0))
		{
			n += (double)(i) / d;
			d *= (double)cm.base;
			str++;
		}
	}
	*num = n;
	return (str);
}
