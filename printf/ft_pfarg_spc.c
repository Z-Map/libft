/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pfarg_spc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 19:56:26 by qloubier          #+#    #+#             */
/*   Updated: 2017/06/08 01:01:46 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"

int			ft_pfarg_spc(int cc, va_list ap, t_pfc *arg)
{
	(void)ap;
	*((int *)&(arg->flag)) &= ~PFF_VECTOR_SET;
	arg->type = PFT_SPECHAR;
	if (cc < 0)
	{
		arg->arg = (uintmax_t)((char)(-cc));
		return (11);
	}
	arg->arg = (uintmax_t)('%');
	return (cc);
}
