/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vmemnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 16:34:42 by qloubier          #+#    #+#             */
/*   Updated: 2017/04/21 00:33:56 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "intern_vmem.h"

t_vmem			*ft_vmemnew(size_t size)
{
	t_vmem		*vm;
	t_vmps		*p;

	if ((size < (0xFF + sizeof(t_vmps)))
		|| !(vm = (t_vmem *)malloc(sizeof(t_vmem) + size)))
		return (NULL);
	p = (t_vmps *)((size_t)vm + sizeof(t_vmem));
	*vm = (t_vmem){ .next = NULL, .prev = NULL,
		.mem = p, .last = p, .cursor = p, .size = size, .len = sizeof(t_vmps),
		._gnext = NULL, ._gprev = NULL};
	*p = (t_vmps){ .flag = FT_VMF_VALID | FT_VMF_EMPTY,
		.prev_len = 0, .len = size - sizeof(t_vmps)};
	ft_ivmempush(vm);
	return (vm);
}
