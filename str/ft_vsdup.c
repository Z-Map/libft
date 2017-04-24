/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsdup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 17:18:23 by qloubier          #+#    #+#             */
/*   Updated: 2017/04/22 02:41:56 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_string.h"

char		*ft_vsdup(const char *s1)
{
	const size_t	len = FT_SLEN(s1);
	char 			*nstr;

	nstr = NULL;
	if (len < 0x7FFF)
	{
		nstr = ft_vsnew((short)len);
		if (nstr)
			FT_SNCPY(nstr, s1, len);
	}
	return (nstr);
}
