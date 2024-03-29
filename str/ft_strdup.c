/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strdup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 17:18:23 by qloubier          #+#    #+#             */
/*   Updated: 2015/12/22 17:08:05 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_string.h"

char	*ft_strdup(const char *s1)
{
	char *nstr;

	nstr = ft_strnew(FT_SLEN(s1));
	if (nstr)
		FT_SCPY(nstr, s1);
	return (nstr);
}
