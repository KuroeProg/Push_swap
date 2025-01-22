/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <cfiachet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 17:30:49 by cfiachet          #+#    #+#             */
/*   Updated: 2025/01/22 14:08:47 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <stdio.h>
# include "libft.h"
# include "ft_printf/ft_printf.h"
# include <limits.h>

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
	int		min;
	int		max;
} t_stack;

typedef struct s_point
{
    int	i;
    int	y;
    int	k;
    int	n;
    int len;
    int *tab;
} t_point;

typedef struct s_move
{
	int	ra;
	int	rra;
	int	rb;
	int	rrb;
	int cost;
} t_move;

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
//void	bubble_sort(t_stack *stack);
void	chunk_sort(t_stack	*stack_a, t_stack *stack_b);
void	turkish_sort(t_stack *stack_a, t_stack *stack_b);

t_node	*get_min_node(t_stack *stack); //recuperer la node avec la data la plus elevee
t_node	*get_max_node(t_stack *stack); //recuperer la node avec la data la plus elevee
t_node	*get_nearest_min_node(t_stack *stack, int data); //recuperer la node inferieure la plus proche de la data donnee
// // int		get_node_next_index(t_stack *stack, t_node *node); //recuperer lindex en partant de top et en se deplacement par les next
void	do_move(t_stack *stack_a, t_stack *stack_b, t_move *move); //faire les moves en fonction du t_move donne
void	set_node_move(t_stack *stack_a, t_stack *stack_b, t_node *node, t_move *move); //calcule et retourne un t_move en fonction de la node donnee



//utils
long	ft_atol(char *str);
void	ft_error(int n);
long		*sorter(char **str, t_stack *stack);
void	free_tab(char **tab);
int		is_indouble(int	*tab, int n);
int		ft_is_int(char *str);
int		int_tab_min_index(int *tab, int size);
int		int_tab_next_index(int *tab, int size, int current);
int		int_tab_count_value(int *tab, int size, int value);
char	**ft_split(char const *s, char c);

//parsing
int		parsing_sentence(char *str, t_point *pt);
int		parsing_args(char **argv, t_point *pt);
int		ft_isdigit(int c);

void	print_stacks(t_stack *a, t_stack *b);

#endif