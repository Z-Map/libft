/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ivm_getvmem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 18:43:16 by qloubier          #+#    #+#             */
/*   Updated: 2017/04/19 18:49:51 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intern_vmem.h"

t_vmem			*ft_ivm_getvmem(t_vmps *vptr)
{
	t_vmem		*vmem;
	size_t		np;

	vmem = *ft_ivmem();
	np = (size_t)vptr;
	while (vmem)
	{
		if ((np >= (size_t)vmem->mem) && (np < (size_t)vmem->mem + vmem->size))
			return (vmem);
		vmem = vmem->_gnext;
	}
	return (NULL);
}
