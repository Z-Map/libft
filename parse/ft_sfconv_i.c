/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sfconv_i.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: map <map@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 16:12:17 by map               #+#    #+#             */
/*   Updated: 2017/03/06 15:47:10 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_parse.h"

static int			valid_num(const char *s, int len)
{
	if ((len > 1) && ((*s == '+') || (*s == '-')))
		++s;
	if (ft_strchr(FT_DECIMAL_DIGIT, (int)*s))
		return (1);
	return (0);
}

int					ft_sfconv_i(const char **c, t_sfb *b, t_sfc *arg)
{
	b->c = ft_strpskp(b->c, FT_WHITESPACE);
	if (!(arg->flag & SFF_IGNORE))
		arg->arg = va_arg(b->ap, void *);
	if (!valid_num(b->c, arg->maxwidth))
		return ((arg->flag & SFF_OPTIONAL) ? 0 : -1);
	ft_sfbuftoarg(b, arg, g_cmapup[8]);
	(*c)++;
	return ((arg->flag & SFF_IGNORE) ? 0 : 1);
}
