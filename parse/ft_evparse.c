/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_evparse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 06:29:35 by qloubier          #+#    #+#             */
/*   Updated: 2017/05/18 12:50:50 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_parse.h"

#include "libft_printf.h"

int					ft_evparse(t_gparse p, t_elm *elm, void *mem, int *i)
{
	size_t			l;
	int				r;

	r = -2;
	l = ~0ul;
	while (++l < elm->vlen)
		if (((p.key) && !ft_strncmp(p.key, elm->values[l].name, p.k_len))
			|| ((!p.key) && (elm->values[l].idx == *i)))
			break;
	if (l < elm->vlen)
	{
		r = elm->values[l].descriptor->parser(elm->values + l, mem, p);
		if (r >= 0)
		{
			*i += (!p.key) ? 1 : 0;
			if (p.cfgbits)
				ft_prssetcfgbit(p, elm->values[l].idx);
		}
	}
	return (r);
}
