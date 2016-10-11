/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pfconv_float.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: map <map@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 23:01:47 by map               #+#    #+#             */
/*   Updated: 2016/10/05 00:20:04 by map              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"

void					ft_pfconv_float(t_pfb *b, t_pfc *arg, size_t len)
{
	len = 0;
	if (arg->flag & PFF_ALTERNTE)
		ft_printf_bwrite(b, "[%#f]", 5);
	else
		ft_printf_bwrite(b, "[%f]", 4);
}
