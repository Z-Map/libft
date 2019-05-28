/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vmemnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 16:34:42 by qloubier          #+#    #+#             */
/*   Updated: 2019/05/28 14:28:20 by qloubier         ###   ########.fr       */
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
		.p_gnext = NULL, .p_gprev = NULL};
	*p = (t_vmps){ .flag = FT_VMF_VALID | FT_VMF_EMPTY,
		.prev_len = 0, .len = (t_us)size};
	ft_ivmempush(vm);
	return (vm);
}
