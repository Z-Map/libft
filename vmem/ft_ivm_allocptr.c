/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ivm_allocptr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 20:36:33 by qloubier          #+#    #+#             */
/*   Updated: 2017/04/21 21:24:26 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intern_vmem.h"

t_vmps			*ft_ivm_allocptr(size_t size, t_vmem *vm)
{
	t_vmps		*p;

	size += sizeof(t_vmps);
	p = vm->cursor;
	while (p && (p->len < size))
		p = ft_ivm_emptyptr(vm, p);
	if (p && (p->len > (size + sizeof(t_vmps) + 4)))
		ft_ivm_splitptr(p, size, vm);
	if (p)
		p->flag &= ~FT_VMF_EMPTY;
	return (p);
}
