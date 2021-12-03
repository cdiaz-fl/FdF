/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiaz-fl <cdiaz-fl@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 13:18:54 by cdiaz-fl          #+#    #+#             */
/*   Updated: 2021/06/13 18:32:24 by cdiaz-fl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	aux;

	i = 0;
	j = 0;
	aux = 0;
	if (dst == NULL || src == NULL)
		return (0);
	while (src[aux] != '\0')
		aux++;
	if (dstsize > 0)
	{
		while (src[j] != '\0' && i < (dstsize - 1))
		{
			dst[i] = src[j];
			i++;
			j++;
		}
		dst[i] = '\0';
	}
	return (aux);
}
