/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swpptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 20:04:08 by qloubier          #+#    #+#             */
/*   Updated: 2017/04/11 20:25:42 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_memory.h"

void			ft_swpptr(void **ptra, void **ptrb)
{
	register void	*a;
	register void	*b;

	a = *ptra;
	b = *ptrb;
	*ptra = b;
	*ptrb = a;
}
