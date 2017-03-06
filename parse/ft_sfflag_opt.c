/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sfflag_opt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: map <map@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 15:25:44 by map               #+#    #+#             */
/*   Updated: 2017/03/06 17:52:37 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_parse.h"

const char		*ft_sfflag_opt(const char *c, t_sfb *b)
{
	if (!(b->arg.flag & SFF_IGNORE))
		b->arg.flag |= SFF_OPTIONAL;
	return (c + 1);
}
