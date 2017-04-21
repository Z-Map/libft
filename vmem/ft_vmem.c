/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vmem.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 00:13:36 by qloubier          #+#    #+#             */
/*   Updated: 2017/04/21 00:34:32 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intern_vmem.h"

t_vmem				*ft_vmem(t_vmem *vm)
{
	static t_vmem	*activemem = NULL;

	if (vm == activemem)
	{
		activemem = vm->_lastactive;
		vm->_lastactive = vm;
	}
	else if (vm)
	{
		vm->_lastactive = activemem;
		activemem = vm;
	}
	else if (!activemem)
		activemem = ft_vmemnew(FT_VMEM_DEFAULT);
	return (activemem);
}
