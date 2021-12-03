/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiaz-fl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 08:54:16 by cdiaz-fl          #+#    #+#             */
/*   Updated: 2021/11/30 12:42:28 by cdiaz-fl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include	"libft.h"
#include	<stdlib.h>
#include	<unistd.h>

char	*ft_error_check(int bytes, char *line)
{
	if (!bytes && !ft_l(line, 0))
	{
		free(line);
		return (NULL);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*s[4096];
	char		*buffer;
	char		*line;
	int			bytes;

	if (fd == 2 || fd < 0)
		return (NULL);
	buffer = malloc(64 + 1);
	bytes = 1;
	while (bytes > 0 && !ft_findchr(s[fd], '\n'))
	{
		bytes = read(fd, buffer, 64);
		if (bytes < 0)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes] = '\0';
		s[fd] = ft_join(s[fd], buffer);
	}
	free(buffer);
	line = ft_c(s[fd], 0, ft_l(s[fd], 10) + 1, 0);
	s[fd] = ft_c(s[fd], ft_l(s[fd], 10) + 1, ft_l(s[fd], 0) - ft_l(line, 0), 1);
	return (ft_error_check(bytes, line));
}
