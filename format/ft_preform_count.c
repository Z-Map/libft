/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_preform_count.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 11:38:40 by qloubier          #+#    #+#             */
/*   Updated: 2016/05/22 07:50:11 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_format.h"

// static void		process_arg(const char **fstr, va_list ap, t_ptfc *arg)
// {
//
// }

static t_list	*parse_arg(const char **fstr, va_list ap, int blen)
{
	// t_list		*ret;
	t_ptfc		arg;

	arg = (t_ptfc){ 0, 6, 0, blen, 0, 0};
	*fstr += 1;
	while (**fstr)
	{
		while ((blen = ft_stridx(PF_FLAG_STR, (int)(*((*fstr)++)))) >= 0)
			arg.flag |= 1 << blen;
		arg.arg = (uintmax_t)ap;
		// if (ft_isdigit((int)(**fstr)))
		// 	;
		*fstr += 1;
	}
	return (ft_lstnew(&arg, sizeof(t_ptfc)));
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
			len += ((t_ptfc *)(elem->content))->minwidth;
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
