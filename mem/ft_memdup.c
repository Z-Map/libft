/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 22:05:26 by qloubier          #+#    #+#             */
/*   Updated: 2017/04/08 02:30:59 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_memory.h"

void	*ft_memdup(const void *s1, size_t n)
{
	void	*rmem;

	if (!n)
		return (NULL);
	rmem = ft_memalloc(n);
	if (rmem)
		FT_MCPY(rmem, s1, n);
	return (rmem);
}
