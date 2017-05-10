/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vparse_uint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 23:10:48 by qloubier          #+#    #+#             */
/*   Updated: 2017/05/09 23:21:58 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_parse.h"

int				ft_vparse_uint(t_val *val, void *mem, t_gparse parser)
{
	t_cmap		*cm;
	const char	*s;
	t_ul		num;
	int			ret;

	s = ft_strpskp(parser.cursor, FT_WHITESPACE);
	cm = &(g_cmaplow[8]);
	if ((*s == "0") && ((s[1] == 'x') || (s[1] == 'X'))
		&& (cm = &(g_cmaplow[14])))
		s += 2;
	ret = ((t_ul)s - (t_ul)parser.cursor);
	if ((parser.cursor = ft_parse_cmlow(
		s, &num, *cm, (int)parser.c_len - ret)) == s)
		return (-1);
	ft_set_numval(val, mem, (t_numv)num, 0);
	return ((int)((t_ul)parser.cursor - (t_ul)s) + ret);
}
