/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 01:10:28 by qloubier          #+#    #+#             */
/*   Updated: 2017/03/10 17:30:48 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_string.h"

size_t		ft_strlcpy(char *dst, const char *src, size_t n)
{
	size_t	i;
	char	*dit;

	dit = dst;
	i = 0;
	if (!n)
		return (ft_strlen(src));
	while (n--)
	{
		if (n)
			*(dit++) = *src;
		else
			*dit = '\0';
		if (*src)
		{
			src++;
			i++;
		}
	}
	while (*(src++))
		i++;
	return (i);
}
