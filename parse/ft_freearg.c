/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freearg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 18:17:36 by qloubier          #+#    #+#             */
/*   Updated: 2017/03/10 18:27:45 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft_parse.h"

static int	clean_arglst(t_arg **arglst)
{
	t_arg	*t;
	t_arg	*i;

	i = *arglst;
	while (i)
	{
		t = i->next;
		free(i);
		i = t;
	}
	*arglst = NULL;
	return (0);
}

int			ft_freearg(t_arg **arglst, t_argret *argp)
{
	int		ret;

	ret = 0;
	if (arglst && *arglst)
		ret = clean_arglst(arglst);
	if (argp)
	{
		if (argp->av)
			free(argp->av);
		free(argp);
	}
	return (ret);
}
