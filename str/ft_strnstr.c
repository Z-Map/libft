/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 16:27:08 by qloubier          #+#    #+#             */
/*   Updated: 2016/10/09 21:49:04 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_string.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	len;

	len = FT_SLEN(s2);
	if (!(*s2))
		return ((char *)(unsigned long)s1);
	while (*s1 && n-- >= len)
	{
		if (*s1 == *s2 && FT_SNCMP(s1 + 1, s2 + 1, len - 1) == 0)
			return ((char *)(unsigned long)s1);
		s1++;
	}
	return (NULL);
}
