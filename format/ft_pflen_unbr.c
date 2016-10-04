/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pflen_unbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 02:43:11 by qloubier          #+#    #+#             */
/*   Updated: 2016/10/04 15:41:51 by map              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_format.h"

int		ft_pflen_unbr(t_pfc *arg)
{
	size_t	len;

	len = ft_jdigitlen(arg->arg);
	arg->b_len = (int)len;
	if ((arg->flag & PREC_SET) && (len < arg->precision))
		len = arg->precision;
	if ((arg->flag & FORCE_SIGN) || (arg->arg & (1ul << 63)))
		len++;
	if ((arg->flag & ZERO_FILL) && !(arg->flag & LEFT_ALIGN)
		&& (len < arg->minwidth))
		len = arg->minwidth;
	return (0);
}
