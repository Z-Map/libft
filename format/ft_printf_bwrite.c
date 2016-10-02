/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bwrite.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 23:52:14 by qloubier          #+#    #+#             */
/*   Updated: 2016/10/01 03:56:31 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft_format.h"

int				ft_printf_bwrite(t_pfb *b, const char *c, size_t len)
{
	ssize_t		i;

	if (!len)
		return (0);
	if (len >= FT_PF_BUFSIZE)
	{
		if ((ft_printf_bflush(b) < 0) || ((i = write(b->fd, c, len)) < 0))
			return (-1);
		b->len += i;
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
