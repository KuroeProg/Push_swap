/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <cfiachet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 13:34:02 by cfiachet          #+#    #+#             */
/*   Updated: 2025/01/11 23:11:03 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack **a)
{
	t_stack *last;
	t_stack *before_last;

	if (*a && (*a)->next)
	{
		last = *a;
		before_last = NULL;
		while (last->next)
		{
			before_last = last;
			last = last->next;
		}
		before_last->next = NULL;
		last->next = *a;
		*a = last;
	}
}

void	rrb(t_stack **b)
{
	t_stack *last;
	t_stack *before_last;

	if (*b && (*b)->next)
	{
		last = *b;
		before_last = NULL;
		while (last->next)
		{
			before_last = last;
			last = last->next;
		}
		before_last->next = NULL;
		last->next = *b;
		*b = last;
	}
}

void	rrr(t_stack **a, t_stack **b)
{
	rra(a);
	rrb(b);
}