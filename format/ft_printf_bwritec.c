/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bwritec.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 23:52:14 by qloubier          #+#    #+#             */
/*   Updated: 2016/10/05 20:28:22 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft_format.h"

int				ft_printf_bwritec(t_pfb *b, char c, size_t len)
{
	ssize_t		i;

	if (!len)
		return (0);
	i = (int)len;
	while (len)
	{
		if (b->blen >= FT_PF_BUFSIZE)
			ft_printf_bflush(b);
		*(b->c) = c;
		++(b->c);
		++(b->blen);
		--len;
	}
	return (i);
}
