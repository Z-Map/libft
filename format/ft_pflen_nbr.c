/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pflen_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 02:43:11 by qloubier          #+#    #+#             */
/*   Updated: 2016/10/05 16:54:45 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_format.h"

int			ft_pflen_nbr(t_pfc *arg)
{
	size_t	len;

	len = ft_jdigitlen((intmax_t)(arg->arg));
	if ((arg->flag & PREC_SET) && (!arg->precision) && (!arg->arg))
		len = 0;
	arg->b_len = (int)len;
	if ((arg->flag & PREC_SET) && (len < arg->precision))
		len = arg->precision;
	if ((arg->flag & (FORCE_SIGN | SPACE)) || (arg->arg & (1ul << 63)))
		len++;
	if ((arg->flag & ZERO_FILL) && !(arg->flag & (LEFT_ALIGN | PREC_SET))
		&& (len < arg->minwidth))
		len = arg->minwidth;
	return ((int)len);
}
