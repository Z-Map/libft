/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pfconv_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 22:58:48 by map               #+#    #+#             */
/*   Updated: 2016/10/05 18:56:30 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_format.h"

void			ft_pfconv_char(t_pfb *b, t_pfc *arg, size_t len)
{
	if (len > 1)
		ft_printf_bwritec(b, '0', len - 1);
	ft_printf_bwritec(b, (char)(arg->arg), arg->b_len);
}
