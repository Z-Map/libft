/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_len_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 19:02:47 by qloubier          #+#    #+#             */
/*   Updated: 2016/05/10 19:10:52 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t		ft_int_len_base(register long i, unsigned char base)
{
	register size_t	len;

	len = (i < 0) ? 2 : 1;
	while ((i /= base) != 0)
		++len;
	return (len);
}
