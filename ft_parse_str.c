#include "ft_printf.h"

static int	ft_write(int *index)
{
	(*index)++;
	return (write(1, " ", 1));
}

int	ft_parse_str(const char *fmt, va_list ap)
{
	t_p_list	par;
	int			len;
	int			index;

	len = 0;
	index = 0;
	while (fmt[index])
	{
		par = ft_flags_reset(par);
		if (fmt[index] == '%')
		{
			index++;
			if (fmt[index] == ' ')
				len += ft_write(&index);
			index = ft_parse_flags(fmt, index, &par, ap);
			if (par.type)
				len += ft_process_types(par, ap);
			continue ;
		}
		len += write (1, &fmt[index], 1);
		index++;
	}
	return (len);
}
