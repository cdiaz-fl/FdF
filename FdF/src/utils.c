/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiaz-fl <cdiaz-fl@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 16:47:50 by cdiaz-fl          #+#    #+#             */
/*   Updated: 2021/12/08 19:56:38 by cdiaz-fl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../libft/libft.h"
#include	"../fdf.h"

int	ft_is_nbr(char *str)
{
	int	i;

	if (str[0] == ' ' || str[0] == '\n')
		return (0);
	i = 0;
	while (str[i])
	{
		if (!ft_strchr("+-0123456789\n,", str[i]))
			return (0);
		if (i > 0 && (str[i] == '+' || str[i] == '-'))
			return (0);
		i++;
	}
	if (i > 11)
		return (0);
	if ((str[0] != '-' && str[0] != '+') && i > 10)
		return (0);
	if (ft_real_atoi(str) > 2147483647)
		return (0);
	if (ft_real_atoi(str) < -2147483648)
		return (0);
	return (1);
}



long	ft_real_atoi(const char *nptr)
{
	long	i;
	long	multi;

	multi = 1;
	while (*nptr == ' ' || *nptr == '\t' || *nptr == '\n' || *nptr == '\r'
		|| *nptr == '\v' || *nptr == '\f')
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			multi = -1;
		nptr++;
	}
	i = 0;
	while (*nptr >= 48 && *nptr <= 57)
	{
		i *= 10;
		i += (*nptr - '0');
		nptr++;
	}
	return (i * multi);
}
