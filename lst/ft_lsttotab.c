/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsttotab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 16:09:23 by qloubier          #+#    #+#             */
/*   Updated: 2016/03/20 02:23:25 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft_list.h"

void			*ft_lsttotab(t_list *node, size_t ts)
{
	unsigned long	len;
	void			*tab;

	len = (unsigned long)(ft_lstlen(node) * ts);
	if ((len == 0) || !(tab = malloc(len)))
		return (NULL);
	len = 0;
	while (node)
	{
		ft_memcpy((void *)((char *)tab + len), node->content, ts);
		len += ts;
		node = node ->next;
	}
	return (tab);
}
