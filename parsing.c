#include "push_swap.h"

int		parsing_sentence(char *str, t_point pt)
{
	char	*temp;

	pt.i = 0;
	while (str[pt.i])
	{
		if (str[pt.i] && str[pt.i] != ' ' || !ft_isdigit(str[pt.i]) 
			|| str[pt.i] == '+')
			ft_error(1);
		pt.i++;
	}
	
	



}

"13 54 11 888 3 85 4"
