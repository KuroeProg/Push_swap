/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <cfiachet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 19:53:12 by cfiachet          #+#    #+#             */
/*   Updated: 2025/01/21 15:20:15 by cfiachet         ###   ########.fr       */
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


/* NEED TO TREAT THE CASE OF STRING OR ARRAY OF ARRAY.
long		*sorter(char **str, t_stack *stack)
{
	t_point	p;
	char	**split;
	int		*tab;
	long 	value;

	p.i = 0;
	p.y = 0;
	while (str[p.i])
	{
		while (str[p.i][p.y])
		{
			if ((!ft_isdigit(str[p.i][p.y]) || str[p.i][p.y] != ' '))
				ft_error(1);
			p.y++;
		}
		p.i++;
		p.y = 0;
	}
	split = ft_split(str, ' ');
	p.n = check_size(split);
	tab = malloc(sizeof(int) * p.n);
	p.i = 0;
	while (split[p.i])
	{
		value = ft_atoi(split[p.i]);
		if (tab[p.i] >= 2147483647 || tab[p.i] <= -2147483648)
		{
			free_tab(split);
			ft_error(1);
		}
		tab[p.i++] = (int)value;
	}
	if (!is_indouble(tab, p.n) == 1)
	{
		free_tab(split);
		free(tab);
		ft_error(1);
	}
	fill_stack(stack, tab, p.i);
	free_tab(split);

	return (tab);
} */

int		is_indouble(int *tab, int n)
{
	int	i;
	int temp;

	temp = tab[i];
	i = 1;
	while (i < n)
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
