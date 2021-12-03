/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiaz-fl <cdiaz-fl@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 12:53:45 by cdiaz-fl          #+#    #+#             */
/*   Updated: 2021/06/13 18:30:30 by cdiaz-fl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*ptr;
	unsigned int	i;
	unsigned int	j;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	ptr = (char *)malloc((ft_strlen(s1) + ft_strlen(s2)) * sizeof(char) + 1);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (i < ft_strlen(s1) + ft_strlen(s2))
	{
		j = 0;
		while (((char *)s1)[j] != '\0')
			ptr[i++] = ((char *)s1)[j++];
		j = 0;
		while (((char *)s2)[j] != '\0')
			ptr[i++] = ((char *)s2)[j++];
		ptr[i] = '\0';
	}
	return (ptr);
}
