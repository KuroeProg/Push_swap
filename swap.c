/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <cfiachet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 13:17:35 by cfiachet          #+#    #+#             */
/*   Updated: 2025/01/07 13:20:19 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *a)
{
	int temp;

	if (a->size > 1)
	{
		temp = a->data[0];
		a->data[0] = a->data[1];
		a->data[1] = temp;
	}
}

void	sb(t_stack *b)
{
	int temp;

	if (b->size > 1)
	{
		temp = b->data[0];
		b->data[0] = b->data[1];
		b->data[1] = temp;
	}
}

void	ss(t_stack *a, t_stack *b)
{
	sa(a);
	sb(b);
}