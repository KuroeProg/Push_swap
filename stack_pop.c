/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_pop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <cfiachet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 12:21:11 by cfiachet          #+#    #+#             */
/*   Updated: 2025/01/24 12:48:46 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*pop_single_element(t_stack *stack)
{
	t_node	*pop;

	pop = stack->top;
	stack->top = NULL;
	stack->min = INT_MAX;
	stack->max = INT_MIN;
	stack->size--;
	return (pop);
}

t_node	*pop_two_elements(t_stack *stack)
{
	t_node	*pop;
	t_node	*start;

	pop = stack->top;
	start = pop->next;
	pop->prev = NULL;
	pop->next = NULL;
	start->next = NULL;
	start->prev = NULL;
	stack->top = start;
	stack->min = start->data;
	stack->max = start->data;
	stack->size--;
	return (pop);
}

t_node	*pop_general_case(t_stack *stack)
{
	t_node	*pop;
	t_node	*start;
	t_node	*end;

	pop = stack->top;
	start = pop->next;
	end = pop->prev;
	if (end != NULL)
		end->next = start;
	if (start != NULL)
		start->prev = end;
	pop->next = NULL;
	pop->prev = NULL;
	stack->top = start;
	stack->size--;
	if (pop->data == stack->min)
		stack->min = get_min_node(stack)->data;
	if (pop->data == stack->max)
		stack->max = get_max_node(stack)->data;
	return (pop);
}

t_node	*pop(t_stack *stack)
{
	if (stack->size == 0)
		return (NULL);
	if (stack->size == 1)
		return (pop_single_element(stack));
	if (stack->size == 2)
		return (pop_two_elements(stack));
	return (pop_general_case(stack));
}
