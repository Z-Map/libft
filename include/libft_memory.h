/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_memory.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 10:24:59 by qloubier          #+#    #+#             */
/*   Updated: 2017/04/16 15:00:58 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_MEMORY_H
# define LIBFT_MEMORY_H
# include <string.h>
# include <stdarg.h>
# include "ft.h"

# define FT_VMEM_DEFAULT	0xFFFF
# define FT_VMF_EMPTY		0x01
# define FT_VMF_VALID		0x5<<28
# define FT_VMF_VALIDAREA	0xF<<28

typedef struct	s_vpointer_stat
{
	t_ui		flag;
	short		prev_len;
	short		len;
}				t_vmps;

typedef struct	s_virtual_memory
{
	t_vmem		*next;
	void		*mem;
	t_vmps		*cursor;
	size_t		size;
	size_t		len;
	t_vmem		*_gnext;
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

/*
** TO-DO : Buffer tools
*/

#endif
