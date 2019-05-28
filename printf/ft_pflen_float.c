/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pflen_float.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 02:43:11 by qloubier          #+#    #+#             */
/*   Updated: 2019/05/28 15:09:16 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"

static char		*pf_float_spe(t_pfc *arg, double d, int *len)
{
	const t_ul		*p = (t_ul *)(&d);
	unsigned long	l;
	char			*c;

	l = *p & FT_D_MAN;
	c = arg->tmpb + *len - 4;
	if (l)
		ft_memcpy(c, "NaN", 4);
	else
		ft_memcpy(c, "inf", 4);
	arg->precision = 0;
	*len = 3;
	return (c);
}

static char		*pf_floattobuf(t_pfc *arg, double d, int *len)
{
	const t_ul		*p = (t_ul *)(&d);
	int				i;
	unsigned long	l;
	char			*c;

	i = 0;
	if (d < 0.0)
		d = -d;
	if (arg->precision || (arg->flag & PFF_ALTERNTE))
	{
		*len -= 1;
		arg->tmpb[*len] = '.';
		i = 1;
	}
	l = (unsigned long)d;
	c = ft_ujfillbuf(l, arg->tmpb, len);
	d = (d - (double)l);
	arg->arg = (uintmax_t)(*p);
	*len += i;
	return (c);
}

static char		*pf_float_biglen(t_pfc *arg, double d, int *len)
{
	int			i;
	char		*c;

	c = arg->tmpb + *len;
	i = 0;
	if (arg->precision || (arg->flag & PFF_ALTERNTE))
	{
		*(--c) = '.';
		i++;
	}
	while ((d > 18446744073709551615.0) && (i < *len))
	{
		*(--c) = '0' + (char)ft_lastfdigit(d);
		d /= 10.0;
		i++;
	}
	*len -= i;
	c = ft_ujfillbuf((unsigned long)d, arg->tmpb, len);
	arg->arg = 0.0;
	*len += i;
	return (c);
}

int				ft_pflen_float(t_pfc *arg)
{
	const double	*p = (double *)(&(arg->arg));
	const double	d = *p;
	size_t			l;
	t_ui			len;

	len = FT_MX_FLOATLEN;
	if (!(arg->flag & PFF_PREC_SET))
		arg->precision = 6;
	l = (arg->arg & FT_D_EXP) >> 52;
	if (l == 0x7FF)
		arg->tmpb = pf_float_spe(arg, d, (int *)&len);
	else if (l > 1075)
		arg->tmpb = pf_float_biglen(arg, d, (int *)&len);
	else
		arg->tmpb = pf_floattobuf(arg, d, (int *)&len);
	if ((d < 0.0) || (arg->flag & (PFF_FORCE_SIGN | PFF_SPACE)))
	{
		*(--(arg->tmpb)) = (arg->flag & PFF_FORCE_SIGN) ? '+' : ' ';
		if (d < 0.0)
			*(arg->tmpb) = '-';
		++len;
	}
	arg->b_len = (int)len;
	len += arg->precision;
	return ((int)len);
}
