/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pflen_unbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 02:43:11 by qloubier          #+#    #+#             */
/*   Updated: 2016/10/05 03:14:48 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_format.h"

int		ft_pflen_unbr(t_pfc *arg)
{
	size_t	len;

	len = ft_ujdigitlen(arg->arg, arg->type);
	arg->b_len = (int)len;
	if ((arg->flag & PREC_SET) && (len < arg->precision))
		len = arg->precision;
	else if ((arg->flag & ALTERNTE) && (arg->type == 8))
		len += 1;
	else if ((arg->flag & ALTERNTE) && (arg->type == 16))
		len += 2;
	if ((arg->flag & ZERO_FILL) && !(arg->flag & (LEFT_ALIGN | PREC_SET))
		&& (len < arg->minwidth))
		len = arg->minwidth;
	return ((int)len);
}
