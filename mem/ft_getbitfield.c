/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getbitfield.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 22:56:57 by qloubier          #+#    #+#             */
/*   Updated: 2017/05/17 23:47:20 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_memory.h"

int				ft_getbitfield(char *mem, size_t idx)
{
	size_t		i;

	i = idx % 8;
	idx /= 8;
	return ((mem[idx] & (1 << i)) ? 1 : 0);
}
