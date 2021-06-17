#include "ft_printf.h"

int	ft_dex_capacity(int arg)
{
	int	i;

	i = 0;
	if (arg == 0)
		return (1);
	while (arg)
	{
		i++;
		arg /= 10;
	}
	return (i);
}

static void	ft_putnbr(int n, t_p_list par)
{
	if (n == -2147483648)
		write(1, "2147483648", 10);
	else
	{
		if (n < 0)
			n = -n;
		if (n > 9)
		{
			ft_putnbr(n / 10, par);
			ft_putchar_fd(n % 10 + '0', 1);
		}
		if (n <= 9)
			ft_putchar_fd(n + '0', 1);
	}
}

static int	ft_minus_int_print(t_p_list par, int arg)
{
	int	len;

	len = 0;
	if (par.precision < 0 && par.precision < ft_dex_capacity(arg))
		par.precision = ft_dex_capacity(arg);
	if (arg < 0)
	{
		write(1, "-", 1);
		len++;
		par.width--;
	}
	while (par.precision > ft_dex_capacity(arg))
	{
		write(1, "0", 1);
		len++;
		par.precision--;
		par.width--;
	}
	ft_putnbr(arg, par);
	while (par.width-- > ft_dex_capacity(arg))
	{
		write(1, " ", 1);
		len++;
	}
	return (len);
}

static int	ft_int_print(t_p_list par, int arg)
{
	int	len;

	len = 0;
	if (arg < 0 && par.null && par.precision < 0)
		len += write(1, "-", 1);
	if (arg < 0 && par.width > 0)
		par.width--;
	while (par.width > par.precision && par.width > ft_dex_capacity(arg))
	{
		if (par.null && par.precision < 0)
			len += write(1, "0", 1);
		else
			len += write(1, " ", 1);
		par.width--;
	}
	if ((arg < 0 && !par.null) || (arg < 0 && par.precision >= 0))
		len += write(1, "-", 1);
	while (par.precision >= 0 && par.precision-- > ft_dex_capacity(arg))
		len += write(1, "0", 1);
	ft_putnbr(arg, par);
	return (len);
}

int	ft_dex_output(t_p_list par, int arg)
{
	int	len;

	len = 0;
	if (par.precision == 0 && arg == 0)
		len += ft_width_put(par);
	else
	{
		if (par.minus)
			len += ft_minus_int_print(par, arg);
		else
			len += ft_int_print(par, arg);
		len += ft_dex_capacity(arg);
	}
	return (len);
}
