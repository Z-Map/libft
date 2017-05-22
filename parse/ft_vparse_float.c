/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vparse_float.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 23:10:48 by qloubier          #+#    #+#             */
/*   Updated: 2017/05/22 03:33:35 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_parse.h"

int				ft_vparse_float(t_val *val, void *mem, t_gparse parser)
{
	const char	*str;
	const char	*s;
	t_numv		num;
	int			ret;

	if (!parser.value)
		return (-1);
	str = parser.value;
	s = ft_strpskp(str, FT_WHITESPACE);
	ret = (int)((t_ul)s - (t_ul)str);
	str = s;
	if (val->basetype & VS_LONGLONG)
		num.ld = ft_buftold(&s, (int)parser.v_len - ret, g_cmaplow[8]);
	else if (val->basetype & VS_LONG)
		num.d = ft_buftod(&s, (int)parser.v_len - ret, g_cmaplow[8]);
	else
		num.f = ft_buftof(&s, (int)parser.v_len - ret, g_cmaplow[8]);
	if ((str == s) || (
		((*str == '-') || (*str == '+')) && ((t_ul)(s - str) == 1)))
		return (-1);
	ft_set_numval(val, mem, num, 0);
	return ((int)((t_ul)s - (t_ul)str) + ret);
}
