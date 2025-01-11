/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <cfiachet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 19:27:54 by cfiachet          #+#    #+#             */
/*   Updated: 2025/01/11 21:30:35 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_countword(char const *s, char sep)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && ft_check(s[i], sep))
			i++;
		if (s[i] && !ft_check(s[i], sep))
		{
			count++;
			while (s[i] && !ft_check(s[i], sep))
				i++;
		}
	}
	return (count);
}

static char	*get_next_word(char *str, char c)
{
	static int index = 0;
	char	*next_word;
	int		i;
	int		len;

	len = 0;
	i = 0;
	while(str[index] == c)
		index++;
	while ((str[index + len] != c) && str[index + len])
		len++;
	next_word = (char *)malloc(sizeof(char) * (len + 1));
	if (!next_word)
		return (NULL);
	while ((str[index]) != c && str[index])
	{
		next_word[i] = str[index];
		i++;
		index++;
	}
	return (next_word);
}

char	**ft_split(char const *s, char c)
{
	size_t		i;
	char		**tab;

	i = 0;
	if (!s)
		return (NULL);
	tab = (char **)malloc(sizeof(char *) * (ft_countword(s, c) + 1));
	if (!tab)
		return (NULL);
	while (*s)
	{
		while (*s && (ft_check(*s, c)))
			s++;
		if (*s && !ft_check(*s, c))
		{
			tab[i] = ft_mallocworld(s, c);
			if (!tab[i])
				return (free_tab(tab, i), NULL);
			i++;
			while (*s && !ft_check(*s, c))
				s++;
		}
	}
	tab[i] = NULL;
	return (tab);
}