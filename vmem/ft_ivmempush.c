/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ivmempush.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 18:18:42 by qloubier          #+#    #+#             */
/*   Updated: 2019/05/28 14:28:20 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intern_vmem.h"

void			ft_ivmempush(t_vmem *vm)
{
	t_vmem		**pvmem;

	if (!vm)
		return ;
	pvmem = ft_ivmem();
	vm->p_gprev = NULL;
	while ((*pvmem) && (*pvmem != vm) && (pvmem = &((*pvmem)->p_gnext)))
		vm->p_gprev = *pvmem;
	if (*pvmem)
		return ;
	vm->p_gnext = NULL;
	*pvmem = vm;
}
