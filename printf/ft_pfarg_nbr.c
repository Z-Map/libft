/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pfarg_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 19:56:26 by qloubier          #+#    #+#             */
/*   Updated: 2017/06/08 01:00:22 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"

int			ft_pfarg_nbr(int cc, va_list ap, t_pfc *arg)
{
	if (arg->flag & PFF_VECTOR_SET)
		arg->arg = (uintmax_t)va_arg(ap, void *);
	else if (arg->flag & PFF_INTMAX)
		arg->arg = (uintmax_t)(va_arg(ap, intmax_t));
	else if (arg->flag & PFF_SIZE_T)
		arg->arg = (uintmax_t)(intmax_t)(va_arg(ap, size_t));
	else if (arg->flag & PFF_LONG_LONG)
		arg->arg = (uintmax_t)(intmax_t)(va_arg(ap, long long));
	else if (arg->flag & (PFF_LONG | PFF_CAPITAL))
		arg->arg = (uintmax_t)(intmax_t)(va_arg(ap, long));
	else if (arg->flag & PFF_SHORT)
		arg->arg = (uintmax_t)(intmax_t)(short)(va_arg(ap, int));
	else if (arg->flag & PFF_SHORT_SHORT)
		arg->arg = (uintmax_t)(intmax_t)(char)(va_arg(ap, int));
	else
		arg->arg = (uintmax_t)(intmax_t)(va_arg(ap, int));
	if (!arg->type)
		arg->type = PFT_INT;
	return (cc);
}
