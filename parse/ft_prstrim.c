/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prstrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 04:38:33 by qloubier          #+#    #+#             */
/*   Updated: 2017/05/12 10:40:15 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_parse.h"

size_t					ft_prstrim(FT_CC **c, size_t *l, FT_CC *s)
{
	register size_t		tmp;

	if (!*l)
		return (0);
	tmp = (size_t)*c;
	*c = ft_strnpskp(*c, s, *l);
	 tmp = *l - (size_t)*c - tmp;
	*l = tmp - (size_t)ft_strrnspn(*c, s, *l);
	return (tmp);
}
