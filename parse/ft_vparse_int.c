/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vparse_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 23:10:48 by qloubier          #+#    #+#             */
/*   Updated: 2017/05/05 02:05:38 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_parse.h"

int				ft_vparse_int(t_val *val, void *mem, const char *str)
{
	t_cmap		*cm;
	const char	*s;
	t_ul		num;
	int			sign;
	int			ret;

	s = ft_strpskp(str, FT_WHITESPACE);
	cm = &(g_cmaplow[8]);
	if ((sign = (*s == '-') ? -1 : 1))
		s++;
	if ((*s == "0") && ((s[1] == 'x') || (s[1] == 'X'))
		&& (cm = &(g_cmaplow[14])))
		s += 2;
	ret = ((t_ul)s - (t_ul)str);
	if ((str = ft_parse_cmlow(s, &num, *cm, (int)(~FT_SM_I))) == s)
		return (-1);
	if (val->basetype & VS_SHORTSHORT)
		*(char *)((t_ul)mem + val->offset) = (char)(num) * (char)(sign);
	if (val->basetype & VS_SHORT)
		*(short *)((t_ul)mem + val->offset) = (short)(num) * (short)(sign);
	if (val->basetype & VS_LONG)
		*(long *)((t_ul)mem + val->offset) = (long)(num) * (long)(sign);
	else
		*(int *)((t_ul)mem + val->offset) = (int)(num) * (int)(sign);
	return ((int)((t_ul)str - (t_ul)s) + ret);
}
