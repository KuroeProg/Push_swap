/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <cfiachet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 16:35:46 by cfiachet          #+#    #+#             */
/*   Updated: 2025/01/21 14:28:14 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>
#include <time.h>

int	*generate_random_array(int size)
{
	int	*array;
	int	i, j, temp;

	if (size > 500)
		return (NULL);

	array = malloc(sizeof(int) * size);
	if (!array)
		return (NULL);

	for (i = 0; i < size; i++)
		array[i] = i + 1;

	srand(time(NULL));
	for (i = size - 1; i > 0; i--)
	{
		j = rand() % (i + 1);
		temp = array[i];
		array[i] = array[j];
		array[j] = temp;
	}

	return (array);
}

void	print_stacks(t_stack *a, t_stack *b)
{
	int i = a->size;
	int j = b->size;
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
	// getchar();
}
int	main(int argc, char **argv)
{
	int	*tab;
	// if (argc < 2)
	// 	return (0);
	t_stack a;
	a = create_stack();
	t_stack	b = create_stack();
	int size = 100;
	tab = generate_random_array(size);
	fill_stack(&a, tab, size);
	// pa(&a, &b);
	// pa(&a, &b);
	// pa(&a, &b);
	// pb(&a, &b); 
	// pb(&a, &b); 
	// pb(&a, &b);
	print_stacks(&a, &b);
	chunk_sort(&a, &b);
	turkish_sort(&a, &b);
	// t_node a = create_node(10);
	// t_node b = create_node(2);
	// link_nodes(&a, &b);
	//bubble_sort(&a);
	print_stacks(&a, &b);

	return (0);
}