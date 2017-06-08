/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pfarg_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 19:56:26 by qloubier          #+#    #+#             */
/*   Updated: 2017/06/08 01:39:30 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"

int			ft_pfarg_ptr(int cc, va_list ap, t_pfc *arg)
{
	arg->type = PFT_HEXA;
	arg->flag &= PFF_NOSIZE;
	arg->flag |= PFF_PTRSET;
	arg->arg = (uintmax_t)va_arg(ap, void *);
	return (cc);
}
