/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pfconv_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 19:44:05 by qloubier          #+#    #+#             */
/*   Updated: 2016/10/05 04:16:43 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_format.h"

void			ft_pfconv_str(t_pfb *b, t_pfc *arg, size_t len)
{
	if (arg->arg)
	{
		if (arg->type == PFT_STR)
			ft_printf_bwrite(b, (char *)(arg->arg), len);
		else
			ft_printf_bwrite(b, (char *)(arg->arg), len);
	}
	else
		ft_printf_bwrite(b, g_pf_nullstr, len);
}
