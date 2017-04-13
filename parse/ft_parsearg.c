/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsearg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 17:39:12 by qloubier          #+#    #+#             */
/*   Updated: 2017/04/13 16:46:00 by qloubier         ###   ########.fr       */
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
	const char	*wrd;
	const char	**tab;
	int			ret;

	ret = getsargs_len(argp->ac - (int)(i + 1), argp->av + i + 1);
	tab = (ret) ? (const char **)(t_ul)(argp->av + i + 1) : NULL;
	while (arglst && (argp->av[i][0] == arglst->letter))
		arglst = arglst->next;
	if (!arglst)
		return (-1);
	wrd = ((arglst->flag & FT_EQUAL_VALUE) && (argp->av[i][1] == '=')) ?
		argp->av[i] : arglst->buf;
	if ((ret = arglst->cb(wrd, arg, tab, ret)) < 0)
		return (-1);
	argp->argp++;
	argp->av[(int)i + ret] = argp->av[i] + ((*wrd != '-') ? FT_SLEN(wrd) : 1);
	i = (size_t)ret;
	while (i--)
		*(tab++) = NULL;
	return (ret);
}

static size_t	ltrarg_loop(t_argret *argp, t_arg *arglst, void *arg, size_t i)
{
	size_t		j;
	char		*c;
	int			ret;

	j = i;
	c = argp->av[i];
	while (*(++(argp->av[i])))
	{
		if ((ret = ltr_loop(argp, arglst, arg, i)) >= 0)
			c = NULL;
		i += (size_t)((ret < 0) ? 0 : ret);
	}
	argp->av[i] = c;
	return (1 + (i - j));
}

static size_t	wrdarg_loop(t_argret *argp, t_arg *arglst, void *arg, size_t i)
{
	const char	*wrd;
	const char	**tab;
	int			ret;

	wrd = (argp->av[i]) + 2;
	ret = getsargs_len(argp->ac - (int)i - 1, argp->av + i + 1);
	tab = (ret) ? (const char **)(t_ul)(argp->av + i + 1) : NULL;
	while (arglst && arglst->argword && ((arglst->flag & FT_EQUAL_VALUE) ?
		ft_strncmp(arglst->argword, wrd, FT_SLEN(arglst->argword)) :
		ft_strcmp(arglst->argword, wrd)))
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
			ft_swpptr((void **)&(argp->av[j++]), (void **)&(argp->av[i]));
		i += k;
	}
	argp->ac = (int)j;
	return (argp);
}
