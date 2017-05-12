/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vparse_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 23:10:48 by qloubier          #+#    #+#             */
/*   Updated: 2017/05/12 10:54:50 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_parse.h"

int				ft_vparse_int(t_val *val, void *mem, t_gparse parser)
{
	t_cmap		*cm;
	const char	*s;
	t_numv		num;
	int			sign;
	int			ret;

	if (!parser.value)
		return (-1);
	s = ft_strpskp(parser.value, FT_WHITESPACE);
	cm = &(g_cmaplow[8]);
	if ((((sign = (*s == '-') ? -1 : 1) < 0) || *s == '+') && s++)
		parser.v_len--;
	if ((*s == '0') && ((s[1] == 'x') || (s[1] == 'X')) && (parser.v_len -= 2)
		&& (cm = &(g_cmaplow[14])))
		s += 2;
	ret = (int)((t_ul)s - (t_ul)parser.value);
	if ((parser.value = ft_parse_cmlow(
		s, &(num.ul), *cm, (int)parser.v_len - ret)) == s)
		return (-1);
	ft_set_numval(val, mem, num, sign);
	return ((int)((t_ul)parser.value - (t_ul)s) + ret);
}
