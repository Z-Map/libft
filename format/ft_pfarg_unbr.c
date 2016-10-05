/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pfarg_unbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 19:56:26 by qloubier          #+#    #+#             */
/*   Updated: 2016/10/05 22:16:41 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_format.h"

int			ft_pfarg_unbr(int cc, va_list ap, t_pfc *arg)
{
	if (arg->flag & INTMAX)
		arg->arg = va_arg(ap, uintmax_t);
	else if (arg->flag & SIZE_T)
		arg->arg = va_arg(ap, size_t);
	else if (arg->flag & LONG_LONG)
		arg->arg = va_arg(ap, unsigned long long);
	else if ((arg->flag & LONG) ||
		((arg->flag & CAPITAL) && (arg->type != PFT_HEXA)))
		arg->arg = va_arg(ap, unsigned long);
	else if (arg->flag & SHORT)
		arg->arg = (uintmax_t)(va_arg(ap, unsigned int) & PF_USHORT);
	else if (arg->flag & SHORT_SHORT)
		arg->arg = (uintmax_t)(va_arg(ap, unsigned int) & PF_UCHAR);
	else
		arg->arg = va_arg(ap, unsigned int);
	if (!arg->type)
		arg->type = PFT_UINT;
	return (cc);
}
