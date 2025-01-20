#include "push_swap.h"

void	ft_error(int n)
{
	if (n == 1)
		write(2, "Error\n", 6);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i++]);
	}
	free(tab);
}