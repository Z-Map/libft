/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vmemalloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 00:41:32 by qloubier          #+#    #+#             */
/*   Updated: 2017/04/22 02:54:10 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intern_vmem.h"

void			*ft_vmemalloc(t_vmem *vm, short size)
{
	t_vmps		*p;

	if (!vm || (size <= 0) || (vm->size <= ((size_t)size + sizeof(t_vmps))))
		return (NULL);
	while (!(p = ft_ivm_allocptr((size_t)size, vm)) && vm->next)
		vm = vm->next;
	if (p)
		return ((void *)((size_t)p + sizeof(t_vmps)));
	if (!(vm->next = ft_vmemnew(vm->size)))
		return (NULL);
	vm->next->prev = vm;
	return ((void *)(ft_ivm_allocptr((size_t)size, vm) + sizeof(t_vmps)));
}
