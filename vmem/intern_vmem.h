/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intern_vmem.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 16:14:51 by qloubier          #+#    #+#             */
/*   Updated: 2017/04/21 20:38:32 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_VMEM
# define INTERN_VMEM

# include "libft_memory.h"

# define VMI_INIT(vmem) (t_vmi){.mem=vmem,.cursor=NULL}

typedef struct	s_vmem_iterator
{
	t_vmem		*mem;
	t_vmps		*cursor;
}				t_vmi;

t_vmem			**ft_ivmem(void );
void			ft_ivmempush(t_vmem *vm);
t_vmps			*ft_ivm_iter(t_vmi *it);
void			*ft_ivm_mptr(t_vmps *vptr);
t_vmem			*ft_ivm_getvmem(t_vmps *vptr);
t_vmps			*ft_ivm_nextptr(t_vmps *vptr, t_vmem **vm);
t_vmps			*ft_ivm_next_emptyptr(t_vmps *vptr, t_vmem **vm);
t_vmps			*ft_ivm_emptyptr(t_vmem *vm, t_vmps *vptr);
t_vmps			*ft_ivm_prevptr(t_vmps *vptr, t_vmem **vm);
t_vmps			*ft_ivm_splitptr(t_vmps *vptr, size_t size, t_vmem *vm);
t_vmps			*ft_ivm_mergenextptr(t_vmps *vptr, t_vmem *vm);
t_vmps			*ft_ivm_mergeprevptr(t_vmps *vptr, t_vmem *vm);
t_vmps			*ft_ivm_allocptr(size_t size, t_vmem *vm);
t_vmps			*ft_ivm_cleanptr(t_vmps *vptr, t_vmem *vm);

#endif
