/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_blstfree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 19:46:18 by qloubier          #+#    #+#             */
/*   Updated: 2016/07/09 19:33:17 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft_list.h"

void			ft_blstfree(t_blst **blst)
{
	t_blst		*blsit;

	while (blst && *blst)
	{
		blsit = (*blst)->next;
		free((void *)(*blst));
		(*blst) = blsit;
	}
	*blst = NULL;
}
