#include "ft_printf.h"

static void	ft_hexX_converter(unsigned int arg, int X)
{
	if (arg >= 16)
	{
		if (arg % 16 < 10)
		{
			ft_hexX_converter(arg / 16, X);
			ft_putchar_fd(arg % 16 + 48, 1);
		}
		if (arg % 16 >= 10)
		{
			ft_hexX_converter(arg / 16, X);
			ft_putchar_fd(arg % 16 + 55 + X, 1);
		}
	}
	if (arg < 16)
	{
		if (arg % 16 < 10)
			ft_putchar_fd(arg % 16 + 48, 1);
		if (arg % 16 >= 10)
			ft_putchar_fd(arg % 16 + 55 + X, 1);
	}
}

static int	ft_hex_capacity(unsigned int hex)
{
	int	cap;

	cap = 0;
	if (hex == 0)
		return (1);
	while (hex)
	{
		hex /= 16;
		cap++;
	}
	return (cap);
}

static int	ft_minus_hex_print(t_p_list par, unsigned int arg, int capital)
{
	int	len;

	len = 0;
	if (par.precision < 0 && par.precision < ft_dex_capacity(arg))
		par.precision = ft_hex_capacity(arg);
	while (par.precision > ft_hex_capacity(arg))
	{
		ft_putchar_fd('0', 1);
		par.width--;
		par.precision--;
		len++;
	}
	ft_hexX_converter(arg, capital);
	while (par.width > par.precision && par.width > ft_hex_capacity(arg))
	{
		ft_putchar_fd(' ', 1);
		par.width--;
		len++;
	}
	len += ft_hex_capacity(arg);
	return (len);
}

static int	ft_hex_print(t_p_list par, unsigned int arg, int capital)
{
	int	len;

	len = 0;
	while (par.width > par.precision && par.width > ft_hex_capacity(arg))
	{
		if (par.null && par.precision < 0)
			write(1, "0", 1);
		else
			write(1, " ", 1);
		len++;
		par.width--;
	}
	while (par.precision >= 0 && par.precision-- > ft_hex_capacity(arg))
	{
		write(1, "0", 1);
		len++;
	}
	ft_hexX_converter(arg, capital);
	len += ft_hex_capacity(arg);
	return (len);
}

int	ft_hex_output(t_p_list par, unsigned int arg, int capital)
{
	int	len;

	len = 0;
	if (par.precision == 0 && arg == 0)
		len += ft_width_put(par);
	else
	{
		if (par.minus)
			len += ft_minus_hex_print(par, arg, capital);
		else
			len += ft_hex_print(par, arg, capital);
	}
	return (len);
}
