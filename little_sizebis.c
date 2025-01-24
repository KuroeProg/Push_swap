/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_sizebis.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <cfiachet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 20:03:53 by cfiachet          #+#    #+#             */
/*   Updated: 2025/01/24 02:02:19 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_small(t_stack *stack_a, t_stack *stack_b)
{
	int		moves;
	t_node	*min;

	moves = stack_a->size / 2;
	while (moves > 0)
	{
		min = get_min_node(stack_a);
		while (stack_a->top->data != min->data)
			ra(stack_a);
		pb(stack_a, stack_b);
		moves--;
	}
	sort_three(stack_a);
	while (stack_b->size > 0)
		pa(stack_a, stack_b);
}

int	get_node_position(t_stack *stack, t_node *node)
{
	t_node	*current;
	int		position;

	if (!stack || !node)
		return (-1);
	current = stack->top;
	position = 0;
	while (current != node)
	{
		current = current->next;
		position++;
	}
	return (position);
}

int	check_tab_size(int *tab, int len, t_stack *stack_a, t_stack *stack_b)
{
	if (len < 22)
	{
		if (len == 0 || len == 1)
		{
			free_all(stack_a, stack_b);
			free(tab);
			exit(0);
		}
		if (len == 2)
		{
			if (tab[0] > tab[1])
				sa(stack_a);
		}
		if (len == 3)
			sort_three(stack_a);
		if (len == 4)
			sort_four(stack_a, stack_b);
		if (len == 5)
			sort_five(stack_a, stack_b);
		else
			sort_small_stack(stack_a, stack_b, len);
		free_func(tab, stack_a, stack_b);
	}
	return (0);
}

void	free_func(int *tab, t_stack *stack_a, t_stack *stack_b)
{
	free_all(stack_a, stack_b);
	free(tab);
	exit(0);
}
