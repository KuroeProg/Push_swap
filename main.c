#include "push_swap.h"

/*int	*init_data(char *args[], int size)
{
    int	*data;
    int	i;

    data = malloc(sizeof(int) * size);
    if (!data)
        return (NULL);
    i = 0;
    while (i < size)
    {
        if (!ft_is_int(args[i]))
            return (free(data), NULL);
        data[i] = ft_atoi(args[i]);
        i++;
    }
    return (data);
}*/

int	*formatted_data(int *data, int size)
{
    int	*formatted;
    int	nb;
    int	tmp;
    int	i;

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

#include "push_swap.h"

int	main(int argc, char **argv)
{
    int		*tab;
    t_stack	a;
    t_stack	b;
    t_point pt;

    if (argc < 2)
        return (0);
    if (argc == 2)
    {
        pt.i = 0;
        pt.len = 0;
        if (!parsing_sentence(argv[1], &pt))
            return (1);
        tab = pt.tab;
    }
    else
    {
        pt.i = 0;
        pt.len = 0;
        if (!parsing_args(argv + 1, &pt))
            return (1);
        tab = pt.tab;
    }
    if (!tab)
    {
        ft_error(1);
        return (1);
    }
	tab = formatted_data(tab, pt.len);
    a = create_stack();
    b = create_stack();
    fill_stack(&a, tab, pt.len);
    chunk_sort(&a, &b);
    turkish_sort(&a, &b);
    free(tab);
    return (0);
}