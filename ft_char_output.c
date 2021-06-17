#include "ft_printf.h"

int	ft_char_output(t_p_list par, int arg)
{
	int	len;

	len = 1;
	if (par.minus)
	{
		write(1, &arg, 1);
		while (len < par.width)
			len += write(1, " ", 1);
	}
	else
	{
		while (len < par.width && !par.null)
			len += write(1, " ", 1);
		while (len < par.width && par.null)
			len += write(1, "0", 1);
		write(1, &arg, 1);
	}
	return (len);
}
