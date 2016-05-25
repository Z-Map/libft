/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_floatlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/05 01:18:17 by qloubier          #+#    #+#             */
/*   Updated: 2016/05/22 07:29:44 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_format.h"

size_t		ft_floatlen(double i, t_ui prec)
{
	register size_t	len;

	len = (i < 0) ? 3 : 2;
	i = (i < 0) ? -i : i;
	while ((i > 10) && ((i /= 10) <= 10))
		++len;
	prec += (t_ui)len;
	while ((i -= (int)i) && (len < prec))
	{
		i *= 10;
		++len;
	}
	return (len);
}
