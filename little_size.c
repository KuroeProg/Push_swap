/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <cfiachet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:49:57 by cfiachet          #+#    #+#             */
/*   Updated: 2025/01/23 21:32:31 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_min_to_b(t_stack *stack_a, t_stack *stack_b)
{
    t_node	*min_node;
    int		min_pos;

    min_node = get_min_node(stack_a);
    min_pos = get_node_position(stack_a, min_node);
    if (min_pos <= stack_a->size / 2)
    {
        while (stack_a->top != min_node)
            ra(stack_a);
    }
    else
    {
        while (stack_a->top != min_node)
            rra(stack_a);
    }
    pb(stack_a, stack_b);
}

static  void	sort_small_stack(t_stack *stack_a, t_stack *stack_b, int size)
{
    int	i;

    if (size <= 3)
    {
        sort_three(stack_a);
        return ;
    }
    else if (size == 4)
    {
        sort_four(stack_a, stack_b);
        return ;
    }
    else if (size == 5)
    {
        sort_five(stack_a, stack_b);
        return ;
    }
    i = 0;
    while (i < size - 3)
    {
        push_min_to_b(stack_a, stack_b);
        i++;
    }
    sort_three(stack_a);
    while (stack_b->size > 0)
        pa(stack_a, stack_b);
}

void	sort_four(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*min;

	min = get_min_node(stack_a);
	while (stack_a->top->data != min->data)
		ra(stack_a);
	pb(stack_a, stack_b);
	sort_three(stack_a);
	pa(stack_a, stack_b);
}

void	sort_three(t_stack *stack)
{
	t_node	*f;

	if (!stack || stack->size != 3)
		return;

	f = stack->top;
	if (f->data < f->next->data && f->next->next->data > f->data && f->next->data > f->next->next->data)
	{
		sa(stack);
		ra(stack);
	}
	else if (f->data > f->next->data && f->next->next->data < f->data && f->next->data > f->next->next->data)
	{
		ra(stack);
		sa(stack);
	}
	else if (f->data < f->next->data && f->next->next->data < f->next->data)
		rra(stack);
	else if (f->data > f->next->next->data && f->data > f->next->data)
		ra(stack);
	else if (f->data > f->next->data && f->data < f->next->next->data)
		sa(stack);
}


int	check_tab_size(int *tab, int len, t_stack *stack_a, t_stack *stack_b)
{
	if (len < 22)
	{
		if (len == 0 || len == 1)
			free(tab);
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
		free_all(stack_a, stack_b);
		free(tab);
		exit(0);
	}
	return (0);
}