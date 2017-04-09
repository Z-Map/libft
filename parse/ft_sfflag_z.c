/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sfflag_z.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 02:25:00 by qloubier          #+#    #+#             */
/*   Updated: 2016/11/10 15:31:11 by map              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_parse.h"

const char			*ft_sfflag_z(const char *c, t_sfb *b)
{
	b->arg.flag |= SFF_SIZE_T;
	return (c + 1);
}