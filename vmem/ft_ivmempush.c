/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ivmempush.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 18:18:42 by qloubier          #+#    #+#             */
/*   Updated: 2017/04/19 18:31:19 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intern_vmem.h"

void			ft_ivmempush(t_vmem *vm)
{
	t_vmem		**pvmem;

	if (!vm)
		return ;
	pvmem = ft_ivmem();
	vm->_gprev = NULL;
	while ((*pvmem) && (*pvmem != vm) && (pvmem = &((*pvmem)->_gnext)))
		vm->_gprev = *pvmem;
	if (*pvmem)
		return ;
	vm->_gnext = NULL;
	*pvmem = vm;
}
