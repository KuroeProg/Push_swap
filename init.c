/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <cfiachet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:39:28 by cfiachet          #+#    #+#             */
/*   Updated: 2025/01/24 19:15:53 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_data(t_point *pt, t_stack *a, t_stack *b)
{
	pt->i = 0;
	pt->y = 0;
	pt->k = 0;
	pt->n = 0;
	pt->len = 0;
	pt->tab = NULL;
	a->top = NULL;
	a->size = 0;
	a->min = 0;
	a->max = 0;
	b->top = NULL;
	b->size = 0;
	b->min = 0;
	b->max = 0;
}

void	init_best_move(t_move *best_move)
{
	best_move->ra = 0;
	best_move->rra = 0;
	best_move->rb = 0;
	best_move->rrb = 0;
	best_move->cost = -1;
}
