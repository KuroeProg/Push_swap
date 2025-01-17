/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <cfiachet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 13:20:40 by cfiachet          #+#    #+#             */
/*   Updated: 2025/01/12 18:18:30 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack **a, t_stack **b)
{
	t_stack *temp;

	if (*b)
	{
		temp = *b;
		*b = (*b)->next;
		if (*b)
			(*b)->preview = NULL;
		temp->next = *a;
		if (*a)
			(*a)->preview = temp;
		*a = temp;
	}
}

void	pb(t_stack **a, t_stack **b)
{
	t_stack *temp;

	if (*a)
	{
		temp = *a;
		*a = (*a)->next;
		if (*a)
			(*a)->preview = NULL;
		temp->next = *b;
		if (*b)
			(*b)->preview = temp;
		*b = temp;
	}
}	
