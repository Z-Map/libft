/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pfflag_h.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 02:24:20 by qloubier          #+#    #+#             */
/*   Updated: 2016/10/05 22:12:40 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_format.h"

const char			*ft_pfflag_h(const char *c, t_pfb *b)
{
	if (c[1] == 'h')
	{
		b->arg.flag |= SHORT_SHORT;
		++c;
	}
	else
		b->arg.flag |= SHORT;
	return (c + 1);
}
