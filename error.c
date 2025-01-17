/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <cfiachet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 21:39:41 by cfiachet          #+#    #+#             */
/*   Updated: 2025/01/11 21:44:42 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_conform(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != ' ' && str[i] != '-')
			return (1);
		i++;
	}
	return (0);
}

int	is_present(t_stack *a, int n)
{
	t_stack *tmp;

	tmp = a;
	while (tmp)
	{
		if (tmp->nbr == n)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}