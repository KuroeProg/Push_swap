/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <cfiachet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 21:44:59 by cfiachet          #+#    #+#             */
/*   Updated: 2025/01/11 21:45:35 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_freestack(t_stack *a)
{
	t_stack *tmp;
	
	while(a)
	{
		tmp = a;
		a = a->next;
		free(tmp);
	}
}

void	free_errors(t_stack *a)
{
	ft_freestack(a);
	exit(1);
}