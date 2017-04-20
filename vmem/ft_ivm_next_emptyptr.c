/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ivm_next_emptyptr.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 17:14:48 by qloubier          #+#    #+#             */
/*   Updated: 2017/04/20 17:19:16 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intern_vmem.h"

t_vmps			*ft_ivm_next_emptyptr(t_vmps *vptr, t_vmem **vm)
{
	vptr = ft_ivm_nextptr(vptr, vm);
	while (vptr && !(vptr->flag & FT_VMF_EMPTY))
		vptr = ft_ivm_nextptr(vptr, vm);
	return (vptr);
}
