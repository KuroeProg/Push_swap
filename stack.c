/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <cfiachet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 19:30:23 by cfiachet          #+#    #+#             */
/*   Updated: 2025/01/23 21:07:18 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack create_stack()
{
	t_stack stack;
	
	stack.top = NULL;
	stack.size = 0;
	return (stack);
}

void 	fill_stack(t_stack *stack, int *tab, int size)
{
	int i;
	t_node	*prev;
	t_node	*next;

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
	link_nodes(next, stack->top);
	stack->size = size;
}

t_node	*get_min_node(t_stack *stack)
{
	t_node *temp;
	t_node *min;

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
	t_node *temp;
	t_node *max;

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
	t_node *temp;
	t_node *nearest;

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

void	push(t_stack *stack, t_node *a)
{
	t_node	*start;
	t_node	*end;

	if (!a)
		return ;
	if (stack->size == 0)
	{
		stack->min = a->data;
		stack->max = a->data;
		stack->top = a;
		stack->size++;
		return ;
	}
	if (stack->size == 1)
	{
		if (a->data < stack->min)
			stack->min = a->data;
		if (a->data > stack->max)
			stack->max = a->data;
		start = stack->top;
		stack->top = a;
		link_nodes(a, start);
		link_nodes(start, a);
		stack->size++;
		return ;
	}
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

t_node	*pop(t_stack *stack)
{
	t_node *start;
	t_node *end;
	t_node	*pop;

	if (stack->size < 3)
	{
		if (stack->size == 0)
			return (NULL);
		if (stack->size == 1)
		{
			stack->min = INT_MAX;
			stack->max = INT_MIN;
			pop = stack->top;
			stack->top = NULL;
			//write(2, "BB", 2);
			stack->size--;
			return (pop);
		}
		if (stack->size == 2)
		{
			pop = stack->top;
			start = pop->next;
			pop->prev = NULL;
			pop->next = NULL;
			start->next = NULL;
			start->prev = NULL;
			stack->top = start;
			stack->min = start->data;
			//write(2, "AA", 2);
			stack->max = start->data;
			stack->size--;
			return (pop);
		}
	}
	else
	{
		stack->min = INT_MIN;
		stack->max = INT_MAX;
	}
	pop = stack->top;
	end = pop->prev;
	start = pop->next;
	pop->next = NULL;
	pop->prev = NULL;
	link_nodes(end, start);
	stack->top = start;
	stack->size--;
	if (pop->data == stack->min)
		stack->min = get_min_node(stack)->data;
	if (pop->data == stack->max)
		stack->max = get_max_node(stack)->data;
	return (pop);
}

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