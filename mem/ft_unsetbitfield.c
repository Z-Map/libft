/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetbitfield.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 22:56:57 by qloubier          #+#    #+#             */
/*   Updated: 2017/05/17 23:41:34 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_memory.h"

void			ft_unsetbitfield(char *mem, size_t idx)
{
	size_t		i;

	i = idx % 8;
	idx /= 8;
	mem[idx] &= ~(1 << i);
}
