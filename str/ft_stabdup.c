/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stabdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 16:51:40 by qloubier          #+#    #+#             */
/*   Updated: 2017/03/10 17:28:59 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft_string.h"

char			**ft_stabdup(const char **tab)
{
	size_t		i;
	FT_CC		**t;
	char		**ret;

	if (!tab)
		return (NULL);
	i = 1;
	t = tab;
	while (*(t++))
		i++;
	if (!(ret = (char **)malloc(sizeof(char *) * i)))
		return (NULL);
	ret[--i] = NULL;
	while (i--)
		ret[i] = (char *)(t_ul)(tab[i]);
	return (ret);
}
