/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stpncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 01:10:28 by qloubier          #+#    #+#             */
/*   Updated: 2017/03/10 15:34:54 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_string.h"

char	*ft_stpncpy(char *dst, const char *src, size_t n)
{
	char	*dit;

	dit = dst;
	if (!n)
		return (dst);
	while (n--)
	{
		*(dit++) = *src;
		if (*src)
		{
			src++;
			dst++;
		}
	}
	return (dst);
}
