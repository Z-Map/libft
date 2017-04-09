/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 15:52:23 by qloubier          #+#    #+#             */
/*   Updated: 2017/04/08 02:50:20 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_string.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
		if (*(s++) == (char)c)
			return ((char *)(unsigned long)(--s));
	return (c ? NULL : (char *)(unsigned long)s);
}
