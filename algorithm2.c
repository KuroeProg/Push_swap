/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <cfiachet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 01:23:16 by cfiachet          #+#    #+#             */
/*   Updated: 2025/01/24 19:18:30 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_best_move(t_move temp_move, t_move *best_move)
{
	int	max_ra_rb;
	int	max_rra_rrb;

	if (temp_move.ra > temp_move.rb)
		max_ra_rb = temp_move.ra;
	else
		max_ra_rb = temp_move.rb;
	if (temp_move.rra > temp_move.rrb)
		max_rra_rrb = temp_move.rra;
	else
		max_rra_rrb = temp_move.rrb;
	if (best_move->cost == -1 || max_ra_rb < best_move->cost)
	{
		best_move->ra = temp_move.ra;
		best_move->rb = temp_move.rb;
		best_move->rra = 0;
		best_move->rrb = 0;
		best_move->cost = max_ra_rb;
	}
	set_best_move2(temp_move, best_move, max_rra_rrb);
}

void	set_best_move2(t_move temp_move, t_move *best_move, int max_rra_rrb)
{
	if (max_rra_rrb < best_move->cost)
	{
		best_move->rra = temp_move.rra;
		best_move->rrb = temp_move.rrb;
		best_move->ra = 0;
		best_move->rb = 0;
		best_move->cost = max_rra_rrb;
	}
	if (temp_move.ra + temp_move.rrb < best_move->cost)
	{
		best_move->ra = temp_move.ra;
		best_move->rb = 0;
		best_move->rra = 0;
		best_move->rrb = temp_move.rrb;
		best_move->cost = temp_move.ra + temp_move.rrb;
	}
	if (temp_move.rb + temp_move.rra < best_move->cost)
	{
		best_move->ra = 0;
		best_move->rb = temp_move.rb;
		best_move->rra = temp_move.rra;
		best_move->rrb = 0;
		best_move->cost = temp_move.rb + temp_move.rra;
	}
}
void	turkish_sort2(t_stack *stack_a)
{
	while (stack_a->top != get_min_node(stack_a))
			rra(stack_a);
}