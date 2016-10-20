/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pflen_float.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 02:43:11 by qloubier          #+#    #+#             */
/*   Updated: 2016/10/20 20:55:47 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"
#include "libft_math.h"

static double	float_trunc(const double *d)
{
	const unsigned long	ld = *((const unsigned long *)(d));
	unsigned long		l;

	l = (ld & FT_D_EXP) >> 52;
	if ((l > 1022) && (l < 1076))
	{
		l = FT_D_MAN >> (l - 1023);
		l = ld & (~l);
		return (*((double *)&l));
	}
	else if (l > 1076)
	{
		l = (ld & ~FT_D_MAN) | ((ld & FT_D_MAN) - 1);
		return (*((double *)&l));
	}
	return (0.0);
}

static double	float_round(const double *d)
{
	const unsigned long	ld = *((const unsigned long *)(d));
	unsigned long		l;
	double				od;

	l = (ld & FT_D_EXP) >> 52;
	if ((l > 1022) && (l < 1076))
	{
		l = FT_D_MAN >> (l - 1023);
		od = ((ld & (l & (~l >> 1))) ? 1.0 : 0.0);
		l = ld & (~l);
		return (*((double *)&l) + od);
	}
	else if (l > 1076)
		return (*d);
	return (0.0);
}

static double	float_mod(double *val, int base)
{
	double			d;

	d = *val;
	*val /= base;
	if ((d = d - (float_trunc(val) * base)) > base)
		d = float_mod(&d, base);
	return (d);
}

static char		*pf_floattobuf(char *buf, double d, t_ui prec, int *len)
{
	int			i;

	i = 0;
	if (d < 0)
		d = -d;
	if (prec)
	{
		*len -= 1;
		buf[*len] = '.';
		i = 1;
	}
	buf = ft_ujfillbuf((unsigned long)d, buf, len);
	*len += i;
	return (buf);
}

static char		*pf_float_biglen(char *buf, double d, t_ui prec, int *len)
{
	int			i;
	char		*c;

	c = buf + *len;
	i = 0;
	if (prec)
	{
		*(--c) = '.';
		i++;
	}
	while (d > 18446744073709551615.0 && i < *len)
	{
		*(--c) = '0' + (char)ft_firstfloatdigit(d);
		d /= 10.0;
		i++;
	}
	*len -= i;
	c = ft_ujfillbuf((unsigned long)d, buf, len);
	*len += i;
	return (c);
}

int				ft_pflen_float(t_pfc *arg)
{
	const double	d = *((double *)(&(arg->arg)));
	size_t			l;
	t_ui			len;

	len = FT_MX_FLOATLEN;
	l = (arg->arg & FT_D_EXP) >> 52;
	if (l > 1022)
	{
		if (l < 1076)
			arg->tmpb = pf_floattobuf(arg->tmpb, d, arg->precision, (int *)&len);
		else
			arg->tmpb = pf_float_biglen(arg->tmpb, d, arg->precision, (int *)&len);
	}
	else
		len = 2;
	arg->b_len = (int)len;
	len += arg->precision;
	(void)float_mod;
	(void)float_round;
	return ((int)len);
}
