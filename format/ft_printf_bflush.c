/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bflush.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 23:29:51 by qloubier          #+#    #+#             */
/*   Updated: 2016/10/06 02:50:22 by map              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft_format.h"

int				ft_printf_bflush(t_pfb *b)
{
	ssize_t		i;

	if (!(b->blen))
		return (0);
	i = write(b->fd, b->buffer, b->blen);
	if (i < 0)
		return (i);
	b->len += i;
	b->blen = 0;
	b->c = b->buffer;
	return (i);
}
