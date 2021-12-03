/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiaz-fl <cdiaz-fl@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 15:41:42 by cdiaz-fl          #+#    #+#             */
/*   Updated: 2021/06/13 18:31:41 by cdiaz-fl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	dl;
	size_t	sl;

	j = 0;
	dl = ft_strlen(dst);
	sl = ft_strlen(src);
	i = dl;
	if (dstsize == 0)
		return (sl);
	if (dstsize < dl)
		return (dstsize + sl);
	else
	{
		while (src[j] != '\0' && (dl + j) < dstsize)
			dst[i++] = src[j++];
		if ((dl + j) == dstsize && dl < dstsize)
			dst [i - 1] = '\0';
		else
			dst[i] = '\0';
		return (dl + sl);
	}
}
