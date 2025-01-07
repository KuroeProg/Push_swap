/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <cfiachet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 13:30:00 by cfiachet          #+#    #+#             */
/*   Updated: 2025/01/07 13:33:49 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *a)
{
	int i;
	int temp;

	if (a-> size > 1)
	{
		temp = a->data[0];
		i = 0;
		while (i < a->size - 1)
		{
			a->data[i] = a->data[i + 1];
			i++;
		}
		a->data[a->size - 1] = temp;
	}
}

void	rb(t_stack *b)
{
	int i;
	int temp;

	if (b->size > 1)
	{
		temp = b->data[0];
		i = 0;
		while (i < b->size - 1)
		{
			b->data[i] = b->data[i + 1];
			i++;
		}
		b->data[b->size - 1] = temp;
	}
}

void	rr(t_stack *a, t_stack *b)
{
	ra(a);
	rb(b);
}