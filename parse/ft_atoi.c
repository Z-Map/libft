/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 14:22:15 by qloubier          #+#    #+#             */
/*   Updated: 2016/07/09 19:58:24 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_parse.h"

int		ft_atoi(const char *str)
{
	unsigned int	ret;
	char			sig;

	ret = 0;
	while (ft_strchr(" \f\n\r\t\v", (int)(*str)) != NULL)
		str++;
	sig = (*str == '-') ? '-' : '+';
	if (*str == '+' || *str == '-')
		str++;
	while (ft_isdigit((int)(*str)))
		ret = ((ret * 10) + (unsigned int)(*(str++) - '0'));
	return ((int)(sig == '+' ? ret : 4294967296 - ret));
}
