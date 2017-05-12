/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnpbrknul.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 04:46:59 by qloubier          #+#    #+#             */
/*   Updated: 2017/05/12 01:08:05 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_string.h"

char	*ft_strnpbrknul(const char *s, const char *stop, size_t n)
{
	while (*s && n--)
		if (FT_SCHR(stop, (int)(*(s++))))
			return ((char *)(unsigned long)(--s));
	return ((char *)(unsigned long)s);
}
