/* ************************************************************************** */
/*	                                                                        */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <cfiachet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 13:04:47 by cfiachet          #+#    #+#             */
/*   Updated: 2025/01/07 13:05:06 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include "inc/libft/libft.h"
# include "inc/libft/ft_printf/ft_printf.h"

typedef struct s_stack
{
	int				nbr;
	int				index;
	int				push_cost;
	int				above_median;
	int				cheapest;
	struct s_stack 	*target_node;
	struct s_stack 	*next;
	struct s_stack 	*preview;
}				t_stack;

void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);

void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);

void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);

void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

// Handle Errors

// stack initiation
void	init_stack_a(t_stack **a, char **argv);

// Nodes initiation

// commands

//algorithms
int		stact_sorted(t_stack *a);
void	sa(t_stack *a);
void	sort_three(t_stack *a);
void	sort_stacks(t_stack **a, t_stack **b);

//free
void	ft_freestack(t_stack *a);

#endif