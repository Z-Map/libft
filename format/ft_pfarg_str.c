/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pfarg_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 19:56:26 by qloubier          #+#    #+#             */
/*   Updated: 2016/05/22 07:44:21 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_format.h"

void			ft_pfarg_str(va_list ap, t_ptfc *arg)
{
	arg->type = PFT_STR;
	arg->arg = (uintmax_t)va_arg(ap, void *);
}
