/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ivm_mptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 18:39:19 by qloubier          #+#    #+#             */
/*   Updated: 2017/04/19 18:42:06 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intern_vmem.h"

void			*ft_ivm_mptr(t_vmps *vptr)
{
	if ((vptr->flag & FT_VMF_VALIDAREA) != FT_VMF_VALID)
		return (NULL);
	return ((void *)((t_ul)vptr + sizeof(t_vmps)));
}
