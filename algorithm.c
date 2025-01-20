/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <cfiachet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 14:45:07 by cfiachet          #+#    #+#             */
/*   Updated: 2025/01/20 19:50:03 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	bubble_sort(t_stack *stack)
{
	int	is_sorted = 0;
	t_node	*first;
	t_node	*second;
	t_node	*temp;
	int count = 0;

	first = stack->top;
	temp = stack->top;

	while (is_sorted == 0 || first != temp)
	{
		second = temp->next;
		if (first == temp)
			is_sorted = 1;
		if (temp->next != first && temp->data > second->data)
		{
			is_sorted = 0;
			swap(stack);
			count++;
		}
		rotate(stack);
		count++;
		temp = stack->top;
		if (is_sorted && first == temp)
			break ;
	}
	printf("%d\n", count);
}

void	bubble_sort_int(int *tab, int size)
{
	int i = 1;
	int is_sorted = 0;
	int temp = 0;
	
	while (is_sorted == 0 || i < size)
	{
		if (i == 1)
			is_sorted = 1;
		if (tab[i - 1] > tab[i])
		{
			is_sorted = 0;
			temp = tab[i - 1];
			tab[i - 1] = tab[i];
			tab[i] = temp;
		}
		i++;
		if (i == size && is_sorted)
			break ;
		if (i == size)
			i = 1;
	}
	i = 0;
	while (i < size)
	{
		printf("%d\n", tab[i]);
		i++;
	}
}
