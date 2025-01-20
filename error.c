#include "push_swap.h"

void	ft_error(int n)
{
	if (n == 1)
		write(2, "Error\n", 6);
	if (n == 2)
		write(2, "Error2\n", 7);

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