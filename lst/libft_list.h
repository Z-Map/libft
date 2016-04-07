/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_list.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 10:28:45 by qloubier          #+#    #+#             */
/*   Updated: 2016/04/07 19:16:50 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <string.h>
#include "../mem/libft_memory.h"

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_static_list
{
	size_t			len;
	void 			*data;
}					t_slst;

t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*ft_lstlast(t_list *lst);
void				ft_lstpush(t_list **alst, t_list *new);
void				ft_lstpushback(t_list **alst, t_list *new);
size_t				ft_lstlen(t_list *lst);
void				*ft_lsttotab(t_list *node, size_t ts, size_t *len);
void				ft_lstcfree(void *vec, size_t s);
