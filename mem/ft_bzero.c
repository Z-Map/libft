/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 01:22:08 by qloubier          #+#    #+#             */
/*   Updated: 2016/10/09 21:19:04 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_memory.h"

void	ft_bzero(void *s, size_t n)
{
	register size_t		aln;

	if (!n)
		return ;
	aln = n - (n % sizeof(long));
	while ((aln--) > n)
		((char *)s)[aln] = 0;
	aln = n / sizeof(long);
	while (aln--)
		((unsigned long *)s)[aln] = 0;
}
