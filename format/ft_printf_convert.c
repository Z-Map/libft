/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_convert.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 05:17:31 by qloubier          #+#    #+#             */
/*   Updated: 2016/10/01 02:23:41 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_format.h"

int				ft_printf_convert(int tid, t_pfc *arg, t_pfb *pfb)
{
	char		gugu[3];

	gugu[0] = '[';
	gugu[1] = PF_TYPE_STR[tid];
	gugu[2] = ']';
	arg->b_len = 10;
	ft_printf_bwrite(pfb, gugu, 3);
	return (0);
}
