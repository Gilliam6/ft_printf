#include "ft_printf.h"

static int	ft_adjustment(t_p_list par, char *str)
{
	int	index;

	index = 0;
	if (par.precision < 0)
	{
		while (str[index])
		{
			write(1, &str[index], 1);
			index++;
		}
	}
	else
	{
		while (par.precision-- > 0)
		{
			write(1, &str[index], 1);
			index++;
		}
	}
	return (index);
}

static int	ft_width_s_put(t_p_list par, char *str)
{
	int	index;

	index = 0;
	if (par.precision < 0)
	{
		while (index < par.width - ft_strlen(str))
		{
			write(1, " ", 1);
			index++;
		}
	}
	if (par.precision >= 0)
	{
		while (index < par.width - par.precision)
		{
			write(1, " ", 1);
			index++;
		}
	}
	return (index);
}

int	ft_string_output(t_p_list par, char *str)
{
	int	len;

	len = 0;
	if (!str)
		str = "(null)";
	if (par.precision >= 0 && par.precision > ft_strlen(str))
		par.precision = ft_strlen(str);
	if (par.minus)
	{
		len += ft_adjustment(par, str);
		if (par.width > par.precision)
			len += ft_width_s_put(par, str);
	}
	else
	{
		if (par.width > par.precision)
			len += ft_width_s_put(par, str);
		len += ft_adjustment(par, str);
	}
	return (len);
}
