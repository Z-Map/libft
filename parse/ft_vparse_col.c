/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vparse_col.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 17:25:16 by qloubier          #+#    #+#             */
/*   Updated: 2017/05/18 11:31:13 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_parse.h"

static int		colvec_parse(t_gparse parser, t_ul *num)
{
	const t_val	cv = {VT_VEC4F, 0, 0, 0, "rgba", (t_elm *)(t_ul)&g_el_vec4f};
	float		vec[4];
	int			ret;
	t_ui		i;

	vec[0] = 0.0f;
	vec[1] = 0.0f;
	vec[2] = 0.0f;
	vec[3] = 1.0f;
	if (!ft_strconcur(parser.cursor, "rgb"))
		ft_prsbrk(&parser.cursor, &parser.c_len, "(", NULL);
	parser.value = parser.cursor;
	parser.v_len = parser.c_len;
	parser.mem = vec;
	parser.cfgbits = NULL;
	ret = ft_vparse_vec((t_val *)(t_ul)&cv, vec, parser);
	i = 4;
	while (i--)
		if ((vec[i] >= 0.0f) && (vec[i] <= 1.0f))
			vec[i] *= 255;
	*num = (t_ul)(((t_uc)vec[0] << 24) | ((t_uc)vec[1] << 16)
		| ((t_uc)vec[2] << 8) | (t_uc)vec[3]);
	return (ret);
}

int				ft_vparse_col(t_val *val, void *mem, t_gparse parser)
{
	int			ret;
	t_ul		num;

	if (!parser.value)
		return (-1);
	parser.cursor = ft_strpskp(parser.value, FT_WHITESPACE);
	parser.c_len = parser.v_len - (size_t)(parser.cursor - parser.value);
	if ((*parser.cursor == '#') && --parser.v_len)
	{
		parser.cursor++;
		ret = (int)(ft_parse_cmlow(parser.cursor, &num, g_cmaplow[14],
			(int)parser.v_len) - parser.cursor);
		ret = (ret) ? ret : -1;
	}
	else
		ret = colvec_parse(parser, &num);
	if (ret < 0)
		return (ret);
	*(t_ui *)((t_ul)mem + val->offset) = (t_ui)num;
	ft_prssetcfgbit(parser, val->idx);
	return (ret);
}
