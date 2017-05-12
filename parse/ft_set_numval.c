/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_numval.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 20:18:01 by qloubier          #+#    #+#             */
/*   Updated: 2017/05/12 10:41:53 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_parse.h"

static void			set_float_type(t_val *val, void *mem, t_numv num)
{
	float			f;
	double			d;

	if (val->basetype & VS_LONGLONG)
		val->descriptor->setter(val, mem, &num.ld);
	else if (val->basetype & VS_LONG)
	{
		d = (double)num.ld;
		val->descriptor->setter(val, mem, &d);
	}
	else
	{
		f = (float)num.ld;
		val->descriptor->setter(val, mem, &f);
	}
}

static void			set_signed_type(t_val *val, void *mem, t_numv num, int s)
{
	long			l;

	if (val->basetype & VS_SHORTSHORT)
		*(t_uc *)(&l) = (num.uc & ~FT_SM_C) | ((unsigned)(char)s & FT_SM_C);
	if (val->basetype & VS_SHORT)
		*(t_us *)(&l) = (num.us & ~FT_SM_S) | ((unsigned)(short)s & FT_SM_S);
	if (val->basetype & VS_LONG)
		*(t_ul *)(&l) = (num.ul & ~FT_SM_L) | ((unsigned)(long)s & FT_SM_L);
	else
		*(t_ui *)(&l) = (num.ui & ~FT_SM_I) | ((unsigned)(int)s & FT_SM_I);
	val->descriptor->setter(val, mem, &l);
}

static void			set_unsigned_type(t_val *val, void *mem, t_numv num)
{
	unsigned long	ul;

	if (val->basetype & VS_SHORTSHORT)
		*(t_uc *)(&ul) = num.uc;
	if (val->basetype & VS_SHORT)
		*(t_us *)(&ul) = num.us;
	if (val->basetype & VS_LONG)
		*(t_ul *)(&ul) = num.ul;
	else
		*(t_ui *)(&ul) = num.ui;
	val->descriptor->setter(val, mem, &ul);
}

void			ft_set_numval(t_val *val, void *mem, t_numv num, int s)
{
	if ((val->basetype & VM_TYPE) == VT_FLOAT)
		set_float_type(val, mem, num);
	else if (((val->basetype & VM_TYPE) == VT_INT)
		&& (val->basetype & VF_UNSIGNED))
		set_unsigned_type(val, mem, num);
	else if ((val->basetype & VM_TYPE) == VT_INT)
		set_signed_type(val, mem, num, s);
}
