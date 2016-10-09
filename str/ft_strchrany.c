/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchrany.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 04:46:59 by qloubier          #+#    #+#             */
/*   Updated: 2016/10/09 21:46:15 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_string.h"

char	*ft_strchrany(const char *s, const char *clst, char end)
{
	while (*s)
	{
		if (ft_strchr(clst, (int)(*s)))
			return ((char *)(unsigned long)s);
		s++;
	}
	if (end)
		return ((char *)(unsigned long)s);
	return (NULL);
}
