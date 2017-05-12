/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strconcur.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 17:54:22 by qloubier          #+#    #+#             */
/*   Updated: 2017/05/11 20:41:21 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_string.h"

int		ft_strconcur(const char *s1, const char *s2)
{
	while (*s1 == *(s2++) && *s1)
		s1++;
	s2--;
	if (*s2)
		return ((int)((unsigned char)(*s1) - (unsigned char)(*s2)));
	return (0);
}
