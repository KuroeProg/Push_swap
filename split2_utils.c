/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split2_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <cfiachet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 21:32:15 by cfiachet          #+#    #+#             */
/*   Updated: 2025/01/11 21:32:30 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check(char c, char sep)
{
	return (c == sep);
}

char	*ft_mallocworld(const char *str, char c)
{
	size_t	i;
	char	*strf;

	i = 0;
	while (str[i] && !ft_check(str[i], c))
		i++;
	strf = (char *)malloc(sizeof(char) * (i + 1));
	if (!strf)
		return (NULL);
	i = 0;
	while (str[i] && !ft_check(str[i], c))
	{
		strf[i] = str[i];
		i++;
	}
	strf[i] = '\0';
	return (strf);
}

void	free_tab(char **tab, size_t i)
{
	while (i > 0)
	{
		free(tab[i - 1]);
		i--;
	}
	free(tab);
}