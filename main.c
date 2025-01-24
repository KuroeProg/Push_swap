/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <cfiachet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 00:18:26 by cfiachet          #+#    #+#             */
/*   Updated: 2025/01/24 17:51:15 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*formatted_data(int *data, int size)
{
	int	*formatted;
	int	nb;
	int	tmp;
	int	i;

	if (size == 0)
		return (free(data), NULL);
	formatted = malloc(sizeof(int) * size);
	if (!formatted)
		return (free(data), NULL);
	nb = 1;
	tmp = int_tab_min_index(data, size);
	formatted[tmp] = nb++;
	i = 0;
	while (i < size - 1)
	{
		tmp = int_tab_next_index(data, size, data[tmp]);
		if (tmp != -1)
			formatted[tmp] = nb++;
		if (int_tab_count_value(data, size, data[tmp]) != 1)
			return (free(data), free(formatted), NULL);
		i++;
	}
	return (free(data), formatted);
}

int	main(int argc, char **argv)
{
	t_point	pt;
	int		*tab;
	t_stack	a;
	t_stack	b;

	if (argc < 2 || !argv)
		return (1);
	init_data(&pt, &a, &b);
	pt.i = 0;
	pt.len = 0;
	if (!parsing_args(argv + 1, &pt))
		return (1);
	tab = pt.tab;
	if (!tab || !check_tab(tab, pt.len))
		return (ft_error(1), 1);
	tab = formatted_data(tab, pt.len);
	a = create_stack();
	b = create_stack();
	fill_stack(&a, tab, pt.len);
	check_tab_size(tab, pt.len, &a, &b);
	chunk_sort(&a, &b);
	turkish_sort(&a, &b);
	free_all(&a, &b);
	free(tab);
	return (0);
}
