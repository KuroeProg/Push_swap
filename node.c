/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <cfiachet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 18:39:09 by cfiachet          #+#    #+#             */
/*   Updated: 2025/01/12 18:40:54 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	append_node(t_stack **stack, int value)
{
	t_stack	*new;
	t_stack	*last;

	if (!stack)
		return ;
	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return ;
	new->next = NULL;
	new->nbr = value;
	if (!(*stack))
	{
		*stack = new;
		new->preview = NULL;
		return ;
	}
	last = ft_last(*stack);
	last->next = new;
	new->preview = last;
}
