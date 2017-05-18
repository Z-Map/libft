/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prsgetsep.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 05:29:34 by qloubier          #+#    #+#             */
/*   Updated: 2017/05/18 12:25:09 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_parse.h"

int				ft_prsgetsep(t_gparse *p, const char *c, size_t len)
{
	size_t		seplen;
	int			i;

	i = 0;
	if (!*c || !p->seplen)
		return (-1);
	seplen = p->seplen;
	while (seplen-- && ((size_t)p->seplst[i].slen > len
		|| ft_strconcur(c, p->seplst[i].separator)))
		i++;
	return (((unsigned int)i < p->seplen) ? i : -1);
}
