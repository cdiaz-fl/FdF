/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiaz-fl <cdiaz-fl@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 11:25:52 by cdiaz-fl          #+#    #+#             */
/*   Updated: 2021/06/13 18:27:39 by cdiaz-fl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	size_t	i;
	char	c;

	if (s != NULL)
	{
		i = ft_strlen(s);
		write(fd, s, i);
		c = '\n';
		ft_putchar_fd(c, fd);
	}
}
