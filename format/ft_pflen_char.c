/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pflen_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 02:43:11 by qloubier          #+#    #+#             */
/*   Updated: 2016/10/05 18:48:50 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_format.h"

int		ft_pflen_char(t_pfc *arg)
{
	arg->b_len = 1;
	if ((arg->flag & ZERO_FILL) && !(arg->flag & LEFT_ALIGN)
		&& (arg->minwidth))
		return (arg->minwidth);
	return (1);
}
