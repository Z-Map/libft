/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 05:19:52 by qloubier          #+#    #+#             */
/*   Updated: 2016/09/30 08:04:34 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_format.h"

static void				init_pfarg(t_pfc *arg)
{
	arg->arg = 0;
	arg->b_len = 0;
	arg->minwidth = 0;
	arg->precision = 0;
	arg->flag = 0;
	arg->type = 0;
}

const char				*ft_printf_parse(const char *fstr, t_pfb *pfb)
{
	const char			*c;
	int					i;

	c = fstr;
	init_pfarg(&(pfb->arg));
	while ((*c) && ((i = ft_stridx(PF_TYPE_STR, (int)(*c))) == -1))
	{
		if ((i = ft_stridx(PF_FLAG_STR, (int)(*c))) >= 0)
			c = g_pf_flag_tab[i].flag(c, pfb);
	}
	if (i != -1)
		
	return (c);
}
