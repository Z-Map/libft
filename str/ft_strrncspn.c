/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrncspn.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 04:46:59 by qloubier          #+#    #+#             */
/*   Updated: 2017/05/12 09:23:18 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_string.h"

int			ft_strrncspn(const char *s, const char *stopset, size_t n)
{
	int		i;
	size_t	len;

	if ((len = FT_SLEN(s)) < n)
		n = len;
	i = 0;
	while ((n--) && !(FT_SCHR(stopset, (int)(s[n]))))
		++i;
	return (i);
}
