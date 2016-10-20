/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_math.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 02:13:18 by qloubier          #+#    #+#             */
/*   Updated: 2016/10/20 17:58:50 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_MATH_H
# define LIBFT_MATH_H

# include "ft.h"

# define FT_SM_C	0x80u
# define FT_SM_S	0x8000u
# define FT_SM_I	0x80000000u
# define FT_SM_L	0x8000000000000000ul

# define FT_D_EXP	0x7ff0000000000000ul
# define FT_D_MAN	0x000ffffffffffffful

int					ft_first_pow2_digit(unsigned long num);
int					ft_firstfloatdigit(double d);
double				ft_fround(const double *d);

#endif
