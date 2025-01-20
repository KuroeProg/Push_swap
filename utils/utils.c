/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <cfiachet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 19:53:12 by cfiachet          #+#    #+#             */
/*   Updated: 2025/01/21 00:51:40 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(char *str)
{
	int	i;
	int sign;
	long result;

	i = 0;
	sign = 1;
	while (str[i] >= 9 && str[i] <= 13 || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(str[i++]))
		result = result * 10 + (str[i] - '0');
	return (result * sign);
}

int		*sorter(char **str, t_stack *stack)
{
	int 	i;
	char	**split;
	int		n;
	int		*tab;

	i = 0;
	while (str[i] && (ft_isdigit(str[i++])) || str[i] == ' ')
	{
		if (!ft_isdigit(str[i]) && str[i] != ' ')
			ft_error(1);
	}
	if (is_indouble(str) == 1)
		ft_error(1);
	if (str[i])
		split = ft_split(str, ' ');
	i = 0;
	n = check_size(split);
	tab = malloc(sizeof(int) * n);
	while (i <= n)
	{
		tab[i++] = ft_atol(split[i]);
		if (tab[i] >= 2147483647 || tab[i] <= -2147483648)
		{
			ft_error(1);
			free_tab(tab);
		}
	}
	is_indouble(tab);
	fill_stack(stack, tab, i);

	return (tab);
}

int		is_indouble(int *tab)
{
	int	i;
	int temp;

	temp = tab[i];
	i = 1;
	while (tab[i])
	{
		if (temp == tab[i])
			return (1);
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
