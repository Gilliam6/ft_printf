#include "ft_printf.h"

int	ft_printf(const char *fmt, ...)
{
	int		len;
	va_list	ap;

	va_start(ap, fmt);
	len = ft_parse_str(fmt, ap);
	va_end(ap);
	return (len);
}
