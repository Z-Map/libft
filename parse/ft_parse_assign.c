/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_assign.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 20:41:25 by qloubier          #+#    #+#             */
/*   Updated: 2017/02/15 00:04:56 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_parse.h"

int			ft_parse_assign(const t_kf *a_table, const char *str, void *arg)
{
	int		len;
	char	sym_name[256];

	if (ft_sscanf(str, "%255s = %n", sym_name, &len) < 1)
		return (0);
	while (a_table->key)
	{
		if (!ft_strcmp(a_table->key, sym_name) &&
			a_table->func(sym_name, str + len, arg))
			return (0);
		a_table++;
	}
	return (0);
}
