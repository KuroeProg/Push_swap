/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <cfiachet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 14:45:07 by cfiachet          #+#    #+#             */
/*   Updated: 2025/01/22 15:02:41 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	chunk_sort(t_stack	*stack_a, t_stack *stack_b)
{
	int	o_size = stack_a->size;
	int median = 0;
	int index;
	int temp;

	while (stack_a->size > 2)
	{
		median = (median + o_size) / 2;
		index = 0;
		temp = stack_a->size;
		while (index < temp)
		{
			if (stack_a->top->data < median)
				pb(stack_a, stack_b);
			else
				ra(stack_a);
			index++;
		}
	}
}

void	do_move(t_stack *stack_a, t_stack *stack_b, t_move *move)
{
	while (move->ra > 0 || move->rb > 0)
	{
		if (move->ra > 0 && move->rb > 0)
		{
			rr(stack_a, stack_b);
			move->ra--;
			move->rb--;
		}
		else if (move->ra > 0)
		{
			ra(stack_a);
			move->ra--;
		}
		else
		{
			rb(stack_b);
			move->rb--;
		}
	}
	while (move->rra > 0 || move->rrb > 0)
	{
		if (move->rra > 0 && move->rrb > 0)
		{
			rrr(stack_a, stack_b);
			move->rra--;
			move->rrb--;
		}
		else if (move->rra > 0)
		{
			rra(stack_a);
			move->rra--;
		}
		else
		{
			rrb(stack_b);
			move->rrb--;
		}
	}
	move->cost = -1;
}

void	set_node_move(t_stack *stack_a, t_stack *stack_b, t_node *node, t_move *move)
{
	int 	i;
	t_node	*current;

	current = node;
	i = 0;
	while (current != stack_b->top)
	{
		i++;
		current = current->prev;
	}
	move->rb = i;
	move->rrb = stack_b->size - i;
	i = 0;
	if (node->data < stack_a->min || node->data > stack_a->max)
		current = get_min_node(stack_a);
	else
		current = get_nearest_min_node(stack_a, node->data);
	while (current != stack_a->top)
	{
		i++;
		current = current->prev;
	}
	move->ra = i;
	move->rra = stack_a->size - i;
}

void	set_best_move(t_move temp_move, t_move *best_move)
{
	if (best_move->cost == -1 || (temp_move.ra > temp_move.rb ? temp_move.ra : temp_move.rb) < best_move->cost)
	{
		best_move->ra = temp_move.ra;
		best_move->rb = temp_move.rb;
		best_move->rra = 0;
		best_move->rrb = 0;
		best_move->cost = (temp_move.ra > temp_move.rb ? temp_move.ra : temp_move.rb);
	}
	if ((temp_move.rra > temp_move.rrb ? temp_move.rra : temp_move.rrb) < best_move->cost)
	{
		best_move->rra = temp_move.rra;
		best_move->rrb = temp_move.rrb;
		best_move->ra = 0;
		best_move->rb = 0;
		best_move->cost = (temp_move.rra > temp_move.rrb ? temp_move.rra : temp_move.rrb);
	}
	if (temp_move.ra + temp_move.rrb < best_move->cost)
	{
		best_move->ra = temp_move.ra;
		best_move->rb = 0;
		best_move->rra = 0;
		best_move->rrb = temp_move.rrb;
		best_move->cost = temp_move.ra + temp_move.rrb;
	}
	if (temp_move.rb + temp_move.rra < best_move->cost)
	{
		best_move->ra = 0;
		best_move->rb = temp_move.rb;
		best_move->rra = temp_move.rra;
		best_move->rrb = 0;
		best_move->cost = temp_move.rb + temp_move.rra;
	}
}

void	turkish_sort(t_stack *stack_a, t_stack *stack_b)
{
	t_move	best_move;
	t_move	temp_move;
	t_node	*current;
	int		i;

	while (stack_b->size > 0)
	{
		current = stack_b->top;
		i = 0;
		while (i < stack_b->size)
		{
			set_node_move(stack_a, stack_b, current, &temp_move);
			set_best_move(temp_move, &best_move);
			current = current->next;
			i++;
		}	
		do_move(stack_a, stack_b, &best_move);
		pa(stack_a, stack_b);
		// print_stacks(stack_a, stack_b);
	}
	if (stack_a->top->data < stack_a->size / 2)
		while (stack_a->top != get_min_node(stack_a))
			ra(stack_a);
	else
		while (stack_a->top != get_min_node(stack_a))
			rra(stack_a);
}





/*
void	bubble_sort(t_stack *stack)
{
	int	is_sorted = 0;
	t_node	*first;
	t_node	*second;
	t_node	*temp;
	int count = 0;

	first = stack->top;
	temp = stack->top;

	while (is_sorted == 0 || first != temp)
	{
		second = temp->next;
		if (first == temp)
			is_sorted = 1;
		if (temp->next != first && temp->data > second->data)
		{
			is_sorted = 0;
			swap(stack);
			count++;
		}
		rotate(stack);
		count++;
		temp = stack->top;
		if (is_sorted && first == temp)
			break ;
	}
	printf("%d\n", count);
}*/

