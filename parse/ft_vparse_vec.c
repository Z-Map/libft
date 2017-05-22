/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vparse_vec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 17:25:16 by qloubier          #+#    #+#             */
/*   Updated: 2017/05/22 02:22:41 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_parse.h"

static int		vec_parse(t_val *val, void *mem, t_gparse parser)
{
	parser.end = FT_WHITESPACE;
	parser.seplst = NULL;
	parser.seplen = 0;
	parser.value = parser.cursor;
	parser.v_len = parser.c_len;
	parser.key = NULL;
	parser.k_len = 0;
	parser.mem = (void *)((t_ul)mem + val->offset);
	parser.cfgbits = NULL;
	return (ft_eparse(parser, val->descriptor, parser.mem));
}

static int		vec_strskip(t_val *val, void *mem, t_gparse parser)
{
	while (*parser.cursor && (*parser.cursor != '(') && parser.c_len--)
		parser.cursor++;
	if (!*(parser.cursor++))
		return (-1);
	parser.end = ",)";
	parser.seplst = NULL;
	parser.seplen = 0;
	parser.value = parser.cursor;
	parser.v_len = --parser.c_len;
	parser.key = NULL;
	parser.k_len = 0;
	parser.mem = (void *)((t_ul)mem + val->offset);
	parser.cfgbits = NULL;
	return (ft_eparse(parser, val->descriptor, parser.mem));
}

int				ft_vparse_vec(t_val *val, void *mem, t_gparse parser)
{
	int			ret;

	if (!parser.value)
		return (-1);
	parser.cursor = ft_strpskp(parser.value, FT_WHITESPACE);
	parser.c_len = parser.v_len - (size_t)(parser.cursor - parser.value);
	if ((*parser.cursor == 'v') || !ft_strconcur(parser.cursor, "vec")
		|| !ft_strconcur(parser.cursor, "t_v"))
		ret = vec_strskip(val, mem, parser);
	else
		ret = vec_parse(val, mem, parser);
	if (ret > 0)
		ft_prssetcfgbit(parser, val->idx);
	return (ret);
}
