SOURCE	=	ft_char_output.c \
			ft_hex_output.c \
			ft_parse_flags.c \
			ft_parse_str.c \
			ft_pointer_output.c \
			ft_printf.c \
			ft_process_types.c \
			ft_string_output.c \
			ft_supportive.c \
			ft_unsigned_int_output.c \
			ft_dex_output.c
HEADER	=	ft_printf.h libft/libft.h

OBJECTS	=	${SOURCE:.c=.o}

RM		=	rm -f

NAME	=	libftprintf.a

AR		=	ar rcs

CFLAGS	=	-Wall -Wextra -Werror

%.o: %.c ${HEADER}
			gcc ${CFLAGS} -Ilibft -c $< -o ${<:.c=.o}

${NAME}:	${OBJECTS}
			make -C libft
			cp libft/libft.a $(NAME)
			${AR} ${NAME} ${OBJECTS}


all:		${NAME}

clean:
			make clean -C libft
			${RM} ${OBJECTS}

fclean:		clean
			make fclean -C libft
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean bonus
