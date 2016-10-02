/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pfflag_width.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 02:25:22 by qloubier          #+#    #+#             */
/*   Updated: 2016/10/01 02:10:18 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_format.h"

const char			*ft_pfflag_width(const char *c, t_pfb *b)
{
	if (b->arg.flag & MNW_SET)
	{
		b->arg.flag |= MNW_SET;
		if (*c != '*')
			return (ft_parse_digit(c + 1, &(b->arg.minwidth)));
		b->arg.minwidth = va_arg(b->ap, unsigned int);
	}
	return (c + 1);
}
