#include "ft_printf.h"

int	ft_process_types(t_p_list par, va_list ap)
{
	if (par.type == 'c')
		return (ft_char_output(par, va_arg(ap, int)));
	if (par.type == 's')
		return (ft_string_output(par, va_arg(ap, char *)));
	if (par.type == 'p')
		return (ft_pointer_output(par, va_arg(ap, unsigned long)));
	if (par.type == 'i' || par.type == 'd')
		return (ft_dex_output(par, va_arg(ap, int)));
	if (par.type == 'u')
		return (ft_unsigned_int_output(par, va_arg(ap, unsigned int)));
	if (par.type == 'x')
		return (ft_hex_output(par, va_arg(ap, unsigned int), 32));
	if (par.type == 'X')
		return (ft_hex_output(par, va_arg(ap, unsigned int), 0));
	if (par.type == '%')
		return (ft_char_output(par, '%'));
	return (0);
}
