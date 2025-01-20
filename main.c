/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <cfiachet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 16:35:46 by cfiachet          #+#    #+#             */
/*   Updated: 2025/01/20 01:52:33 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>
void	print_stacks(t_stack *a, t_stack *b)
{
	int i = a->size > b->size ? a->size : b->size;
	int j = a->size < b->size ? a->size : b->size;
	t_node *node_a = a->top;
	t_node *node_b = b->top;
	printf("====================================\n");
	printf("|       A        ||        B       |\n");
	printf("====================================\n");
	while (i || j)
	{
		if (i >= j)
		{
			printf("|  % 12d  |", node_a->data);
			node_a = node_a->next;
			i--;
		}
		else
			printf("|                |");
		if (j >= i + 1)
		{
			printf("|  % 12d  |\n", node_b->data);
			node_b = node_b->next;
			j--;
		}
		else
			printf("|                |\n");
	}
	//getchar();
}
void	bubble_sort_int(int *tab, int size);
int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	t_stack a = create_stack();
	t_stack b = create_stack();
	int tab[10] = {5, 7, -34534853, 43824, 234, 353, 8, 4, 32453, 0};
	int tab2[2] = {9, -10};
	fill_stack(&a, tab, 10);
	fill_stack(&b, tab2, 2);
	// pa(&a, &b);
	// pa(&a, &b);
	// pa(&a, &b);
	// pb(&a, &b); 
	// pb(&a, &b); 
	// pb(&a, &b);
	print_stacks(&a, &b);
	// t_node a = create_node(10);
	// t_node b = create_node(2);
	// link_nodes(&a, &b);
	bubble_sort(&a);
	print_stacks(&a, &b);

	return (0);
}