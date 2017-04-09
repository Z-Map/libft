/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sfconv_f.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: map <map@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 20:45:33 by map               #+#    #+#             */
/*   Updated: 2017/03/07 11:42:44 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_parse.h"

static int			valid_num(const char *s, int len)
{
	if ((len > 1) && ((*s == '+') || (*s == '-')))
		++s;
	if (FT_SCHR(FT_DECIMAL_DIGIT, (int)*s))
		return (1);
	return (0);
}

int					ft_sfconv_f(const char **c, t_sfb *b, t_sfc *arg)
{
	(*c)++;
	b->c = ft_strpskp(b->c, FT_WHITESPACE);
	if (!(arg->flag & SFF_IGNORE))
		arg->arg = va_arg(b->ap, void *);
	if (!valid_num(b->c, arg->maxwidth))
		return (((arg->flag & SFF_OPTIONAL) && (*c)++) ? 0 : -1);
	ft_sfbuftofarg(b, arg, g_cmapup[8]);
	return ((arg->flag & SFF_IGNORE) ? 0 : 1);
}
