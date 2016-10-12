/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pflen_float.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 02:43:11 by qloubier          #+#    #+#             */
/*   Updated: 2016/10/12 03:53:15 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"
#include "libft_math.h"

static double		float_trunc(const double *d)
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

static double		float_round(const double *d)
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

static double		float_mod(double *val, int base)
{
	double			d;

	d = *val;
	*val /= base;
	if ((d = d - (float_trunc(val) * base)) > base)
		d = float_mod(&d, base);
	return (d);
}

int					ft_pflen_float(t_pfc *arg)
{
	size_t	len;

	len = ft_floatlen(*((double *)(&(arg->arg))), arg->precision);
	(void)float_mod;
	(void)float_round;
	return ((int)len);
}
