/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsnew.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 16:45:37 by qloubier          #+#    #+#             */
/*   Updated: 2017/04/22 02:40:11 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_string.h"

char				*ft_vsnew(short size)
{
	static t_vmem	*vm;

	if (!vm)
		vm = ft_vmemnew(FT_VSBUF);
	if (size >= 0)
		return ((char *)ft_vmemalloc(vm, size + 1));
	return (NULL);
}
