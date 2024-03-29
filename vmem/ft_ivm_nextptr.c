/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ivm_nextptr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 18:50:35 by qloubier          #+#    #+#             */
/*   Updated: 2017/04/20 17:16:11 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intern_vmem.h"

t_vmps			*ft_ivm_nextptr(t_vmps *vptr, t_vmem **vm)
{
	t_vmem		*mem;
	t_vmps		*p;

	mem = (vm && *vm) ? *vm : ft_ivm_getvmem(vptr);
	if (!mem || !vptr)
		return (NULL);
	p = (t_vmps *)((size_t)vptr + (size_t)vptr->len);
	if (p != mem->last)
		return (p);
	if (!mem->next)
		return (NULL);
	*vm = mem->next;
	return (mem->next->mem);
}
