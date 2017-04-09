/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 16:51:16 by qloubier          #+#    #+#             */
/*   Updated: 2017/04/08 02:34:54 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft_memory.h"

void	*ft_memalloc(size_t size)
{
	void	*memptr;

	memptr = malloc(size);
	if (memptr)
		FT_BZERO(memptr, size);
	return (memptr);
}
