/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsttotab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 16:09:23 by qloubier          #+#    #+#             */
/*   Updated: 2017/04/08 02:30:59 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft_list.h"

void				*ft_lsttotab(t_list *node, size_t ts, size_t *len)
{
	unsigned long	i;
	void			*tab;

	*len = ft_lstlen(node);
	if ((len == 0) || !(tab = malloc(*len * ts)))
		return (NULL);
	i = 0;
	while (node)
	{
		FT_MCPY((void *)((char *)tab + i), node->content, ts);
		i += ts;
		node = node->next;
	}
	return (tab);
}
