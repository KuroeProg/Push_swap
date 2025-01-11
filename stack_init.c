/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <cfiachet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 13:55:31 by cfiachet          #+#    #+#             */
/*   Updated: 2025/01/11 21:51:05 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	ft_atol(const char *str)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		*str++;
	}
	while (ft_isdigit(*str))
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sign);
}

static void	append_node(t_stack **stack, int n)
{
	//ajouter des noeuds
}


void	init_stack_a(t_stack **a, char **argv)
{
	long	value;
	int		i;

	i = 0;
	while(argv[i])
	{
		if (is_conform(argv[i]))
			free_errors(a);
		value = ft_atol(argv[i]);
		if (value < -2147483648 || value > 2147483647)
			free_errors(a);
		if (is_present(*a, (int)value))
			free_errors(a);
		append_node(a, (int)value);
		i++;
	}
}