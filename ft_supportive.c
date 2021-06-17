#include "ft_printf.h"

t_p_list	ft_flags_reset(t_p_list par)
{
	par.width = 0;
	par.precision = -1;
	par.type = 0;
	par.minus = 0;
	par.null = 0;
	par.star = 0;
	return (par);
}

int	ft_line_validator(char c, char *str)
{
	while (*str)
	{
		if (c == *str)
			return (1);
		str++;
	}
	return (0);
}

int	ft_width_put(t_p_list par)
{
	int	len;

	len = 0;
	while (par.width--)
	{
		write(1, " ", 1);
		len++;
	}
	return (len);
}
