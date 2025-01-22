/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <cfiachet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 19:53:12 by cfiachet          #+#    #+#             */
/*   Updated: 2025/01/23 00:18:47 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

long	ft_atol(char *str)
{
	int	i;
	int sign;
	long result;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
		result = result * 10 + (str[i++] - '0');
	return (result * sign);
}


int	is_indouble(int *tab, int n)
{
    int i;
    int j;

    i = 0;
    while (i < n - 1)
    {
        j = i + 1;
        while (j < n)
        {
            if (tab[i] == tab[j])
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}

int	check_size(int *tab)
{
	int i;

	i = 0;

	while (tab[i])
		i++;
	return (i);
}
