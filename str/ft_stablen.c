/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stablen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 17:03:58 by qloubier          #+#    #+#             */
/*   Updated: 2017/03/10 17:07:15 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_string.h"

size_t			ft_stablen(const char **tab, size_t *slen)
{
	size_t		i;

	i = 0;
	if (slen)
	{
		*slen = 0;
		while (*tab)
		{
			i++;
			*slen += ft_strlen(*(tab++));
		}
	}
	else
	{
		while (*(tab++))
			i++;
	}
	return (i);
}
