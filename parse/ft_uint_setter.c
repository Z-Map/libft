/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uint_setter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 11:20:34 by qloubier          #+#    #+#             */
/*   Updated: 2017/05/12 11:23:14 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_parse.h"

void					ft_uint_setter(t_val *val, void *mem, void *v)
{
	void		*ptr;

	ptr = (void *)((t_ul)mem + val->offset);
	if (val->basetype & VS_SHORTSHORT)
		*(t_uc *)ptr = *(t_uc *)v;
	if (val->basetype & VS_SHORT)
		*(t_us *)ptr = *(t_us *)v;
	if (val->basetype & VS_LONG)
		*(t_ul *)ptr = *(t_ul *)v;
	else
		*(t_ui *)ptr = *(t_ui *)v;
}
