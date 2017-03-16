/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsearg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 17:39:12 by qloubier          #+#    #+#             */
/*   Updated: 2017/03/16 17:04:55 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft_parse.h"

t_argret		*ft_parsearg(t_arg *arglst, int argc, char **argv, void *arg)
{
	t_argret	*argp;

	if (!(argp = malloc(sizeof(t_argret))) ||
		!(argp->av = ft_stabndup((const char **)(t_ul)argv, (size_t)argc)))
		return (NULL);
	argp->ac = argc;
	(void)arglst;
	(void)arg;
	return (argp);
}
