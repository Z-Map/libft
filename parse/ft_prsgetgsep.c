/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prsgetgsep.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 05:29:34 by qloubier          #+#    #+#             */
/*   Updated: 2017/05/12 10:38:32 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_parse.h"

int				ft_prsgetsep(t_gparse *p, const char *c, size_t len)
{
	size_t		seplen;
	int			i;

	seplen = p->seplen;
	i = 0;
	while (seplen-- && (!p->seplst[i].end
		|| (size_t)p->seplst[i].slen > len
		|| ft_strconcur(c, p->seplst[i].separator)))
		i++;
	return (((unsigned)i < p->seplen) ? i : -1);
}
