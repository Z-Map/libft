/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stabnlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 17:03:58 by qloubier          #+#    #+#             */
/*   Updated: 2017/03/10 17:25:22 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_string.h"

size_t			ft_stabnlen(const char **tab, size_t n, size_t *slen)
{
	size_t		i;

	i = 0;
	if (slen)
	{
		*slen = 0;
		while ((*tab) && (n--))
		{
			i++;
			*slen += FT_SLEN(*(tab++));
		}
	}
	else
	{
		while (*(tab++) && (n--))
			i++;
	}
	return (i);
}
