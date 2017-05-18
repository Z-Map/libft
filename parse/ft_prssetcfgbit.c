/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prssetcfgbit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 22:44:10 by qloubier          #+#    #+#             */
/*   Updated: 2017/05/17 23:48:25 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_parse.h"

int				ft_prssetcfgbit(t_gparse parser, int idx)
{
	if (!parser.cfgbits || idx < 0)
		return (0);
	ft_setbitfield(parser.cfgbits, (size_t)idx);
	return (1);
}
