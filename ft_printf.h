#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"
# include <stdarg.h>
# include <unistd.h>

typedef struct s_print_list
{
	int		width;
	int		precision;
	int		null;
	char	type;
	int		minus;
	int		star;
}					t_p_list;

t_p_list	ft_flags_reset(t_p_list par);
int			ft_line_validator(char c, char *set);
int			ft_parse_flags(const char *fmt, int i, t_p_list *par, va_list ap);
int			ft_int_capacity(int arg);
int			ft_width_put(t_p_list par);
int			ft_dex_capacity(int arg);
int			ft_parse_str(const char *fmt, va_list ap);
int			ft_process_types(t_p_list par, va_list ap);
int			ft_char_output(t_p_list par, int arg);
int			ft_string_output(t_p_list par, char *str);
int			ft_pointer_output(t_p_list par, unsigned long point);
int			ft_int_output(t_p_list par, int arg);
int			ft_unsigned_int_output(t_p_list par, unsigned int arg);
int			ft_hex_output(t_p_list ap, unsigned int arg, int capital);
int			ft_unsigned_int_capacity(unsigned int arg);
int			ft_dex_output(t_p_list par, int arg);
int			ft_printf(const char *fmt, ...);
#endif
