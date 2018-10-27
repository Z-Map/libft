/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pfarg_float.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 19:56:26 by qloubier          #+#    #+#             */
/*   Updated: 2017/06/08 00:59:34 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"

int			ft_pfarg_float(int cc, va_list ap, t_pfc *arg)
{
	double	*d;

	arg->type = PFT_FLOAT;
	d = (double *)(&(arg->arg));
	if (arg->flag & PFF_VECTOR_SET)
		arg->arg = (uintmax_t)va_arg(ap, void *);
	else
		*d = va_arg(ap, double);
	return (cc);
}
