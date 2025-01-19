/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <cfiachet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 19:30:23 by cfiachet          #+#    #+#             */
/*   Updated: 2025/01/19 12:06:34 by cfiachet         ###   ########.fr       */
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

void	push(t_stack *stack, t_node *a)
{
	t_node	*start;
	t_node	*end;

	if (!a)
		return ;
	if (stack->size == 0)
	{
		stack->top = a;
		stack->size++;
		return ;
	}
	if (stack->size == 1)
	{
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
			pop = stack->top;
			stack->top = NULL;
			stack->size--;
			return (pop);
		}
		if (stack->size == 2) //////FAIRE UNE FONCTION UNLINK NODES
		{
			pop = stack->top;
			start = pop->next;
			pop->prev = NULL;
			pop->next = NULL;
			start->next = NULL;
			start->prev = NULL;
			stack->top = start;
			stack->size--;
			return (pop);
		}
	}
	pop = stack->top;
	end = pop->prev;
	start = pop->next;
	pop->next = NULL;
	pop->prev = NULL;
	link_nodes(end, start);
	stack->top = start;
	stack->size--;

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