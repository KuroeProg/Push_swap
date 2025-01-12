/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <cfiachet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 15:07:01 by cfiachet          #+#    #+#             */
/*   Updated: 2025/01/12 13:35:15 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stact_sorted(t_stack *a)
{
	while (a && a->next)
	{
		if (a->nbr > a->next->nbr)
			return (0);
		a = a->next;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2 || !argv[1])
		return (0);
	else if (argc == 2)
		ft_split2(argv[1], ' ');
	init_stack_a(&a, argv + 1);
	if (!stack_sorted(a))
	{
		if (stacklen(a) == 2)
			sa(&a);
		else if (stacklen(a) == 3)
			sort_three(&a);
		else
			sort_stacks(&a, &b);
	}
	free_stack(&a);
	return (0);
	
}