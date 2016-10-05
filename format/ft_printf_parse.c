/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 05:19:52 by qloubier          #+#    #+#             */
/*   Updated: 2016/10/05 21:14:42 by qloubier         ###   ########.fr       */
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
		else if (ft_isdigit((int)(*c)))
			c = ft_pfflag_width(c, pfb);
		else
			break ;
	}
	if (!*c)
		return (c);
	if (ft_isupper((int)(*c)))
		pfb->arg.flag |= CAPITAL;
	if (i == -1)
		i = ft_pfarg_spc(-(int)(*c), pfb->ap, &(pfb->arg));
	else
		i = g_pf_flag_tab[i].getarg(i, pfb->ap, &(pfb->arg));
	ft_printf_convert(i, &(pfb->arg), pfb);
	return (c + 1);
}
