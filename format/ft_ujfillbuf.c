/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ujfillbuf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 21:38:32 by qloubier          #+#    #+#             */
/*   Updated: 2016/10/07 04:37:10 by map              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_format.h"

char			*ft_ujfillbuf(uintmax_t n, char *b, int *len)
{
	const int	ln = *len;
	int			l;

	b += ln - 1;
	*b = '0' + (char)(n % 10);
	l = 0;
	while ((n /= 10) && (++l < ln))
		*(--b) = '0' + (char)(n % 10);
	*len = l;
	return (b);
}
