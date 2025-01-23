/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <cfiachet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 19:30:14 by cfiachet          #+#    #+#             */
/*   Updated: 2025/01/21 19:16:24 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	sa(t_stack *stack_a)
{
	swap(stack_a);
	printf("sa\n");
}

void	sb(t_stack *stack_b)
{
	swap(stack_b);
	printf("sb\n");
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	swap(stack_a);
	swap(stack_b);
	printf("ss\n");
}

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	push(stack_a, pop(stack_b));
	printf("pa\n");
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	push(stack_b, pop(stack_a));
	printf("pb\n");
}

void	ra(t_stack *stack_a)
{
	rotate(stack_a);
	printf("ra\n");
}
void	rb(t_stack *stack_b)
{
	rotate(stack_b);
	printf("rb\n");
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	printf("rr\n");
}
void	rra(t_stack *stack_a)
{
	rreverse(stack_a);
	printf("rra\n");
}

void	rrb(t_stack *stack_b)
{
	rreverse(stack_b);
	printf("rrb\n");
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	rreverse(stack_a);
	rreverse(stack_b);
	printf("rrr\n");
}