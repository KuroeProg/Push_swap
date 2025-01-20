/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <cfiachet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 16:35:46 by cfiachet          #+#    #+#             */
/*   Updated: 2025/01/21 00:46:29 by cfiachet         ###   ########.fr       */
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
int	main(int argc, char **argv)
{
	int	*tab;
	if (argc < 2)
		return (0);
	t_stack a;
	a = create_stack();
	tab = sorter(argv, &a);
	
	fill_stack(&a, tab, 10);
	t_stack	b = create_stack();
	int *tab2 = {10,54,34,2};
	fill_stack(&b, tab2, 4);

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