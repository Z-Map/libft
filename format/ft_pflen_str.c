/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pflen_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 02:43:11 by qloubier          #+#    #+#             */
/*   Updated: 2016/10/04 16:51:13 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_format.h"

int		ft_pflen_str(t_pfc *arg)
{
	size_t	len;

	if (arg->arg)
		len = ft_strlen((char *)(arg->arg));
	else
		len = 6;
	arg->b_len = (int)len;
	if (len > arg->precision)
		len = arg->precision;
	return (len);
}
