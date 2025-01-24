/* ************************************************************************** */
/*	                                                                      */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <cfiachet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 22:30:59 by cfiachet          #+#    #+#             */
/*   Updated: 2025/01/23 00:17:50 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_min_to_b(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*min_node;
	int		min_pos;

	min_node = get_min_node(stack_a);
	min_pos = get_node_position(stack_a, min_node);
	if (min_pos <= stack_a->size / 2)
	{
		while (stack_a->top != min_node)
			ra(stack_a);
	}
	else
	{
		while (stack_a->top != min_node)
			rra(stack_a);
	}
	pb(stack_a, stack_b);
}

void	sort_five(t_stack *stack_a, t_stack *stack_b)
{
	push_min_to_b(stack_a, stack_b);
	push_min_to_b(stack_a, stack_b);
	sort_three(stack_a);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
	exit(0);
}
