/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enext.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 18:33:28 by qloubier          #+#    #+#             */
/*   Updated: 2017/05/12 06:25:50 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_parse.h"

int				ft_enext(t_gparse *parser)
{
	const char	*c;
	size_t		len;
	int			i;

	c = parser->cursor;
	len = parser->c_len;
	if (!len || !*c)
		return (0);
	while (*c && ((i = ft_prsgetsep(parser, c, len)) < 0) && len--)
		c++;
	parser->k_len = (i < 0) ? 0 : c - parser->cursor;
	parser->key = (parser->k_len) ? parser->cursor : NULL;
	len = parser->k_len + ((i < 0) ? (size_t)parser->seplst[i].slen : 0);
	parser->cursor += len;
	parser->c_len -= len;
	parser->value = parser->cursor;
	if ((i >= 0) && (parser->seplst[i].end))
		parser->v_len = ft_prsgskp(parser, parser->seplst + i, NULL);
	else
	{
		parser->v_len = ft_prsgskp(parser, NULL, parser->end);
		ft_prsskp(&(parser->cursor), &(parser->c_len), parser->end, NULL);
	}
	parser->value = (!parser->v_len) ? NULL : parser->value;
	return (1);
}
