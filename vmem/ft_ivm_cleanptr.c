/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ivm_cleanptr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 20:49:00 by qloubier          #+#    #+#             */
/*   Updated: 2017/04/21 21:15:52 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intern_vmem.h"

t_vmps			*ft_ivm_cleanptr(t_vmps *vptr, t_vmem *vm)
{
	if (!vptr)
		return (NULL);
	if (!vm)
		vm = ft_ivm_getvmem(vptr);
	vptr->flag |= FT_VMF_EMPTY;
	while ((vptr != vm->mem)
		&& (*(t_ui *)((size_t)vptr - (size_t)vptr->prev_len) & FT_VMF_EMPTY))
		vptr = ft_ivm_mergeprevptr(vptr, vm);
	while ((vptr != vm->last)
		&& (*(t_ui *)((size_t)vptr + (size_t)vptr->len) & FT_VMF_EMPTY))
		vptr = ft_ivm_mergenextptr(vptr, vm);
	if ((size_t)vm->cursor > (size_t)vptr)
		vm->cursor = vptr;
	return (vptr);
}
