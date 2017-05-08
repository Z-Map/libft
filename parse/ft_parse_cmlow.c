/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_cmlow.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: map <map@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 13:19:18 by map               #+#    #+#             */
/*   Updated: 2017/05/04 23:53:26 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_parse.h"

const char	*ft_parse_cmlow(const char *str, unsigned long *num, t_cmap cm,
				int len)
{
	register int	i;

	*num = 0;
	i = 0;
	while ((*str) && (len-- > 0) &&
		((i = ft_strnidx(cm.cmap, ft_tolower(*str), (size_t)cm.base)) >= 0))
	{
		*num = (*num * (unsigned long)cm.base) + (unsigned long)(i);
		str++;
	}
	return (str);
}
