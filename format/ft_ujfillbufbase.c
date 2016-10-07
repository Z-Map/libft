/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ujfillbufbase.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 21:38:32 by qloubier          #+#    #+#             */
/*   Updated: 2016/10/07 18:47:43 by map              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_format.h"

char			*ft_ujfillbufbase(uintmax_t n, t_ui base, char *b, int *len)
{
	const int	ln = *len;
	int			l;

	b += ln - 1;
	*b = '0' + (char)(n % base);
	l = 0;
	while ((n /= base) && (++l < ln))
		*(--b) = '0' + (char)(n % base);
	*len = l;
	return (b);
}
