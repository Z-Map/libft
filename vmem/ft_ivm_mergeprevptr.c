/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ivm_mergeprevptr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 18:00:16 by qloubier          #+#    #+#             */
/*   Updated: 2017/04/21 21:17:38 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intern_vmem.h"

t_vmps			*ft_ivm_mergeprevptr(t_vmps *vptr, t_vmem *vm)
{
	t_vmps		*pp;

	if (!vm)
		vm = ft_ivm_getvmem(vptr);
	if (vptr == vm->mem)
		return (vptr);
	pp = ft_ivm_prevptr(vptr, &vm);
	pp->len += (short)(vptr->len);
	pp->flag = vptr->flag;
	vptr->flag &= ~FT_VMF_VALIDAREA;
	if (vm->last == vptr)
		vm->last = pp;
	if (vm->cursor == vptr)
		vm->cursor = pp;
	return (pp);
}
