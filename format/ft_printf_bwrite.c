/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bwrite.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 23:52:14 by qloubier          #+#    #+#             */
/*   Updated: 2016/09/30 00:33:18 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft_format.h"

int				ft_printf_bwrite(t_pfb *b, const char *c, size_t len)
{
	int			i;

	if (!len)
		return (0);
	if (len >= FT_PF_BUFSIZE)
	{
		ft_printf_bflush(b);
		b->len += write(b->fd, c, len);
		return (2);
	}
	i = 0;
	while (len)
	{
		if (b->blen >= FT_PF_BUFSIZE && ++i)
			ft_printf_bflush(b);
		*(b->c) = *c;
		++(b->c);
		++(b->blen);
		++c;
		--len;
	}
	return (i);
}
