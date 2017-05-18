/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vparse_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 09:40:36 by qloubier          #+#    #+#             */
/*   Updated: 2017/05/18 13:34:38 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_parse.h"

#include "libft_printf.h"

int				ft_vparse_str(t_val *val, void *mem, t_gparse parser)
{
	char		*s;

	if (!parser.value || !parser.v_len)
		return (-1);
	ft_prstrim(&(parser.value), &(parser.v_len), FT_WHITESPACE);
	if ((parser.v_len > 1) && ft_strchr(FT_STRLIMITER,(int)(*parser.value))
		&& (*parser.value == parser.value[parser.v_len - 1]))
	{
		parser.v_len -= 2;
		parser.value++;
	}
	if ((s = ft_strnew(parser.v_len)))
		val->descriptor->setter(val, mem, s);
	else
		return (-1);
	ft_memcpy(s, parser.value, parser.v_len);
	s[parser.v_len] = '\0';
	return ((int)parser.v_len);
}
