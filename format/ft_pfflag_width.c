/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pfflag_width.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 02:25:22 by qloubier          #+#    #+#             */
/*   Updated: 2016/10/05 18:27:21 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_format.h"

const char			*ft_pfflag_width(const char *c, t_pfb *b)
{
	int				i;

	if (*c == '*')
	{
		i = va_arg(b->ap, int);
		if (i < 0 && (i = -i))
			b->arg.flag |= LEFT_ALIGN;
		b->arg.minwidth = (t_ui)i;
		++c;
	}
	else
		c = ft_parse_digit(c, &(b->arg.minwidth));
	b->arg.flag |= MNW_SET;
	return (c);
}
