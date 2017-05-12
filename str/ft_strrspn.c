/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 04:46:59 by qloubier          #+#    #+#             */
/*   Updated: 2017/05/12 09:18:14 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_string.h"

int			ft_strrspn(const char *s, const char *skipset)
{
	int		i;
	size_t	n;

	i = 0;
	n = FT_SLEN(s);
	while (n-- && (FT_SCHR(skipset, (int)(s[n]))))
		++i;
	return (i);
}
