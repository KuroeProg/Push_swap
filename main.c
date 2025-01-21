/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <cfiachet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 16:35:46 by cfiachet          #+#    #+#             */
/*   Updated: 2025/01/21 19:35:47 by cfiachet         ###   ########.fr       */
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

// int	*init_data(char *args[], int size)
// {
// 	int	*data;
// 	int	i;

// 	data = malloc(sizeof(int) * size);
// 	if (!data)
// 		return (NULL);
// 	i = 0;
// 	while (i < size)
// 	{
// 		if (!ft_is_int(args[i]))
// 			return (free(data), NULL);
// 		data[i] = ft_atoi(args[i]);
// 		i++;
// 	}
// 	return (data);
// }

// int	*formatted_data(int *data, int size)
// {
// 	int	*formatted;
// 	int	nb;
// 	int	tmp;
// 	int	i;

// 	formatted = malloc(sizeof(int) * size);
// 	if (!formatted)
// 		return (free(data), NULL);
// 	nb = 1;
// 	tmp = int_tab_min_index(data, size);
// 	formatted[tmp] = nb++;
// 	i = 0;
// 	while (i < size - 1)
// 	{
// 		tmp = int_tab_next_index(data, size, data[tmp]);
// 		if (tmp != -1)
// 			formatted[tmp] = nb++;
// 		if (int_tab_count_value(data, size, data[tmp]) != 1)
// 			return (free(data), free(formatted), NULL);
// 		i++;
// 	}
// 	return (free(data), formatted);
// }

int	main(int argc, char **argv)
{
	int	*tab;
	// if (argc < 2)
	// 	return (0);
	// if (argc == 2)
	// 	parsing_sentence(argv + 1);
	//if (argc > 2)
		
	t_stack a;
	a = create_stack();
	t_stack	b = create_stack();
	int size = 500;
	tab = generate_random_array(size);
	// print_stacks(&a, &b);
	fill_stack(&a, tab, size);
	chunk_sort(&a, &b);
	turkish_sort(&a, &b);
	// print_stacks(&a, &b);

	return (0);
}