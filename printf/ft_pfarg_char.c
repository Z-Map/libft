/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pfarg_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 19:56:26 by qloubier          #+#    #+#             */
/*   Updated: 2017/06/08 00:54:07 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"

int			ft_pfarg_char(int cc, va_list ap, t_pfc *arg)
{
	t_ui	*flg;

	flg = (unsigned int *)&(arg->flag);
	*flg &= ~((t_ui)PFF_VECTOR_SET);
	arg->type = PFT_CHAR;
	if (arg->flag & (PFF_LONG | PFF_LONG_LONG | PFF_CAPITAL))
		arg->arg = (uintmax_t)((wchar_t)(va_arg(ap, int)));
	else
		arg->arg = (uintmax_t)((char)(va_arg(ap, int)));
	return (cc);
}
