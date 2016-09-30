/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bflush.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 23:29:51 by qloubier          #+#    #+#             */
/*   Updated: 2016/09/30 00:22:39 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft_format.h"

int				ft_printf_bflush(t_pfb *b)
{
	int			i;

	if (!(b->blen))
		return (0);
	i = write(b->fd, b->buffer, b->blen);
	b->len += i;
	b->blen = 0;
	b->c = b->buffer;
	return (i);
}
