/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 12:58:32 by hyeo              #+#    #+#             */
/*   Updated: 2022/06/20 15:06:59 by hyeo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check(char const str, char *charset)
{
	if (str == charset[0])
		return (1);
	return (0);
}

int	findsecond(char const *str, char *charset)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && !(check(str[i], charset)))
		i++;
	return (i);
}

int	findfirst(char const *str, char *charset)
{
	int	i;
	int	total;

	total = 0;
	i = 0;
	while (*str)
	{
		while (*str && check(*str, charset))
			str++;
		i = findsecond(str, charset);
		str += i;
		if (i)
			total++;
	}
	return (total);
}

char	**malloc_free(char **all)
{
	int	i;

	i = 0;
	while (all[i])
	{
		free(all[i]);
		i++;
	}
	free(all);
	return (NULL);
}

char	**ft_split(char const *s, char *c)
{
	int		i;
	int		total;
	char	**dest;

	i = 0;
	if (!s)
		return (NULL);
	total = findfirst(s, c);
	dest = (char **)malloc(sizeof(char *) * (total + 1));
	if (!dest)
		return (0);
	while (i < total)
	{
		while (check(*s, c))
			s++;
		dest[i] = malloc(sizeof(char) * (findsecond(s, c) + 1));
		if (!dest[i])
			return (malloc_free(dest));
		ft_strlcpy(dest[i], s, findsecond(s, c) + 1);
		s += findsecond(s, c);
		i++;
	}
	dest[total] = 0;
	return (dest);
}
