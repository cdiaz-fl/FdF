/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiaz-fl <cdiaz-fl@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 18:42:21 by cdiaz-fl          #+#    #+#             */
/*   Updated: 2021/11/20 08:17:54 by cdiaz-fl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;

	if (dst != (void *)0 || src != (void *)0)
	{
		if (dst > src)
		{
			while (len-- > 0)
				((unsigned char *)dst)[len] = ((unsigned char *)src)[len];
		}
		else
		{
			i = 0;
			while (i < len)
			{
				((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
				i++;
			}
		}
		return (dst);
	}
	return (NULL);
}
