/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pfarg_n.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 01:47:47 by qloubier          #+#    #+#             */
/*   Updated: 2016/10/01 01:49:35 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_format.h"

void			ft_pfarg_n(va_list ap, t_pfc *arg)
{
	arg->type = PFT_N;
	arg->arg = (uintmax_t)va_arg(ap, void *);
}
