/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pfargvec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 01:06:56 by qloubier          #+#    #+#             */
/*   Updated: 2019/05/28 15:07:25 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"

static void	getunbr(void *ptr, t_ui i, t_pfc *arg)
{
	if (arg->flag & PFF_INTMAX)
		arg->arg = ((uintmax_t *)ptr)[i];
	else if (arg->flag & PFF_SIZE_T)
		arg->arg = ((size_t *)ptr)[i];
	else if (arg->flag & PFF_LONG_LONG)
		arg->arg = ((unsigned long long *)ptr)[i];
	else if ((arg->flag & PFF_LONG) ||
		((arg->flag & PFF_CAPITAL) && (arg->type != PFT_HEXA)))
		arg->arg = ((unsigned long *)ptr)[i];
	else if (arg->flag & PFF_SHORT)
		arg->arg = ((unsigned short *)ptr)[i];
	else if (arg->flag & PFF_SHORT_SHORT)
		arg->arg = ((unsigned char *)ptr)[i];
	else
		arg->arg = ((unsigned int *)ptr)[i];
}

static void	getnbr(void *ptr, t_ui i, t_pfc *arg)
{
	if (arg->flag & PFF_INTMAX)
		arg->arg = (uintmax_t)(((intmax_t *)ptr)[i]);
	else if (arg->flag & PFF_SIZE_T)
		arg->arg = (uintmax_t)(intmax_t)(((size_t *)ptr)[i]);
	else if (arg->flag & PFF_LONG_LONG)
		arg->arg = (uintmax_t)(intmax_t)(((long long *)ptr)[i]);
	else if (arg->flag & (PFF_LONG | PFF_CAPITAL))
		arg->arg = (uintmax_t)(intmax_t)(((long *)ptr)[i]);
	else if (arg->flag & PFF_SHORT)
		arg->arg = (uintmax_t)(intmax_t)(((short *)ptr)[i]);
	else if (arg->flag & PFF_SHORT_SHORT)
		arg->arg = (uintmax_t)(intmax_t)(((char *)ptr)[i]);
	else
		arg->arg = (uintmax_t)(intmax_t)(((int *)ptr)[i]);
}

static void	getfnbr(void *ptr, t_ui i, t_pfc *arg)
{
	double	d;
	t_ul	*pul;

	pul = (t_ul *)&d;
	if (arg->flag & (PFF_LONG | PFF_CAPITAL))
		d = ((double *)ptr)[i];
	else
		d = (double)(((float *)ptr)[i]);
	arg->arg = *pul;
}

t_pfc		ft_pfargvec(t_pfc arg, t_ui i)
{
	if (arg.type == PFT_INT)
		getnbr((void *)arg.arg, i, &arg);
	else if ((arg.type == PFT_STR) || (arg.type == PFT_WSTR))
		arg.arg = (uintmax_t)(((char *)arg.arg)[i]);
	else if (arg.type == PFT_FLOAT)
		getfnbr((void *)arg.arg, i, &arg);
	else
		getunbr((void *)arg.arg, i, &arg);
	return (arg);
}
