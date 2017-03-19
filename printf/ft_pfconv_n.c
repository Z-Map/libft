/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pfconv_n.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: map <map@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 00:03:05 by map               #+#    #+#             */
/*   Updated: 2017/03/19 13:14:59 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"

void			ft_pfconv_n(t_pfb *b, t_pfc *arg, size_t len)
{
	len = 0;
	(void)len;
	if ((arg->type == PFT_N) && (arg->arg))
		*((int *)(arg->arg)) = b->blen + (int)(b->len);
}
