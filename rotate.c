/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <cfiachet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 13:30:00 by cfiachet          #+#    #+#             */
/*   Updated: 2025/01/11 23:16:42 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **a)
{
	t_stack *first;
	t_stack *last;

	if (*a && (*a)->next)
	{
		first = *a;
		last = *a;
		while (last->next)
			last = last->next;
		*a = first->next;
		first->next = NULL;
		last->next = first;
	}
}

void	rb(t_stack **b)
{
	t_stack	*first;
	t_stack	*last;

	if (*b && (*b)->next)
	{
		first = *b;
		last = *b;
		while (last->next)
			last = last->next;
		*b = first->next;
		first->next = NULL;
		last->next = first;
	}
}

void	rr(t_stack **a, t_stack **b)
{
	ra(a);
	rb(b);
}