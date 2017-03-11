/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strunsplit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 15:15:32 by qloubier          #+#    #+#             */
/*   Updated: 2017/03/10 17:31:11 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft_string.h"

char				*ft_strunsplit(const char **tab, const char *separator)
{
	const size_t	slen = ft_strlen(separator);
	size_t			len;
	FT_CC			**t;
	char			*ret;
	char			*str;

	len = 1;
	t = tab;
	while (*t)
		len += slen + ft_strlen(*(t++));
	len -= slen;
	if (!(ret = malloc(sizeof(char) * len)))
		return (NULL);
	t = tab;
	str = ret;
	while (*t)
	{
		str = ft_stpcpy(str, *(t++));
		if (*t)
			str = ft_stpcpy(str, separator);
	}
	return (ret);
}
