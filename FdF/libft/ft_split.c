/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiaz-fl <cdiaz-fl@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 10:43:35 by cdiaz-fl          #+#    #+#             */
/*   Updated: 2021/12/11 15:11:17 by cdiaz-fl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

static char	**ft_freemem(char **ptr, unsigned int j)
{
	unsigned int	i;

	if (ptr)
	{
		i = 0;
		while (i < j)
		{
			if (ptr[i] != NULL)
				free(ptr[i]);
			i++;
		}
		free (ptr);
	}
	return (NULL);
}

static char	*ft_fill(char const *s, char c)
{
	char			*ptr;
	unsigned int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	ptr = (char *)malloc((i + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != c)
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

static char	**ft_len(char const *s, char c, char **ptr)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			ptr [j] = ft_fill(&s[i], c);
			if (!ptr[j])
				return (ft_freemem(ptr, j));
			j++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	ptr[j] = NULL;
	return (ptr);
}

static unsigned int	ft_numb(char const *s, char c)
{
	unsigned int	i;
	unsigned int	numb;

	i = 0;
	numb = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			numb++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (numb);
}

char	**ft_split(char *s, char c)
{
	char			**ptr;
	unsigned int	numb;

	if (!s)
		return (NULL);
	numb = ft_numb(s, c);
	ptr = (char **)malloc((numb + 1) * sizeof(char *));
	if (!ptr)
		return (NULL);
	ptr = ft_len(s, c, ptr);
	if (s != NULL)
		free(s);
	return (ptr);
}
