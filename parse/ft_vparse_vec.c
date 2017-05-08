/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vparse_vec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 17:25:16 by qloubier          #+#    #+#             */
/*   Updated: 2017/05/08 06:16:23 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_parse.h"

static int		vec_parse(t_val *val, void *mem, const char *str)
{
	
}

int				ft_vparse_vec(t_val *val, void *mem, const char *str)
{
	const char	*s;
	int			ret;

	s = ft_strpskp(str, FT_WHITESPACE);
	if (*s == 'v')
		ret = vec_parse(val, mem, s);

}
