/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <cfiachet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 12:31:02 by cfiachet          #+#    #+#             */
/*   Updated: 2025/01/24 12:43:31 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack)
{
	t_node	*first;
	t_node	*second;
	int		temp;

	if (stack->size < 2)
		return ;
	first = stack->top;
	second = first->next;
	temp = second->data;
	second->data = first->data;
	first->data = temp;
}

void	rotate(t_stack *stack)
{
	t_node	*start;
	t_node	*second;

	if (stack->size < 2)
		return ;
	start = stack->top;
	second = start->next;
	stack->top = second;
}

void	rreverse(t_stack *stack)
{
	t_node	*start;
	t_node	*end;

	if (stack->size < 2)
		return ;
	start = stack->top;
	end = start->prev;
	stack->top = end;
}
