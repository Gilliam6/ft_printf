#include "ft_printf.h"

int	ft_hex_capacity(unsigned long point, t_p_list par)
{
	int	i;

	i = 0;
	if (point == 0 && par.precision == 0)
		return (0);
	if (point == 0)
		return (1);
	while (point)
	{
		i++;
		point /= 16;
	}
	return (i);
}

void	ft_hex_converter(unsigned long point)
{
	int	hex;

	if (point == 0)
		return ;
	if (point % 16 < 10)
	{
		hex = point % 16 + 48;
		ft_hex_converter(point / 16);
		write(1, &hex, 1);
	}
	if (point % 16 >= 10)
	{
		hex = point % 16 + 87;
		ft_hex_converter(point / 16);
		write(1, &hex, 1);
	}
}

int	ft_pointer_output(t_p_list par, unsigned long point)
{
	int	len;

	len = 2;
	while (!par.minus && par.width > 2 + ft_hex_capacity(point, par))
	{
		len += write(1, " ", 1);
		par.width--;
	}
	write(1, "0x", 2);
	if (point == 0 && par.precision != 0)
		len += write(1, "0", 1);
	ft_hex_converter(point);
	while (par.minus && par.width > 2 + ft_hex_capacity(point, par))
	{
		len += write(1, " ", 1);
		par.width--;
	}
	while (point)
	{
		len++;
		point /= 16;
	}
	return (len);
}
