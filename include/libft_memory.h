/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_memory.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 10:24:59 by qloubier          #+#    #+#             */
/*   Updated: 2017/04/22 02:55:28 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_MEMORY_H
# define LIBFT_MEMORY_H
# include <string.h>
# include <stdarg.h>
# include "ft.h"

# define FT_VMEM_DEFAULT	0xFFFF
# define FT_VMF_EMPTY		0x01u
# define FT_VMF_VALID		0x5u<<28
# define FT_VMF_VALIDAREA	0xFu<<28

typedef struct	s_vpointer_stat
{
	t_ui		flag;
	t_us		prev_len;
	t_us		len;
}				t_vmps;

struct			s_virtual_memory
{
	t_vmem		*next;
	t_vmem		*prev;
	t_vmps		*mem;
	t_vmps		*last;
	t_vmps		*cursor;
	size_t		size;
	size_t		len;
	t_vmem		*_gnext;
	t_vmem		*_gprev;
	t_vmem		*_lastactive;
};

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

// Not tested yet :


t_vmem			*ft_vmem(t_vmem *vm);
t_vmem			*ft_vmemnew(size_t size);
void			*ft_vmalloc(short size);
void			*ft_vmemalloc(t_vmem *vm, short size);
int				ft_vfree(void *vptr);


/*
** TO-DO : Buffer tools
*/

#endif
