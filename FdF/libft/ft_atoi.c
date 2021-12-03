/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiaz-fl <cdiaz-fl@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 17:07:56 by cdiaz-fl          #+#    #+#             */
/*   Updated: 2021/06/13 18:18:56 by cdiaz-fl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_finalnegative(const char *str, int i, int a);
static int	ft_countnegative(const char *str, int i);

int	ft_atoi(const char *str)
{
	int	a;
	int	i;

	i = 0;
	a = 0;
	while (str[i] != '\0')
	{
		if ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
			i++;
		else if (((str[i] < 48 || str[i] > 57) && str[i] != 45
				&& str[i] != 43) || (ft_countnegative(str, i) != -1))
			break ;
		else
		{
			if (str[i] == '-' || str[i] == '+')
				i++;
			while (str[i] > 47 && str[i] < 58)
			{
				a = (a * 10) + (str[i] - '0');
				i++;
			}
			break ;
		}
	}
	return (ft_finalnegative (str, i, a));
}

static int	ft_countnegative(const char *str, int i)
{
	long	x;

	x = 0;
	while ((str[i] < '0' || str[i] > '9') && str[i] != '\0')
	{
		if (str[i] == '-' || str[i] == '+')
			x++;
		i++;
	}
	if (x == 1 || x == 0)
		return (-1);
	else
		return (0);
}

static int	ft_finalnegative(const char *str, int i, int a)
{
	long	x;

	x = 0;
	i = i - 1;
	while (i >= 0)
	{
		if (str[i] == '-')
			x++;
		i--;
	}
	if (x == 1)
		return (a * -1);
	else
		return (a);
}
