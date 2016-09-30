/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pfarg_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 19:56:26 by qloubier          #+#    #+#             */
/*   Updated: 2016/09/30 07:29:55 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_format.h"

void			ft_pfarg_char(va_list ap, t_pfc *arg)
{
	arg->type = PFT_CHAR;
	arg->arg = va_arg(ap, int);
}
