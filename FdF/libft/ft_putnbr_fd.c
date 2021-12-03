/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiaz-fl <cdiaz-fl@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 11:27:38 by cdiaz-fl          #+#    #+#             */
/*   Updated: 2021/06/13 18:27:59 by cdiaz-fl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

static void	negative(int fd);

void	ft_putnbr_fd(int n, int fd)
{
	int	aux;

	if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	else if (n == -2147483648)
		negative(fd);
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		aux = n * -1;
		ft_putnbr_fd(aux, fd);
	}
	else
		ft_putchar_fd(n + '0', fd);
}

static void	negative(int fd)
{
	ft_putchar_fd('-', fd);
	ft_putchar_fd('2', fd);
	ft_putnbr_fd(147483648, fd);
}
