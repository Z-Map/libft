/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eparse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 05:32:56 by qloubier          #+#    #+#             */
/*   Updated: 2017/05/16 20:41:01 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_parse.h"


int				ft_eparse(t_gparse parser, t_elm *elm, void *mem)
{
	int			i;
	t_ui		vid;

	i = 0;
	vid = 0;
	parser.cursor = parser.value;
	parser.c_len = parser.v_len;
	while (ft_enext(&parser))
	{
		ft_prstrim(&parser.cursor, &parser.c_len, FT_WHITESPACE);
		if (ft_evparse(parser, elm, mem, &vid) >= 0)
			i = 1;
	}
	return (i);
}
