/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiaz-fl <cdiaz-fl@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 11:24:44 by cdiaz-fl          #+#    #+#             */
/*   Updated: 2021/06/08 16:28:55 by cdiaz-fl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_change(long l, char *ptr, long i)
{
	if (l < 0)
	{
		ptr[0] = '-';
		l *= -1;
	}
	while (l > 0)
	{
		ptr[i - 1] = ((l % 10) + '0');
		l /= 10;
		i--;
	}
	return (ptr);
}

static long	ft_count(long n)
{
	long	i;

	i = 0;
	if (n == 0)
		i++;
	if (n < 0)
	{
		i++;
		n *= -1;
	}
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	long		i;
	char		*ptr;
	long		l;

	l = (long)n;
	i = ft_count(l);
	ptr = (char *)malloc(i * sizeof(char) + 1);
	if (!ptr)
		return (NULL);
	ptr[i] = '\0';
	if (!n)
	{
		ptr[i - 1] = n + '0';
		return (ptr);
	}
	return (ft_change(l, ptr, i));
}
