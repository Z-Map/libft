/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ivm_mergenextptr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 17:59:59 by qloubier          #+#    #+#             */
/*   Updated: 2017/04/21 21:18:10 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intern_vmem.h"

t_vmps			*ft_ivm_mergenextptr(t_vmps *vptr, t_vmem *vm)
{
	t_vmps		*np;

	if (!vm)
		vm = ft_ivm_getvmem(vptr);
	if (vptr == vm->last)
		return (vptr);
	np = ft_ivm_nextptr(vptr, &vm);
	vptr->len += np->len;
	if (vm->last == np)
		vm->last = vptr;
	if (vm->cursor == np)
		vm->cursor = ft_ivm_emptyptr(vm, np);
	np->flag &= ~FT_VMF_VALIDAREA;
	return (vptr);
}
