/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pfflag_dot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 02:22:27 by qloubier          #+#    #+#             */
/*   Updated: 2016/09/30 07:40:38 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_format.h"

const char			*ft_pfflag_dot(const char *c, t_pfb *b)
{
	if (c[1] != '*')
		return (ft_parse_digit(c + 1, &(b->arg.precision)));
	b->arg.precision = va_arg(b->ap, unsigned int);
	return (c + 2);
}
