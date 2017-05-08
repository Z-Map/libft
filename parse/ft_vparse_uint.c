/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vparse_uint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 23:10:48 by qloubier          #+#    #+#             */
/*   Updated: 2017/05/05 02:33:03 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_parse.h"

int				ft_vparse_uint(t_val *val, void *mem, const char *str)
{
	t_cmap		*cm;
	const char	*s;
	t_ul		num;
	int			ret;

	s = ft_strpskp(str, FT_WHITESPACE);
	cm = &(g_cmaplow[8]);
	if ((*s == "0") && ((s[1] == 'x') || (s[1] == 'X'))
		&& (cm = &(g_cmaplow[14])))
		s += 2;
	ret = ((t_ul)s - (t_ul)str);
	if ((str = ft_parse_cmlow(s, &num, *cm, (int)(~FT_SM_I))) == s)
		return (-1);
	if (val->basetype & VS_SHORTSHORT)
		*(t_uc *)((t_ul)mem + val->offset) = (t_uc)(num);
	if (val->basetype & VS_SHORT)
		*(short *)((t_ul)mem + val->offset) = (unsigned short)(num);
	if (val->basetype & VS_LONG)
		*(t_ul *)((t_ul)mem + val->offset) = num;
	else
		*(t_ui *)((t_ul)mem + val->offset) = (t_ui)(num);
	return ((int)((t_ul)str - (t_ul)s) + ret);
}
