/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsttotab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 16:09:23 by qloubier          #+#    #+#             */
/*   Updated: 2016/03/21 15:20:52 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft_list.h"

t_slst				ft_lsttotab(t_list *node, size_t ts)
{
	unsigned long	len;
	void			*tab;
	t_slst			ret;

	ret = (t_slst){0, NULL};
	len = (unsigned long)ft_lstlen(node);
	if ((len == 0) || !(tab = malloc(len * ts)))
		return (ret);
	ret.len = len;
	len = 0;
	while (node)
	{
		ft_memcpy((void *)((char *)tab + len), node->content, ts);
		len += ts;
		node = node ->next;
	}
	ret.data = tab;
	return (ret);
}
