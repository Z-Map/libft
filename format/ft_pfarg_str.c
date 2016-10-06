/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pfarg_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 19:56:26 by qloubier          #+#    #+#             */
/*   Updated: 2016/10/06 04:36:36 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_format.h"

int			ft_pfarg_str(int cc, va_list ap, t_pfc *arg)
{
	if (arg->flag & (LONG | LONG_LONG | CAPITAL))
		arg->type = PFT_WSTR;
	else
		arg->type = PFT_STR;
	arg->arg = (uintmax_t)va_arg(ap, void *);
	return (cc);
}
