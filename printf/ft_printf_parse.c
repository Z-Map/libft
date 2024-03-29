/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 05:19:52 by qloubier          #+#    #+#             */
/*   Updated: 2017/06/08 01:42:48 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"

static void				init_pfarg(t_pfc *arg, t_pfb *b)
{
	arg->arg = 0;
	arg->b_len = 0;
	arg->minwidth = 0;
	arg->precision = 0;
	arg->flag = 0;
	arg->type = 0;
	arg->tmpb = b->tmp;
	arg->vlen = 1;
}

static inline void		convert_loop(int i, t_pfb *pfb)
{
	t_ui				j;
	t_pfc				arg;

	if (!(pfb->arg.flag & PFF_VECTOR_SET))
		ft_printf_convert(i, &(pfb->arg), pfb);
	else
	{
		j = 0;
		while (pfb->arg.vlen) {
			arg = ft_pfargvec(pfb->arg, j++);
			ft_printf_convert(i, &arg, pfb);
			pfb->arg.vlen--;
			if (pfb->arg.vlen)
				ft_printf_bwritec(pfb, ' ', 1);
		}
	}
}

const char				*ft_printf_parse(const char *fstr, t_pfb *pfb)
{
	const char			*c;
	int					i;

	i = 0;
	c = fstr;
	init_pfarg(&(pfb->arg), pfb);
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
		pfb->arg.flag |= PFF_CAPITAL;
	if (i == -1)
		i = ft_pfarg_spc(-(int)(*c), pfb->ap, &(pfb->arg));
	else
		i = g_pf_flag_tab[i].getarg(i, pfb->ap, &(pfb->arg));
	convert_loop(i, pfb);
	return (c + 1);
}
