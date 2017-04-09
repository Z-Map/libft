/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 17:01:32 by qloubier          #+#    #+#             */
/*   Updated: 2016/11/22 18:28:06 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_string.h"

char	*ft_strtrim(char const *s)
{
	size_t	len;
	char	*nstr;

	len = 0;
	if (!s)
		return (NULL);
	while (*s && FT_SCHR(FT_WHITESPACE, (int)(*s)))
		s++;
	if (!(*s))
		return (ft_memalloc(1));
	len = FT_SLEN(s) - 1;
	while (FT_SCHR(FT_WHITESPACE, (int)(s[len])))
		--len;
	if ((nstr = ft_strnew(len + 1)))
		FT_SNCPY(nstr, s, len + 1);
	return (nstr);
}
