/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_len.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 13:51:04 by qloubier          #+#    #+#             */
/*   Updated: 2016/05/04 14:18:27 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t		ft_int_len(int i)
{
	register size_t	len;

	len = (i < 0) ? 1 : 0;
	i = (i < 0) ? -i : i;
	if (i < 10)
		return (len + 1);
	else if (i < 100)
		return (len + 2);
	else if (i < 1000)
		return (len + 3);
	else if (i < 10000)
		return (len + 4);
	else if (i < 100000)
		return (len + 5);
	else if (i < 1000000)
		return (len + 6);
	else if (i < 10000000)
		return (len + 7);
	else if (i < 100000000)
		return (len + 8);
	else if (i < 1000000000)
		return (len + 9);
	return (len + 10);
}
