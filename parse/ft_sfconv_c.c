/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sfconv_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: map <map@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 16:15:29 by map               #+#    #+#             */
/*   Updated: 2017/03/06 15:50:25 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_parse.h"

int					ft_sfconv_c(const char **c, t_sfb *b, t_sfc *arg)
{
	int				len;

	len = (arg->flag & SFF_MXW_SET) ? arg->maxwidth : 1;
	if (!(arg->flag & SFF_IGNORE))
		arg->arg = va_arg(b->ap, char *);
	if (ft_strnidx(b->c, 0, (size_t)len) >= 0)
		return ((arg->flag & SFF_OPTIONAL) ? 0 : -1);
	if (!(arg->flag & SFF_IGNORE))
		ft_memcpy(arg->arg, b->c, (size_t)len);
	b->c += len;
	(*c)++;
	return ((arg->flag & SFF_IGNORE) ? 0 : 1);
}
