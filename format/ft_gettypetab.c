/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gettypetab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 19:15:42 by qloubier          #+#    #+#             */
/*   Updated: 2016/05/19 16:52:10 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_format.h"

static void			**ft_get_args_parse(void)
{
	return ((void *[]){ &ft_parse_nbr, &ft_parse_nbr, &ft_parse_oct,
		&ft_parse_char, &ft_parse_str, &ft_parse_wstr, &ft_parse_float,
		&ft_parse_ptr, &ft_parse_hexa, &ft_parse_unbr, &ft_parse_spc });
}

void				**ft_gettypetab(int i)
{
	if (i == 1)
		return (ft_get_args_parse());
}
