/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pflen_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 02:43:11 by qloubier          #+#    #+#             */
/*   Updated: 2016/10/05 04:15:58 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft_format.h"

int		ft_pflen_str(t_pfc *arg)
{
	size_t	len;

	if (arg->arg)
	{
		if (arg->type == PFT_WSTR)
			len = ft_wstrlen((wchar_t *)(arg->arg)) * sizeof(wchar_t);
		else
			len = ft_strlen((char *)(arg->arg));
	}
	else
		len = 6;
	arg->b_len = (int)len;
	if (len > arg->precision)
		len = arg->precision;
	return (len);
}
