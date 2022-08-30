SRCS    = so_long.c\
		so_long_utils.c\
		so_long_utils_2.c\
		so_long_init.c\
		so_long_check_errors.c\
		so_long_read_and_check.c\
		so_long_pars.c\
		so_long_moves.c\
		gnl/get_next_line_utils.c\
		gnl/get_next_line.c\
		ft_printf/count_hexa.c\
		ft_printf/count_hexa_x_x.c\
		ft_printf/count_nb.c\
		ft_printf/count_u.c\
		ft_printf/ft_char.c\
		ft_printf/ft_printf.c\
		ft_printf/ft_putchar.c\
		ft_printf/ft_putnbr_base.c\
		ft_printf/ft_putnbr_base_x_x.c\
		ft_printf/ft_putnbr_d_i.c\
		ft_printf/ft_putnbr_u.c\
		ft_printf/ft_string.c\
		ft_printf/ft_strlen.c\

OBJS	= ${SRCS:.c=.o}
LMLX	= -L minilibx-linux/ -lmlx -lXext -lX11
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
HEAD 	= -I includes -I -I minilibx-linux/
NAME	= so_long
MLX_DIR = minilibx-linux

all :		${NAME}

.c.o:		${CC} ${CFLAGS} ${HEAD} -o ${<:.c=.o} -c $<

${NAME}:	${OBJS}
			@make -C ${MLX_DIR}
			${CC} ${CFLAGS} -o ${NAME} $^ ${LMLX} 

clean:
			rm -f ${OBJS}
			@make clean -C ${MLX_DIR}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY: all clean fclean re