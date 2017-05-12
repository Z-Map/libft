/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrnpskpnul.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 04:46:59 by qloubier          #+#    #+#             */
/*   Updated: 2017/05/12 09:13:24 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_string.h"

char	*ft_strrnpskpnul(const char *s, const char *skip, size_t n)
{
	const size_t	len = FT_SLEN(s);

	n = (len < n) ? len : n;
	while (n--)
		if (!FT_SCHR(skip, (int)(s[n])))
			return ((char *)(unsigned long)(s + n));
	return ((char *)(unsigned long)s);
}
