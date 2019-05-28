/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vmem.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 00:13:36 by qloubier          #+#    #+#             */
/*   Updated: 2019/05/28 14:28:38 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intern_vmem.h"

t_vmem				*ft_vmem(t_vmem *vm)
{
	static t_vmem	*activemem = NULL;

	if (vm == activemem)
	{
		activemem = vm->p_lastactive;
		vm->p_lastactive = vm;
	}
	else if (vm)
	{
		vm->p_lastactive = activemem;
		activemem = vm;
	}
	else if (!activemem)
		activemem = ft_vmemnew(FT_VMEM_DEFAULT);
	return (activemem);
}
