
#include "push_swap.h"

int	parsing_sentence(char *str, t_point *pt)
{
	char **split;
	int i;

	split = ft_split(str, ' ');
	if (!split)
		return (0);
	pt->len = 0;
	while (split[pt->len])
		pt->len++;
	pt->tab = malloc(sizeof(int) * pt->len);
	if (!pt->tab)
		return (free_tab(split), 0);
	i = 0;
	while (i < pt->len)
	{
		if (!ft_is_int(split[i]))
			return (free_tab(split), free(pt->tab), 0);
		pt->tab[i] = ft_atol(split[i]);
		i++;
	}
	free_tab(split);
	return (1);
}


int	parsing_args(char **argv, t_point *pt)
{
    int i;
    int total_len = 0;
    char *joined_args;
    char *temp;

    i = 0;
    while (argv[i])
    {
        total_len += ft_strlen(argv[i]) + 1; 
        i++;
    }
    joined_args = malloc(total_len);
    if (!joined_args)
        return (0);
    joined_args[0] = '\0';
    i = 0;
    while (argv[i])
    {
        temp = ft_strjoin(joined_args, argv[i]);
        free(joined_args);
        joined_args = temp;
        if (argv[i + 1])
        {
            temp = ft_strjoin(joined_args, " ");
            free(joined_args);
            joined_args = temp;
        }
        i++;
    }
    if (!parsing_sentence(joined_args, pt))
    {
        free(joined_args);
        return (0);
    }

    free(joined_args);
    return (1);
}

int	check_tab(int *tab, int len)
{
    int i;

    if (is_indouble(tab, len) == 1)
        return (0);
    i = 0;
    while (i < len)
    {
        if (tab[i] > INT_MAX || tab[i] < INT_MIN)
        {
            ft_printf("Error\n");
            return (0);
        }
        i++;
    }
    return (1);
}