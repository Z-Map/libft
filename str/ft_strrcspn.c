/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrcspn.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 04:46:59 by qloubier          #+#    #+#             */
/*   Updated: 2017/05/12 09:23:35 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_string.h"

int			ft_strrcspn(const char *s, const char *stopset)
{
	int		i;
	size_t	n;

	n = FT_SLEN(s);
	i = 0;
	while ((n--) && !(FT_SCHR(stopset, (int)(s[n]))))
		++i;
	return (i);
}
