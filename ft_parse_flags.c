#include "ft_printf.h"

static int	ft_precision(const char *fmt, int index, t_p_list **par, va_list ap)
{
	int	arg;

	if (fmt[index] == '*')
	{
		arg = va_arg(ap, int);
		(*par)->precision = arg;
		return (index + 1);
	}
	else
	{
		(*par)->precision = 0;
		while (ft_isdigit(fmt[index]))
		{
			(*par)->precision *= 10;
			(*par)->precision += fmt[index] - 48;
			index++;
		}
		return (index);
	}
}

static t_p_list	*ft_minus(t_p_list *par)
{
	par->minus = 1;
	par->null = 0;
	return (par);
}

static t_p_list	*ft_width(va_list ap, t_p_list *par)
{
	par->star = 1;
	par->width = va_arg(ap, int);
	if (par->width < 0)
	{
		par->minus = 1;
		par->width *= -1;
		par->null = 0;
	}
	return (par);
}

static t_p_list	*ft_int_width(char c, t_p_list *par)
{
	if (par->star)
	{
		par->width = 0;
		par->width = par->width * 10 + (c - 48);
		return (par);
	}
	else
	{
		par->width = par->width * 10 + (c - 48);
		return (par);
	}
}

int	ft_parse_flags(const char *fmt, int index, t_p_list *par, va_list ap)
{
	while (ft_line_validator(fmt[index], "*0987654321.-cspdiuxX%"))
	{
		if (fmt[index] == '0' && !(par->width) && !(par->minus))
			par->null = 1;
		if (fmt[index] == '.')
			index = ft_precision(fmt, index + 1, &par, ap);
		if (fmt[index] == '-')
			par = ft_minus(par);
		if (fmt[index] == '*')
			par = ft_width(ap, par);
		if (ft_isdigit(fmt[index]))
			par = ft_int_width(fmt[index], par);
		if (ft_line_validator(fmt[index], "cspdiuxX%"))
		{
			par->type = fmt[index];
			index++;
			return (index);
		}
		index++;
	}
	return (index);
}
