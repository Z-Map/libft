/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cbufnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/14 19:24:47 by qloubier          #+#    #+#             */
/*   Updated: 2016/05/14 19:28:30 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_list.h"
#include <stdlib.h>

t_cbuf		*ft_cbufnew(size_t bsize)
{
	t_cbuf	*ret;

	if (ret = (t_cbuf *)malloc())
	{
		*ret = 
		*(ret->data) = '\0';
	}
	return (ret);
}
