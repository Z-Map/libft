/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mfree_ret.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 17:03:47 by qloubier          #+#    #+#             */
/*   Updated: 2017/04/10 17:49:21 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft_memory.h"

void			*ft_mfree_ret(void *ret, size_t num, ...)
{
	va_list		ap;
	void		**p;

	va_start(ap, num);
	while (num--)
	{
		p = va_arg(ap, (void *));
		if (p && *p)
		{
			free(*p);
			*p = NULL;
		}
	}
	va_end(ap);
	return (ret);
}
