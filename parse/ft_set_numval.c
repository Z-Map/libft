/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_numval.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 20:18:01 by qloubier          #+#    #+#             */
/*   Updated: 2017/05/09 21:26:25 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_parse.h"

void			ft_set_numval(t_val *val, void *mem, t_numv num, int s)
{
	void		*ptr;

	ptr = (t_ul)mem + val->offset;
	if (val->basetype & VM_TYPE == VT_FLOAT)
	{
		if (val->basetype & VS_LONGLONG)
			*(long double *)ptr = num.ld;
		if (val->basetype & VS_LONG)
			*(double *)ptr = (double)num.ld;
		else
			*(float *)ptr = (float)num.ld;
	}
	else if (val->basetype & VM_TYPE == VT_INT)
	{
		if (val->basetype & VS_SHORTSHORT)
			*(t_uc *)ptr = (num.uc & ~FT_SM_C) | ((unsigned)(char)s & FT_SM_C);
		if (val->basetype & VS_SHORT)
			*(t_us *)ptr = (num.us & ~FT_SM_S) | ((unsigned)(short)s & FT_SM_S);
		if (val->basetype & VS_LONG)
			*(t_ul *)ptr = (num.ul & ~FT_SM_L) | ((unsigned)(long)s & FT_SM_L);
		else
			*(t_ui *)ptr = (num.ui & ~FT_SM_I) | ((unsigned)(int)s & FT_SM_I);
	}
}
