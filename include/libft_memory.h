/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_memory.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 10:24:59 by qloubier          #+#    #+#             */
/*   Updated: 2017/04/11 20:25:33 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_MEMORY_H
# define LIBFT_MEMORY_H
# include <string.h>
# include <stdarg.h>
# include "ft.h"

void			ft_bzero(void *s, size_t n);
void			*ft_memset(void *b, int c, size_t len);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memswp(void *ping, void *pong, size_t len);
void			ft_swpptr(void **ptra, void **ptrb);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memdup(const void *s1, size_t n);
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
void			ft_mfree(size_t num, ...);
void			*ft_mfree_ret(void *ret, size_t num, ...);
t_ui			ft_memalign(t_ui i);
void			ft_ptabdel(void ***tptr);

/*
** TO-DO : Buffer tools
*/

#endif
