/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_blsttotab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 19:58:15 by qloubier          #+#    #+#             */
/*   Updated: 2017/04/08 02:15:37 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft_list.h"

void		*ft_blsttotab(t_blst *blst, size_t *len)
{
	char	*tab;
	size_t	i;

	if (!blst || !(tab = (char *)malloc(blst->csize * ft_blstlen(blst))))
		return (NULL);
	*len = 0;
	i = 0;
	while (blst)
	{
		FT_MCPY(tab + i, blst->data, blst->len * blst->csize);
		*len += blst->len;
		i += blst->len * blst->csize;
		blst = blst->next;
	}
	return (tab);
}
