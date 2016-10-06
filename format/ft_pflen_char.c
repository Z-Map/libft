/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pflen_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 02:43:11 by qloubier          #+#    #+#             */
/*   Updated: 2016/10/06 04:39:27 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_format.h"

int		ft_pflen_char(t_pfc *arg)
{
	if (arg->flag & (LONG | LONG_LONG | CAPITAL))
		arg->b_len = ft_utf8wcsize((wchar_t)arg->arg);
	else
		arg->b_len = 1;
	if ((arg->flag & ZERO_FILL) && !(arg->flag & LEFT_ALIGN)
		&& (arg->minwidth))
		return (arg->minwidth);
	return (1);
}
