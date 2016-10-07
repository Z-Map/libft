/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pfconv_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 19:54:57 by qloubier          #+#    #+#             */
/*   Updated: 2016/10/07 18:50:39 by map              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_format.h"

void			ft_pfconv_nbr(t_pfb *b, t_pfc *arg, size_t len)
{
	int			i;

	if ((intmax_t)(arg->arg) < 0)
	{
		len -= ft_printf_bwritec(b, '-', 1);
		arg->arg = (uintmax_t)(-(intmax_t)(arg->arg));
	}
	else if ((arg->flag & PFF_FORCE_SIGN))
		len -= ft_printf_bwritec(b, '+', 1);
	else if ((arg->flag & PFF_SPACE))
		len -= ft_printf_bwritec(b, ' ', 1);
	i = (int)len - (int)(arg->b_len);
	if (i > 0)
		ft_printf_bwritec(b, '0', (size_t)i);
	ft_printf_bwrite(b, arg->tmpb, (size_t)(arg->b_len));
}
