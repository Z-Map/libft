/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readfile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 14:06:20 by qloubier          #+#    #+#             */
/*   Updated: 2017/03/23 14:33:07 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "libft_io.h"

int				ft_readfile(const char *filename, char **content)
{
	int			fd;
	struct stat	fst;
	char		*buf;
	ssize_t		ret;

	fst.st_size = 0;
	if (stat(filename, &fst) || !fst.st_size ||
		((fd = open(filename, O_RDONLY)) < 3))
		return (0);
	if (!(buf = malloc((t_ul)(fst.st_size) + 1)))
	{
		close(fd);
		return (0);
	}
	*content = buf;
	ret = read(fd, buf, (t_ul)fst.st_size);
	buf[ret] = '\0';
	close(fd);
	return ((int)ret);
}
