/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eparse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 05:32:56 by qloubier          #+#    #+#             */
/*   Updated: 2017/05/12 06:30:49 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_parse.h"


int				ft_eparse(t_gparse parser, t_elm *elm, void *mem)
{
	int			i;
	int			vid;

	i = -1;
	vid = 0;
	parser.cursor = parser.value;
	parser.c_len = parser.v_len;
	while (ft_enext(&parser))
	{

	}
	return (i);
}
