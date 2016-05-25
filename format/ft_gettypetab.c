/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gettypetab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 19:15:42 by qloubier          #+#    #+#             */
/*   Updated: 2016/05/22 07:30:45 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_format.h"

static void			**ft_get_args_parse(void)
{
	return ((void *[]){ &ft_pfarg_nbr, &ft_pfarg_nbr, &ft_pfarg_oct,
		&ft_pfarg_char, &ft_pfarg_str, &ft_pfarg_wstr, &ft_pfarg_float,
		&ft_pfarg_ptr, &ft_pfarg_hexa, &ft_pfarg_unbr, &ft_pfarg_spc });
}

void				**ft_gettypetab(int i)
{
	if (i == 1)
		return (ft_get_args_parse());
	else
		return (NULL);
}
