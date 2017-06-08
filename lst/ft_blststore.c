/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_blststore.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 18:39:30 by qloubier          #+#    #+#             */
/*   Updated: 2017/06/08 02:35:24 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_list.h"

void		*ft_blststore(t_blst *blst, void *data)
{
	void	*ret;

	if (!blst)
		return (NULL);
	while (blst->next && (blst->len == blst->bsize))
		blst = blst->next;
	if (blst->len == blst->bsize)
	{
		blst->next = ft_blstnew(blst->csize, blst->bsize);
		blst = blst->next;
	}
	if (!blst)
		return (NULL);
	ret = (void *)((unsigned long)blst->data + (blst->len * blst->csize));
	if (data)
		FT_MCPY(ret, data, blst->csize);
	else
		FT_BZERO(ret, blst->csize);
	blst->len += 1;
	return (ret);
}
