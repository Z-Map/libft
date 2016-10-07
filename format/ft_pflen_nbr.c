/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pflen_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 02:43:11 by qloubier          #+#    #+#             */
/*   Updated: 2016/10/07 18:42:49 by map              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_format.h"

int					ft_pflen_nbr(t_pfc *arg)
{
	const intmax_t	n = (intmax_t)(arg->arg);
	const int		neg = (n < 0) ? 1 : 0;
	int				len;

	len = FT_MX_FLOATLEN;
	if ((arg->flag & PFF_PREC_SET) && (!arg->precision) && (!arg->arg))
		len = 0;
	else
		arg->tmpb = ft_ujfillbuf((uintmax_t)((neg) ? -n : n), arg->tmpb, &len);
	arg->b_len = len;
	if ((arg->flag & PFF_PREC_SET) && (len < arg->precision))
		len = arg->precision;
	if ((arg->flag & (PFF_FORCE_SIGN | PFF_SPACE)) || (neg))
		len++;
	if ((arg->flag & PFF_ZERO_FILL)
		&& !(arg->flag & (PFF_LEFT_ALIGN | PFF_PREC_SET))
		&& (len < arg->minwidth))
		len = arg->minwidth;
	return (len);
}
