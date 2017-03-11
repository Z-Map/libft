/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setarg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 15:09:55 by qloubier          #+#    #+#             */
/*   Updated: 2017/03/10 18:37:11 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft_parse.h"

t_arg				*ft_setarg(t_arg **arglst, char c, FT_CC *str,
						int (*cb)(FT_CC *, void *, FT_CC **, int))
{
	const size_t	slen = ft_strlen(str);
	t_arg			*arg;
	t_arg			*i;

	if (!(arg = malloc(sizeof(t_arg) + slen + 1)))
		return (NULL);
	*arg = (t_arg){ .letter = c, .buf = {'-', c, '\0'}, .flag = 0,
		.argword = (((char *)arg) + sizeof(t_arg)), .cb = cb, .next = NULL};
	ft_strcpy(arg->argword, str);
	if (!(*arglst))
		*arglst = arg;
	else
	{
		i = *arglst;
		while (i->next)
			i = i->next;
		i->next = arg;
	}
	return (arg);
}
