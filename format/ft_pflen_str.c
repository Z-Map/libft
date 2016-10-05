/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pflen_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 02:43:11 by qloubier          #+#    #+#             */
/*   Updated: 2016/10/05 20:53:24 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft_format.h"

int		ft_pflen_str(t_pfc *arg)
{
	size_t	len;

	if (arg->arg)
	{
		if (arg->type == PFT_WSTR)
			len = ft_wstrlen((wchar_t *)(arg->arg)) * sizeof(wchar_t);
		else
			len = ft_strlen((char *)(arg->arg));
	}
	else
		len = 6;
	if ((arg->flag & PREC_SET) && (len > arg->precision))
		len = arg->precision;
	arg->b_len = (int)len;
	if ((arg->flag & ZERO_FILL) && !(arg->flag & LEFT_ALIGN)
		&& (len < arg->minwidth))
		len = arg->minwidth;
	return (len);
}
