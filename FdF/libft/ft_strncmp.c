/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiaz-fl <cdiaz-fl@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 16:16:27 by cdiaz-fl          #+#    #+#             */
/*   Updated: 2021/05/31 18:07:23 by cdiaz-fl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*pt1;
	unsigned char	*pt2;
	size_t			i;

	i = 0;
	pt1 = (unsigned char *) s1;
	pt2 = (unsigned char *) s2;
	if (n == 0)
		return (0);
	while ((pt1[i] != '\0' || pt2[i] != '\0') && i < n)
	{
		if (pt1[i] != pt2[i])
			return (pt1[i] - pt2[i]);
		i++;
	}
	return (0);
}
