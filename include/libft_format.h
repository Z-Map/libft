/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_format.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 10:32:33 by qloubier          #+#    #+#             */
/*   Updated: 2016/10/10 06:02:05 by map              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_FORMAT_H
# define LIBFT_FORMAT_H
# include <string.h>
# include <stdarg.h>
# include <inttypes.h>
# include <wchar.h>
# include <unistd.h>
# include "ft.h"
# include "libft_list.h"
# include "libft_string.h"
# include "libft_wstring.h"
# include "libft_unicode.h"
# include "libft_parse.h"

/*
**	Declare public format function
*/

const char				*ft_forf(const char *c, const char *s, size_t *len);

size_t					ft_snbrlen(short nbr);
size_t					ft_nbrlen(int nbr);
size_t					ft_lnbrlen(long nbr);
size_t					ft_jnbrlen(intmax_t nbr);
size_t					ft_jdigitlen(intmax_t i);
size_t					ft_nbrlen_base(register long i, char base);
size_t					ft_ujnbrlen(uintmax_t nbr, unsigned int base);
size_t					ft_ujdigitlen(uintmax_t i, unsigned int base);
size_t					ft_floatlen(double i, t_ui pre);

char					*ft_itoa(int n);
char					*ft_ujtobuf(uintmax_t n, char *b);
char					*ft_ujfillbuf(uintmax_t n, char *b, int *len);
char					*ft_ujfillbufbase(uintmax_t n, t_cmap cm, char *b,
							int *len);

/*
**	TO DO
*/

char					*ft_dtoa(double n, t_ui prec);
char					*ft_ftoa(float n, t_ui prec);

#endif
