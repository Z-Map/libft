/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_preform_count.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 11:38:40 by qloubier          #+#    #+#             */
/*   Updated: 2016/10/06 23:59:30 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_format.h"

static t_list	*parse_arg(const char **fstr, va_list ap, int blen)
{
	t_pfc		arg;

	arg = (t_pfc){ 0, 6, 0, blen, 0, 0};
	*fstr += 1;
	while (**fstr)
	{
		while ((blen = ft_stridx(PF_FLAG_STR, (int)(*((*fstr)++)))) >= 0)
			arg.flag |= 1 << blen;
		arg.arg = (uintmax_t)ap;
		*fstr += 1;
	}
	return (ft_lstnew(&arg, sizeof(t_pfc)));
}

int				ft_preform_count(const char *fstr, va_list ap, t_list **args)
{
	t_list		*elem;
	int			len;
	int			blen;

	elem = NULL;
	len = 0;
	blen = 0;
	while (fstr)
	{
		if (*fstr == '%')
		{
			if ((elem = parse_arg(&fstr, ap, blen)) == NULL)
				return (-1);
			ft_lstpushback(args, elem);
			len += ((t_pfc *)(elem->content))->minwidth;
			blen = 0;
		}
		else
		{
			++fstr;
			++len;
			++blen;
		}
	}
	return (len);
}
