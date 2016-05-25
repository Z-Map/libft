/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cbufnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/14 19:24:47 by qloubier          #+#    #+#             */
/*   Updated: 2016/05/22 07:25:49 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_list.h"
#include <stdlib.h>

t_cbuf		*ft_cbufnew(size_t bsize)
{
	t_cbuf	*ret;

	if ((ret = (t_cbuf *)malloc(sizeof(t_cbuf) + bsize + 1)))
	{
		*ret = (t_cbuf){bsize, 0, (char *)(ret + sizeof(t_cbuf)), NULL};
		*(ret->data) = '\0';
	}
	return (ret);
}
