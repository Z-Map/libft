/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strparse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 23:47:10 by qloubier          #+#    #+#             */
/*   Updated: 2016/05/13 15:36:42 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_string.h"

char		*ft_strparse(char *str, char s, int (**parser)(char *, void *),
				void *param)
{
	int		ret;

	ret = 0;
	while (*str && *str != s)
		++str;
	if (*(str++) == s)
		while ((ret = parser[*(str)](str, param)) > 0)
			++str;
	return (ret);
}
