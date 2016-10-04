/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pfconv_unbr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 19:54:57 by qloubier          #+#    #+#             */
/*   Updated: 2016/10/04 22:57:20 by map              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_format.h"

void			ft_pfconv_unbr(t_pfb *b, t_pfc *arg, size_t len)
{
	char		buf[40];
	int			i;
	uintmax_t	a;

	if (((arg->flag & ALTERNTE) && (arg->type == PFT_HEXA))
		|| (arg->type == PFT_PTR))
		ft_printf_bwrite(b, "0x", 2);
	i = (int)len - (int)(b->arg.b_len);
	if (i > 0)
		ft_printf_bwritec(b, '0', (size_t)i);
	len = b->arg.b_len;
	a = b->arg.arg;
	while (len)
	{
		buf[--len] = '0' + (char)(a % 10);
		a /= 10;
	}
	ft_printf_bwrite(b, buf, (size_t)(b->arg.b_len));
}
