/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pfconv_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 19:54:57 by qloubier          #+#    #+#             */
/*   Updated: 2016/10/04 21:52:40 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_format.h"

void			ft_pfconv_nbr(t_pfb *b, size_t len)
{
	char		buf[40];
	int			i;
	uintmax_t	a;

	if ((intmax_t)(b->arg.arg) > 0)
	{
		ft_printf_bwritec(b, '-', 1);
		b->arg.arg = (uintmax_t)(-(intmax_t)(b->arg.arg));
	}
	else if (b->arg.flag & FORCE_SIGN)
		ft_printf_bwritec(b, '+', 1);
	else if (b->arg.flag & SPACE)
		ft_printf_bwritec(b, ' ', 1);
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
