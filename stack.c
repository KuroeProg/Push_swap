/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <cfiachet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 19:30:23 by cfiachet          #+#    #+#             */
/*   Updated: 2025/01/24 13:02:29 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	create_stack(void)
{
	t_stack	stack;

	stack.top = NULL;
	stack.size = 0;
	return (stack);
}

void	fill_stack(t_stack *stack, int *tab, int size)
{
	int		i;
	t_node	*prev;
	t_node	*next;

	if (size == 0)
		return ;
	prev = create_node(tab[0]);
	stack->top = prev;
	i = 1;
	while (i < size)
	{
		next = create_node(tab[i]);
		link_nodes(prev, next);
		prev = next;
		i++;
	}
	if (size > 1)
		link_nodes(next, stack->top);
	stack->size = size;
}

t_node	*get_min_node(t_stack *stack)
{
	t_node	*temp;
	t_node	*min;

	temp = stack->top;
	min = NULL;
	while (temp != min)
	{
		if (!min || temp->data < min->data)
			min = temp;
		temp = temp->next;
	}
	return (min);
}

t_node	*get_max_node(t_stack *stack)
{
	t_node	*temp;
	t_node	*max;

	temp = stack->top;
	max = NULL;
	while (temp != max)
	{
		if (!max || temp->data > max->data)
			max = temp;
		temp = temp->next;
	}
	return (max);
}

t_node	*get_nearest_min_node(t_stack *stack, int data)
{
	t_node	*temp;
	t_node	*nearest;

	temp = stack->top;
	nearest = NULL;
	while (temp != nearest)
	{
		if (temp->data > data && (!nearest || temp->data < nearest->data))
			nearest = temp;
		temp = temp->next;
	}
	return (nearest);
}
