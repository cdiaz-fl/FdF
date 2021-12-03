/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiaz-fl <cdiaz-fl@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 12:08:49 by cdiaz-fl          #+#    #+#             */
/*   Updated: 2021/06/04 12:52:34 by cdiaz-fl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"
#include	<stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*ptr;
	unsigned int	i;
	unsigned int	x;

	if (s == NULL)
		return (NULL);
	ptr = (char *)malloc(len * sizeof(char) + 1);
	if (ptr == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		*ptr = '\0';
		return (ptr);
	}
	i = 0;
	while (i != start)
		i++;
	x = 0;
	while (x < len)
		ptr[x++] = s[i++];
	ptr[x] = '\0';
	return (ptr);
}
