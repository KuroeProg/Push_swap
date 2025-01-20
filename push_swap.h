/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <cfiachet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 17:30:49 by cfiachet          #+#    #+#             */
/*   Updated: 2025/01/20 21:14:49 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include "libft.h"
# include "ft_printf/ft_printf.h"

typedef struct s_node
{
	int				data;
	struct s_node	*prev;
	struct s_node	*next;
} t_node;

typedef struct s_stack
{
	t_node	*top;
	int		size;
} t_stack;

//nodes
t_node	*create_node(int data);
void	link_nodes(t_node *a, t_node *b);

//stack
t_stack create_stack();
void 	fill_stack(t_stack *stack, int *tab, int size);
void	push(t_stack *stack, t_node *a);
t_node	*pop(t_stack *stack);
void	swap(t_stack *stack);
void	rotate(t_stack *stack);
void	rreverse(t_stack *stack);

//instructions
void	sa(t_stack *stack_a);
void	sb(t_stack *stack_b);
void	ss(t_stack *stack_a, t_stack *stack_b);
void	pa(t_stack *stack_a, t_stack *stack_b);
void	pb(t_stack *stack_a, t_stack *stack_b);
void	ra(t_stack *stack_a);
void	rb(t_stack *stack_b);
void	rr(t_stack *stack_a, t_stack *stack_b);
void	rra(t_stack *stack_a);
void	rrb(t_stack *stack_b);
void	rrr(t_stack *stack_a, t_stack *stack_b);

//algorithms
void	bubble_sort(t_stack *stack);

//utils
long	atol(char *str);
void	ft_error(int n);
int		*sorter(char *str, t_stack *stack);
void	free_tab(char **tab);

#endif