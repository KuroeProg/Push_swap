/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <cfiachet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 19:27:54 by cfiachet          #+#    #+#             */
/*   Updated: 2025/01/11 19:28:31 by cfiachet         ###   ########.fr       */
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

