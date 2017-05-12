/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrpbrknul.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 04:46:59 by qloubier          #+#    #+#             */
/*   Updated: 2017/05/12 09:08:58 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_string.h"

char	*ft_strrpbrknul(const char *s, const char *stopset)
{
	size_t	n;

	n = FT_SLEN(s);
	while (n--)
		if (FT_SCHR(stopset, (int)(s[n])))
			return ((char *)(unsigned long)(s + n));
	return ((char *)(unsigned long)s);
}
