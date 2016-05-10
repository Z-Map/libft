/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 20:46:41 by qloubier          #+#    #+#             */
/*   Updated: 2016/05/08 14:46:43 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void		ft_putnbr(int n)
{
	char					buffer[11];
	register unsigned int	nbr;
	register size_t			len;

	len = 1;
	nbr = (unsigned int)((n < 0) ? -n : n);
	buffer[10] = '0' + (char)(nbr % 10);
	while ((nbr /= 10))
		buffer[10 - (len++)] = '0' + (char)(nbr % 10);
	if (n < 0)
		buffer[10 - (len++)] = '-';
	write(1, (buffer + (11 - len)), len);
}
