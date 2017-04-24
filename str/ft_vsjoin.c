/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsjoin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 16:30:04 by qloubier          #+#    #+#             */
/*   Updated: 2017/04/22 02:46:32 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_string.h"

char				*ft_vsjoin(char const *s1, char const *s2)
{
	const size_t	bsize = FT_SLEN(s1) + FT_SLEN(s2);
	char			*nstr;

	if ((bsize >= 0x7FFF) || (!s1 && !s2))
		return (NULL);
	else if (!s1 || !s2)
		return (s1 ? ft_vsdup(s1) : ft_vsdup(s2));
	if ((nstr = ft_vsnew((short)bsize)))
		FT_SCAT(FT_SCPY(nstr, s1), s2);
	return (nstr);
}
