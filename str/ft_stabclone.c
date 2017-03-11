/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stabclone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 16:51:40 by qloubier          #+#    #+#             */
/*   Updated: 2017/03/10 17:27:37 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft_string.h"

char			**ft_stabclone(const char **tab)
{
	size_t		len;
	size_t		slen;
	char		**ret;
	char		*str;

	if (!tab)
		return (NULL);
	len = ft_stablen(tab, &slen);
	if (!(ret = (char **)malloc((sizeof(char *) * (len + 1))
		+ (sizeof(char) * (slen + len)))))
		return (NULL);
	ret[len] = NULL;
	str = ((char *)ret) + (sizeof(char *) * (len + 1));
	while (len--)
	{
		ret[len] = str;
		str = ft_stpcpy(str, tab[len]) + 1;
	}
	return (ret);
}
