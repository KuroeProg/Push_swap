/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <cfiachet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 12:25:55 by cfiachet          #+#    #+#             */
/*   Updated: 2025/01/24 12:49:41 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_empty_stack(t_stack *stack, t_node *a)
{
	stack->min = a->data;
	stack->max = a->data;
	stack->top = a;
	stack->size++;
}

void	push_single_element_stack(t_stack *stack, t_node *a)
{
	t_node	*start;

	if (a->data < stack->min)
		stack->min = a->data;
	if (a->data > stack->max)
		stack->max = a->data;
	start = stack->top;
	stack->top = a;
	link_nodes(a, start);
	link_nodes(start, a);
	stack->size++;
}

void	push_general_case(t_stack *stack, t_node *a)
{
	t_node	*start;
	t_node	*end;

	start = stack->top;
	end = start->prev;
	link_nodes(end, a);
	link_nodes(a, start);
	stack->top = a;
	stack->size++;
	if (a->data < stack->min)
		stack->min = a->data;
	if (a->data > stack->max)
		stack->max = a->data;
}

void	push(t_stack *stack, t_node *a)
{
	if (!a)
		return ;
	if (stack->size == 0)
		(push_empty_stack(stack, a));
	else if (stack->size == 1)
		(push_single_element_stack(stack, a));
	else
		(push_general_case(stack, a));
}
