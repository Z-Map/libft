/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eparse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 05:32:56 by qloubier          #+#    #+#             */
/*   Updated: 2019/05/28 14:51:56 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_parse.h"

int				ft_eparse(t_gparse parser, t_elm *elm, void *mem)
{
	int			i;
	int			r;
	int			vid;

	i = -1;
	vid = 0;
	parser.cursor = parser.value;
	parser.c_len = parser.v_len;
	while (ft_enext(&parser))
	{
		ft_prstrim(&parser.key, &parser.k_len, FT_WHITESPACE);
		if ((r = ft_evparse(parser, elm, mem, &vid)) >= -1)
			i = (i < 0) ? 0 : i;
		if (r >= 0)
			i++;
	}
	return (i);
}
