/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_parse.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/09 19:48:04 by qloubier          #+#    #+#             */
/*   Updated: 2016/07/09 21:35:13 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_PARSE_H
#define LIBFT_PARSE_H

# include <string.h>
# include <stdarg.h>
# include "libft_string.h"
# include "libft_memory.h"
# include "libft_list.h"

int						ft_atoi(const char *str);

/*
** TO DO
*/

float					ft_atof(const char *str);
double					ft_atod(const char *str);

#endif
