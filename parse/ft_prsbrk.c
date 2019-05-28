/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prsbrk.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 04:38:28 by qloubier          #+#    #+#             */
/*   Updated: 2019/05/28 14:58:22 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_parse.h"

size_t					ft_prsbrk(FT_CC **c, size_t *l, FT_CC *s, FT_CC **b)
{
	register size_t		tmp;

	tmp = (size_t)*c;
	*c = ft_strnpbrk(*c, s, *l);
	if (b)
		*b = (const char *)c;
	tmp = (size_t)*c - tmp;
	*l -= tmp;
	return (tmp);
}
