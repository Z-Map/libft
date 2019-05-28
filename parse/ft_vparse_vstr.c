/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vparse_vstr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 09:40:36 by qloubier          #+#    #+#             */
/*   Updated: 2019/05/28 15:05:44 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_parse.h"

int				ft_vparse_str(t_val *val, void *mem, t_gparse parser)
{
	char		*s;

	if (!parser.value)
		return (-1);
	ft_prstrim(&(parser.value), &(parser.v_len), FT_WHITESPACE);
	if ((parser.v_len > 1) && ft_strchr(FT_STRLIMITER, (int)*parser.value)
		&& (*parser.value == parser.value[parser.v_len - 1]))
	{
		parser.v_len -= 2;
		parser.value++;
	}
	if ((s = ft_vsnew((short)parser.v_len)))
		val->descriptor->setter(val, mem, s);
	else
		return (-1);
	ft_memcpy(s, parser.value, parser.v_len);
	s[parser.v_len] = '\0';
	return ((int)parser.v_len);
}
