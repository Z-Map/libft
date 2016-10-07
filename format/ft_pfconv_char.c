/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pfconv_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: map <marvin@student.42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 22:58:48 by map               #+#    #+#             */
/*   Updated: 2016/10/06 04:47:16 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_format.h"

void			ft_pfconv_char(t_pfb *b, t_pfc *arg, size_t len)
{
	wchar_t		cb;

	if ((int)len > arg->b_len)
		ft_printf_bwritec(b, '0', len - (unsigned int)arg->b_len);
	if (arg->flag & (PFF_LONG | PFF_LONG_LONG | PFF_CAPITAL))
	{
		cb = (wchar_t)(arg->arg);
		ft_printf_bwritew(b, &cb, arg->b_len);
	}
	else
		ft_printf_bwritec(b, (char)(arg->arg), arg->b_len);
}
