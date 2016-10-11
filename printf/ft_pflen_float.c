/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pflen_float.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 02:43:11 by qloubier          #+#    #+#             */
/*   Updated: 2016/10/04 17:13:44 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"

int		ft_pflen_float(t_pfc *arg)
{
	size_t	len;

	len = ft_floatlen(*((double *)(&(arg->arg))), arg->precision);
	return ((int)len);
}
