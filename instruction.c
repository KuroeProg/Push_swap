/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <cfiachet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 19:30:14 by cfiachet          #+#    #+#             */
/*   Updated: 2025/01/19 11:47:58 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	sa(t_stack *stack_a)
{
	swap(stack_a);
}

void	sb(t_stack *stack_b)
{
	swap(stack_b);
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	swap(stack_a);
	swap(stack_b);
}

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	push(stack_a, pop(stack_b));
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	push(stack_b, pop(stack_a));
}

void	ra(t_stack *stack_a)
{
	rotate(stack_a);
}
void	rb(t_stack *stack_b)
{
	rotate(stack_b);
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
}
void	rra(t_stack *stack_a)
{
	rreverse(stack_a);
}

void	rrb(t_stack *stack_b)
{
	rreverse(stack_b);
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	rreverse(stack_a);
	rreverse(stack_b);
}