/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pfconv_unbr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 19:54:57 by qloubier          #+#    #+#             */
/*   Updated: 2016/10/05 21:21:01 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_format.h"

void			ft_pfconv_unbr(t_pfb *b, t_pfc *arg, size_t len)
{
	const char	*cmap = (arg->flag & PFF_CAPITAL) ? FT_DIGIT : FT_DIGIT_L;
	char		buf[40];
	int			i;
	uintmax_t	a;

	if ((arg->type == PFT_HEXA) && (arg->flag & PFF_ALTERNTE)
		&& (arg->arg || arg->flag & PFF_PTR))
		len -= ft_printf_bwrite(b, ((arg->flag & PFF_CAPITAL) ? "0X" : "0x"), 2);
	i = (int)len - (int)(arg->b_len);
	if (i > 0)
		ft_printf_bwritec(b, '0', (size_t)i);
	len = arg->b_len;
	a = arg->arg;
	while (len)
	{
		buf[--len] = cmap[(int)(a % arg->type)];
		a /= arg->type;
	}
	ft_printf_bwrite(b, buf, (size_t)(arg->b_len));
}
