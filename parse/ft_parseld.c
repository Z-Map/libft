/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parseld.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: map <map@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 13:19:18 by map               #+#    #+#             */
/*   Updated: 2017/05/22 03:26:22 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_parse.h"

static inline const char	*parse_frac(const char *str, long double *num,
								t_cmap cm, int len)
{
	register int	i;
	long double		d;
	long double		n;

	d = (long double)cm.base;
	n = (long double)0.0;
	while ((*str) && (len-- > 0) &&
		((i = ft_strnidx(cm.cmap, (int)(*str), (size_t)cm.base)) >= 0))
	{
		n += (long double)i / d;
		d *= (long double)cm.base;
		str++;
	}
	*num = n + *num;
	return (str);
}

const char					*ft_parseld(const char *str, long double *num,
								t_cmap cm, int len)
{
	register int	i;

	*num = (long double)0.0;
	i = 0;
	while ((*str) && (len-- > 0) &&
		((i = ft_strnidx(cm.cmap, (int)(*str), (size_t)cm.base)) >= 0))
	{
		*num = (*num * (long double)cm.base) + (long double)(i);
		str++;
	}
	if ((*str == '.') && (len > 0))
		str = parse_frac(str + 1, num, cm, len);
	return (str);
}
