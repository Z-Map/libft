/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prsgskp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 05:20:10 by qloubier          #+#    #+#             */
/*   Updated: 2017/05/18 10:35:07 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_parse.h"

size_t				ft_prsgskp(t_gparse *p, t_gsep *group, FT_CC *e)
{
	size_t			i;
	int				gi;

	i = 0;
	while (p->c_len && *(p->cursor))
	{
		if (group && ((size_t)group->elen >= p->c_len)
			&& !ft_strconcur(p->cursor, group->end))
		{
			p->cursor += group->elen;
			p->c_len -= (size_t)group->elen;
			return (i);
		}
		else if (e && ft_strchr(e, *(p->cursor)))
		{
			p->cursor++;
			p->c_len--;
			return (i);
		}
		else if ((gi = ft_prsgetgsep(p, p->cursor++, p->c_len--)) >= 0)
			i += ft_prsgskp(p, p->seplst + gi, (group && e) ? e : NULL);
		else
			i++;
	}
	return (i);
}
