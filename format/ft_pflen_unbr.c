/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pflen_unbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 02:43:11 by qloubier          #+#    #+#             */
/*   Updated: 2016/10/07 19:00:38 by map              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_format.h"

int		ft_pflen_unbr(t_pfc *arg)
{
	int				len;

	len = FT_MX_FLOATLEN;
	if ((arg->flag & PFF_PREC_SET) && (!arg->precision) && (!arg->arg))
		len = 0;
	else
		arg->tmpb = ft_ujfillbufbase(arg->arg, arg->type, arg->tmpb, &len);
	arg->b_len = len;
	if ((arg->flag & PFF_PREC_SET) && (len < arg->precision))
		len = arg->precision;
	else if ((arg->flag & PFF_ALTERNTE) && (arg->type == PFT_OCT)
		&& (arg->arg || !len))
		len += 1;
	if ((arg->flag & PFF_PTR) ||
		((arg->flag & PFF_ALTERNTE) && (arg->type == PFT_HEXA) && arg->arg))
		len += 2;
	if ((arg->flag & PFF_ZERO_FILL) && !(arg->flag & (PFF_LEFT_ALIGN | PFF_PREC_SET))
		&& (len < arg->minwidth))
		len = arg->minwidth;
	return ((int)len);
}
