/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 02:37:49 by qloubier          #+#    #+#             */
/*   Updated: 2016/05/17 11:12:25 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int		ft_printf(const char *fstr, ...)
{
	va_list		ap;
	int			len;
	t_list		*args;

	if (!fstr)
		return (-1);
	va_start(ap, fstr);
	len = ft_preform_count(fstr, ap, &args);
	va_end(ap);
	ft_print_buff(fstr, len, args);
	return (len);
}
