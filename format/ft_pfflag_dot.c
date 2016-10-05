/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pfflag_dot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 02:22:27 by qloubier          #+#    #+#             */
/*   Updated: 2016/10/05 01:27:14 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_format.h"

const char			*ft_pfflag_dot(const char *c, t_pfb *b)
{
	if (!(b->arg.flag & PREC_SET))
	{
		b->arg.flag |= PREC_SET;
		// write(1, "[prec parse : ", 14);
		// write(1, c, 1);
		// write(1, "]\n", 2);
		if (c[1] != '*')
			return (ft_parse_digit(c + 1, &(b->arg.precision)));
		b->arg.precision = va_arg(b->ap, unsigned int);
		return (c + 2);
	}
	return (c + 1);
}
