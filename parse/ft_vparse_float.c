/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vparse_float.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 23:10:48 by qloubier          #+#    #+#             */
/*   Updated: 2017/05/09 23:25:47 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_parse.h"

int				ft_vparse_float(t_val *val, void *mem, t_gparse parser)
{
	const char	*str;
	const char	*s;
	long double	num;
	int			ret;

	str = parser.cursor;
	s = ft_strpskp(str, FT_WHITESPACE);
	ret = ((t_ul)s - (t_ul)str);
	str = s;
	num = ft_buftold(&s, (int)parser.c_len, g_cmaplow[8]);
	if ((str == s) || (
		((*str == '-') || (*str == '+')) && ((t_ul)(s - str) == 1)))
		return (-1);
	ft_set_numval(val, mem, (t_numv)num, 0);
	return ((int)((t_ul)s - (t_ul)str) + ret);
}
