/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsearg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 17:39:12 by qloubier          #+#    #+#             */
/*   Updated: 2017/04/13 13:36:13 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft_parse.h"

static int		getsargs_len(int ac, char **av)
{
	int			ret;

	if (ac <= 0)
		return (0);
	ret = 0;
	while (ac-- && (**(av++) != '-'))
		ret++;
	return (ret);
}

static int		ltr_loop(t_argret *argp, t_arg *arglst, void *arg, size_t i)
{
	const char	**tab;
	int			tlen;

	tlen = getsargs_len(argp->ac - (int)i, argp->av + i);
	tab = (const char **)(t_ul)(argp->av);
}

static size_t	ltrarg_loop(t_argret *argp, t_arg *arglst, void *arg, size_t i)
{
	char		*c;
	int			ret;

	(argp->av[i])++;
	c = argp->av[i];
	while (*argp->av[i])
	{
		if ((ret = ltr_loop(argp, arglst, arg, i)))

	}
	return (1);
}

static size_t	wrdarg_loop(t_argret *argp, t_arg *arglst, void *arg, size_t i)
{
	const char	*wrd;
	const char	**tab;
	int			ret;

	wrd = (argp->av[i]) + 2;
	ret = getsargs_len(argp->ac - (int)i - 1, argp->av + i + 1);
	tab = (argp->ac == (int)i) ? NULL : (const char **)(t_ul)(argp->av + i + 1);
	while (arglst && !ft_strequ(arglst->argword, wrd))
		arglst = arglst->next;
	if (!arglst)
		return (1);
	if ((ret = arglst->cb(argp->av[i], arg, tab, ret)) < 0)
		return (1);
	argp->argp++;
	argp->av[i] = NULL;
	if (!ret)
		return (1);
	i = (size_t)ret;
	while (i--)
		*(tab++) = NULL;
	return ((size_t)(ret + 1));
}

t_argret		*ft_parsearg(t_arg *arglst, int argc, char **argv, void *arg)
{
	size_t		i;
	size_t		j;
	size_t		k;
	t_argret	*argp;

	if (!(argp = malloc(sizeof(t_argret))) ||
		!(argp->av = ft_stabndup((const char **)(t_ul)argv, (size_t)argc)))
		return (ft_mfree_ret(NULL, 1, &argp));
	argp->argp = 0;
	argp->ac = argc;
	i = 0;
	j = 0;
	while ((int)i < argc)
	{
		k = 1;
		if (!ft_strncmp(argp->av[i], "--", 2))
			k = wrdarg_loop(argp, arglst, arg, i);
		else if (argp->av[i][0] == '-')
			k = ltrarg_loop(argp, arglst, arg, i);
		if (argp->av[i])
			ft_swpptr(&(argp->av[j++]), &(argp->av[i]));
		i += k;
	}
	argp->ac = (int)j;
	return (argp);
}
