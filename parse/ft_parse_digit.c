/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_digit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 03:53:28 by qloubier          #+#    #+#             */
/*   Updated: 2016/10/05 01:27:24 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft_parse.h"

const char			*ft_parse_digit(const char *str, unsigned int *num)
{
	int				i;

	*num = 0;
	i = 0;
	while (ft_isdigit((int)(*str)))
	{
		*num = ((*num * 10) + (unsigned int)(*(str++) - '0'));
		i++;
	}
	// write(1, "[digit parse : ", 15);
	// write(1, str - i, i + 1);
	// write(1, "]\n", 2);
	return (str);
}
