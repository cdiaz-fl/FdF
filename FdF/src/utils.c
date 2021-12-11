/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiaz-fl <cdiaz-fl@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 16:47:50 by cdiaz-fl          #+#    #+#             */
/*   Updated: 2021/12/11 09:35:37 by cdiaz-fl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../libft/libft.h"
#include	"../fdf.h"
#include <math.h>

#include <stdio.h>

int	ft_is_nbr(char *str, int k, int j, t_map *map)
{
	int	i;

	if (str[0] == ' ' || str[0] == '\n')
		return (0);
	i = 0;
	while (str[i])
	{
		if (!ft_strchr("+-0123456789\n,x ABCDEFabcdef", str[i]))
			return (0);
		if (i > 0 && (str[i] == '+' || str[i] == '-'))
			return (0);
		i++;
	}
	ft_check_hex(str, k, j, map);
	if (ft_strchr(str, 'x') && k != -1)
		ft_cut_str(str, k, j, map);
	return (1);
}


void	ft_cut_str(char *str, int k, int j, t_map *map)
{
	int	end;

	end = 0;
	while (!ft_strchr("+-0123456789", str[end]))
		end++;
	while (ft_strchr("+-0123456789", str[end]) && (size_t)end < ft_strlen(str))
		end++;
	str[end] = '\0';
	map->f_map[k][j] = ft_atoi(str);	
}


/*
int	ft_final_check(char str)
{
	int 	i;
	int 	k;

	i = 0;
	while (i < ft_strlen(str))
	{
		if (str[i] == ',')
		{
			if (str[i + 1] == ' ')
				k = i + 2;
			else
				k = i + 1;
			while (k < ft_strlen(str))
			{
				if (!ft_strchr("0123456789\n,x", str[i]))
					return (1);
				k++;
			}
		}
		i++;
	}
	return (0);
}
*/

void	ft_check_hex(char *str, int k, int j, t_map *map)
{
	int	i;

	i = 0;
	if (map != NULL)
	{
		while ((size_t)i < ft_strlen(str))
		{
			if (str[i] == '0' && str[i + 1] == 'x')
			{
				map->color_map[k][j] = ft_hex_to_int(str + i);
				return ;
			}
			i++;
		}
		map->color_map[k][j] = 0x00FFFFFF;
	}
}

int	ft_hex_to_int(char *str)
{
	int	result;
	int	i;
	int	init;
	int	count;

	i = 0;
	while (str[i] != 'x')
			i++;
	i++;
	init = i;
	count = 0;
	while ((size_t)i < ft_strlen(str) && ft_strchr("0123456789ABCDEFabcdef", str[i]))
	{
		count++;
		i++;
	}
	i = init;
	result = 0;
	count--;
	while ((size_t)i < ft_strlen(str))
	{
		if (str[i] >= 'a' && str[i] <= 'f')
			result += (str[i] - 87) * (int)powf(16.00, (float)count);

		else if(str[i] >= 'A' && str[i] <= 'F')
			result += (str[i] - 55) * (int)powf(16.00, (float)count);

		else
			result += (str[i] - '0') * (int)pow(16.00, (float)count);
		count--;
		i++;
	}



	return (result);;
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
