SRCS    = srcs/so_long.c\
		srcs/so_long_utils.c\
		srcs/so_long_utils_2.c\
		srcs/so_long_init.c\
		srcs/so_long_check_errors.c\
		srcs/so_long_read_and_check.c\
		srcs/so_long_pars.c\
		srcs/so_long_moves.c\
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
		ft_printf/ft_strlen.c

SRCS_BONUS	= bonus/so_long_bonus.c\
		bonus/so_long_utils_bonus.c\
		bonus/so_long_utils_2_bonus.c\
		bonus/so_long_init_bonus.c\
		bonus/so_long_check_errors_bonus.c\
		bonus/so_long_read_and_check_bonus.c\
		bonus/so_long_pars_bonus.c\
		bonus/so_long_moves_bonus.c\
		bonus/so_long_itoa_bonus.c\
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
		ft_printf/ft_strlen.c

OBJS	= ${SRCS:.c=.o}
OBJS_BONUS	= ${SRCS_BONUS:.c=.o}
LMLX	= -L minilibx-linux/ -lmlx -lXext -lX11
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
HEAD 	= -I includes -I -I minilibx-linux/
NAME	= so_long
NAME_BONUS	= so_long_bonus
MLX_DIR = minilibx-linux

${NAME}:	${OBJS}
			@make -C ${MLX_DIR}
			${CC} ${CFLAGS} -o ${NAME} $^ ${LMLX}
 
all :		${NAME} ${NAME_BONUS}

.c.o:		${CC} ${CFLAGS} ${HEAD} -o ${<:.c=.o} -c $<



${NAME_BONUS}:	${OBJS_BONUS}
			@make -C ${MLX_DIR}
			${CC} ${CFLAGS} -o ${NAME_BONUS} $^ ${LMLX}

bonus:		${NAME_BONUS}

clean:
			rm -f ${OBJS}
			rm -f ${OBJS_BONUS}
			@make clean -C ${MLX_DIR}

fclean:		clean
			rm -f ${NAME}
			rm -f ${NAME_BONUS}

re:			fclean all 

.PHONY: all clean fclean re