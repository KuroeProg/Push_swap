/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <cfiachet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:59:48 by cfiachet          #+#    #+#             */
/*   Updated: 2025/01/23 15:28:36 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_all(t_stack *a, t_stack *b)
{
	
	free_stack(a);
	free_stack(b);
}

void	free_stack(t_stack *stack)
{
	t_node *current;
	t_node	*temp;
	int		i;

	if (!stack->top)
		return ;
	current = stack->top;
	temp = stack->top;
	i = -1;
	while (++i < stack->size)
	{
		temp = current->next;
		free(current);
		current = temp;
	}
}