/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enext.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 18:33:28 by qloubier          #+#    #+#             */
/*   Updated: 2017/05/12 04:33:49 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_parse.h"

static int		key_loop(t_gparse *parser, const char *c, size_t len)
{
	size_t		seplen;
	int			i;

	seplen = parser->seplen;
	i = 0;
	while (seplen-- && ((size_t)parser->seplst[i].slen > len
		|| ft_strconcur(c, parser->seplst[i].separator)))
		i++;
	return ((i < parser->seplen) ? i : -1);
}

static int		get_key(t_gparse *parser)
{
	const char	*c;
	size_t		len;
	int			i;

	c = parser->cursor;
	len = parser->c_len;
	while (*c)
	{
		if (((i = ft_stridx(parser->stopset, *c)) >= 0)
			&& (!(parser->seplst[i].separator)
			|| ()))
			break;
		i = -1;
		len--;
		c++;
	}
	if (i > 0)
	{
		parser->k_len = parser->c_len - len;
		parser->key = (parser->k_len) ? parser->cursor : NULL;
		len = parser->c_len;
		c += (!parser->seplst[i].separator) ? 1 :
			FT_SLEN(parser->seplst[i].separator);
	}
	return (i);
}

static int		get_value(t_gparse *parser)
{
	const char	*c;

	c = ft_strnpbrk(parser->cursor, parser->end, parser->c_len);
	parser->v_len = (size_t)(c - parser->cursor);
	parser->value = (parser->v_len) ? parser->cursor : NULL;
	parser->c_len -= parser->v_len;
	c = ft_strnpskp(c, parser->end, parser->c_len);
	parser->c_len -= (size_t)(c - parser->cursor);
	parser->cursor = c;
	return (1);
}

static int		get_group(t_gparse *parser, int i)
{
	const char	*c;

	c = ft_strnpbrk(parser->cursor, parser->seplst[i].end, parser->c_len);
	parser->v_len = (size_t)(c - parser->cursor);
	parser->value = (parser->v_len) ? parser->cursor : NULL;
	parser->c_len -= parser->v_len;
	c = ft_strnpskp(c, parser->end, parser->c_len);
	parser->c_len -= (size_t)(c - parser->cursor);
	parser->cursor = c;
	return (1);
}

int				ft_enext(t_gparse *parser)
{
	const char	*c;
	size_t		len;
	int			i;

	c = parser->cursor;
	len = parser->c_len;
	if (!len)
		return (0);
	while (*c && ((i = key_loop(parser, c, len)) < 0) && len--)
		c++;
	parser->k_len = (i < 0) ? 0 : c - parser->cursor;
	parser->key = (parser->k_len) ? parser->cursor : NULL;
	len = parser->k_len + ((i < 0) ? (size_t)parser->seplst[i].slen : 0);
	parser->cursor += len;
	parser->c_len -= len;
	if ((i >= 0) && (parser->seplst[i].end))
		return (get_group(parser, i));
	return (get_value(parser));
}
