/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vfree.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 16:46:20 by qloubier          #+#    #+#             */
/*   Updated: 2017/05/10 16:52:09 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intern_vmem.h"

int				ft_vfree(void **vptr)
{
	t_vmps		*p;
	t_vmem		*vm;

	if (!vptr || !*vptr)
		return (0);
	p = (t_vmps *)(*vptr);
	if (!(vm = ft_ivm_getvmem(p)))
		return (0);
	ft_ivm_cleanptr(p, vm);
	*vptr = NULL;
	return (1);
}
