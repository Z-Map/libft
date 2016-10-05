/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pflen_unbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 02:43:11 by qloubier          #+#    #+#             */
/*   Updated: 2016/10/05 21:33:34 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_format.h"

int		ft_pflen_unbr(t_pfc *arg)
{
	size_t	len;

	len = ft_ujdigitlen(arg->arg, arg->type);
	if ((arg->flag & PREC_SET) && (!arg->precision) && (!arg->arg))
		len = 0;
	arg->b_len = (int)len;
	if ((arg->flag & PREC_SET) && (len < arg->precision))
		len = arg->precision;
	else if ((arg->flag & ALTERNTE) && (arg->type == PFT_OCT)
		&& (arg->arg || !len))
		len += 1;
	if ((arg->flag & PFF_PTR) ||
		((arg->flag & ALTERNTE) && (arg->type == PFT_HEXA) && arg->arg))
		len += 2;
	if ((arg->flag & ZERO_FILL) && !(arg->flag & (LEFT_ALIGN | PREC_SET))
		&& (len < arg->minwidth))
		len = arg->minwidth;
	return ((int)len);
}
