/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_preform_count.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 11:38:40 by qloubier          #+#    #+#             */
/*   Updated: 2016/05/17 20:49:48 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_format.h"

static void		ft_process_arg(const char **fstr, va_list ap, t_ptfc *arg)
{
	
}

static t_list	*ft_parse_arg(const char **fstr, va_list ap, int blen)
{
	t_list		ret;
	t_ptfc		arg;

	arg = (ptfc){ 0, 6, 0, blen, 0};
	*fstr += 1;

	return (ret);
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
			if ((elem = ft_parse_arg(&fstr, ap, blen)) == NULL)
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
