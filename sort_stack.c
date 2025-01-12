/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <cfiachet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 17:09:28 by cfiachet          #+#    #+#             */
/*   Updated: 2025/01/12 14:01:25 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stacks(t_stack **a, t_stack **b)
{
	
}

void	sort_three(t_stack **a)
{
	if ((*a)->nbr > (*a)->next->nbr)
		sa(a);
	if ((*a)->next->nbr > (*a)->next->next->nbr)
	{
		rra(a);
		if ((*a)->nbr > (*a)->next->nbr)
			sa(a);
	}
}