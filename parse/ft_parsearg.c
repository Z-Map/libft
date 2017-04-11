/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsearg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 17:39:12 by qloubier          #+#    #+#             */
/*   Updated: 2017/04/10 18:00:04 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft_parse.h"

static size_t	letterarg_loop(t_argret *argp, t_arg *arglst, void *arg)
{

}

static size_t	wordarg_loop(t_argret *argp, t_arg *arglst, void *arg)
{

}

t_argret		*ft_parsearg(t_arg *arglst, int argc, char **argv, void *arg)
{
	size_t		i;
	t_argret	*argp;

	if (!(argp = malloc(sizeof(t_argret))) ||
		!(argp->av = ft_stabndup((const char **)(t_ul)argv, (size_t)argc)))
		return (ft_mfree_ret(NULL, 1, &argp));
	argp->argp = 0;
	argp->ac = argc;
	i = 0;
	while (i < argc)
	{
		if (argp->av[i][0] == '-')
		{
			if (argp->av[i][1] == '-')
				i +=
			else
				i +=
		}
	}
	return (argp);
}
