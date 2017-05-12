/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float_setter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 10:22:03 by qloubier          #+#    #+#             */
/*   Updated: 2017/05/12 10:37:32 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_parse.h"

void			ft_float_setter(t_val *val, void *mem, void *v)
{
	void		*ptr;

	ptr = (void *)((t_ul)mem + val->offset);
	if (val->basetype & VS_LONGLONG)
		*(long double *)ptr = *(long double *)v;
	if (val->basetype & VS_LONG)
		*(double *)ptr = *(double *)v;
	else
		*(float *)ptr = *(float *)v;
}
