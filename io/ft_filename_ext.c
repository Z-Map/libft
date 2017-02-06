/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filename_ext.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 00:04:51 by qloubier          #+#    #+#             */
/*   Updated: 2017/02/07 00:55:49 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_io.h"

size_t	ft_filename_ext(char *buf, const char *path, const char *ext, size_t l)
{
	size_t		i;

	i = l;
	while ((i--) && (*path))
		*(buf++) = *(path++);
	while ((i--) && (*ext))
		*(buf++) = *(ext++);
	if (!i)
		buf--;
	*buf = '\0';
	return (l - i);
}
