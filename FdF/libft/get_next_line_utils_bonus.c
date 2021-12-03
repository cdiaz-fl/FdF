/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiaz-fl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 09:14:44 by cdiaz-fl          #+#    #+#             */
/*   Updated: 2021/11/30 12:43:28 by cdiaz-fl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include	"libft.h"
#include	<stdlib.h>

int	ft_l(char	*s, char c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (i);
}

char	*ft_findchr(char	*s, char c)
{
	int	i;

	i = -1;
	if (!s)
		return (NULL);
	while (s[++i])
	{
		if (s[i] == c)
			return (s + i);
	}
	return (NULL);
}

char	*ft_join(char *s1, char *s2)
{
	char	*new;
	int		i;
	int		j;

	i = -1;
	j = -1;
	if (!s1)
	{
		s1 = malloc(1);
		s1[0] = '\0';
	}
	new = malloc(ft_l(s1, 0) + ft_l(s2, 0) + 1);
	if (!new)
		return (NULL);
	while (s1[++i])
		new[i] = s1[i];
	while (s2[++j])
		new[i + j] = s2[j];
	new[j + i] = '\0';
	free(s1);
	return (new);
}

char	*ft_c(char *s, int start, int l, int f)
{
	char	*new;
	int		i;

	i = 0;
	if (!ft_findchr(s, '\n') && f)
	{
		free(s);
		return (NULL);
	}
	new = malloc(l + 1);
	if (!new)
		return (NULL);
	while (i < l && s[start + i])
	{
		new[i] = s[start + i];
		i++;
	}
	new[i] = '\0';
	if (f)
		free(s);
	return (new);
}
