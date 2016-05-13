/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 19:02:47 by qloubier          #+#    #+#             */
/*   Updated: 2016/05/13 14:44:15 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t		ft_nbrlen_base(register long i, char base)
{
	register size_t	len;

	len = (i < 0) ? 2 : 1;
	while ((i /= base) != 0)
		++len;
	return (len);
}
