/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gettypetab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 19:15:42 by qloubier          #+#    #+#             */
/*   Updated: 2016/05/18 19:25:56 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_format.h"

static void			**ft_get_args_parse()
{
	return ((void *[]){});
}

void				**ft_gettypetab(int i)
{
	if (i == 1)
		return (ft_get_args_parse());
}
