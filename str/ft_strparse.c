/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strparse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 23:47:10 by qloubier          #+#    #+#             */
/*   Updated: 2016/05/10 23:54:46 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_string.h"

char		*ft_strparse(char *str, char s, int (**parser)(char *, void *),
				void *param)
{
	while (*str && *str != s)
		++str;
	if (*str == s)
		while (parser[*()](*str))

}
