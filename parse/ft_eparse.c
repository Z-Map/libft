/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eparse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 05:32:56 by qloubier          #+#    #+#             */
/*   Updated: 2017/05/10 19:45:39 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_parse.h"


int				ft_eparse(t_gparse parser, t_elm *elm, void *mem)
{
	t_gparse	p;
	size_t		blen;
	int			i;

	p = parser;
	blen = parser.v_len;
	while (blen)
	{
		p.b_len = (size_t)ft_strncspn(p.cursor, p.end, blen);
		i = ft_strncspn(p.cursor, p.separator, p.b_len);
		if (i < (int)p.b_len)

		blen -= p.b_len;
		if (blen)
		{
			i = ft_strnspn(p.buffer + p.b_len, p.end, blen);
			p.cursor = (const char *)((size_t)p.buffer + p.b_len + (size_t)i);
			blen -= (size_t)i;
		}
	}
	return ()
}
