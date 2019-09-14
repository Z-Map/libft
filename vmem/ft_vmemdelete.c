/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vmemdelete.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 16:01:50 by qloubier          #+#    #+#             */
/*   Updated: 2019/07/25 16:18:01 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "intern_vmem.h"

int				ft_vmemdelete(t_vmem *vm)
{
	t_vmem		*vm_cur;

	vm_cur = vm;
	while ((vm = vm_cur))
	{
		vm_cur = vm->next;
		free(vm);
	}
	return (1);
}
