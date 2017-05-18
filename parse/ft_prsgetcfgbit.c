/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prsgetcfgbit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 22:44:40 by qloubier          #+#    #+#             */
/*   Updated: 2017/05/17 23:48:17 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_parse.h"

int				ft_prsgetcfgbit(t_gparse parser, int idx)
{
	if (!parser.cfgbits || idx < 0)
		return (0);
	return (ft_getbitfield(parser.cfgbits, (size_t)idx));
}
