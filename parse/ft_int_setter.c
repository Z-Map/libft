/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_setter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 11:20:34 by qloubier          #+#    #+#             */
/*   Updated: 2017/05/12 11:23:52 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_parse.h"

void					ft_int_setter(t_val *val, void *mem, void *v)
{
	void		*ptr;

	ptr = (void *)((t_ul)mem + val->offset);
	if (val->basetype & VS_SHORTSHORT)
		*(char *)ptr = *(char *)v;
	if (val->basetype & VS_SHORT)
		*(short *)ptr = *(short *)v;
	if (val->basetype & VS_LONG)
		*(long *)ptr = *(long *)v;
	else
		*(int *)ptr = *(int *)v;
}
