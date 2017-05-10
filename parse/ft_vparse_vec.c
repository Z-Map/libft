/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vparse_vec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 17:25:16 by qloubier          #+#    #+#             */
/*   Updated: 2017/05/10 19:45:42 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_parse.h"

static int		vec_parse(t_val *val, void *mem, t_gparse parser)
{

}

int				ft_vparse_vec(t_val *val, void *mem, t_gparse parser)
{
	const char	*s;
	int			ret;

	s = ft_strpskp(str, FT_WHITESPACE);
	if (*s == 'v')
		ret = vec_parse(val, mem, s);

}
