/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ivm_emptyptr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 18:38:26 by qloubier          #+#    #+#             */
/*   Updated: 2017/04/21 19:18:20 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intern_vmem.h"

t_vmps			*ft_ivm_emptyptr(t_vmem *vm, t_vmps *vptr)
{
	t_vmps		*p;

	if (!vptr)
		p = vm->mem;
	else
		p = (t_vmps *)((size_t)vptr + (size_t)vptr->len);
	if (!p)
		return (p);
	while ((p != vm->last) && !(p->flag & FT_VMF_EMPTY))
		p = (t_vmps *)((size_t)p + (size_t)p->len);
	return ((p->flag & FT_VMF_EMPTY) ? p : NULL);
}
