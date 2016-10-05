/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pfflag_width.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 02:25:22 by qloubier          #+#    #+#             */
/*   Updated: 2016/10/05 01:27:16 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_format.h"

const char			*ft_pfflag_width(const char *c, t_pfb *b)
{
	if (!(b->arg.flag & MNW_SET))
	{
		b->arg.flag |= MNW_SET;
		// write(1, "[width parse : ", 15);
		// write(1, c, 1);
		// write(1, "]\n", 2);
		if (*c != '*')
			return (ft_parse_digit(c, &(b->arg.minwidth)));
		b->arg.minwidth = va_arg(b->ap, unsigned int);
	}
	return (c + 1);
}
