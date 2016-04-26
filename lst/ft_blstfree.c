/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_blstfree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 19:46:18 by qloubier          #+#    #+#             */
/*   Updated: 2016/04/26 20:57:07 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_list.h"
#include <stdlib.h>

void			ft_blstfree(t_blst *blst)
{
	t_blst		*blsit;

	while (blst)
	{
		blsit = blst->next;
		free(blst);
		blst = blsit;
	}
}
