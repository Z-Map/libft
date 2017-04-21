/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ivm_splitptr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 17:31:15 by qloubier          #+#    #+#             */
/*   Updated: 2017/04/21 20:36:09 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intern_vmem.h"

t_vmps			*ft_ivm_splitptr(t_vmps *vptr, size_t size, t_vmem *vm)
{
	t_vmps		*p;

	size += sizeof(t_vmps);
	if (!vptr || size >= vptr->len)
		return (NULL);
	p = (t_vmps *)((size_t)vptr + size);
	*p = (t_vmps){ .flag = FT_VMF_VALID | FT_VMF_EMPTY,
		.prev_len = size, .len = vptr->len - size};
	vptr->len = size;
	return (p);
}
