/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_forf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 18:12:32 by qloubier          #+#    #+#             */
/*   Updated: 2016/09/30 00:31:58 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_format.h"

const char				*ft_forf(const char *c, const char *s, size_t *len)
{
	const char			*sc;

	if (!c || !(*c) || !s)
		return (NULL);
	*len = 0;
	while (*c)
	{
		sc = s;
		while (*sc)
			if (*(sc++) == *c)
				return (c);
		(*len) += 1;
		c++;
	}
	return (NULL);
}
