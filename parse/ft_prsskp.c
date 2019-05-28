/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prsskp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 04:38:33 by qloubier          #+#    #+#             */
/*   Updated: 2019/05/28 14:58:36 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_parse.h"

size_t					ft_prsskp(FT_CC **c, size_t *l, FT_CC *s, FT_CC **b)
{
	register size_t		tmp;

	if (!*l)
		return (0);
	tmp = (size_t)*c;
	*c = ft_strnpskp(*c, s, *l);
	if (b)
		*b = (const char *)c;
	tmp = (size_t)*c - tmp;
	*l -= tmp;
	return (tmp);
}
