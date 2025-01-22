#include "../push_swap.h"

int	ft_is_int(char *str)
{
    long num;

    num = ft_atol(str);
    if (num < INT_MIN || num > INT_MAX)
    {
        write(2, "Error\n", 6);
        return (0);
    }
    return (1);
}

int	int_tab_min_index(int *tab, int size)
{
    int min;
    int index;
    int i;

    min = tab[0];
    index = 0;
    i = 1;
    while (i < size)
    {
        if (tab[i] < min)
        {
            min = tab[i];
            index = i;
        }
        i++;
    }
    return (index);
}

int	int_tab_next_index(int *tab, int size, int current)
{
    int next;
    int index;
    int i;

    next = INT_MAX;
    index = -1;
    i = 0;
    while (i < size)
    {
        if (tab[i] > current && tab[i] < next)
        {
            next = tab[i];
            index = i;
        }
        i++;
    }
    return (index);
}

int	int_tab_count_value(int *tab, int size, int value)
{
    int count;
    int i;

    count = 0;
    i = 0;
    while (i < size)
    {
        if (tab[i] == value)
            count++;
        i++;
    }
    return (count);
}