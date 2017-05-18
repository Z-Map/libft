/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrnspn.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 04:46:59 by qloubier          #+#    #+#             */
/*   Updated: 2017/05/18 13:27:00 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_string.h"

int			ft_strrnspn(const char *s, const char *skipset, size_t n)
{
	int		i;
	size_t	len;

	if ((len = FT_SLEN(s)) < n)
		n = len;
	i = 0;
	while (n && (FT_SCHR(skipset, (int)(s[n - 1]))))
	{
		n--;
		++i;
	}
	return (i);
}
