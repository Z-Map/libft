/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stabndup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 16:51:40 by qloubier          #+#    #+#             */
/*   Updated: 2017/03/10 17:29:22 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft_string.h"

char			**ft_stabndup(const char **tab, size_t n)
{
	size_t		i;
	FT_CC		**t;
	char		**ret;

	if (!tab)
		return (NULL);
	i = 1;
	t = tab;
	while (*(t++) && (n--))
		i++;
	if (!(ret = (char **)malloc(sizeof(char *) * i)))
		return (NULL);
	ret[--i] = NULL;
	while (i--)
		ret[i] = (char *)(t_ul)(tab[i]);
	return (ret);
}
