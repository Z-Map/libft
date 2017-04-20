/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ivm_prevptr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 16:27:42 by qloubier          #+#    #+#             */
/*   Updated: 2017/04/20 17:16:20 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intern_vmem.h"

t_vmps			*ft_ivm_prevptr(t_vmps *vptr, t_vmem **vm)
{
	t_vmem		*mem;

	mem = (vm && *vm) ? *vm : ft_ivm_getvmem(vptr);
	if (!mem || !vptr)
		return (NULL);
	if (vptr > mem->mem)
		return ((t_vmps *)((size_t)vptr - (size_t)vptr->prev_len));
	if (!mem->prev)
		return (NULL);
	*vm = mem->prev;
	return (mem->prev->last);
}
