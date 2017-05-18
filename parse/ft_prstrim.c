/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prstrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 04:38:33 by qloubier          #+#    #+#             */
/*   Updated: 2017/05/18 13:34:25 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_parse.h"
#include "libft_printf.h"

size_t					ft_prstrim(FT_CC **c, size_t *l, FT_CC *s)
{
	register size_t		tmp;

	if (!*c || !*l)
		return (0);
	tmp = (size_t)*c;
	*c = ft_strnpskp(*c, s, *l);
	tmp = ((size_t)*c - tmp);
	*l -= tmp;
	*l -= (size_t)ft_strrnspn(*c, s, *l);
	return (tmp);
}
