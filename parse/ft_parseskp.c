/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parseskp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 04:38:33 by qloubier          #+#    #+#             */
/*   Updated: 2017/05/12 04:55:50 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_parse.h"

size_t					ft_parseskp(FT_CC **c, size_t *l, FT_CC *s, FT_CC **b)
{
	register size_t		tmp;

	tmp = (size_t)*c;
	*c = ft_strnpskp(*c, s, *l);
	if (b)
		*b = (const char *)c;
	 tmp = (size_t)*c - tmp;
	*l -= tmp;
	return (tmp);
}
