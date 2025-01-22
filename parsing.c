
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

	pt->len = 0;
	while (argv[pt->len])
		pt->len++;
	pt->tab = malloc(sizeof(int) * pt->len);
	if (!pt->tab)
		return (0);
	i = 0;
	while (i < pt->len)
	{
		if (!ft_is_int(argv[i]))
			return (free(pt->tab), 0);
		pt->tab[i] = ft_atol(argv[i]);
		i++;
	}
	return (1);
}