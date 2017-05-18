/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsndup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 17:18:23 by qloubier          #+#    #+#             */
/*   Updated: 2017/05/17 20:28:55 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_string.h"

char		*ft_vsndup(const char *s1, size_t n)
{
	size_t			len = FT_SLEN(s1);
	char 			*nstr;

	nstr = NULL;
	if (len < n)
		n = len;
	if (n < 0x7FFF)
	{
		nstr = ft_vsnew((short)n);
		if (nstr)
			FT_SNCPY(nstr, s1, n);
		nstr[n] = '\0';
	}
	return (nstr);
}
