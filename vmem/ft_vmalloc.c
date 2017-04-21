/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vmalloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 00:35:26 by qloubier          #+#    #+#             */
/*   Updated: 2017/04/21 01:22:41 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intern_vmem.h"

void			*ft_vmalloc(short size)
{
	t_vmem		*vm;

	vm = ft_vmem(NULL);
	if (!vm || (size <= 0))
		return (NULL);

}
