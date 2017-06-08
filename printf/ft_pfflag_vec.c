/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pfflag_vec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 00:19:05 by qloubier          #+#    #+#             */
/*   Updated: 2017/06/08 01:09:10 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"

const char				*ft_pfflag_vec(const char *c, t_pfb *b)
{
	int				i;

	i = 0;
	if (c[1] == '*')
	{
		i = va_arg(b->ap, int);
		b->arg.vlen = (t_ui)((i < 0) ? 0 : i);
		c += 2;
	}
	else
		c = ft_parse_digit(c + 1, &(b->arg.vlen));
	if (i >= 0)
		b->arg.flag |= PFF_VECTOR_SET;
	return (c);
}
