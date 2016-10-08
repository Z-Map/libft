/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ujfillbufbase.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 21:38:32 by qloubier          #+#    #+#             */
/*   Updated: 2016/10/08 20:01:26 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_format.h"

char			*ft_ujfillbufbase(uintmax_t n, t_cmap cm, char *b, int *len)
{
	const t_ui	base = cm.base;
	const int	ln = *len;
	int			l;

	b += ln - 1;
	*b = cm.cmap[n % base];
	l = 1;
	while ((n /= base) && (l < ln))
	{
		*(--b) = cm.cmap[n % base];
		++l;
	}
	*len = l;
	return (b);
}
