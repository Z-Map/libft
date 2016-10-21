/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pfconv_float.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: map <marvin@student.42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 23:01:47 by map               #+#    #+#             */
/*   Updated: 2016/10/21 04:22:57 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"

void					ft_pfconv_float(t_pfb *b, t_pfc *arg, size_t len)
{
	len -= (size_t)arg->b_len;
	ft_printf_bwrite(b, arg->tmpb, (size_t)(arg->b_len));
	ft_printf_bwritec(b, '0', (size_t)len);
}
