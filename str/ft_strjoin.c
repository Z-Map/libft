/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 16:30:04 by qloubier          #+#    #+#             */
/*   Updated: 2017/04/08 02:38:50 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_string.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	bsize;
	char	*nstr;

	bsize = 0;
	if (!s1 && !s2)
		return (NULL);
	else if (!s1 || !s2)
		return (s1 ? ft_strdup(s1) : ft_strdup(s2));
	bsize = FT_SLEN(s1) + FT_SLEN(s2);
	if ((nstr = ft_strnew(bsize)))
		FT_SCAT(FT_SCPY(nstr, s1), s2);
	return (nstr);
}
