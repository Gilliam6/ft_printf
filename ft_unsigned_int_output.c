#include "ft_printf.h"

static void	ft_putnbr(unsigned int n)
{
	if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putchar_fd(n % 10 + '0', 1);
	}
	if (n <= 9)
		ft_putchar_fd(n + '0', 1);
}

static int	ft_minus_u_print(t_p_list par, unsigned int arg)
{
	int	len;

	len = 0;
	if (par.precision < 0 && par.precision < ft_unsigned_int_capacity(arg))
		par.precision = ft_unsigned_int_capacity(arg);
	while (par.precision > ft_unsigned_int_capacity(arg))
	{
		write(1, "0", 1);
		len++;
		par.precision--;
		par.width--;
	}
	ft_putnbr(arg);
	while (par.width-- > ft_unsigned_int_capacity(arg))
	{
		write(1, " ", 1);
		len++;
	}
	return (len);
}

static int	ft_u_print(t_p_list p, unsigned int arg)
{
	int	len;

	len = 0;
	while (p.width > p.precision && p.width > ft_unsigned_int_capacity(arg))
	{
		if (p.null && p.precision < 0)
			write(1, "0", 1);
		else
			write(1, " ", 1);
		len++;
		p.width--;
	}
	while (p.precision >= 0 && p.precision-- > ft_unsigned_int_capacity(arg))
	{
		write(1, "0", 1);
		len++;
	}
	ft_putnbr(arg);
	return (len);
}

int	ft_unsigned_int_capacity(unsigned int arg)
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

int	ft_unsigned_int_output(t_p_list par, unsigned int arg)
{
	int	len;

	len = 0;
	if (par.precision == 0 && arg == 0)
		len += ft_width_put(par);
	else
	{
		if (par.minus)
			len += ft_minus_u_print(par, arg);
		else
			len += ft_u_print(par, arg);
		len += ft_unsigned_int_capacity(arg);
	}
	return (len);
}
