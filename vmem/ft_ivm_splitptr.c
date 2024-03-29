/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ivm_splitptr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 17:31:15 by qloubier          #+#    #+#             */
/*   Updated: 2017/04/22 02:56:39 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intern_vmem.h"

t_vmps			*ft_ivm_splitptr(t_vmps *vptr, size_t size, t_vmem *vm)
{
	t_vmps		*p;

	size += sizeof(t_vmps);
	if (!vptr || (size >= (size_t)vptr->len))
		return (NULL);
	p = (t_vmps *)((size_t)vptr + size);
	*p = (t_vmps){ .flag = FT_VMF_VALID | FT_VMF_EMPTY,
		.prev_len = (t_us)size, .len = vptr->len - (t_us)size};
	vptr->len = (t_us)size;
	if (vm->last == vptr)
		vm->last = p;
	return (p);
}
