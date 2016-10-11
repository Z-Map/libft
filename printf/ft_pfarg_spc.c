/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pfarg_spc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 19:56:26 by qloubier          #+#    #+#             */
/*   Updated: 2016/10/05 17:54:34 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"

int			ft_pfarg_spc(int cc, va_list ap, t_pfc *arg)
{
	(void)ap;
	arg->type = PFT_SPECHAR;
	if (cc < 0)
	{
		arg->arg = (uintmax_t)((char)(-cc));
		return (17);
	}
	arg->arg = (uintmax_t)('%');
	return (cc);
}
