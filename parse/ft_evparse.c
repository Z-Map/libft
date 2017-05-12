/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_evparse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 06:29:35 by qloubier          #+#    #+#             */
/*   Updated: 2017/05/12 09:38:28 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_parse.h"

int					ft_evparse(t_gparse p, t_elm *elm, void *mem, int *i)
{
	size_t			l;

	if (!p.key)
	{
		l = (size_t)*i;
		if (l < elm->vlen)
			return (elm->values[l].descriptor->parser(
				elm->values + (*i)++, mem, p));
		return (-1);
	}
	l = 0;
	while ((l < elm->vlen) && ft_strncmp(elm->values[l].name, p.key, p.k_len))
		l++;
	if (l < elm->vlen)
		return (elm->values[l].descriptor->parser(
			elm->values + l, mem, p));
	return (-1);
}
