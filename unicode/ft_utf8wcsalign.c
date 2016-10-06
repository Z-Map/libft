/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utf8wcsalign.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: map <marvin@student.42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 01:31:57 by map               #+#    #+#             */
/*   Updated: 2016/10/06 04:17:29 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_unicode.h"

size_t		ft_utf8wcsalign(const wchar_t *s, size_t mxlen)
{
	size_t	len;
	size_t	i;

	len = 0;
	while (*s && (len < mxlen))
	{
		i = len + ft_utf8wcsize(*(s++));
		if (i > mxlen)
			break ;
		len = i;
	}
	return (len);
}
