/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ivm_iter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 18:33:47 by qloubier          #+#    #+#             */
/*   Updated: 2017/04/19 18:38:40 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intern_vmem.h"

t_vmps			*ft_ivm_iter(t_vmi *it)
{
	if (!it->mem)
		return (NULL);
	if (!it->cursor)
		return (it->cursor = it->mem->mem);
	return (it->cursor = ft_ivm_nextptr(it->cursor, &(it->mem)));
}
