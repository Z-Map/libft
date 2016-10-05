/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pfconv_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 19:54:57 by qloubier          #+#    #+#             */
/*   Updated: 2016/10/05 20:16:54 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_format.h"

void			ft_pfconv_nbr(t_pfb *b, t_pfc *arg, size_t len)
{
	char		buf[40];
	int			i;
	uintmax_t	a;

	if ((intmax_t)(arg->arg) < 0)
	{
		len -= ft_printf_bwritec(b, '-', 1);
		arg->arg = (uintmax_t)(-(intmax_t)(arg->arg));
	}
	else if ((arg->flag & FORCE_SIGN))
		len -= ft_printf_bwritec(b, '+', 1);
	else if ((arg->flag & SPACE))
		len -= ft_printf_bwritec(b, ' ', 1);
	i = (int)len - (int)(arg->b_len);
	if (i > 0)
		ft_printf_bwritec(b, '0', (size_t)i);
	len = arg->b_len;
	a = arg->arg;
	while (len)
	{
		buf[--len] = '0' + (char)(a % 10);
		a /= 10;
	}
	ft_printf_bwrite(b, buf, (size_t)(arg->b_len));
}
