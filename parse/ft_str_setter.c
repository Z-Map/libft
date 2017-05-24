/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_setter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 11:20:34 by qloubier          #+#    #+#             */
/*   Updated: 2017/05/18 13:03:16 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_parse.h"

void					ft_str_setter(t_val *val, void *mem, void *v)
{
	*(void **)((t_ul)mem + val->offset) = v;
}