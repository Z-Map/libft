/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sfflag_nc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: map <map@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 15:25:44 by map               #+#    #+#             */
/*   Updated: 2017/03/06 19:15:54 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_parse.h"

const char		*ft_sfflag_nc(const char *c, t_sfb *b)
{
	b->arg.flag |= SFF_IGNORE;
	if (b->arg.flag & SFF_OPTIONAL)
		b->arg.flag ^= SFF_OPTIONAL;
	return (c + 1);
}
