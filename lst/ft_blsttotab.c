/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_blsttotab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 19:58:15 by qloubier          #+#    #+#             */
/*   Updated: 2016/04/26 20:57:47 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_list.h"
#include <stdlib.h>

void		*ft_blsttotab(t_blst *blst)
{
	void	*tab;
	size_t	i;

	if (!(tab = malloc(blst->csize * ft_blstlen(blst))))
		return (NULL);
	i = 0;
	while (blst)
	{
		ft_memcpy(tab + i, blst->data, blst->len * blst->csize);
		i += blst->len * blst->csize;
		blst = blst->next;
	}
	return (tab);
}
