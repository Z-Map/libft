/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strichr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 19:30:06 by qloubier          #+#    #+#             */
/*   Updated: 2016/01/09 20:07:38 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_string.h"

char	*ft_strchrnot(const char *s, int c)
{
	while (*s && *s == (char)c)
		s++;
	return ((*s && c) ? (char *)s : NULL);
}
